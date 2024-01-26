#include <QtImpSaldosMovimientos.h>
#include <QCtrlTiendasEntrega.h>
#include <QCtrlProveedoresSS.h>
#include <QCtrlProductosSS.h>
#include <QCtrlStock.h>
#include <QCtrlExistenciaProveedor.h>
#include <QCtrlSaldosMovimientosMes.h>
#include <QCtrlConceptosSaldosMovimientos.h>
#include <zSiscomConexion.h>
#include <zSiscomOperaciones.h>
#include <zSiscomConexion.h>
#include <zSiscomRegistros.h>
#include <zSiscomRegistro.h>
#include <zSiscomDesarrollo4.h>
#include <zSiscomEnviaArchivo.h>
#include <zSiscomRecibeArchivo.h>
#include <zSiscomQt3.h>
#include <zSiscomCampo.h>

#include <zOperacionesServiSNTE.h>
#include <zExistenciaProveedor.h>
#include <qpushbutton.h>
#include <qlineedit.h>
#include <qtabwidget.h>
QtImpSaldosMovimientos::QtImpSaldosMovimientos(QWidget *pQWParent,
					       const char *pchrPtrName):
					   SaldosMovimientos(pQWParent,pchrPtrName)
{
	
	Conexion((zSiscomConexion *)gzSiscomConexion);
	IniciaVariables();
	ConectaSlots();
}
void QtImpSaldosMovimientos::IniciaVariables()
{
QCtrTiendas->Servidor(zSisConexion);
QCtrProveedores->Servidor(zSisConexion);
QCtrProductos->Servidor(zSisConexion);
QCtrExistenciaProveedor->Servidor(zSisConexion);
QCtrSaldosMovimientosMes->Servidor(zSisConexion);
QCtrConceptosSaldosMovimientos->Servidor(zSisConexion);

QCtrExistenciaProveedor->TipoVista(0);


QCtrTiendas->IniciaControl();
QCtrProveedores->IniciaControl();
QCtrStock->Servidor(zSisConexion);
zSiscomQt3::Foco(QCtrTiendas);
}
void QtImpSaldosMovimientos::Conexion(zSiscomConexion *pzSisConexion)
{
	zSisConexion=pzSisConexion;
}
void QtImpSaldosMovimientos::ConectaSlots()
{
	connect(QCtrTiendas,
		SIGNAL(SignalTienda(zSiscomRegistro *)),
		SLOT(SlotTienda(zSiscomRegistro *)));
	connect(QCtrProveedores,
		SIGNAL(SignalProveedor(zSiscomRegistro *)),
		SLOT(SlotProveedor(zSiscomRegistro *)));
	connect(QCtrProductos,
		SIGNAL(SignalProducto(zSiscomRegistro *)),
		SLOT(SlotProducto(zSiscomRegistro *)));
	connect(QCtrSaldosMovimientosMes,
		SIGNAL(SignalMes(int)),
		SLOT(SlotMes(int)));

}
void QtImpSaldosMovimientos::SlotMes(int pintMes)
{
LogSiscom("El Mes seleccionado %d",pintMes);
QCtrConceptosSaldosMovimientos->Producto(zSisRegProducto);
QCtrConceptosSaldosMovimientos->Tienda(zSisRegTienda);
QCtrConceptosSaldosMovimientos->IniciaControl();
}
void QtImpSaldosMovimientos::SlotConsultando()
{
QCtrStock->Tienda(zSisRegTienda);
QCtrStock->Proveedor(zSisRegProveedor);
QCtrStock->ConCosto(0);
QCtrStock->IniciaControl();
}
void QtImpSaldosMovimientos::SlotProducto(zSiscomRegistro *pzSisRegProducto)
{
	zSisRegProducto=pzSisRegProducto;
	SaldosProducto();
	SaldosMovimientosMes();
	QTWInformacion->setCurrentPage(1);
}
void QtImpSaldosMovimientos::SlotTienda(zSiscomRegistro *pzSisRegTienda)
{
	zSisRegTienda=pzSisRegTienda;
	zSiscomQt3::Foco(QCtrProveedores);
}
void QtImpSaldosMovimientos::SlotProveedor(zSiscomRegistro *pzSisRegProveedor)
{
	QTWInformacion->setCurrentPage(0);
	zSisRegProveedor=pzSisRegProveedor;
	ConsultandoProductosProveedor();
	zSiscomQt3::Foco(QCtrProductos);
	SlotConsultando();
}

void QtImpSaldosMovimientos::ConsultandoProductosProveedor()
{
	QCtrProductos->Proveedor(zSisRegProveedor);
	QCtrProductos->IniciaControl();
}
void QtImpSaldosMovimientos::SaldosProducto()
{
	QCtrExistenciaProveedor->Producto(zSisRegProducto);
	QCtrExistenciaProveedor->Proveedor(zSisRegProveedor);
	QCtrExistenciaProveedor->IniciaControl();
	zExiProveedor=QCtrExistenciaProveedor->ExistenciaProveedor();
	MuestraTotalesProducto();
}
void QtImpSaldosMovimientos::MuestraTotalesProducto()
{

    if(zExiProveedor->PrimerProducto())
    {
	QLEStockTotal->setText(zExiProveedor->TotalStock());
	QLEExistenciaTotal->setText(zExiProveedor->TotalExistencia());
    }
}
void QtImpSaldosMovimientos::SaldosMovimientosMes()
{
QCtrSaldosMovimientosMes->Producto(zSisRegProducto);
QCtrSaldosMovimientosMes->Proveedor(zSisRegProveedor);
QCtrSaldosMovimientosMes->Tienda(zSisRegTienda);
QCtrSaldosMovimientosMes->IniciaControl();
LogSiscom("Corriendo los saldos movimientos por mes");
}
