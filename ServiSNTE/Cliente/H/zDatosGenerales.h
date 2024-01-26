#ifndef __ZDATOSGENERALES_H__
#define __ZDATOSGENERALES_H__

#include <zSiscomRegistro.h>

class zDatosGenerales:public zSiscomRegistro
{

public:
	zDatosGenerales(const char *pchrPtrIdPersona);
	zDatosGenerales(zSiscomRegistro *pzSisRegDatos);
	void CURP(const char *pchrPtrCurp);
	void EstadoNacimiento(const char *pchrPtrEstadoNacimiento);
	void PaisNacimiento(const char *pchrPtrPaisNacimiento);
	void Genero(const char *pchrPtrGenero);
	void EstadoCivil(const char *pchrPtrEstadoCivil);
	void Edad(const char *pchrPtrEdad);
	void FechaNacimiento(const char *pchrPtrFechaNacimiento);
	void Identificacion(const char *pchrPtrIdentificacion);
	void NoIdentificacion(const char *pchrPtrNoIdentificacion);
	void Ocupacion(const char *pchrPtrOcupacion);
	void Nacionalidad(const char *pchrPtrNacionalidad);

};

#endif
