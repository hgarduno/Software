#ifndef __ZPRODUCTOCOMPRA_H__
#define __ZPRODUCTOCOMPRA_H__
#include <zProducto.h>
class zProductoCompra:public zProducto
{
public:
	zProductoCompra();
	void ClaveProveedor(const char *pchrPtrCveProveedor);
	void Cantidad(const char *pchrPtrCantidad);
	void DscProveedor(const char *pchrPtrDscProveedor);
	void Precio(const char *pchrPtrPrecio);
	void PrecioTotal(const char *pchrPtrPrecioTotal);

	const char *ClaveProveedor();
	const char *DscProveedor();

	const char *Precio();
	const char *PrecioTotal();

	static zProductoCompra *DeCompra(zSiscomRegistro *);
};

#endif
