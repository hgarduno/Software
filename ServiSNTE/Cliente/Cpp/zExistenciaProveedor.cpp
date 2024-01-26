#include <zExistenciaProveedor.h>
zExistenciaProveedor::zExistenciaProveedor()
{

}
const char *zExistenciaProveedor::NumeroProducto()
{
   return (const char *)(*zSisRegProducto)["numproducto"];
}

const char *zExistenciaProveedor::NombreProducto()
{
   return (const char *)(*zSisRegProducto)["nombreproducto"];
}
const char *zExistenciaProveedor::Modelo()
{
   return (const char *)(*zSisRegProducto)["modelo"];
}

const char *zExistenciaProveedor::TotalStock()
{
   return (const char *)(*zSisRegProducto)["Stock"];
}
const char *zExistenciaProveedor::TotalExistencia()
{
   return (const char *)(*zSisRegProducto)["Existencia"];
}
const char *zExistenciaProveedor::CostoTotal()
{
   return (const char *)(*zSisRegProducto)["Costo"];
}
zSiscomRegistro *zExistenciaProveedor::Producto()
{
   return zSisRegProducto;
}

const char *zExistenciaProveedor::IdTienda()
{
   return (const char *)(*zSisRegTienda)["idtienda"];

}
const char *zExistenciaProveedor::Nombre()
{
   return (const char *)(*zSisRegTienda)["nombre"];
}
const char *zExistenciaProveedor::Siglas()
{
   return (const char *)(*zSisRegTienda)["siglas"];
}
zSiscomRegistro *zExistenciaProveedor::Tienda()
{
   return zSisRegTienda;
}
const char *zExistenciaProveedor::Stock()
{ 
return (const char *)(*zSisRegTienda)["stock"];
}
const char *zExistenciaProveedor::Existencia()
{
return (const char *)(*zSisRegTienda)["existencia"];
}
int zExistenciaProveedor::PrimerProducto()
{
  zSisRegProducto=Primer();
  return zSisRegProducto ? 1 : 0;
}


int zExistenciaProveedor::SiguienteProducto()
{
  zSisRegProducto=Siguiente();
  return zSisRegProducto ? 1 : 0;
}
int zExistenciaProveedor::SiguienteTienda()
{
  zSisRegTienda=zSisRegProducto->AsociadosDelCampo("DatosExistencia")->Siguiente();
  return zSisRegTienda ? 1 :0 ;
}

int zExistenciaProveedor::PrimerTienda()
{
  zSisRegTienda=zSisRegProducto->AsociadosDelCampo("DatosExistencia")->Primer();
  return zSisRegTienda ? 1 :0 ;
}
int zExistenciaProveedor::NTiendas()
{
  return zSisRegProducto->AsociadosDelCampo("DatosExistencia")->NNodos();
}

void zExistenciaProveedor::Proveedor(zSiscomRegistro *pzSisRegProveedor)
{
   zSisRegProveedor=pzSisRegProveedor;
}
zSiscomRegistro *zExistenciaProveedor::Proveedor()
{
	return zSisRegProveedor;
}

