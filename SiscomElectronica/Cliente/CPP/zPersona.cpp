#include <zPersona.h>
#include <zSiscomCampo.h>
zPersona::zPersona(const char *pchrPtrIdPersona,
		   const char *pchrPtrNombre,
		   const char *pchrPtrAPaterno,
		   const char *pchrPtrAMaterno)
{
  (*this) 								<< 
  new zSiscomCampo("IdPersona",(const unsigned char *)pchrPtrIdPersona) <<
  new zSiscomCampo("Nombre",(const unsigned char *)pchrPtrNombre) 	<<
  new zSiscomCampo("APaterno",(const unsigned char *)pchrPtrAPaterno) 	<<
  new zSiscomCampo("AMaterno",(const unsigned char *)pchrPtrAMaterno) 	<<
  new zSiscomCampo("TipoPersona");

}

zPersona::zPersona(zSiscomRegistro *pzSisRegistro)
{

  (*this) 								<< 
  new zSiscomCampo("IdPersona",(*pzSisRegistro)["idpersona"]) 		<<
  new zSiscomCampo("Nombre",(*pzSisRegistro)["nombre"]) 		<<
  new zSiscomCampo("APaterno",(*pzSisRegistro)["apaterno"]) 		<<
  new zSiscomCampo("AMaterno",(*pzSisRegistro)["amaterno"])		<<
  new zSiscomCampo("TipoPersona",(*pzSisRegistro)["tipopersona"]);
}

zPersona::zPersona()
{
(*this)					<<
new zSiscomCampo("IdPersona")		<<
new zSiscomCampo("Nombre")		<<
new zSiscomCampo("APaterno")		<<
new zSiscomCampo("AMaterno")		<<
new zSiscomCampo("TipoPersona");
}


const char *zPersona::IdPersona()
{
   return (const char *)Campo("IdPersona");
}


const char *zPersona::Nombre()
{
   return (const char *)Campo("Nombre");
}
const char *zPersona::APaterno()
{
   return (const char *)Campo("APaterno");
}
const char *zPersona::AMaterno()
{
   return (const char *)Campo("AMaterno");
}
int zPersona::PersonaValida()
{
   return Nombre() 	&&
          APaterno() 	&&
	  AMaterno() ;
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
