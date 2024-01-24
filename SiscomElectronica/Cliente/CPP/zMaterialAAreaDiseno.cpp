#include <zMaterialAAreaDiseno.h>
#include <zSiscomCampo.h>
zMaterialAAreaDiseno::zMaterialAAreaDiseno(const char *pchrPtrExplicacion)
{
  (*this) <<
  new zSiscomCampo("Explicacion",(const unsigned char *)pchrPtrExplicacion);
}
