#ifndef __VENTAS_H__
#define __VENTAS_H__
#include <SiscomDesarrollo2.h>

typedef struct ProcesoVentas
{
	const char *chrPtrEdoVenta;
	const char *chrPtrTipoCliente;
	void (*SQLVentas[10])(SArgsSiscom *);
}StcProcesoVentas;

SiscomOperaciones2 *OPRegistraVenta();
void ArgumentosVenta(SArgsSiscom *);
void RegistraVenta(SArgsSiscom *);
void ProcesoVentas(SArgsSiscom *);

#endif
