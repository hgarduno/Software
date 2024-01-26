#include <QtImprimiendoRepCuentasPagar.h>
#include <QtImprimeRepCuentasPagar.h>

#include <zSiscomConexion.h>
#include <zSiscomDesarrollo4.h>
#include <zImpresionCuentasPagar.h>
QtImprimiendoRepCuentasPagar::QtImprimiendoRepCuentasPagar(zSiscomConexion *pzSisConexion,
				zImpresionCuentasPagar *pzCuentasPagar,
				QWidget *pQWParent,
				const char *pchrPtrName,
				bool pbModal,
				WFlags pWFlags):
			QtImprimiendoReporte(pzSisConexion,
					     pzCuentasPagar,
					     pQWParent,
					     pchrPtrName,
					     pbModal,
					     pWFlags),
				zSisConexion(pzSisConexion),
				zCtsPagar(pzCuentasPagar)
{
Iniciando();
}

QtImprimeReporte *QtImprimiendoRepCuentasPagar::ControlReporte()
{ 
     return new QtImprimeRepCuentasPagar(zSisConexion,
     					zCtsPagar,
					this,
					"QtImpRepCuentasPagar");
}
