#include <IMP_CotizaImportacion.h>
#include <IMP_RegistroCotizacionImportacion.h>
#include <IMP_ActualizaProductoCotizacionImportacion.h>
#include <IMP_CotizacionImportacionCierre.h>
#include <QCtrlProductosSE.h>
#include <QCtrlProveedoresSE.h>


#include <zSiscomElectronica.h>
#include <zSiscomDesarrollo4.h>
#include <zSiscomRegistro.h>
#include <zSiscomQt3.h>


#include <zCotizacionImportacion.h>
#include <zProductoCotImp.h>
#include <zProductosCotImp.h>
#include <qpushbutton.h>
#include <qlineedit.h>
#include <qmessagebox.h>
#include <qtable.h>
#include <qtextedit.h>

QCotizaImportacion *InstanciaCotizaImportacion(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QCotizaImportacion((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QCotizaImportacion::QCotizaImportacion(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				CotizaImportacion(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos),
				zSisConexion((zSiscomConexion *)gzSiscomConexion)
{
IniciaVariables();
ConectaSlots();
}

QCotizaImportacion::~QCotizaImportacion()
{

}

void QCotizaImportacion::ConectaSlots()
{
  connect(QPBRegistra,SIGNAL(clicked()),SLOT(SlotRegistra()));
  connect(QPBConsulta,SIGNAL(clicked()),SLOT(SlotConsulta()));
  connect(QLECostoDolar,SIGNAL(returnPressed()),SLOT(SlotFocoAProveedor()));
  connect(QCtrProveedores,SIGNAL(SignalSelecciono(zSiscomRegistro *)),SLOT(SlotProveedor(zSiscomRegistro *)));
  connect(QCtrProductos,SIGNAL(SignalSelecciono(zSiscomRegistro *)),SLOT(SlotProducto(zSiscomRegistro *)));
  connect(QLECantidad,SIGNAL(textChanged(const QString &)),SLOT(SlotCapturandoCantidad(const QString &)));
  connect(QLECantidad,SIGNAL(returnPressed()),SLOT(SlotFocoAPrecio()));
  connect(QLEPrecio,SIGNAL(textChanged(const QString &)),SLOT(SlotCapturandoPrecio(const QString &)));
  connect(QLEPrecio,SIGNAL(returnPressed()),SLOT(SlotFocoAAnexar()));
  connect(QPBAnexar,SIGNAL(clicked()),SLOT(SlotAnexar()));
  connect(QTProductos,SIGNAL(doubleClicked(int,int,int,const QPoint &)),SLOT(SlotSeleccionoProducto(int,int,int,const QPoint &)));
  connect(QTProductos,SIGNAL(clicked(int,int,int,const QPoint &)),SLOT(SlotSeleccionandoProducto(int,int,int,const QPoint &)));
  connect(QTProductos,SIGNAL(selectionChanged()),SLOT(SlotCambioLaSeleccion()));
  connect(QPBEliminar,SIGNAL(clicked()),SLOT(SlotEliminar()));

}
void QCotizaImportacion::SlotEliminar()
{
  EliminaProductos();
  RegistraProducto();
  MuestraCotizacion();
}
void QCotizaImportacion::SlotCambioLaSeleccion()
{
     SeActivaEliminaProducto();
}
void QCotizaImportacion::SlotSeleccionandoProducto(int pintNProducto,
						   int,
						   int,
						   const QPoint &)
{
   QTProductos->selectRow(pintNProducto);
   SeActivaEliminaProducto();

}
void QCotizaImportacion::SlotSeleccionoProducto(int pintNProducto,
					        int,
						int,
						const QPoint &)
{
if(pintNProducto!=-1)
{
	QTProductos->selectRow(pintNProducto);
	ActualizandoProducto(pintNProducto);
}
}
void QCotizaImportacion::SlotAnexar()
{
  AnexaProducto();
  RegistraProducto();
  MuestraCotizacion();
  SeAnexoProducto();
  zSiscomQt3::Foco(QCtrProductos);

  
}
void QCotizaImportacion::SlotFocoAAnexar()
{
    zSiscomQt3::Foco(QPBAnexar);
}
void QCotizaImportacion::SlotCapturandoPrecio(const QString &)
{
    QPBAnexar->setEnabled(zSiscomQt3::TextoValido(QLECantidad) &&
                          zSiscomQt3::TextoValido(QLEPrecio));
}
void QCotizaImportacion::SlotFocoAPrecio()
{
     zSiscomQt3::Foco(QLEPrecio);
}
void QCotizaImportacion::SlotCapturandoCantidad(const QString &)
{
    QLEPrecio->setEnabled(zSiscomQt3::TextoValido(QLECantidad));
}
void QCotizaImportacion::SlotProducto(zSiscomRegistro *pzSisRegProducto)
{
   zSisRegProducto=pzSisRegProducto;
   ConsultandoPeso();

}
void QCotizaImportacion::SlotConsulta()
{
 Consultando();
}
void QCotizaImportacion::SlotProveedor(zSiscomRegistro *pzSisRegProveedor)
{
    if(pzSisRegProveedor)
    {
     QPBRegistra->setEnabled(true);
     zSiscomQt3::Foco(QPBRegistra);
      zSisRegProveedor=pzSisRegProveedor;
      zCotImportacion->Proveedor(zSisRegProveedor);
    }
}
void QCotizaImportacion::SlotFocoAProveedor()
{
   QCtrProveedores->setEnabled(true);
   zSiscomQt3::Foco(QCtrProveedores);
   zCotImportacion->CostoDolar(zSiscomQt3::Texto(QLECostoDolar));
}
void QCotizaImportacion::SlotRegistra()
{
QRegistroCotizacionImportacion lQCRegCotImp(zCotImportacion,chrPtrArgumentos);
if(lQCRegCotImp.Cotizando())
Cotizando();
}
void QCotizaImportacion::IniciaVariables()
{
  QCtrProductos->Servidor(zSisConexion);
  QCtrProductos->IniciaControl();
  QCtrProveedores->Servidor(zSisConexion);
  QCtrProveedores->IniciaControl();
  zSiscomQt3::Foco(QLECostoDolar);
  zCotImportacion=new zCotizacionImportacion;
}

void QCotizaImportacion::Cotizando()
{
    QCtrProductos->setEnabled(true);
    zSiscomQt3::Foco(QCtrProductos);
}
void QCotizaImportacion::Consultando()
{
   Consulta();
}
void QCotizaImportacion::Consulta()
{
 QRegistroCotizacionImportacion lQCRegCotImp(0,chrPtrArgumentos);
 if((zCotImportacion=lQCRegCotImp.Cotizacion()))
 {
  ContinuaCotizacion();
  /*
  MuestraProductos();
  */
  MuestraCotizacion();

 }
}
void QCotizaImportacion::MuestraProductos()
{
int lintFila;
zProductoCotImp *lzProdCotImp;
 QTProductos->setNumRows(zCotImportacion->Productos()->NNodos());
for(lzProdCotImp=(zProductoCotImp *)zCotImportacion->Productos()->Primer(),
    lintFila=0;
    lzProdCotImp;
    lzProdCotImp=(zProductoCotImp *)zCotImportacion->Productos()->Siguiente(),
    lintFila++)
{
QTProductos->setText(lintFila,0,lzProdCotImp->Clave());
QTProductos->setText(lintFila,1,lzProdCotImp->Cantidad());
QTProductos->setText(lintFila,2,lzProdCotImp->Peso());
QTProductos->setText(lintFila,3,lzProdCotImp->PesoTotal());
QTProductos->setText(lintFila,4,lzProdCotImp->Precio());
QTProductos->setText(lintFila,5,lzProdCotImp->Importe());
}
zSiscomQt3::AjustaColumnasTabla(QTProductos);
}
void QCotizaImportacion::ContinuaCotizacion()
{
   QLECostoDolar->setReadOnly(true);
   QLECostoDolar->setText(zCotImportacion->CostoDolar());
   QPBConsulta->setEnabled(false);
   QCtrProductos->setEnabled(true);
   zSiscomQt3::Foco(QCtrProductos);

}
void QCotizaImportacion::ConsultandoPeso()
{
char lchrArrPeso[12];
 if(ConsultaPeso(lchrArrPeso))
 {
  MuestraPeso(lchrArrPeso);
  QLECantidad->setEnabled(true);  
  zSiscomQt3::Foco(QLECantidad);
 }
}
void QCotizaImportacion::MuestraPeso(char *pchrPtrPeso)
{
 QLEPeso->setText(pchrPtrPeso);
}
int QCotizaImportacion::ConsultaPeso(char *pchrPtrPeso)
{
zSiscomElectronica lzSisElectro(zSisConexion,"PesoProducto");
return lzSisElectro.PesoProducto(zSisRegProducto,pchrPtrPeso);
}
void QCotizaImportacion::AnexaProducto()
{
 zProductoCotImp *lzProdCotImp=new zProductoCotImp(zSisRegProducto);  
  lzProdCotImp->Peso(zSiscomQt3::Texto(QLEPeso));
  lzProdCotImp->Cantidad(zSiscomQt3::Texto(QLECantidad));
  lzProdCotImp->Precio(zSiscomQt3::Texto(QLEPrecio));
  zCotImportacion->Agrega(lzProdCotImp);
}
void QCotizaImportacion::RegistraProducto()
{
zSiscomElectronica lzSisElectronica(zSisConexion,"RegistraProductoCotizaImportacion");
lzSisElectronica.RegistraProductoCotizaImportacion(zCotImportacion);
}
void QCotizaImportacion::ActualizandoProducto(int pintNProducto)
{
QActualizaProductoCotizacionImportacion lQActProdCotImp(zCotImportacion->Producto(pintNProducto),
							chrPtrArgumentos);
if(lQActProdCotImp.SeActualizoAlgo())
{
   RegistraProducto();
   /*
   MuestraProductos();
   */
   MuestraCotizacion();
}
}
void QCotizaImportacion::SeActivaEliminaProducto()
{
int lintContador;
int lintFilaSeleccionada=0;
for(lintContador=0;
    lintContador<QTProductos->numRows();
    lintContador++)
if(QTProductos->isRowSelected(lintContador,true))
lintFilaSeleccionada=1;

QPBEliminar->setEnabled(lintFilaSeleccionada);
}

void QCotizaImportacion::EliminaProductos()
{
int lintProductos[250], lintContador,lintNProductos=0;
 for(lintContador=0;
     lintContador<QTProductos->numRows();
     lintContador++)
if(QTProductos->isRowSelected(lintContador,true))
    lintProductos[lintNProductos++]=lintContador;
for(lintContador=0;lintContador<lintNProductos;lintContador++)
 zCotImportacion->Productos()->Elimina(lintProductos[lintContador]);
}

void QCotizaImportacion::MuestraDatosCotizacion()
{
char lchrArrTexto[1024];
TextoDatosCotizacion(lchrArrTexto);
QTEDatosCotizacion->setText(lchrArrTexto);
}
void QCotizaImportacion::TextoDatosCotizacion(char *pchrPtrTexto)
{
sprintf(pchrPtrTexto,
	"<b>%s</b><br><br><br><br><br>"
	"<b>Importe %s</b> <br> "
	"<b>Peso    %s</b>            ",
	zCotImportacion->RazonSocial(),
	zCotImportacion->ImporteTotal(),
	zCotImportacion->PesoTotal());

}
void QCotizaImportacion::MuestraCotizacion()
{
MuestraProductos();
MuestraDatosCotizacion();
}
void QCotizaImportacion::SeleccionaOtraCotizacion()
{
    delete zCotImportacion;
    QPBConsulta->setEnabled(true);
    zSiscomQt3::Foco(QPBConsulta);
}
void QCotizaImportacion::RegistraOtraCotizacion()
{
   delete zCotImportacion;
   QPBConsulta->setEnabled(false);
   QPBRegistra->setEnabled(true);
   zSiscomQt3::Foco(QPBRegistra);
}
void QCotizaImportacion::closeEvent(QCloseEvent *pQCloseEvent)
{
QCotizacionImportacionCierre lQCotImpCierre;
switch(lQCotImpCierre.ComoCierro())
{
	case QCotizacionImportacionCierre::Cierre:
		pQCloseEvent->accept();
	break;
	case QCotizacionImportacionCierre::SeleccionaOtraCotizacion:
		SeleccionaOtraCotizacion();	
	break;
	case QCotizacionImportacionCierre::RegistraOtraCotizacion:
		RegistraOtraCotizacion();	
	break;
}
}
void QCotizaImportacion::SeAnexoProducto()
{
   QPBAnexar->setEnabled(false);
   QLECantidad->setEnabled(false);
   QLEPrecio->setEnabled(false);
}
