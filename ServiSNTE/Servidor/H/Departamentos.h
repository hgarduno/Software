#ifndef __DEPARTAMENTOS_H__
#define __DEPARTAMENTOS_H__
#include <SiscomProtocoloComunicaciones.h>
#include <SiscomOperaciones.h>
#include <SiscomArchivosIni.h>

void RegistraDepartamento(int pintSocket,
	   void *pvidPtrAncla,
	   const SiscomRegistroProL *pSiscomRegProLPtrPrim,
	   const SiscomRegistroProL *pSiscomRegProLPtrAct);

int EnviaIdDepartamentoRegistrado(SiscomOperaciones *pSiscomOpePtrDato);
int GeneraIdDepartamento(SiscomOperaciones *pSiscomOpePtrDato);
#endif
