#include <zCosto.h>
#include <zSiscomCampo.h>


zCosto::zCosto(const char *pchrPtrIdCosto,
	       const char *pchrPtrCosto,
	       const char *pchrPtrCostoMIva,
	       const char *pchrPtrCostoIva,
	       const char *pchrPtrIva,
	       const char *pchrPtrFecha)
{
  (*this) << 
  new zSiscomCampo("idcostobruto",(unsigned char *)pchrPtrIdCosto)		<<
  new zSiscomCampo("costobruto",(unsigned char *)pchrPtrCosto)		<<
  new zSiscomCampo("costoneto",(unsigned char *)pchrPtrCostoMIva)  	<<
  new zSiscomCampo("iva",(unsigned char *)pchrPtrIva)			<<
  new zSiscomCampo("fecha",(unsigned char *)pchrPtrFecha)		<<
  new zSiscomCampo("Estatus");
}
const char *zCosto::CostoNeto()
{
	return (const char *)(*this)["costoneto"];
}
void zCosto::CostoNeto(const unsigned char *pchrPtrCosto)
{
  ActualizaCampo("costoneto",pchrPtrCosto);
}
