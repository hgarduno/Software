#include <QCtrlSoporteVentas.h>

#include <zReportesServiSNTE.h>
#include <zSiscomQt3.h>
#include <zSiscomConexion.h>
#include <zSiscomDesarrollo4.h>
#include <zSiscomRegistro.h>
#include <zSiscomRegistros.h>
#include <zStockTienda.h>


QCtrlSoporteVentas::QCtrlSoporteVentas( QWidget *parent, const char *name )
    : QTable( parent, name )
{
	ConectaSlots();
}
void QCtrlSoporteVentas::IniciaVariables()
{
 FormaEncabezado();
}
void QCtrlSoporteVentas::IniciaControl()
{
	FormaEncabezado();
	ConsultaStock();
	setReadOnly(true);
}
void QCtrlSoporteVentas::ReConsultando()
{
    ConsultaStock();
}
void QCtrlSoporteVentas::Servidor(zSiscomConexion *pzSisConexion)
{
 zSisConexion=pzSisConexion;
}
void QCtrlSoporteVentas::ConsultaStock()
{
zReportesServiSNTE lzRepServiSNTE(zSisConexion,"StockTienda");
zLstStock=lzRepServiSNTE.StockTienda(zSisRegTienda,zSisRegProveedor );
zLstStock->Tienda(zSisRegTienda);
}
void QCtrlSoporteVentas::ConectaSlots()
{
}
void QCtrlSoporteVentas::Tienda(zSiscomRegistro *pzSisRegTienda)
{  
	zSisRegTienda=pzSisRegTienda;
}
