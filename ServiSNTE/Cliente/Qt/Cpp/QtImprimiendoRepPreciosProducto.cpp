#include <QtImprimiendoRepPreciosProducto.h>
#include <QtImprimeRepPreciosProducto.h>

#include <zSiscomConexion.h>
#include <zSiscomDesarrollo4.h>
#include <zImpresionListaPrecios.h>
QtImprimiendoRepPreciosProducto::QtImprimiendoRepPreciosProducto(zSiscomConexion *pzSisConexion,
				zImpresionListaPrecios *pzLstPrecios,
				QWidget *pQWParent,
				const char *pchrPtrName,
				bool pbModal,
				WFlags pWFlags):
			QtImprimiendoReporte(pzSisConexion,
					     pzLstPrecios,
					     pQWParent,
					     pchrPtrName,
					     pbModal,
					     pWFlags),
				zSisConexion(pzSisConexion),
				zLstPrecios(pzLstPrecios)
{
Iniciando();
}

QtImprimeReporte *QtImprimiendoRepPreciosProducto::ControlReporte()
{ 
QtImprimeRepPreciosProducto *lQtImpRepPrecioProducto;
     lQtImpRepPrecioProducto=new QtImprimeRepPreciosProducto(zSisConexion,
     					zLstPrecios,
					this,
					"QtImpRepPreciosProducto");
     lQtImpRepPrecioProducto->Nombre("Productos Para Tienda Por Proveedor");
     return lQtImpRepPrecioProducto;
}
