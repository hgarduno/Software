#include <zImpresionSoporteTransferencias.h>
#include <zSoporteTransferencias.h>
#include <zSiscomCampo.h>
#include <string.h>
zImpresionSoporteTransferencias::zImpresionSoporteTransferencias(zSoporteTransferencias *pzSoporteTransferencias):
						zSptTransferencias(pzSoporteTransferencias)
{
Encabezado();
}


void zImpresionSoporteTransferencias::Encabezado()
{
   (*this) 								<< 
   RegistroEncabezado("Sistema","Transferencias.") 			<<
   RegistroEncabezado("NombreSistema","SERVISNTE") 			<<
   RegistroEncabezado("Fecha","08-08-2016") 				<<
   RegistroEncabezado("Hora","Hora:8:00") 				<<
   RegistroEncabezado("Concepto","Concepto")		 		<<
   RegistroEncabezado("Folio","Folio") 					<<
   RegistroEncabezado("Defecha","De fecha") 				<<
   RegistroEncabezado("Origen","Origen") 				<<
   RegistroEncabezado("Destino","Destino")				<<
   RegistroEncabezado("Camion","Camion")				<<
   RegistroEncabezado("Chofer","Chofer")				<<
   RegistroEncabezado("Sec","Sec")					<<
   RegistroEncabezado("Articulo","Articulo")				<<
   RegistroEncabezado("NombreProducto","Nombre del Producto")		<<
   RegistroEncabezado("Modelo","Modelo")				<<
   RegistroEncabezado("Nota","Nota")					<<
   RegistroEncabezado("Cant","Cant.")					<<
   RegistroEncabezado("CostoNeto","Costo/Neto")				<<
   RegistroEncabezado("Importe","Importe");	

}
zSiscomRegistro *zImpresionSoporteTransferencias::RegistroEncabezado(const char *pchrPtrCampo,
						   const char *pchrPtrDato)
{
 zSiscomRegistro *lzSisRegCampo;
 lzSisRegCampo=new zSiscomRegistro;
 (*lzSisRegCampo) << new zSiscomCampo(pchrPtrCampo,(const unsigned char *)pchrPtrDato);
 return lzSisRegCampo;
}
zSoporteTransferencias *zImpresionSoporteTransferencias::SoporteTransferencias()
{
 return zSptTransferencias;
}
