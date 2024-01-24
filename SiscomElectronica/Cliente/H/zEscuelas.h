#ifndef __ZESCUELAS_H__
#define __ZESCUELAS_H__
#include <zSiscomRegistros.h>


class zEscuela;

class zEscuelas:public zSiscomRegistros
{
public:
	zEscuelas();
	zEscuelas &operator<<(zEscuela *);
};

#endif
