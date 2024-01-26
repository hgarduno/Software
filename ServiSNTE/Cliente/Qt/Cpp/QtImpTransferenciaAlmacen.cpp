#include <QtImpTransferenciaAlmacen.h>
#include <QtImprimeTransferencia.h>
#include <QtImprimeTransferencia2.h>
#include <QtImpCapturaCantidad.h>
#include <QtImpSeleccionaProducto.h>
#include <zSiscomDesarrollo4.h>
#include <QCtrlTiendasEntrega.h>
#include <QCtrlVendedores.h>
#include <QCtrlCamiones.h>
#include <QCtrlCodigoBarras.h>
#include <QCtrlProveedoresSS.h>
#include <zImpresionTransferencia.h>
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
#include <zTransferencia.h>
#include <zProducto.h>
#include <zProductos.h>
#include <zProductoTransferencia.h>

#include <qpushbutton.h>
#include <qlineedit.h>
#include <qdatetime.h>
#include <qcheckbox.h>
#include <qstring.h>
#include <qlcdnumber.h>
#include <qtable.h>
#include <qtextedit.h>
#include <qmessagebox.h>
#include <qradiobutton.h>
#include <qapplication.h>
#include <qclipboard.h>

QtImpTransferenciaAlmacen::QtImpTransferenciaAlmacen(QWidget *pQWParent,
				     const char *pchrPtrName):
				     TransferenciaAlmacen(pQWParent,pchrPtrName),
				     zSiscomTiendasEntrega(0),
				     zSiscomAlmacenista(0),
				     zSiscomChofer(0),
				     zSiscomCamion(0),
				     chrPtrTransfiereAPiso("0"),
				     intEsStock(0),
				     intPorClaveProveedor(1)
{
    Conexion((zSiscomConexion *)gzSiscomConexion);
    PorClaveProveedor();
    IniciaControles();
    IniciaVariables();
    ConectaSlots();
}

void QtImpTransferenciaAlmacen::Conexion(zSiscomConexion *pzSisConexion)
{
	zSisConexion=pzSisConexion;
}

void QtImpTransferenciaAlmacen::ConectaSlots()
{
    connect(QCtrTiendasEntrega,
        SIGNAL(SignalTienda(zSiscomRegistro *)),
        SLOT(SlotTienda(zSiscomRegistro *)));
    connect(QCtrAlmacenistas,
        SIGNAL(SignalVendedor(zSiscomRegistro *)),
        SLOT(SlotAlmacenista(zSiscomRegistro *)));
    connect(QCtrChoferes,
        SIGNAL(SignalVendedor(zSiscomRegistro *)),
        SLOT(SlotChofer(zSiscomRegistro *)));
    connect(QCtrCamiones,
        SIGNAL(SignalCamion(zSiscomRegistro *)),
        SLOT(SlotCamion(zSiscomRegistro *)));
    
    connect(QPBTransferir,
        SIGNAL(clicked()),
        SLOT(SlotRegistraTransferencia()));
    connect(QPBImprimir,
        SIGNAL(clicked()),
        SLOT(SlotImprimeTransferencia()));
    connect(QTProductos,
        SIGNAL(clicked(int, int, int, const QPoint &)),
        SLOT(SlotCapturaCantidad(int, int, int, const QPoint &)));
    connect(QCtrProveedores,
	    SIGNAL(SignalProveedor(zSiscomRegistro *)),
	    SLOT(SlotSeleccionaProveedor(zSiscomRegistro *)));
    connect(QPBTransfiereAPiso,
    	    SIGNAL(clicked()),
	    SLOT(SlotTransfiereAPiso()));
     connect(QRBEsStock,
     	     SIGNAL(clicked()),
	     SLOT(SlotEsStock()));
connect(QPBCopiar,
	SIGNAL(clicked()),
	SLOT(SlotCopiar()));
connect(QLECodigoBarras,
	SIGNAL(returnPressed()),
	SLOT(SlotAgregarProducto()));
connect(QPBEliminar,
	SIGNAL(clicked()),
	SLOT(SlotEliminar()));
connect(QLECodigoBarras,
	SIGNAL(textChanged(const QString &)),
	SLOT(SlotCambiandoCodigoBarras(const QString &)));
}
void QtImpTransferenciaAlmacen::SlotCambiandoCodigoBarras(const QString &pQStrCodigoBarras)
{

}
void QtImpTransferenciaAlmacen::SlotEliminar()
{
   EliminaProductos();    
}
void QtImpTransferenciaAlmacen::SlotAgregarProducto()
{
   zProdsTransferencia<<zProdTransferencia;
   QPBTransferir->setEnabled(zProdsTransferencia.NNodos());
   QPBEliminar->setEnabled(true);
   MuestraTransferencia();
}
void QtImpTransferenciaAlmacen::SlotCopiar()
{
QString lQStrLstCodigos;
  	GeneraListaCodigoBarras(lQStrLstCodigos); 
	QApplication::clipboard()->setText(lQStrLstCodigos);
}
void QtImpTransferenciaAlmacen::SlotEsStock()
{
 if(QRBEsStock->isChecked())
 intEsStock=1;
 else
 intEsStock=0;
}
void QtImpTransferenciaAlmacen::SlotTransfiereAPiso()
{
  QCtrTiendasEntrega->setEnabled(false);
  QCtrAlmacenistas->setEnabled(true);
  zSiscomQt3::Foco(QCtrAlmacenistas);
  chrPtrTransfiereAPiso="1";

}
void QtImpTransferenciaAlmacen::SlotSeleccionaProveedor(zSiscomRegistro *pzSisRegProveedor)
{
zSiscomRegistro *lzSisRegProducto;
QtImpSeleccionaProducto lQtImpSelProducto(zSisConexion,pzSisRegProveedor);
if((lzSisRegProducto=lQtImpSelProducto.Producto()))
{
	zProdTransferencia=new zProductoTransferencia(lzSisRegProducto);
	zProdTransferencia->Cantidad("1");
	zProdTransferencia->Stock(intEsStock ? "1" : "0");
	SlotAgregarProducto();
}
}
void QtImpTransferenciaAlmacen::SlotTienda(zSiscomRegistro *pzSiscomTiendasEntrega)
{
    zSiscomTiendasEntrega=pzSiscomTiendasEntrega;
    QCtrAlmacenistas->setEnabled(true);
    zSiscomQt3::Foco(QCtrAlmacenistas);
    QPBTransfiereAPiso->setEnabled(false);
}

void QtImpTransferenciaAlmacen::SlotAlmacenista(zSiscomRegistro *pzSiscomAlmacenista)
{
    zSiscomAlmacenista=pzSiscomAlmacenista;
   if(!SeTransfiereAPiso())
   {
    QCtrChoferes->setEnabled(true);
    zSiscomQt3::Foco(QCtrChoferes);
   }
   else
   {
	QLECodigoBarras->setEnabled(true);
	zSiscomQt3::Foco(QLECodigoBarras);
   }
}

void QtImpTransferenciaAlmacen::SlotChofer(zSiscomRegistro *pzSiscomChofer)
{
    zSiscomChofer=pzSiscomChofer;
    QCtrCamiones->setEnabled(true);
    zSiscomQt3::Foco(QCtrCamiones);
}

void QtImpTransferenciaAlmacen::SlotCamion(zSiscomRegistro *pzSiscomCamion)
{
    zSiscomCamion=pzSiscomCamion;
    QLECodigoBarras->setEnabled(true);
    zSiscomQt3::Foco(QLECodigoBarras);
}
void QtImpTransferenciaAlmacen::SlotMuestraProductos(zSiscomRegistros *pzSiscomProductos)
{
    const char *lchrPtrCampos[]={"nombreproducto","modelo","codigobarras","cantidad",0};
    MarcaComoStock();
    zSiscomQt3::LlenaTabla(lchrPtrCampos,pzSiscomProductos,QTProductos);    
    if(QTProductos->numRows()>0) 
    QPBTransferir->setEnabled(true);
}
void QtImpTransferenciaAlmacen::SlotRegistraTransferencia()
{
    RegistrandoTransferencia();
    //ReInicia();
}
void QtImpTransferenciaAlmacen::SlotImprimeTransferencia()
{    
  ImporteTransferencia();
  ImprimeTransferencia();
}
void QtImpTransferenciaAlmacen::SlotCapturaCantidad(int pintFila,
                         int pintColumna,
                         int,
                         const QPoint &)
{
    QTProductos->selectRow(pintFila);
    if(pintColumna==3)
    {
        QtImpCapturaCantidad IQICCantidad;
        QString lQStrCantidad;
        if(IQICCantidad.Aceptar()==1)
        {
            IQICCantidad.Cantidad(&lQStrCantidad);
	     /* Tepotzotlan Mexico 18 de Marzo 2016
	      * Se integra el manejo de las cantidades
	      */
	    ActualizandoCantidad(pintFila,strdup((const char *)lQStrCantidad));
        }
    }
    if(pintColumna==4)
    {
	QtImpCapturaCantidad lQtCapturaCantidad;
	QString lQStrObservaciones;
	lQtCapturaCantidad.Cantidad(&lQStrObservaciones);
	ActualizandoObservaciones(pintFila,strdup((const char *)lQStrObservaciones));
    }
}
void QtImpTransferenciaAlmacen::SlotAStock()
{
    RegistrandoTransferencia();
    //ReIniciaVenta();
}
void QtImpTransferenciaAlmacen::IniciaControles()
{
 QCtrTiendasEntrega->Servidor(zSisConexion);
 QCtrTiendasEntrega->IniciaControl();
 QCtrAlmacenistas->Servidor(zSisConexion);
 QCtrAlmacenistas->IniciaControl("Almacenistas");
 QCtrChoferes->Servidor(zSisConexion);
 QCtrChoferes->IniciaControl("Choferes");
 QCtrCamiones->Servidor(zSisConexion);
 QCtrCamiones->IniciaControl();
 zSiscomQt3::Foco(QCtrTiendasEntrega);
}
void QtImpTransferenciaAlmacen::IniciaVariables()
{
QCtrProveedores->Servidor(zSisConexion);
 if(intPorClaveProveedor)
 QCtrProveedores->IniciaControlPorClave();
 else
 QCtrProveedores->IniciaControl();
}
void QtImpTransferenciaAlmacen::RegistrandoTransferencia()
{
    pzTransferencia = new zTransferencia(zSiscomTiendasEntrega,
                                   zSiscomAlmacenista,
                                   zSiscomChofer,
                                   zSiscomCamion);
    pzTransferencia->IdEstado((const unsigned char *) "1");
    pzTransferencia->ObservacionGeneral((const unsigned char *)strdup(QTEObservacionGeneral->text()));
    pzTransferencia->Productos(&zProdsTransferencia);
    pzTransferencia->IdTipoTransferencia(chrPtrTransfiereAPiso);
    zOperacionesServiSNTE lzOpeServiSNTETransferencia(zSisConexion,"RegistraTransferencia");
    zSisIdTransferencia = lzOpeServiSNTETransferencia.TransfiereATienda(pzTransferencia);
    if(!SeTransfiereAPiso())
    pzTransferencia->TiendaOrigen(zSisIdTransferencia->AsociadoDelCampo("Tienda")); 
    pzTransferencia->Dia((*zSisIdTransferencia)["Dia"]);
    pzTransferencia->Mes((*zSisIdTransferencia)["Mes"]);
    pzTransferencia->Anio((*zSisIdTransferencia)["Anio"]);
    //Ajuste de estado para que no afecte localmente a las transferencias recibidas.
    if(!SeTransfiereAPiso())
    {
    /*
    zOperacionesServiSNTE lzOpeServiSNTEActTrans(zSisConexion,"ActualizaEstadoTransferencia");
    lzOpeServiSNTEActTrans.ActualizaEstadoTransferencia(
                (const char *)(*zSisIdTransferencia)["IdTransferencia"],
                "2",
		(const char *)(*zSiscomTiendasEntrega)["idtienda"]);
	 */
    }
    QPBImprimir->setEnabled(true);
    zSiscomQt3::Foco(QPBImprimir);
    //QString informacion = "El producto NO se encuentra en la base: ";
    //informacion = informacion + QLECodigoBarras->text();
    QMessageBox::information(this,"Aviso del sistema",
                    "Transferencia exitosa!                    ");
}

int QtImpTransferenciaAlmacen::SeTransfiereAPiso()
{
   return !strcmp(chrPtrTransfiereAPiso,"1") ? 1 :0 ;
}
void QtImpTransferenciaAlmacen::MarcaComoStock()
{

}
void QtImpTransferenciaAlmacen::ActualizandoCantidad(int pintNProducto,const char *pchrPtrCantidad)
{
     zProdsTransferencia.Cantidad(pintNProducto,pchrPtrCantidad);
     MuestraTransferencia();
}
void QtImpTransferenciaAlmacen::ActualizandoObservaciones(int pintNProducto,const char *pchrPtrObservaciones)
{
    zProdsTransferencia.Observaciones(pintNProducto,pchrPtrObservaciones);
    MuestraTransferencia();

}
void QtImpTransferenciaAlmacen::keyPressEvent(QKeyEvent *pQKETecla)
{
LogSiscom("%d",pQKETecla->key());

}
void QtImpTransferenciaAlmacen::GeneraListaCodigoBarras(QString &pQStrLstCodigos)
{
int lintContador;
for(lintContador=0;
    lintContador<QTProductos->numRows();
    lintContador++)
{
   if(QTProductos->isRowSelected(lintContador))
   {
           pQStrLstCodigos+=zProdsTransferencia.CodigoBarras(lintContador);
	   pQStrLstCodigos+="\n";
   }
}
}
void QtImpTransferenciaAlmacen::MuestraTransferencia()
{
const char *lchrPtrCampos[]={"nombreproducto","modelo","codigobarras","Cantidad","Observacion","Stock",0};
zSiscomQt3::LlenaTabla(lchrPtrCampos,&zProdsTransferencia,QTProductos);
}
void QtImpTransferenciaAlmacen::ReInicia()
{
	zProdsTransferencia.Libera();
	zSiscomTiendasEntrega=0;
	zSiscomAlmacenista=0;
	zSiscomChofer=0;
	zSiscomCamion=0;
	chrPtrTransfiereAPiso="0";
	intEsStock=0;
	QTProductos->setNumRows(0);
	QPBTransferir->setEnabled(false);
	QPBTransfiereAPiso->setEnabled(true);
	QCtrChoferes->setEnabled(false);
	QCtrCamiones->setEnabled(false);
	QCtrAlmacenistas->setEnabled(false);

	zSiscomQt3::Foco(QCtrTiendasEntrega);




}

void QtImpTransferenciaAlmacen::EliminaProductos()
{
int lintContador;
  for(lintContador=0;
      lintContador<QTProductos->numRows();
      lintContador++)
  {
	if(QTProductos->isRowSelected(lintContador))
	{
	   zProdsTransferencia.Elimina(lintContador);
   	   MuestraTransferencia();
	   QPBEliminar->setEnabled(zProdsTransferencia.NNodos());
	}
  }
}
void QtImpTransferenciaAlmacen::ImporteTransferencia()
{
zOperacionesServiSNTE lzSisOpeServiSNTE(zSisConexion,"CostoPrecioTransferencia");
pzTransferencia->AsignaOrden();
lzSisOpeServiSNTE.CostoPrecioTransferencia(pzTransferencia->Orden());
}
void QtImpTransferenciaAlmacen::ImprimeTransferencia()
{
QtImprimeTransferencia2 lQtImpTransferencia2(zSisConexion);
zImpresionTransferencia lzImprTransferencia;
lzImprTransferencia.Transferencia(pzTransferencia);
lQtImpTransferencia2.ImpresionTransferencia2(&lzImprTransferencia);
lQtImpTransferencia2.MargenX(0);
lQtImpTransferencia2.MargenY(0);
lQtImpTransferencia2.Imprime();

}

void QtImpTransferenciaAlmacen::PorClaveProveedor()
{
const char *lchrPtrPorClaveProveedor=getenv("ProveedorPorClave");
if(lchrPtrPorClaveProveedor)
intPorClaveProveedor=1;
else
intPorClaveProveedor=0;
}
