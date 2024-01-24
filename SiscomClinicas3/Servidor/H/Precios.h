#ifndef __PRECIOS_H__
#define __PRECIOS_H__
#include <SiscomDesarrollo2.h>

SiscomOperaciones2 *OPPreciosServicio();
SiscomOperaciones2 *OPPreciosServicioMedico();
SiscomOperaciones2 *OPActualizaPrecioServicioGeneral();
SiscomOperaciones2 *OPActualizaPrecioServicioMedico();

void ArgumentosPreciosClinicas(SArgsSiscom *);
void RegistraPrecioClinicas(SArgsSiscom *);

#endif
