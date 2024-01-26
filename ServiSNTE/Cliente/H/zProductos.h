#ifndef __ZPRODUCTOS_H__
#define __ZPRODUCTOS_H__
#include <zSiscomRegistros.h>

class zProductos:public zSiscomRegistros
{
public:
	zProductos();
	const char *CodigoBarras(int pintNProducto);
	const char *Stock(int pintNProducto);

	void Cantidad(int pintNProducto,const char *pchrPtrCantidad);
	void Observaciones(int pintNProducto,const char *pchrPtrObservaciones);

};

#endif
