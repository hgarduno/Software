#include <zCobertura.h>
#include <zSiscomCampo.h>
#include <string.h>
zCobertura::zCobertura(zSiscomRegistro *pzSisRegRegreso)
{
(*this) 								<< 
new zSiscomCampo("IdCobertura",(*pzSisRegRegreso)["idcobertura"]) 	<<
new zSiscomCampo("Cp",(*pzSisRegRegreso)["cp"])				<<
new zSiscomCampo("Municipio",(*pzSisRegRegreso)["municipio"])		<<
new zSiscomCampo("Estado",(*pzSisRegRegreso)["estado"])			<<
new zSiscomCampo("Cobertura",(*pzSisRegRegreso)["cobertura"])		<<
new zSiscomCampo("Dias",(*pzSisRegRegreso)["dias"])			<<
new zSiscomCampo("Tarifa",(*pzSisRegRegreso)["tarifa"]);
}
int zCobertura::Cobertura()
{
  return !strcmp(CampoConstChar("Cobertura"),"si");
}
const char *zCobertura::Cp()
{
   return CampoConstChar("Cp");
}
const char *zCobertura::Municipio()
{
  return CampoConstChar("Municipio");
}
const char *zCobertura::Estado()
{
  return CampoConstChar("Estado");
}
const char *zCobertura::Dias()
{
   return CampoConstChar("Dias");
}
const char *zCobertura::Tarifa()
{
   return CampoConstChar("Tarifa");
}
