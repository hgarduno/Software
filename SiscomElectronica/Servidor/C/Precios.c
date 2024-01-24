#include <Precios.h>
#include <SqlPrecios.h>
#include <SqlReportesSiscom.h>


#include <SiscomDesarrolloMacros.h>
#include <SiscomCamposProtocolo.h>
#include <SiscomDesarrolloMacros.h>
#include <SiscomMacrosOperaciones.h>
#include <SiscomConfiguracionServidor.h>
#include <SiscomProtocoloComunicaciones.h>
#include <SiscomOperaciones.h>
#include <SiscomInsercionesSql.h>
#include <SqlSiscomElectronica.h>
#include <SiscomDesarrollo4/H/SiscomFuncionesComunes.h>
#include <ComunSiscomElectronica4.h>

#include <string.h>

void ActualizaPrecioExpendios(int pintSocket,
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
SiscomAgregaOperacion(ArgumentoConsultaUnosExpendios,&lSiscomProDat);
SiscomAgregaOperacion(AgregaCampoCondicionExpendios,&lSiscomProDat);
SiscomAgregaOperacion(ArgumentoActualizaPrecioExpendios,&lSiscomProDat);
SiscomAgregaOperacion(CopiaExpendiosPrecios,&lSiscomProDat);
SiscomAgregaOperacion(CondicionConsultaUnosExpendios,&lSiscomProDat);
SiscomAgregaOperacion(SqlConsultandoUnosExpendios,&lSiscomProDat);
SiscomAgregaOperacion(SqlActualizaPrecioAlgunosExpendios,&lSiscomProDat);
SiscomAgregaOperacion(ActualizandoPrecioExpendios,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}

void SincronizaPreciosExpendio(int pintSocket,
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
SiscomAgregaOperacion(ArgumentoConsultaUnosExpendios,&lSiscomProDat);
SiscomAgregaOperacion(AgregaCampoCondicionExpendios,&lSiscomProDat);
SiscomAgregaOperacion(ArgumentoActualizaPrecioExpendios,&lSiscomProDat);
SiscomAgregaOperacion(CopiaExpendiosPrecios,&lSiscomProDat);
SiscomAgregaOperacion(CondicionConsultaUnosExpendios,&lSiscomProDat);
SiscomAgregaOperacion(SqlConsultandoUnosExpendios,&lSiscomProDat);
SiscomAgregaOperacion(SqlActualizaPrecioAlgunosExpendios,&lSiscomProDat);
SiscomAgregaOperacion(ActualizandoPreciosExpendio,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);


}

void Precios2Productos(int pintSocket,
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
SiscomAgregaOperacion(ArgumentoExpendioPrecios,&lSiscomProDat);
SiscomAgregaOperacion(ArgumentoPreciosOrigen,&lSiscomProDat);
SiscomAgregaOperacion(ArgumentoPreciosDestino,&lSiscomProDat);
SiscomAgregaOperacion(SqlExpendiosSiscom,&lSiscomProDat);
SiscomAgregaOperacion(SqlPreciosExpendios,&lSiscomProDat);
SiscomAgregaOperacion(EnviandoPrecios2Expendios,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}

void PreciosExpendios(int pintSocket,
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
SiscomAgregaOperacion(ArgumentoExpendioPrecios,&lSiscomProDat);
SiscomAgregaOperacion(ArgumentoPreciosOrigen,&lSiscomProDat);
SiscomAgregaOperacion(ArgumentoPreciosDestino,&lSiscomProDat);
SiscomAgregaOperacion(SqlExpendiosSiscom,&lSiscomProDat);
SiscomAgregaOperacion(SqlPreciosExpendios,&lSiscomProDat);
SiscomAgregaOperacion(EnviandoPreciosExpendios,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}

int EnviandoPreciosExpendios(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[256];
/*SiscomArgumentoLog("PreciosOrigen",lchrArrBuffer,pSiscomOpePtrDato); 
SiscomArgumentoLog("PreciosDestino",lchrArrBuffer,pSiscomOpePtrDato); 
*/
FormaRespuestaEnvia(pSiscomOpePtrDato);
return 0;
}

int EnviandoPrecios2Expendios(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[256];
SiscomArgumentoLog("PreciosOrigen",lchrArrBuffer,pSiscomOpePtrDato); 
SiscomArgumentoLog("PreciosDestino",lchrArrBuffer,pSiscomOpePtrDato); 
return 0;
}
void FormaRespuestaEnvia(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[256];
SiscomRegistroProL *lSisRegProLPtrPrimReg=0,
	 	   *lSisRegProLPtrActReg=0;

SiscomAnexaRegistroPro(&lSisRegProLPtrPrimReg,
		       &lSisRegProLPtrActReg,
		 lchrArrBuffer,
		 "PreciosO,IdExpendioO,PreciosD,IdExpendioD,",
		 (const char *)0,
		 SiscomCampoAsociadoEntradaOperacion("Envio","IdExpendioO",pSiscomOpePtrDato),
		 (const char *)0,
		 SiscomCampoAsociadoEntradaOperacion("Envio","IdExpendioD",pSiscomOpePtrDato));

SiscomRegistrosAlCampo("PreciosO",
		 SiscomObtenArgumentoPrimOperaciones("PreciosOrigen",pSiscomOpePtrDato),	
		 SiscomObtenArgumentoActOperaciones("PreciosOrigen",pSiscomOpePtrDato),	
		 lSisRegProLPtrActReg);

SiscomRegistrosAlCampo("PreciosD",
		       SiscomObtenArgumentoPrimOperaciones("PreciosDestino",pSiscomOpePtrDato),	
		       SiscomObtenArgumentoActOperaciones("PreciosDestino",pSiscomOpePtrDato),	
		       lSisRegProLPtrActReg);
SiscomRegistroProtocoloLog(lchrArrBuffer,lSisRegProLPtrPrimReg);
SiscomEnviaRegistrosSocket(pSiscomOpePtrDato->intSocket,lchrArrBuffer,lSisRegProLPtrPrimReg); 
}
int ArgumentoExpendioPrecios(SiscomOperaciones *pSiscomOpePtrDato)
{
SiscomAgregaArgumentoOperacion("Expendios",
                                (SiscomRegistroProL *)0,
                                (SiscomRegistroProL *)0,
                                pSiscomOpePtrDato);
return 0;
}
int ArgumentoPreciosOrigen(SiscomOperaciones *pSiscomOpePtrDato)
{
SiscomAgregaArgumentoOperacion("PreciosOrigen",
                                (SiscomRegistroProL *)0,
                                (SiscomRegistroProL *)0,
                                pSiscomOpePtrDato);

return 0;
}

int ArgumentoPreciosDestino(SiscomOperaciones *pSiscomOpePtrDato)
{
SiscomAgregaArgumentoOperacion("PreciosDestino",
				(SiscomRegistroProL *)0,
				(SiscomRegistroProL *)0,
				pSiscomOpePtrDato);
return 0;
}
void FormaPreciosProductos(SiscomOperaciones *pSiscomOpPtrDato)
{


}

int ArgumentoActualizaPrecioExpendios(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128];
SiscomAgregaArgumentoInsercionSql("SqlPrecioExpendios",
				  pSiscomOpePtrDato->chrArrBaseDatos,
				  pSiscomOpePtrDato->chrArrPuertoBaseDatos,
				  lchrArrBuffer,
				  pSiscomOpePtrDato);
return 0;
}
int AgregaCampoCondicionExpendios(SiscomOperaciones *pSisOpePtrDato)
{
AgregaCampoCondicionConsultaUnosExpendios("Envio",pSisOpePtrDato);
 return 0;
}
int ActualizandoPrecioExpendios(SiscomOperaciones *pSisOpePtrDato)
{
/*
char lchrArrBuffer[128];
SiscomAsociadoEntradaLog("Envio",lchrArrBuffer,pSisOpePtrDato);
SiscomAsociadoAsociadoLog("Envio","Precios",lchrArrBuffer,pSisOpePtrDato);
SiscomAsociadoAsociadoLog("Envio","Expendios",lchrArrBuffer,pSisOpePtrDato);
SiscomArgumentoLog("Expendios",lchrArrBuffer,pSisOpePtrDato);
*/
return 0;
}
int ActualizandoPreciosExpendio(SiscomOperaciones *pSisOpePtrDato)
{
/*
char lchrArrBuffer[128];
SiscomAsociadoEntradaLog("Envio",lchrArrBuffer,pSisOpePtrDato);
SiscomAsociadoAsociadoLog("Envio","Precios",lchrArrBuffer,pSisOpePtrDato);
SiscomAsociadoAsociadoLog("Envio","Expendios",lchrArrBuffer,pSisOpePtrDato);
SiscomArgumentoLog("Expendios",lchrArrBuffer,pSisOpePtrDato);
*/
return 0;
}

int CopiaExpendiosPrecios(SiscomOperaciones *pSisOpePtrDato)
{
CopiaExpendiosAArgumento("Envio","Expendios",pSisOpePtrDato);
return 0;
}
