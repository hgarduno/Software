#ifndef __ZLISTAEXPENDIOS_H__
#define __ZLISTAEXPENDIOS_H__

#include <zSiscomRegistro.h>

class zEmpresa;

class zListaExpendios:public zSiscomRegistro
{
public:
	zListaExpendios();
	void Agrega(zEmpresa *);
};

#endif
