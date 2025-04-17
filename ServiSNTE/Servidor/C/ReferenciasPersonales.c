#include <ReferenciasPersonales.h>
#include <ComunSiscomServiSNTE.h>
#include <SqlReferenciasPersonales.h>
#include <SiscomDesarrolloMacros.h>
#include <SiscomMacrosOperaciones.h>
#include <SiscomFuncionesComunes.h>
#include <string.h>
void RegistraReferenciasPersonales(int pintSocket,
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
SiscomAgregaOperacion(GeneraIdReferenciaPersonal,&lSiscomProDat); 
SiscomAgregaOperacion(GeneraIdTelefonosReferencia,&lSiscomProDat); 
SiscomAgregaOperacion(GeneraIdDireccionesReferencia,&lSiscomProDat); 
SiscomAgregaOperacion(GeneraIdPersonasReferencia,&lSiscomProDat); 
SiscomAgregaOperacion(GeneraRFCPersonasReferencia,&lSiscomProDat); 
SiscomAgregaOperacion(SqlInsertaReferenciasPersonales,&lSiscomProDat); 
SiscomAgregaOperacion(EnviaEstadoRegistroReferenciasPersonales,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}
int EnviaEstadoRegistroReferenciasPersonales(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[256];
LogSiscom("");
if(ValidaEstadoRegistroReferenciasPersonales(pSiscomOpePtrDato))
RespondeRegistroExitoso(pSiscomOpePtrDato);

SiscomAsociadoEntradaLog("Envio",lchrArrBuffer,pSiscomOpePtrDato);
SiscomAsociadosArgumentoLog("SqlReferenciasPersonales","SentenciasSql",lchrArrBuffer,pSiscomOpePtrDato); 
return 0;
}

int ValidaEstadoRegistroReferenciasPersonales(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128];
if(pSiscomOpePtrDato->SiscomRegProLPtrPrimRes)
SiscomRegistroProtocoloLog(lchrArrBuffer,pSiscomOpePtrDato->SiscomRegProLPtrPrimRes);
return 1;
}

int GeneraIdReferenciaPersonal(SiscomOperaciones *pSiscomOpePtrDato)
{
SiscomIdARegistrosAsociadosEntrada("Envio","IdReferencia",pSiscomOpePtrDato);
return 0;
}

int GeneraIdTelefonosReferencia(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128];
SiscomRegistroProL *lSisRegProLPtrTelefonos,
		   *lSisRegProLPtrNumeros;
lSisRegProLPtrTelefonos=SiscomRegistrosAsociadosCampoEntrada("Envio","Telefonos",pSiscomOpePtrDato);
while(lSisRegProLPtrTelefonos)
{
lSisRegProLPtrNumeros=SiscomObtenRegistrosCampoProL("Telefonos",lSisRegProLPtrTelefonos);
if(SiscomCampoRegistroProLCharEsVacio("IdTelefono",lSisRegProLPtrNumeros)==1)
{
SiscomIdUnicoRegistros("IdTelefono",lSisRegProLPtrNumeros);
SiscomRegistroProtocoloLog(lchrArrBuffer,lSisRegProLPtrNumeros);
}
lSisRegProLPtrTelefonos=lSisRegProLPtrTelefonos->SiscomRegProLPtrSig;
}
return 0;
}
int GeneraIdDireccionesReferencia(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128],
	lchrArrIdDireccion[28];

SiscomRegistroProL *lSisRegProLPtrDirecciones;
lSisRegProLPtrDirecciones=SiscomRegistrosAsociadosCampoEntrada("Envio","Direcciones",pSiscomOpePtrDato);
for(;
     lSisRegProLPtrDirecciones;
     lSisRegProLPtrDirecciones=lSisRegProLPtrDirecciones->SiscomRegProLPtrSig)
{
 if(SiscomCampoRegistroProLCharEsVacio("IdDireccion",lSisRegProLPtrDirecciones)==1)
 {
	SiscomObtenNumeroUnicoChar(lchrArrIdDireccion);
	SiscomActualizaCampoRegistroActual("IdDireccion",lchrArrIdDireccion,lSisRegProLPtrDirecciones);
 }
}
return 0;
}
int GeneraIdPersonasReferencia(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128],
	lchrArrIdPersona[25];
SiscomRegistroProL *lSisRegProLPtrDirecciones,
		   *lSisRegPersonaRef;
lSisRegProLPtrDirecciones=SiscomRegistrosAsociadosCampoEntrada("Envio","Nombres",pSiscomOpePtrDato);
SiscomRegistroProtocoloLog(lchrArrBuffer,lSisRegProLPtrDirecciones);
for(; 
     lSisRegProLPtrDirecciones;
     lSisRegProLPtrDirecciones=lSisRegProLPtrDirecciones->SiscomRegProLPtrSig)
if(SiscomCampoRegistroProLCharEsVacio("IdPersona",lSisRegProLPtrDirecciones)==1)
{
   SiscomObtenNumeroUnicoChar(lchrArrIdPersona);
   SiscomActualizaCampoRegistroActual("IdPersona",lchrArrIdPersona,lSisRegProLPtrDirecciones);
}
return 0;
}

int GeneraRFCPersonasReferencia(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128];
SiscomRegistroProL *lSisRegProLPtrDirecciones;
lSisRegProLPtrDirecciones=SiscomRegistrosAsociadosCampoEntrada("Envio","Nombres",pSiscomOpePtrDato);
SiscomIdUnicoRegistros("RFC",lSisRegProLPtrDirecciones);
return 0;
}
