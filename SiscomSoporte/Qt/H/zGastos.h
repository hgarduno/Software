#ifndef __ZGASTOS_H__
#define __ZGASTOS_H__
#include <zSiscomRegistros.h>


class zGasto;

class zGastos:public zSiscomRegistros
{
public:
	zGastos();
	zGastos &operator<<(zGasto *);
};

#endif
