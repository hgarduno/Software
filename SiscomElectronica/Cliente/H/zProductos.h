#ifndef __ZPRODUCTOS_H__
#define __ZPRODUCTOS_H__

#include <zSiscomRegistros.h>

class zProducto;
class zProductos:public zSiscomRegistros
{
public:
	zProductos();
	void Agrega(const char *pchrPtrClave);
	void Agrega(zProducto *pzProducto);
	void Agrega(zSiscomRegistros *);
};

#endif
