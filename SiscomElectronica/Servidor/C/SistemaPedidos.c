#include <SistemaPedidos.h>
#include <SiscomDesarrolloMacros.h>
#include <SiscomCamposProtocolo.h>
#include <SiscomDesarrolloMacros.h>
#include <SiscomMacrosOperaciones.h>
#include <SiscomConfiguracionServidor.h>
#include <ComunSiscomElectronica4.h>
#include <SqlSistemaPedidos.h>

#include <string.h>
void OrdenesPendientes(int pintSocket,
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
SiscomAgregaOperacion(SqlOrdenesPendientes,&lSiscomProDat);
SiscomAgregaOperacion(EnviandoOrdenesPendientes,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}
int EnviandoOrdenesPendientes(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[256];
LogSiscom("Consultando BaseDatos(%s) Servidor(%s:%d)",
	  pSiscomOpePtrDato->chrArrBaseDatos,
	  pSiscomOpePtrDato->chrArrDirIpSvrAccesoDatos,
	  pSiscomOpePtrDato->intPuertoSvrAccesoDatos);
if(SiscomObtenRegistrosCampoRespuesta("OrdenesPendientes",pSiscomOpePtrDato))
SiscomEnviaRegistrosSocket(pSiscomOpePtrDato->intSocket,
			  lchrArrBuffer,
			  SiscomRegistrosCampoO("OrdenesPendientes",pSiscomOpePtrDato));
return 0;
}
