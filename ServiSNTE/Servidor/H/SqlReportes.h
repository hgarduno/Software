#ifndef __SQLREPORTES_H__
#define __SQLREPORTES_H__
#include <SiscomProtocoloComunicaciones.h>
#include <SiscomOperaciones.h>
#include <SiscomArchivosIni.h>

int SqlReporteVentas(SiscomOperaciones *pSiscomOpePtrDat);
int SqlVentasCliente(SiscomOperaciones *pSiscomOpePtrDat);
int SqlExistenciasTienda(SiscomOperaciones *pSiscomOpePtrDat);
int SqlExistenciasAlmacen(SiscomOperaciones *pSiscomOpePtrDat);
int SqlExistenciasAlmacenProveedor(SiscomOperaciones *pSiscomOpePtrDat);
int SqlExistenciasAlmacenListaProductos(SiscomOperaciones *pSiscomOpePtrDat);
int SqlExistenciasTiendaListaProductos(SiscomOperaciones *pSiscomOpePtrDat);
int SqlExistenciasProductoTienda(SiscomOperaciones *pSiscomOpePtrDat);
int SqlExistenciasProductoAlmacen(SiscomOperaciones *pSiscomOpePtrDat);
int SqlExistenciasTiendaProveedor(SiscomOperaciones *pSiscomOpePtrDat);
int SqlReporteCompras(SiscomOperaciones *pSiscomOpePtrDat);
int SqlReporteDetalleCompra(SiscomOperaciones *pSiscomOpePtrDat);
int SqlConsultaFoliosCancelados(SiscomOperaciones *pSiscomOpePtrDat);
int SqlPreciosProductos(SiscomOperaciones *pSiscomOpePtrDat);
int SqlPreciosProductosComprador(SiscomOperaciones *pSiscomOpePtrDat);

int SqlStockDepartamentoProveedor(SiscomOperaciones *pSiscomOpePtrDat);
int SqlExistenciasProveedor(SiscomOperaciones *pSiscomOpePtrDat);
int SqlStockTienda(SiscomOperaciones *pSiscomOpePtrDato);
int SqlProductosServiSNTE(SiscomOperaciones *pSiscomOpePtrDato);
int SqlDatosCompra(SiscomOperaciones *pSiscomOpePtrDato);
int SqlRepProveedores(SiscomOperaciones *pSiscomOpePtrDato);
#endif
