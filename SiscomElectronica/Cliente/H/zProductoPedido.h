#ifndef __ZPRODUCTOPEDIDO_H__
#define __ZPRODUCTOPEDIDO_H__
#include <zProductoCotizar.h>
#include <zProducto.h>
class zProductoPedido:public zProducto
{
public:
	zProductoPedido(const char *pchrPtrClave);
	void Cantidad(const char *pchrPtrCantidad);
	void ObsProducto(const char *pchrPtrObsProducto);
	void IdPedido(const char *pchrPtrIdPedido);
	void IdProducto(const char *pchrPtrIdProducto);
	const  char *Cantidad();
	const  char *ObsProducto();
};
#endif
