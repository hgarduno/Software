#include <JTExpress.h>
#include <SqlJTExpress.h>
#include <string.h>
#include <ComunSiscomElectronica4.h>
#include <SiscomDesarrolloMacros.h>
void JTExpressCobertura(int pintSocket,
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
SiscomAgregaOperacion(SqlCoberturaJTExpress,&lSiscomProDat); 
SiscomAgregaOperacion(EnviaCoberturaJTExpress,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}

int EnviaCoberturaJTExpress(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128];
LogSiscom("Validando Cobertura");
SiscomEnviaRegistrosRespuesta(pSiscomOpePtrDato,lchrArrBuffer);
return 0;
}
