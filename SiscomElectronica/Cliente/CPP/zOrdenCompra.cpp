#include <zOrdenCompra.h>
#include <zSiscomCampo.h>
#include <zEmpresa.h>
zOrdenCompra::zOrdenCompra()
{
  (*this) 		<<
  new zSiscomCampo("IdCompra")	<<
  new zSiscomCampo("Proveedor")	<<
  new zSiscomCampo("Productos");
}
