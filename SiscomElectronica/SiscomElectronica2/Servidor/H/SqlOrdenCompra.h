#ifndef __SQLORDENCOMPRA_H__
#define __SQLORDENCOMPRA_H__
#include <SiscomDesarrollo2.h>

void SqlComprasProductoSemestreAnterior(SArgsSiscom *pSAgsSiscom);
void SqlVentasProductoSemestreAnterior(SArgsSiscom *pSAgsSiscom);
void SqlComprasProductoSemestreActual(SArgsSiscom *pSAgsSiscom);
void SqlVentasProductoSemestreActual(SArgsSiscom *pSAgsSiscom);
void SqlExistenciasPrecio(SArgsSiscom *pSAgsSiscom);
void SqlHistoricoComprasOrden(SArgsSiscom *pSAgsSiscom);
void SqlTotalTransferencias(SArgsSiscom *pSAgsSiscom);
void SqlTransferenciasPorExpendio(SArgsSiscom *pSAgsSiscom);

#endif
