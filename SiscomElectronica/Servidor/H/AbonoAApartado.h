#ifndef __ABONOAAPARTADO_H__
#define __ABONOAAPARTADO_H__
#include <SiscomDesarrollo4/H/SiscomOperaciones.h>

void AbonoAApartado(int pintSocket,
		SiscomRegistroProL *pSiscomRegProLPtrPrim,
		SiscomRegistroProL *pSiscomRegProLPtrAct);
int EnviandoAbonoAApartado(SiscomOperaciones *);

int ArgumentoAbonoAApartado(SiscomOperaciones *pSiscomOpePtrDato);
int AgregaFechaAbonoAApartado(SiscomOperaciones *pSiscomOpePtrDato);
#endif


