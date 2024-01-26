#include <zProductoTransferencia.h>
#include <zSiscomCampo.h>
zProductoTransferencia::zProductoTransferencia(zSiscomRegistro *pzSisRegProducto):
			zProducto(pzSisRegProducto)
{
  (*this)				<<
  new zSiscomCampo("Cantidad") 		<<
  new zSiscomCampo("Stock")		<<
  new zSiscomCampo("Observacion")	<<
  new zSiscomCampo("Precio")		<<
  new zSiscomCampo("Costo")		<<
  new zSiscomCampo("Importe");

}
void zProductoTransferencia::Cantidad(const char *pchrPtrCantidad)
{
  ActualizaCampo("Cantidad",(const unsigned char *)pchrPtrCantidad);
}


void zProductoTransferencia::Stock(const char *pchrPtrStock)
{
  ActualizaCampo("Stock",(const unsigned char *)pchrPtrStock);
}
void zProductoTransferencia::Observacion(const char *pchrPtrObservacion)
{
  ActualizaCampo("Observacion",(const unsigned char *)pchrPtrObservacion);
}
const char *zProductoTransferencia::Stock()
{
  return (const char *)(*this)["Stock"];
}
