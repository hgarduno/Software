#ifndef __ZDATOSPERSONALES_H__
#define __ZDATOSPERSONALES_H__


class zDatosPersonales
{
public:
	zDatosPersonales();
	zDatosPersonales(const char *pchrPtrNombre,
			 const char *pchrPtrAPaterno,
			 const char *pchrPtrAMaterno);
	const char *Nombre();
	const char *APaterno();
	const char *AMaterno();

private:
	const char *chrPtrNombre;
	const char *chrPtrAPaterno;
	const char *chrPtrAMaterno;
};

#endif
