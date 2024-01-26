#include <zReferenciasPersonales.h>
#include <zDireccion.h>
#include <zPersona.h>
#include <zParentesco.h>
#include <zTelefonos.h>
#include <zSiscomCampo.h>
#include <zSiscomRegistros.h>
#include <zSiscomDesarrollo4.h>
zReferenciasPersonales::zReferenciasPersonales(const char *pchrPtrIdCliente)
{
 (*this)								<<
 new zSiscomCampo("IdPersona",(const unsigned char *)pchrPtrIdCliente)	<<
 new zSiscomCampo("IdReferencia")					<<
 new zSiscomCampo("Direcciones")					<<
 new zSiscomCampo("Nombres")						<<
 new zSiscomCampo("Parentesco")					<<
 new zSiscomCampo("Telefonos");
}
zReferenciasPersonales::zReferenciasPersonales(zSiscomRegistros *pzSisRegsReferencias)
{
zSiscomRegistro *lzSisRegReferencia;
Campos();
for(lzSisRegReferencia=pzSisRegsReferencias->Primer();
    lzSisRegReferencia;
    lzSisRegReferencia=pzSisRegsReferencias->Siguiente())
{
 AsociadoAlCampo("Direcciones",new zDireccion(lzSisRegReferencia));
 AsociadoAlCampo("Nombres",new zPersona(lzSisRegReferencia));
 AsociadoAlCampo("Telefonos",zTelefonos().DesdeDatosEmpleo(lzSisRegReferencia));
}
}
void zReferenciasPersonales::Campos()
{
 (*this)								<<
 new zSiscomCampo("IdPersona")					<<
 new zSiscomCampo("IdReferencia")					<<
 new zSiscomCampo("Direcciones")					<<
 new zSiscomCampo("Nombres")						<<
 new zSiscomCampo("Parentesco")					<<
 new zSiscomCampo("Telefonos");
}
void zReferenciasPersonales::Direccion(zDireccion *pzDireccion)
{
  AsociadoAlCampo("Direcciones",pzDireccion);
}
void zReferenciasPersonales::Nombre(zPersona *pzPersona)
{
  AsociadoAlCampo("Nombres",pzPersona);
}
void zReferenciasPersonales::Parentesco(zParentesco *pzParentesco)
{
   AsociadoAlCampo("Parentesco",pzParentesco);
}
void zReferenciasPersonales::Telefonos(zTelefonos *pzTelefonos)
{
 AsociadoAlCampo("Telefonos",pzTelefonos);
}
zSiscomRegistros *zReferenciasPersonales::Direcciones()
{
  return AsociadosDelCampo("Direcciones");

}

zSiscomRegistros *zReferenciasPersonales::Nombres()
{
  return AsociadosDelCampo("Nombres");
}
zSiscomRegistros *zReferenciasPersonales::Parentescos()
{
  return AsociadosDelCampo("Parentesco");
}
zSiscomRegistros *zReferenciasPersonales::Telefonos()
{
  return AsociadosDelCampo("Telefonos");
}
