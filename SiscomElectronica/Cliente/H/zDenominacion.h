#ifndef __ZDENOMINACION_H__
#define __ZDENOMINACION_H__
#include <zSiscomRegistro.h>


class zDenominacion:public zSiscomRegistro
{
public:
	zDenominacion();
	zDenominacion(const char *pchrPtrId,
		      const char *pchrPtrDenominacion);

	const char *Denominacion();
	const char *Id();

};

#endif
