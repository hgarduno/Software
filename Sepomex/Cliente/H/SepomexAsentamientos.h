#ifndef __SEPOMEXASENTAMIENTOS_H__
#define __SEPOMEXASENTAMIENTOS_H__
#include <SISCOMComunicaciones++.h>

class SepomexAsentamiento:public SiscomInformacion
{
public:

	SepomexAsentamiento(const char *,
			 const char *,
			 const char *,
			 const char *,
			 const char *,
			 const char *);

};

class SepomexAsentamientos:public QPtrList<SepomexAsentamiento>
{

public:
	SepomexAsentamientos();
	SepomexAsentamientos &operator<<(SepomexAsentamiento *);
	
};

class SepomexOpAsentamientos:public SiscomOperaciones
{
	public:
		SepomexOpAsentamientos(SiscomDatCom *,
				    SiscomParametrosConsulta *);
private:

	void SiscomGeneraRegistros(const SiscomComunicaSrv *,
				   QPtrList<SiscomInformacion> *);
};
#endif
