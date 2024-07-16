#ifndef __ZCAMBIOSCAJA_H__
#define __ZCAMBIOSCAJA_H__

#include <zSiscomRegistros.h>


class zCambioCaja;

class zCambiosCaja:public zSiscomRegistros
{
public:
	zCambiosCaja();
	void CambiosCaja(zSiscomRegistros *);
	const char *Fecha();
	const char *Importe();

	zCambioCaja *CambioCaja(int );

};


#endif
