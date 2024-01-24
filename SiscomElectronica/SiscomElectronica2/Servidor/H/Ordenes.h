#ifndef __ORDENES_H__
#define __ORDENES_H__
#include <SiscomDesarrollo2.h>
SiscomOperaciones2 *OpOrdenesVendidasSiscom();
SiscomOperaciones2 *OpDetalleOrden();
SiscomOperaciones2 *OpAnexarOrdenContabilidad();
void AnexarOrdenContabilidad(SArgsSiscom *);
void ArgumentosOrdenes(SArgsSiscom *);

#endif
