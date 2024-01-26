#ifndef __ZIMPRESIONSTOCKTIENDA_H__
#define __ZIMPRESIONSTOCKTIENDA_H__
#include <zImpresion.h>


class zStockTienda;

class zImpresionStockTienda:public zImpresion
{
public:
	zImpresionStockTienda(zStockTienda *pzLstPrecios);
	void ImprimePrecio(int pintPrecio);
	void ImprimeImporteVenta(int pintImporteVenta);
	int ImprimePrecio();
	int ImprimeImporteVenta();
	void Encabezado();
	zStockTienda *StockTienda();
private:
	zStockTienda *zStkTienda;	
	int intImprimePrecio;
	int intImprimeImporteVenta;
private:
	zSiscomRegistro *RegistroEncabezado(const char *pchrPtrNombre,const char *pchrPtrDato);
};

#endif
