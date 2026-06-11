#ifndef __ZFORMAPAGOTRANSFERENCIA_H__
#define __ZFORMAPAGOTRANASFERNCIA_H__
#include <zSiscomRegistro.h>

class zFormaPagoTransferencia:public zSiscomRegistro
{
public:
	
	zFormaPagoTransferencia();
	zFormaPagoTransferencia(zSiscomRegistro *);
	void YaSeReflejo(const char *);
	void Observaciones(const char *);
	void Importe(const char *);

	int YaSeReflejoInt();

	const char *Observaciones();
	const char *Importe();
};

#endif
