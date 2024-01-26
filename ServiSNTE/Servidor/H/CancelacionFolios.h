#ifndef __CANCELACIONFOLIOS_H__
#define __CANCELACIONFOLIOS_H__
#include <SiscomProtocoloComunicaciones.h>
#include <SiscomOperaciones.h>
#include <SiscomArchivosIni.h>

void RegistraCancelacionFolio(int pintSocket,
	   void *pvidPtrAncla,
	   const SiscomRegistroProL *pSiscomRegProLPtrPrim,
	   const SiscomRegistroProL *pSiscomRegProLPtrAct);

int EnviaIdCancelacionFolioRegistrado(SiscomOperaciones *pSiscomOpePtrDato);
int GeneraIdCancelacionFolio(SiscomOperaciones *pSiscomOpePtrDato);
#endif
