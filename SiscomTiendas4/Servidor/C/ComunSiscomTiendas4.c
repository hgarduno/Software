#include <ComunSiscomTiendas4.h>
#include <ServidorGeneral.h>


#include <string.h>
/* 
 * Esta funcion debera tomar de la memoria comun, con el IdExpendio
 * los datos de comunicacion
 *
 *
 */

void (*ComunicacionSeguridad)(SArgsSiscom *);
void ObtenDatosComunicacionExpendio(const char *pchrPtrIdExpendio,
				         SArgsSiscom *pSAgsSiscom)
{
	pSAgsSiscom->intPtoComAD=gSSiscomConfiguracionSvr.intPtoAccesoDatos;
	strcpy(pSAgsSiscom->chrArrDirIpAD,
	       gSSiscomConfiguracionSvr.chrPtrDirIpAccesoDatos);
}
void CopiaDatosIniDatosComunicacion(SArgsSiscom *pSAgsSiscom)
{
	pSAgsSiscom->intPtoComAD=gSSiscomConfiguracionSvr.intPtoAccesoDatos;
	strcpy(pSAgsSiscom->chrArrDirIpAD,
	       gSSiscomConfiguracionSvr.chrPtrDirIpAccesoDatos);
}
void ObtenDatosExpendio(SArgsSiscom *pSAgsSiscom)
{
const char *lchrPtrIdExpendio;
	if(pSAgsSiscom->LCSiscomPro2Dat)
	{
	if(!strcmp((lchrPtrIdExpendio=SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"IdExpendio")),
		  "No Se Encontro El Campo"))
	CopiaDatosIniDatosComunicacion(pSAgsSiscom);
	else
	{
	  if(!lchrPtrIdExpendio[0])
	  {
	    SiscomAsignaDatoCampo2("IdExpendio","0",pSAgsSiscom->LCSiscomPro2Dat);
	    CopiaDatosIniDatosComunicacion(pSAgsSiscom);
	  }
	  else
	  ObtenDatosComunicacionExpendio(
	  		lchrPtrIdExpendio,
			pSAgsSiscom);
	}
	}
	else
	CopiaDatosIniDatosComunicacion(pSAgsSiscom);

}
void ComunicacionAccesoDatos(SArgsSiscom *pSAgsSiscom)
{
/*
 * En esta rutina se debera colocar la logica para encontrar la direccion IP y pto
 * de comunicaciones de los expendios
 *
 * Para iniciar el desarrollo se toma la informacion del Ini
 *
 * Para el trabajo con los expendios, se toma la siguiente consideracion:
 * Todos los datos de entrada que asi lo requieran deberan de contar con
 * un campo IdExpendio, sino se cuenta con este dato se tomara que las operaciones
 * se realizan sobre la matriz IdExpendio=0. 
 *
 *
 */
	ObtenDatosExpendio(pSAgsSiscom);	
}

void EjecutaRegistroInformacion(SArgsSiscom *pSAgsSiscom,
				const char *pchrPtrArgumento)
{
char *lchrPtrEdoConexion;
int lintSocket;
LCamposSiscomPro2 *lLCSiscomPro2Res=0;
int lintNRegRes=0;
SiscomInformacionServidorConRespuesta(
	pSAgsSiscom->intPtoComAD,
	pSAgsSiscom->chrArrDirIpAD,
	"Inserciones",
	SiscomArgumentosNumeroRegistros(pchrPtrArgumento,pSAgsSiscom),
	SiscomArgumentoOperacionPrim(pchrPtrArgumento,pSAgsSiscom),
	&lchrPtrEdoConexion,
	&lintSocket,
	&lLCSiscomPro2Res,
	&lintNRegRes);
SiscomContenidoProtocolo(lLCSiscomPro2Res);
}
void ObtenInformacionArgumento(const char *pchrPtrArgumento,
			       SArgsSiscom *pSAgsSiscom,
			       LCamposSiscomPro2 **pLCSiscomPro2Prim,
			       LCamposSiscomPro2 **pLCSiscomPro2Act,
			       int *pintPtrNRegistros)
{

	*pLCSiscomPro2Prim=SiscomArgumentoOperacionPrim(pchrPtrArgumento,pSAgsSiscom);
	*pLCSiscomPro2Act=SiscomArgumentoOperacionAct(pchrPtrArgumento,pSAgsSiscom);
	*pintPtrNRegistros=SiscomArgumentosNumeroRegistros(pchrPtrArgumento,pSAgsSiscom);
}
void AsignaInformacionArgumento(const char *pchrPtrArgumento,
				SArgsSiscom *pSAgsSiscom,
				LCamposSiscomPro2 *pLCSiscomPro2Prim,
				LCamposSiscomPro2 *pLCSiscomPro2Act,
				int pintNRegistros)
{
	SiscomAsignaArgumentoOperacionAct(pchrPtrArgumento,pLCSiscomPro2Act,pSAgsSiscom);
	SiscomAsignaArgumentoOperacionPrim(pchrPtrArgumento,pLCSiscomPro2Prim,pSAgsSiscom);
	SiscomAsignaArgumentoNumeroRegistros(pchrPtrArgumento,pintNRegistros,pSAgsSiscom);
}


void EjecutaConsultaYResponde(SArgsSiscom *pSAgsSiscom,
			      const char *pchrPtrConsultaSQL)
{
LCamposSiscomPro2 *lLCSiscomPro2Regreso=0;
int lintNRegRespuesta=0;
	SiscomConsultaBaseDatosSinDatosConexion(pchrPtrConsultaSQL,
						gSSiscomConfiguracionSvr.chrPtrDirIpAccesoDatos,
						gSSiscomConfiguracionSvr.intPtoAccesoDatos,
						&lLCSiscomPro2Regreso,
						&lintNRegRespuesta);

	SiscomEnviaAlServidor(pSAgsSiscom->intSocketCliente,
			      lintNRegRespuesta,
			      "Respuesta",
			      lLCSiscomPro2Regreso);
	/*
	SiscomMensajesLog2("<<<<<<<<<<<< EjecutaConsultaYResponde");
	SiscomImprimeContenidoProtocolo2("",lLCSiscomPro2Regreso);
	SiscomMensajesLog2(">>>>>>>>>>>>EjecutaConsultaYResponde");

	*/
	
}

void CambiaCampoProtocoloMayusculas(LCamposSiscomPro2 *pLCSiscomPro2Dat,
				  const char *pchrPtrCampo)
{

	for(;
	     pLCSiscomPro2Dat;
	     pLCSiscomPro2Dat=pLCSiscomPro2Dat->SCP2PtrSig)
	  CambiaCampoMayusculas(pLCSiscomPro2Dat,pchrPtrCampo);
}
void CambiaCampoMayusculas(LCamposSiscomPro2 *pLCSiscomPro2,
			   const char *pchrPtrCampo)
{
char *lchrPtrCampo=strdup(SiscomObtenDato(pLCSiscomPro2,pchrPtrCampo));
	SiscomCambiaMayusculas(lchrPtrCampo);
	SiscomAsignaDatoCampo2(pchrPtrCampo,lchrPtrCampo,pLCSiscomPro2);
}


void AnexaArgsConsulta(void (*SQLConsulta)(SArgsSiscom *,char *),
		       const char *pchrPtrConsulta,
		       StcArgsConsulta *pSAConsulta)
{
int lintContador=pSAConsulta->intNConsultas;
SiscomLog("%d",lintContador);
/*
	for(lintContador=0;
	    (pSAConsulta+lintContador)->chrPtrNombre;
	    lintContador++)
	{
	 SiscomLog("%s:%d",pchrPtrConsulta,lintContador);
	}
*/
	(pSAConsulta+lintContador)->SQLFormaCadena=SQLConsulta;
	(pSAConsulta+lintContador)->chrPtrNombre=strdup(pchrPtrConsulta);
	pSAConsulta->intNConsultas++;
}
SQLGeneraConsulta ObtenFuncionGeneraConsulta(
			StcArgsConsulta *pSAgsConsulta,
			SQLGeneraConsulta pSQLConsultaError,
			const char *pchrPtrConsulta)
{
int lintContador;
	for(lintContador=0;
	    lintContador<pSAgsConsulta->intNConsultas;
	    lintContador++)
	{
	  SiscomLog("%d",lintContador);
	 if(!strcmp((pSAgsConsulta+lintContador)->chrPtrNombre,
	 	    pchrPtrConsulta))
	 {
	   SiscomLog("");
	   return (pSAgsConsulta+lintContador)->SQLFormaCadena;
	 }
	}

	 return !pSQLConsultaError  ? SQLConsultaNoSoportada : pSQLConsultaError ;
}
void SQLConsultaNoSoportada(SArgsSiscom *pSAgsSiscom,char *pchrPtrConsulta)
{
SiscomMensajesLog2("SQLConsultaNoSoportada");
}

void GeneraInsercionActualizacion(SArgsSiscom *pSAgsSiscom,
				  const char *pchrPtrArgumento,
				  void (*GeneraSQL)(LCamposSiscomPro2 *,
				  		    LCamposSiscomPro2 **,
				  		    LCamposSiscomPro2 **,
						    int *))
{
LCamposSiscomPro2 *lLCSiscomPro2SQLPrim=0,
		  *lLCSiscomPro2SQLAct;
int lintNRegistros;
SiscomObtenInformacionArgumento(pchrPtrArgumento,
				pSAgsSiscom,
				&lLCSiscomPro2SQLPrim,
				&lLCSiscomPro2SQLAct,
				&lintNRegistros);
GeneraSQL(pSAgsSiscom->LCSiscomPro2Dat,
	  &lLCSiscomPro2SQLPrim,
	  &lLCSiscomPro2SQLAct,
	  &lintNRegistros);
SiscomAsignaInformacionArgumento(pchrPtrArgumento,
                              pSAgsSiscom,
                              lLCSiscomPro2SQLPrim,
                              lLCSiscomPro2SQLAct,
                              lintNRegistros);



}

