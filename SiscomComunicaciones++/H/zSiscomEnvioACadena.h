#ifndef __ZSISCOMENVIOACADENA_H__
#define __ZSISCOMENVIOACADENA_H__
#include <zSiscomEnvio.h>

class zSiscomEnvioACadena:public zSiscomEnvio
{
public:
	zSiscomEnvioACadena(zSiscomConexion *pzSisConexion,zSiscomRegistros *pzSisRegsEnvio);
	void Cadena(const char *pchrPtrCadena);
};

#endif
