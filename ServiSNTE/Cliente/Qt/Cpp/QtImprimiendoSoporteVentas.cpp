#include <QtImprimiendoSoporteVentas.h>
#include <QtImprimeSoporteVentas.h>

#include <zSiscomConexion.h>
#include <zSiscomDesarrollo4.h>
#include <zImpresionSoporteVentas.h>
QtImprimiendoSoporteVentas::QtImprimiendoSoporteVentas(zSiscomConexion *pzSisConexion,
				zImpresionSoporteVentas *pzSoporteVentas,
				QWidget *pQWParent,
				const char *pchrPtrName,
				bool pbModal,
				WFlags pWFlags):
			QtImprimiendoReporte(pzSisConexion,
					     pzSoporteVentas,
					     pQWParent,
					     pchrPtrName,
					     pbModal,
					     pWFlags),
				zSisConexion(pzSisConexion),
				zSptVentas(pzSoporteVentas)
{
Iniciando();
}

QtImprimeReporte *QtImprimiendoSoporteVentas::ControlReporte()
{ 
     return new QtImprimeSoporteVentas(zSisConexion,
     					zSptVentas,
					this,
					"QtImpSoporteVentas");
}
