#ifndef __FIJAFECHACOMPRAS_H__
#define __FIJAFECHACOMPRAS_H__
#include <SiscomProtocoloComunicaciones.h>
#include <SiscomOperaciones.h>
#include <SiscomArchivosIni.h>

void RegistraFechaCompra(int pintSocket,
	   void *pvidPtrAncla,
	   const SiscomRegistroProL *pSiscomRegProLPtrPrim,
	   const SiscomRegistroProL *pSiscomRegProLPtrAct);

int EnviaIdFechaCompraRegistrado(SiscomOperaciones *pSiscomOpePtrDato);
int EnviaFechaCompraProveedor(SiscomOperaciones *pSiscomOpePtrDat);
int ObtenFechaHoy(SiscomOperaciones *pSiscomOpePtrDato);
#endif
