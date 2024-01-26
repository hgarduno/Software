#ifndef __APARTADOS_H__
#define __APARTADOS_H__
#include <SiscomProtocoloComunicaciones.h>
#include <SiscomOperaciones.h>
#include <SiscomArchivosIni.h>

void RegistraPrecio(int pintSocket,
	   void *pvidPtrAncla,
	   const SiscomRegistroProL *pSiscomRegProLPtrPrim,
	   const SiscomRegistroProL *pSiscomRegProLPtrAct);

void AbonoACredito(int pintSocket,
	   void *pvidPtrAncla,
	   const SiscomRegistroProL *pSiscomRegProLPtrPrim,
	   const SiscomRegistroProL *pSiscomRegProLPtrAct);
int EnviaCreditosCliente(SiscomOperaciones *pSiscomOpePtrDato);
int EstadoAbonoACredito(SiscomOperaciones *pSiscomOpePtrDato);
int AgregaCampoFecha(SiscomOperaciones *pSiscomOpePtrDato);
#endif
