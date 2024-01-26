#ifndef __ZSTOCKTIENDA_H__
#define __ZSTOCKTIENDA_H__
#include <zSiscomRegistros.h>

class zStockTienda:public zSiscomRegistros
{
public:
	zStockTienda();
	int SiguienteProveedor();
        int PrimerProveedor();
        const char *NumeroProveedor();
        const char *RazonSocial();
	const char *TotalProveedor();
        const char *Numero();
        const char *Nombre();
        const char *Modelo();
        const char *CostoNeto();
	const char *ImporteCosto();
	const char *Precio();
	const char *ImporteVenta();
	void Tienda(zSiscomRegistro *pzSisRegTienda);
	zSiscomRegistro *Tienda();
	zSiscomRegistro *Proveedor();
	zSiscomRegistro *Producto();
        const char *Stock();
        zSiscomRegistros *Productos();
        int SiguienteProducto();
        int PrimerProducto();
private:
        zSiscomRegistro *zSisRegProveedor;
        zSiscomRegistro *zSisRegProducto;
	zSiscomRegistro *zSisRegTienda;

};

#endif
