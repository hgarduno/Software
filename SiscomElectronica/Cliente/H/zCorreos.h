#ifndef __ZCORREOS_H__
#define __ZCORREOS_H__
#include <zSiscomRegistros.h>

class zCorreo;
class zCorreos:public zSiscomRegistros
{
public:
	zCorreos();
	int NCorreos();
};

#endif


