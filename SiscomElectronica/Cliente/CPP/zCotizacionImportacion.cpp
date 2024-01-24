#include <zCotizacionImportacion.h>
#include <zProductosCotImp.h> 
#include <zSiscomCampo.h>


#include <zSiscomDesarrollo4.h>

zCotizacionImportacion::zCotizacionImportacion()
{

  (*this) 									<<
  new zSiscomCampo("IdCotizacion")						<<
  new zSiscomCampo("Cotizacion")						<< 
  new zSiscomCampo("CostoDolar")						<<
  new zSiscomCampo("PesoTotal")							<<
  new zSiscomCampo("ImporteTotal")						<<
  new zSiscomCampo("Proveedor")							<<
  new zSiscomCampo("Productos");

}
zCotizacionImportacion::~zCotizacionImportacion()
{

}
void zCotizacionImportacion::CostoDolar(const char *pchrPtrCostoDolar)
{
    ActualizaCampo("CostoDolar",(const unsigned char *)pchrPtrCostoDolar);
}
void zCotizacionImportacion::Proveedor(zSiscomRegistro *pzSisRegProveedor)
{
    AsociadoAlCampo("Proveedor",pzSisRegProveedor);
}
void zCotizacionImportacion::Cotizacion(const char *pchrPtrCotizacion)
{
	ActualizaCampo("Cotizacion",(const unsigned char *)pchrPtrCotizacion);
}
void zCotizacionImportacion::IdCotizacion(const char *pchrPtrIdCotizacion)
{
	ActualizaCampo("IdCotizacion",(const unsigned char *)pchrPtrIdCotizacion);
}
void zCotizacionImportacion::PesoTotal(const char *pchrPtrPesoTotal)
{
	ActualizaCampo("PesoTotal",(const unsigned char *)pchrPtrPesoTotal);
}
void zCotizacionImportacion::ImporteTotal(const char *pchrPtrImporteTotal)
{
       ActualizaCampo("ImporteTotal",(const unsigned char *)pchrPtrImporteTotal);
}
void zCotizacionImportacion::Productos(zProductosCotImp *pzProdsCotImp)
{
      AsociadosAlCampo("Productos",pzProdsCotImp);
}
const char *zCotizacionImportacion::RazonSocial()
{
    return (const char *)CampoAsociado("Proveedor","RazonSocial");
}
const char *zCotizacionImportacion::Cotizacion()
{
      return (const char *)(*this)["Cotizacion"];
}

const char *zCotizacionImportacion::PesoTotal()
{
      return (const char *)(*this)["PesoTotal"];
}
const char *zCotizacionImportacion::ImporteTotal()
{
      return (const char *)(*this)["ImporteTotal"];
}
const char *zCotizacionImportacion::CostoDolar()
{
	return (const char *)(*this)["CostoDolar"];
}
zProductosCotImp *zCotizacionImportacion::Productos()
{
  return (zProductosCotImp *)AsociadosDelCampo("Productos");
}

zProductoCotImp *zCotizacionImportacion::Producto(int pintNProducto)
{
    return (zProductoCotImp *)(*Productos())[pintNProducto];
}
void zCotizacionImportacion::PesoTotalProducto(const char *pchrPtrCveProducto,
					       const char *pchrPtrPesoTotalProd)
{
   Productos()->PesoTotalProducto(pchrPtrCveProducto,pchrPtrPesoTotalProd); 
}


void zCotizacionImportacion::ImporteProducto(const char *pchrPtrCveProducto,
					       const char *pchrPtrPesoTotalProd)
{
   Productos()->ImporteProducto(pchrPtrCveProducto,pchrPtrPesoTotalProd); 
}
void zCotizacionImportacion::PesoTotalProductos(zSiscomRegistros *pzSisRegsProductos)
{
zSiscomRegistro *lzSisRegProducto;
for(lzSisRegProducto=pzSisRegsProductos->Primer();
    lzSisRegProducto;
    lzSisRegProducto=pzSisRegsProductos->Siguiente())
   PesoTotalProducto((const char *)(*lzSisRegProducto)["Clave"],
                     (const char *)(*lzSisRegProducto)["PesoTotal"]);
}


void zCotizacionImportacion::ImporteProductos(zSiscomRegistros *pzSisRegsProductos)
{
zSiscomRegistro *lzSisRegProducto;
for(lzSisRegProducto=pzSisRegsProductos->Primer();
    lzSisRegProducto;
    lzSisRegProducto=pzSisRegsProductos->Siguiente())
    ImporteProducto((const char *)(*lzSisRegProducto)["Clave"],
                     (const char *)(*lzSisRegProducto)["Importe"]);
}
void zCotizacionImportacion::Agrega(zProductosCotImp *pzProdsCotImp)
{
    if(!Productos())
    Productos(new zProductosCotImp);
    Productos()->Agrega(pzProdsCotImp);
}
void zCotizacionImportacion::Agrega(zSiscomRegistros *pzSisRegsProductos)
{
 	if(!Productos())
	  Productos(new zProductosCotImp);
	Productos()->Agrega(pzSisRegsProductos);
}
void zCotizacionImportacion::Agrega(zProductoCotImp *pzProdCotImp)
{
       if(!Productos())
	  Productos(new zProductosCotImp);
	Productos()->Agrega(pzProdCotImp);
}
