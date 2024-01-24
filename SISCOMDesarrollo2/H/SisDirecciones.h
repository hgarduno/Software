#ifndef __SISDIRECCIONES_H__
#define __SISDIRECCIONES_H__
#include <SISCOMComunicaciones++.h>

class SisDireccion:public SiscomInformacion2
{
public:
	SisDireccion(const char *,
		     const char *,
		     const char *,
		     const char *);
	SisDireccion(const char *,
		     const char *,
		     const char *,
		     const char *,
		     const char *,
		     const char *,
		     const char *);
	
	void IdPersona(const char *);
private:
	const char *chrPtrCalle;
	const char *chrPtrNumero;
	const char *chrPtrIdAsentamiento;
	const char *chrPtrComoLlegar;
	const char *chrPtrAsentamiento;
	const char *chrPtrEstado;
	const char *chrPtrMunicipio;


private:
	void SiscomAnexaRegistro();
	void SiscomFormaRegistro();
};

class SisLstDireccion:public QPtrList<SisDireccion>
{
public:
	SisLstDireccion();
	SisLstDireccion &operator<<(SisDireccion *);
};
#endif
