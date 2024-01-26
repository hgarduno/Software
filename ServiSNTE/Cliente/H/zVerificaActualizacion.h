#ifndef __ZVERIFICAACTUALIZACION_H__
#define __ZVERIFICAACTUALIZACION_H__
#include <zSiscomOperaciones.h>
class zSiscomConexion;
class zSiscomRegistro;
class zSiscomRegistros;


class zVerificaActualizacion:public zSiscomOperaciones
{

public:
	zVerificaActualizacion(zSiscomConexion *pzSiscomConexion,
			       const char *pchrPtrFuncion,
			       const char *pchrPtrModulo="libSiscomServiSNTE.so");

private:
	void Verificando();
};
#endif
