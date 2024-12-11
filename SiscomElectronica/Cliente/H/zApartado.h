#ifndef __ZAPARTADO_H__
#define __ZAPARTADO_H__

#include <zSiscomRegistro.h>

class zApartado:public zSiscomRegistro
{
public:
	zApartado(const char *pchrPtrACuenta,
		  const char *pchrPtrFechaHoraEntrega,
		  const char *pchrPtrObservaciones);
	zApartado(zSiscomRegistro *);
	const char *ACuenta();
	const char *Observaciones();
	const char *FechaHoraE();
	const char *PorPagar();

};

#endif
