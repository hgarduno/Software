#include <zStockTienda.h>
zStockTienda::zStockTienda()
{

}
int zStockTienda::SiguienteProveedor()
{
   zSisRegProveedor=Siguiente(); 
   return zSisRegProveedor ? 1 : 0;
}
int zStockTienda::PrimerProveedor()
{
  zSisRegProveedor=Primer(); 
   return zSisRegProveedor ? 1 : 0;
}
const char *zStockTienda::NumeroProveedor()
{
  return (const char *)(*zSisRegProveedor)["idempresa"];
}
const char *zStockTienda::RazonSocial()
{
  return (const char *)(*zSisRegProveedor)["razonsocial"];
}
const char *zStockTienda::TotalProveedor()
{
  return (const char *)(*zSisRegProveedor)["TotalProveedor"];
}
zSiscomRegistros *zStockTienda::Productos()
{
   return zSisRegProveedor->AsociadosDelCampo("Productos");
}

int zStockTienda::PrimerProducto()
{
    zSisRegProducto=zSisRegProveedor->AsociadosDelCampo("Productos")->Primer();
    return zSisRegProducto ? 1 :0;
}

int zStockTienda::SiguienteProducto()
{
    zSisRegProducto=zSisRegProveedor->AsociadosDelCampo("Productos")->Siguiente();
    return zSisRegProducto ? 1 :0;
}
const char *zStockTienda::Numero()
{
   return (const char *)(*zSisRegProducto)["numproducto"];
}

const char *zStockTienda::Nombre()
{
   return (const char *)(*zSisRegProducto)["nombreproducto"];
}
const char *zStockTienda::Modelo()
{
   return (const char *)(*zSisRegProducto)["modelo"];
}
const char *zStockTienda::CostoNeto()
{
   return (const char *)(*zSisRegProducto)["costoneto"];
}
const char *zStockTienda::ImporteCosto()
{
   return (const char *)(*zSisRegProducto)["importecosto"];
}
const char *zStockTienda::Stock()
{
   return (const char *)(*zSisRegProducto)["stock"];
}
const char *zStockTienda::Precio()
{
    return (const char *)(*zSisRegProducto)["preciogeneral"];
}
const char *zStockTienda::ImporteVenta()
{
    return (const char *)(*zSisRegProducto)["importeventa"];
}
zSiscomRegistro *zStockTienda::Tienda()
{
   return zSisRegTienda;
}
zSiscomRegistro *zStockTienda::Proveedor()
{
   return zSisRegProveedor;
}
zSiscomRegistro *zStockTienda::Producto()
{
 return zSisRegProducto;
}
void zStockTienda::Tienda(zSiscomRegistro *pzSisRegTienda)
{
   zSisRegTienda=pzSisRegTienda;
}
