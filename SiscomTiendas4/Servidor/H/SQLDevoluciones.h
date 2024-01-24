#ifndef __SQLDEVOLUCIONES_H__
#define __SQLDEVOLUCIONES_H__
#include <SiscomDesarrollo2.h>

void SQLInventarioDevolucion(SArgsSiscom *);
void SQLVentasDevolucion(SArgsSiscom *);
void SQLActualizaTotalVenta(SArgsSiscom *);
void SQLDevolucion(SArgsSiscom *);
void SQLDetalleDevolucion(SArgsSiscom *);

void SQLGeneraInventarioDevolucion(LCamposSiscomPro2 *,
				   LCamposSiscomPro2 **,
				   LCamposSiscomPro2 **,
				   int *);
void SQLGeneraVentasDevolucion(LCamposSiscomPro2 *,
				   LCamposSiscomPro2 **,
				   LCamposSiscomPro2 **,
				   int *);
void SQLGeneraActualizaTotalVenta(LCamposSiscomPro2 *,
				  LCamposSiscomPro2 **,
				  LCamposSiscomPro2 **,
				  int *);

void SQLGeneraDevolucion(LCamposSiscomPro2 *,
				   LCamposSiscomPro2 **,
				   LCamposSiscomPro2 **,
				   int *);
void SQLGeneraDetalleDevolucion(LCamposSiscomPro2 *,
				   LCamposSiscomPro2 **,
				   LCamposSiscomPro2 **,
				   int *);

#endif
