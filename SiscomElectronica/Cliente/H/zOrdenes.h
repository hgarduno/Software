#ifndef __ZORDENES_H__
#define __ZORDENES_H__
#include <zSiscomRegistros.h>
class zOrdenVenta;
class zOrdenes:public zSiscomRegistros
{
public:
	zOrdenes();
	void Orden(zSiscomRegistro *);
	zOrdenVenta *Orden(int pintNOrden);
	int OrdenFacturada(int pintOrden);
	
	int HayMasDeUnaOrden();
	int HayUnaOrden();

	const char *IdFactura(int pintNOrden);
};

#endif

