#ifndef __SISPERSONAS_H__
#define __SISPERSONAS_H__
#include <SISCOMComunicaciones++.h>

class SisPersona:public SiscomInformacion2
{
public:
	SisPersona(const char *,
		   const char *,
		   const char *,
		   const char *);
private:
	const char *chrPtrNombre;
	const char *chrPtrAPaterno;
	const char *chrPtrAMaterno;
	const char *chrPtrIdPersona;
private:
	void SiscomFormaRegistro();
	void SiscomAnexaRegistro();
};

class SisLstPersona:public QPtrList<SisPersona>
{
public:
	SisLstPersona();
	SisLstPersona &operator<<(SisPersona *);
};

#endif
