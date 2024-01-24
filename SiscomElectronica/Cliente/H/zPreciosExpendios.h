#ifndef __ZPRECIOSEXPENDIOS_H__
#define __ZPRECIOSEXPENDIOS_H__

#include <zSiscomRegistros.h>

class zPreciosExpendio;
class zEmpresa;
class zPreciosExpendios:public zSiscomRegistros
{
public:
	zPreciosExpendios();
	void AgregaExpendio(zPreciosExpendio *);
	zPreciosExpendio *Empresa(const char *pchrPtrIdExpendio);
	zPreciosExpendio *Precios(const char *pchrPtrIdExpendio);
	void Precios(const char *pchrPtrIdExpendio,zSiscomRegistros *);
};

#endif
