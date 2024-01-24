#ifndef __PROVEEDORES4_H__
#define __PROVEEDORES4_H__

#include <SiscomDesarrollo4/H/SiscomOperaciones.h>

void Proveedores4(int pintSocket,
			     SiscomRegistroProL *pSiscomRegProLPtrPrim,
			     SiscomRegistroProL *pSiscomRegProLPtrAct);

int EnviandoProveedores4(SiscomOperaciones *pSiscomOpePtrDato);

#endif
