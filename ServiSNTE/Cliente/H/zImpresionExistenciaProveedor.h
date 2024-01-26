#ifndef __ZIMPRESIONEXISTENCIAPROVEEDOR_H__
#define __ZIMPRESIONEXISTENCIAPROVEEDOR_H__
#include <zImpresion.h>


class zExistenciaProveedor;

class zImpresionExistenciaProveedor:public zImpresion
{
public:
	zImpresionExistenciaProveedor(zExistenciaProveedor *pzLstPrecios);
	void ImprimePrecio(int pintPrecio);
	void ImprimeImporteVenta(int pintImporteVenta);
	int ImprimePrecio();
	int ImprimeImporteVenta();
	void Encabezado();
	zExistenciaProveedor *ExistenciaProveedor();
private:
	zExistenciaProveedor *zStkTienda;	
	int intImprimePrecio;
	int intImprimeImporteVenta;
private:
	zSiscomRegistro *RegistroEncabezado(const char *pchrPtrNombre,const char *pchrPtrDato);
};

#endif
