#ifndef __SQLRASTREAPRODUCTO_H__
#define __SQLRASTREAPRODUCTO_H__
#include <SiscomDesarrollo2.h>

void SqlExistenciaProducto(SArgsSiscom *pSAgsSiscom);
void SqlExiProductoBodegas(SArgsSiscom *pSAgsSiscom);
void SqlVentasProductoAnterior(SArgsSiscom *pSAgsSiscom);
void SqlTotalVentasAnterior(SArgsSiscom *pSAgsSiscom);
void SqlComprasProductoAnterior(SArgsSiscom *pSAgsSiscom);
void SqlTotalComprasAnterior(SArgsSiscom *pSAgsSiscom);
void SqlTransferenciasExpendioExpendio(SArgsSiscom *pSAgsSiscom);
void SqlTotalTransBodExp(SArgsSiscom *pSAgsSiscom);
void SqlTransferenciasBodegasExpendio(SArgsSiscom *pSAgsSiscom);
void SqlTotalTransExpExp(SArgsSiscom *pSAgsSiscom);

void SqlTransferenciaBodegaBodega(SArgsSiscom *pSAgsSiscom);

void SqlActualizoInventario(SArgsSiscom *pSAgsSiscom);

#endif
