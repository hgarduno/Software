#ifndef __SEPOMEXMUNICIPIOS_H__
#define __SEPOMEXMUNICIPIOS_H__
#include <SISCOMComunicaciones++.h>

class SepomexMunicipio:public SiscomInformacion
{
public:

	SepomexMunicipio(const char *,
			 const char *,
			 const char *);

};

class SepomexMunicipios:public QPtrList<SepomexMunicipio>
{

public:
	SepomexMunicipios();
	SepomexMunicipios &operator<<(SepomexMunicipio *);

};

class SepomexOpMunicipios:public SiscomOperaciones
{
	public:
		SepomexOpMunicipios(SiscomDatCom *,
				    SiscomParametrosConsulta *);
private:

	void SiscomGeneraRegistros(const SiscomComunicaSrv *,
				   QPtrList<SiscomInformacion> *);
};
#endif
