#include <zOrdenFavorita.h>
#include <zSiscomCampo.h>
zOrdenFavorita::zOrdenFavorita()
{
  (*this)			<< 
  new zSiscomCampo("IdOrden") 	<<
  new zSiscomCampo("Texto") ;
}
void zOrdenFavorita::IdOrden(const char *pchrPtrIdOrden)
{
    ActualizaCampo("IdOrden",(const unsigned char *)pchrPtrIdOrden);
}

void zOrdenFavorita::Texto(const char *pchrPtrTexto)
{
    ActualizaCampo("Texto",(const unsigned char *)pchrPtrTexto);
}
const char *zOrdenFavorita::Texto()
{
   return (const char *)(*this)["Texto"];
}
const char *zOrdenFavorita::IdOrden()
{
   return (const char *)(*this)["IdOrden"];
}
  
