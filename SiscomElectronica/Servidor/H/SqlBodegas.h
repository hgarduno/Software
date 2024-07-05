#ifndef __SQLBODEGAS_H__
#define __SQLBODEGAS_H__

#include <SiscomDesarrollo4/H/SiscomOperaciones.h>

int SqlBodegasExpendios(SiscomOperaciones *pSisOpePtrDatos);
int SqlExistenciaBodega4(SiscomOperaciones *pSisOpePtrDatos);

int SqlActualizaExistenciaBodega4(SiscomOperaciones *pSisOpePtrDatos);

int SqlActualizaBodegaOrigenDestino(SiscomOperaciones *pSisOpePtrDato);
int SqlEnviandoSqlTransferenciasBodegaBodega(SiscomOperaciones *pSisOpePtrDatos);



void UpdateExistenciaBodega4(SiscomOperaciones *pSisOpePtrDato,
			     SiscomRegistroProL *pSisRegProLPtrDato,
			     char *pchrPtrSql);


void UpdateExistenciaBodegaOrigen(SiscomOperaciones *pSisOpePtrDato,
			          SiscomRegistroProL *pSisRegProLPtrDato,
			          char *pchrPtrSql);

void UpdateExistenciaBodegaDestino(SiscomOperaciones *pSisOpePtrDato,
			          SiscomRegistroProL *pSisRegProLPtrDato,
			          char *pchrPtrSql);

void InsertToTransferenciaBodegaBodega(SiscomOperaciones *pSisOpePtrDato,
				       SiscomRegistroProL *pSisRegProLPtrDato,
				       char *pchrPtrSql);

int SqlSentenciasMatriz(SiscomOperaciones *pSisOpePtrDatos);
#endif
