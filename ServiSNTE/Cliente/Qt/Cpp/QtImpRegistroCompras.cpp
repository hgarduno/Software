#include <QtImpRegistroCompras.h>
#include <QtImpCapturaCantidad.h>
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

#include <zCosto.h>
#include <zOperacionesServiSNTE.h>
#include <zProducto.h>

#include <qpushbutton.h>
#include <qlineedit.h>
#include <qcheckbox.h>
#include <qstring.h>
#include <qtable.h>
#include <qlcdnumber.h>
#include <qclipboard.h>
#include <QCtrlProveedoresSS.h>
#include <QCtrlProductosSS.h>
#include <QCtrlTipoDocumentos.h>
#include <QCtrlConceptosExistencias.h>
#include <QBarCode.h>
#include <stdio.h>
#include <string.h>
#include <qapplication.h>
QtImpRegistroCompras::QtImpRegistroCompras(QWidget *pQWParent,
				     const char *pchrPtrName):
				     RegistroCompras(pQWParent,pchrPtrName)
{
 Conexion((zSiscomConexion *)gzSiscomConexion);
 ConectaSlots();
 IniciaControles();
}

void QtImpRegistroCompras::Conexion(zSiscomConexion *pzSisConexion)
{
	zSisConexion=pzSisConexion;
}

void QtImpRegistroCompras::ConectaSlots()
{
	connect(QCtrProveedor,
		SIGNAL(SignalProveedor(zSiscomRegistro *)),
		SLOT(SlotProveedor(zSiscomRegistro *)));
	connect(QCtrTipoDocumento,
		SIGNAL(SignalTipoDocumento(zSiscomRegistro *)),
		SLOT(SlotTipoDocumento(zSiscomRegistro *)));
	connect(QCtrConcepto,
		SIGNAL(SignalConcepto(zSiscomRegistro *)),
		SLOT(SlotConcepto(zSiscomRegistro *)));
	connect(QCtrProducto,
		SIGNAL(SignalProducto(zSiscomRegistro *)),
		SLOT(SlotProducto(zSiscomRegistro *)));
	connect(QLESerieFactura,
		SIGNAL(returnPressed()),
		SLOT(SlotFocoAFolio()));
	connect(QLESerieProducto,
		SIGNAL(returnPressed()),
		SLOT(SlotFocoACantidad()));
	connect(QLECantidad,
		SIGNAL(returnPressed()),
		SLOT(SlotFocoAAgregar()));
	connect(QLEFolio,
		SIGNAL(returnPressed()),
		SLOT(SlotFocoAConcepto()));
	connect(QPBAgregar,
		SIGNAL(clicked()),
		SLOT(SlotAgregarProducto()));
	connect(QPBRegistrar,
		SIGNAL(clicked()),
		SLOT(SlotRegistraCompra()));

	connect(QTDetalleCompra,
		SIGNAL(clicked(int,int,int,const QPoint &)),
		SLOT(SlotProductoOrden(int,int,int,const QPoint &)));
	connect(QTDetalleCompra,
		SIGNAL(doubleClicked(int,int,int,const QPoint &)),
		SLOT(SlotCambiaCantidad(int,int,int,const QPoint &)));
	connect(QPBEliminar,
		SIGNAL(clicked()),
		SLOT(SlotEliminarProductoOrden()));

	connect(QLEFecha,
		SIGNAL(returnPressed()),
		SLOT(SlotFocoATipoDocumento()));
	connect(QPBCopiar,
		SIGNAL(clicked()),
		SLOT(SlotCopiar()));

}
void QtImpRegistroCompras::SlotCopiar()
{
QString lQStrProductos;
  CreaListaProductos(lQStrProductos);
  QApplication::clipboard()->setText(lQStrProductos);
}
void QtImpRegistroCompras::SlotFocoATipoDocumento()
{
   HabilitaTipoDocumento();
}
void QtImpRegistroCompras::SlotCambiaCantidad(int pintNFila,
					      int pintNColumna,
					      int,
					      const QPoint &)
{
   if(pintNColumna==2)
   CambiandoCantidad(pintNFila);

}
void QtImpRegistroCompras::SlotEliminarProductoOrden()
{
   zProdsOrden.Elimina(intProductoSeleccionado);
   MuestraCompra();
}
void QtImpRegistroCompras::SlotProductoOrden(int pintNProducto,
					     int pintColumna,
					     int,
					     const QPoint &)
{
 if(pintNProducto!=-1)
 {
  intProductoSeleccionado=pintNProducto;
  QTDetalleCompra->selectRow(pintNProducto);
  QPBEliminar->setEnabled(true);
 }

}
void QtImpRegistroCompras::SlotFocoACantidad()
{
 QLECantidad->setEnabled(true);
 zSiscomQt3::Foco(QLECantidad); 
}
void QtImpRegistroCompras::SlotFocoAAgregar()
{
 zSiscomQt3::Foco(QPBAgregar);

}
void QtImpRegistroCompras::SlotRegistraCompra()
{
  IniciaRegistroCompra();
  ProductosALaCompra();
  RegistraCompra();
  ReIniciaCompras();
   
}
void QtImpRegistroCompras::SlotAgregarProducto()
{
     zSiscomQt3::Foco(QCtrProducto);
     AgregandoProducto();
     HabilitaRegistraCompra();
}
void QtImpRegistroCompras::SlotProveedor(zSiscomRegistro *pzSisProveedor)
{
	zSisProveedor=pzSisProveedor;
	/*
	ObtenFechaCompra(); 
	*/
	QCtrProducto->Proveedor(zSisProveedor);
	QCtrProducto->IniciaControl();
	QLEFecha->setEnabled(true);
	zSiscomQt3::Foco(QLEFecha);
	/*
	HabilitaTipoDocumento(); 
	*/
}
void QtImpRegistroCompras::SlotTipoDocumento(zSiscomRegistro *pzSisTipoDocumento)
{
	zSisTipoDocumento=pzSisTipoDocumento;
	HabilitaSerieFactura();
}
void QtImpRegistroCompras::SlotConcepto(zSiscomRegistro *pzSisConcepto)
{
	zSisConcepto=pzSisConcepto;
	HabilitaStockYProductos();
}
void QtImpRegistroCompras::SlotProducto(zSiscomRegistro *pzSisProducto)
{
	zSisProducto=pzSisProducto;
	QLEModelo->setText((const char *)(*zSisProducto)["modelo"]);
	FocoASerieProducto();
	QPBAgregar->setEnabled(true);
}
void QtImpRegistroCompras::SlotFocoAFolio()
{
	QLEFolio->setEnabled(true);
	zSiscomQt3::Foco(QLEFolio);
}
void QtImpRegistroCompras::SlotFocoAConcepto()
{
	QCtrConcepto->setEnabled(true);
	zSiscomQt3::Foco(QCtrConcepto);
}
void QtImpRegistroCompras::SlotHabilitaBotonAgregar()
{
	QPBAgregar->setEnabled(true);
	zSiscomQt3::Foco(QPBAgregar);
}
void QtImpRegistroCompras::IniciaControles()
{
QCtrProveedor->Servidor(zSisConexion);
QCtrProveedor->IniciaControl();
QCtrTipoDocumento->Servidor(zSisConexion);
QCtrTipoDocumento->IniciaControl();
QCtrConcepto->Servidor(zSisConexion);
QCtrConcepto->IniciaControl();
QCtrProducto->Servidor(zSisConexion);
zSiscomQt3::Foco(QCtrProveedor);
}

void QtImpRegistroCompras::HabilitaTipoDocumento()
{
	QCtrTipoDocumento->setEnabled(true);
	zSiscomQt3::Foco(QCtrTipoDocumento);
}
void QtImpRegistroCompras::HabilitaSerieFactura()
{
	QLESerieFactura->setEnabled(true);
	zSiscomQt3::Foco(QLESerieFactura);
}
void QtImpRegistroCompras::HabilitaStockYProductos()
{
	QCtrProducto->setEnabled(true);
	zSiscomQt3::Foco(QCtrProducto);
}
void QtImpRegistroCompras::FocoASerieProducto()
{
	QLESerieProducto->setEnabled(true);
	zSiscomQt3::Foco(QLESerieProducto);
}
void QtImpRegistroCompras::AgregaProductoCompra()
{
zProducto *lzProducto;
     lzProducto= new zProducto(zSisProducto,
     				zSiscomQt3::Texto(QLESerieProducto),
				zSiscomQt3::Texto(QLECantidad));
    zProdsOrden <<lzProducto;
}
void QtImpRegistroCompras::MuestraCompra()
{
 int lintContador;
 zSiscomRegistro *lzSisRegistro;
 QTDetalleCompra->setNumRows(zProdsOrden.NNodos());
 for(lzSisRegistro=zProdsOrden.Primer(),
     lintContador=0;
     lzSisRegistro;
     lzSisRegistro=zProdsOrden.Siguiente(),
     lintContador++)
 {
   QTDetalleCompra->setText(lintContador,0,(const char *)(*lzSisRegistro)["nombreproducto"]);
   QTDetalleCompra->setText(lintContador,1,(const char *)(*lzSisRegistro)["modelo"]);
   QTDetalleCompra->setText(lintContador,2,(const char *)(*lzSisRegistro)["Cantidad"]);
 }
}
void QtImpRegistroCompras::HabilitaRegistraCompra()
{
  QPBRegistrar->setEnabled(zProdsOrden.NNodos());
}
void QtImpRegistroCompras::IniciaRegistroCompra()
{
   zCompraC.IdProveedor((*zSisProveedor)["idempresa"]);
   zCompraC.IdTipoDocumento((*zSisTipoDocumento)["idtipodocumento"]);
   zCompraC.IdConcepto((*zSisConcepto)["idconceptosexistencias"]);
   zCompraC.SerieFactura(zSiscomQt3::Texto(QLESerieFactura));
   zCompraC.Folio(zSiscomQt3::Texto(QLEFolio));
   zCompraC.Orden(&zOrdenCompra);
}
void QtImpRegistroCompras::RegistraCompra()
{
zOperacionesServiSNTE lzOpeServiSNTERegCompra(zSisConexion,"RegistraCompra");
zCompraC.Fecha(strdup((const char *)QLEFecha->text()));
lzOpeServiSNTERegCompra.RegistraCompra(&zCompraC);
}

void QtImpRegistroCompras::AgregandoProducto()
{
    AgregaProductoCompra();
    MuestraCompra();
}
void QtImpRegistroCompras::ProductosALaCompra()
{
 zOrdenCompra.Productos(&zProdsOrden);

}
void QtImpRegistroCompras::ObtenFechaCompra()
{
char lchrArrFechaCompra[12];
zOperacionesServiSNTE lzOpServiSNTE(zSisConexion,"FechaCompraProveedor");
if((intFechaCompraRegistrada=lzOpServiSNTE.FechaCompraProveedor(zSisProveedor,lchrArrFechaCompra)))
QLEFecha->setText(lchrArrFechaCompra);
}

void QtImpRegistroCompras::ReIniciaCompras()
{
  QTDetalleCompra->setNumRows(0);
  zProdsOrden.Libera();
  zSisProveedor=0;
  zSisTipoDocumento=0;
  zSisConcepto=0;
  zSisProducto=0;
  QCtrTipoDocumento->setEnabled(false);
  QLESerieFactura->setEnabled(false);
  QLEFolio->setEnabled(false);
  QLEFecha->setEnabled(false);
  QCtrConcepto->setEnabled(false);
  QCtrProducto->setEnabled(false);
  QLESerieProducto->setEnabled(false);
  QLECantidad->setEnabled(false);
  QPBRegistrar->setEnabled(false);
  QPBImprimir->setEnabled(false);
  QPBAgregar->setEnabled(false);
  QPBEliminar->setEnabled(false);
  zSiscomQt3::Foco(QCtrProveedor);

}
void QtImpRegistroCompras::CambiaCantidad(int pintNProducto)
{
QtImpCapturaCantidad lQtCapturaCantidad;
zProducto *lzProducto;
QString lQStrCantidad;
const char *lchrPtrCantidad;
if(lQtCapturaCantidad.Aceptar())
{
   lzProducto=(zProducto *)zProdsOrden[pintNProducto];
   lQtCapturaCantidad.Cantidad(&lQStrCantidad);
   lchrPtrCantidad=(const char *)lQStrCantidad;
   lzProducto->ActualizaCampo("Cantidad",(const unsigned char *)strdup(lchrPtrCantidad));
   SiscomRegistroLog2(lzProducto); 
}
}
void QtImpRegistroCompras::CambiandoCantidad(int pintNProducto)
{
	CambiaCantidad(pintNProducto);
	MuestraCompra();
	SiscomRegistrosLog(&zProdsOrden);
}
void QtImpRegistroCompras::CreaListaProductos(QString &pQStrProductos)
{
zProducto *lzSisRegProducto;
for(lzSisRegProducto=(zProducto *)zProdsOrden.Primer();
    lzSisRegProducto;
    lzSisRegProducto=(zProducto *)zProdsOrden.Siguiente())
{
  pQStrProductos+=(const char *)(*lzSisRegProducto)["codigobarras"];
  pQStrProductos+="\n";
}
}
