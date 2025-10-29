#ifndef __ZEXPENDIOS_H__
#define __ZEXPENDIOS_H__

#include <zSiscomRegistros.h>


class zExpendio;
class zExpendios:public zSiscomRegistros
{
public:
	zExpendios();
	void Agrega(zExpendio *);
	void Principal(zExpendio *);
	const char *RazonSocialPrincipal();
	zExpendio *Expendio(int );
	zExpendio *Principal();
	zExpendio *Actual();
	void Actual(zExpendio *);


private:
	zExpendio *zExActual;
};

#endif
