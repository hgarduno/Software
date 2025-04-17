#ifndef __ZCOMPRAS_H__
#define __ZCOMPRAS_H__
#include <zSiscomRegistros.h>


class zCompras:public zSiscomRegistros
{
public:
	zCompras();

	void Compras(zSiscomRegistros *);

};

#endif
