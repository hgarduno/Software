#ifndef __PRACTICAS_H__
#define __PRACTICAS_H__
#include <SiscomDesarrollo4/H/SiscomOperaciones.h>
void RegistraPractica(int pintSocket,
		SiscomRegistroProL *pSiscomRegProLPtrPrim,
		SiscomRegistroProL *pSiscomRegProLPtrAct);

void PracticaRegistrada(int pintSocket,
		SiscomRegistroProL *pSiscomRegProLPtrPrim,
		SiscomRegistroProL *pSiscomRegProLPtrAct);
int EnviandoRegistroPractica(SiscomOperaciones *pSiscomOpePtrDato);
int EnviaPracticaRegistrada(SiscomOperaciones *pSiscomOpePtrDato);
int AgregaIdProducto(SiscomOperaciones *pSiscomOpePtrDato);
int AgregaArgumentoPracticas(SiscomOperaciones *pSiscomOpePtrDato);
#endif
