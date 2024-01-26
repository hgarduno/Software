#ifndef __ZSISCOMLINEACOMANDOS_H__
#define __ZSISCOMLINEACOMANDOS_H__
#include <zSiscomRegistros.h>


class zSiscomLineaComandos:public zSiscomRegistros
{
public:
	zSiscomLineaComandos(int pintArgc,char **pchrPtrArgv);
	const char *operator[](const char *pchrPtrOpcion);
	int EstaLaOpcion(const char *pchrPtrOpcion);

private:
	void AnalizaArgumentos(int pintArgc,char **pchrPtrArgv);	
	void AgregaOpcion(char **pchrPtrArgv);
				
};
#endif
