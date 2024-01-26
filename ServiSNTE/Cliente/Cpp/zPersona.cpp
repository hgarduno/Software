#include <zPersona.h>
#include <zDireccion.h>
#include <zTelefonos.h>
#include <zSiscomCampo.h>
#include <zSiscomRegistros.h> 
zPersona::zPersona()
{
 (*this)					<<
  new zSiscomCampo("IdPersona") 		<<
  new zSiscomCampo("Nombre")       		<<
  new zSiscomCampo("APaterno")			<<
  new zSiscomCampo("AMaterno") 			<<
  new zSiscomCampo("RFC")			<<
  new zSiscomCampo("EdoRegistro",(const unsigned char *)"No");
}
zPersona::zPersona(const char *pchrPtrIdPersona,
		   const char *pchrPtrNombre,
		   const char *pchrPtrAPaterno,
		   const char *pchrPtrAMaterno,
		   const char *pchrPtrRFC)
{
  (*this) 								<< 
  new zSiscomCampo("IdPersona",(unsigned char *)pchrPtrIdPersona) 	<<
  new zSiscomCampo("Nombre",(unsigned char *)pchrPtrNombre)       	<<
  new zSiscomCampo("APaterno",(unsigned char *)pchrPtrAPaterno)		<<
  new zSiscomCampo("AMaterno",(unsigned char *)pchrPtrAMaterno) 	<<
  new zSiscomCampo("RFC",(unsigned char *)pchrPtrRFC)			<<
  new zSiscomCampo("EdoRegistro",(const unsigned char *)"No");
}

zPersona::zPersona(zSiscomRegistro *pzSisRegCliente)
{
    (*this) 								<<
    new zSiscomCampo("IdPersona",(*pzSisRegCliente)["idpersona"])	<<
    new zSiscomCampo("Nombre",(*pzSisRegCliente)["nombre"])		<<
    new zSiscomCampo("APaterno",(*pzSisRegCliente)["apaterno"])		<<
    new zSiscomCampo("AMaterno",(*pzSisRegCliente)["amaterno"])		<<
    new zSiscomCampo("RFC",(*pzSisRegCliente)["rfc"])			<<
    new zSiscomCampo("Direccion")					<<
    new zSiscomCampo("Telefonos")					<<
    new zSiscomCampo("EdoRegistro",(const unsigned char *)"No");
}
void zPersona::Nombre(const char *pchrPtrNombre)
{
  ActualizaCampo("Nombre",(const unsigned char *)pchrPtrNombre);
}

void zPersona::APaterno(const char *pchrPtrAPaterno)
{
  ActualizaCampo("APaterno",(const unsigned char *)pchrPtrAPaterno);
}
void zPersona::AMaterno(const char *pchrPtrAMaterno)
{
  ActualizaCampo("AMaterno",(const unsigned char *)pchrPtrAMaterno);
}
void zPersona::RFC(const char *pchrPtrRFC)
{
  ActualizaCampo("RFC",(const unsigned char *)pchrPtrRFC);
}
void zPersona::Id(const char *pchrPtrId)
{
  ActualizaCampo("IdPersona",(const unsigned char *)pchrPtrId);
}
void zPersona::EdoRegistro(const char *pchrPtrEdoRegistro)
{
  ActualizaCampo("EdoRegistro",(const unsigned char *)pchrPtrEdoRegistro);
}
void zPersona::Direccion(zSiscomRegistro *pzSisRegCliente)
{
zDireccion *lzDireccion=new zDireccion(pzSisRegCliente);
AsociadoAlCampo("Direccion",lzDireccion);
}
void zPersona::Telefonos(zSiscomRegistro *pzSisRegCliente)
{
AsociadoAlCampo("Telefonos",zTelefonos().DesdePersonaRegistrada(pzSisRegCliente));
}
zDireccion *zPersona::Direccion()
{
  return (zDireccion *)AsociadoDelCampo("Direccion");
}
zTelefonos *zPersona::Telefonos()
{
  return (zTelefonos *)AsociadoDelCampo("Telefonos");
}
zSiscomRegistro *zPersona::TelefonoParticular()
{
   return Telefonos()->Telefono("Particular");  
}
const char *zPersona::NumeroParticular()
{
zSiscomRegistro *lzSisRegTelefono;
 if((lzSisRegTelefono=TelefonoParticular()))
       return (const char *)(*lzSisRegTelefono)["Telefono"];
 else
 return "";
}


const char *zPersona::Nombre()
{
  return (const char *)(*this)["Nombre"];
}



const char *zPersona::APaterno()
{
  return (const char *)(*this)["APaterno"];
}
const char *zPersona::AMaterno()
{
  return (const char *)(*this)["AMaterno"];
}
const char *zPersona::RFC()
{
  return (const char *)(*this)["RFC"];
}
const char *zPersona::Id()
{
  return (const char *)(*this)["IdPersona"];
}
void zPersona::DesdePersonaRegistrada(zSiscomRegistro *pzSisRegPersona)
{
	Nombre((const char *)(*pzSisRegPersona)["nombre"]);
	APaterno((const char *)(*pzSisRegPersona)["apaterno"]);
	AMaterno((const char *)(*pzSisRegPersona)["amaterno"]);
	Id((const char *)(*pzSisRegPersona)["idpersona"]);
	RFC((const char *)(*pzSisRegPersona)["rfc"]);
}
