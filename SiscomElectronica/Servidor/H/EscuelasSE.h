#ifndef __ESCUELASSE_H__
#define __ESCUELASSE_H_
#include <SiscomDesarrollo4/H/SiscomOperaciones.h>
int EnviandoEscuelasSE(SiscomOperaciones *pSiscomOpePtrDato);
void EscuelasSE(int pintSocket,
			SiscomRegistroProL *pSiscomRegProLPtrPrim,
			SiscomRegistroProL *pSiscomRegProLPtrAct);

void EntregaEscuela(int pintSocket,
		SiscomRegistroProL *pSiscomRegProLPtrPrim,
		SiscomRegistroProL *pSiscomRegProLPtrAct);
#endif
