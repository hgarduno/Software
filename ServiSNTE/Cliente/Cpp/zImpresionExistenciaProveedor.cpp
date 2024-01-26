#include <zImpresionExistenciaProveedor.h>
#include <zExistenciaProveedor.h>
#include <zSiscomCampo.h>
#include <string.h>
zImpresionExistenciaProveedor::zImpresionExistenciaProveedor(zExistenciaProveedor *pzExistenciaProveedor):
						zStkTienda(pzExistenciaProveedor),
						intImprimePrecio(0),
						intImprimeImporteVenta(0)
{
Encabezado();
}


void zImpresionExistenciaProveedor::Encabezado()
{
   (*this) 									<< 
   RegistroEncabezado("Sistema","Existencia Proveedor") 			<<
   RegistroEncabezado("NombreSistema","SERVISNTE") 				<<
   RegistroEncabezado("Fecha","08-08-2016") 					<<
   RegistroEncabezado("Hora","Hora:8:00") 					<<
   RegistroEncabezado("Tda","Tienda") 						<<
   RegistroEncabezado("NombreTienda","Nombre de la Tienda") 			<<
   RegistroEncabezado("Stk","Stk") 						<<
   RegistroEncabezado("Existencia","Existencia") 				<<
   RegistroEncabezado("ImpCosto","Imp. Costo") 					<<
   RegistroEncabezado("ImpVenta","Imp. Venta");
}
zSiscomRegistro *zImpresionExistenciaProveedor::RegistroEncabezado(const char *pchrPtrCampo,
						   const char *pchrPtrDato)
{
 zSiscomRegistro *lzSisRegCampo;
 lzSisRegCampo=new zSiscomRegistro;
 (*lzSisRegCampo) << new zSiscomCampo(pchrPtrCampo,(const unsigned char *)pchrPtrDato);
 return lzSisRegCampo;
}
zExistenciaProveedor *zImpresionExistenciaProveedor::ExistenciaProveedor()
{
 return zStkTienda;
}
void zImpresionExistenciaProveedor::ImprimePrecio(int pintImprimePrecio)
{
	intImprimePrecio=pintImprimePrecio;
}
void zImpresionExistenciaProveedor::ImprimeImporteVenta(int pintImprimeImporteVenta)
{
	intImprimeImporteVenta=pintImprimeImporteVenta;

}
int zImpresionExistenciaProveedor::ImprimePrecio()
{
	return intImprimePrecio;
}

int zImpresionExistenciaProveedor::ImprimeImporteVenta()
{
	return intImprimeImporteVenta;
}
