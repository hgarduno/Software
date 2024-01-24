#include <zEstante.h>
#include <zSiscomCampo.h>


zEstante::zEstante()
{
  (*this) << 
  new zSiscomCampo("IdEstante") <<
  new zSiscomCampo("Estante")	<<
  new zSiscomCampo("Descripcion") ;
}
zEstante::zEstante(zSiscomRegistro *pzSisRegRegistro)
{
  (*this) << 
  new zSiscomCampo("IdEstante") <<
  new zSiscomCampo("Estante")	<<
  new zSiscomCampo("Descripcion") ;
  IdEstante((const char *)(*pzSisRegRegistro)["idestante"]);
  Estante((const char *)(*pzSisRegRegistro)["estante"]);
}
void zEstante::IdEstante(const char *pchrPtrIdEstante)
{
     ActualizaCampo("IdEstante",(const unsigned char *)pchrPtrIdEstante);
}
void zEstante::Estante(const char *pchrPtrEstante)
{
    ActualizaCampo("Estante",(const unsigned char *)pchrPtrEstante);
}
const char *zEstante::Estante()
{
   return (const char *)Campo("Estante");
}
const char *zEstante::IdEstante()
{
   return (const char *)Campo("IdEstante");
}
