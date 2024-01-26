#include <zCompra.h>
#include <zSiscomCampo.h>
#include <zOrden.h>
zCompra::zCompra()
{
(*this) 				<<
new zSiscomCampo("IdCompra")		<<
new zSiscomCampo("IdProveedor") 	<<
new zSiscomCampo("IdTipoDocumento")	<<
new zSiscomCampo("IdConcepto")	<<
new zSiscomCampo("SerieFactura")	<<
new zSiscomCampo("Folio")		<<
new zSiscomCampo("Fecha")		<<
new zSiscomCampo("Orden");

}

void zCompra::IdCompra(const unsigned char *pchrPtrIdCompra)
{
ActualizaCampo("IdCompra",pchrPtrIdCompra);
}
void zCompra::IdProveedor(const unsigned char *pchrPtrIdProveedor)
{
ActualizaCampo("IdProveedor",pchrPtrIdProveedor);
}

void zCompra::IdTipoDocumento(const unsigned char *pchrPtrIdTipoDocumento)
{
ActualizaCampo("IdTipoDocumento",pchrPtrIdTipoDocumento);
}

void zCompra::IdConcepto(const unsigned char *pchrPtrIdConcepto)
{
ActualizaCampo("IdConcepto",pchrPtrIdConcepto);
}
void zCompra::SerieFactura(const char *pchrPtrSerieFactura)
{
ActualizaCampo("SerieFactura",(const unsigned char *)pchrPtrSerieFactura);
}
void zCompra::Folio(const char *pchrPtrFolio)
{
ActualizaCampo("Folio",(const unsigned char *)pchrPtrFolio);
}
void zCompra::Fecha(const char *pchrPtrFecha)
{
ActualizaCampo("Fecha",(const unsigned char *)pchrPtrFecha);
}
void zCompra::Orden(zOrden *pzOrden)
{
 AsociadoAlCampo("Orden",pzOrden); 
}
