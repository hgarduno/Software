#ifndef __ZADMINISTRACIONSERVISNTE_H__
#define __ZADMINISTRACIONSERVISNTE_H__
#include <zSiscomOperaciones.h>
class zSiscomConexion;
class zSiscomRegistro;
class zSiscomRegistros;

class zAdministracionServiSNTE:public zSiscomOperaciones
{
public:
	zAdministracionServiSNTE(zSiscomConexion *pzSisConexion,
			   const char *pchrPtrFuncion,
			   const char *pchrPtrModulo="libSiscomServiSNTE.so");
	void ActivaServidor(zSiscomRegistro *pzSisRegTienda,const char *pchrPtrActivo);
	zSiscomRegistros *EstadoServidores();
};
#endif
