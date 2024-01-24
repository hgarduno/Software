#ifndef __SQLBODEGAS_H__
#define __SQLBODEGAS_H__

#include <SiscomDesarrollo4/H/SiscomOperaciones.h>

int SqlBodegasExpendios(SiscomOperaciones *pSisOpePtrDatos);
int SqlExistenciaBodega4(SiscomOperaciones *pSisOpePtrDatos);

int SqlActualizaExistenciaBodega4(SiscomOperaciones *pSisOpePtrDatos);

int SqlActualizaBodegaOrigenDestino(SiscomOperaciones *pSisOpePtrDato);



void UpdateExistenciaBodega4(SiscomOperaciones *pSisOpePtrDato,
			     SiscomRegistroProL *pSisRegProLPtrDato,
			     char *pchrPtrSql);


void UpdateExistenciaBodegaOrigen(SiscomOperaciones *pSisOpePtrDato,
			          SiscomRegistroProL *pSisRegProLPtrDato,
			          char *pchrPtrSql);

void UpdateExistenciaBodegaDestino(SiscomOperaciones *pSisOpePtrDato,
			          SiscomRegistroProL *pSisRegProLPtrDato,
			          char *pchrPtrSql);

#endif
