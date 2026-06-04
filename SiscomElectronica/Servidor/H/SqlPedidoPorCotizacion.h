#ifndef __SQLPEDIDOPORCOTIZACION_H__
#define __SQLPEDIDOPORCOTIZACION_H__
#include <SiscomDesarrollo4/H/SiscomOperaciones.h>

int SqlPedidoPorCotizacion(SiscomOperaciones *pSiscomOpePtrDato);

void InsertToPedidosMaterialPC(SiscomOperaciones *pSiscomOpePtrDato,
		      SiscomRegistroProL *pSiscomRegProLPtrDato,
		      char *pchrPtrSql);
void InsertToDetallePedidosMaterialPC(SiscomOperaciones *pSiscomOpePtrDato,
		      SiscomRegistroProL *pSiscomRegProLPtrDato,
		      char *pchrPtrSql);

void InsertToEstadoPedidoMaterialPC(SiscomOperaciones *pSiscomOpePtrDato,
		      SiscomRegistroProL *pSiscomRegProLPtrDato,
		      char *pchrPtrSql);
void InsertToEstadoPedidoMaterialPC(SiscomOperaciones *pSiscomOpePtrDato,
		      SiscomRegistroProL *pSiscomRegProLPtrDato,
		      char *pchrPtrSql);
void InsertToUltimoEstadoPedidoMaterialPC(SiscomOperaciones *pSiscomOpePtrDato,
		      SiscomRegistroProL *pSiscomRegProLPtrDato,
		      char *pchrPtrSql);
#endif
