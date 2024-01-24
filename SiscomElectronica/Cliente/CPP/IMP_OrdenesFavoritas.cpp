#include <IMP_OrdenesFavoritas.h>
#include <IMP_Cotizaciones.h>

#include <QCtrlOrdenesFavoritas.h>

#include <QtSisBotonOrden.h>

#include <zOrdenFavorita.h>
#include <zSiscomElectronica.h>
#include <zSiscomDesarrollo4.h>
#include <zSiscomRegistro.h>
#include <zSiscomQt3.h>

#include <zOrdenVenta.h> 

#include <qpushbutton.h>
#include <qtable.h>
#include <qlineedit.h>
#include <qlcdnumber.h>
#include <qtextedit.h>
#include <qmessagebox.h>


QOrdenesFavoritas *InstanciaOrdenesFavoritas(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QOrdenesFavoritas((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QOrdenesFavoritas::QOrdenesFavoritas(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				OrdenesFavoritas(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos),
				zSisConexion((zSiscomConexion *)gzSiscomConexion),
				intSeleccionandoParaEliminar(0)
{
IniciaVariables();
ConectaSlots();
QCtrOrdenesFavoritas->AgregaBotonOrden();
}

QOrdenesFavoritas::~QOrdenesFavoritas()
{

}

void QOrdenesFavoritas::ConectaSlots()
{
connect(QPBSelOrden,SIGNAL(clicked()),SLOT(SlotSelOrden()));
connect(QTEDesVenta,SIGNAL(textChanged()),SLOT(SlotCapturandoFavorita()));
connect(QPBRegistraFavoritas,SIGNAL(clicked()),SLOT(SlotRegistraFavoritas()));
connect(QCtrOrdenesFavoritas,
	SIGNAL(SignalOrden(QtSisBotonOrden *)),
	SLOT(SlotOrden(QtSisBotonOrden *)));
connect(QCtrOrdenesFavoritas,
	SIGNAL(SignalEliminaOrden(QtSisBotonOrden *)),
	SLOT(SlotMarcaParaEliminar(QtSisBotonOrden *)));
connect(QPBAsignaOrdenFavorita,
	SIGNAL(clicked()),
	SLOT(SlotAsignaOrdenFavorita()));
connect(QPBEliminaOrden,SIGNAL(clicked()),SLOT(SlotEliminaOrden()));
connect(QPBAgregarOrdenFavorita,
	SIGNAL(clicked()),
	SLOT(SlotAgregaOrdenFavorita()));
}
void QOrdenesFavoritas::SlotAgregaOrdenFavorita()
{
}
void QOrdenesFavoritas::SlotMarcaParaEliminar(QtSisBotonOrden *pQtSisBtnOrden)
{
     if(intSeleccionandoParaEliminar==1)
     {
     pQtSisBtnOrden->setDown(true);  
     zOrdsFavoritasE << pQtSisBtnOrden->OrdenFavorita();
     }
}
void QOrdenesFavoritas::SlotEliminaOrden()
{
   if(intSeleccionandoParaEliminar==0)
   PreparaParaEliminarOrdenesFavoritas();
   else
   if(intSeleccionandoParaEliminar==1)
   {
   EliminaOrdenesFavoritas();
   QCtrOrdenesFavoritas->ReConsulta();
   }
}
void QOrdenesFavoritas::SlotAsignaOrdenFavorita()
{
  AgregaOrdenFavorita();
  QtSisBtnOrden->Orden(zOrdVenta);
  QtSisBtnOrden->setDown(false);
  QTProductos->setNumRows(0);
  QCtrOrdenesFavoritas->HabilitaBotonesSiTieneOrden();   
  QPBAsignaOrdenFavorita->setEnabled(false);
  QtSisBtnOrden=0;
  QTEDesVenta->clear();
}
void QOrdenesFavoritas::SlotCapturandoFavorita()
{
    if(QtSisBtnOrden)
    QtSisBtnOrden->setText(QTEDesVenta->text());
    else
    QMessageBox::information(this,
    			     "Aviso Sistema",
			     "NO Se ha Seleccionado Boton");
}
void QOrdenesFavoritas::SlotOrden(QtSisBotonOrden *pQtSisBtnOrden)
{
  if(!YaTieneOrden(pQtSisBtnOrden))
  {
  QtSisBtnOrden=pQtSisBtnOrden;
  QtSisBtnOrden->setDown(true);
  QCtrOrdenesFavoritas->HabilitaBotones(QtSisBtnOrden,false);
  QPBAsignaOrdenFavorita->setEnabled(true);
  zSiscomQt3::Foco(QTEDesVenta);
  }
  else
    Muestra(pQtSisBtnOrden->Orden());
}
void QOrdenesFavoritas::SlotRegistraFavoritas()
{
 RegistrandoFavoritas();
}
void QOrdenesFavoritas::SlotSelOrden()
{
QCotizaciones lQOrdenes(zSisConexion,parentWidget());
connect(&lQOrdenes,
	SIGNAL(SignalVendeOrden(zOrdenVenta *)),
	SLOT(SlotSeleccionoOrden(zOrdenVenta *)));
lQOrdenes.Ejecutando();
Muestra(zOrdVenta);
QCtrOrdenesFavoritas->HabilitaBotones(true);
}
void QOrdenesFavoritas::SlotSeleccionoOrden(zOrdenVenta *pzOrdenVenta)
{
zOrdVenta=pzOrdenVenta;
}
void QOrdenesFavoritas::IniciaVariables()
{
QCtrOrdenesFavoritas->Servidor(zSisConexion);
QCtrOrdenesFavoritas->IniciaControl();
}
void QOrdenesFavoritas::Muestra(zOrdenVenta *pzOrdenVenta)
{
 QLCDNImporte->display(pzOrdenVenta->ImporteOrden());
 MuestraProductos(pzOrdenVenta);
}
void QOrdenesFavoritas::MuestraProductos(zOrdenVenta *pzOrdenVenta)
{
const char *lchrPtrCampos[]={"Cantidad","Clave","Precio","Importe",0};
zSiscomQt3::LlenaTabla(lchrPtrCampos,pzOrdenVenta->Productos(),QTProductos);
}
void QOrdenesFavoritas::RegistraFavoritas()
{
zSiscomElectronica lzSisElectronica(zSisConexion,"RegistraOrdenesFavoritas");
lzSisElectronica.RegistraOrdenesFavoritas(&zOrdsFavoritas);
}
void QOrdenesFavoritas::RegistrandoFavoritas()
{
  RegistraFavoritas();
}
int QOrdenesFavoritas::YaTieneOrden(QtSisBotonOrden *pQtSisBtnOrden)
{
  return pQtSisBtnOrden->Orden() ? 1:0; 
}
void QOrdenesFavoritas::AgregaOrdenFavorita()
{

zOrdenFavorita *lzOrdenFavorita=new zOrdenFavorita;
  lzOrdenFavorita->IdOrden((const char *)(*zOrdVenta)["IdVenta"]);
  lzOrdenFavorita->Texto(zSiscomQt3::Texto(QTEDesVenta));
  zOrdsFavoritas << lzOrdenFavorita;
}
void QOrdenesFavoritas::PreparaParaEliminarOrdenesFavoritas()
{
   QCtrOrdenesFavoritas->ModoControl(2);
   QCtrOrdenesFavoritas->HabilitaBotones(true);
   intSeleccionandoParaEliminar=1;
   QMessageBox::information(this,
   			    "Aviso Sistema",
			    "Selecciona las ordenes \n"
			    "a ELIMINAR");
}
void QOrdenesFavoritas::EliminaOrdenesFavoritas()
{
zSiscomElectronica lzSisElectronica(zSisConexion,"EliminaOrdenesFavoritas");
lzSisElectronica.EliminaOrdenesFavoritas(&zOrdsFavoritasE);
}
