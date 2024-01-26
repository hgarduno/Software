#include <zEmpresa.h>
#include <zTelefonos.h>
#include <zCorreo.h>
#include <zDireccion.h>
#include <zSiscomCampo.h>
zEmpresa::zEmpresa(const char *pchrPtrIdEmpresa)
{
  (*this)								<< 
  new zSiscomCampo("IdEmpresa",(const unsigned char *)pchrPtrIdEmpresa)	<<
  new zSiscomCampo("RazonSocial")					<<
  new zSiscomCampo("Direccion")					<<
  new zSiscomCampo("Telefonos")					<<
  new zSiscomCampo("Correos")						<<
  new zSiscomCampo("Giro")						<<
  new zSiscomCampo("EdoRegistro");
}
zEmpresa::zEmpresa()
{
  (*this)				<< 
  new zSiscomCampo("IdEmpresa")	<<
  new zSiscomCampo("RazonSocial")	<<
  new zSiscomCampo("Direccion")	<<
  new zSiscomCampo("Telefonos")	<<
  new zSiscomCampo("Correos")		<<
  new zSiscomCampo("Giro")		<<
  new zSiscomCampo("EdoRegistro");
}
zDireccion *zEmpresa::Direccion()
{
  return (zDireccion *)AsociadoDelCampo("Direccion");
}
zTelefonos *zEmpresa::Telefonos()
{  
  return (zTelefonos *)AsociadoDelCampo("Telefonos");
}
zCorreo *zEmpresa::Correo()
{
   return (zCorreo *)AsociadoDelCampo("Correos");
}
const char *zEmpresa::Giro()
{
  return (const char *)(*this)["Giro"];
}
zEmpresa *zEmpresa::DesdeDatosEmpleo(zSiscomRegistro *pzSisRegEmpleo)
{
zEmpresa *lzEmpresa=new zEmpresa((const char *)(*pzSisRegEmpleo)["idempresa"]);
zDireccion *lzDirEmpresa=new zDireccion(pzSisRegEmpleo);
zCorreo *lzCorreo=new zCorreo(pzSisRegEmpleo);
lzEmpresa->RazonSocial((const char *)(*pzSisRegEmpleo)["razonsocial"]);
lzEmpresa->Giro((const char *)(*pzSisRegEmpleo)["giro"]);
lzEmpresa->Direccion(lzDirEmpresa);
lzEmpresa->Correos(lzCorreo);
lzEmpresa->Telefonos(zTelefonos().DesdeDatosEmpleo(pzSisRegEmpleo));
return lzEmpresa;
}
void zEmpresa::IdEmpresa(const char *pchrPtrIdEmpresa)
{
   ActualizaCampo("IdEmpresa",(const unsigned char *)pchrPtrIdEmpresa);
}
void zEmpresa::RazonSocial(const char *pchrPtrRazonSocial)
{
   ActualizaCampo("RazonSocial",(const unsigned char *)pchrPtrRazonSocial);
}
void zEmpresa::Giro(const char *pchrPtrGiro)
{
   ActualizaCampo("Giro",(const unsigned char *)pchrPtrGiro);
}
void zEmpresa::Direccion(zDireccion *pzDireccion)
{
	AsociadoAlCampo("Direccion",(zSiscomRegistro *)pzDireccion);
}
void zEmpresa::Telefonos(zTelefonos *pzTelefonos)
{
    AsociadoAlCampo("Telefonos",pzTelefonos);
}
/* Tepotzotlan Sabado 9 de Enero 2016 
 * Se debe integrar una clase como la de zTelefonos , para 
 * el manejo de los correos
 */
void zEmpresa::Correos(zCorreo *pzCorreo)
{
  AsociadoAlCampo("Correos",pzCorreo);
}
void zEmpresa::EdoRegistro(const char *pchrPtrEdoRegistro)
{
  ActualizaCampo("EdoRegistro",(const unsigned char *)pchrPtrEdoRegistro);
}
