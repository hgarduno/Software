#include <RNPersonas.h>
#include <ServidorGeneral.h>

#include <ComunElectronica.h>
#include <ComunElectronica2.h>
#include <string.h>
extern StcSiscomConfiguracion gSSiscomConfiguracionSvr;

int gintNCnsPersonas=6;
StcConsultas gStcCnsPersonas[]={ {EsConsultaClientes,FormaConsultaClientes},
				 {EsConsultaPorRFC,FormaConsultaClienteRFC},
				 {EsConsultaUsuariosSeguridad3,FormaConsultaUsuariosSeguridad3},
				 {EsConsultaPersonaFirma,FormaConsultaDatosFirma},
				 {EsConsultaEmpleadosExpendio,FormaConsultaEmpleadosExpendio},
				 {EsConsultaValidaFirmaEmpleado,FormaConsultaValidaFirmaEmpleado}
				       };

StcRegistraPersona gStcRegPersonas[]={ {"Empleado",RegistraEmpleado}
				      };

int gintNumRegPersonas=1;
void AnalizaConsultaPersonas(char **pchrPtrEntrada,
			     SiscomOperacionesServidor *pSOpServidor)
{
int lintContador;
	
for(lintContador=0;
    lintContador<gintNCnsPersonas;
    lintContador++)
	if(gStcCnsPersonas[lintContador].Consulta(pchrPtrEntrada))
	 gStcCnsPersonas[lintContador].FormaConsulta(pchrPtrEntrada,pSOpServidor);
}
void ConsultaPersonas(int pintSocket,
		      int pintNRegistros)
{
SiscomOperacionesServidor lSOpServidor;
char **lchrPtrEntrada=0;

	lSOpServidor.EjecutaProcesoAntes=0;
	SiscomIniciaComunicacionesSrv(gSSiscomConfiguracionSvr.chrPtrDirIpAccesoDatos,
				      gSSiscomConfiguracionSvr.intPtoAccesoDatos,
				      &lSOpServidor);
	SiscomLeeInformacionProtocolo(pintSocket,
				      pintNRegistros,
				      &lSOpServidor.LCSiscomPro2Dat);
	SiscomContenidoProtocolo(lSOpServidor.LCSiscomPro2Dat);
	SiscomCopiaDatosProtocoloCharChar(lSOpServidor.LCSiscomPro2Dat,
					  pintNRegistros,
					  "Parametro",
					  &lchrPtrEntrada);

	ElectronicaComunicacionExpendio2(lchrPtrEntrada[1],
					 &lSOpServidor.intPtoCom,
					 lSOpServidor.chrPtrDirIpSvr,
					0);
	SiscomLog("Consultando %s:%d",
		  lSOpServidor.chrPtrDirIpSvr,
		  lSOpServidor.intPtoCom);
			
	AnalizaConsultaPersonas(lchrPtrEntrada,&lSOpServidor);
	SiscomOperacionesServidores(&lSOpServidor);
	SiscomEnviaAlServidor(pintSocket,
			      lSOpServidor.intNRegistrosRes,
			      "ClientesRegistrados",
			      lSOpServidor.LCSiscomPro2);
	close(pintSocket);
	


}
int EsConsultaClientes(char **pchrPtrEntrada)
{

	if(!pchrPtrEntrada[0][0] &&
	   !pchrPtrEntrada[1][0] &&
	   !pchrPtrEntrada[2][0] &&
	   !pchrPtrEntrada[3][0] &&
	   !pchrPtrEntrada[4][0] &&
	    pchrPtrEntrada[5][0])
	  return 1;
	  else
	  return 0;
}

void FormaConsultaClientes(char **pchrPtrEntrada,
			   SiscomOperacionesServidor *pSOpServidor)
{
char lchrArrSQL[1024];
/*
 *
 *
 * No tiene sentido agrupar por expendio
 * ya que los expendios se controlan de 
 * forma separada en otro servidor
 *
 *
	sprintf(lchrArrSQL,
		"select *,						\
					'' as firma,			\
					'' as password ,		\
					'' as edofirma			\
				 from personas inner join 		\
				      clienteexpendio  using(idpersona)	\
				 where tipopersona=1 and 		\
				       idempresa=%s",
				 pchrPtrEntrada[6]);

 */
	sprintf(lchrArrSQL,
		"select a.*,		 					\n\
			'' as firma,						\n\
			'' as password ,					\n\
			'' as edofirma						\n\
		 from personas as a inner join 					\n\
		      alumnoescuela as b on (a.idpersona=b.idpersona) 	\n\
		 where tipopersona=1");

	SiscomLog("FormaConsultaClientes:%s",lchrArrSQL);
	SiscomInformacionOperaciones("ConsultaSQL","Consultas",pSOpServidor);
	SiscomAnexaRegistroPro2(&pSOpServidor->LCSiscomPro2EPrim,
				&pSOpServidor->LCSiscomPro2EAct,
				&pSOpServidor->intNRegistros,
				"ConsultaSQL",
				lchrArrSQL);
					SiscomLog(
			  "FormaConsultaClientes:%s",pchrPtrEntrada[6]);
	ElectronicaComunicacionExpendio2(pchrPtrEntrada[6],
					 &pSOpServidor->intPtoCom,
					 pSOpServidor->chrPtrDirIpSvr,
					 0);
}

int EsConsultaPorRFC(char **pchrPtrEntrada)
{
	if(!pchrPtrEntrada[0][0] &&
	   !pchrPtrEntrada[1][0] &&
	   !pchrPtrEntrada[2][0] &&
	   pchrPtrEntrada[3][0] &&
	   !pchrPtrEntrada[4][0] &&
	   !pchrPtrEntrada[5][0])
	  return 1;
	  else
	  return 0;
}
void FormaConsultaClienteRFC(char **pchrPtrEntrada,
			   SiscomOperacionesServidor *pSOpServidor)
{
char lchrArrConsulta[128];
	sprintf(lchrArrConsulta,
		"select *,'' as firma,'' as password 	\
		 from personas	\
		 where rfc='%s'",
		 pchrPtrEntrada[3]);
	SiscomLog("FormaConsultaClientes");
	SiscomInformacionOperaciones("ConsultaSQL","Consultas",pSOpServidor);
	SiscomAnexaRegistroPro2(&pSOpServidor->LCSiscomPro2EPrim,
				&pSOpServidor->LCSiscomPro2EAct,
				&pSOpServidor->intNRegistros,
				"ConsultaSQL",
				lchrArrConsulta);
}
int EsConsultaUsuariosSeguridad3(char **pchrPtrEntrada)
{
	return !strcmp(pchrPtrEntrada[0],"FirmasSeguridad3");
}
void FormaConsultaUsuariosSeguridad3(char **pchrPtrEntrada,
			   SiscomOperacionesServidor *pSOpServidor)
{
char lchrArrConsulta[1024];

	SiscomInformacionOperaciones("ConsultaSQL",
	                             "ConsultasBaseDatos",
			             pSOpServidor);
	sprintf(lchrArrConsulta,
		"\
select  NmbUsuario as nombre, 	\
	apaterno,		\
	amaterno,		\
	'' as rfc,		\
	'' as idpersona,	\
	idPerfil as tipopersona,\
	firma,			\
	password		\
from usuarios inner join firmas using(idusuario) \
where idaplicacion=(select idAplicacion 	 \
		    from aplicaciones		 \
		    where NmbAplicacion='%s');",
	pchrPtrEntrada[1]);

SiscomAnexaRegistroPro2(&pSOpServidor->LCSiscomPro2EPrim,
                        &pSOpServidor->LCSiscomPro2EAct,
			&pSOpServidor->intNRegistros,
			"ConsultaSQL,   \
			 BaseDatos,     \
			 PtoBaseDatos",
			lchrArrConsulta,
			"Seguridad3",
			"");
}
int EsConsultaPersonaFirma(char **pchrPtrEntrada)
{
	return !strcmp(pchrPtrEntrada[0],
			"DatosFirma");
}
void FormaConsultaDatosFirma(char **pchrPtrEntrada,
			   SiscomOperacionesServidor *pSOpServidor)
{
char lchrArrConsulta[512];
	sprintf(lchrArrConsulta,
		"SELECT b.*,				 \
			a.firma,'' as password 		 \
		from	firmas as a inner join 		 \
			personas as b using (idpersona)  \
		where firma='%s';",
		pchrPtrEntrada[1]);
	SiscomInformacionOperaciones("ConsultaSQL","Consultas",pSOpServidor);
	SiscomAnexaRegistroPro2(&pSOpServidor->LCSiscomPro2EPrim,
				&pSOpServidor->LCSiscomPro2EAct,
				&pSOpServidor->intNRegistros,
				"ConsultaSQL",
				lchrArrConsulta);
}

int EsConsultaEmpleadosExpendio(char **pchrPtrEntrada)
{
	return !strcmp(pchrPtrEntrada[0],
			"EmpleadosExpendio");
}
void FormaConsultaEmpleadosExpendio(char **pchrPtrEntrada,
			   SiscomOperacionesServidor *pSOpServidor)
{
char lchrArrConsulta[512];
	sprintf(lchrArrConsulta,
		"select b.nombre,			\n\
		        b.apaterno,			\n\
			b.amaterno,			\n\
			'' as rfc,			\n\
			idpersona,			\n\
			tipopersona,			\n\
			firma,				\n\
			'' as password			\n\
		 from firmas inner join personas as b	\n\
		      using (idPersona)              	\n\
		 where idexpendio=%s",
		pchrPtrEntrada[1]);
	SiscomLog("%s",lchrArrConsulta);
	SiscomInformacionOperaciones("ConsultaSQL","Consultas",pSOpServidor);
	SiscomAnexaRegistroPro2(&pSOpServidor->LCSiscomPro2EPrim,
				&pSOpServidor->LCSiscomPro2EAct,
				&pSOpServidor->intNRegistros,
				"ConsultaSQL",
				lchrArrConsulta);
}
int EsConsultaValidaFirmaEmpleado(char **pchrPtrEntrada)
{
	return !strcmp(pchrPtrEntrada[0],"ValidaFirmaEmpleado");
}
void MarcaComoFirmado(SiscomOperacionesServidor *pSOpServidor)
{
LCamposSiscomPro2 *lLCSiscomPro2Ins=0,
                  *lLCSiscomPro2InsAct=0;
char lchrArrActualiza[1204];
char *lchrPtrEdoConexion=0;
int     lintSocketAD,
        lintNRegistros=0,
	lintContador;
	sprintf(lchrArrActualiza,
		"update firmas set edofirma=1 	\
		 where idusuario=%s",
		 SiscomObtenDato(pSOpServidor->LCSiscomPro2,"idusuario"));

	SiscomAnexaRegistroPro2(&lLCSiscomPro2Ins,
				&lLCSiscomPro2InsAct,
				&lintNRegistros,
				"ComandoSQL,	\
				 BaseDatos,	\
				 PtoBaseDatos",
				 lchrArrActualiza,
				 "Seguridad3",
				 "");

	SiscomInformacionServidor(pSOpServidor->intPtoCom,
				  pSOpServidor->chrPtrDirIpSvr,
				  "InsercionesBaseDatos",
				  lintNRegistros,
				  lLCSiscomPro2Ins,
				  &lchrPtrEdoConexion,
				  &lintSocketAD);

}
void VerificaElEstadoFirma(SiscomOperacionesServidor *pSOpServidor)
{
/*
 *
	SiscomImprimeContenidoProtocolo("",
					gPtrFleArchivoLog,
					pSOpServidor->LCSiscomPro2);
*/
	if(!SiscomObtenDato(pSOpServidor->LCSiscomPro2,"edofirma")[0] ||
	    SiscomObtenDato(pSOpServidor->LCSiscomPro2,"edofirma")[0]=='0')
	{
	  MarcaComoFirmado(pSOpServidor);

	}
	else
	{
	   
	}
}
void FormaConsultaValidaFirmaEmpleado(char **pchrPtrEntrada,
			   SiscomOperacionesServidor *pSOpServidor)
{
char lchrArrConsulta[1024];

	SiscomInformacionOperaciones("ConsultaSQL",
	                             "ConsultasBaseDatos",
			             pSOpServidor);
	sprintf(lchrArrConsulta,
		"\
select  NmbUsuario as nombre, 	\
	apaterno,		\
	amaterno,		\
	'' as rfc,		\
	'' as idpersona,	\
	idPerfil as tipopersona,\
	firma,			\
	password,		\
	edofirma,		\
	idusuario		\
from usuarios inner join firmas using(idusuario) \
where idaplicacion=(select idAplicacion 	 \
		    from aplicaciones		 \
		    where NmbAplicacion='%s') and  \
      firma='%s' and				  \
      password='%s';",
	pchrPtrEntrada[5],
	pchrPtrEntrada[3],
	pchrPtrEntrada[4]);

SiscomAnexaRegistroPro2(&pSOpServidor->LCSiscomPro2EPrim,
                        &pSOpServidor->LCSiscomPro2EAct,
			&pSOpServidor->intNRegistros,
			"ConsultaSQL,   \
			 BaseDatos,     \
			 PtoBaseDatos",
			lchrArrConsulta,
			"Seguridad3",
			"");
	pSOpServidor->EjecutaProcesoDespues=VerificaElEstadoFirma;
}

void RegistraPersonas(int pintSocket,
			int pintNRegistros)
{
LCamposSiscomPro2 *lLCSiscomPro2=0;
LCamposSiscomPro2 *lLCSiscomPro2Ins=0,
                  *lLCSiscomPro2InsAct=0;
char lchrArrActualiza[1204];
char *lchrPtrEdoConexion=0;
int     lintSocketAD,
        lintNRegistros=0,
	lintContador,
	lintIdEmpresa;
int lintPtoComAd;
char lchrArrDirIpSvrAd[35];
SiscomLeeInformacionProtocolo(pintSocket,
                                      pintNRegistros,
                                      &lLCSiscomPro2);
	ElectronicaComunicacionExpendio2(
		SiscomObtenDato(lLCSiscomPro2,"Departamento"),
		&lintPtoComAd,
		lchrArrDirIpSvrAd,
		0);
					
	for(lintContador=0;
	    lintContador<gintNumRegPersonas;
	    lintContador++)
	 if(!strcmp(SiscomObtenDato(lLCSiscomPro2,"DscTipoPersona"),
	     gStcRegPersonas[lintContador].chrPtrTipoPersona))
	 {
	            gStcRegPersonas[lintContador].RegistraPersonas(
		    		lLCSiscomPro2,
				pintSocket,
				lchrArrDirIpSvrAd,
				lintPtoComAd);
		    return;
	 }
}
void RegistraDireccion(int pintIdPersona,
			LCamposSiscomPro2 **pLCSiscomPro2,
		     LCamposSiscomPro2 **pLCSiscomPro2RegPrim,
		     LCamposSiscomPro2 **pLCSiscomPro2RegAct,
		     int *pintPtrNRegistros)
{
char lchrArrCadenaInsercion[1024];
	SiscomImprimeContenidoProtocolo("",
					gPtrFleArchivoLog,
					*pLCSiscomPro2);	
	while(SiscomObtenDato(*pLCSiscomPro2,"Calle")[0] &&
	      SiscomObtenDato(*pLCSiscomPro2,"Numero")[0])
	{
		
	   SiscomLog(
	   		     "%s,%s,%s",
			     SiscomObtenDato(*pLCSiscomPro2,"Calle"),
			     SiscomObtenDato(*pLCSiscomPro2,"Numero"),
			     SiscomObtenDato(*pLCSiscomPro2,"Colonia"));
	   sprintf(lchrArrCadenaInsercion,
	   	   "insert into direcciones values(%d,0,'%s','%s','%s',%s,'%s','%s','%s');",
		   pintIdPersona,
		   SiscomObtenDato(*pLCSiscomPro2,"Calle"),
		   SiscomObtenDato(*pLCSiscomPro2,"Numero"),
		   SiscomObtenDato(*pLCSiscomPro2,"Colonia"),
		   SiscomObtenDato(*pLCSiscomPro2,"CP"),
		   SiscomObtenDato(*pLCSiscomPro2,"Municipio"),
		   SiscomObtenDato(*pLCSiscomPro2,"Estado"),
		   SiscomObtenDato(*pLCSiscomPro2,"Referencias"));
	 SiscomAnexaRegistroPro2(pLCSiscomPro2RegPrim,
				pLCSiscomPro2RegAct,
				pintPtrNRegistros,
				"ComandoSQL",
				lchrArrCadenaInsercion);
   
		   


	   *pLCSiscomPro2=(*pLCSiscomPro2)->SCP2PtrSig;
	}
	      

}

void RegistraPersona(LCamposSiscomPro2 **pLCSiscomPro2,
		     LCamposSiscomPro2 **pLCSiscomPro2RegPrim,
		     LCamposSiscomPro2 **pLCSiscomPro2RegAct,
		     int *pintPtrNRegistros,
		     int *pintPtrIdPersona)
{

char lchrArrCadenaInsercion[1024];

	*pintPtrIdPersona=SiscomObtenNumeroUnico();
	sprintf(lchrArrCadenaInsercion,
		"insert into personas values('%s','%s','%s','%s',%d,%s,'');",
		SiscomObtenDato(*pLCSiscomPro2,"Nombre"),
		SiscomObtenDato(*pLCSiscomPro2,"APaterno"),
		SiscomObtenDato(*pLCSiscomPro2,"AMaterno"),
		SiscomObtenDato(*pLCSiscomPro2,"RFC"),
		*pintPtrIdPersona,
		SiscomObtenDato(*pLCSiscomPro2,"TipoPersona"));

	SiscomAnexaRegistroPro2(pLCSiscomPro2RegPrim,
				pLCSiscomPro2RegAct,
				pintPtrNRegistros,
				"ComandoSQL",
				lchrArrCadenaInsercion);

	sprintf(lchrArrCadenaInsercion,
		"insert into firmas values('%s',%d,%s);",
		SiscomObtenDato(*pLCSiscomPro2,"Firma"),
		*pintPtrIdPersona,
		SiscomObtenDato(*pLCSiscomPro2,"Departamento"));
	SiscomAnexaRegistroPro2(pLCSiscomPro2RegPrim,
				pLCSiscomPro2RegAct,
				pintPtrNRegistros,
				"ComandoSQL",
				 lchrArrCadenaInsercion);
	*pLCSiscomPro2=(*pLCSiscomPro2)->SCP2PtrSig;




}
void RegistraTelefonos(int pintIdPersona,
			LCamposSiscomPro2 **pLCSiscomPro2,
		     LCamposSiscomPro2 **pLCSiscomPro2RegPrim,
		     LCamposSiscomPro2 **pLCSiscomPro2RegAct,
		     int *pintPtrNRegistros)
{
char lchrArrCadenaInsercion[1024];
	SiscomImprimeContenidoProtocolo("",
					gPtrFleArchivoLog,
					*pLCSiscomPro2);	
	while(*pLCSiscomPro2 && 
	       SiscomObtenDato(*pLCSiscomPro2,"NmbMedioCom")[0]) 
	{
		
	   sprintf(lchrArrCadenaInsercion,
	   	   "insert into telefonos values(%d,0,'%s','%s');",
		   pintIdPersona,
		   SiscomObtenDato(*pLCSiscomPro2,"Medio"),
		   "");
	 SiscomAnexaRegistroPro2(pLCSiscomPro2RegPrim,
				pLCSiscomPro2RegAct,
				pintPtrNRegistros,
				"ComandoSQL",
				lchrArrCadenaInsercion);
   
		   


	   *pLCSiscomPro2=(*pLCSiscomPro2)->SCP2PtrSig;
	 }
}

void RegistraBaseTiendas(LCamposSiscomPro2 *pLCSiscomPro2,
			 int pintSocketCliente,
			 const char *pchrPtrDirIpSvrAD,
			 int pintPtoComAD)
{
LCamposSiscomPro2 *lLCSiscomPro2=pLCSiscomPro2;
LCamposSiscomPro2 *lLCSiscomPro2EnvPrim=0,
		  *lLCSiscomPro2EnvAct=0;
int lintNRegistros=0;
int lintIdPersona;
int lintSocketAD;
char *lchrPtrEdoConexion;
	RegistraPersona(&lLCSiscomPro2,
			&lLCSiscomPro2EnvPrim,
			&lLCSiscomPro2EnvAct,
			&lintNRegistros,
			&lintIdPersona);
	RegistraDireccion(lintIdPersona,
			  &lLCSiscomPro2,
			  &lLCSiscomPro2EnvPrim,
			  &lLCSiscomPro2EnvAct,
			  &lintNRegistros);
	RegistraTelefonos(lintIdPersona,
			  &lLCSiscomPro2,
			  &lLCSiscomPro2EnvPrim,
			  &lLCSiscomPro2EnvAct,
			  &lintNRegistros);
	SiscomImprimeContenidoProtocolo("",
					 gPtrFleArchivoLog,
					 lLCSiscomPro2EnvPrim);
	SiscomInformacionServidor(pintPtoComAD,
				  pchrPtrDirIpSvrAD,
				  "Inserciones",
				  lintNRegistros,
				  lLCSiscomPro2EnvPrim,
				  &lchrPtrEdoConexion,
				  &lintSocketAD);
}

void RegistraBaseSeguridad3(LCamposSiscomPro2 *pLCSiscomPro2,
			    int pintSocketCliente,
			    const char *pchrPtrDirIpSvrAd,
			    int pintPtoComSvrAd)
{
LCamposSiscomPro2 *lLCSiscomPro2EnvPrim=0,
		  *lLCSiscomPro2EnvAct=0;
int lintNRegistros=0;
int lintIdPersona;
char lchrArrCadenaInsercion[1024];
int lintSocketAD;
char *lchrPtrEdoConexion;
SiscomContenidoProtocolo(pLCSiscomPro2);

	lintIdPersona=SiscomObtenNumeroUnico();
	sprintf(lchrArrCadenaInsercion,
		"insert into usuarios values(%d,%s,%s,'%s','%s','%s');",
		lintIdPersona,
		SiscomObtenDato(pLCSiscomPro2,"IdAplicacion"),
		SiscomObtenDato(pLCSiscomPro2,"TipoPersona"),
		SiscomObtenDato(pLCSiscomPro2,"Nombre"),
		SiscomObtenDato(pLCSiscomPro2,"APaterno"),
		SiscomObtenDato(pLCSiscomPro2,"AMaterno"));
	SiscomAnexaRegistroPro2(&lLCSiscomPro2EnvPrim,
				&lLCSiscomPro2EnvAct,
				&lintNRegistros,
				"ComandoSQL,	\
				 BaseDatos,	\
				 PtoBaseDatos",
				 lchrArrCadenaInsercion,
				 "Seguridad3",
				 "");
	sprintf(lchrArrCadenaInsercion,
		"insert into firmas values(%d,'%s','%s');",
		lintIdPersona,
		SiscomObtenDato(pLCSiscomPro2,"Firma"),
		SiscomObtenDato(pLCSiscomPro2,"Password"));
	SiscomAnexaRegistroPro2(&lLCSiscomPro2EnvPrim,
				&lLCSiscomPro2EnvAct,
				&lintNRegistros,
				"ComandoSQL,	\
				 BaseDatos,	\
				 PtoBaseDatos",
				 lchrArrCadenaInsercion,
				 "Seguridad3",
				 "");
	SiscomInformacionServidor(pintPtoComSvrAd,
				  pchrPtrDirIpSvrAd,
				  "InsercionesBaseDatos",
				  lintNRegistros,
				  lLCSiscomPro2EnvPrim,
				  &lchrPtrEdoConexion,
				  &lintSocketAD);
	SiscomImprimeContenidoProtocolo("",
					 gPtrFleArchivoLog,
					 lLCSiscomPro2EnvPrim);

}
void RegistraEmpleado(LCamposSiscomPro2 *pLCSiscomPro2,
		      int pintSocketCliente,
		      const char *pchrPtrDirIpSvrAd,
		      int pintPtoComAd)

{
SiscomLog("RegistraEmpleado");

	SiscomImprimeContenidoProtocolo("",
					gPtrFleArchivoLog,
					pLCSiscomPro2);
	RegistraBaseTiendas(pLCSiscomPro2,
				pintSocketCliente,
				pchrPtrDirIpSvrAd,
				pintPtoComAd);
	RegistraBaseSeguridad3(pLCSiscomPro2,
				pintSocketCliente,
				pchrPtrDirIpSvrAd,
				pintPtoComAd);
}
void CambiaEstadoFirma(int pintSocket,
			int pintNRegistros)
{
LCamposSiscomPro2 *lLCSiscomPro2=0;
LCamposSiscomPro2 *lLCSiscomPro2Ins=0,
                  *lLCSiscomPro2InsAct=0;
char lchrArrActualiza[1204];
char *lchrPtrEdoConexion=0;
int     lintSocketAD,
        lintNRegistros=0,
	lintContador;
char lchrArrDirIpSvr[35];
int lintPtoComSvr;
char **lchrPtrEntrada;
SiscomLeeInformacionProtocolo(pintSocket,
                                      pintNRegistros,
                                     &lLCSiscomPro2);
/*
SiscomLog( "CambiaEstadoFirma");
SiscomContenidoProtocolo(lLCSiscomPro2);

*/
SiscomCopiaDatosProtocoloCharChar(lLCSiscomPro2,
				  pintNRegistros,
				  "Parametro",
				  &lchrPtrEntrada);


ElectronicaComunicacionExpendio2(lchrPtrEntrada[0],
					 &lintPtoComSvr,
					 lchrArrDirIpSvr,
					0);

sprintf(lchrArrActualiza,
	"update firmas set edofirma=%s   	\
	 where idusuario=%s",
	 lchrPtrEntrada[2],
	 lchrPtrEntrada[1]);
	SiscomAnexaRegistroPro2(&lLCSiscomPro2Ins,
				&lLCSiscomPro2InsAct,
				&lintNRegistros,
				"ComandoSQL,	\
				 BaseDatos,	\
				 PtoBaseDatos",
				 lchrArrActualiza,
				 "Seguridad3",
				 "");

SiscomInformacionServidor(gSSiscomConfiguracionSvr.intPtoAccesoDatos,
	                          gSSiscomConfiguracionSvr.chrPtrDirIpAccesoDatos,
				  "InsercionesBaseDatos",
				  lintNRegistros,
				  lLCSiscomPro2Ins,
				  &lchrPtrEdoConexion,
				  &lintSocketAD);
	if(lchrPtrEdoConexion)
	SiscomLog(
			  "Error Al Enviar:%s",
	                  lchrPtrEdoConexion);

/*
  for(lintContador=0;
  	lLCSiscomPro2;
	lLCSiscomPro2=lLCSiscomPro2->SCP2PtrSig,
	lintContador++)
  {
  	 if(FormaCadenaOperacionSqlFamilias(lintContador,lLCSiscomPro2,lchrArrActualiza))
	 SiscomAnexaRegistroPro2(&lLCSiscomPro2Ins,
	 			 &lLCSiscomPro2InsAct,
				 &lintNRegistros,
				 "ComandoSQL",
				 lchrArrActualiza);
  }
  	SiscomContenidoProtocolo(lLCSiscomPro2Ins);
	SiscomInformacionServidor(gSSiscomConfiguracionSvr.intPtoAccesoDatos,
	                          gSSiscomConfiguracionSvr.chrPtrDirIpAccesoDatos,
				  "Inserciones",
				  lintNRegistros,
				  lLCSiscomPro2Ins,
				  &lchrPtrEdoConexion,
				  &lintSocketAD);
	if(lchrPtrEdoConexion)
	SiscomLog(
			  "Error Al Enviar:%s",
	                  lchrPtrEdoConexion);
*/
}

