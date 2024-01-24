#include <zClavesProveedor.h>
#include <zClaveProveedor.h>
zClavesProveedor::zClavesProveedor()
{

}
zClavesProveedor &zClavesProveedor::operator<<(zClaveProveedor *pzClaveProveedor)
{
   Agrega(pzClaveProveedor);
   return *this;

}
