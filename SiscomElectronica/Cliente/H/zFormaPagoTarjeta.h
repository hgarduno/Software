#ifndef __ZFORMAPAGOTARJETA_H__
#define __ZFORMAPAGOTARJETA_H__
#include <zSiscomRegistro.h>
class zFormaPagoTarjeta:public zSiscomRegistro
{
public:
	zFormaPagoTarjeta();
	void Importe(const char *);
	const char *Importe();

};

#endif
