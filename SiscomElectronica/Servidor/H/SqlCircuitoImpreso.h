#ifndef __SQLCIRCUITOIMPRESO_H__
#define __SQLCIRCUITOIMPRESO_H__
#include <SiscomDesarrollo4/H/SiscomOperaciones.h>
int SqlRegistraCircuitoImpreso(SiscomOperaciones *pSiscomOpePtrDato);
int SqlCircuitosImpresosPendientes(SiscomOperaciones *pSiscomOpePtrDato);
int SqlEstadosImpresosSE(SiscomOperaciones *pSiscomOpePtrDato);
int SqlCircuitosImpresosPorFechaEstado(SiscomOperaciones *pSiscomOpePtrDato);
int SqlCircuitoImpresoActualizaEdo(SiscomOperaciones *pSiscomOpePtrDato);

void InsertToCircuitoImpreso(SiscomOperaciones *pSiscomOpePtrDato,
		      SiscomRegistroProL *pSiscomRegProLPtrDato,
		      char *pchrPtrSql);

void InsertToCircuitoImpresoInformacion(SiscomOperaciones *pSiscomOpePtrDato,
		      SiscomRegistroProL *pSiscomRegProLPtrDato,
		      char *pchrPtrSql);
void InsertToFechaEntregaImpreso(SiscomOperaciones *pSiscomOpePtrDato,
		      SiscomRegistroProL *pSiscomRegProLPtrDato,
		      char *pchrPtrSql);

void InsertToEstadoCircuitoImpreso(SiscomOperaciones *pSiscomOpePtrDato,
		      SiscomRegistroProL *pSiscomRegProLPtrDato,
		      char *pchrPtrSql);
void InsertToUltimoEstadoCircuitoImpreso(SiscomOperaciones *pSiscomOpePtrDato,
		      SiscomRegistroProL *pSiscomRegProLPtrDato,
		      char *pchrPtrSql);

void UpdateToUltimoEstado(SiscomOperaciones *pSiscomOpePtrDato,
		      SiscomRegistroProL *pSiscomRegProLPtrDato,
		      char *pchrPtrSql);
#endif
