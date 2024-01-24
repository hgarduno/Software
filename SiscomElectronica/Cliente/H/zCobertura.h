#ifndef __ZCOBERTURA_H__
#define __ZCOBERTURA_H__
#include <zSiscomRegistro.h>


class zCobertura:public zSiscomRegistro
{
public:
	zCobertura(zSiscomRegistro *);
	int Cobertura();
	const char *Cp();
	const char *Municipio();
	const char *Estado();
	const char *Dias();
	const char *Tarifa();
};

#endif
