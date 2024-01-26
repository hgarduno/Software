#include <zImpresionStockProveedorCosto.h>
#include <zStockProveedorCosto.h>
#include <zSiscomCampo.h>
#include <string.h>
zImpresionStockProveedorCosto::zImpresionStockProveedorCosto(zStockProveedorCosto *pzStockProveedorCosto):
						zStkTienda(pzStockProveedorCosto)
{
Encabezado();
}


void zImpresionStockProveedorCosto::Encabezado()
{
   (*this) 									<< 
   RegistroEncabezado("Sistema","Stock por proveedor y tienda con Costo") 	<<
   RegistroEncabezado("Proveedor","Proveedor") 				<<
   RegistroEncabezado("NumeroProveedor","Proveedor")				 	<<
   RegistroEncabezado("Fecha","08/08/2016") 					<<
   RegistroEncabezado("Hora","Hora:10:00") 					<<
   RegistroEncabezado("Producto","Producto") 					<<
   RegistroEncabezado("Modelo","Modelo") 				<<
   RegistroEncabezado("Total","Costo")					<<
   RegistroEncabezado("Tienda","Tienda");
}
zSiscomRegistro *zImpresionStockProveedorCosto::RegistroEncabezado(const char *pchrPtrCampo,
						   const char *pchrPtrDato)
{
 zSiscomRegistro *lzSisRegCampo;
 lzSisRegCampo=new zSiscomRegistro;
 (*lzSisRegCampo) << new zSiscomCampo(pchrPtrCampo,(const unsigned char *)pchrPtrDato);
 return lzSisRegCampo;
}
zStockProveedorCosto *zImpresionStockProveedorCosto::StockProveedorCosto()
{
 return zStkTienda;
}
