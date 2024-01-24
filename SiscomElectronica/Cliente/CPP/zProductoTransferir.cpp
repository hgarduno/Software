#include <zProductoTransferir.h>
#include <zSiscomCampo.h>
zProductoTransferir::zProductoTransferir():
			zProducto()
{
  (*this) << 
  new zSiscomCampo("Cantidad");
}
void zProductoTransferir::Cantidad(const char *pchrPtrCantidad)
{
	ActualizaCampo("Cantidad",(const unsigned char *)pchrPtrCantidad);
}
