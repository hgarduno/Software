#include <zCambioCaja.h>
#include <zSiscomCampo.h>

zCambioCaja::zCambioCaja(const char *pchrPtrFecha)
{
(*this) 							<< 
new zSiscomCampo("Fecha",(const unsigned char *)pchrPtrFecha)	<<
new zSiscomCampo("IdCambioCaja")				<<
new zSiscomCampo("Importe")					<<
new zSiscomCampo("Dinero");
}

zCambioCaja::zCambioCaja(zSiscomRegistro *pzSisRegCambioCaja)
{
(*this)									<<
new zSiscomCampo("Fecha",(*pzSisRegCambioCaja)["fecha"])		<<
new zSiscomCampo("Importe",(*pzSisRegCambioCaja)["importe"])		<<
new zSiscomCampo("IdCambioCaja",(*pzSisRegCambioCaja)["idcambiocaja"])	<<
new zSiscomCampo("Dinero");
}

const char *zCambioCaja::Fecha()
{
return (const char *)Campo("Fecha");
}
const char *zCambioCaja::Importe()
{
return (const char *)Campo("Importe");
}

const char *zCambioCaja::IdCambioCaja()
{
return (const char *)Campo("IdCambioCaja");
}
zDenominaciones *zCambioCaja::Dinero()
{
  return (zDenominaciones *)AsociadosDelCampo("Dinero");
}
void zCambioCaja::Dinero(zDenominaciones *pzDenominaciones)
{
     AsociadosAlCampo("Dinero",(zSiscomRegistros *)pzDenominaciones);
}
