#include <MediosComunicacion.h>
#include <SqlMediosComunicacion.h>
#include <ComunSiscomServiSNTE.h>
#include <SiscomDesarrolloMacros.h>
#include <SiscomMacrosOperaciones.h>
#include <string.h>
void RegistraTelefonosCliente(int pintSocket,
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
SiscomAgregaOperacion(AsignaIdTelefonosCliente,&lSiscomProDat);
SiscomAgregaOperacion(AsignaIdCorreo,&lSiscomProDat);
SiscomAgregaOperacion(SqlTelefonosCliente,&lSiscomProDat); 
SiscomAgregaOperacion(EnviaEstadoRegistroTelefonos,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}
void ActualizaTelefonosCliente(int pintSocket,
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
SiscomAgregaOperacion(SqlActualizaTelefonosCliente,&lSiscomProDat); 
SiscomAgregaOperacion(EnviaEstadoRegistroTelefonos,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}


int EnviaEstadoRegistroTelefonos(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[1024];
SiscomAsociadoEntradaLog("Envio",lchrArrBuffer,pSiscomOpePtrDato);
SiscomAsociadosArgumentoLog("SqlTelefonos","SentenciasSql",lchrArrBuffer,pSiscomOpePtrDato);  
if(ValidaRegistroTelefonos(pSiscomOpePtrDato))
RespondeRegistroExitoso(pSiscomOpePtrDato);
else
LogSiscom("Falta el registro con error");
return 0;
}

int AsignaIdTelefonosCliente(SiscomOperaciones *pSiscomOpePtrDato)
{
SiscomIdAsociadosCampoEntrada("Envio","Telefonos","IdTelefono",pSiscomOpePtrDato);
return 0;
}

int AsignaIdCorreo(SiscomOperaciones *pSiscomOpePtrDato)
{
SiscomIdAsociadosCampoEntrada("Envio","Correo","IdCorreo",pSiscomOpePtrDato);
return 0;
}
int ValidaRegistroTelefonos(SiscomOperaciones *pSiscomOpePtrDato)
{
return 1;
}
