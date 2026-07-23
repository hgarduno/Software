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
	void Efectivo(const char *pchrPtrEfectivo);
	void Total(const char *);
	void PorPagar(const char *);
	void PagoCompleto(const char *);
	void Combinada(const char *);
	

	zFormaPagoTransferencia *Transferencia();
	zFormaPagoTarjeta *Tarjeta();

	const char *Telefono();
	const char *Observaciones();

	const char *Efectivo();
	const char *PorPagar();
	const char *Total();
	const char *PagoCompleto();
	const char *Combinada();

	int PagoCompletoInt();

};


#endif
