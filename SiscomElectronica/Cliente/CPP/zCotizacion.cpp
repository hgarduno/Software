#include <zCotizacion.h>
#include <zSiscomCampo.h> 

zCotizacion::zCotizacion()
{
  (*this)		<<
  new zSiscomCampo("Descripcion");
}
zCotizacion::zCotizacion(zSiscomRegistro *pzSisRegCotizacion)
{
  (*this)							<<
  new zSiscomCampo("Descripcion",(*pzSisRegCotizacion)["descripcion"]);
}
void zCotizacion::Descripcion(const char *pchrPtrDescripcion)
{
  ActualizaCampo("Descripcion",(const unsigned char *)pchrPtrDescripcion);
}
const char *zCotizacion::Descripcion()
{
   return (const char *)(*this)["Descripcion"];
}
int zCotizacion::DescripcionValida()
{
   return (const char *)(*this)["Descripcion"] ? 1 : 0;
}
