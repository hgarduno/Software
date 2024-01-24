#include <OrdenRapida.h>

#include <SqlEscuelasSE.h>
#include <SqlOrdenRapida.h>

#include <SiscomDesarrolloMacros.h>
#include <SiscomMacrosOperaciones.h>
#include <SiscomCamposProtocolo.h>
#include <SiscomDesarrolloMacros.h>
#include <SiscomConfiguracionServidor.h>
#include <SiscomMacrosOperaciones.h>
#include <ComunSiscomElectronica4.h>

#include <string.h>
#include <stdio.h>

void OrdenEscuelaPrincipal(int pintSocket,
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
SiscomAgregaOperacion(SqlOrdenEscuelaPrincipal,&lSiscomProDat);
SiscomAgregaOperacion(EnviaOrdenEscuelaPrincipal,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}
void OrdenOtro(int pintSocket,
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
SiscomAgregaOperacion(SqlOrdenEscuelaOtro,&lSiscomProDat);
SiscomAgregaOperacion(EnviaOrdenEscuelaPrincipal,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}


int EnviaOrdenEscuelaPrincipal(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128];
SiscomAsociadoRespuestaLog("Escuela",lchrArrBuffer,pSiscomOpePtrDato);
SiscomAsociadoRespuestaLog("PublicoEnGeneral",lchrArrBuffer,pSiscomOpePtrDato);
SiscomEnviaRegistrosRespuesta(pSiscomOpePtrDato,lchrArrBuffer);
return 0;
}
