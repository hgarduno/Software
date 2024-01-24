#include <EscuelasSE.h>
#include <SiscomDesarrolloMacros.h>
#include <SiscomCamposProtocolo.h>
#include <SiscomDesarrolloMacros.h>
#include <SiscomMacrosOperaciones.h>
#include <SiscomConfiguracionServidor.h>
#include <ComunSiscomElectronica4.h>
#include <SqlEscuelasSE.h>

#include <string.h>

/* Martes 22 de Marzo 2016
 * Queretaro
 * Se debe integrar en esta consulta, el tipo de 
 * producto, para que cuando se cotice se pueda 
 * considerar con la informacion que llega
 */

void EscuelasSE(int pintSocket,
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
SiscomAgregaOperacion(SqlEscuelasSE,&lSiscomProDat);
SiscomAgregaOperacion(EnviandoEscuelasSE,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}


void EntregaEscuela(int pintSocket,
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
SiscomAgregaOperacion(SqlEntregaEscuela,&lSiscomProDat);
SiscomAgregaOperacion(EnviandoEscuelasSE,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}


int EnviandoEscuelasSE(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[512];
if(SiscomObtenRegistrosCampoRespuesta("Escuelas",pSiscomOpePtrDato))
SiscomEnviaRegistrosSocket(pSiscomOpePtrDato->intSocket,
			  lchrArrBuffer,
			  SiscomRegistrosCampoO("Escuelas",pSiscomOpePtrDato));
return 0;
}
