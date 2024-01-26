#include <zImpresionSoporteCompras.h>
#include <zSoporteCompras.h>
#include <zSiscomCampo.h>
#include <string.h>
zImpresionSoporteCompras::zImpresionSoporteCompras(zSoporteCompras *pzSoporteCompras):
						zSopComp(pzSoporteCompras)
{
Encabezado();
}


void zImpresionSoporteCompras::Encabezado()
{
   (*this) 								<< 
   RegistroEncabezado("Sistema","Relacion de Cheques a Pagar")	 	<<
   RegistroEncabezado("NombreSistema","SERVISNTE") 			<<
   RegistroEncabezado("Fecha","08-08-2016") 				<<
   RegistroEncabezado("Hora","Hora:8:00") 				<<
   RegistroEncabezado("Par","Par") 					<<
   RegistroEncabezado("Prod","Producto") 				<<
   RegistroEncabezado("Mod","Modelo") 					<<
   RegistroEncabezado("Cant","Cantidad") 				<<
   RegistroEncabezado("CostoN","Costo/N")				<<
   RegistroEncabezado("ImporteC","Imp./C")				<<
   RegistroEncabezado("PrecioV","Precio/V")				<<
   RegistroEncabezado("ImporteC","Imp./V");
}

zSiscomRegistro *zImpresionSoporteCompras::RegistroEncabezado(const char *pchrPtrCampo,
						   const char *pchrPtrDato)
{
 zSiscomRegistro *lzSisRegCampo;
 lzSisRegCampo=new zSiscomRegistro;
 (*lzSisRegCampo) << new zSiscomCampo(pchrPtrCampo,(const unsigned char *)pchrPtrDato);
 return lzSisRegCampo;
}
zSoporteCompras *zImpresionSoporteCompras::SoporteCompras()
{
 return zSopComp;
}
