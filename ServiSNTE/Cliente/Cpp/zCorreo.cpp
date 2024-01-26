#include <zCorreo.h>
#include <zSiscomCampo.h>
zCorreo::zCorreo()
{
(*this)					<<
  new zSiscomCampo("IdCorreo")	<<
  new zSiscomCampo("Correo")		<<
  new zSiscomCampo("Descripcion");
}
zCorreo::zCorreo(zSiscomRegistro *pzSisRegCorreo)
{
(*this)								<<
  new zSiscomCampo("IdCorreo",(*pzSisRegCorreo)["idcorreo"])	<<
  new zSiscomCampo("Correo",(*pzSisRegCorreo)["correo"])	<<
  new zSiscomCampo("Descripcion");
}

void zCorreo::IdCorreo(const char *pchrPtrIdCorreo)
{
   ActualizaCampo("IdCorreo",(const unsigned char *)pchrPtrIdCorreo);
}

void zCorreo::Correo(const char *pchrPtrCorreo)
{
  ActualizaCampo("Correo",(const unsigned char *)pchrPtrCorreo);
}
void zCorreo::Descripcion(const char *pchrPtrDescripcion)
{
  ActualizaCampo("Descripcion",(const unsigned char *)pchrPtrDescripcion);
}
const char *zCorreo::Correo()
{
return (const char *)(*this)["Correo"];	
}
