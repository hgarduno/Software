#include <QtImprimiendoRepProveedores.h>
#include <QtImprimeRepProveedores.h>

#include <zSiscomConexion.h>
#include <zSiscomDesarrollo4.h>
#include <zImpresionProveedores.h>
QtImprimiendoRepProveedores::QtImprimiendoRepProveedores(zSiscomConexion *pzSisConexion,
				zImpresionProveedores *pzProveedores,
				QWidget *pQWParent,
				const char *pchrPtrName,
				bool pbModal,
				WFlags pWFlags):
			QtImprimiendoReporte(pzSisConexion,
					     pzProveedores,
					     pQWParent,
					     pchrPtrName,
					     pbModal,
					     pWFlags),
				zSisConexion(pzSisConexion),
				zImpDatCompra(pzProveedores)
{
Iniciando();
}

QtImprimeReporte *QtImprimiendoRepProveedores::ControlReporte()
{ 
     return new QtImprimeRepProveedores(zSisConexion,
     					zImpDatCompra,
					this,
					"QtImpRepProveedores");
}
