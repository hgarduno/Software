#ifndef __ZPRECIO2EXPENDIO_H__
#define __ZPRECIO2EXPENDIO_H__
#include <zSiscomRegistro.h>

class zEmpresa;
class zPrecio2Expendio:public zSiscomRegistro
{
public:
	zPrecio2Expendio(const char *pchrPtrPrecio,zEmpresa *);

};
#endif
