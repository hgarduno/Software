
#ifndef __ZINVENTARIOBODEGA_H__
#define __ZINVENTARIOBODEGA_H__
#include <ZProductosInventario.h>


class ZInventarioBodega:public ZProductosInventario
{
public:
	ZInventarioBodega(const char *pchrPtrArchivo,
			    const char *pchrPtrIdExpendio,
			    const char *pchrPtrIdInventario,
			    const char *pchrPtrIBodega);

private:
	void AgregandoProducto(const char *pchrPtrCveProducto,
			       const char *pchrPtrCantidad,
			       const char *pchrPtrIdExpendio,
			       const char *pchrPtrIdEmpleado);
};


#endif
