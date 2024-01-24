#ifndef __ZDEVOLUCION_H__
#define __ZDEVOLUCION_H__

#include <zSiscomRegistro.h>


class zSiscomRegistros;
class zDevolucion:public zSiscomRegistro
{
public:
	zDevolucion();
	void IdVenta(const char *pchrPtrIdVenta);
	void Productos(zSiscomRegistros *);
};

#endif
