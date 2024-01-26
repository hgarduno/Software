#include <QtImprimiendoRepStockTienda.h>
#include <QtImprimeRepStockTienda.h>

#include <zSiscomConexion.h>
#include <zSiscomDesarrollo4.h>
#include <zImpresionStockTienda.h>
QtImprimiendoRepStockTienda::QtImprimiendoRepStockTienda(zSiscomConexion *pzSisConexion,
				zImpresionStockTienda *pzStockTienda,
				QWidget *pQWParent,
				const char *pchrPtrName,
				bool pbModal,
				WFlags pWFlags):
			QtImprimiendoReporte(pzSisConexion,
					     pzStockTienda,
					     pQWParent,
					     pchrPtrName,
					     pbModal,
					     pWFlags),
				zSisConexion(pzSisConexion),
				zStkTienda(pzStockTienda)
{
Iniciando();
}

QtImprimeReporte *QtImprimiendoRepStockTienda::ControlReporte()
{ 
     return new QtImprimeRepStockTienda(zSisConexion,
     					zStkTienda,
					this,
					"QtImpRepStockTienda");
}
