#ifndef __ZCOMPRAIMPORTACIONPRODUCTO_H__
#define __ZCOMPRAIMPORTACIONPRODUCTO_H__
#include <zSiscomRegistro.h>


class zCompraImportacionProducto:public zSiscomRegistro
{
public:
	zCompraImportacionProducto();
	void Fecha(const char *pchrPtrFecha);
	void IdCompra(const char *pchrPtrIdCompra);
	void Cantidad(const char *pchrPtrCantidad);
	void Costo(const char *pchrPtrCosto);
	void CostoTotal(const char *pchrPtrCostoTotal);

	const char *Fecha();
	const char *IdCompra();
	const char *Cantidad();
	const char *Costo();
	const char *CostoTotal();
static zCompraImportacionProducto *Compra(zSiscomRegistro *pzSisRegCompra);
};

#endif
