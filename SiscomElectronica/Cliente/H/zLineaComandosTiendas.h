#ifndef __ZLINEACOMANDOSTIENDAS_H__
#define __ZLINEACOMANDOSTIENDAS_H__
#include <zSiscomLineaComandos.h>


class zLineaComandosTiendas:public zSiscomLineaComandos
{
public:
	zLineaComandosTiendas(int pintArgc,char **pchrPtrArgv);
	int CorreMaximizada();
	int SegundoPlano();
	const char *NombreEjecucion();


};

#endif
