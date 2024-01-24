#ifndef __ZPEDIDO_H__
#define __ZPEDIDO_H__
#include <zSiscomRegistro.h>

class zPuntoEntrega;
class zEstadoPedido;
class zDireccion;
class zPedido:public zSiscomRegistro
{
public:
	zPedido();
	zPedido(zSiscomRegistro *);
	void FechaHoraE(const char *pchrPtrFechaHoraE);
	void SePagaCon(const char *pchrPtrSePagaCon);
	void Cambio(const char *pchrPtrCambio);
	void Observaciones(const char *pchrPtrObservaciones);
	void EstadoPedido(zEstadoPedido *);
	void PuntoEntrega(zPuntoEntrega *);
	void TipoEntrega(const char *pchrPtrTipoEntrega);
	void Direccion(zDireccion *);
	

	const char *FechaHoraE();
	const char *SePagaCon();
	const char *Cambio();
	const char *Observaciones();
	zPuntoEntrega *PuntoEntrega();
	const char *Calle();
	const char *Numero();
	const char *NumeroInt();
	const char *TipoEntrega();
	int TipoEntregaInt();
	zEstadoPedido *EstadoPedido();

	
private:


};
#endif
