#include <zApartado.h>
#include <zSiscomCampo.h>
zApartado::zApartado(const char *pchrPtrACuenta,
		     const char *pchrPtrFechaHoraEntrega,
		     const char *pchrPtrObservaciones)
{
  (*this)  										<< 
  new zSiscomCampo("ACuenta",(const unsigned char *)pchrPtrACuenta) 			<<
  new zSiscomCampo("FechaHoraE",(const unsigned char *)pchrPtrFechaHoraEntrega)		<<
  new zSiscomCampo("Observaciones",(const unsigned char *)pchrPtrObservaciones);
}
const char *zApartado::ACuenta()
{
  return (const char *)(*this)["ACuenta"];
}
