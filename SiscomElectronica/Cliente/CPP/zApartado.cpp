#include <zApartado.h>
#include <zSiscomCampo.h>
zApartado::zApartado(const char *pchrPtrACuenta,
		     const char *pchrPtrFechaHoraEntrega,
		     const char *pchrPtrObservaciones)
{
  (*this)  										<< 
  new zSiscomCampo("ACuenta",(const unsigned char *)pchrPtrACuenta) 			<<
  new zSiscomCampo("FechaHoraE",(const unsigned char *)pchrPtrFechaHoraEntrega)		<<
  new zSiscomCampo("PorPagar")								<<
  new zSiscomCampo("Observaciones",(const unsigned char *)pchrPtrObservaciones)		<<
  new zSiscomCampo("Abonos");
  
}

zApartado::zApartado(zSiscomRegistro *pzSisRegApartado)
{
  (*this)  								<< 
  new zSiscomCampo("ACuenta",(*pzSisRegApartado)["acuenta"]) 		<<
  new zSiscomCampo("FechaHoraE",(*pzSisRegApartado)["fechaentrega"])	<<
  new zSiscomCampo("PorPagar",(*pzSisRegApartado)["porpagar"])		<<
  new zSiscomCampo("Observaciones",(*pzSisRegApartado)["observaciones"]);
}

const char *zApartado::ACuenta()
{
  return (const char *)(*this)["ACuenta"];
}
const char *zApartado::Observaciones()
{
  return (const char *)(*this)["Observaciones"];
}

const char *zApartado::FechaHoraE()
{
  return (const char *)(*this)["FechaHoraE"];
}


const char *zApartado::PorPagar()
{
  return (const char *)(*this)["PorPagar"];
}
