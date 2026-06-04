#ifndef __ZPEDIDOEXISTENCIAM_H__
#define __ZPEDIDOEXISTENCIAM_H__
#include <zSiscomRegistro.h>

class zProductos;

class zPedidoExistenciaM:public zSiscomRegistro
{
public:
	zPedidoExistenciaM();
	void IdExpendio(const char *);
	void Porcentaje(const char *);
	void IdPedido(const char *);
	void Fecha(const char *);
	void Observaciones(const char *);
	void Productos(zProductos *);
	void Productos(zSiscomRegistros *);
	const char *IdExpendio();
	const char *Porcentaje();
	const char *IdPedido();
	const char *Fecha();
	const char *Observaciones();
	zProductos *Productos();


};

#endif
