#ifndef __ZCOTIZACIONIMPORTACION_H__
#define __ZCOTIZACIONIMPORTACION_H__
#include <zSiscomRegistro.h>
class zProductosCotImp;
class zProductoCotImp;
class zCotizacionImportacion:public zSiscomRegistro
{
public:
	zCotizacionImportacion();
	~zCotizacionImportacion();

	void Cotizacion(const char *pchrPtrCotizacion);
	void CostoDolar(const char *pchrPtrCostoDolar);
	void Proveedor(zSiscomRegistro *pzSisRegProveedor);
	void IdCotizacion(const char *pchrPtrIdCotizacion);
	void PesoTotal(const char *pchrPtrPesoTotal);
	void ImporteTotal(const char *pchrPtrImporteTotal);
	void Productos(zProductosCotImp *pzProdsCotImp);
	void Agrega(zProductosCotImp *pzProdsCotImp);
	void Agrega(zSiscomRegistros *pzSisRegsProductos);
	void Agrega(zProductoCotImp *);

	const char *RazonSocial();
	const char *Cotizacion();
	const char *PesoTotal();
	const char *ImporteTotal();
	const char *CostoDolar();
	zProductosCotImp *Productos();
	zProductoCotImp *Producto(int pintNProducto);
	void PesoTotalProducto(const char *pchrPtrCve,const char *);
	void PesoTotalProductos(zSiscomRegistros *);
	void ImporteProducto(const char *pchrPtrClave,const char *pchrPtrImporte);
	void ImporteProductos(zSiscomRegistros *);

};


#endif
