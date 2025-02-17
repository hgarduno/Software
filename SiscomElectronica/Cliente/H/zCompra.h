#ifndef __ZCOMPRA_H__
#define __ZCOMPRA_H__
#include <zSiscomRegistro.h> 



class zProductos;

class zCompra:public zSiscomRegistro
{
public:
	zCompra();

	zCompra(zSiscomRegistro *);

	void IdCompra(const char *pchrPtrIdCompra);
	void Fecha(const char *pchrPtrFecha);
	void Importe(const char *pchrPtrImporte);
	void Productos(zSiscomRegistros *);
	
	zProductos *Productos();	
};


#endif
