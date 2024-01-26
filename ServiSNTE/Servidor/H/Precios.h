#ifndef __PRECIOS_H__
#define __PRECIOS_H__
#include <SiscomProtocoloComunicaciones.h>
#include <SiscomOperaciones.h>
#include <SiscomArchivosIni.h>

void RegistraPrecio(int pintSocket,
	   void *pvidPtrAncla,
	   const SiscomRegistroProL *pSiscomRegProLPtrPrim,
	   const SiscomRegistroProL *pSiscomRegProLPtrAct);

int EnviaIdPrecioRegistrada(SiscomOperaciones *pSiscomOpePtrDato);
int FechaPrecioGeneral(SiscomOperaciones *pSiscomOpePtrDato);
int FechaPrecioForaneo(SiscomOperaciones *pSiscomOpePtrDato);
int FechaPrecioBruto(SiscomOperaciones *pSiscomOpePtrDato);
int GeneraIdCostoGeneral(SiscomOperaciones *pSiscomOpePtrDato);
int GeneraIdCostoForaneo(SiscomOperaciones *pSiscomOpePtrDato);
int GeneraIdCostoBruto(SiscomOperaciones *pSiscomOpePtrDato);
int OrdenPrecio(SiscomOperaciones *pSiscomOpePtrDato);
#endif
