#ifndef __ZPRODUCTOINVENTARIO_H__
#define __ZPRODUCTOINVENTARIO_H__
#include <zProducto.h>
class zProductoInventario:public zProducto
{
public:
	zProductoInventario(zSiscomRegistro *pzSisRegProducto);


	void Inventario(const char *pchrPtrInventario);
	const char *Inventario();

};

#endif
