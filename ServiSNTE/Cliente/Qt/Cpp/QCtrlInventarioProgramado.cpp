#include <QCtrlInventarioProgramado.h>

#include <zReportesServiSNTE.h>
#include <zSiscomQt3.h>
#include <zSiscomConexion.h>
#include <zSiscomDesarrollo4.h>
#include <zSiscomRegistro.h>
#include <zSiscomRegistros.h>
#include <zStockTienda.h>


QCtrlInventarioProgramado::QCtrlInventarioProgramado( QWidget *parent, const char *name )
    : QTable( parent, name )
{
	ConectaSlots();
}
void QCtrlInventarioProgramado::IniciaVariables()
{
 FormaEncabezado();
}
void QCtrlInventarioProgramado::IniciaControl()
{
	FormaEncabezado();
	ConsultaStock();
	setReadOnly(true);
}
void QCtrlInventarioProgramado::ReConsultando()
{
    ConsultaStock();
}
void QCtrlInventarioProgramado::Servidor(zSiscomConexion *pzSisConexion)
{
 zSisConexion=pzSisConexion;
}
void QCtrlInventarioProgramado::ConsultaStock()
{
zReportesServiSNTE lzRepServiSNTE(zSisConexion,"StockTienda");
zLstStock=lzRepServiSNTE.StockTienda(zSisRegTienda,zSisRegProveedor );
zLstStock->Tienda(zSisRegTienda);
}
void QCtrlInventarioProgramado::ConectaSlots()
{
}
void QCtrlInventarioProgramado::Tienda(zSiscomRegistro *pzSisRegTienda)
{  
	zSisRegTienda=pzSisRegTienda;
}
