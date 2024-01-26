#ifndef __ZPRODUCTO_H__
#define __ZPRODUCTO_H__
#include <zSiscomRegistro.h>

class zCostos;
class zCosto;
class zDescuento;
class zPrecio;
class zProducto:public zSiscomRegistro
{
public:
	zProducto();
	zProducto(zSiscomRegistro *pzSiscomRegistro);
	zProducto(zSiscomRegistro *pzSisProducto,
		  const char *pchrPtrSerie,
		  const char *pchrPtrCantidad);
	zProducto(zSiscomRegistro *pzSisRegProveedor,
		  zSiscomRegistro *pzSisRegDepartamento,
		  const char *pchrPtrIdProducto,
		  const char *pchrPtrNombre,
		  const char *pchrPtrModelo,
		  const char *pchrPtrNumeroProducto);
	zProducto(zSiscomRegistro *pzSisRegProveedor,
		  zSiscomRegistro *pzSisRegDepartamento,
		  const char *pchrPtrIdProducto,
		  const char *pchrPtrNombre,
		  const char *pchrPtrModelo,
		  const char *pchrPtrNumeroProducto,
		  const char *pchrPtrPrecio,
		  zDescuento *pzDescuento,
		  zCosto *pzCosto);

	void AgregaCostos(zCostos *pzCCBruto,
			  zCostos *pzCCGeneral,
			  zCostos *pzCCForaneo,
			  zDescuento *pzCDescuento);
	void AgregaCostoBruto(const char *pchrPtrCosto);
	void ParaInventario(const char *pchrPtrCantidad,
				  const char *pchrPtrCodigoBarras);
	
	const char *CodigoBarras();

	const char *SePuedeVender();

	void Descuentos(zDescuento *pzDescuentos);
	void Costo(zCosto *pzCosto);
	void Precio(zPrecio *pzPrecio);
	void PrecioForaneo(zPrecio *pzPrecio);
};



#endif
