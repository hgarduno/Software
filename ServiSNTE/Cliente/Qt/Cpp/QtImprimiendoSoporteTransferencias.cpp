#include <QtImprimiendoSoporteTransferencias.h>
#include <QtImprimeSoporteTransferencias.h>

#include <zSiscomConexion.h>
#include <zSiscomDesarrollo4.h>
#include <zImpresionSoporteTransferencias.h>
QtImprimiendoSoporteTransferencias::QtImprimiendoSoporteTransferencias(zSiscomConexion *pzSisConexion,
				zImpresionSoporteTransferencias *pzSoporteTransferencias,
				QWidget *pQWParent,
				const char *pchrPtrName,
				bool pbModal,
				WFlags pWFlags):
			QtImprimiendoReporte(pzSisConexion,
					     pzSoporteTransferencias,
					     pQWParent,
					     pchrPtrName,
					     pbModal,
					     pWFlags),
				zSisConexion(pzSisConexion),
				zSptTransferencias(pzSoporteTransferencias)
{
Iniciando();
}

QtImprimeReporte *QtImprimiendoSoporteTransferencias::ControlReporte()
{ 
     return new QtImprimeSoporteTransferencias(zSisConexion,
     					zSptTransferencias,
					this,
					"QtImpSoporteTransferencias");
}
