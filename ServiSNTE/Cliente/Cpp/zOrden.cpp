#include <zOrden.h>
#include <zProductos.h>
#include <zProducto.h>
#include <zSiscomCampo.h>
#include <zSiscomRegistros.h>
#include <zProductoTransferencia.h>
#include <zSiscomDesarrollo4.h>
zOrden::zOrden()
{
  (*this) 					<< 
  new zSiscomCampo("IdTipoVenta")		<<
  new zSiscomCampo("IdFinanciadora") 		<<
  new zSiscomCampo("IdPlazo") 		<<
   new zSiscomCampo("Total") 			<<
   new zSiscomCampo("Iva")   			<<
   new zSiscomCampo("SubTotal")  		<<
   new zSiscomCampo("Productos")		<<
   new zSiscomCampo("Credito");
}
void zOrden::Plazo(zSiscomRegistro *pzSisRegPlazo)
{
  ActualizaCampo("IdPlazo",(*pzSisRegPlazo)["idplazo"]);
}
void zOrden::TipoVenta(zSiscomRegistro *pzSisRegTipoVenta)
{
    ActualizaCampo("IdTipoVenta",(*pzSisRegTipoVenta)["idtipoventa"]);
}
void zOrden::Financiadora(zSiscomRegistro *pzSisRegFinanciadora)
{
  ActualizaCampo("IdFinanciadora",(*pzSisRegFinanciadora)["idfinanciadora"]);
}
void zOrden::Productos(zProductos *pzProdsOrden)
{
  AsociadosAlCampo("Productos",pzProdsOrden);
}
zProductos *zOrden::Productos()
{
 return (zProductos *)AsociadosDelCampo("Productos"); 
}
void zOrden::ActualizaImporteProductos(zSiscomRegistros *pzSisRegsProductos)
{
zSiscomRegistros *lzSisRegsProductos;
zSiscomRegistro *lzSisRegProducto,
		*lzSisRegProductoEntrada;
lzSisRegsProductos=AsociadosDelCampo("Productos");

for(lzSisRegProducto=lzSisRegsProductos->Primer(),
    lzSisRegProductoEntrada=pzSisRegsProductos->Primer();
    lzSisRegProducto;
    lzSisRegProducto=lzSisRegsProductos->Siguiente(),
    lzSisRegProductoEntrada=pzSisRegsProductos->Siguiente())
   lzSisRegProducto->ActualizaCampo("Importe",(*lzSisRegProductoEntrada)["Importe"]);
}
void zOrden::Credito(zSiscomRegistro *pzSisRegCredito)
{
zSiscomRegistros *lzSisRegsCredito=AsociadosDelCampo("Credito");
if(lzSisRegsCredito)
 lzSisRegsCredito->Libera();
  AsociadoAlCampo("Credito",pzSisRegCredito); 
}
zSiscomRegistro *zOrden::Credito()
{
zSiscomRegistros *lzSisRegsCredito=AsociadosDelCampo("Credito");
if(lzSisRegsCredito)
 return lzSisRegsCredito->Primer();
else
return 0;
}
void zOrden::AsignaCostoPrecioProducto(zSiscomRegistro *pzSisRegProducto)
{
zProductos *lzProductos=Productos();
zProducto *lzProducto;
for(lzProducto=(zProducto *)lzProductos->Primer();
    lzProducto;
    lzProducto=(zProducto *)lzProductos->Siguiente())
{
     if((*lzProducto)==(*(zProducto *)(pzSisRegProducto)))
     {
        lzProducto->ActualizaCampo("Precio",(*pzSisRegProducto)["Precio"]);
	lzProducto->ActualizaCampo("Costo",(*pzSisRegProducto)["Costo"]);
	lzProducto->ActualizaCampo("Importe",(*pzSisRegProducto)["Importe"]);
     }
}

}
void zOrden::AsignaCostoPrecioProductos(zSiscomRegistros *pzSisRegsProductos)
{
zSiscomRegistro *lzSisRegProducto;
for(lzSisRegProducto=pzSisRegsProductos->Primer();
    lzSisRegProducto;
    lzSisRegProducto=pzSisRegsProductos->Siguiente())
AsignaCostoPrecioProducto(lzSisRegProducto);
}
