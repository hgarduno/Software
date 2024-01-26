#include <zUsuario.h>
#include <zSiscomRegistro.h>
#include <zSiscomCampo.h>

zUsuario::zUsuario():zPersona()
{
 	(*this)					<<
	new zSiscomCampo("IdTipoUsuario")	<<
	new zSiscomCampo("Firma")		<<
	new zSiscomCampo("Password")		<<
	new zSiscomCampo("RePassword");
}

zUsuario::zUsuario(const char *pchrPtrNombre,
                   const char *pchrPtrAPaterno,
                   const char *pchrPtrAMaterno):
		   zPersona(0,
			    pchrPtrNombre,
			    pchrPtrAPaterno,
			    pchrPtrAMaterno,
			    0)
{
        (*this)                                 <<
        new zSiscomCampo("IdTipoUsuario")       <<
        new zSiscomCampo("Firma")               <<
        new zSiscomCampo("Password")            <<
        new zSiscomCampo("RePassword");
}
void zUsuario::Firma(const char *pchrPtrFirma)
{
  ActualizaCampo("Firma",(const unsigned char *)pchrPtrFirma); 
}

void zUsuario::Password(const char *pchrPtrPassword)
{
  ActualizaCampo("Password",(const unsigned char *)pchrPtrPassword); 
}
void zUsuario::RePassword(const char *pchrPtrRePassword)
{
  ActualizaCampo("RePassword",(const unsigned char *)pchrPtrRePassword); 
}
void zUsuario::IdTipoUsuario(const char *pchrPtrIdTipoUsuario)
{
  ActualizaCampo("IdTipoUsuario",(const unsigned char *)pchrPtrIdTipoUsuario); 
}
