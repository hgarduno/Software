#ifndef __SQLCONTABILIDAD_H__
#define __SQLCONTABILIDAD_H__
#include <SiscomDesarrollo4/H/SiscomOperaciones.h>


int SqlOrdenesTarjetaTransferencia(SiscomOperaciones *pSiscomOpePtrDatos);
int SqlInsertaOrdenesCantabilidad(SiscomOperaciones *pSiscomOpePtrDatos);

void SqlConsultaOrdenesTarjetaTransferencia(SiscomOperaciones *pSiscomOpePtrDatos,
				   char *pchrPtrSql);


void SqlOrdenesContabilidadExpendio(SiscomRegistroProL *pSisRegProLPtrDatos,
				   SiscomRegistroProL *pSisRegProLPtrSql,
				   SiscomOperaciones *pSisOpePtrDatos);
void SqlInserIntoOrdenesContabilidad(SiscomOperaciones *pSisOpePtrDatos,
				     SiscomRegistroProL *pSisRegProLPtrOrdenes,
				     char *pchrPtrSql);



void InsertandoFacturacionPeriodica(SiscomOperaciones *pSisOpePtrDatos,
				    SiscomRegistroProL *pSisRegProLPtrSql);
#endif
