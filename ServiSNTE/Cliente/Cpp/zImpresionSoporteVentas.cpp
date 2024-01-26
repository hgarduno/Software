#include <zImpresionSoporteVentas.h>
#include <zSoporteVentas.h>
#include <zSiscomCampo.h>
#include <string.h>
zImpresionSoporteVentas::zImpresionSoporteVentas(zSoporteVentas *pzSoporteVentas):
						zSptVentas(pzSoporteVentas)
{
Encabezado();
}


void zImpresionSoporteVentas::Encabezado()
{
   (*this) 								<< 
   RegistroEncabezado("Sistema","Sistema Intregral de control de tiendas")	<<
   RegistroEncabezado("NombreSistema","SERVISNTE") 			<<
   RegistroEncabezado("Fecha","08-08-2016") 				<<
   RegistroEncabezado("Hora","Hora:8:00") 				<<
   RegistroEncabezado("Tienda","Tienda") 					<<
   RegistroEncabezado("Concepto","Concepto") 					<<
   RegistroEncabezado("PorProducto","Por Producto") 				<<
   RegistroEncabezado("Modelo","Modelo") 				<<
   RegistroEncabezado("Cant","Cant") 				<<
   RegistroEncabezado("CostoN","Costo/N")				<<
   RegistroEncabezado("ImporteC","Imp./C")				<<
   RegistroEncabezado("PrecioV","Precio/V")				<<
   RegistroEncabezado("ImporteC","Imp./V");
}

zSiscomRegistro *zImpresionSoporteVentas::RegistroEncabezado(const char *pchrPtrCampo,
						   const char *pchrPtrDato)
{
 zSiscomRegistro *lzSisRegCampo;
 lzSisRegCampo=new zSiscomRegistro;
 (*lzSisRegCampo) << new zSiscomCampo(pchrPtrCampo,(const unsigned char *)pchrPtrDato);
 return lzSisRegCampo;
}
zSoporteVentas *zImpresionSoporteVentas::SoporteVentas()
{
 return zSptVentas;
}
