#include <QtImpActualizaStock.h>
#include <zReportesServiSNTE.h>
#include <QCtrlTiendasEntrega.h>
#include <QCtrlProveedoresSS.h>
#include <QCtrlProductosSS.h>

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

#include <zStockTienda.h>

#include <zOperacionesServiSNTE.h>
#include <qpushbutton.h>
#include <qlineedit.h>

#include <QCtrlStock.h>
QtImpActualizaStock::QtImpActualizaStock(QWidget *pQWParent,
					       const char *pchrPtrName):
					   ActualizaStock(pQWParent,pchrPtrName),
					   zSisRegProveedor(0),
					   zSisRegTienda(0),
					   zSisRegProducto(0)

{
	Conexion((zSiscomConexion *)gzSiscomConexion);
	IniciaVariables();
	ConectaSlots();
}
void QtImpActualizaStock::IniciaVariables()
{
QCtrTiendas->Servidor(zSisConexion);
QCtrProveedores->Servidor(zSisConexion);
QCtrProductos->Servidor(zSisConexion);
QCtrTiendas->IniciaControl();
QCtrProveedores->IniciaControl();
QCtrStock->Servidor(zSisConexion);

zSiscomQt3::Foco(QCtrTiendas);
}
void QtImpActualizaStock::Conexion(zSiscomConexion *pzSisConexion)
{
	zSisConexion=pzSisConexion;
}
void QtImpActualizaStock::ConectaSlots()
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
	connect(QLEStock,
		SIGNAL(returnPressed()),
		SLOT(SlotFocoAActualizar()));
	connect(QPBConsulta,
		SIGNAL(clicked()),
		SLOT(SlotConsultando()));
	connect(QPBActualizar,
		SIGNAL(clicked()),
		SLOT(SlotActualizar()));
}
void QtImpActualizaStock::SlotProducto(zSiscomRegistro *pzSisRegProducto)
{
	if((zSisRegProducto=pzSisRegProducto))
	{
	QLEStock->setEnabled(QLEStock);
	zSiscomQt3::Foco(QLEStock);
	}
}
void QtImpActualizaStock::SlotActualizar()
{
  Actualizando();
  QCtrStock->ReConsultando();
  zSiscomQt3::Foco(QCtrTiendas);
  HabilitaDesHabilita(false);
  QCtrProductos->ReIniciaControl();
}
void QtImpActualizaStock::SlotFocoAStock()
{
	zSiscomQt3::Foco(QLEStock);
}
void QtImpActualizaStock::SlotFocoAActualizar()
{
	QPBActualizar->setEnabled(true);
	zSiscomQt3::Foco(QPBActualizar);
}
void QtImpActualizaStock::SlotConsultando()
{
QCtrStock->Tienda(zSisRegTienda);
QCtrStock->Proveedor(zSisRegProveedor);
QCtrStock->ConCosto(0);
QCtrStock->IniciaControl();
}
void QtImpActualizaStock::SlotTienda(zSiscomRegistro *pzSisRegTienda)
{
	if((zSisRegTienda=pzSisRegTienda))
	{
	QCtrProveedores->setEnabled(true);
	zSiscomQt3::Foco(QCtrProveedores);
	}
}
void QtImpActualizaStock::SlotProveedor(zSiscomRegistro *pzSisRegProveedor)
{
	if((zSisRegProveedor=pzSisRegProveedor))
	{
	QCtrProductos->setEnabled(true);
	ConsultandoProductosProveedor();
	zSiscomQt3::Foco(QCtrProductos);
	SlotConsultando();
	}
}
void QtImpActualizaStock::Actualizando()
{
zOperacionesServiSNTE lzOpServiSNTE(zSisConexion,"ActualizandoStock");
lzOpServiSNTE.ActualizaStock(zSisRegTienda,
			     zSisRegProducto,
			     zSiscomQt3::Texto(QLEStock));
}
void QtImpActualizaStock::ConsultandoProductosProveedor()
{
	QCtrProductos->Proveedor(zSisRegProveedor);
	QCtrProductos->IniciaControl();
}
void QtImpActualizaStock::HabilitaDesHabilita(bool pbEstado)
{
    QCtrProveedores->setEnabled(pbEstado);
    QCtrProductos->setEnabled(pbEstado);
    QLEStock->setEnabled(pbEstado);
    QPBActualizar->setEnabled(pbEstado);

}
