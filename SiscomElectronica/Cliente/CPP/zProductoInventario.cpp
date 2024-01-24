#include <zProductoInventario.h>
#include <zSiscomCampo.h>
zProductoInventario::zProductoInventario(zSiscomRegistro *pzSisRegistro):zProducto(pzSisRegistro)
{
  (*this) << 
  new zSiscomCampo("Inventario");
}
void zProductoInventario::Inventario(const char *pchrPtrInventario)
{
   ActualizaCampo("Inventario",(const unsigned char *)pchrPtrInventario);
}
