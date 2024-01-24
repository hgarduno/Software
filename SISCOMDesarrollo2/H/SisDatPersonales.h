#ifndef __SISDATPERSONALES_H__
#define __SISDATPERSONALES_H__
#include <SisPersonas.h>
#include <SisDirecciones.h>
#include <SisMedioComunicacion.h>

class SisDatPersonales:public SisPersona
{
public:
	SisDatPersonales(const char *,
			 const char *,
			 const char *,
			 const char *);

	void SiscomAnexaMedio(SisMedCom *);
	void SiscomAnexaDireccion(SisDireccion &);
private:
	SisLstDireccion SLstDirs;
	SisLstMedCom SLCMComMedios;
	SisDireccion *SDirDato;
private:
	void IniciaVariables();
};

#endif
