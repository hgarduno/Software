#ifndef __ZPERSONA_H__
#define __ZPERSONA_H__

#include <zSiscomRegistro.h>

class zDireccion;
class zTelefonos;

class zPersona:public zSiscomRegistro
{
public:
	zPersona();
	zPersona(const char *pchrPtrIdPersona,
		 const char *pchrPtrNombre,
		 const char *pchrPtrAPaterno,
		 const char *pchrPtrMaterno,
		 const char *pchrPtrRFC=0);
	zPersona(zSiscomRegistro *);
	void Direccion(zSiscomRegistro *);
	void Telefonos(zSiscomRegistro *);
	void EdoRegistro(const char *pchrPtrEdoRegistro);
	zDireccion *Direccion();
	zTelefonos *Telefonos();
	const char *NumeroParticular();
	zSiscomRegistro *TelefonoParticular();
	void Nombre(const char *pchrPtrNombre);
	void APaterno(const char *pchrPtrAPaterno);
	void AMaterno(const char *pchrPtrAMaterno);
	void RFC(const char *pchrPtrRFC);
	void Id(const char *pchrPtrId);

	const char *Nombre();
	const char *APaterno();
	const char *AMaterno();
	const char *RFC();
	const char *Id();

	void DesdePersonaRegistrada(zSiscomRegistro *pzSisRegPersona);
	
};

#endif
