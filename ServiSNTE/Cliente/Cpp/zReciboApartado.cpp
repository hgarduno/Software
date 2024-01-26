#include <zReciboApartado.h>
#include <zProductos.h>
#include <zSiscomCampo.h>
#include <zSiscomRegistros.h>

zReciboApartado::zReciboApartado() 
{
  (*this) <<
   new zSiscomCampo("Folio")       		<< 
   new zSiscomCampo("Tienda") 		<<
   new zSiscomCampo("Fecha") 			<<
   new zSiscomCampo("Apartado") 		<<
   new zSiscomCampo("Cliente") 		<<
   new zSiscomCampo("Importe")     		<<
   new zSiscomCampo("ImporteLetra")     	<<
   new zSiscomCampo("Concepto")     		<<
   new zSiscomCampo("Elaboro")		<<
   new zSiscomCampo("FolioApartado");
}

void zReciboApartado::Folio(const char *pchrPtrFolio)
{
    ActualizaCampo("Folio",(const unsigned char *)pchrPtrFolio);
}

void zReciboApartado::Tienda(const char *pchrPtrTienda)
{
    ActualizaCampo("Tienda",(const unsigned char *)pchrPtrTienda);
}

void zReciboApartado::Fecha(const char *pchrPtrFecha)
{
    ActualizaCampo("Fecha",(const unsigned char *)pchrPtrFecha);
}

void zReciboApartado::Apartado(const char *pchrPtrApartado)
{
    ActualizaCampo("Apartado",(const unsigned char *)pchrPtrApartado);
}

void zReciboApartado::Cliente(const char *pchrPtrCliente)
{
    ActualizaCampo("Cliente",(const unsigned char *)pchrPtrCliente);
}

void zReciboApartado::Importe(const char *pchrPtrImporte)
{
    ActualizaCampo("Importe",(const unsigned char *)pchrPtrImporte);
}

void zReciboApartado::ImporteLetra(const char *pchrPtrImporteLetra)
{
    ActualizaCampo("ImporteLetra",(const unsigned char *)pchrPtrImporteLetra);
}

void zReciboApartado::Concepto(const char *pchrPtrConcepto)
{
    ActualizaCampo("Concepto",(const unsigned char *)pchrPtrConcepto);
}

void zReciboApartado::Elaboro(const char *pchrPtrElaboro)
{
    ActualizaCampo("Elaboro",(const unsigned char *)pchrPtrElaboro);
}
void zReciboApartado::FolioApartado(const char *pchrPtrFolioApartado)
{
   ActualizaCampo("FolioApartado",(const unsigned char *)pchrPtrFolioApartado);
}


