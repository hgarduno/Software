#include <QtImprimiendoRepStockProveedorCosto.h>
#include <QtImprimeRepStockProveedorCosto.h>

#include <zSiscomConexion.h>
#include <zSiscomDesarrollo4.h>
#include <zImpresionStockProveedorCosto.h>
QtImprimiendoRepStockProveedorCosto::QtImprimiendoRepStockProveedorCosto(zSiscomConexion *pzSisConexion,
				zImpresionStockProveedorCosto *pzStockProveedorCosto,
				QWidget *pQWParent,
				const char *pchrPtrName,
				bool pbModal,
				WFlags pWFlags):
			QtImprimiendoReporte(pzSisConexion,
					     pzStockProveedorCosto,
					     pQWParent,
					     pchrPtrName,
					     pbModal,
					     pWFlags),
				zSisConexion(pzSisConexion),
				zStkTienda(pzStockProveedorCosto)
{
Iniciando();
}

QtImprimeReporte *QtImprimiendoRepStockProveedorCosto::ControlReporte()
{ 
     return new QtImprimeRepStockProveedorCosto(zSisConexion,
     					zStkTienda,
					this,
					"QtImpRepStockProveedorCosto");
}
