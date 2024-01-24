#ifndef __ZESTANTE_H__
#define __ZESTANTE_H__
#include <zSiscomRegistro.h>

class zEstante:public zSiscomRegistro
{
public:
	zEstante();
	zEstante(zSiscomRegistro *);
	void IdEstante(const char *pchrPtrIdEstante);
	void Estante(const char *pchrPtrEstante);
	const char *Estante();
	const char *IdEstante();
};

#endif
