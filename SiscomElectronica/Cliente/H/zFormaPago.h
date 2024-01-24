#ifndef __ZFORMAPAGO_H__
#define __ZFORMAPAGO_H__
#include <zSiscomRegistro.h>


class zFormaPagoTransferencia;
class zFormaPagoTarjeta;


class zFormaPago:public zSiscomRegistro
{
public:
	zFormaPago();
	void Telefono(const char *pchrPtrTelefono);
	void Observaciones(const char *);
	void Tarjeta(zFormaPagoTarjeta *);
	void Transferencia(zFormaPagoTransferencia *);

	zFormaPagoTransferencia *Transferencia();

	const char *Telefono();
	const char *Observaciones();

};


#endif
