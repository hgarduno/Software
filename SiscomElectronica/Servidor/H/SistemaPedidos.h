#ifndef __SISTEMAPEDIDOS_H__
#define __SISTEMAPEDIDOS_H__
#include <SiscomProtocoloComunicaciones.h>
#include <SiscomDesarrollo4/H/SiscomOperaciones.h>

void OrdenesPendientes(int pintSocket,
			SiscomRegistroProL *pSiscomRegProLPtrPrim,
			SiscomRegistroProL *pSiscomRegProLPtrAct);

int EnviandoOrdenesPendientes(SiscomOperaciones *pSiscomOpePtrDato);
#endif
