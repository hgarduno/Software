#include <zImpresionStockTienda.h>
#include <zStockTienda.h>
#include <zSiscomCampo.h>
#include <string.h>
zImpresionStockTienda::zImpresionStockTienda(zStockTienda *pzStockTienda):
						zStkTienda(pzStockTienda),
						intImprimePrecio(0),
						intImprimeImporteVenta(0)
{
Encabezado();
}


void zImpresionStockTienda::Encabezado()
{
   (*this) 								<< 
   RegistroEncabezado("Sistema","Stockt por Tienda departamento y proveedor") 	<<
   RegistroEncabezado("NombreSistema","SERVISNTE") 			<<
   RegistroEncabezado("Tienda",(const char *)zStkTienda->Tienda()->Campo("nombre")) <<
   RegistroEncabezado("Fecha","08-08-2016") 				<<
   RegistroEncabezado("Hora","Hora:8:00") 					<<
   RegistroEncabezado("Clave","Clave") 					<<
   RegistroEncabezado("NombreProducto","Nombre del producto") 		<<
   RegistroEncabezado("Modelo","Modelo") 				<<
   RegistroEncabezado("Stock","Stock") 					<<
   RegistroEncabezado("Costo","Costo")					<<
   RegistroEncabezado("ImporteCosto","Imp. Costo")			<<
   RegistroEncabezado("Venta","Venta")					<<
   RegistroEncabezado("ImporteVenta","Imp. Venta");

}
zSiscomRegistro *zImpresionStockTienda::RegistroEncabezado(const char *pchrPtrCampo,
						   const char *pchrPtrDato)
{
 zSiscomRegistro *lzSisRegCampo;
 lzSisRegCampo=new zSiscomRegistro;
 (*lzSisRegCampo) << new zSiscomCampo(pchrPtrCampo,(const unsigned char *)pchrPtrDato);
 return lzSisRegCampo;
}
zStockTienda *zImpresionStockTienda::StockTienda()
{
 return zStkTienda;
}
void zImpresionStockTienda::ImprimePrecio(int pintImprimePrecio)
{
	intImprimePrecio=pintImprimePrecio;
}
void zImpresionStockTienda::ImprimeImporteVenta(int pintImprimeImporteVenta)
{
	intImprimeImporteVenta=pintImprimeImporteVenta;

}
int zImpresionStockTienda::ImprimePrecio()
{
	return intImprimePrecio;
}

int zImpresionStockTienda::ImprimeImporteVenta()
{
	return intImprimeImporteVenta;
}
