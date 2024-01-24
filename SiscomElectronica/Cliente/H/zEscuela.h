#ifndef __ZESCUELA_H__
#define __ZESCUELA_H__
#include <zSiscomRegistro.h>

class zEscuela:public zSiscomRegistro
{
public:
	zEscuela(zSiscomRegistro *pzSisReg);
	zEscuela(const unsigned char *pchrPtrIdEscuela,const unsigned char *pchrPtrEscuela);
	const char *Nombre();
	void Escuela(const char *pchrPtrEscuela);
};

#endif
