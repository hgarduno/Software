#ifndef __COMPRAS_H__
#define __COMPRAS_H__
#include <SiscomDesarrollo2.h>

SiscomOperaciones2 *OPRegistraCompra();
SiscomOperaciones2 *OPUltimaCompraProducto();
SiscomOperaciones2 *OPCompras();
SiscomOperaciones2 *OPDetalleCompra();
void ArgumentosCompras(SArgsSiscom *);
void RegistraCompras(SArgsSiscom *);
void GeneraIdCompra(SArgsSiscom *);

#endif
