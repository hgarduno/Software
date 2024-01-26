#include <QCtrlEstadoInventario.h>

#include <zReportesServiSNTE.h>
#include <zSiscomQt3.h>
#include <zSiscomConexion.h>
#include <zSiscomDesarrollo4.h>
#include <zSiscomRegistro.h>
#include <zSiscomRegistros.h>
#include <zStockTienda.h>


QCtrlEstadoInventario::QCtrlEstadoInventario( QWidget *parent, const char *name )
    : QTable( parent, name )
{
	ConectaSlots();
}
void QCtrlEstadoInventario::IniciaVariables()
{
 FormaEncabezado();
}
void QCtrlEstadoInventario::IniciaControl()
{
	FormaEncabezado();
	ConsultaStock();
	setReadOnly(true);
}
void QCtrlEstadoInventario::ReConsultando()
{
    ConsultaStock();
}
void QCtrlEstadoInventario::Servidor(zSiscomConexion *pzSisConexion)
{
 zSisConexion=pzSisConexion;
}
void QCtrlEstadoInventario::ConsultaStock()
{
zReportesServiSNTE lzRepServiSNTE(zSisConexion,"StockTienda");
zLstStock=lzRepServiSNTE.StockTienda(zSisRegTienda,zSisRegProveedor );
zLstStock->Tienda(zSisRegTienda);
}
void QCtrlEstadoInventario::ConectaSlots()
{
}
void QCtrlEstadoInventario::Tienda(zSiscomRegistro *pzSisRegTienda)
{  
	zSisRegTienda=pzSisRegTienda;
}
