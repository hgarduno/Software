#include <zDonacionMaterial.h>
#include <zSiscomCampo.h>
zDonacionMaterial::zDonacionMaterial(const char *pchrPtrExplicacion)
{

(*this) << 
new zSiscomCampo("Explicacion",(const unsigned char *)pchrPtrExplicacion);
}
