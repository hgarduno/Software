#include <QtImprimiendoRelacionChequesPagar.h>
#include <QtImprimeRelacionChequesPagar.h>

#include <zSiscomConexion.h>
#include <zSiscomDesarrollo4.h>
#include <zImpresionRelacionChequesPagar.h>
QtImprimiendoRelacionChequesPagar::QtImprimiendoRelacionChequesPagar(zSiscomConexion *pzSisConexion,
				zImpresionRelacionChequesPagar *pzRelacionChequesPagar,
				QWidget *pQWParent,
				const char *pchrPtrName,
				bool pbModal,
				WFlags pWFlags):
			QtImprimiendoReporte(pzSisConexion,
					     pzRelacionChequesPagar,
					     pQWParent,
					     pchrPtrName,
					     pbModal,
					     pWFlags),
				zSisConexion(pzSisConexion),
				zRelCheqPagar(pzRelacionChequesPagar)
{
Iniciando();
}

QtImprimeReporte *QtImprimiendoRelacionChequesPagar::ControlReporte()
{ 
     return new QtImprimeRelacionChequesPagar(zSisConexion,
     					zRelCheqPagar,
					this,
					"QtImpRelacionChequesPagar");
}
