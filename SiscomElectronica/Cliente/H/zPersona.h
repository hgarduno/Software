#ifndef __ZPERSONA_H__
#define __ZPERSONA_H__
#include <zSiscomRegistro.h>


class zPersona:public zSiscomRegistro
{
public:
	zPersona(const char *pchrPtrIdPersona,
		 const char *pchrPtrNombre,
		 const char *pchrPtrAPaterno,
		 const char *pchrPtrAMaterno);
	zPersona(zSiscomRegistro *pzSisRegistro);
	int PersonaValida();
	zPersona();
	const char *IdPersona();
	const char *Nombre();
	const char *APaterno();
	const char *AMaterno();

	void Nombre(const char *pchrPtrNombre);
	void APaterno(const char *pchrPtrAPaterno);
	void AMaterno(const char *pchrPtrAMaterno);

	
};

#endif
