#ifndef __CLAVESPROVEEDOR_H__
#define __CLAVESPROVEEDOR_H__
#include <SiscomDesarrollo4/H/SiscomOperaciones.h>

void RegistraClavesProveedor(int pintSocket,
		SiscomRegistroProL *pSiscomRegProLPtrPrim,
		SiscomRegistroProL *pSiscomRegProLPtrAct);

void ActualizaClaveProveedor(int pintSocket,
		SiscomRegistroProL *pSiscomRegProLPtrPrim,
		SiscomRegistroProL *pSiscomRegProLPtrAct);
void ValidaClaveRegistrada(int pintSocket,
		SiscomRegistroProL *pSiscomRegProLPtrPrim,
		SiscomRegistroProL *pSiscomRegProLPtrAct);
int EnviandoClavesProveedor(SiscomOperaciones *pSiscomOpePtrDato);
int ValidandoClaveRegistrada(SiscomOperaciones *pSiscomOpePtrDato);
int ArgumentoClavesProveedor(SiscomOperaciones *pSiscomOpePtrDato);
#endif
