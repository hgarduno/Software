#ifndef __ZORDEN_H__
#define __ZORDEN_H__
#include <zSiscomRegistro.h>

class zProductos;
class zSiscomRegistros;
class zOrden:public zSiscomRegistro
{
   public:
   	zOrden();
	void TipoVenta(zSiscomRegistro *pzSisRegTipoVenta);
	void Financiadora(zSiscomRegistro *pzSisRegFinanciadora);
	void Plazo(zSiscomRegistro *pzSisPlazo);
	void Productos(zProductos *pzProdsOrden);
	zProductos *Productos();
	zSiscomRegistro *Credito();
	void ActualizaImporteProductos(zSiscomRegistros *pzSisRegsProductos);
	void Credito(zSiscomRegistro *pzSisRegCredito);
	void AsignaCostoPrecioProductos(zSiscomRegistros *pzSisRegsProductos);
	void AsignaCostoPrecioProducto(zSiscomRegistro *pzSisRegEntrada);
};

#endif
