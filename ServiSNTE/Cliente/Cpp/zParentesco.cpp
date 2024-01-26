#include <zParentesco.h>
#include <zSiscomCampo.h>
zParentesco::zParentesco()
{
(*this)					<<
new zSiscomCampo("IdReferencia")	<<
new zSiscomCampo("Parentesco");
}

void zParentesco::Parentesco(const char *pchrPtrParentesco)
{
 ActualizaCampo("Parentesco",(const unsigned char *)pchrPtrParentesco);
}
