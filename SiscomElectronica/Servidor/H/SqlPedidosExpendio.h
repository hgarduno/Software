#ifndef __SQLPEDIDOSEXPENDIO_H__
#define __SQLPEDIDOSEXPENDIO_H__
#include <SiscomDesarrollo4/H/SiscomOperaciones.h>

int SqlTransfiereBodegaExpendioParaPedido(SiscomOperaciones *pSiscomOpePtrDato);
int SqlActualizaInventarioParaPedido(SiscomOperaciones *pSiscomOpePtrDato);
int SqlPedidoExpendioHoy(SiscomOperaciones *pSiscomPtrDato);
int SqlIniciandoPedidoExpendioHoy(SiscomOperaciones *pSiscomOpePtrDato);
int SqlProductoAPedidoExpendio(SiscomOperaciones *pSiscomOpePtrDato);
int SqlEliminaProductoPedido(SiscomOperaciones *pSiscomOpePtrDato);
int SqlActualizaProductoPedido(SiscomOperaciones *pSiscomOpePtrDato);
int SqlActualizaObservacionesPedido(SiscomOperaciones *pSiscomOpePtrDato);
int SqlRegistraPedido(SiscomOperaciones *pSiscomOpePtrDato);
int SqlEnviaPedidoMatriz(SiscomOperaciones *pSiscomOpePtrDato);
int SqlServidoresSiscom(SiscomOperaciones *pSiscomOpePtrDato);
int SqlEstadoPedidoExpendioProducto(SiscomOperaciones *pSiscomOpePtrDato);
int SqlExistenciaExpendioBodegaProducto(SiscomOperaciones *pSisOpePtrDato);

void SqlConsultaDetallePedidoExpendioHoy(SiscomOperaciones *pSiscomOpePtrDato,char *pchrPtrSql);
void SqlConsultaPedidoExpendioHoy(SiscomOperaciones *pSiscomOpePtrDato,char *pchrPtrSql);


void InsertToPedidosMaterial(SiscomOperaciones *pSiscomOpePtrDato,
                      SiscomRegistroProL *pSiscomRegProLPtrDato,
                      char *pchrPtrSql);

void InsertToPedidosMaterialAMatriz(SiscomOperaciones *pSiscomOpePtrDato,
                      SiscomRegistroProL *pSiscomRegProLPtrDato,
                      char *pchrPtrSql);
void InsertToDetallePedidoMaterial(SiscomOperaciones *pSiscomOpePtrDato,
                      SiscomRegistroProL *pSiscomRegProLPtrDato,
                      char *pchrPtrSql);
void InsertToDetallePedidoMaterialAMatriz(SiscomOperaciones *pSiscomOpePtrDato,
                      SiscomRegistroProL *pSiscomRegProLPtrDato,
                      char *pchrPtrSql);

void InsertToUltimoEstadoPedidoMatriz(SiscomOperaciones *pSiscomOpePtrDato,
                      SiscomRegistroProL *pSiscomRegProLPtrDato,
                      char *pchrPtrSql);

void InsertToEstadoPedidoExpendioProducto(SiscomOperaciones *pSiscomOpePtrDato,
                      SiscomRegistroProL *pSiscomRegProLPtrDato,
                      char *pchrPtrSql);
void InsertToDesajusteInventarioParaPedido(SiscomOperaciones *pSiscomOpePtrDato,
                      SiscomRegistroProL *pSiscomRegProLPtrDato,
                      char *pchrPtrSql);

void InsertIntoInventarioParaPedido(SiscomOperaciones *pSiscomOpePtrDato,
                      SiscomRegistroProL *pSiscomRegProLPtrDato,
                      char *pchrPtrSql);
void InsertIntoBodegaAExpendioParaPedido(SiscomOperaciones *pSiscomOpePtrDato,
                      SiscomRegistroProL *pSiscomRegProLPtrDato,
                      char *pchrPtrSql);

void InsertIntoDesajusteInventarioParaPedido(SiscomOperaciones *pSiscomOpePtrDato,
                      SiscomRegistroProL *pSiscomRegProLPtrDato,
                      char *pchrPtrSql);
void DeleteFromDetallePedidoMaterial(SiscomOperaciones *pSiscomOpePtrDato,
                      SiscomRegistroProL *pSiscomRegProLPtrDato,
                      char *pchrPtrSql);
void UpdateFromDetallePedidoMaterial(SiscomOperaciones *pSiscomOpePtrDato,
                      SiscomRegistroProL *pSiscomRegProLPtrDato,
                      char *pchrPtrSql);
void UpdateFromPedidosMaterialObservaciones(SiscomOperaciones *pSiscomOpePtrDato,
                      SiscomRegistroProL *pSiscomRegProLPtrDato,
                      char *pchrPtrSql);
void UpdateFromExistenciasParaPedido(SiscomOperaciones *pSiscomOpePtrDato,
                      SiscomRegistroProL *pSiscomRegProLPtrDato,
                      char *pchrPtrSql);
void UpdateMaterialBodegaParaPedido(SiscomOperaciones *pSiscomOpePtrDato,
                      SiscomRegistroProL *pSiscomRegProLPtrDato,
                      char *pchrPtrSql);

#endif
