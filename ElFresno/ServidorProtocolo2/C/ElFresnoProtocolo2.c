#include <RNSiscomSeguridad3Prot2.h>
#include <ElFresnoProtocolo2.h>
#include <ConsultasElFresno.h>
#include <ServidorGeneral.h>
#include <Empleados.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

/*FILE *gPtrFleArchivoLog;  */
int errno;
StcSiscomConfiguracion gSSiscomConfiguracionSvr;
const char *gchrPtrConsultaPersonas="select	a.*,				\
						b.NmbTipoPersona,		\
						b.DscTipoPersona,		\
						c.Firma				\
				     from personas as a inner join		\
				     	  TiposPersona as b using(TipoPersona)  inner join \
					  firmas as c using(idpersona)";


const char *gchrPtrFtoResCnsPersonas=	"TipoDato,		\
					IdPersona,		\
					Nombre,			\
					APaterno,		\
					AMaterno,		\
					RFC,			\
					TipoPersona,		\
					Calle,			\
					Numero,			\
					Colonia,		\
					CP,			\
					Municipio,		\
					Estado,			\
					Referencias,		\
					Telefono,		\
					Correo,			\
					Firma,			\
					Password,		\
					NmbPerfil,		\
					DscPerfil,		\
					IdUsuarioBDSeguridad3";

						
void Principal(int pintSocket)
{
SSiscomOperaciones *lSSiscomOp=0;
int lintContador;
char *lchrPtrOperacion=0;
int lintNRegistros;
SSiscomOperaciones2 *lSOpPtrOperaciones=0;
SiscomOperaciones2 *lSOpPtrSistema;
SArgsSiscom lSArgsSiscomDat;
	memset(&lSArgsSiscomDat,0,sizeof(SArgsSiscom));
	OperacionesSistemaGeneral(&lSSiscomOp);
	SiscomLeeNumeroRegistros(pintSocket,
				 &lintNRegistros);	
	SiscomLeeOperacion(pintSocket,
                           &lchrPtrOperacion);
	for(lintContador=0;
            lintContador<lSSiscomOp->intNumOperaciones;
            lintContador++)
        if(!strcmp((lSSiscomOp+lintContador)->chrPtrOperacion,
                   lchrPtrOperacion))
        {
             (lSSiscomOp+lintContador)->Operacion(pintSocket,lintNRegistros);
             return ;
        }
	SiscomLog("MAIN:Operacion {%s} No Soportada En La version 1.0 se busca en la version 2",
		  lchrPtrOperacion);

	AsignaOperacionesVersion2(pintSocket,
				  lintNRegistros,
				  &lSOpPtrOperaciones,
				  &lSArgsSiscomDat);
	ManejadorErrores(&lSArgsSiscomDat);
	lSOpPtrSistema=SiscomOperaciones2CualEjecuta(
				lchrPtrOperacion,
				lSOpPtrOperaciones,
				SiscomErrorOperacion2,
				&lSArgsSiscomDat);
	SiscomOperaciones2Ejecuta(lSOpPtrSistema,
				  &lSArgsSiscomDat);

}

void AsignaOperacionesVersion2(int pintSocket,
			       int pintNRegistros,
			       SSiscomOperaciones2 **pSSOperaciones2,
			       SArgsSiscom *pSArgsSiscom)
{
pSArgsSiscom->intSocketCliente=pintSocket;
pSArgsSiscom->intNRegistrosDat=pintNRegistros;
SiscomLog("");

SiscomAnexaOperacion2("ConsultasElFresno",
		      OConsultasElFresno(),
		      pSSOperaciones2);
SiscomAnexaOperacion2("BorraEmpleado",
		      OBorraEmpleado(),
		      pSSOperaciones2);
/*
SiscomAnexaOperacion2("ConsultasGimnasios",
		      OConsultasGimnasios(),
		      pSSOperaciones2);
SiscomAnexaOperacion2("RegistraEntrenamiento",
		      ORegistraEntrenamiento(),
		      pSSOperaciones2);
*/
}

void SiscomErrorOperacion2(SArgsSiscom *pSAgsSisPtr)
{
SiscomMensajesLog2("Operacion No Soportada");
}
void OperacionesSistemaGeneral(SSiscomOperaciones **pSSiscomOp)
{

	SiscomIniciaOperaciones(14,pSSiscomOp);
	SiscomAnexaOperacion("ActualizaProveedor",
			     ActualizaProveedor,
			     pSSiscomOp);
	SiscomAnexaOperacion("AnexaDireccion",
			     AnexaDireccion,
			     pSSiscomOp);
	SiscomAnexaOperacion("AnexaContacto",
			     AnexaContacto,
			     pSSiscomOp);
	SiscomAnexaOperacion("AnexaTelefono",
			     AnexaTelefono,
			     pSSiscomOp);
	SiscomAnexaOperacion("ConsultaVehiculos",
			     ConsultaVehiculos,
			     pSSiscomOp);
	SiscomAnexaOperacion("ModificaVehiculo",
			     ModificaVehiculo,
			     pSSiscomOp);
	SiscomAnexaOperacion("EliminaVehiculo",
			     EliminaVehiculo,
			     pSSiscomOp);
	SiscomAnexaOperacion("ModificaFamilia",
			     ModificaFamilia,
			     pSSiscomOp);
	SiscomAnexaOperacion("ModificaUnidad",
			     ModificaUnidad,
			     pSSiscomOp);
	SiscomAnexaOperacion("ModificaProducto",
			     ModificaProducto,
			     pSSiscomOp);
	SiscomAnexaOperacion("ConsultaPersonas",
			     ConsultaPersonas,
			     pSSiscomOp);
	SiscomAnexaOperacion("FijaFechaCorte",
			     FijaFechaCorte,
			     pSSiscomOp);
	SiscomAnexaOperacion("ConsultaCorteExistencias",
			     ConsultaCorteExistencias,
			     pSSiscomOp);
	SiscomAnexaOperacion("ConsultaSeguridad3Pro2",
			      ConsultaSeguridad3Pro2,
			      pSSiscomOp);
}
void ActualizaProveedor(int pintSocket,
		       int pintNRegistros)
{
LCamposSiscomPro2 *lLCSiscomPro2=0;
LCamposSiscomPro2 *lLCSiscomPro2Ins=0,
                  *lLCSiscomPro2InsAct=0;
char lchrArrActualiza[1204];
char *lchrPtrEdoConexion=0;
int lintNRegistros=0,
    lintSocketAD;
SiscomLeeInformacionProtocolo(pintSocket,
                                      pintNRegistros,
                                      &lLCSiscomPro2);
  for(;
  	lLCSiscomPro2;
	lLCSiscomPro2=lLCSiscomPro2->SCP2PtrSig)
  {
  	
	 sprintf(lchrArrActualiza,
	 	 "update empresas	\
		  set RazonSocial='%s', \
		      RFC='%s'		\
		  where idEmpresa=%s",
		  SiscomObtenDato(lLCSiscomPro2,"RazonSocial"),
		  SiscomObtenDato(lLCSiscomPro2,"RFC"),
		  SiscomObtenDato(lLCSiscomPro2,"IdEmpresa"));
	 SiscomAnexaRegistroPro2(&lLCSiscomPro2Ins,
	 			 &lLCSiscomPro2InsAct,
				 &lintNRegistros,
				 "ComandoSQL",
				 lchrArrActualiza);

  }
	SiscomInformacionServidor(gSSiscomConfiguracionSvr.intPtoAccesoDatos,
	                          gSSiscomConfiguracionSvr.chrPtrDirIpAccesoDatos,
				  "Inserciones",
				  lintNRegistros,
				  lLCSiscomPro2Ins,
				  &lchrPtrEdoConexion,
				  &lintSocketAD);
	if(lchrPtrEdoConexion)
	SiscomMensajesLog(gPtrFleArchivoLog,
			  "Error Al Enviar:%s",
	                  lchrPtrEdoConexion);
}
void AnexaDireccion(int pintSocket,
		       int pintNRegistros)
{
LCamposSiscomPro2 *lLCSiscomPro2=0;
LCamposSiscomPro2 *lLCSiscomPro2Ins=0,
                  *lLCSiscomPro2InsAct=0;
char lchrArrActualiza[1204];
char *lchrPtrEdoConexion=0;
int lintNRegistros=0,
    lintSocketAD;
SiscomLeeInformacionProtocolo(pintSocket,
                                      pintNRegistros,
                                      &lLCSiscomPro2);
  for(;
  	lLCSiscomPro2;
	lLCSiscomPro2=lLCSiscomPro2->SCP2PtrSig)
  {
  	
	 sprintf(lchrArrActualiza,
	 	"insert into Direcciones values(0,%s,'%s','%s','%s','%s','%s','%s','');",
		  SiscomObtenDato(lLCSiscomPro2,"IdPersonaEmpresa"),
		  SiscomObtenDato(lLCSiscomPro2,"Calle"),
		  SiscomObtenDato(lLCSiscomPro2,"Numero"),
		  SiscomObtenDato(lLCSiscomPro2,"Colonia"),
		  SiscomObtenDato(lLCSiscomPro2,"CP"),
		  SiscomObtenDato(lLCSiscomPro2,"Municipio"),
		  SiscomObtenDato(lLCSiscomPro2,"Estado"));
	 SiscomAnexaRegistroPro2(&lLCSiscomPro2Ins,
	 			 &lLCSiscomPro2InsAct,
				 &lintNRegistros,
				 "ComandoSQL",
				 lchrArrActualiza);

  }
	SiscomInformacionServidor(gSSiscomConfiguracionSvr.intPtoAccesoDatos,
	                          gSSiscomConfiguracionSvr.chrPtrDirIpAccesoDatos,
				  "Inserciones",
				  lintNRegistros,
				  lLCSiscomPro2Ins,
				  &lchrPtrEdoConexion,
				  &lintSocketAD);
	if(lchrPtrEdoConexion)
	SiscomMensajesLog(gPtrFleArchivoLog,
			  "Error Al Enviar:%s",
	                  lchrPtrEdoConexion);
}
void AnexaContacto(int pintSocket,
		       int pintNRegistros)
{
LCamposSiscomPro2 *lLCSiscomPro2=0;
LCamposSiscomPro2 *lLCSiscomPro2Ins=0,
                  *lLCSiscomPro2InsAct=0;
char lchrArrActualiza[1204];
char *lchrPtrEdoConexion=0;
int lintNRegistros=0,
    lintSocketAD;
int lintIdContacto,
    lintContador;
SiscomLeeInformacionProtocolo(pintSocket,
                                      pintNRegistros,
                                      &lLCSiscomPro2);
  for(lintContador=0;
  	lLCSiscomPro2;
	lLCSiscomPro2=lLCSiscomPro2->SCP2PtrSig,
	lintContador++)
  {
  	lintIdContacto=SiscomObtenNumeroUnico()+lintContador;	
	 sprintf(lchrArrActualiza,
	 	"insert into Personas values('%s','%s','%s','%s',%ld,2);",
		  SiscomObtenDato(lLCSiscomPro2,"Nombre"),
		  SiscomObtenDato(lLCSiscomPro2,"APaterno"),
		  SiscomObtenDato(lLCSiscomPro2,"AMaterno"),
		  SiscomObtenDato(lLCSiscomPro2,"RFC"),
		  lintIdContacto);
	 SiscomAnexaRegistroPro2(&lLCSiscomPro2Ins,
	 			 &lLCSiscomPro2InsAct,
				 &lintNRegistros,
				 "ComandoSQL",
				 lchrArrActualiza);
	sprintf(lchrArrActualiza,
	 	"insert into Contactos values(%ld,%s,'%s');",
		  lintIdContacto,
		  SiscomObtenDato(lLCSiscomPro2,"IdEmpresa"),
		  SiscomObtenDato(lLCSiscomPro2,"Descripcion"));
	 SiscomAnexaRegistroPro2(&lLCSiscomPro2Ins,
	 			 &lLCSiscomPro2InsAct,
				 &lintNRegistros,
				 "ComandoSQL",
				 lchrArrActualiza);


  }
  	SiscomImprimeContenidoProtocolo("",
					gPtrFleArchivoLog,
					lLCSiscomPro2Ins);
	SiscomInformacionServidor(gSSiscomConfiguracionSvr.intPtoAccesoDatos,
	                          gSSiscomConfiguracionSvr.chrPtrDirIpAccesoDatos,
				  "Inserciones",
				  lintNRegistros,
				  lLCSiscomPro2Ins,
				  &lchrPtrEdoConexion,
				  &lintSocketAD);
	if(lchrPtrEdoConexion)
	SiscomMensajesLog(gPtrFleArchivoLog,
			  "Error Al Enviar:%s",
	                  lchrPtrEdoConexion);
}

void AnexaTelefono(int pintSocket,
		       int pintNRegistros)
{
LCamposSiscomPro2 *lLCSiscomPro2=0;
LCamposSiscomPro2 *lLCSiscomPro2Ins=0,
                  *lLCSiscomPro2InsAct=0;
char lchrArrActualiza[1204];
char *lchrPtrEdoConexion=0;
int lintNRegistros=0,
    lintSocketAD;
SiscomLeeInformacionProtocolo(pintSocket,
                                      pintNRegistros,
                                      &lLCSiscomPro2);
  for(;
  	lLCSiscomPro2;
	lLCSiscomPro2=lLCSiscomPro2->SCP2PtrSig)
  {
  	
	 sprintf(lchrArrActualiza,
	 	 "insert into telefonos values(0,%s,'%s [%s]');",
		  SiscomObtenDato(lLCSiscomPro2,"IdEmpresaPersona"),
		  SiscomObtenDato(lLCSiscomPro2,"Medio"),
		  SiscomObtenDato(lLCSiscomPro2,"Descripcion"));
	 SiscomAnexaRegistroPro2(&lLCSiscomPro2Ins,
	 			 &lLCSiscomPro2InsAct,
				 &lintNRegistros,
				 "ComandoSQL",
				 lchrArrActualiza);

  }
	SiscomInformacionServidor(gSSiscomConfiguracionSvr.intPtoAccesoDatos,
                          gSSiscomConfiguracionSvr.chrPtrDirIpAccesoDatos,
				  "Inserciones",
				  lintNRegistros,
				  lLCSiscomPro2Ins,
				  &lchrPtrEdoConexion,
				  &lintSocketAD);
	if(lchrPtrEdoConexion)
	SiscomMensajesLog(gPtrFleArchivoLog,
			  "Error Al Enviar:%s",
	                  lchrPtrEdoConexion);
}
void AnalizaConsultaSolicitada(SiscomOperacionesServidor *pSOpServidor)
{
LCamposSiscomPro2 *lLCSiscomPro2=pSOpServidor->LCSiscomPro2Dat;
	if(!strcmp("Todos",
	           SiscomObtenDato(lLCSiscomPro2,"Parametro")))
	{
	SiscomInformacionOperaciones("ConsultaSQL",
				     "Consultas",
				     pSOpServidor);
	SiscomAnexaRegistroPro2(&pSOpServidor->LCSiscomPro2EPrim,
				&pSOpServidor->LCSiscomPro2EAct,
				&pSOpServidor->intNRegistros,
				"ConsultaSQL",
				"select * from vehiculos");	
	}

}
void ConsultaVehiculos(int pintSocket,
		       int pintNRegistros)
{

SiscomOperacionesServidor lSOpServidor;

	SiscomIniciaComunicacionesSrv(gSSiscomConfiguracionSvr.chrPtrDirIpAccesoDatos,
				   gSSiscomConfiguracionSvr.intPtoAccesoDatos,
				   &lSOpServidor);
	SiscomLeeInformacionProtocolo(pintSocket,
				      pintNRegistros,
				      &lSOpServidor.LCSiscomPro2Dat);
	AnalizaConsultaSolicitada(&lSOpServidor);
	SiscomOperacionesServidores(&lSOpServidor);
	SiscomImprimeContenidoProtocolo("",
					gPtrFleArchivoLog,
					lSOpServidor.LCSiscomPro2);
	SiscomEnviaAlServidor(pintSocket,
			      lSOpServidor.intNRegistrosRes,
			      "RespuestaVehiculos",
			      lSOpServidor.LCSiscomPro2);
	close(pintSocket);


}
void ModificaVehiculo(int pintSocket,
		       int pintNRegistros)
{
LCamposSiscomPro2 *lLCSiscomPro2=0;
LCamposSiscomPro2 *lLCSiscomPro2Ins=0,
                  *lLCSiscomPro2InsAct=0;
char lchrArrActualiza[1204];
char *lchrPtrEdoConexion=0;
int lintNRegistros=0,
    lintSocketAD;
SiscomLeeInformacionProtocolo(pintSocket,
                                      pintNRegistros,
                                      &lLCSiscomPro2);
  for(;
  	lLCSiscomPro2;
	lLCSiscomPro2=lLCSiscomPro2->SCP2PtrSig)
  {
  	
	 sprintf(lchrArrActualiza,
	 	 "update vehiculos 	      \
		         set placas='%s',     \
		 	     dscVehiculo='%s' \
		  where idVehiculo=%s",
		  SiscomObtenDato(lLCSiscomPro2,"Placas"),
		  SiscomObtenDato(lLCSiscomPro2,"Descripcion"),
		  SiscomObtenDato(lLCSiscomPro2,"IdVehiculo"));
	 SiscomAnexaRegistroPro2(&lLCSiscomPro2Ins,
	 			 &lLCSiscomPro2InsAct,
				 &lintNRegistros,
				 "ComandoSQL",
				 lchrArrActualiza);

  }
	SiscomInformacionServidor(gSSiscomConfiguracionSvr.intPtoAccesoDatos,
	                          gSSiscomConfiguracionSvr.chrPtrDirIpAccesoDatos,
				  "Inserciones",
				  lintNRegistros,
				  lLCSiscomPro2Ins,
				  &lchrPtrEdoConexion,
				  &lintSocketAD);
	if(lchrPtrEdoConexion)
	SiscomMensajesLog(gPtrFleArchivoLog,
			  "Error Al Enviar:%s",
	                  lchrPtrEdoConexion);
}
void EliminaVehiculo(int pintSocket,
		       int pintNRegistros)
{
LCamposSiscomPro2 *lLCSiscomPro2=0;
LCamposSiscomPro2 *lLCSiscomPro2Ins=0,
                  *lLCSiscomPro2InsAct=0;
char lchrArrActualiza[1204];
char *lchrPtrEdoConexion=0;
int lintNRegistros=0,
    lintSocketAD;
SiscomLeeInformacionProtocolo(pintSocket,
                                      pintNRegistros,
                                      &lLCSiscomPro2);
  for(;
  	lLCSiscomPro2;
	lLCSiscomPro2=lLCSiscomPro2->SCP2PtrSig)
  {
  	
	 sprintf(lchrArrActualiza,
	 	 "delete from vehiculos \
		  where idVehiculo=%s",
		  SiscomObtenDato(lLCSiscomPro2,"IdVehiculo"));
	 SiscomAnexaRegistroPro2(&lLCSiscomPro2Ins,
	 			 &lLCSiscomPro2InsAct,
				 &lintNRegistros,
				 "ComandoSQL",
				 lchrArrActualiza);

  }
	SiscomInformacionServidor(gSSiscomConfiguracionSvr.intPtoAccesoDatos,
	                          gSSiscomConfiguracionSvr.chrPtrDirIpAccesoDatos,
				  "Inserciones",
				  lintNRegistros,
				  lLCSiscomPro2Ins,
				  &lchrPtrEdoConexion,
				  &lintSocketAD);
	if(lchrPtrEdoConexion)
	SiscomMensajesLog(gPtrFleArchivoLog,
			  "Error Al Enviar:%s",
	                  lchrPtrEdoConexion);
}
void ActualizaFamiliaSQL(int pintPtoCom,
			 const char *pchrPtrDirIpSvr,
			 const char *pchrPtrBaseDatos,
			 const char *pchrPtrPtoBaseDatos,
			 LCamposSiscomPro2 *pLCSiscomPro2,
			 char *pchrPtrActualiza)
{

	sprintf(pchrPtrActualiza,
		"update familias 		\
		        set NmbFamilia='%s',	\
			    DscFamilia='%s'	\
	         where idFamilia=%s",
		 SiscomObtenDato(pLCSiscomPro2,"NmbFamilia"),
		 SiscomObtenDato(pLCSiscomPro2,"Descripcion"),
		 SiscomObtenDato(pLCSiscomPro2,"IdFamilia"));
		 		 



}
void ModificaFamilia(int pintSocket,
		    int pintNRegistros)
{
char lchrArrBuffer[256];
	SiscomFormaComandosSql(
		pintSocket,
		pintNRegistros,
		gSSiscomConfiguracionSvr.intPtoAccesoDatos,
		gSSiscomConfiguracionSvr.chrPtrDirIpAccesoDatos,
		0,
		0,
		ActualizaFamiliaSQL,
		lchrArrBuffer,
		0);
}
void ActualizaUnidadSQL(int pintPtoCom,
			 const char *pchrPtrDirIpSvr,
			 const char *pchrPtrBaseDatos,
			 const char *pchrPtrPtoBaseDatos,
			 LCamposSiscomPro2 *pLCSiscomPro2,
			 char *pchrPtrActualiza)
{

	sprintf(pchrPtrActualiza,
		"update Unidades \
		        set NmbUnidad='%s',	\
			    Abreviatura='%s'	\
	         where Unidad=%s",
		 SiscomObtenDato(pLCSiscomPro2,"NmbUnidad"),
		 SiscomObtenDato(pLCSiscomPro2,"Abreviatura"),
		 SiscomObtenDato(pLCSiscomPro2,"Unidad"));
}
void ModificaUnidad(int pintSocket,
		  int pintNRegistros)

{
char lchrArrBuffer[256];
	SiscomFormaComandosSql(
		pintSocket,
		pintNRegistros,
		gSSiscomConfiguracionSvr.intPtoAccesoDatos,
		gSSiscomConfiguracionSvr.chrPtrDirIpAccesoDatos,
		0,
		0,
		ActualizaUnidadSQL,
		lchrArrBuffer,
		0);



}
void ActualizaProductoSQL(int pintPtoCom,
			 const char *pchrPtrDirIpSvr,
			 const char *pchrPtrBaseDatos,
			 const char *pchrPtrPtoBaseDatos,
			 LCamposSiscomPro2 *pLCSiscomPro2,
			 char *pchrPtrActualiza)
{

	sprintf(pchrPtrActualiza,
		"update Productos  		\
		        set DscProducto='%s',	\
			    Unidad =%s,		\
			    idFamilia=%s 	\
	         where CveProducto='%s'",
		 SiscomObtenDato(pLCSiscomPro2,"Descripcion"),
		 SiscomObtenDato(pLCSiscomPro2,"Unidad"),
		 SiscomObtenDato(pLCSiscomPro2,"IdFamilia"),
		 SiscomObtenDato(pLCSiscomPro2,"Clave"));
}
void ModificaProducto(int pintSocket,
		     int pintNRegistros)
{
char lchrArrBuffer[256];
	SiscomFormaComandosSql(
		pintSocket,
		pintNRegistros,
		gSSiscomConfiguracionSvr.intPtoAccesoDatos,
		gSSiscomConfiguracionSvr.chrPtrDirIpAccesoDatos,
		0,
		0,
		ActualizaProductoSQL,
		lchrArrBuffer,
		0);
}
void ConsultaPersonas(int pintSocket,
		     int pintNRegistros)
{
SiscomOperacionesServidor lSOpServidor;
LCamposSiscomPro2 *lLCSiscomPro2Direcciones=0;
LCamposSiscomPro2 *lLCSiscomPro2Telefonos=0;
LCamposSiscomPro2 *lLCSiscomPro2Correos=0;
LCamposSiscomPro2 *lLCSiscomPro2Respuesta=0;
LCamposSiscomPro2 *lLCSiscomPro2Firmas=0;
char *lchrPtrCondicion=0;
int lintNRegRespuesta;

	SiscomIniciaComunicacionesSrv(gSSiscomConfiguracionSvr.chrPtrDirIpAccesoDatos,
				   gSSiscomConfiguracionSvr.intPtoAccesoDatos,
				   &lSOpServidor);
	SiscomLeeInformacionProtocolo(pintSocket,
				      pintNRegistros,
				      &lSOpServidor.LCSiscomPro2Dat);
	AnalizaConsultaSolicitadaPersonas(&lSOpServidor);
	SiscomOperacionesServidores(&lSOpServidor);
	GeneraCondicionConsultaDatosPersona(lSOpServidor.LCSiscomPro2,&lchrPtrCondicion);
	ConsultaDirecciones(lchrPtrCondicion,&lLCSiscomPro2Direcciones);
	ConsultaTelefonos(lchrPtrCondicion,&lLCSiscomPro2Telefonos);
	ConsultaCorreos(lchrPtrCondicion,&lLCSiscomPro2Correos);
	ConsultaFirmas(lSOpServidor.LCSiscomPro2,&lLCSiscomPro2Firmas);
	GeneraRespuestaConsultaPersonas(lSOpServidor.LCSiscomPro2,
				lLCSiscomPro2Direcciones,
				lLCSiscomPro2Telefonos,
				lLCSiscomPro2Correos,
				lLCSiscomPro2Firmas,
				&lintNRegRespuesta,
				&lLCSiscomPro2Respuesta);
	SiscomImprimeContenidoProtocolo("",
					gPtrFleArchivoLog,
					lLCSiscomPro2Respuesta);
	SiscomEnviaAlServidor(pintSocket,
			      lintNRegRespuesta,
			      "RespuestaVehiculos",
			      lLCSiscomPro2Respuesta);

}
void AnalizaConsultaSolicitadaPersonas(SiscomOperacionesServidor *pSOpServidor)
{
char lchrArrConsulta[1024];
LCamposSiscomPro2 *lLCSiscomPro2=pSOpServidor->LCSiscomPro2Dat;
	if(!SiscomObtenDato(lLCSiscomPro2,"Nombre")[0]		&&
	   !SiscomObtenDato(lLCSiscomPro2,"APaterno")[0]	&&
	   !SiscomObtenDato(lLCSiscomPro2,"AMaterno")[0]	&&
	   !SiscomObtenDato(lLCSiscomPro2,"RFC")[0])
	{
	SiscomInformacionOperaciones("ConsultaSQL",
				     "Consultas",
				     pSOpServidor);
	sprintf(lchrArrConsulta,
		"%s 				\
		 where tipoPersona!=1 and	\
		       tipoPersona!=2		\
		 order by idPersona",
		 gchrPtrConsultaPersonas);

	SiscomAnexaRegistroPro2(&pSOpServidor->LCSiscomPro2EPrim,
				&pSOpServidor->LCSiscomPro2EAct,
				&pSOpServidor->intNRegistros,
				"ConsultaSQL",
				lchrArrConsulta);
	}
	else
	if(SiscomObtenDato(lLCSiscomPro2,"Nombre")[0]		&&
	   SiscomObtenDato(lLCSiscomPro2,"APaterno")[0]	&&
	   SiscomObtenDato(lLCSiscomPro2,"AMaterno")[0]	&&
	   !SiscomObtenDato(lLCSiscomPro2,"RFC")[0])
	{
	SiscomInformacionOperaciones("ConsultaSQL",
				     "Consultas",
				     pSOpServidor);
	sprintf(lchrArrConsulta,
		"%s 				\
		 where Nombre='%s' and		\
		       APaterno='%s' and	\
		       AMaterno='%s' 		\
		 order by idPersona",
		 gchrPtrConsultaPersonas,
		SiscomObtenDato(lLCSiscomPro2,"Nombre"),
		SiscomObtenDato(lLCSiscomPro2,"APaterno"),
		SiscomObtenDato(lLCSiscomPro2,"AMaterno"));
	SiscomAnexaRegistroPro2(&pSOpServidor->LCSiscomPro2EPrim,
				&pSOpServidor->LCSiscomPro2EAct,
				&pSOpServidor->intNRegistros,
				"ConsultaSQL",
				lchrArrConsulta);
	}
}
void GeneraCondicionConsultaDatosPersona(LCamposSiscomPro2 *pLCSiscomPro2,
					char **pchrPtrCondicion)
{
char lchrArrPaso[128];
int lintTam;
   *pchrPtrCondicion=strdup("in(");
 for(;
     pLCSiscomPro2;
     pLCSiscomPro2=pLCSiscomPro2->SCP2PtrSig)
 {
 	if(pLCSiscomPro2->SCP2PtrSig)
 	sprintf(lchrArrPaso,
		"%s,",
		SiscomObtenDato(pLCSiscomPro2,"idpersona"));
	else
	sprintf(lchrArrPaso,
		"%s)",
		SiscomObtenDato(pLCSiscomPro2,"idpersona"));
	*pchrPtrCondicion=(char *)realloc(*pchrPtrCondicion,
					  strlen(*pchrPtrCondicion)+
					  strlen(lchrArrPaso)+1);
	strcat(*pchrPtrCondicion,lchrArrPaso);
 }
	
}
void EjecutaConsultaGeneralABDElFresno(const char *pchrPtrConsulta,
				      LCamposSiscomPro2 **pLCSiscomPro2Reg)
{
SiscomOperacionesServidor lSOpServidor;
	SiscomIniciaComunicacionesSrv(gSSiscomConfiguracionSvr.chrPtrDirIpAccesoDatos,
				   gSSiscomConfiguracionSvr.intPtoAccesoDatos,
				   &lSOpServidor);
	SiscomInformacionOperaciones("ConsultaSQL",
				     "Consultas",
				     &lSOpServidor);
	SiscomAnexaRegistroPro2(&lSOpServidor.LCSiscomPro2EPrim,
				&lSOpServidor.LCSiscomPro2EAct,
				&lSOpServidor.intNRegistros,
				"ConsultaSQL",
				pchrPtrConsulta);	
	SiscomOperacionesServidores(&lSOpServidor);
	*pLCSiscomPro2Reg=lSOpServidor.LCSiscomPro2;

}
void ConsultaDirecciones(char *pchrPtrCondicion,
			 LCamposSiscomPro2 **pLCSiscomPro2Reg)
{
char *lchrPtrConsulta;
	lchrPtrConsulta=(char *)malloc(strlen(pchrPtrCondicion)+128);

	sprintf(lchrPtrConsulta,
		"select *				\
		 from direcciones 			\
		 where idPersona %s 			\
		 order by idPersona",
		 pchrPtrCondicion);
	EjecutaConsultaGeneralABDElFresno(lchrPtrConsulta,pLCSiscomPro2Reg);
}
void ConsultaTelefonos(char *pchrPtrCondicion,
			 LCamposSiscomPro2 **pLCSiscomPro2Reg)
{
char *lchrPtrConsulta;
	lchrPtrConsulta=(char *)malloc(strlen(pchrPtrCondicion)+128);
	sprintf(lchrPtrConsulta,
		"select *		\
		 from telefonos 	\
		 where idPersona %s 	\
		 order by idPersona",
		 pchrPtrCondicion);
	EjecutaConsultaGeneralABDElFresno(lchrPtrConsulta,pLCSiscomPro2Reg);

}
void ConsultaCorreos(char *pchrPtrCondicion,
			 LCamposSiscomPro2 **pLCSiscomPro2Reg)
{
char *lchrPtrConsulta;
	lchrPtrConsulta=(char *)malloc(strlen(pchrPtrCondicion)+128);
sprintf(lchrPtrConsulta,
		"select *		\
		 from correos 		\
		 where idPersona %s 	\
		 order by idPersona",
		 pchrPtrCondicion);
	EjecutaConsultaGeneralABDElFresno(lchrPtrConsulta,pLCSiscomPro2Reg);

}
void AnexaDireccionesPersona(LCamposSiscomPro2 *pLCSiscomPro2Persona,
			     LCamposSiscomPro2 *pLCSiscomPro2Dir,
			     int *pintPtrNRegistros,
			     LCamposSiscomPro2 **pLCSiscomPro2Res,
			     LCamposSiscomPro2 **pLCSiscomPro2ResAct)
{
int lintUnaDireccion=0;

	for(;
	    pLCSiscomPro2Dir;
	    pLCSiscomPro2Dir=pLCSiscomPro2Dir->SCP2PtrSig)
	{
	   if(!strcmp(SiscomObtenDato(pLCSiscomPro2Persona,"idpersona"),
	   	      SiscomObtenDato(pLCSiscomPro2Dir,"idpersona")))
	   {
	     lintUnaDireccion=1;
	     SiscomAnexaRegistroPro2(
	   	pLCSiscomPro2Res,
	   	pLCSiscomPro2ResAct,
		pintPtrNRegistros,
		gchrPtrFtoResCnsPersonas,
		"Direccion",
		"",
		"",
		"",
		"",
		"",
		"",
		SiscomObtenDato(pLCSiscomPro2Dir,"calle"),
		SiscomObtenDato(pLCSiscomPro2Dir,"numero"),
		SiscomObtenDato(pLCSiscomPro2Dir,"colonia"),
		SiscomObtenDato(pLCSiscomPro2Dir,"cp"),
		SiscomObtenDato(pLCSiscomPro2Dir,"municipio"),
		SiscomObtenDato(pLCSiscomPro2Dir,"estado"),
		SiscomObtenDato(pLCSiscomPro2Dir,"referencias"),
		"",
		"",
		"",
		"",
		"",
		"",
		"");


	   }

	}
	if(!lintUnaDireccion)
	SiscomAnexaRegistroPro2(
	   	pLCSiscomPro2Res,
	   	pLCSiscomPro2ResAct,
		pintPtrNRegistros,
		gchrPtrFtoResCnsPersonas,
		"Direccion",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"");

}
void AnexaTelefonosPersona(LCamposSiscomPro2 *pLCSiscomPro2Persona,
			     LCamposSiscomPro2 *pLCSiscomPro2Tel,
			     int *pintPtrNRegistros,
			     LCamposSiscomPro2 **pLCSiscomPro2Res,
			     LCamposSiscomPro2 **pLCSiscomPro2ResAct)
{
int lintUnTelefono=0;

	for(;
	    pLCSiscomPro2Tel;
	    pLCSiscomPro2Tel=pLCSiscomPro2Tel->SCP2PtrSig)
	{
	   if(!strcmp(SiscomObtenDato(pLCSiscomPro2Persona,"idpersona"),
	   	      SiscomObtenDato(pLCSiscomPro2Tel,"idpersona")))
	   {
	     lintUnTelefono=1;
	    SiscomAnexaRegistroPro2(
	   	pLCSiscomPro2Res,
	   	pLCSiscomPro2ResAct,
		pintPtrNRegistros,
		gchrPtrFtoResCnsPersonas,
		"Telefono",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		SiscomObtenDato(pLCSiscomPro2Tel,"telefono"),
		"",
		"",
		"",
		"",
		"",
		"");


	   }
	
	}
	    
if(!lintUnTelefono)
SiscomAnexaRegistroPro2(
	   	pLCSiscomPro2Res,
	   	pLCSiscomPro2ResAct,
		pintPtrNRegistros,
		gchrPtrFtoResCnsPersonas,
		"Telefono",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"");


}
void AnexaCorreosPersona(LCamposSiscomPro2 *pLCSiscomPro2Persona,
			     LCamposSiscomPro2 *pLCSiscomPro2Cor,
			     int *pintPtrNRegistros,
			     LCamposSiscomPro2 **pLCSiscomPro2Res,
			     LCamposSiscomPro2 **pLCSiscomPro2ResAct)
{
int lintUnCorreo=0;

	for(;
	     pLCSiscomPro2Cor;
	     pLCSiscomPro2Cor=pLCSiscomPro2Cor=pLCSiscomPro2Cor->SCP2PtrSig)
	{
	   if(!strcmp(SiscomObtenDato(pLCSiscomPro2Persona,"idpersona"),
	   	      SiscomObtenDato(pLCSiscomPro2Cor,"idpersona")))
	   {
	     lintUnCorreo=1;
	SiscomAnexaRegistroPro2(
	   	pLCSiscomPro2Res,
	   	pLCSiscomPro2ResAct,
		pintPtrNRegistros,
		gchrPtrFtoResCnsPersonas,
		"Correos",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		SiscomObtenDato(pLCSiscomPro2Cor,"correo"),
		"",
		"",
		"",
		"",
		"");
	   }
	}
if(!lintUnCorreo)
SiscomAnexaRegistroPro2(
	   	pLCSiscomPro2Res,
	   	pLCSiscomPro2ResAct,
		pintPtrNRegistros,
		gchrPtrFtoResCnsPersonas,
		"Correos",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"");


}

void AnexaFirmaPersona(LCamposSiscomPro2 *pLCSiscomPro2Persona,
			     LCamposSiscomPro2 *pLCSiscomPro2Fir,
			     int *pintPtrNRegistros,
			     LCamposSiscomPro2 **pLCSiscomPro2Res,
			     LCamposSiscomPro2 **pLCSiscomPro2ResAct)
{
int lintUnaFirma=0;

	SiscomImprimeContenidoProtocolo("",
					gPtrFleArchivoLog,
					pLCSiscomPro2Persona);
	SiscomImprimeContenidoProtocolo("",
					gPtrFleArchivoLog,
					pLCSiscomPro2Fir);
	for(;
	     pLCSiscomPro2Fir;
	     pLCSiscomPro2Fir=pLCSiscomPro2Fir=pLCSiscomPro2Fir->SCP2PtrSig)
	{
	   if(!strcmp(SiscomObtenDato(pLCSiscomPro2Persona,"tipopersona"),
	   	      SiscomObtenDato(pLCSiscomPro2Fir,"idperfil"))  &&
	      !strcmp(SiscomObtenDato(pLCSiscomPro2Persona,"firma"),
	      	      SiscomObtenDato(pLCSiscomPro2Fir,"firma")))
	   {
	     lintUnaFirma=1;
	SiscomAnexaRegistroPro2(
	   	pLCSiscomPro2Res,
	   	pLCSiscomPro2ResAct,
		pintPtrNRegistros,
		gchrPtrFtoResCnsPersonas,
		"Firma",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		SiscomObtenDato(pLCSiscomPro2Persona,"firma"),
		SiscomObtenDato(pLCSiscomPro2Fir,"password"),
		SiscomObtenDato(pLCSiscomPro2Fir,"nmbperfil"),
		SiscomObtenDato(pLCSiscomPro2Fir,"dscperfil"),
		SiscomObtenDato(pLCSiscomPro2Fir,"idusuario"));
	   }
	}
if(!lintUnaFirma)
SiscomAnexaRegistroPro2(
	   	pLCSiscomPro2Res,
	   	pLCSiscomPro2ResAct,
		pintPtrNRegistros,
		gchrPtrFtoResCnsPersonas,
		"Firma",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"");


}

void GeneraRespuestaConsultaPersonas(LCamposSiscomPro2 *pLCSiscomPro2Personas,
				     LCamposSiscomPro2 *pLCSiscomPro2Dir,
				     LCamposSiscomPro2 *pLCSiscomPro2Tel,
				     LCamposSiscomPro2 *pLCSiscomPro2Cor,
				     LCamposSiscomPro2 *pLCSiscomPro2Firmas,
				     int *pintPtrNRegistros,
				     LCamposSiscomPro2 **pLCSiscomPro2Res)
{
LCamposSiscomPro2 *lLCSiscomPro2Act=0;

	*pintPtrNRegistros=0;
	for(;
	    pLCSiscomPro2Personas;
	    pLCSiscomPro2Personas=pLCSiscomPro2Personas->SCP2PtrSig)
	{
	   SiscomAnexaRegistroPro2(
	   	pLCSiscomPro2Res,
	   	&lLCSiscomPro2Act,
		pintPtrNRegistros,
		gchrPtrFtoResCnsPersonas,
		"Generales",
		SiscomObtenDato(pLCSiscomPro2Personas,"idpersona"),
		SiscomObtenDato(pLCSiscomPro2Personas,"nombre"),
		SiscomObtenDato(pLCSiscomPro2Personas,"apaterno"),
		SiscomObtenDato(pLCSiscomPro2Personas,"amaterno"),
		SiscomObtenDato(pLCSiscomPro2Personas,"rfc"),
		SiscomObtenDato(pLCSiscomPro2Personas,"tipopersona"),
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"");
	    AnexaDireccionesPersona(pLCSiscomPro2Personas,
				    pLCSiscomPro2Dir,
	    			    pintPtrNRegistros,
				    pLCSiscomPro2Res,
				    &lLCSiscomPro2Act);
	    AnexaTelefonosPersona(pLCSiscomPro2Personas,
				    pLCSiscomPro2Tel,
	    			    pintPtrNRegistros,
				    pLCSiscomPro2Res,
				    &lLCSiscomPro2Act);
	   AnexaCorreosPersona(pLCSiscomPro2Personas,
				    pLCSiscomPro2Cor,
	    			    pintPtrNRegistros,
				    pLCSiscomPro2Res,
				    &lLCSiscomPro2Act);
	 AnexaFirmaPersona(pLCSiscomPro2Personas,
				    pLCSiscomPro2Firmas,
	    			    pintPtrNRegistros,
				    pLCSiscomPro2Res,
				    &lLCSiscomPro2Act);

	}
}
void CondicionPerfiles(LCamposSiscomPro2 *pLCSiscomPro2Personas,
		       char **pchrPtrCondicion)
{
char lchrArrPaso[128];

	*pchrPtrCondicion=strdup("in(");
	for(;
		pLCSiscomPro2Personas;
		pLCSiscomPro2Personas=pLCSiscomPro2Personas->SCP2PtrSig)
	{
		if(pLCSiscomPro2Personas->SCP2PtrSig)
		sprintf(lchrArrPaso,
			"%s,",
			SiscomObtenDato(pLCSiscomPro2Personas,"tipopersona"));
		else
		sprintf(lchrArrPaso,
			"%s)",
			SiscomObtenDato(pLCSiscomPro2Personas,"tipopersona"));
		*pchrPtrCondicion=(char *)realloc(*pchrPtrCondicion,
					 	  strlen(*pchrPtrCondicion)+
						  strlen(lchrArrPaso)+1);
		strcat(*pchrPtrCondicion,lchrArrPaso);	
	}

}
void ConsultaFirmas(LCamposSiscomPro2 *pLCSiscomPro2Personas,
		    LCamposSiscomPro2 **pLCSiscomPro2Firmas)
{
SiscomOperacionesServidor lSOpServidor;
char *lchrPtrCondicion;
char *lchrPtrConsulta;
	CondicionPerfiles(pLCSiscomPro2Personas,&lchrPtrCondicion);
	
	lchrPtrConsulta=(char *)malloc(strlen(lchrPtrCondicion)+512);
	SiscomIniciaComunicacionesSrv(gSSiscomConfiguracionSvr.chrPtrDirIpAccesoDatos,
				   gSSiscomConfiguracionSvr.intPtoAccesoDatos,
				   &lSOpServidor);
	SiscomInformacionOperaciones("ConsultaSQL",
				     "ConsultasBaseDatos",
				     &lSOpServidor);
	sprintf(lchrPtrConsulta,
		"select idperfil,				\
			idusuario,				\
			nmbusuario,				\
			apaterno,				\
			amaterno,				\
			firma,					\
			password,				\
			nmbperfil, 				\
			dscperfil				\
		 from usuarios as a inner join			\
		      firmas using(idusuario) inner join	\
		      perfiles using(idperfil)                  \
		 where idperfil %s 				\
		 order by nmbperfil",
		 lchrPtrCondicion);
	SiscomAnexaRegistroPro2(&lSOpServidor.LCSiscomPro2EPrim,
				&lSOpServidor.LCSiscomPro2EAct,
				&lSOpServidor.intNRegistros,
				"ConsultaSQL,	\
				 BaseDatos,	\
				 PtoBaseDatos",
				 lchrPtrConsulta,
				"Seguridad3",
				"");	
	SiscomOperacionesServidores(&lSOpServidor);
	*pLCSiscomPro2Firmas=lSOpServidor.LCSiscomPro2;
	

}

