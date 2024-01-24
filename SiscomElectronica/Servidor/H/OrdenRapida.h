#ifndef __ORDENRAPIDA_H__
#define __ORDENRAPIDA_H__
#include <SiscomDesarrollo4/H/SiscomOperaciones.h>

void OrdenEscuelaPrincipal(int pintSocket,
		    SiscomRegistroProL *pSiscomRegProLPtrPrim,
		    SiscomRegistroProL *pSiscomRegProLPtrAct);

void OrdenOtro(int pintSocket,
		    SiscomRegistroProL *pSiscomRegProLPtrPrim,
		    SiscomRegistroProL *pSiscomRegProLPtrAct);
int EnviaOrdenEscuelaPrincipal(SiscomOperaciones *pSiscomOpePtrDato);


#endif
