#include <Personas.h>
#include <SqlPersonas.h>
#include <ComunSiscomServiSNTE.h>
#include <SiscomDesarrolloMacros.h>
#include <SiscomMacrosOperaciones.h>
#include <string.h>
void RegistraCliente(int pintSocket,
	   void *pvidPtrAncla,
	   const SiscomRegistroProL *pSiscomRegProLPtrPrim,
	   const SiscomRegistroProL *pSiscomRegProLPtrAct)
{
SiscomProcesos *lSiscomProDat=0;
SiscomOperaciones lSiscomOpDat;
SiscomOperacionErrores lSiscomOpeErrores={0, ErrorRFCVacioONulo, ErrorPersonaYaRegistrada,0 };
memset(&lSiscomOpDat,0,sizeof(SiscomOperaciones));
SiscomIniciaDatosOperacion(pintSocket,
			   pvidPtrAncla,
			   (SiscomRegistroProL *)pSiscomRegProLPtrPrim,
			   (SiscomRegistroProL *)pSiscomRegProLPtrAct,
			   &lSiscomOpDat);
SiscomAgregaOperacion(ComunicacionAccesoDatos,&lSiscomProDat);
/*SiscomAgregaOperacion(ValidaRFC,&lSiscomProDat); */
SiscomAgregaOperacion(GeneraIdPersona,&lSiscomProDat);
SiscomAgregaOperacion(SqlRegistraCliente,&lSiscomProDat);
SiscomAgregaOperacion(ValidaRegistroPersona,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,lSiscomOpeErrores,lSiscomProDat);
}
void PersonaRegistrada(int pintSocket,
	   void *pvidPtrAncla,
	   const SiscomRegistroProL *pSiscomRegProLPtrPrim,
	   const SiscomRegistroProL *pSiscomRegProLPtrAct)
{
SiscomProcesos *lSiscomProDat=0;
SiscomOperaciones lSiscomOpDat;
SiscomOperacionErrores lSiscomOpeErrores={0, ErrorRFCVacioONulo, 0 };
memset(&lSiscomOpDat,0,sizeof(SiscomOperaciones));
SiscomIniciaDatosOperacion(pintSocket,
			   pvidPtrAncla,
			   (SiscomRegistroProL *)pSiscomRegProLPtrPrim,
			   (SiscomRegistroProL *)pSiscomRegProLPtrAct,
			   &lSiscomOpDat);
SiscomAgregaOperacion(ComunicacionAccesoDatos,&lSiscomProDat);
SiscomAgregaOperacion(SqlPersonaYaRegistrada,&lSiscomProDat);
SiscomAgregaOperacion(EnviaRespuestaPersonaRegistrada,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,lSiscomOpeErrores,lSiscomProDat);
}


void ActualizaRFC(int pintSocket,
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
SiscomAgregaOperacion(SqlActualizaRFC,&lSiscomProDat);
SiscomAgregaOperacion(ValidaActualizacionRFC,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);

}

void RFCRegistradoBaseDatos(int pintSocket,
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
SiscomAgregaOperacion(SqlRFCRegistradoBaseDatos,&lSiscomProDat);
SiscomAgregaOperacion(EnviaRFCRegistradoBaseDatos,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}
int GeneraIdPersona(SiscomOperaciones *pSiscomOpePtrDato)
{
  SiscomIdARegistrosAsociadosEntrada("Envio","IdPersona",pSiscomOpePtrDato);
return 0;
}
int ValidaRegistroPersona(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128];
   if(!SiscomComparaCadenaCampoRegistroProL("Error",
   					   "EstadoOperacion",
					   pSiscomOpePtrDato->SiscomRegProLPtrPrimRes))
   {
   return 2;
   }
   else
   {
      LogSiscom("Se registro a la persona");
      EnviaIdPersonaRegistrada(pSiscomOpePtrDato);
   }
return 0;
}
int EnviaIdPersonaRegistrada(SiscomOperaciones *pSiscomOpePtrDato)
{
SiscomRegistroProL *lSiscomRegProLPtrPrim=0,
		   *lSiscomRegProLPtrAct=0;
char lchrArrBuffer[128];
const char *lchrPtrIdPersona;
lchrPtrIdPersona=SiscomCampoAsociadoEntradaOperacion("Envio",
						     "IdPersona",
						     pSiscomOpePtrDato);
SiscomAnexaRegistroPro(&lSiscomRegProLPtrPrim,
		       &lSiscomRegProLPtrAct,
		       lchrArrBuffer,
		       "IdPersona,Mensajes,",
		       lchrPtrIdPersona,
		       "Registro Exitoso");
SiscomEnviaRegistrosSocket(pSiscomOpePtrDato->intSocket,
			   lchrArrBuffer,
			   lSiscomRegProLPtrPrim);
SiscomRegistroProtocoloLog(lchrArrBuffer,lSiscomRegProLPtrPrim);
SiscomAsociadosArgumentoLog("SqlInsertaPersona",
			    "SentenciasSql",
			    lchrArrBuffer,
			    pSiscomOpePtrDato);
SiscomRegistroProtocoloLog(lchrArrBuffer,pSiscomOpePtrDato->SiscomRegProLPtrPrimRes);
return 0;
}

int EnviaErrorAlRegistrarPersona(SiscomOperaciones *pSiscomOpePtrDato)
{

SiscomRegistroProL *lSiscomRegProLPtrPrim=0,
                   *lSiscomRegProLPtrAct=0;
char lchrArrBuffer[128];

SiscomAnexaRegistroPro(&lSiscomRegProLPtrPrim,
                       &lSiscomRegProLPtrAct,
                       lchrArrBuffer,
                       "MensajeSistema,",
                       "Datos Personales ya Registrados");

SiscomRegistroProtocoloLog(lchrArrBuffer,lSiscomRegProLPtrPrim);
SiscomEnviaRegistrosSocket(pSiscomOpePtrDato->intSocket,
                           lchrArrBuffer,
                           lSiscomRegProLPtrPrim);

return 0;
}


int ValidaRFC(SiscomOperaciones *pSiscomOpePtrDato)
{
const char *lchrPtrRFC=SiscomCampoAsociadoEntradaOperacion("Envio","RFC",pSiscomOpePtrDato);
LogSiscom("%s",lchrPtrRFC);
if(lchrPtrRFC)
{
    if(*lchrPtrRFC)
    {
      LogSiscom("Se envio el RFC");
       return 0; 
    }
    else
    {
	LogSiscom("Se Envio un RFC Nulo");
	return 1;
	
    }
}
else
{
LogSiscom("Se Envio un RFC Nulo");
return 1;
}

return 0;
}

int ErrorRFCVacioONulo(SiscomOperaciones *pSiscomOpePtrDato)
{
SiscomRegistroProL *lSiscomRegProLPtrPrim=0,
                   *lSiscomRegProLPtrAct=0;
char lchrArrBuffer[128];

SiscomAnexaRegistroPro(&lSiscomRegProLPtrPrim,
                       &lSiscomRegProLPtrAct,
                       lchrArrBuffer,
                       "MensajeSistema,",
                       "Se Debe Capturar el RFC del Maestro");

SiscomRegistroProtocoloLog(lchrArrBuffer,lSiscomRegProLPtrPrim);
SiscomEnviaRegistrosSocket(pSiscomOpePtrDato->intSocket,
                           lchrArrBuffer,
                           lSiscomRegProLPtrPrim);

LogSiscom("Se Identifico un RFC Invalido");
}

int ErrorPersonaYaRegistrada(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[256];
LogSiscom("La Persona ya esta registrada");
pSiscomOpePtrDato->SiscomRegProLPtrPrimRes=0;
pSiscomOpePtrDato->SiscomRegProLPtrActRes=0;
SqlPersonaYaRegistrada(pSiscomOpePtrDato);
SiscomEnviaRegistrosRespuesta(pSiscomOpePtrDato,lchrArrBuffer);
}

int EnviaRespuestaPersonaRegistrada(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128];
SiscomRegistroProL *lSisRegProLPtrPersona;
LogSiscom("Viendo si la persona ya esta registrada");
SiscomAsociadoRespuestaLog("SqlPersonaRegistrada",lchrArrBuffer,pSiscomOpePtrDato);
if((lSisRegProLPtrPersona=SiscomRegistrosAsociadoRespuestaOperacion("SqlPersonaRegistrada",
								pSiscomOpePtrDato)))
{
  LogSiscom("La Persona ya esta registrada:%s",
  	    SiscomObtenCampoRegistroProLChar("idpersona",lSisRegProLPtrPersona));
  EnviaPersonaRegistrada(lSisRegProLPtrPersona,pSiscomOpePtrDato);
}
else
{
LogSiscom("La persona no esta registrada");
  EnviaPersonaNoRegistrada(pSiscomOpePtrDato);
}
}
void AgregaTelefonosRespuesta(SiscomRegistroProL *pSisRegProLPtrPersona,
			      SiscomOperaciones *pSiscomOpePtrDato)
{


}
void EnviaPersonaRegistrada(SiscomRegistroProL *pSisRegProLPtrPersona,
			    SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128];
SiscomAgregaCampoRegistros("EdoRegistro","Si",pSisRegProLPtrPersona);
SiscomAgregaCampoRegistros("Telefonos",0,pSisRegProLPtrPersona);
SiscomActualizaCampoRegistro("nombre","",pSisRegProLPtrPersona);
SiscomActualizaCampoRegistro("apaterno","",pSisRegProLPtrPersona);
SiscomActualizaCampoRegistro("amaterno","",pSisRegProLPtrPersona);
SiscomRegistroProtocoloLog(lchrArrBuffer,pSisRegProLPtrPersona);
SiscomRegistrosAlCampo("Telefonos",
		       SiscomRegistrosAsociadoRespuestaOperacion("SqlTelefonos",pSiscomOpePtrDato),
		       0,
		       pSisRegProLPtrPersona);
SiscomEnviaRegistrosSocket(pSiscomOpePtrDato->intSocket,lchrArrBuffer,pSisRegProLPtrPersona);
}
void EnviaPersonaNoRegistrada(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128];
SiscomRegistroProL *lSisRegProLPtrPrim=0,
		   *lSisRegProLPtrAct=0;

SiscomAnexaRegistroPro(&lSisRegProLPtrPrim,
		       &lSisRegProLPtrAct,
		       lchrArrBuffer,
		       "EdoRegistro,Mensaje,",
		       "No",
		       "Se Puede registrar");
SiscomEnviaRegistrosSocket(pSiscomOpePtrDato->intSocket,lchrArrBuffer,lSisRegProLPtrPrim);
}

int ValidaActualizacionRFC(SiscomOperaciones *pSiscomOpePtrDato)
{
LogSiscom("Validando el RFC");
}
int EnviaRFCRegistradoBaseDatos(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[1024];
if(SiscomObtenRegistrosCampoRespuesta("RFCRegistradoBaseDatos",pSiscomOpePtrDat))
SiscomEnviaRegistrosRespuesta(pSiscomOpePtrDat,lchrArrBuffer);
else
RespondeConsultaSinRegistros(pSiscomOpePtrDat);
}
