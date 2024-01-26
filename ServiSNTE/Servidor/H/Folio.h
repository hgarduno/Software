#ifndef __FOLIO_H__
#define __FOLIO_H__
#include <SiscomProtocoloComunicaciones.h>
#include <SiscomOperaciones.h>
#include <SiscomArchivosIni.h>

void RegistraFolio(int pintSocket,
	   void *pvidPtrAncla,
	   const SiscomRegistroProL *pSiscomRegProLPtrPrim,
	   const SiscomRegistroProL *pSiscomRegProLPtrAct);

void FolioActual(int pintSocket,
	   void *pvidPtrAncla,
	   const SiscomRegistroProL *pSiscomRegProLPtrPrim,
	   const SiscomRegistroProL *pSiscomRegProLPtrAct);

int GeneraIdFolio(SiscomOperaciones *pSiscomOpePtrDato);
int EnviaIdFolioRegistrado(SiscomOperaciones *pSiscomOpePtrDato);
int EnviaFolioActual(SiscomOperaciones *pSiscomOpePtrDato);
#endif
