#include <zProducto.h>
#include <zSiscomCampo.h>

#include <zSiscomDesarrollo4.h>
#include <string.h>
zProducto::zProducto(const char *pchrPtrClave)
{
   (*this) << new zSiscomCampo("Clave",(const unsigned char *)pchrPtrClave);
}
zProducto::zProducto()
{
 (*this) 				<< 
 new zSiscomCampo("Clave") 		<<
 new zSiscomCampo("Descripcion");
}
zProducto::zProducto(zSiscomRegistro *pzSisRegProducto)
{
  (*this) 									<<
  new zSiscomCampo("Clave",(*pzSisRegProducto)["cveproducto"])			<<
  new zSiscomCampo("Descripcion",(*pzSisRegProducto)["dscproducto"])		<<
  new zSiscomCampo("Existencia",(*pzSisRegProducto)["existencia"])		<< 
  new zSiscomCampo("ExiBodega",(*pzSisRegProducto)["exbodegas"])	        <<
  new zSiscomCampo("TipoProducto",(*pzSisRegProducto)["idtipoproducto"])	<<
  new zSiscomCampo("IdProducto",(*pzSisRegProducto)["idproducto"])		<<
  new zSiscomCampo("IdCaja",(*pzSisRegProducto)["idcaja"])			<<
  new zSiscomCampo("Caja",(*pzSisRegProducto)["caja"])				<<
  new zSiscomCampo("Estante",(*pzSisRegProducto)["estante"])			<<
  new zSiscomCampo("Productos");
}

void zProducto::Clave(const char *pchrPtrClave)
{
    ActualizaCampo("Clave",(const unsigned char *)pchrPtrClave);
}
void zProducto::Descripcion(const char *pchrPtrDescripcion)
{
 ActualizaCampo("Descripcion",(const unsigned char *)pchrPtrDescripcion);
}
void zProducto::ExiBodega(const char *pchrPtrExiBodega)
{
    ActualizaCampo("ExiBodega",(const unsigned char *)pchrPtrExiBodega);
}
void zProducto::DefinicionProducto(zSiscomRegistros *pzSisRegsDefinicion)
{
   AsociadosAlCampo("Productos",pzSisRegsDefinicion); 
}
const char *zProducto::Clave()
{
   return (const char *)(*this)["Clave"];
}
const char *zProducto::Descripcion()
{
  return (const char *)(*this)["Descripcion"];
}
const char *zProducto::TipoProducto()
{
  return (const char *)(*this)["TipoProducto"];
}
const char *zProducto::Existencia()
{
  return (const char *)(*this)["Existencia"];
}
const char *zProducto::ExiBodega()
{
   return (const char *)(*this)["ExiBodega"];
}
int zProducto::TipoProductoInt()
{
   return CampoInt("TipoProducto");
}
const char *zProducto::IdCaja()
{
   return (const char *)(*this)["IdCaja"];
}
const char *zProducto::Caja()
{
   return (const char *)(*this)["Caja"];
}
zSiscomRegistros *zProducto::DefinicionProducto()
{
   return AsociadosDelCampo("Productos");
}
bool zProducto::operator==(const char *pchrPtrCveProducto)
{
    return !strcmp((const char *)(*this)["Clave"],pchrPtrCveProducto);
}
bool zProducto::operator==(zSiscomRegistro *pzSisRegProducto)
{
    return !strcmp((const char *)(*this)["Clave"],(const char *)(*pzSisRegProducto)["Clave"]);
}
