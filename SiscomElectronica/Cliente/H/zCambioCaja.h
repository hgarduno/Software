#ifndef __ZCAMBIOCAJA_H__
#define __ZCAMBIOCAJA_H__

#include <zSiscomRegistro.h>

class zDenominaciones;
class zCambioCaja:public zSiscomRegistro
{
public:
	zCambioCaja(const char *pchrPtrFecha);
	zCambioCaja(zSiscomRegistro *);
	const char *Fecha();
	const char *Importe();
	const char *IdCambioCaja();
	zDenominaciones *Dinero();

	void Dinero(zDenominaciones *);

};

#endif
