#ifndef __DIRECCIONES_H__
#define __DIRECCIONES_H__
#include <SiscomProtocoloComunicaciones.h>
#include <SiscomOperaciones.h>
#include <SiscomArchivosIni.h>

void RegistraDireccion(int pintSocket,
	   void *pvidPtrAncla,
	   const SiscomRegistroProL *pSiscomRegProLPtrPrim,
	   const SiscomRegistroProL *pSiscomRegProLPtrAct);
void DireccionesPersona(int pintSocket,
	   void *pvidPtrAncla,
	   const SiscomRegistroProL *pSiscomRegProLPtrPrim,
	   const SiscomRegistroProL *pSiscomRegProLPtrAct);

int EnviaIdDireccionRegistrada(SiscomOperaciones *pSiscomOpePtrDato);
int EnviaDirecciones(SiscomOperaciones *pSiscomOpePtrDato);
int GeneraIdDireccion(SiscomOperaciones *pSiscomOpePtrDato);
int HayDatosDirecciones(SiscomOperaciones *pSiscomOpePtrDato);


int EnviaEstadoRegistroDatosCasa(SiscomOperaciones *pSiscomOpePtrDato);
#endif
