#include <CancelacionFolios.h>
#include <SqlCancelacionFolios.h>
#include <ComunSiscomServiSNTE.h>
#include <SiscomDesarrolloMacros.h>
#include <SiscomMacrosOperaciones.h>
#include <string.h>
void RegistraCancelacionFolio(int pintSocket,
	   void *pvidPtrAncla,
	   const SiscomRegistroProL *pSiscomRegProLPtrPrim,
	   const SiscomRegistroProL *pSiscomRegProLPtrAct)
{
SiscomProcesos *lSiscomProDat=0;
SiscomOperaciones lSiscomOpDat;
memset(&lSiscomOpDat,0,sizeof(SiscomOperaciones));
SiscomIniciaDatosOperacion(pintSocket,
			   pvidPtrAncla,
			   (SiscomRegistroProL *)pSiscomRegProLPtrPrim,
			   (SiscomRegistroProL *)pSiscomRegProLPtrAct,
			   &lSiscomOpDat);
SiscomAgregaOperacion(ComunicacionAccesoDatos,&lSiscomProDat);
SiscomAgregaOperacion(GeneraIdCancelacionFolio,&lSiscomProDat);
SiscomAgregaOperacion(SqlRegistraCancelacionFolio,&lSiscomProDat);
SiscomAgregaOperacion(EnviaIdCancelacionFolioRegistrado,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}


int GeneraIdCancelacionFolio(SiscomOperaciones *pSiscomOpePtrDato)
{
  SiscomIdARegistrosAsociadosEntrada("Envio","IdCancelacionFolio",pSiscomOpePtrDato);
}

int EnviaIdCancelacionFolioRegistrado(SiscomOperaciones *pSiscomOpePtrDato)
{
LogSiscom("");
SiscomRegistroProL *lSiscomRegProLPtrPrim=0,
		   *lSiscomRegProLPtrAct=0;
char lchrArrBuffer[128];
const char *lchrPtrIdCancelacionFolio;
lchrPtrIdCancelacionFolio=SiscomCampoAsociadoEntradaOperacion("Envio",
						     "IdCancelacionFolio",
						     pSiscomOpePtrDato);
SiscomAnexaRegistroPro(&lSiscomRegProLPtrPrim,
		       &lSiscomRegProLPtrAct,
		       lchrArrBuffer,
		       "IdCancelacionFolio,Mensajes,",
		       lchrPtrIdCancelacionFolio,
		       "Registro Exitoso");
SiscomEnviaRegistrosSocket(pSiscomOpePtrDato->intSocket,
			   lchrArrBuffer,
			   lSiscomRegProLPtrPrim);
SiscomRegistroProtocoloLog(lchrArrBuffer,lSiscomRegProLPtrPrim);
SiscomAsociadosArgumentoLog("SqlInsertaCancelacionFolio",
			    "SentenciasSql",
			    lchrArrBuffer,
			    pSiscomOpePtrDato);
}
