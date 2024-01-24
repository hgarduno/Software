#ifndef __ZPEDIDOEXPENDIO_H__
#define __ZPEDIDOEXPENDIO_H__
#include <zSiscomRegistro.h>
class zPedidoExpendio:public zSiscomRegistro
{
public:
	zPedidoExpendio();
	void Pedido(zSiscomRegistro *pzSisRegPedido);
	void Productos(zSiscomRegistros *pzSisRegsProductos);
	const char *IdProducto(int pintNProducto);
	const char *Clave(int pintClave);
	zSiscomRegistros *Productos();
	const char *Observaciones();
	const char *IdPedido();

private:
		
zSiscomRegistros *zSisRegProductos;

};

#endif
