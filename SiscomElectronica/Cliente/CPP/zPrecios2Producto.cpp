#include <zPrecios2Producto.h>
#include <zSiscomCampo.h>
zPrecios2Producto::zPrecios2Producto(const char *pchrPtrClave)
{
(*this)		<<
new zSiscomCampo("Clave",(const unsigned char *)pchrPtrClave) <<
new zSiscomCampo("Precios") ;

}
