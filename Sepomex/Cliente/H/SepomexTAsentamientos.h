#ifndef __SEPOMEXTASENTAMIENTOS_H__
#define __SEPOMEXTASENTAMIENTOS_H__
#include <SISCOMComunicaciones++.h>

class SepomexTAsentamiento:public SiscomInformacion
{
public:

	SepomexTAsentamiento(const char *,
			 const char *);

};

class SepomexTAsentamientos:public QPtrList<SepomexTAsentamiento>
{

public:
	SepomexTAsentamientos();
	SepomexTAsentamientos &operator<<(SepomexTAsentamiento *);

};

class SepomexOpTAsentamientos:public SiscomOperaciones
{
	public:
		SepomexOpTAsentamientos(SiscomDatCom *,
				    SiscomParametrosConsulta *);
private:

	void SiscomGeneraRegistros(const SiscomComunicaSrv *,
				   QPtrList<SiscomInformacion> *);
};
#endif
