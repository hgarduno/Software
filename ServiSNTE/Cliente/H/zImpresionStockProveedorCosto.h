#ifndef __ZIMPRESIONSTOCKPROVEEDORCOSTO_H__
#define __ZIMPRESIONSTOCKPROVEEDORCOSTO_H__
#include <zImpresion.h>


class zStockProveedorCosto;

class zImpresionStockProveedorCosto:public zImpresion
{
public:
	zImpresionStockProveedorCosto(zStockProveedorCosto *pzLstPrecios);
	void Encabezado();
	zStockProveedorCosto *StockProveedorCosto();
private:
	zStockProveedorCosto *zStkTienda;	
private:
	zSiscomRegistro *RegistroEncabezado(const char *pchrPtrNombre,const char *pchrPtrDato);
};

#endif
