#ifndef __SQLCOMPRAS_H__
#define __SQLCOMPRAS_H__
#include <SiscomDesarrollo2.h>
void SQLRegistraCompra(SArgsSiscom *);
void SQLActualizaInventario(SArgsSiscom *);
void SQLUltimaCompraProducto(SArgsSiscom *);
void SQLCompras(SArgsSiscom *);
void SQLDetalleCompra(SArgsSiscom *);
void SQLProductosCotizando(SArgsSiscom *);

void SQLGeneraCompras(LCamposSiscomPro2 *,
		      LCamposSiscomPro2 **,
		      LCamposSiscomPro2 **,
		      int *);

void SQLGeneraInventario(LCamposSiscomPro2 *,
		      LCamposSiscomPro2 **,
		      LCamposSiscomPro2 **,
		      int *);
void SQLGeneraProductosCotizando(LCamposSiscomPro2 *,
				 LCamposSiscomPro2 **,
				 LCamposSiscomPro2 **,
				 int *);
#endif
