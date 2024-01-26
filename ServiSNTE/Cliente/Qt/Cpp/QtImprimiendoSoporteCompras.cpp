#include <QtImprimiendoSoporteCompras.h>
#include <QtImprimeSoporteCompras.h>

#include <zSiscomConexion.h>
#include <zSiscomDesarrollo4.h>
#include <zImpresionSoporteCompras.h>
QtImprimiendoSoporteCompras::QtImprimiendoSoporteCompras(zSiscomConexion *pzSisConexion,
				zImpresionSoporteCompras *pzSoporteCompras,
				QWidget *pQWParent,
				const char *pchrPtrName,
				bool pbModal,
				WFlags pWFlags):
			QtImprimiendoReporte(pzSisConexion,
					     pzSoporteCompras,
					     pQWParent,
					     pchrPtrName,
					     pbModal,
					     pWFlags),
				zSisConexion(pzSisConexion),
				zSopComp(pzSoporteCompras)
{
Iniciando();
}

QtImprimeReporte *QtImprimiendoSoporteCompras::ControlReporte()
{ 
     return new QtImprimeSoporteCompras(zSisConexion,
     					zSopComp,
					this,
					"QtImpSoporteCompras");
}
