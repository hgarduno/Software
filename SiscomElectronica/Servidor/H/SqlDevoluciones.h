#ifndef __SQLDEVOLUCIONES__
#define __SQLDEVOLUCIONES__
#include <SiscomDesarrollo4/H/SiscomOperaciones.h>
int SqlDevolucionOrden(SiscomOperaciones *pSiscomOpePtrDato);

void DeleteVentasDevolucion(SiscomOperaciones *pSiscomOpePtrDato,
				      SiscomRegistroProL *pSiscomRegProLPtrDato,
				      char *pchrPtrSql);
void UpdateExistenciaDevolucion(SiscomOperaciones *pSiscomOpePtrDato,
				      SiscomRegistroProL *pSiscomRegProLPtrDato,
				      char *pchrPtrSql);
void DeleteImporteOrdenDevolucion(SiscomOperaciones *pSiscomOpePtrDato,
				      SiscomRegistroProL *pSiscomRegProLPtrDato,
				      char *pchrPtrSql);

void DeleteEscuelaOrdenDevolucion(SiscomOperaciones *pSiscomOpePtrDato,
				      SiscomRegistroProL *pSiscomRegProLPtrDato,
				      char *pchrPtrSql);
void DeletePagaConDevolucion(SiscomOperaciones *pSiscomOpePtrDato,
				      SiscomRegistroProL *pSiscomRegProLPtrDato,
				      char *pchrPtrSql);
void DeletePagoTransferenciaDevolucion(SiscomOperaciones *pSiscomOpePtrDato,
				      SiscomRegistroProL *pSiscomRegProLPtrDato,
				      char *pchrPtrSql);
void DeletePagoTarjetaDevolucion(SiscomOperaciones *pSiscomOpePtrDato,
				      SiscomRegistroProL *pSiscomRegProLPtrDato,
				      char *pchrPtrSql);
#endif

