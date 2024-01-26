#include <QtImprimiendoRepExistenciaProveedor.h>
#include <QtImprimeRepExistenciaProveedor.h>

#include <zSiscomConexion.h>
#include <zSiscomDesarrollo4.h>
#include <zImpresionExistenciaProveedor.h>
QtImprimiendoRepExistenciaProveedor::QtImprimiendoRepExistenciaProveedor(zSiscomConexion *pzSisConexion,
				zImpresionExistenciaProveedor *pzExistenciaProveedor,
				QWidget *pQWParent,
				const char *pchrPtrName,
				bool pbModal,
				WFlags pWFlags):
			QtImprimiendoReporte(pzSisConexion,
					     pzExistenciaProveedor,
					     pQWParent,
					     pchrPtrName,
					     pbModal,
					     pWFlags),
				zSisConexion(pzSisConexion),
				zStkTienda(pzExistenciaProveedor)
{
Iniciando();
}

QtImprimeReporte *QtImprimiendoRepExistenciaProveedor::ControlReporte()
{ 
     return new QtImprimeRepExistenciaProveedor(zSisConexion,
     					zStkTienda,
					this,
					"QtImpRepExistenciaProveedor");
}
