#ifndef __ZUSUARIO_H__
#define __ZUSUARIO_H__

#include <zPersona.h>


class zSiscomRegistro;

class zUsuario:public zPersona
{
  public:
  	zUsuario();
	zUsuario(const char *pchrPtrNombre,
                 const char *pchrPtrAPaterno,
                 const char *pchrPtrAMaterno);
	void IdTipoUsuario(const char *pchrPtrIdTipoUsuario);
	void Firma(const char *pchrPtrFirma);
	void Password(const char *pchrPtrPassword);
	void RePassword(const char *pchrPtrRePassword);

};

#endif
