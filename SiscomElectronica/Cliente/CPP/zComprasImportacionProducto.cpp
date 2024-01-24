#include <zComprasImportacionProducto.h>
#include <zCompraImportacionProducto.h>
zComprasImportacionProducto::zComprasImportacionProducto()
{

}
zComprasImportacionProducto &zComprasImportacionProducto::operator<<(zCompraImportacionProducto *pzComImpPro)
{
 Agrega(pzComImpPro);
return *this;
}

zCompraImportacionProducto *zComprasImportacionProducto::Ultima()
{
  return (zCompraImportacionProducto *)(*this)[0];
}
