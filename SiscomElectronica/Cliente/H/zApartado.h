#ifndef __ZAPARTADO_H__
#define __ZAPARTADO_H__

#include <zSiscomRegistro.h>

class zApartado:public zSiscomRegistro
{
public:
	zApartado(const char *pchrPtrACuenta,
		  const char *pchrPtrFechaHoraEntrega,
		  const char *pchrPtrObservaciones);
};

#endif
