#ifndef __SISCOMACTUALIZACIONSISTEMA_H__
#define __SISCOMACTUALIZACIONSISTEMA_H__
#include <SiscomProtocoloComunicaciones.h>
#include <SiscomOperaciones.h>
#include <SiscomArchivosIni.h>

void RegistraActualizacionMaquina(int pintSocket,
	   void *pvidPtrAncla,
	   const SiscomRegistroProL *pSiscomRegProLPtrPrim,
	   const SiscomRegistroProL *pSiscomRegProLPtrAct);

int ActualizoSistema(SiscomOperaciones *pSiscomOpePtrDato);
int DatosActualizacionSistema(SiscomOperaciones *);
#endif
