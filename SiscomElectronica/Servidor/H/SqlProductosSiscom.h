#ifndef __SQLPRODUCTOSSISCOM_H__
#define __SQLPRODUCTOSSISCOM_H__
#include <SiscomDesarrollo4/H/SiscomOperaciones.h>
#include <SiscomDesarrollo4/H/SiscomFuncionesComunes.h>

int SqlComprandoProductoSiscom(SiscomOperaciones *pSiscomOpePtrDato);
int SqlRegistroCompraProductosSiscom(SiscomOperaciones *pSiscomOpePtrDato);
void UpdateExistenciaDefinicionProductoSiscom(SiscomOperaciones *pSiscomOpePtrDato,
			 SiscomRegistroProL *pSiscomRegProLPtrDato,
			 char *pchrPtrSql);

void UpdateExistenciaProductoSiscom(SiscomOperaciones *pSiscomOpePtrDato,
			 SiscomRegistroProL *pSiscomRegProLPtrDato,
			 char *pchrPtrSql);
void InsertToCompraProductoSiscom(SiscomOperaciones *pSiscomOpePtrDato,
			 SiscomRegistroProL *pSiscomRegProLPtrDato,
			 char *pchrPtrSql);
void InsertToProductosSiscomComprados(SiscomOperaciones *pSiscomOpePtrDato,
			 SiscomRegistroProL *pSiscomRegProLPtrDato,
			 char *pchrPtrSql);

void InsertToDetalleCompraProductoSiscom(SiscomOperaciones *pSiscomOpePtrDato,
			 SiscomRegistroProL *pSiscomRegProLPtrDato,
			 char *pchrPtrSql);
void InsertToOrigenProductoSiscom(SiscomOperaciones *pSiscomOpePtrDato,
			 SiscomRegistroProL *pSiscomRegProLPtrDato,
			 char *pchrPtrSql);
int SqlExistenciasDefinicionProducto(const char *pchrPtrCondicion,
				     SiscomOperaciones *pSiscomOpePtrDato);
#endif
