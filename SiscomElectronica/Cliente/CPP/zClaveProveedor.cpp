#include <zClaveProveedor.h>
#include <zSiscomCampo.h>

#include  <zEmpresa.h>
zClaveProveedor::zClaveProveedor():zProducto()
{
  (*this) 				<< 
  new zSiscomCampo("ClaveP")		<<
  new zSiscomCampo("DescripcionP")	<<
  new zSiscomCampo("Proveedor");
}
zClaveProveedor::zClaveProveedor(zSiscomRegistro *pzSisRegProducto)
{
  (*this) 								<<
  new zSiscomCampo("ClaveP",(*pzSisRegProducto)["cveproveedor"]) 	<<
  new zSiscomCampo("DescripcionP",(*pzSisRegProducto)["descripcion"]) 	<<
  new zSiscomCampo("Proveedor");
  ActualizaCampo("Clave",(*pzSisRegProducto)["cveproducto"]);

  Proveedor(pzSisRegProducto);
}
void zClaveProveedor::ClaveP(const char *pchrPtrClaveP)
{
  ActualizaCampo("ClaveP",(const unsigned char *)pchrPtrClaveP);
}
void zClaveProveedor::DescripcionP(const char *pchrPtrDescripcionP)
{
 ActualizaCampo("DescripcionP",(const unsigned char *)pchrPtrDescripcionP);
}
void zClaveProveedor::Proveedor(zSiscomRegistro *pzSisRegProveedor)
{
  AsociadoAlCampo("Proveedor",zEmpresa::DeConsultaEmpresas(pzSisRegProveedor)); 
}
const char *zClaveProveedor::ClaveP()
{
   return (const char *)(*this)["ClaveP"];

}
const char *zClaveProveedor::DescripcionP()
{
   return (const char *)(*this)["DescripcionP"];
}
