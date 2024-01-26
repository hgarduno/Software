#include <Empleo.h>
#include <ComunSiscomServiSNTE.h>
#include <SqlEmpleo.h>
#include <SiscomDesarrolloMacros.h>
#include <SiscomMacrosOperaciones.h>

#include <string.h>
void RegistraEmpleo(int pintSocket,
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
SiscomAgregaOperacion(AgregaIdEmpresa,&lSiscomProDat);
SiscomAgregaOperacion(AgregaIdJefe,&lSiscomProDat);
SiscomAgregaOperacion(AgregaJefeRFC,&lSiscomProDat);
SiscomAgregaOperacion(AgregaIdEmpleo,&lSiscomProDat);
SiscomAgregaOperacion(AgregaIdDireccionEmpleo,&lSiscomProDat);
SiscomAgregaOperacion(AgregaIdCorreoEmpleo,&lSiscomProDat);
SiscomAgregaOperacion(AgregaIdTelefonoEmpleo,&lSiscomProDat);
SiscomAgregaOperacion(SqlInsertaEmpleo,&lSiscomProDat);
SiscomAgregaOperacion(EnviaEstadoRegistroEmpleo,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}

void ActualizaEmpleo(int pintSocket,
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
SiscomAgregaOperacion(SqlActualizaEmpleo,&lSiscomProDat);
SiscomAgregaOperacion(EnviaEstadoRegistroEmpleo,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}



void EmpresaRegistrada(int pintSocket,
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
SiscomAgregaOperacion(SqlEmpresaYaRegistrada,&lSiscomProDat);
SiscomAgregaOperacion(EnviaRespuestaEmpresaRegistrada,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}



int EnviaEstadoRegistroEmpleo(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[256];
SiscomAsociadoEntradaLog("Envio",lchrArrBuffer,pSiscomOpePtrDato);
SiscomAsociadosArgumentoLog("SqlEmpleo","SentenciasSql",lchrArrBuffer,pSiscomOpePtrDato);
return 0;
}

int AgregaIdEmpresa(SiscomOperaciones *pSiscomOpePtrDato)
{
if(!EstaLaEmpresaYaRegistrada(pSiscomOpePtrDato))
SiscomIdAsociadosCampoEntrada("Envio","Empresa","IdEmpresa",pSiscomOpePtrDato);
return 0;
}

int AgregaIdJefe(SiscomOperaciones *pSiscomOpePtrDato)
{
if(!EstaElJefeYaRegistrado(pSiscomOpePtrDato))
  SiscomIdAsociadosCampoEntrada("Envio","Jefe","IdPersona",pSiscomOpePtrDato);
return 0;
}
/* Miercoles 3 de febrero del 2016
 * En este caso el RFC, no viene como dato, pero como
 * es llave en la tabla, se genera con un Numero unico
 */
int AgregaJefeRFC(SiscomOperaciones *pSiscomOpePtrDato)
{
SiscomIdAsociadosCampoEntrada("Envio","Jefe","RFC",pSiscomOpePtrDato);
return 0;
}
int AgregaIdEmpleo(SiscomOperaciones *pSiscomOpePtrDato)
{
SiscomIdARegistrosAsociadosEntrada("Envio","IdEmpleo",pSiscomOpePtrDato);
return 0;
}

int AgregaIdDireccionEmpleo(SiscomOperaciones *pSiscomOpePtrDato)
{
SiscomRegistroProL *lSisRegProLPtrEmpresa=SiscomRegistrosAsociadosCampoEntrada("Envio","Empresa",pSiscomOpePtrDato);
SiscomRegistroProL *lSisRegProLPtrDireccion=SiscomObtenRegistrosCampoProL("Direccion",lSisRegProLPtrEmpresa);

if(!EstaLaEmpresaYaRegistrada(pSiscomOpePtrDato))
SiscomIdUnicoRegistros("IdDireccion",lSisRegProLPtrDireccion);  
return 0;
}

int AgregaIdTelefonoEmpleo(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128];
SiscomRegistroProL *lSisRegProLPtrEmpresa;
SiscomRegistroProL *lSisRegProLPtrTelefonos,
   		   *lSisRegProLPtrNumerosTelefono;

if(!EstaLaEmpresaYaRegistrada(pSiscomOpePtrDato))
{
lSisRegProLPtrEmpresa=SiscomRegistrosAsociadosCampoEntrada("Envio", "Empresa",pSiscomOpePtrDato);
lSisRegProLPtrTelefonos=SiscomObtenRegistrosCampoProL("Telefonos",lSisRegProLPtrEmpresa);
lSisRegProLPtrNumerosTelefono=SiscomObtenRegistrosCampoProL("Telefonos",lSisRegProLPtrTelefonos);
SiscomRegistroProtocoloLog(lchrArrBuffer,lSisRegProLPtrNumerosTelefono);
SiscomIdUnicoRegistros("IdTelefono",lSisRegProLPtrNumerosTelefono);  
}
return 0;
}

int AgregaIdCorreoEmpleo(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[256];
SiscomRegistroProL *lSisRegProLPtrEmpresa,
		   *lSisRegProLPtrCorreos;


if(!EstaLaEmpresaYaRegistrada(pSiscomOpePtrDato))
{
lSisRegProLPtrEmpresa=SiscomRegistrosAsociadosCampoEntrada("Envio","Empresa",pSiscomOpePtrDato);
lSisRegProLPtrCorreos=SiscomObtenRegistrosCampoProL("Correos",lSisRegProLPtrEmpresa);
SiscomRegistroProtocoloLog(lchrArrBuffer,lSisRegProLPtrEmpresa);
SiscomRegistroProtocoloLog(lchrArrBuffer,lSisRegProLPtrCorreos);
SiscomIdUnicoRegistros("IdCorreo",lSisRegProLPtrCorreos);  
}
return 0;
}


int EnviaRespuestaEmpresaRegistrada(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[1024];
SiscomRegistroProL *lSisRegProLPtrEmpresa;
SiscomAsociadoRespuestaLog("SqlEmpresaRegistrada",lchrArrBuffer,pSiscomOpePtrDato);
if((lSisRegProLPtrEmpresa=SiscomRegistrosAsociadoRespuestaOperacion(
					"SqlEmpresaRegistrada",
					pSiscomOpePtrDato)))
{
 LogSiscom("La empresa esta registrada");
 EnviaEmpresaRegistrada(lSisRegProLPtrEmpresa,pSiscomOpePtrDato);
}
else
{
  LogSiscom("La empresa no esta registrada");
  EnviaEmpresaNoRegistrada(pSiscomOpePtrDato);
}
}

void EnviaEmpresaRegistrada(SiscomRegistroProL *pSisRegProLPtrEmpresa,
			    SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[1024];
SiscomAgregaCampoRegistros("EdoRegistro","Si",pSisRegProLPtrEmpresa);
SiscomActualizaCampoRegistro("razonsocial","",pSisRegProLPtrEmpresa);
SiscomEnviaRegistrosSocket(pSiscomOpePtrDato->intSocket, lchrArrBuffer,pSisRegProLPtrEmpresa);
}
void EnviaEmpresaNoRegistrada(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[256];
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

int EstaLaEmpresaYaRegistrada(SiscomOperaciones *pSiscomOpePtrDato)
{
SiscomRegistroProL *lSisRegProLPtrEmpresa;
int lintRegreso;
lSisRegProLPtrEmpresa=SiscomRegistrosAsociadosCampoEntrada("Envio","Empresa",pSiscomOpePtrDato);
return !SiscomComparaCadenaCampoRegistroProL("Si","EdoRegistro",lSisRegProLPtrEmpresa);
}


int EstaElJefeYaRegistrado(SiscomOperaciones *pSiscomOpePtrDato)
{
SiscomRegistroProL *lSisRegProLPtrEmpresa;
int lintRegreso;
lSisRegProLPtrEmpresa=SiscomRegistrosAsociadosCampoEntrada("Envio","Jefe",pSiscomOpePtrDato);
return !SiscomComparaCadenaCampoRegistroProL("Si","EdoRegistro",lSisRegProLPtrEmpresa);
}
