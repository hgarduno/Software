#ifndef __SINCRONIZAEXPENDIOS_H__
#define __SINCRONIZAEXPENDIOS_H__

#include <SiscomDesarrollo4/H/SiscomOperaciones.h>

void SincronizaProductosExpendio(int pintSocket,
			     SiscomRegistroProL *pSiscomRegProLPtrPrim,
			     SiscomRegistroProL *pSiscomRegProLPtrAct);


int SincronizandoProductosExpendio(SiscomOperaciones *pSisOpePtrDato);
int ArgumentoProductosMatriz(SiscomOperaciones *pSiscomOpePtrDato);
int ArgumentoProductosExpendio(SiscomOperaciones *pSiscomOpePtrDato);
int ProductosASincronizarExpendio(SiscomOperaciones *pSisOpePtrDato);
int ArgumentoProductosASincronizar(SiscomOperaciones *pSiscomOpePtrDato);
int ArgumentoSqlProductosASincronizar(SiscomOperaciones *pSiscomOpePtrDato);
int ArgumentoBodegasExpendio(SiscomOperaciones *pSiscomOpePtrDato);


void ObtenProductosASincronizar(SiscomOperaciones *pSisOpePtrDato,
				SiscomRegistroProL **pSisRegProLPtrProASi);
#endif
