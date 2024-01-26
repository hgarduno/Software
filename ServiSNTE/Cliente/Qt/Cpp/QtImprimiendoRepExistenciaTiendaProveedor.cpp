#include <QtImprimiendoRepExistenciaTiendaProveedor.h>
#include <QtImprimeRepExistenciaTiendaProveedor.h>

#include <zSiscomConexion.h>
#include <zSiscomDesarrollo4.h>
#include <zImpresionExistenciaTiendaProveedor.h>
QtImprimiendoRepExistenciaTiendaProveedor::QtImprimiendoRepExistenciaTiendaProveedor(zSiscomConexion *pzSisConexion,
				zImpresionExistenciaTiendaProveedor *pzExistenciaTiendaProveedor,
				QWidget *pQWParent,
				const char *pchrPtrName,
				bool pbModal,
				WFlags pWFlags):
			QtImprimiendoReporte(pzSisConexion,
					     pzExistenciaTiendaProveedor,
					     pQWParent,
					     pchrPtrName,
					     pbModal,
					     pWFlags),
				zSisConexion(pzSisConexion),
				zExtTiendaProveedor(pzExistenciaTiendaProveedor)
{
Iniciando();
}

QtImprimeReporte *QtImprimiendoRepExistenciaTiendaProveedor::ControlReporte()
{ 
     return new QtImprimeRepExistenciaTiendaProveedor(zSisConexion,
     					zExtTiendaProveedor,
					this,
					"QtImpRepExistenciaTiendaProveedor");
}
