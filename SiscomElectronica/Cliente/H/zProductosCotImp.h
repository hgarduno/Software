#ifndef __ZPRODUCTOSCOTIMP_H__
#define __ZPRODUCTOSCOTIMP_H__
#include <zSiscomRegistros.h>


class zProductoCotImp;
class zProductosCotImp:public zSiscomRegistros
{
public:
	zProductosCotImp();
	void Agrega(zProductoCotImp *);
	void Agrega(zProductosCotImp *);
	void Agrega(zSiscomRegistros *);
	void PesoTotalProducto(const char *pchrPtrCveProducto,const char *pchrPtrPeso);
	void ImporteProducto(const char *pchrPtrCveProducto,const char *pchrPtrImporte);
	zProductoCotImp *Producto(const char *pchrPtrCveProducto);
	

};

#endif
