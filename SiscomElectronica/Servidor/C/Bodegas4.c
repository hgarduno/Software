#include <Bodegas4.h>
#include <SqlBodegas.h>

#include <SiscomDesarrolloMacros.h>
#include <SiscomCamposProtocolo.h>
#include <SiscomMacrosOperaciones.h>
#include <SiscomMacrosInsercionesSql.h>
#include <SiscomConfiguracionServidor.h>
#include <SiscomProtocoloComunicaciones.h>
#include <SiscomOperaciones.h>

#include <SiscomInsercionesSql.h>
#include <SiscomDesarrollo4/H/SiscomFuncionesComunes.h>
#include <ComunSiscomElectronica4.h>

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void TransfiereBodegaBodega(int pintSocket,
             SiscomRegistroProL *pSiscomRegProLPtrPrim,
             SiscomRegistroProL *pSiscomRegProLPtrAct)
{
SiscomProcesos *lSiscomProDat=0;
SiscomOperaciones lSiscomOpDat;
memset(&lSiscomOpDat,0,sizeof(SiscomOperaciones));
SiscomIniciaDatosOperacion(pintSocket,
			   0,
			   (SiscomRegistroProL *)pSiscomRegProLPtrPrim,
			   (SiscomRegistroProL *)pSiscomRegProLPtrAct,
			   &lSiscomOpDat);
SiscomAgregaOperacion(AccesoDatosSiscomElectronica4,&lSiscomProDat);
SiscomAgregaOperacion(ArgumentoBodegaOrigen,&lSiscomProDat);
SiscomAgregaOperacion(ArgumentoBodegaDestino,&lSiscomProDat);
SiscomAgregaOperacion(ArgumentoSqlLocal,&lSiscomProDat);
SiscomAgregaOperacion(SqlSentenciasMatriz,&lSiscomProDat);
SiscomAgregaOperacion(SqlEnviandoSqlTransferenciasBodegaBodega,&lSiscomProDat);
SiscomAgregaOperacion(SqlActualizaBodegaOrigenDestino,&lSiscomProDat);
SiscomAgregaOperacion(TransfiriendoBodegaBodega,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}


void BodegasExpendios(int pintSocket,
             SiscomRegistroProL *pSiscomRegProLPtrPrim,
             SiscomRegistroProL *pSiscomRegProLPtrAct)
{
SiscomProcesos *lSiscomProDat=0;
SiscomOperaciones lSiscomOpDat;
memset(&lSiscomOpDat,0,sizeof(SiscomOperaciones));
SiscomIniciaDatosOperacion(pintSocket,
			   0,
			   (SiscomRegistroProL *)pSiscomRegProLPtrPrim,
			   (SiscomRegistroProL *)pSiscomRegProLPtrAct,
			   &lSiscomOpDat);
SiscomAgregaOperacion(AccesoDatosSiscomElectronica4,&lSiscomProDat);
SiscomAgregaOperacion(SqlBodegasExpendios,&lSiscomProDat);
SiscomAgregaOperacion(EnviaExpendiosBodegas,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}


void ExistenciaBodega4(int pintSocket,
             SiscomRegistroProL *pSiscomRegProLPtrPrim,
             SiscomRegistroProL *pSiscomRegProLPtrAct)
{
SiscomProcesos *lSiscomProDat=0;
SiscomOperaciones lSiscomOpDat;
memset(&lSiscomOpDat,0,sizeof(SiscomOperaciones));
SiscomIniciaDatosOperacion(pintSocket,
			   0,
			   (SiscomRegistroProL *)pSiscomRegProLPtrPrim,
			   (SiscomRegistroProL *)pSiscomRegProLPtrAct,
			   &lSiscomOpDat);
SiscomAgregaOperacion(AccesoDatosSiscomElectronica4,&lSiscomProDat);
SiscomAgregaOperacion(ArgumentoExistenciaBodega,&lSiscomProDat);
SiscomAgregaOperacion(SqlExistenciaBodega4,&lSiscomProDat);
SiscomAgregaOperacion(EnviaExistenciaBodega,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}


void ActualizaExistenciaBodega4(int pintSocket,
             SiscomRegistroProL *pSiscomRegProLPtrPrim,
             SiscomRegistroProL *pSiscomRegProLPtrAct)
{
SiscomProcesos *lSiscomProDat=0;
SiscomOperaciones lSiscomOpDat;
memset(&lSiscomOpDat,0,sizeof(SiscomOperaciones));
SiscomIniciaDatosOperacion(pintSocket,
			   0,
			   (SiscomRegistroProL *)pSiscomRegProLPtrPrim,
			   (SiscomRegistroProL *)pSiscomRegProLPtrAct,
			   &lSiscomOpDat);
SiscomAgregaOperacion(AccesoDatosSiscomElectronica4,&lSiscomProDat);
SiscomAgregaOperacion(ArgumentoActualizaExistencia,&lSiscomProDat);
SiscomAgregaOperacion(SqlActualizaExistenciaBodega4,&lSiscomProDat);
SiscomAgregaOperacion(EnviaActualizaExistenciaBodega,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}

void ValidaExistenciaBodega(int pintSocket,
             SiscomRegistroProL *pSiscomRegProLPtrPrim,
             SiscomRegistroProL *pSiscomRegProLPtrAct)
{
SiscomProcesos *lSiscomProDat=0;
SiscomOperaciones lSiscomOpDat;
memset(&lSiscomOpDat,0,sizeof(SiscomOperaciones));
SiscomIniciaDatosOperacion(pintSocket,
			   0,
			   (SiscomRegistroProL *)pSiscomRegProLPtrPrim,
			   (SiscomRegistroProL *)pSiscomRegProLPtrAct,
			   &lSiscomOpDat);
SiscomAgregaOperacion(AccesoDatosSiscomElectronica4,&lSiscomProDat);
SiscomAgregaOperacion(ArgumentoExistenciaBodega,&lSiscomProDat);
SiscomAgregaOperacion(SqlExistenciaBodega4,&lSiscomProDat);
SiscomAgregaOperacion(EnviaValidacionExistenciaBodega,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}

int EnviaActualizaExistenciaBodega(SiscomOperaciones *pSisOpePtrDatos)
{
char lchrArrBuffer[256];
SiscomAsociadoEntradaLog("Envio",lchrArrBuffer,pSisOpePtrDatos);
SiscomAsociadosArgumentoLog("SqlExistenciaBodega","SentenciasSql",lchrArrBuffer,pSisOpePtrDatos);
return 0;
}


int EnviaExistenciaBodega(SiscomOperaciones *pSisOpePtrDatos)
{
char lchrArrBuffer[256];
SiscomRegistroProL *lSisRegProLPtrEx;
lSisRegProLPtrEx=SiscomObtenArgumentoPrimOperaciones("ExistenciaBodega",pSisOpePtrDatos);
SiscomEnviaRegistrosSocket(pSisOpePtrDatos->intSocket,
			  lchrArrBuffer,
			  lSisRegProLPtrEx);
/*
 * 
 * CDMX Sabado 15 de Julio 2023
 *
 * Por alguna razon esta funcion truena ,,, revisar porque pasa esto
SiscomEnviaArgumentoCliente("ExistenciaBodega",lchrArrBuffer,pSisOpePtrDatos); 
SiscomArgumentoLog("ExistenciaBodega",lchrArrBuffer,pSisOpePtrDatos);

*/
return 0;
}
int EnviaExpendiosBodegas(SiscomOperaciones *pSisOpePtrDatos)
{
char lchrArrBuffer[512];
if(SiscomObtenRegistrosCampoRespuesta("BodegasExpendios",pSisOpePtrDatos))
SiscomEnviaRegistrosSocket(pSisOpePtrDatos->intSocket,
			  lchrArrBuffer,
			  SiscomRegistrosCampoO("BodegasExpendios",pSisOpePtrDatos));
return 0;
}


int ArgumentoActualizaExistencia(SiscomOperaciones *pSisOpePtrDato)
{
char lchrArrBuffer[256];

LogSiscom("Actualizando la base %s",DatoBodegaExpendio("Base",pSisOpePtrDato));
SiscomAgregaArgumentoInsercionSql("SqlExistenciaBodega",
				  DatoBodegaExpendio("Base",pSisOpePtrDato),
				  0,
				  lchrArrBuffer,
				  pSisOpePtrDato);

return 0;
				  
}
int ArgumentoBodegaOrigen(SiscomOperaciones *pSisOpePtrDato)
{
char lchrArrBuffer[128];
LogSiscom("La Base de la bodega origen %s",
	ObtenBaseBodegaO(pSisOpePtrDato));
SiscomAgregaArgumentoInsercionSql("SqlBodegaO",
				  ObtenBaseBodegaO(pSisOpePtrDato),
				  0,
				  lchrArrBuffer,
				  pSisOpePtrDato);

return 0;
}

int ArgumentoSqlLocal(SiscomOperaciones *pSisOpePtrDato)
{
char lchrArrBuffer[128];
SiscomAgregaArgumentoInsercionSql("SqlLocal",
				  /*ObtenBaseBodegaO(pSisOpePtrDato),*/
				  pSisOpePtrDato->chrArrBaseDatos,
				  pSisOpePtrDato->chrArrPuertoBaseDatos,
				  lchrArrBuffer,
				  pSisOpePtrDato);

return 0;
}

int ArgumentoBodegaDestino(SiscomOperaciones *pSisOpePtrDato)
{
char lchrArrBuffer[128];
LogSiscom("La Base de la bodega Destino %s",ObtenBaseBodegaD(pSisOpePtrDato));
SiscomAgregaArgumentoInsercionSql("SqlBodegaD",
				  ObtenBaseBodegaD(pSisOpePtrDato),
				  0,
				  lchrArrBuffer,
				  pSisOpePtrDato);
return 0;
}

int PuertoExpendioBodega(SiscomOperaciones *pSisOpePtrDatos)
{
const char *lchrPtrPuerto=DatoBodegaExpendio("Puerto",pSisOpePtrDatos);
return atoi(lchrPtrPuerto);
}

const char *DatoBodegaExpendio(const char *pchrPtrDato,SiscomOperaciones *pSisOpePtrDatos)
{
SiscomRegistroProL *lSisRegProLPtrExpendio;
char lchrArrBuffer[128];
if((lSisRegProLPtrExpendio=SiscomRegistrosCampoAsociadoAsociadoEntradaOperacion("Envio",
							"Bodega",
							"Expendio",
							pSisOpePtrDatos)))
{
/*
SiscomRegistroProtocoloLog(lchrArrBuffer,lSisRegProLPtrExpendio);

*/
return SiscomObtenCampoRegistroProLChar(pchrPtrDato,lSisRegProLPtrExpendio);
}
else
return 0;
}
const char *DatoBodega(const char *pchrPtrDato,SiscomOperaciones *pSisOpePtrDatos)
{
return SiscomCampoAsociadoAsociadoEntradaOperacion("Envio",
						   "Bodega",
						   pchrPtrDato,
						   pSisOpePtrDatos);
}

int TransfiriendoBodegaBodega(SiscomOperaciones *pSisOpePtrDatos)
{
char lchrArrBuffer[128];

LogSiscom("Origen %s -> Destino %s",
	  ObtenDirIpExpendioBodegaO(pSisOpePtrDatos),
	  ObtenDirIpExpendioBodegaD(pSisOpePtrDatos));
/*
SiscomAsociadoEntradaLog("Envio",lchrArrBuffer,pSisOpePtrDatos);
SiscomAsociadoAsociadoLog("Envio","BodegaO",lchrArrBuffer,pSisOpePtrDatos);
SiscomAsociadoAsociadoLog("Envio","BodegaD",lchrArrBuffer,pSisOpePtrDatos);

*/
SiscomArgumentoInsercionSqlLog("SqlBodegaO",lchrArrBuffer,pSisOpePtrDatos);
SiscomArgumentoInsercionSqlLog("SqlBodegaD",lchrArrBuffer,pSisOpePtrDatos);
SiscomArgumentoInsercionSqlLog("SqlLocal",lchrArrBuffer,pSisOpePtrDatos);
}

int ArgumentoExistenciaBodega(SiscomOperaciones *pSisOpPtrDatos)
{
char lchrArrBuffer[125];
SiscomAgregaArgumentoOperacion("ExistenciaBodega",
			       (SiscomRegistroProL *)0,
			       (SiscomRegistroProL *)0,
			       pSisOpPtrDatos);
return 0;
}
SiscomRegistroProL *RegistroExpendioBodega(const char *pchrPtrOrgDes,SiscomOperaciones *pSisOpePtrDato)
{
SiscomRegistroProL *lSisRegProLPtrExpendioO;
char lchrArrBuffer[128];
if((lSisRegProLPtrExpendioO=SiscomRegistrosCampoAsociadoAsociadoEntradaOperacion("Envio",
									     pchrPtrOrgDes,
									     "Expendio",
									     pSisOpePtrDato)))
{
/*
   SiscomRegistroProtocoloLog(lchrArrBuffer,lSisRegProLPtrExpendioO);
*/
    return lSisRegProLPtrExpendioO; 
}
}

SiscomRegistroProL *RegistroBodega(const char *pchrPtrOrgDes,
				   SiscomOperaciones *pSisOpePtrDato)
{
SiscomRegistroProL *lSisRegProLPtrExpendioO;
char lchrArrBuffer[128];
if((lSisRegProLPtrExpendioO=SiscomRegistroAsociadoEntradaOperacion("Envio",
								   pchrPtrOrgDes,
								  pSisOpePtrDato)))
{
/*
   SiscomRegistroProtocoloLog(lchrArrBuffer,lSisRegProLPtrExpendioO);
*/
    return lSisRegProLPtrExpendioO; 
}
}
const char *ObtenDirIpExpendioBodegaO(SiscomOperaciones *pSisOpePtrDato)
{
const char *lchrPtrDirIpExBodO;
SiscomRegistroProL *lSisRegProLPtrExpendioO;

 if((lSisRegProLPtrExpendioO=RegistroExpendioBodega("BodegaO",pSisOpePtrDato)))
 if((lchrPtrDirIpExBodO=SiscomObtenCampoRegistroProLChar("DirIp",lSisRegProLPtrExpendioO)))
    return lchrPtrDirIpExBodO;
	
}

int ObtenPuertoExpendioBodegaO(SiscomOperaciones *pSisOpePtrDato)
{
int lintPuerto;
SiscomRegistroProL *lSisRegProLPtrExpendioO;

 if((lSisRegProLPtrExpendioO=RegistroExpendioBodega("BodegaO",pSisOpePtrDato)))
 if((lintPuerto=SiscomObtenCampoRegistroProLInt("Puerto",lSisRegProLPtrExpendioO)))
    return lintPuerto;
}

const char *ObtenBaseBodegaO(SiscomOperaciones *pSisOpePtrDato)
{
const char *lchrPtrDirIpExBodO;
SiscomRegistroProL *lSisRegProLPtrExpendioO;

 if((lSisRegProLPtrExpendioO=RegistroExpendioBodega("BodegaO",pSisOpePtrDato)))
 if((lchrPtrDirIpExBodO=SiscomObtenCampoRegistroProLChar("Base",lSisRegProLPtrExpendioO)))
    return lchrPtrDirIpExBodO;
	
}

const char *ObtenIdBodegaO(SiscomOperaciones *pSisOpePtrDato)
{
const char *lchrPtrDirIpExBodO;
SiscomRegistroProL *lSisRegProLPtrExpendioO;

 if((lSisRegProLPtrExpendioO=RegistroBodega("BodegaO",pSisOpePtrDato)))
 if((lchrPtrDirIpExBodO=SiscomObtenCampoRegistroProLChar("IdBodega",lSisRegProLPtrExpendioO)))
    return lchrPtrDirIpExBodO;
	

}

const char *ObtenDirIpExpendioBodegaD(SiscomOperaciones *pSisOpePtrDato)
{
const char *lchrPtrDirIpExBodO;
SiscomRegistroProL *lSisRegProLPtrExpendioO;

 if((lSisRegProLPtrExpendioO=RegistroExpendioBodega("BodegaD",pSisOpePtrDato)))
 if((lchrPtrDirIpExBodO=SiscomObtenCampoRegistroProLChar("DirIp",lSisRegProLPtrExpendioO)))
    return lchrPtrDirIpExBodO;
	
}
int ObtenPuertoExpendioBodegaD(SiscomOperaciones *pSisOpePtrDato)
{
int lintPuerto;
SiscomRegistroProL *lSisRegProLPtrExpendioO;

 if((lSisRegProLPtrExpendioO=RegistroExpendioBodega("BodegaD",pSisOpePtrDato)))
 if((lintPuerto=SiscomObtenCampoRegistroProLInt("Puerto",lSisRegProLPtrExpendioO)))
    return lintPuerto;
}


const char *ObtenBaseBodegaD(SiscomOperaciones *pSisOpePtrDato)
{
const char *lchrPtrDirIpExBodO;
SiscomRegistroProL *lSisRegProLPtrExpendioO;

 if((lSisRegProLPtrExpendioO=RegistroExpendioBodega("BodegaD",pSisOpePtrDato)))
 if((lchrPtrDirIpExBodO=SiscomObtenCampoRegistroProLChar("Base",lSisRegProLPtrExpendioO)))
    return lchrPtrDirIpExBodO;
	
}

const char *ObtenIdBodegaD(SiscomOperaciones *pSisOpePtrDato)
{
const char *lchrPtrDirIpExBodO;
SiscomRegistroProL *lSisRegProLPtrExpendioO;
 if((lSisRegProLPtrExpendioO=RegistroBodega("BodegaD",pSisOpePtrDato)))
 if((lchrPtrDirIpExBodO=SiscomObtenCampoRegistroProLChar("IdBodega",lSisRegProLPtrExpendioO)))
    return lchrPtrDirIpExBodO;
}
int CantidadVSExistenciaBodega(SiscomOperaciones *pSisOpePtrDato)
{
const char *lchrPtrExistencia,
	   *lchrPtrCantidad;
float lfltCantidad,lfltExistencia;
lchrPtrExistencia=SiscomCampoArgumentoAct("ExistenciaBodega",
					  "existencia",
					  pSisOpePtrDato);
lfltExistencia=atof(lchrPtrExistencia);
lfltCantidad=SiscomCampoAsociadoEntradaOperacionFloat("Envio","Cantidad",pSisOpePtrDato);

if(lfltCantidad<=lfltExistencia)
return 1;
else 
return 0;

}
int EnviaValidacionExistenciaBodega(SiscomOperaciones *pSisOpePtrDato)
{
char lchrArrBuffer[512];
if(CantidadVSExistenciaBodega(pSisOpePtrDato))
   SiscomFormaEnviaRegistroRespuesta(pSisOpePtrDato,lchrArrBuffer,"Estado,","1");
else
   SiscomFormaEnviaRegistroRespuesta(pSisOpePtrDato,lchrArrBuffer,"Estado,","0");
return 0;
}
