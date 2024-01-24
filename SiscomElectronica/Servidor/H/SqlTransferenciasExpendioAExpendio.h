#ifndef __SQLTRANSFERENCIASEXPENDIOAEXPENDIO_H__
#define __SQLTRANSFERENCIASEXPENDIOAEXPENDIO_H__

#include <SiscomDesarrollo4/H/SiscomOperaciones.h>

int SqlTransferenciasOtrosExpendios(SiscomOperaciones *pSiscomOpePtrDatos);
int SqlRegistraTransferenciaExpendioOrigen(SiscomOperaciones *pSiscomOpePtrDato);
int SqlRegistraTransferenciaExpendioDestino(SiscomOperaciones *pSiscomOpePtrDato);
int SqlExistenciaExpendioOrigenDestino(SiscomRegistroProL *pSisRegProLPtrExpendios,
				       SiscomOperaciones *pSiscomOpePtrDatos);

void InsertIntoTransfiereMaterial(SiscomOperaciones *pSiscomOpePtrDato,
			          SiscomRegistroProL *pSiscomRegProLPtrDatos,
				  char *pchrPtrSql);
void InsertIntoTransferencia(SiscomOperaciones *pSiscomOpePtrDato,
			          SiscomRegistroProL *pSiscomRegProLPtrDatos,
				  char *pchrPtrSql);
void UpdateToExistencias(SiscomOperaciones *pSiscomOpePtrDato,
			 SiscomRegistroProL *pSiscomRegProLPtrDatos,
			char *pchrPtrSql);

void InsertIntoTransferenciaDestino(SiscomOperaciones *pSiscomOpePtrDato,
			          SiscomRegistroProL *pSiscomRegProLPtrDatos,
				  char *pchrPtrSql);
void UpdateToExistenciasDestino(SiscomOperaciones *pSiscomOpePtrDato,
			 SiscomRegistroProL *pSiscomRegProLPtrDatos,
			char *pchrPtrSql);

#endif
