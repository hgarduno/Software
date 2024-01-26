#include <ActualizacionSistema.h>
#include <SqlActualizacionSistema.h>
#include <SiscomDesarrolloMacros.h>
#include <SiscomMacrosOperaciones.h>
#include <ComunSiscomServiSNTE.h>

#include <SqlActualizacionSistema.h>

#include <string.h>
void ActualizacionDisponible(int pintSocket,
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
SiscomAgregaOperacion(SqlActualizacionSistema,&lSiscomProDat);
SiscomAgregaOperacion(DatosActualizacionSistema,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat); 
}
void RegistraActualizacionMaquina(int pintSocket,
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
SiscomAgregaOperacion(SqlInsertaMaquinaActualizada,&lSiscomProDat);
SiscomAgregaOperacion(ActualizoSistema,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat); 
}
int ActualizoSistema(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128];
LogSiscom("Actualizo sistema :) :) :)");
SiscomAsociadoEntradaLog("Envio",lchrArrBuffer,pSiscomOpePtrDato);
return 0;
}

int DatosActualizacionSistema(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[2048];
SiscomRegistroProL *lSiscomRegProLPtrDato;

lSiscomRegProLPtrDato=SiscomRegistrosAsociadoRespuestaOperacion("ActualizaSistema",pSiscomOpePtrDato);
LogSiscom("%x \n",lSiscomRegProLPtrDato);
if(SiscomRegistrosAsociadoRespuestaOperacion("ActualizaSistema",pSiscomOpePtrDato))
{
SiscomAsociadoRespuestaLog("ActualizaSistema",lchrArrBuffer,pSiscomOpePtrDato); 
SiscomEnviaAsociadoRespuestaCliente("ActualizaSistema",lchrArrBuffer,pSiscomOpePtrDato);
}
else
{
LogSiscom("NO Hay Actualizacion disponible");
RespondeConsultaSinRegistros(pSiscomOpePtrDato);
}


return 0;
}
