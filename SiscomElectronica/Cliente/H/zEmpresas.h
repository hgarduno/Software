#ifndef __ZEMPRESAS_H__
#define __ZEMPRESAS_H__
#include <zSiscomRegistros.h>

class zEmpresa;
class zEmpresas:public zSiscomRegistros
{
public:
	zEmpresas();
	zEmpresas &operator<<(zEmpresa *);
};

#endif
