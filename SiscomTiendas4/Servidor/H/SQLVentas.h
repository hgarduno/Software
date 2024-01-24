#ifndef __SQLVENTAS_H__
#define __SQLVENTAS_H__
#include <SiscomDesarrollo2.h>
void SQLVenta(SArgsSiscom *);
void SQLActualizaVenta(SArgsSiscom *);
void SQLMarcaComoVendida(SArgsSiscom *);
void SQLEliminaDetalleVenta(SArgsSiscom *);
void SQLDetalleVenta(SArgsSiscom *);
void SqlObtenDetalleVenta(SArgsSiscom *);
void SQLVentaMoral(SArgsSiscom *);
void SQLVentaFisica(SArgsSiscom *);
void SQLActualizaInventarioVentas(SArgsSiscom *);
void SQLActualizaProductosCotizandoVenta(SArgsSiscom *);
void SQLRemisionFactura(SArgsSiscom *pSAgsSiscom);

void SQLInsertaVentas(SArgsSiscom *);

void SQLGeneraVenta(LCamposSiscomPro2 *,
			 LCamposSiscomPro2 **,
			 LCamposSiscomPro2 **,
			 int *);

void SQLGeneraActualizaVenta(LCamposSiscomPro2 *,
			 LCamposSiscomPro2 **,
			 LCamposSiscomPro2 **,
			 int *);

void SQLGeneraMarcaComoVendida(LCamposSiscomPro2 *,
			 LCamposSiscomPro2 **,
			 LCamposSiscomPro2 **,
			 int *);

void SQLGeneraEliminaDetalleVenta(LCamposSiscomPro2 *,
			 LCamposSiscomPro2 **,
			 LCamposSiscomPro2 **,
			 int *);
void SQLGeneraDetalleVenta(LCamposSiscomPro2 *,
			 LCamposSiscomPro2 **,
			 LCamposSiscomPro2 **,
			 int *);
void SQLGeneraVentaFisica(LCamposSiscomPro2 *,
			 LCamposSiscomPro2 **,
			 LCamposSiscomPro2 **,
			 int *);
void SQLGeneraVentaMoral(LCamposSiscomPro2 *,
			 LCamposSiscomPro2 **,
			 LCamposSiscomPro2 **,
			 int *);

void SQLGeneraActualizaInventarioVentas(LCamposSiscomPro2 *,
			 LCamposSiscomPro2 **,
			 LCamposSiscomPro2 **,
			 int *);
void SQLGeneraActualizaProductosCotizandoVenta(LCamposSiscomPro2 *,
			 LCamposSiscomPro2 **,
			 LCamposSiscomPro2 **,
			 int *);


void SQLGeneraInsertaRemisionFactura(LCamposSiscomPro2 *,
			 LCamposSiscomPro2 **,
			 LCamposSiscomPro2 **,
			 int *);
#endif
