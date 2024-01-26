#ifndef __ZEXISTENCIAPROVEEDOR_H__
#define __ZEXISTENCIAPROVEEDOR_H__
#include <zSiscomRegistros.h>
class zExistenciaProveedor:public zSiscomRegistros
{
public:
	zExistenciaProveedor();
	void Proveedor(zSiscomRegistro *pzSisRegProveedor);
	const char *NumeroProducto();
	const char *NombreProducto();
	const char *Modelo();
	const char *TotalStock();
	const char *TotalExistencia();
	const char *CostoTotal();
	zSiscomRegistro *Producto();
	zSiscomRegistro *Proveedor();

	const char *Siglas();
	const char *Nombre();
	const char *IdTienda();
	zSiscomRegistro *Tienda();

	const char *Stock();
	const char *Existencia();
	int SiguienteProducto();
	int PrimerProducto();
	int SiguienteTienda();
	int PrimerTienda();

	int NTiendas();

private:
	zSiscomRegistro *zSisRegProducto;	
	zSiscomRegistro *zSisRegTienda;

	zSiscomRegistro *zSisRegProveedor;
};
#endif
