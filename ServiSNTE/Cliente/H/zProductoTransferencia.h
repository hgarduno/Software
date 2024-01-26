#ifndef __ZPRODUCTOTRANSFERENCIA_H__
#define __ZPRODUCTOTRANSFERENCIA_H__

#include <zProducto.h>
#include <string.h>


class zProductoTransferencia:public zProducto
{
public:
	zProductoTransferencia(zSiscomRegistro *pzSisRegProducto);
	void Cantidad(const char *pchrPtrCantidad);
	void Stock(const char *pchrPtrStock);
	void Observacion(const char *pchrPtrObservacion);
	const char *Stock();


};


inline int operator==(zProducto &pzProd1,zProducto &pzProd2)
{
const char *lchrPtrIdProd1,
	   *lchrPtrIdProd2;

	lchrPtrIdProd1=(const char *)pzProd1["idproducto"];
	lchrPtrIdProd2=(const char *)pzProd2["idproducto"];
	return !strcmp(lchrPtrIdProd1,lchrPtrIdProd2);
}

#endif
