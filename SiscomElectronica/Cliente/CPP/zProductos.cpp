#include <zProductos.h>
#include <zProducto.h>
zProductos::zProductos()
{

}
void zProductos::Agrega(const char *pchrPtrClave)
{
   (*this) << new zProducto(pchrPtrClave);
}
void zProductos::Agrega(zProducto *pzProducto)
{
   (*this)	<<  pzProducto;
}
