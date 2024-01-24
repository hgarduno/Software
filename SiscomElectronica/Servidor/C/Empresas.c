#include <Empresas.h>

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

#include <SqlEmpresas.h>
#include <SqlCatalogosSat.h>
#include <string.h>



void RFCs(int pintSocket,
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
SiscomAgregaOperacion(SqlRFCsRegistrados,&lSiscomProDat);
SiscomAgregaOperacion(EnviaRFCs,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}

void RegistraRegimenFiscal(int pintSocket,
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
SiscomAgregaOperacion(CreaArgumentoRegimenFiscal,&lSiscomProDat);
SiscomAgregaOperacion(SqlRegistraRegimenFiscal,&lSiscomProDat);
SiscomAgregaOperacion(RegistrandoRegimenFiscal,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}


int EnviaRFCs(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[512];
SiscomAsociadoEntradaLog("Envio",lchrArrBuffer,pSiscomOpePtrDato);
if(SiscomObtenRegistrosCampoRespuesta("Empresas",pSiscomOpePtrDato))
SiscomEnviaRegistrosSocket(pSiscomOpePtrDato->intSocket,
			  lchrArrBuffer,
			  SiscomRegistrosCampoO("Empresas",pSiscomOpePtrDato));
return 0;
}


int RegistrandoRegimenFiscal(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[512];
SiscomAsociadoEntradaLog("Envio",lchrArrBuffer,pSiscomOpePtrDato);
return 0;
}

int CreaArgumentoRegimenFiscal(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128];
SiscomAgregaArgumentoInsercionSql("SqlRegimenFiscal",
				  pSiscomOpePtrDato->chrArrBaseDatos,
				  pSiscomOpePtrDato->chrArrPuertoBaseDatos,
				  lchrArrBuffer,
				  pSiscomOpePtrDato);
return 0;
}
