#include <zListaPrecios.h>
zListaPrecios::zListaPrecios()
{


}
int zListaPrecios::SiguienteProveedor()
{
   zSisRegProveedor=Siguiente();
   return zSisRegProveedor ? 1 : 0;
}
int zListaPrecios::PrimerProveedor()
{
  zSisRegProveedor=Primer();
   return zSisRegProveedor ? 1 : 0;
}
const char *zListaPrecios::NumeroProveedor()
{
  return (const char *)(*zSisRegProveedor)["idempresa"];
}
const char *zListaPrecios::RazonSocial()
{
  return (const char *)(*zSisRegProveedor)["razonsocial"];
}
zSiscomRegistros *zListaPrecios::Productos()
{
   return zSisRegDepartamento->AsociadosDelCampo("Productos");
}

int zListaPrecios::PrimerProducto()
{
    zSisRegProducto=zSisRegDepartamento->AsociadosDelCampo("Productos")->Primer();
    return zSisRegProducto ? 1 :0;
}

int zListaPrecios::SiguienteProducto()
{
    zSisRegProducto=zSisRegDepartamento->AsociadosDelCampo("Productos")->Siguiente();
    return zSisRegProducto ? 1 :0;
}
int zListaPrecios::PrimerDepartamento()
{
	zSisRegDepartamento=Primer();
	return zSisRegDepartamento ? 1 : 0;


}
int zListaPrecios::SiguienteDepartamento()
{ 
	zSisRegDepartamento=Siguiente();
	return zSisRegDepartamento ? 1 : 0;
}
const char *zListaPrecios::Numero()
{
   return (const char *)(*zSisRegProducto)["numproducto"];
}

const char *zListaPrecios::Nombre()
{
   return (const char *)(*zSisRegProducto)["nombreproducto"];
}
const char *zListaPrecios::Modelo()
{
   return (const char *)(*zSisRegProducto)["modelo"];
}
const char *zListaPrecios::PrecioGeneral()
{
   return (const char *)(*zSisRegProducto)["preciogeneral"];
}
const char *zListaPrecios::Stock()
{
   return (const char *)(*zSisRegProducto)["stock"];
}

const char *zListaPrecios::IdDepartamento()
{
   return (const char *)(*zSisRegDepartamento)["iddepartamento"];
}
const char *zListaPrecios::NombreDepartamento()
{
   return (const char *)(*zSisRegDepartamento)["nombredepto"];
}
zSiscomRegistro *zListaPrecios::Proveedor()
{
  return zSisRegProveedor;
}
zSiscomRegistro *zListaPrecios::Producto()
{
  return zSisRegProducto; 
}
zSiscomRegistro *zListaPrecios::Departamento()
{
  return zSisRegDepartamento; 
}

