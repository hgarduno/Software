#ifndef __SQLCOMPRAIMPORTACION_H__
#define __SQLCOMPRAIMPORTACION_H__
#include <SiscomDesarrollo4/H/SiscomOperaciones.h>

int SqlGuardaCompraImportacion(SiscomOperaciones *pSiscomOpePtrDato);
int SqlRegistraCompraImportacion(SiscomOperaciones *pSiscomOpePtrDato);
int SqlRegistroParcialCompraImportacionFaltaronProductos(SiscomOperaciones *pSiscomOpePtrDato);
void InsertToRegistroCompra(SiscomOperaciones *pSiscomOpePtrDato,
			   SiscomRegistroProL *pSiscomRegProLPtrDato,
			   char *pchrPtrSql);
void InsertToProductoCompraImportacion(SiscomOperaciones *pSiscomOpePtrDato,
			   SiscomRegistroProL *pSiscomRegProLPtrDato,
			   char *pchrPtrSql);
void UpdateExistenciaCompraImportacion(SiscomOperaciones *pSiscomOpePtrDato,
			   SiscomRegistroProL *pSiscomRegProLPtrDato,
			   char *pchrPtrSql);
void UpdateRegistroCompraImportacion(SiscomOperaciones *pSiscomOpePtrDato,
			   SiscomRegistroProL *pSiscomRegProLPtrDato,
			   char *pchrPtrSql);


void InsertToCompraImportacion(SiscomOperaciones *pSiscomOpePtrDato,
			   SiscomRegistroProL *pSiscomRegProLPtrDato,
			   char *pchrPtrSql);

void InsertToDescripcionCompraImportacion(SiscomOperaciones *pSiscomOpePtrDato,
			   SiscomRegistroProL *pSiscomRegProLPtrDato,
			   char *pchrPtrSql);

void InsertToProductoProveedorImportacion(SiscomOperaciones *pSiscomOpePtrDato,
				      SiscomRegistroProL *pSiscomRegProLPtrDato,
				      char *pchrPtrSql);
void InsertToDetalleCompraImportacion(SiscomOperaciones *pSiscomOpePtrDato,
				      SiscomRegistroProL *pSiscomRegProLPtrDato,
				      char *pchrPtrSql);

void InsertToProveedoresCompraImportacion(SiscomOperaciones *pSiscomOpePtrDato,
				      SiscomRegistroProL *pSiscomRegProLPtrDato,
				      char *pchrPtrSql);
void DeleteCompraImportacion(SiscomOperaciones *pSiscomOpePtrDato,
			   SiscomRegistroProL *pSiscomRegProLPtrDato,
			   char *pchrPtrSql);
void DeleteDetalleCompraImportacion(SiscomOperaciones *pSiscomOpePtrDato,
			   SiscomRegistroProL *pSiscomRegProLPtrDato,
			   char *pchrPtrSql);;
void DeleteProductoProveedorImportacion(SiscomOperaciones *pSiscomOpePtrDato,
			   SiscomRegistroProL *pSiscomRegProLPtrDato,
			   char *pchrPtrSql);
void DeleteDescripcionCompraImportacion(SiscomOperaciones *pSiscomOpePtrDato,
			   SiscomRegistroProL *pSiscomRegProLPtrDato,
			   char *pchrPtrSql);

void DeleteProveedoresCompraImportacion(SiscomOperaciones *pSiscomOpePtrDato,
			   SiscomRegistroProL *pSiscomRegProLPtrDato,
			   char *pchrPtrSql);

int SqlProductosPorFiltro(SiscomOperaciones *pSiscomOpePtrDato);
int SqlConsultaCompraImportacion(SiscomOperaciones *pSiscomOpePtrDato);
int SqlConsultaComprasImportacion(SiscomOperaciones *pSiscomOpePtrDato);
int SqlProductoImportadoInf(SiscomOperaciones *pSisOpePtrDato);
int SqlCompletaProductosImportacion(SiscomOperaciones *pSisOpePtrDat);
void SqlFormaConsultaProveedoresCompraImportacion(SiscomOperaciones *pSisOpePtrDato, char *pchrPtrSql);
#endif
