#ifndef __ZPRODUCTOTRANSFERIR_H__
#define __ZPRODUCTOTRANSFERIR_H__

#include <zProducto.h>

class zProductoTransferir :public zProducto
{
  public:
  	zProductoTransferir();
	void Cantidad(const char *pchrPtrCantidad);

};

#endif
