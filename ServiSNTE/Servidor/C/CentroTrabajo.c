#include <CentroTrabajo.h>
#include <SqlCentroTrabajo.h>
#include <ComunSiscomServiSNTE.h>
#include <SiscomDesarrolloMacros.h>
#include <SiscomMacrosOperaciones.h>
#include <string.h>

void RegistraCentroTrabajo(int pintSocket,
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
SiscomAgregaOperacion(SqlInsertaCentroTrabajo,&lSiscomProDat);
SiscomAgregaOperacion(EnviaEstadoRegistroCentroTrabajo,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}
int EnviaEstadoRegistroCentroTrabajo(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128];
LogSiscom("Registrando el centro de trabajo");
SiscomAsociadoEntradaLog("Envio",lchrArrBuffer,pSiscomOpePtrDato);
SiscomAsociadosArgumentoLog("SqlCentroTrabajo","SentenciasSql",lchrArrBuffer,pSiscomOpePtrDato);
if(ValidaEstadoRegistroCentroTrabajo(pSiscomOpePtrDato))
   EnviaRegistroExitosoCentroTrabajo(pSiscomOpePtrDato);
else
{

}
}
int ValidaEstadoRegistroCentroTrabajo(SiscomOperaciones *pSiscomOpePtrDato)
{
return 1;
}
void EnviaRegistroExitosoCentroTrabajo(SiscomOperaciones *pSiscomOpePtrDato)
{
 RespondeRegistroExitoso(pSiscomOpePtrDato);
}
