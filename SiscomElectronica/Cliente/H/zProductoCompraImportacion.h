#ifndef __ZPRODUCTOCOMPRAIMPORTACION_H__
#define __ZPRODUCTOCOMPRAIMPORTACION_H__
#include <zProductoCompra.h>
class zComprasImportacionProducto;
class zProductoCompraImportacion:public zProductoCompra
{
public:
	zProductoCompraImportacion();
	void Peso(const char *);
	void PesoTotal(const char *);
	const char *Peso();
	const char *PesoTotal();
	zComprasImportacionProducto *Compras();

static zProductoCompraImportacion *Producto(zSiscomRegistro *);

	void Compras(zSiscomRegistros *);

};

#endif
