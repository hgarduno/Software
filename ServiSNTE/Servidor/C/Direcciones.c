#include <Direcciones.h>
#include <SqlDirecciones.h>
#include <ComunSiscomServiSNTE.h>
#include <SiscomDesarrolloMacros.h>
#include <SiscomMacrosOperaciones.h>
#include <string.h>
void RegistraDireccion(int pintSocket,
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
SiscomAgregaOperacion(GeneraIdDireccion,&lSiscomProDat);
SiscomAgregaOperacion(SqlRegistraDireccion,&lSiscomProDat);
SiscomAgregaOperacion(EnviaIdDireccionRegistrada,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}

void ActualizaDireccion(int pintSocket,
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
SiscomAgregaOperacion(SqlActualizaDireccion,&lSiscomProDat);
SiscomAgregaOperacion(EnviaIdDireccionRegistrada,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}



void RegistraDatosCasa(int pintSocket,
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
SiscomAgregaOperacion(SqlRegistraDatosCasa,&lSiscomProDat);
SiscomAgregaOperacion(EnviaEstadoRegistroDatosCasa,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}
int ValidandoRegistroDatosCasa(SiscomOperaciones *pSiscomOpePtrDato)
{
   return 1;
}
int EnviaEstadoRegistroDatosCasa(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128];
if(ValidandoRegistroDatosCasa(pSiscomOpePtrDato))
RespondeRegistroExitoso(pSiscomOpePtrDato);

SiscomAsociadosArgumentoLog("SqlInsertaDireccion",
			    "SentenciasSql",
			    lchrArrBuffer,
			    pSiscomOpePtrDato);
}

void DireccionesPersona(int pintSocket,
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
SiscomAgregaOperacion(SqlDireccionesPersona,&lSiscomProDat);
SiscomAgregaOperacion(EnviaDirecciones,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}


int GeneraIdDireccion(SiscomOperaciones *pSiscomOpePtrDato)
{
  SiscomIdARegistrosAsociadosEntrada("Envio","IdDireccion",pSiscomOpePtrDato);
}

int EnviaIdDireccionRegistrada(SiscomOperaciones *pSiscomOpePtrDato)
{
SiscomRegistroProL *lSiscomRegProLPtrPrim=0,
		   *lSiscomRegProLPtrAct=0;
char lchrArrBuffer[128];
const char *lchrPtrIdDireccion;
lchrPtrIdDireccion=SiscomCampoAsociadoEntradaOperacion("Envio",
						     "IdDireccion",
						     pSiscomOpePtrDato);
SiscomAnexaRegistroPro(&lSiscomRegProLPtrPrim,
		       &lSiscomRegProLPtrAct,
		       lchrArrBuffer,
		       "IdDireccion,Mensajes,",
		       lchrPtrIdDireccion,
		       "Registro Exitoso");
SiscomEnviaRegistrosSocket(pSiscomOpePtrDato->intSocket,
			   lchrArrBuffer,
			   lSiscomRegProLPtrPrim);
SiscomRegistroProtocoloLog(lchrArrBuffer,lSiscomRegProLPtrPrim);
/*
SiscomAsociadosArgumentoLog("SqlInsertaDireccion",
			    "SentenciasSql",
			    lchrArrBuffer,
			    pSiscomOpePtrDato);
*/
}

int HayDatosDirecciones(SiscomOperaciones *pSiscomOpePtrDato)
{
SiscomRegistroProL *lSiscomRegProLPtrCliente;
lSiscomRegProLPtrCliente=SiscomObtenRegistrosCampoRespuesta("DireccionesPersona",pSiscomOpePtrDato);
return lSiscomRegProLPtrCliente ? 1 : 0;
}
void EnviaLasDirecciones(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128];
LogSiscom("Se Envian las direcciones");

SiscomEnviaAsociadoRespuestaCliente("DireccionesPersona",
				    lchrArrBuffer,
				    pSiscomOpePtrDato);
		
}
void EnviaSinDatosDirecciones(SiscomOperaciones *pSiscomOpePtrDato)
{
SiscomRegistroProL *lSiscomRegProLPtrPrim=0,
		   *lSiscomRegProLPtrAct=0;
char lchrArrBuffer[128];
SiscomAnexaRegistroPro(&lSiscomRegProLPtrPrim,
		       &lSiscomRegProLPtrAct,
		       lchrArrBuffer,
		       "IdMensaje,Mensajes,",
		       "1",
		       "No Hay Direcciones");
SiscomEnviaRegistrosSocket(pSiscomOpePtrDato->intSocket,
			   lchrArrBuffer,
			   lSiscomRegProLPtrPrim);
}
int EnviaDirecciones(SiscomOperaciones *pSiscomOpePtrDato)
{
  if(HayDatosDirecciones(pSiscomOpePtrDato))
   EnviaLasDirecciones(pSiscomOpePtrDato);
   else
   EnviaSinDatosDirecciones(pSiscomOpePtrDato);
}
