#ifndef __SEGURIDAD3_H__
#define __SEGURIDAD3_H__

#include <SiscomDesarrollo4/H/SiscomOperaciones.h>


void PerfilesAplicacion(int pintSocket,
		SiscomRegistroProL *pSiscomRegProLPtrPrim,
		SiscomRegistroProL *pSiscomRegProLPtrAct);

int RegresaPerfilesAplicacion(SiscomOperaciones *pSiscomOpePtrDato);

#endif
