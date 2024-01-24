#ifndef __ZPRODUCTOCOTIMP_H__
#define __ZPRODUCTOCOTIMP_H__
#include <zProducto.h>


class zProductoCotImp:public zProducto
{
public:
	zProductoCotImp(zSiscomRegistro *);

	void Peso(const char *pchrPtrPeso);
	void Precio(const char *pchrPtrPrecio);
	void Cantidad(const char *pchrPtrCantidad);

	void PesoTotal(const char *pchrPtrPeso);
	void Importe(const char *pchrPtrImporte);

	const char *Cantidad();
	const char *Peso();
	const char *PesoTotal();
	const char *Precio();
	const char *Importe();
static	zProductoCotImp *ProductoDeRegistro(zSiscomRegistro *);
};

#endif
