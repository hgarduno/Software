#include <zImpresionExistenciaTiendaProveedor.h>
#include <zExistenciaTiendaProveedor.h>
#include <zSiscomCampo.h>
#include <string.h>
zImpresionExistenciaTiendaProveedor::zImpresionExistenciaTiendaProveedor(zExistenciaTiendaProveedor *pzExistenciaTiendaProveedor):
						zExtTiendaProveedor(pzExistenciaTiendaProveedor)
{
Encabezado();
}


void zImpresionExistenciaTiendaProveedor::Encabezado()
{
   (*this) 								<< 
   RegistroEncabezado("Sistema","Existencias por tienda y proveedor") 	<<
   RegistroEncabezado("NombreSistema","SERVISNTE") 			<<
   RegistroEncabezado("Tienda","Tienda")			        <<
   RegistroEncabezado("Fecha","08-08-2016") 				<<
   RegistroEncabezado("Hora","Hora:8:00") 				<<
   RegistroEncabezado("Producto","Nombre del producto") 		<<
   RegistroEncabezado("Modelo","Modelo") 				<<
   RegistroEncabezado("CostoUStk","Costo U. Stk.") 			<<
   RegistroEncabezado("Prop","Prop") 					<<
   RegistroEncabezado("ImporteCosto","Imp. Costo")			<<
   RegistroEncabezado("ImporteVenta","Imp. Venta")			<<
   RegistroEncabezado("Status","Status");	

}
zSiscomRegistro *zImpresionExistenciaTiendaProveedor::RegistroEncabezado(const char *pchrPtrCampo,
						   const char *pchrPtrDato)
{
 zSiscomRegistro *lzSisRegCampo;
 lzSisRegCampo=new zSiscomRegistro;
 (*lzSisRegCampo) << new zSiscomCampo(pchrPtrCampo,(const unsigned char *)pchrPtrDato);
 return lzSisRegCampo;
}
zExistenciaTiendaProveedor *zImpresionExistenciaTiendaProveedor::ExistenciaTiendaProveedor()
{
 return zExtTiendaProveedor;
}
