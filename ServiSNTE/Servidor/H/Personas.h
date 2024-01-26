#ifndef __PERSONAS_H__
#define __PERSONAS_H__
#include <SiscomProtocoloComunicaciones.h>
#include <SiscomOperaciones.h>
#include <SiscomArchivosIni.h>

void RegistraCliente(int pintSocket,
	   void *pvidPtrAncla,
	   const SiscomRegistroProL *pSiscomRegProLPtrPrim,
	   const SiscomRegistroProL *pSiscomRegProLPtrAct);

void PersonaRegistrada(int pintSocket,
	   void *pvidPtrAncla,
	   const SiscomRegistroProL *pSiscomRegProLPtrPrim,
	   const SiscomRegistroProL *pSiscomRegProLPtrAct);

void ActualizaRFC(int pintSocket,
	   void *pvidPtrAncla,
	   const SiscomRegistroProL *pSiscomRegProLPtrPrim,
	   const SiscomRegistroProL *pSiscomRegProLPtrAct);

int ValidaRegistroPersona(SiscomOperaciones *pSiscomOpePtrDato);
int EnviaIdPersonaRegistrada(SiscomOperaciones *pSiscomOpePtrDato);
int GeneraIdPersona(SiscomOperaciones *pSiscomOpePtrDato);
int ValidaRFC(SiscomOperaciones *pSiscomOpePtrDato);
int EnviaErrorAlRegistrarPersona(SiscomOperaciones *pSiscomOpePtrDato);
int ValidaActualizacionRFC(SiscomOperaciones *pSiscomOpePtrDato);

int ErrorRFCVacioONulo(SiscomOperaciones *pSiscomOpePtrDato);
int ErrorPersonaYaRegistrada(SiscomOperaciones *pSiscomOpePtrDato);
int EnviaRespuestaPersonaRegistrada(SiscomOperaciones *pSiscomOpePtrDato);
int EnviaRFCRegistradoBaseDatos(SiscomOperaciones *pSiscomOpePtrDat);
void EnviaPersonaRegistrada(SiscomRegistroProL *pSisRegProLPtrPersona,
			    SiscomOperaciones *pSiscomOpePtrDato);
void EnviaPersonaNoRegistrada(SiscomOperaciones *pSiscomOpePtrDato);
#endif
