#include <QtImprimiendoRepDatosCompra.h>
#include <QtImprimeRepDatosCompra.h>

#include <zSiscomConexion.h>
#include <zSiscomDesarrollo4.h>
#include <zImpresionDatosCompra.h>
QtImprimiendoRepDatosCompra::QtImprimiendoRepDatosCompra(zSiscomConexion *pzSisConexion,
				zImpresionDatosCompra *pzDatosCompra,
				QWidget *pQWParent,
				const char *pchrPtrName,
				bool pbModal,
				WFlags pWFlags):
			QtImprimiendoReporte(pzSisConexion,
					     pzDatosCompra,
					     pQWParent,
					     pchrPtrName,
					     pbModal,
					     pWFlags),
				zSisConexion(pzSisConexion),
				zImpDatCompra(pzDatosCompra)
{
Iniciando();
}

QtImprimeReporte *QtImprimiendoRepDatosCompra::ControlReporte()
{ 
     return new QtImprimeRepDatosCompra(zSisConexion,
     					zImpDatCompra,
					this,
					"QtImpRepDatosCompra");
}
