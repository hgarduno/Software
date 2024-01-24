#ifndef __ZPRODUCTOPRECIOEXPENDIOS_H__
#define __ZPRODUCTOPRECIOEXPENDIOS_H__
#include <zProductoPrecio.h>
class zEmpresas;
class zProductoPrecioExpendios:public zProductoPrecio
{
public:
	zProductoPrecioExpendios(const char *pchrPtrClave);
	void Expendios(zEmpresas *);

};

#endif
