#ifndef __ZINVENTARIOEXPENDIO_H__
#define __ZINVENTARIOEXPENDIO_H__
#include <ZProductosInventario.h>


class ZInventarioExpendio:public ZProductosInventario
{
public:
	ZInventarioExpendio(const char *pchrPtrArchivo,
			    const char *pchrPtrIdExpendio,
			    const char *pchrPtrIdInventario,
			    const char *pchrPtrIdBodega);

private:
	void AgregandoProducto(const char *pchrPtrCveProducto,
			       const char *pchrPtrCantidad,
			       const char *pchrPtrIdExpendio,
			       const char *pchrPtrIdEmpleado);
};


#endif
