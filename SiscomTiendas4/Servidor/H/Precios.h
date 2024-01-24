#ifndef __PRECIOS_H__
#define __PRECIOS_H__
#include <SiscomDesarrollo2.h>

SiscomOperaciones2 *OPAnexaPrecio();
SiscomOperaciones2 *OPPreciosRegistrados();
SiscomOperaciones2 *OPIniciaPrecios();
SiscomOperaciones2 *OPPreciosProducto();
SiscomOperaciones2 *OPActualizaPrecioProducto();

void CambiaMayusculasPrecio(SArgsSiscom *);
void RegistraPrecio(SArgsSiscom *);
void ArgumentosPrecios(SArgsSiscom *);
void GeneraIdPrecio(SArgsSiscom *);

void IniciaPreciosProductos(SArgsSiscom *);

void ArgumentosIniciaPrecios(SArgsSiscom *);

#endif
