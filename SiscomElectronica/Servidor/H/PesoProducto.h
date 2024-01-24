#ifndef __PESOPRODUCTO_H__
#define __PESOPRODUCTO_H__

#include <SiscomDesarrollo4/H/SiscomOperaciones.h>

void PesoProducto(int pintSocket,
			     SiscomRegistroProL *pSiscomRegProLPtrPrim,
			     SiscomRegistroProL *pSiscomRegProLPtrAct);
void RegistraPesoProducto(int pintSocket,
			     SiscomRegistroProL *pSiscomRegProLPtrPrim,
			     SiscomRegistroProL *pSiscomRegProLPtrAct);

void ActualizaPesoProducto(int pintSocket,
			     SiscomRegistroProL *pSiscomRegProLPtrPrim,
			     SiscomRegistroProL *pSiscomRegProLPtrAct);

int EnviandoPesoProducto(SiscomOperaciones *pSiscomOpePtrDato);
int EnviandoRegistroPesoProducto(SiscomOperaciones *pSiscomOpePtrDato);

int ArgumentoPesoProducto(SiscomOperaciones *pSiscomOpePtrDato);
#endif
