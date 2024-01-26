#ifndef __SQLPOSICIONESIMPRESION_H__
#define __SQLPOSICIONESIMPRESION_H__
#include <SiscomProtocoloComunicaciones.h>
#include <SiscomOperaciones.h>
#include <SiscomArchivosIni.h>
int SqlPosicionesPuntoVenta(SiscomOperaciones *pSiscomOpePtrDato);
int SqlPosicionesReciboApartado(SiscomOperaciones *pSiscomOpePtrDato);
int SqlPosicionesTransferencia(SiscomOperaciones *pSiscomOpePtrDato);
int SqlPosicionesListaPrecios(SiscomOperaciones *pSiscomOpePtrDato);
int SqlPosicionesListaPreciosComprador(SiscomOperaciones *pSiscomOpePtrDato);
int SqlPosicionesStockTienda(SiscomOperaciones *pSiscomOpePtrDato);
int SqlPosicionesCuentasPagar(SiscomOperaciones *pSiscomOpePtrDato);
int SqlPosicionesRelacionChequesPagar(SiscomOperaciones *pSiscomOpePtrDato);
int SqlPosicionesSoporteCompras(SiscomOperaciones *pSiscomOpePtrDato);
int SqlPosicionesSoporteVentas(SiscomOperaciones *pSiscomOpePtrDato);
int SqlPosicionesStockProveedorCosto(SiscomOperaciones *pSiscomOpePtrDato);
int SqlPosicionesExistenciaProveedor(SiscomOperaciones *pSiscomOpePtrDato);
int SqlPosicionesDatosCompra(SiscomOperaciones *pSiscomOpePtrDato);
int SqlPosicionesExistenciaTiendaProveedor(SiscomOperaciones *pSiscomOpePtrDato);
int SqlPosicionesSoporteTransferencias(SiscomOperaciones *pSiscomOpePtrDato);
int SqlPosicionesProveedores(SiscomOperaciones *pSiscomOpePtrDato);

#endif
