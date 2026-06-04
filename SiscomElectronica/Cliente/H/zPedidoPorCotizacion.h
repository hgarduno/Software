#ifndef __ZPEDIDOPORCOTIZACION_H__
#define __ZPEDIDOPORCOTIZACION_H__
#include <zSiscomRegistro.h>



class zSiscomRegistros;
class zPedidoPorCotizacion:public zSiscomRegistro
{
public:
	zPedidoPorCotizacion();
	void IdExpendio(const char *);
	void IdPedido(const char *);
	void Fecha(const char *);
	void Observaciones(const char *);
	void Productos(zSiscomRegistros *pzSisRegsProductos);
};


#endif
