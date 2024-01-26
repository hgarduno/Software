#ifndef __ZPRECIOSPRODUCTO_H__
#define __ZPRECIOSPRODUCTO_H__
#include <zSiscomRegistro.h>


class zPrecio;
class zCosto;
class zPreciosProducto:public zSiscomRegistro
{
public:
	zPreciosProducto(zPrecio *pzPrecio,
			 zPrecio *pzPrecioForaneo,
			 zCosto *pzCosto);
};

#endif
