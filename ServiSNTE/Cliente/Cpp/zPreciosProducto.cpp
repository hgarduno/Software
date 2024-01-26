#include <zPreciosProducto.h>
#include <zPrecio.h>
#include <zCosto.h>
zPreciosProducto::zPreciosProducto(zPrecio *pzPrecio,
				   zPrecio *pzPrecioForaneo,
				   zCosto *pzCosto)
{

   AgregaCampo("Precio",pzPrecio);
   AgregaCampo("PrecioForaneo",pzPrecioForaneo);
   AgregaCampo("Costo",pzCosto);
}
