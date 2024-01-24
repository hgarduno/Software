#ifndef __ZMANEJADOREJECUCION_H__
#define __ZMANEJADOREJECUCION_H__
#include <zSiscomOperaciones.h>
class zLineaComandosTiendas;
class zSiscomRegistros;
class zManejadorEjecucion:public zSiscomOperaciones
{
public:
	zManejadorEjecucion(zSiscomConexion *pzSiscomConexion);
	zManejadorEjecucion(zSiscomConexion *pzSisConexion,int);
	void Agrega(zLineaComandosTiendas *pzLineaCmdsTiendas);

private:
	const char *Pid();
private:
	zSiscomRegistros *zSisRegsRegreso;
};

#endif
