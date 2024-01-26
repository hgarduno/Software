#include <DatosGenerales.h>
#include <ComunSiscomServiSNTE.h>
#include <SqlDatosGenerales.h>
#include <SiscomDesarrolloMacros.h>
#include <SiscomMacrosOperaciones.h>

#include <string.h>
void RegistraGenerales(int pintSocket,
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
SiscomAgregaOperacion(SqlInsertaGeneralesCliente,&lSiscomProDat);
SiscomAgregaOperacion(EnviaEstadoRegistroGenerales,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}
void ActualizaGenerales(int pintSocket,
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
SiscomAgregaOperacion(SqlActualizaGeneralesCliente,&lSiscomProDat);
SiscomAgregaOperacion(EnviaEstadoRegistroGenerales,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}

int EstadoRegistroGenerales(SiscomOperaciones *pSiscomOpePtrDato)
{
  return 1;
}
int EnviaEstadoRegistroGenerales(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[256];
SiscomAsociadoEntradaLog("Envio",lchrArrBuffer,pSiscomOpePtrDato);
SiscomAsociadosArgumentoLog("SqlDatosGenerales","SentenciasSql",lchrArrBuffer,pSiscomOpePtrDato);
if(EstadoRegistroGenerales(pSiscomOpePtrDato))
RespondeRegistroExitoso(pSiscomOpePtrDato);
else
LogSiscom("Procesar el error");
return 0;
}
