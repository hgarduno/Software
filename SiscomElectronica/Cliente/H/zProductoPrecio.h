#ifndef __ZPRODUCTOPRECIO_H__
#define __ZPRODUCTOPRECIO_H__
#include <zProducto.h>

class zPrecios;
class zProductoPrecio:public zProducto
{
public:
	zProductoPrecio(const char *pchrPtrClave);
	void Precios(zPrecios *);

};

#endif
