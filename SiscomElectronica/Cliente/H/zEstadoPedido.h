#ifndef __ZESTADOPEDIDO_H__
#define __ZESTADOPEDIDO_H__
#include <zSiscomRegistro.h>


class zEstadoPedido:public zSiscomRegistro
{
public:
	zEstadoPedido(const char *,const char *,const char *,const char *);
	zEstadoPedido(zSiscomRegistro *);

	const char *IdEstado();
	const char *Descripcion();
	const char *Fecha();
	const char *Accion();

	void IdEstado(const char *pchrPtrIdEstado);
	void Descripcion(const char *pchrPtrDescripcion);
	void Fecha(const char *pchrPtrFecha);
	void Accion(const char *pchrPtrAccion);
	
static zEstadoPedido *EstadoPedido(zSiscomRegistro *);
};
#endif
