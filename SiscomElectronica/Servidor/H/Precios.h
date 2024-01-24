#ifndef __PRECIOS_H__
#define __PRECIOS_H__
#include <SiscomDesarrollo4/H/SiscomOperaciones.h>
void Precios2Productos(int pintSocket,
			     SiscomRegistroProL *pSiscomRegProLPtrPrim,
			     SiscomRegistroProL *pSiscomRegProLPtrAct);
void PreciosExpendios(int pintSocket,
			     SiscomRegistroProL *pSiscomRegProLPtrPrim,
			     SiscomRegistroProL *pSiscomRegProLPtrAct);

void ActualizaPrecioExpendios(int pintSocket,
			     SiscomRegistroProL *pSiscomRegProLPtrPrim,
			     SiscomRegistroProL *pSiscomRegProLPtrAct);


int EnviandoPreciosExpendios(SiscomOperaciones *pSiscomOpePtrDato);
int EnviandoPrecios2Expendios(SiscomOperaciones *pSiscomOpePtrDato);
int ArgumentoExpendioPrecios(SiscomOperaciones *pSiscomOpePtrDato);
int ArgumentoPreciosOrigen(SiscomOperaciones *pSiscomOpePtrDato);
int ArgumentoPreciosDestino(SiscomOperaciones *pSiscomOpePtrDato);
int ArgumentoActualizaPrecioExpendios(SiscomOperaciones *pSiscomOpePtrDato);
int ActualizandoPreciosExpendio(SiscomOperaciones *pSisOpePtrDato);

int AgregaCampoCondicionExpendios(SiscomOperaciones *pSisOpePtrDato);
int ActualizandoPrecioExpendios(SiscomOperaciones *pSisOpePtrDato);
int CopiaExpendiosPrecios(SiscomOperaciones *pSisOpePtrDato);
void FormaRespuestaEnvia(SiscomOperaciones *pSiscomOpePtrDato);

#endif
