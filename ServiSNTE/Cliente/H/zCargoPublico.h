#ifndef __ZCARGOPUBLICO_H__
#define __ZCARGOPUBLICO_H__
#include <zSiscomRegistro.h>

class zCargoPublico:public zSiscomRegistro
{
public:
	zCargoPublico(const char *pchrPtrIdPersona);
	void IdCargoPublico(const char *pchrPtrIdCargoPublico);
	void Descripcion(const char *pchrPtrDescripcion);
	void Dependencia(const char *pchrPtrDependencia);
	void Puesto(const char *pchrPtrPuesto);
	void Funciones(const char *pchrPtrFunciones);
	void Periodo(const char *pchrPtrPeriodo);

};

#endif
