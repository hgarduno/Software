#ifndef __SQLPRODUCTOS_H__
#define __SQLPRODUCTOS_H__
#include <SiscomProtocoloComunicaciones.h>
#include <SiscomOperaciones.h>
#include <SiscomArchivosIni.h>
#include <SiscomReplicacion.h>

int SqlPreciosDescuentosProducto(SiscomOperaciones *pSiscomOpePtrDat);
int SqlProductoPorCodigoBarras(SiscomOperaciones *pSiscomOpePtrDat);
int SqlPreciosProducto(SiscomOperaciones *pSiscomOpePtrDat);
int SqlRegistraProducto(SiscomOperaciones *pSiscomOpePtrDat);
int SqlActualizandoStock(SiscomOperaciones *pSiscomOpePtrDat);

void InsertToCostoBruto(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql);

void SqlDescuentosProducto(SiscomOperaciones *pSiscomOpePtrDat,
			      char *pchrPtrSql);
void SqlCostosBrutoProducto(SiscomOperaciones *pSiscomOpePtrDat,
			      char *pchrPtrSql);
void SqlPreciosForaneoProducto(SiscomOperaciones *pSiscomOpePtrDat,
			      char *pchrPtrSql);
void SqlPreciosGeneralProducto(SiscomOperaciones *pSiscomOpePtrDat,
			      char *pchrPtrSql);

void InsertToProductos(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql);
void InsertToProductoProveedor(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql);
void InsertToExistencia(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql);
void InsertToExistenciaAlmacen(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql);
void InsertToCostoBruto(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql);
void InsertToProductoCodigoBarrasCrea(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql);
void InsertToEstatusProducto(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql);
void InsertToDepartamentoProducto(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql);

void InsertToStock(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql);
void InsertToProductoStockRegProd(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql);

void UpdateStock(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql);

void InsertToDescuentoEmpresa(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql);

void InsertToUltimoDescuentoEmpresa(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql);
#endif
