#include <RNTransfiereProductos.h>
#include <RNPersonas.h>
#include <RNCotizaDispositivos.h>


#include <ComunElectronica.h>
#include <ComunElectronica2.h>

/* SISCOM Zacatenco
 * Viernes 6 de Noviembre del 2015
 * Se integra la validacion de las existencias 
 * en las transferencias 
 */
#include <SqlValidandoTransferencias.h>
#include <ServidorGeneral.h>
#include <ComunElectronica.h>
#include <string.h>

extern StcSiscomConfiguracion gSSiscomConfiguracionSvr;
StcConsultas gStcCnsTransfiereProductos[]={ 
				{
					EsConsultaTransfiereProductos,
					FormaConsultaTransfiereProductos
				}
			       };
int gintCnsTransfiereProductos=1;

int EsConsultaTransfiereProductos(char **pchrPtrEntrada)
{
	return !strcmp(pchrPtrEntrada[0],"TransfiereProductos");
}
void FormaConsultaTransfiereProductos(char **pchrPtrEntrada,
			   SiscomOperacionesServidor *pSOpServidor)
{

 SiscomInformacionOperaciones("ConsultaSQL","Consultas",pSOpServidor);
 SiscomAnexaRegistroPro2(&pSOpServidor->LCSiscomPro2EPrim,
		         &pSOpServidor->LCSiscomPro2EAct,
			&pSOpServidor->intNRegistros,
			"ConsultaSQL",
			"select * from tipoprecio");


}
void AnalizaConsultaTransfiereProductos(char **pchrPtrEntrada,
			      SiscomOperacionesServidor *pSOpServidor)
{
int lintContador;
	for(lintContador=0;
	    lintContador<gintCnsTransfiereProductos;
	    lintContador++)
	   if(gStcCnsTransfiereProductos[lintContador].Consulta(pchrPtrEntrada))
	   {
	      gStcCnsTransfiereProductos[lintContador].FormaConsulta(pchrPtrEntrada,
	     						  pSOpServidor);
	      break;
	   }

	

}
void ConsultaTransfiereProductos(int pintSocket,
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
	SiscomCopiaDatosProtocoloCharChar(lSOpServidor.LCSiscomPro2Dat,
					  pintNRegistros,
					  "Parametro",
					  &lchrPtrEntrada);
	AnalizaConsultaTransfiereProductos(lchrPtrEntrada,&lSOpServidor);
	SiscomOperacionesServidores(&lSOpServidor);
	SiscomEnviaAlServidor(pintSocket,
			      lSOpServidor.intNRegistrosRes,
			      "ClientesRegistrados",
			      lSOpServidor.LCSiscomPro2);
	close(pintSocket);
}
void FormaCadenaOperacionSqlTransfiereProductos(int lintContador,
			     LCamposSiscomPro2 *pLCSiscomPro2,
			     char *pchrPtrCadena)
{
	if(!strcmp(SiscomObtenDato(pLCSiscomPro2,"EdoRegistro"),"Insertar"))
	{
	 sprintf(pchrPtrCadena,
	 	 "insert into TransfiereProductos values(%d,%s,'%s');",
		 (int )(SiscomObtenNumeroUnico()+lintContador),
		 SiscomObtenDato(pLCSiscomPro2,"IdMateria"),
		 SiscomObtenDato(pLCSiscomPro2,"Nombre"));
	}

}
void TransfiereAlExpendio(const char *pchrPtrIdExpendio,
			  LCamposSiscomPro2 *pLCSiscomPro2Material,
			  int pintNRegistros)
{
int lintPtoExpendio;
char lchrArrDirIpExpendio[25];
char lchrArrBaseDatos[128];
char *lchrPtrEdoConexion;
int lintSocketEnvio;
	ElectronicaComunicacionExpendio2(pchrPtrIdExpendio,
					 &lintPtoExpendio,
					 lchrArrDirIpExpendio,
					 lchrArrBaseDatos);
	SiscomLog("Tranfiriendo al Expendio:%d,%s",
			  lintPtoExpendio,
			  lchrArrDirIpExpendio);
	SiscomContenidoProtocolo(pLCSiscomPro2Material);
	SiscomInformacionServidor(lintPtoExpendio,
				  lchrArrDirIpExpendio,
				  "Inserciones",
				  pintNRegistros,
				  pLCSiscomPro2Material,
				  &lchrPtrEdoConexion,
				  &lintSocketEnvio);


}
const char *EnviaInformacionInserciones(int pintPtoComAd,
		      const char *pchrPtrDirIpSvrAd,
		      LCamposSiscomPro2 *pLCSiscomPro2,
		      int pintNumRegistros)
{
int lintSocketAD;
char *lchrPtrEdoConexion=0;
LCamposSiscomPro2 *lLCSiscomPro2Reg=0;
int lintNRegistrosReg=0;
SiscomLog("Se Enviara A:%d,%s",pintPtoComAd,pchrPtrDirIpSvrAd);
SiscomContenidoProtocolo(pLCSiscomPro2);
	SiscomInformacionServidorConRespuesta(pintPtoComAd,
				  pchrPtrDirIpSvrAd,
				  "Inserciones",
				  pintNumRegistros,
				  pLCSiscomPro2,
				  &lchrPtrEdoConexion,
				  &lintSocketAD,
				  &lLCSiscomPro2Reg,
				  &lintNRegistrosReg);
	return lchrPtrEdoConexion;
}
void GeneraInsercionTransferencias(const char *pchrPtrFechaHoy,
				  const char *pchrPtrIdExpendio,
				 LCamposSiscomPro2 **pLCSiscomProLPtrEnvioPrim,
				 LCamposSiscomPro2 **pLCSiscomProLPtrEnvioAct,
				 int *pintPtrNRegistros,
				 int *pintPtrIdTransferencia)
{
char lchrArrSql[128];
   *pintPtrIdTransferencia=SiscomObtenNumeroUnico();
   sprintf(lchrArrSql,
   	   "insert into Transferencias values(%s,%d,0,'%s');",
	   pchrPtrIdExpendio,
	   *pintPtrIdTransferencia,
	   pchrPtrFechaHoy); 
  SiscomAnexaRegistroPro2(pLCSiscomProLPtrEnvioPrim,
  			  pLCSiscomProLPtrEnvioAct,
			  pintPtrNRegistros,
			  "ComandoSQL,EdoRegistro",
			  lchrArrSql,
			  "");
}
void ActualizaMatriz(int pintSocket,
		     LCamposSiscomPro2 *pLCSiscomPro2,
		     int *pintPtrIdTransferencia)
{
LCamposSiscomPro2 *lLCSiscomPro2PrimEnvio=0,
		  *lLCSiscomPro2ActEnvio=0;
int lintNumRegistros=0;
char lchrArrCadComandoSQL[1024],
	lchrArrFechaHoraHoy[50];
const char *lchrPtrIdExpendio;
int lintPtoComAd;
char lchrArrDirIpSvrAd[35];
SiscomLog("");
SiscomContenidoProtocolo(pLCSiscomPro2);
  SiscomObtenFechaHoraActualAAAADDMM(lchrArrFechaHoraHoy);
  	ElectronicaComunicacionExpendio2(
			SiscomObtenDato(pLCSiscomPro2,"IdMatriz"),
			&lintPtoComAd,
			lchrArrDirIpSvrAd,
			0);
	lchrPtrIdExpendio=SiscomObtenDato(pLCSiscomPro2,"IdExpendio");
	GeneraInsercionTransferencias(lchrArrFechaHoraHoy,
				      lchrPtrIdExpendio,
				      &lLCSiscomPro2PrimEnvio,
				      &lLCSiscomPro2ActEnvio,
				      &lintNumRegistros,
				      pintPtrIdTransferencia);
	for(;
		pLCSiscomPro2;
		pLCSiscomPro2=pLCSiscomPro2->SCP2PtrSig)
	{
		sprintf(lchrArrCadComandoSQL,
			"insert into transfierematerial values('%s',%s,%s,'%s',%s,%s,%d);",
			lchrArrFechaHoraHoy,
			SiscomObtenDato(pLCSiscomPro2,"IdMatriz"),
			SiscomObtenDato(pLCSiscomPro2,"IdExpendio"),
			SiscomObtenDato(pLCSiscomPro2,"CveProducto"),
			SiscomObtenDato(pLCSiscomPro2,"Cantidad"),
			SiscomObtenDato(pLCSiscomPro2,"IdEmpleado"),
			*pintPtrIdTransferencia);
		SiscomAnexaRegistroPro2(&lLCSiscomPro2PrimEnvio,
					&lLCSiscomPro2ActEnvio,
					&lintNumRegistros,
					"ComandoSQL",
					lchrArrCadComandoSQL);
		sprintf(lchrArrCadComandoSQL,
	"update existencias set existencia=existencia-%s where CveProducto='%s' and IdExpendio=%s",
		  SiscomObtenDato(pLCSiscomPro2,"Cantidad"),
		  SiscomObtenDato(pLCSiscomPro2,"CveProducto"),
		  SiscomObtenDato(pLCSiscomPro2,"IdMatriz"));
	 SiscomAnexaRegistroPro2(&lLCSiscomPro2PrimEnvio,
	 			 &lLCSiscomPro2ActEnvio,
				 &lintNumRegistros,
				 "ComandoSQL",
				 lchrArrCadComandoSQL);
	}
	EnviaInformacionInserciones(lintPtoComAd,
				    lchrArrDirIpSvrAd,
				    lLCSiscomPro2PrimEnvio,
				    lintNumRegistros);

	

}
const char *ActualizaExpendio(int pintSocket,
		       LCamposSiscomPro2 *pLCSiscomPro2)
{
LCamposSiscomPro2 *lLCSiscomPro2PrimEnvio=0,
		  *lLCSiscomPro2ActEnvio=0;
int lintNumRegistros=0;
char lchrArrCadComandoSQL[1024];
int lintPtoComAD;
char lchrArrDirIpSvrAd[35];
SiscomLog("ActualizaExpendio");
SiscomContenidoProtocolo(pLCSiscomPro2);

	ElectronicaComunicacionExpendio2(
			SiscomObtenDato(pLCSiscomPro2,"IdExpendio"),
			&lintPtoComAD,
			lchrArrDirIpSvrAd,
			0);
	for(;
		pLCSiscomPro2;
		pLCSiscomPro2=pLCSiscomPro2->SCP2PtrSig)
	{
		sprintf(lchrArrCadComandoSQL,
	 	 "update existencias set existencia=existencia+%s   \
		  where CveProducto='%s' and			    \
		       	IdExpendio=%s",
		  SiscomObtenDato(pLCSiscomPro2,"Cantidad"),
		  SiscomObtenDato(pLCSiscomPro2,"CveProducto"),
		  SiscomObtenDato(pLCSiscomPro2,"IdExpendio"));
	 SiscomAnexaRegistroPro2(&lLCSiscomPro2PrimEnvio,
	 			 &lLCSiscomPro2ActEnvio,
				 &lintNumRegistros,
				 "ComandoSQL",
				 lchrArrCadComandoSQL);
	}
return EnviaInformacionInserciones(lintPtoComAD,
				    lchrArrDirIpSvrAd,
				    lLCSiscomPro2PrimEnvio,
				    lintNumRegistros);




}
void RespondeCliente(int pintSocketCliente,
		     const char *pchrPtrEdoConexion)
{
LCamposSiscomPro2 *lLCSiscomPro2RegEdoT=0,
		  *lLCSiscomPro2RegEdoTAct=0;
int lintNumRegRegreso=0;

	if(pchrPtrEdoConexion)
	SiscomAnexaRegistroPro2(&lLCSiscomPro2RegEdoT,
				&lLCSiscomPro2RegEdoTAct,
				&lintNumRegRegreso,
				"EdoConexion",
				"Expendio Sin Conexion");
	else
	SiscomAnexaRegistroPro2(&lLCSiscomPro2RegEdoT,
				&lLCSiscomPro2RegEdoTAct,
				&lintNumRegRegreso,
				"EdoConexion",
				"Conexion Exitosa");

	SiscomEnviaAlServidor(pintSocketCliente,
			      lintNumRegRegreso,
			      "EdoConexionExpendio",
			      lLCSiscomPro2RegEdoT);

}
void ActualizaErrorTransferencia(LCamposSiscomPro2 *pLCSiscomPro2Dat,
				int pintIdTransferencia)
{
int lintPtoComAd,lintNRegistros=0;
char lchrArrDirIpSvrAd[28],
	lchrArrSql[128];

LCamposSiscomPro2 *lLCSiscomPro2Ins=0,
                  *lLCSiscomPro2InsAct=0;
  	ElectronicaComunicacionExpendio2(
			SiscomObtenDato(pLCSiscomPro2Dat,"IdMatriz"),
			&lintPtoComAd,
			lchrArrDirIpSvrAd,
			0);
SiscomLog("NO se pudo realizar la transferencia %d Actualizando Matriz (%s:%d)",
	pintIdTransferencia,
	lchrArrDirIpSvrAd,
	lintPtoComAd);
	sprintf(lchrArrSql,
		"update Transferencias set IdEstado=1 where idTransferencia=%d;",
		pintIdTransferencia);
	SiscomLog("%s",lchrArrSql);
	SiscomAnexaRegistroPro2(&lLCSiscomPro2Ins,
		          &lLCSiscomPro2InsAct,
			  &lintNRegistros,
			  "ComandoSQL,EdoRegistro",
			  lchrArrSql,
			  "");
	EnviaInformacionInserciones(lintPtoComAd,
				    lchrArrDirIpSvrAd,
				    lLCSiscomPro2Ins,
				    lintNRegistros);
}
void TransfiereProductos(int pintSocket,
			int pintNRegistros)
{
LCamposSiscomPro2 *lLCSiscomPro2=0;
LCamposSiscomPro2 *lLCSiscomPro2Ins=0,
                  *lLCSiscomPro2InsAct=0;
LCamposSiscomPro2 *lLCSiscomPro2TExpendio=0,
		  *lLCSiscomPro2TExpendioAct=0;


char lchrArrActualiza[1204];
char *lchrPtrEdoConexion=0;
int     lintSocketAD,
        lintNRegistros=0,
	lintContador,
	lintNRegTransfiere=0,
	lintIdTransferencia;

char lchrArrCadenaSQL[1024];
char lchrArrFechaHoraHoy[30];

const char *lchrPtrIdExpendio;
const char *lchrPtrEdoConexionExpendio=0;
/* Viernes 6 de Noviembre del 2015
 * Tepotzotlan Mexico
 * Se agrega la validacion de las existencias antes 
 * de enviar la transferencia
 * para lo que se trabaja en este codigo original
 * version con la integracion de la version 2 :)
 */
SArgsSiscom lSArgsSiscom;
SiscomLeeInformacionProtocolo(pintSocket, pintNRegistros, &lLCSiscomPro2);
SiscomLog("RegistraTransfiereProductos");
SiscomContenidoProtocolo(lLCSiscomPro2);
if(ValidandoExistenciaExpendio(lLCSiscomPro2,pintSocket,&lSArgsSiscom))
{
lchrPtrEdoConexionExpendio=ActualizaExpendio(pintSocket,lLCSiscomPro2);
	ActualizaMatriz(pintSocket,
			lLCSiscomPro2,
			&lintIdTransferencia);
	if(lchrPtrEdoConexionExpendio)
	ActualizaErrorTransferencia(lLCSiscomPro2,lintIdTransferencia);
	RespondeCliente(pintSocket,lchrPtrEdoConexionExpendio);
}
else
{
SiscomLog("Algun producto No Alcanza");
SiscomContenidoProtocolo(lSArgsSiscom.LCSiscomPro2Regreso);
SiscomEnviaRegreso(&lSArgsSiscom);
close(pintSocket);
}
}

/* Jueves 8 de septiembre del 2016 
 * Se agrega la validacion de la existencia
 * despues de modificar una cantidad, ya que
 * al realizar este proceso, al no realizar 
 * la validacion, se quedan marcados productos
 * que estaban en rojo
 */
void ValidaExistencia(int pintSocket,
			int pintNRegistros)
{
LCamposSiscomPro2 *lLCSiscomPro2=0;
LCamposSiscomPro2 *lLCSiscomPro2Ins=0,
                  *lLCSiscomPro2InsAct=0;
LCamposSiscomPro2 *lLCSiscomPro2TExpendio=0,
		  *lLCSiscomPro2TExpendioAct=0;


char lchrArrActualiza[1204];
char *lchrPtrEdoConexion=0;
int     lintSocketAD,
        lintNRegistros=0,
	lintContador,
	lintNRegTransfiere=0,
	lintIdTransferencia;

char lchrArrCadenaSQL[1024];
char lchrArrFechaHoraHoy[30];

const char *lchrPtrIdExpendio;
const char *lchrPtrEdoConexionExpendio=0;

SArgsSiscom lSArgsSiscom;
SiscomLeeInformacionProtocolo(pintSocket, pintNRegistros, &lLCSiscomPro2);
SiscomLog("Validando La Existencia para transferencia");
SiscomContenidoProtocolo(lLCSiscomPro2);
if(ValidandoExistenciaExpendio(lLCSiscomPro2,pintSocket,&lSArgsSiscom))
{
SiscomLog("Se valida la existencia, todo alcanza");
RespondeCliente(pintSocket,lchrPtrEdoConexionExpendio);
}
else
{
SiscomLog("Algun producto No Alcanza");
SiscomContenidoProtocolo(lSArgsSiscom.LCSiscomPro2Regreso);
SiscomEnviaRegreso(&lSArgsSiscom);
close(pintSocket);
}
}
void ArgumentosValidaExistenciaExpendio(SArgsSiscom *pSAgsSiscom)
{
SiscomAsignaMemoriaArgumentosOperaciones(2,pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(0,"SqlValidaExistencia",pSAgsSiscom);
}
int VerificaLaCantidadVsExistencia(LCamposSiscomPro2 *pLCSiscomPro2Producto,
				    LCamposSiscomPro2 *pLCSiscomPro2Existencias)
{
   for(;
   	pLCSiscomPro2Existencias;
	pLCSiscomPro2Existencias=pLCSiscomPro2Existencias->SCP2PtrSig)
	if(!SiscomComparaCampo2(pLCSiscomPro2Producto,
				pLCSiscomPro2Existencias,
				"CveProducto",
				"cveproducto"))
	{
	  /*
	  if(!SiscomObtenDatoInt(pLCSiscomPro2Producto,"Cantidad"))
	   return 0;
	   else
	   */
	  SiscomLog("Cantidad(%d)",
	  	    SiscomObtenDatoInt(pLCSiscomPro2Producto,"Cantidad")); 
	    if(SiscomObtenDatoInt(pLCSiscomPro2Existencias,"existencia")>=
	       SiscomObtenDatoInt(pLCSiscomPro2Producto,"Cantidad"))
	    {
	      SiscomLog("La existencia es mayor que la cantidad :)");
	   return 1;
	   }
	   else
	   return 0;
	}
}
int ValidaLaExistencia(SArgsSiscom *pSAgsSiscom)
{
int lintTodoHay=1;
const char *lchrPtrExistencia;
LCamposSiscomPro2 *lLCSiscomPro2Productos=pSAgsSiscom->LCSiscomPro2Dat,
		  *lLCSiscomPro2Existencia=SiscomArgumentoOperacionPrim("SqlValidaExistencia",pSAgsSiscom);
for(;
 	lLCSiscomPro2Productos;
	lLCSiscomPro2Productos=lLCSiscomPro2Productos->SCP2PtrSig)
{
	SiscomLog("Buscando Existencia de %s",SiscomObtenDato(lLCSiscomPro2Productos,"CveProducto"));
		  
        if(!(VerificaLaCantidadVsExistencia(lLCSiscomPro2Productos,lLCSiscomPro2Existencia)))
	{
	  lintTodoHay=0;
	  SiscomAnexaRegistroRegreso(pSAgsSiscom,
	  			    "CveProducto,Cantidad,Existencia,EdoConexion",
				     SiscomObtenDato(lLCSiscomPro2Productos,"CveProducto"), 
				     SiscomObtenDato(lLCSiscomPro2Productos,"Cantidad"), 
				     lchrPtrExistencia,
				     "No Alcanza");
				    
	}
}
return lintTodoHay;
}
int ValidandoExistenciaExpendio(LCamposSiscomPro2 *pLCSiscomPro2Productos,
				int pintSocket,
				SArgsSiscom *pSArgsSiscom)
{
memset(pSArgsSiscom,0,sizeof(SArgsSiscom));
pSArgsSiscom->LCSiscomPro2Dat=pLCSiscomPro2Productos;
pSArgsSiscom->intSocketCliente=pintSocket;
ComunicacionExpendioConsulta(pSArgsSiscom); 
ArgumentosValidaExistenciaExpendio(pSArgsSiscom);
SqlExistenciasProductosATransferir(pSArgsSiscom);
SiscomImprimeArgumento("SqlValidaExistencia",pSArgsSiscom);
return ValidaLaExistencia(pSArgsSiscom);
}
