#include <zProductoCompra.h>
#include <zSiscomCampo.h>
zProductoCompra::zProductoCompra()
{

  (*this)				<<
  new zSiscomCampo("ClaveProveedor")	<<
  new zSiscomCampo("Cantidad")		<<
  new zSiscomCampo("DscProveedor")	<<
  new zSiscomCampo("Precio")		<<
  new zSiscomCampo("PrecioTotal");	
}

void zProductoCompra::ClaveProveedor(const char *pchrPtrCveProveedor)
{
  ActualizaCampo("ClaveProveedor",(const unsigned char *)pchrPtrCveProveedor);
}
void zProductoCompra::Cantidad(const char *pchrPtrCantidad)
{
  ActualizaCampo("Cantidad",(const unsigned char *)pchrPtrCantidad);
}

void zProductoCompra::DscProveedor(const char *pchrPtrDscProveedor)
{
  ActualizaCampo("DscProveedor",(const unsigned char *)pchrPtrDscProveedor);
}
void zProductoCompra::Precio(const char *pchrPtrPrecio)
{
   ActualizaCampo("Precio",(const unsigned char *)pchrPtrPrecio);
}
void zProductoCompra::PrecioTotal(const char *pchrPtrPrecioTotal)
{
   ActualizaCampo("PrecioTotal",(const unsigned char *)pchrPtrPrecioTotal);
}
const char *zProductoCompra::ClaveProveedor()
{
  return (const char *)(*this)["ClaveProveedor"];
}
const char *zProductoCompra::DscProveedor()
{
  return (const char *)(*this)["DscProveedor"];
}
const char *zProductoCompra::Precio()
{
  return (const char *)(*this)["Precio"];
}
const char *zProductoCompra::PrecioTotal()
{
  return (const char *)(*this)["PrecioTotal"];
}
