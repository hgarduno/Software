#ifndef __CONTENEDOR_H__
#define __CONTENEDOR_H__
#include <SiscomDesarrollo4/H/SiscomOperaciones.h>

void AgregaFacturaContenedor(int pintSocket,
			     SiscomRegistroProL *pSiscomRegProLPtrPrim,
			     SiscomRegistroProL *pSiscomRegProLPtrAct);

int AgregandoFacturaContenedor(SiscomOperaciones *pSisOpePtrDato);
#endif
