#ifndef __MEDIOSCOMUNICACION_H__
#define __MEDIOSCOMUNICACION_H__
#include <SiscomProtocoloComunicaciones.h>
#include <SiscomOperaciones.h>

void RegistraTelefonosCliente(int pintSocket,
	   void *pvidPtrAncla,
	   const SiscomRegistroProL *pSiscomRegProLPtrPrim,
	   const SiscomRegistroProL *pSiscomRegProLPtrAct);

int EnviaEstadoRegistroTelefonos(SiscomOperaciones *pSiscomOpePtrDato);
int AsignaIdTelefonosCliente(SiscomOperaciones *pSiscomOpePtrDato);
int AsignaIdCorreo(SiscomOperaciones *pSiscomOpePtrDato);
int ValidaRegistroTelefonos(SiscomOperaciones *pSiscomOpePtrDato);
#endif
