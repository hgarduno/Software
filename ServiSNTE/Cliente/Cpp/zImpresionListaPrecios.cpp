#include <zImpresionListaPrecios.h>
#include <zListaPrecios.h>
#include <zSiscomCampo.h>
#include <string.h>
zImpresionListaPrecios::zImpresionListaPrecios(zListaPrecios *pzLstPrecios,
					       const char *pchrPtrNombre):
						zLstPrecios(pzLstPrecios)
{
Encabezado(pchrPtrNombre);
}


void zImpresionListaPrecios::Encabezado(const char *pchrPtrNombre)
{
   (*this) 									<< 
   RegistroEncabezado("Sistema","Sistema de control de tiendas") 		<<
   RegistroEncabezado("NombreSistema","SERVISNTE") 				<<
   RegistroEncabezado("ListaProductos",pchrPtrNombre) 			<<
   RegistroEncabezado("Fecha:","08-08-2016") 					<<
   RegistroEncabezado("Hora","8:00") 						<<
   RegistroEncabezado("Clave","Clave") 						<<
   RegistroEncabezado("NombreProducto","Nombre del producto") 			<<
   RegistroEncabezado("Modelo","Modelo") 					<<
   RegistroEncabezado("Stock","Stock") 						<<
   RegistroEncabezado("PrecioUnitario","Precio Unitario");

}
zSiscomRegistro *zImpresionListaPrecios::RegistroEncabezado(const char *pchrPtrCampo,
						   const char *pchrPtrDato)
{
 zSiscomRegistro *lzSisRegCampo;
 lzSisRegCampo=new zSiscomRegistro;
 (*lzSisRegCampo) << new zSiscomCampo(pchrPtrCampo,(const unsigned char *)pchrPtrDato);
 return lzSisRegCampo;
}
zListaPrecios *zImpresionListaPrecios::ListaPrecios()
{
 return zLstPrecios;
}
