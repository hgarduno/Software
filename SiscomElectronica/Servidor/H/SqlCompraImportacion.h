#ifndef __SQLCOMPRAIMPORTACION_H__
#define __SQLCOMPRAIMPORTACION_H__
#include <SiscomDesarrollo4/H/SiscomOperaciones.h>

int SqlActualizandoCompraRegistrada(SiscomOperaciones *pSisOpePtrDato);
int SqlProductosCompraImportacion(SiscomOperaciones *pSiscomOpePtrDato);
int SqlGuardaCompraImportacion(SiscomOperaciones *pSiscomOpePtrDato);
int SqlRegistraCompraImportacion(SiscomOperaciones *pSiscomOpePtrDato);
int SqlRegistroParcialCompraImportacionFaltaronProductos(SiscomOperaciones *pSiscomOpePtrDato);
void InsertToRegistroCompra(SiscomOperaciones *pSiscomOpePtrDato,
			   SiscomRegistroProL *pSiscomRegProLPtrDato,
			   char *pchrPtrSql);
void InsertToProductoCompraImportacion(SiscomOperaciones *pSiscomOpePtrDato,
			   SiscomRegistroProL *pSiscomRegProLPtrDato,
			   char *pchrPtrSql);

void InsertToProductoCompraImportacionPorCambio(SiscomOperaciones *pSiscomOpePtrDato,
			   SiscomRegistroProL *pSiscomRegProLPtrDato,
			   char *pchrPtrSql);
void UpdateExistenciaCompraImportacion(SiscomOperaciones *pSiscomOpePtrDato,
			   SiscomRegistroProL *pSiscomRegProLPtrDato,
			   char *pchrPtrSql);

void UpdateExistenciaCompraImportacionPorCambio(SiscomOperaciones *pSiscomOpePtrDato,
			   SiscomRegistroProL *pSiscomRegProLPtrDato,
			   char *pchrPtrSql);
void UpdateRegistroCompraImportacion(SiscomOperaciones *pSiscomOpePtrDato,
			   SiscomRegistroProL *pSiscomRegProLPtrDato,
			   char *pchrPtrSql);

void UpdateRegistroCompraImportacionPorCambio(SiscomOperaciones *pSiscomOpePtrDato,
			   SiscomRegistroProL *pSiscomRegProLPtrDato,
			   char *pchrPtrSql);

void UpdateDetalleCompraImportacionRegistrada(SiscomOperaciones *pSisOpePtrDato,
					      SiscomRegistroProL *pSisRegProLPtrDatos,
					      char *pchrPtrSql);

void UpdateRegistroCompraImportacionPorActualizacion(SiscomOperaciones *pSiscomOpePtrDato,
			   SiscomRegistroProL *pSiscomRegProLPtrDato,
			   char *pchrPtrSql);

void UpdateGeneralesCompraImportacion(SiscomOperaciones *pSiscomOpePtrDato,
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


void UpdateCompraImportacionPorModificacion(SiscomOperaciones *pSiscomOpePtrDato,
			   SiscomRegistroProL *pSiscomRegProLPtrDato,
			   char *pchrPtrSql);


void UpdateCompraImportacionPorActualizacion(SiscomOperaciones *pSiscomOpePtrDato,
			   SiscomRegistroProL *pSiscomRegProLPtrDato,
			   char *pchrPtrSql);
int SqlProductosPorFiltro(SiscomOperaciones *pSiscomOpePtrDato);
int SqlConsultaCompraImportacion(SiscomOperaciones *pSiscomOpePtrDato);
int SqlConsultaComprasImportacion(SiscomOperaciones *pSiscomOpePtrDato);
int SqlProductoImportadoInf(SiscomOperaciones *pSisOpePtrDato);
int SqlCompletaProductosImportacion(SiscomOperaciones *pSisOpePtrDat);
void SqlFormaConsultaProveedoresCompraImportacion(SiscomOperaciones *pSisOpePtrDato, char *pchrPtrSql);

void SqlFormaProductosCompraImportacion(SiscomOperaciones *pSisOpePtrDatos,char *pchrPtrSql);
void SqlConsultandoProductosCompra(SiscomOperaciones *pSisOpePtrDatos);
#endif
