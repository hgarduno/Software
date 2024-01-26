#include <QCtrlSaldosMovimientosMes.h>
#include <zOperacionesSaldosMovimientos.h>
#include <zSiscomQt3.h>
#include <zSiscomConexion.h>
#include <zSiscomDesarrollo4.h>
#include <zSiscomRegistro.h>
#include <zSiscomRegistros.h>
#include <zStockTienda.h>


QCtrlSaldosMovimientosMes::QCtrlSaldosMovimientosMes( QWidget *parent, const char *name )
    : QTable( parent, name )

{
	ConectaSlots();
}
void QCtrlSaldosMovimientosMes::IniciaVariables()
{
setReadOnly(true);
}
void QCtrlSaldosMovimientosMes::IniciaControl()
{
	Consultando();  
}
void QCtrlSaldosMovimientosMes::Servidor(zSiscomConexion *pzSisConexion)
{
 zSisConexion=pzSisConexion;
}
void QCtrlSaldosMovimientosMes::ConectaSlots()
{
	connect(this,	
		SIGNAL(clicked(int,int,int,const QPoint &)),
		SLOT(SlotMes(int,int,int,const QPoint &)));

}
void QCtrlSaldosMovimientosMes::SlotMes(int pintMes,
				        int,
					int,
					const QPoint &)
{
emit SignalMes(pintMes+1);
}
void QCtrlSaldosMovimientosMes::Producto(zSiscomRegistro *pzSisRegProducto)
{
	zSisRegProducto=pzSisRegProducto;
}
void QCtrlSaldosMovimientosMes::Proveedor(zSiscomRegistro *pzSisRegProveedor)
{
	zSisRegProveedor=pzSisRegProveedor;
}
void QCtrlSaldosMovimientosMes::Tienda(zSiscomRegistro *pzSisRegTienda)
{
	zSisRegTienda=pzSisRegTienda;
}
void QCtrlSaldosMovimientosMes::FormaEncabezado()
{
  setNumCols(4);
  horizontalHeader()->setLabel(0,"Mes");
  horizontalHeader()->setLabel(1,"Entradas");
  horizontalHeader()->setLabel(2,"Salidas");
  horizontalHeader()->setLabel(3,"Saldo");
}
void QCtrlSaldosMovimientosMes::Consultando()
{
FormaEncabezado();
Consulta();
Muestra();
}
void QCtrlSaldosMovimientosMes::Consulta()
{
zOperacionesSaldosMovimientos lzOpSaldosMovimientos(zSisConexion,"SaldosMovimientosMes");
zSisRegsSaldosMovimientosProdMes=lzOpSaldosMovimientos.ProveedorProductoMes(zSisRegTienda,zSisRegProveedor,zSisRegProducto);
}
void QCtrlSaldosMovimientosMes::Muestra()
{
const char *lchrPtrCampos[]={"Mes","Salidas","Entradas","Existencia",0};
zSiscomQt3::LlenaTabla(lchrPtrCampos,
			zSisRegsSaldosMovimientosProdMes,
			this);
}
