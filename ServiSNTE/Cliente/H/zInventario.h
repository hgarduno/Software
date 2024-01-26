#ifndef __ZINVENTARIO_H__
#define __ZINVENTARIO_H__
#include <zSiscomRegistro.h>

class zProducto;
class zProductos;
class zInventario:public zSiscomRegistro
{
public:
	zInventario(const char *pchrPtrIdInventario,
		    const char *pchrPtrIdMotivoInventario);
	void Producto(zProducto *);
	void Productos(zProductos *);
    void ProductoIndividual(zProducto *);
    void IdMotivoInventario(const char *);
};

#endif
