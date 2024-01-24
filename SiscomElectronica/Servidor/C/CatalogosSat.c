#include <CatalogosSat.h>


#include <SiscomDesarrolloMacros.h>
#include <SiscomCamposProtocolo.h>
#include <SiscomDesarrolloMacros.h>
#include <SiscomMacrosOperaciones.h>
#include <SiscomConfiguracionServidor.h>
#include <SiscomProtocoloComunicaciones.h>
#include <SiscomOperaciones.h>
#include <SiscomInsercionesSql.h>
#include <SiscomDesarrollo4/H/SiscomFuncionesComunes.h>
#include <ComunSiscomElectronica4.h>

#include <SqlCatalogosSat.h>
#include <string.h>


void FormasPagoSat(int pintSocket,
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
SiscomAgregaOperacion(SqlFormasPagoSat,&lSiscomProDat);
SiscomAgregaOperacion(EnviaFormasPagoSat,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}

void MetodoPagoSat(int pintSocket,
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
SiscomAgregaOperacion(SqlMetodoPagoSat,&lSiscomProDat);
SiscomAgregaOperacion(EnviaMetodoPagoSat,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}

void UsoFacturaSat(int pintSocket,
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
SiscomAgregaOperacion(SqlUsoFacturaSat,&lSiscomProDat);
SiscomAgregaOperacion(EnviaUsoFacturaSat,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}
void RegimenFiscal(int pintSocket,
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
SiscomAgregaOperacion(SqlRegimenFiscal,&lSiscomProDat);
SiscomAgregaOperacion(EnviaRegimenFiscal,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}



int EnviaFormasPagoSat(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[512];
SiscomAsociadoEntradaLog("Envio",lchrArrBuffer,pSiscomOpePtrDato);
if(SiscomObtenRegistrosCampoRespuesta("FormaPagoSat",pSiscomOpePtrDato))
SiscomEnviaRegistrosSocket(pSiscomOpePtrDato->intSocket,
			  lchrArrBuffer,
			  SiscomRegistrosCampoO("FormaPagoSat",pSiscomOpePtrDato));
return 0;
}

int EnviaMetodoPagoSat(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[512];
SiscomAsociadoEntradaLog("Envio",lchrArrBuffer,pSiscomOpePtrDato);
if(SiscomObtenRegistrosCampoRespuesta("MetodoPagoSat",pSiscomOpePtrDato))
SiscomEnviaRegistrosSocket(pSiscomOpePtrDato->intSocket,
			  lchrArrBuffer,
			  SiscomRegistrosCampoO("MetodoPagoSat",pSiscomOpePtrDato));
return 0;
}

int EnviaUsoFacturaSat(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[512];
SiscomAsociadoEntradaLog("Envio",lchrArrBuffer,pSiscomOpePtrDato);
if(SiscomObtenRegistrosCampoRespuesta("UsoFacturaSat",pSiscomOpePtrDato))
SiscomEnviaRegistrosSocket(pSiscomOpePtrDato->intSocket,
			  lchrArrBuffer,
			  SiscomRegistrosCampoO("UsoFacturaSat",pSiscomOpePtrDato));
return 0;
}


int EnviaRegimenFiscal(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[512];
if(SiscomObtenRegistrosCampoRespuesta("RegimenFiscal",pSiscomOpePtrDato))
SiscomEnviaRegistrosSocket(pSiscomOpePtrDato->intSocket,
			  lchrArrBuffer,
			  SiscomRegistrosCampoO("RegimenFiscal",pSiscomOpePtrDato));
return 0;
}
