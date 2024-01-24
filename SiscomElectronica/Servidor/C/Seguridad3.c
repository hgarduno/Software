#include <Seguridad3.h>
#include <SqlSeguridad3.h>
#include <ComunSiscomElectronica4.h>


#include <SiscomDesarrolloMacros.h>
#include <SiscomCamposProtocolo.h>
#include <SiscomDesarrolloMacros.h>
#include <SiscomMacrosOperaciones.h>
#include <SiscomConfiguracionServidor.h>
#include <SiscomProtocoloComunicaciones.h>
#include <SiscomInsercionesSql.h>

#include <string.h>

void PerfilesAplicacion(int pintSocket,
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
SiscomAgregaOperacion(AccesoDatosSeguridad3,&lSiscomProDat);
SiscomAgregaOperacion(SqlPerfilesAplicacion,&lSiscomProDat);
SiscomAgregaOperacion(RegresaPerfilesAplicacion,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}
int RegresaPerfilesAplicacion(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128];
SiscomAsociadoRespuestaLog("Perfiles",lchrArrBuffer,pSiscomOpePtrDato);
SiscomEnviaAsociadoRespuestaCliente("Perfiles",lchrArrBuffer,pSiscomOpePtrDato);
LogSiscom("------");
return 0;
}
