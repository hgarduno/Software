#include <QtImprimiendoRepListaPreciosComprador.h>
#include <QtImprimeRepListaPreciosComprador.h>

#include <zSiscomConexion.h>
#include <zSiscomDesarrollo4.h>
#include <zImpresionListaPreciosComprador.h>
QtImprimiendoRepListaPreciosComprador::QtImprimiendoRepListaPreciosComprador(zSiscomConexion *pzSisConexion,
				zImpresionListaPreciosComprador *pzListaPreciosComprador,
				QWidget *pQWParent,
				const char *pchrPtrName,
				bool pbModal,
				WFlags pWFlags):
			QtImprimiendoReporte(pzSisConexion,
					     pzListaPreciosComprador,
					     pQWParent,
					     pchrPtrName,
					     pbModal,
					     pWFlags),
				zSisConexion(pzSisConexion),
				zStkTienda(pzListaPreciosComprador)
{
Iniciando();
}

QtImprimeReporte *QtImprimiendoRepListaPreciosComprador::ControlReporte()
{ 
     return new QtImprimeRepListaPreciosComprador(zSisConexion,
     					zStkTienda,
					this,
					"QtImpRepListaPreciosComprador");
}
