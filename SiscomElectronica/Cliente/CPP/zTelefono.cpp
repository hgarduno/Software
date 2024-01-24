#include <zTelefono.h>
#include <zSiscomCampo.h>
zTelefono::zTelefono(const char *pchrPtrIdTelefono,
		     const char *pchrPtrTelefono)
{
(*this) 								<<
new zSiscomCampo("IdTelefono",(const unsigned char *)pchrPtrIdTelefono) <<
new zSiscomCampo("Telefono",(const unsigned char *)pchrPtrTelefono);
}
zTelefono::zTelefono(zSiscomRegistro *pzSisRegRegreso)
{
(*this) 						<<
new zSiscomCampo("IdTelefono") 				<<
new zSiscomCampo("Telefono",(*pzSisRegRegreso)["telefono"]);

}
const char *zTelefono::Telefono()
{
  return (const char *)(*this)["Telefono"];
}
