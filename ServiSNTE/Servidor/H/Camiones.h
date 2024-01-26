#ifndef __CAMIONES_H__
#define __CAMIONES_H__
#include <SiscomProtocoloComunicaciones.h>
#include <SiscomOperaciones.h>
#include <SiscomArchivosIni.h>

void RegistraCamion(int pintSocket,
	   void *pvidPtrAncla,
	   const SiscomRegistroProL *pSiscomRegProLPtrPrim,
	   const SiscomRegistroProL *pSiscomRegProLPtrAct);

int EnviaIdCamionRegistrado(SiscomOperaciones *pSiscomOpePtrDato);
int GeneraIdCamion(SiscomOperaciones *pSiscomOpePtrDato);
#endif
