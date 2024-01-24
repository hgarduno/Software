#include <IMP_Cotizaciones.h>
#include <IMP_QControlFecha.h>


#include <zSiscomElectronica.h>
#include <zSiscomDesarrollo4.h>
#include <zSiscomRegistro.h>
#include <zSiscomQt3.h>

#include <zOrdenVenta.h>
#include <zCotizacion.h>
#include <zOrdenes.h>
#include <zProductoCotizar.h>

#include <qpushbutton.h>
#include <qtextedit.h>
#include <qlineedit.h>
#include <qlcdnumber.h>
#include <qmessagebox.h>
#include <qtable.h>
#include <qbuttongroup.h> 
#include <qradiobutton.h>

QCotizaciones::QCotizaciones(zSiscomConexion *pzSisConexion,
			    QWidget *pQWParent,       
			     const char *pchrPtrName,
				    bool pbModal,
				    WFlags pWFlags):	      
				QtCotizaciones(pQWParent,pchrPtrName,pbModal,pWFlags),
				zSisConexion((zSiscomConexion *)pzSisConexion),
				intConsultaPorRangoFechas(0),
				intConsultaPorIdVenta(0),
				intAceptar(0),
				intTipoOrden(0)
{
IniciaVariables();
ConectaSlots();
}

QCotizaciones::~QCotizaciones()
{

}

void QCotizaciones::ConectaSlots()
{
connect(QCtrFechaInicio,SIGNAL(Signal_EnterA_o()),SLOT(SlotFocoAFechaFin()));
connect(QCtrFechaFin,SIGNAL(Signal_EnterA_o()),SLOT(SlotFocoAConsultar()));
connect(QLEIdOrden,SIGNAL(returnPressed()),SLOT(SlotFocoAConsultar()));
connect(QPBConsultar,SIGNAL(clicked()),SLOT(SlotConsulta()));
connect(QPBAceptar,SIGNAL(clicked()),SLOT(SlotAceptar()));
connect(QPBCancelar,SIGNAL(clicked()),SLOT(SlotCancelar()));
connect(QLEIdOrden,SIGNAL(textChanged(const QString &)),SLOT(SlotCapturandoIdVenta(const QString &)));
/*
connect(QTOrdenes,
	SIGNAL(doubleClicked(int,int,int,const QPoint &)),
	SLOT(SlotOrden(int,int,int,const QPoint &)));
*/
connect(QTOrdenes,SIGNAL(currentChanged(int,int)),SLOT(SlotOrden(int,int)));
connect(QBGTipoOrden,SIGNAL(pressed(int)),SLOT(SlotSeleccionandoTipoOrden(int)));
}
void QCotizaciones::SlotSeleccionandoTipoOrden(int pintTipoOrden)
{
  QCtrFechaInicio->setEnabled(true);
  QCtrFechaFin->setEnabled(true);
  zSiscomQt3::Foco(QCtrFechaInicio);
  intTipoOrden=pintTipoOrden;
  QLEIdOrden->setEnabled(true);
}
void QCotizaciones::SlotOrden(int pintNOrden,
			      int)
{
if(pintNOrden!=-1)
{
 MuestraProductosOrden(pintNOrden);
 ActivaAceptar();
 zSiscomQt3::Foco(QPBAceptar);
}
}
void QCotizaciones::SlotOrden(int pintNOrden,
			      int,
			      int,
			      const QPoint &)
{
 if(pintNOrden!=-1)
 MuestraProductosOrden(pintNOrden);

}
				
void QCotizaciones::SlotCancelar()
{
   intAceptar=0;
   done(1);
}
void QCotizaciones::SlotCapturandoIdVenta(const QString &pQStrIdVenta)
{
   HabilitandoConsulta();
}
void QCotizaciones::SlotAceptar()
{
   intAceptar=1;
   done(1);
   emit SignalVendeOrden(zOrdVenta);
}
void QCotizaciones::SlotConsulta()
{
if(EsConsultaPorIdVenta())
{
Consultando();
QtCotizaciones::MascaraTelefonoIdOrden(false);
}
else
if(EsConsultaPorRangoFechas())
ConsultandoPorRangoFechas();


}
void QCotizaciones::SlotFocoAConsultar()
{
  if(!zSiscomQt3::TextoValido(QLEIdOrden))
  {
  intConsultaPorRangoFechas=1;
  intConsultaPorIdVenta=0;
  }
  else
  {
	intConsultaPorRangoFechas=0;
	intConsultaPorIdVenta=1;
  }
  QPBConsultar->setEnabled(true);
  zSiscomQt3::Foco(QPBConsultar);
}
void QCotizaciones::SlotFocoAFechaFin()
{
	zSiscomQt3::Foco(QCtrFechaFin);
}
void QCotizaciones::IniciaVariables()
{
QCtrFechaInicio->ColocaFechaHoy();
QCtrFechaFin->ColocaFechaHoy();
//zSiscomQt3::Foco(QCtrFechaInicio);
zSiscomQt3::Foco(QBGTipoOrden);
zSiscomQt3::Foco(this);
}
void QCotizaciones::Consultando()
{
int lintEdoConsulta;
  if((lintEdoConsulta=Consulta())==2)
  MuestraConsultaPorRangoFechas();
  else
  if(lintEdoConsulta==1)
  {
  Muestra();
  ActivaAceptar();
  zSiscomQt3::Foco(QPBAceptar);
  }
  else
  QMessageBox::information(this,"Aviso del Sistema","NO Se encontro la cotizacion");
}
void QCotizaciones::ConsultandoPorRangoFechas()
{
  if(ConsultaPorRangoFechas())
  MuestraConsultaPorRangoFechas();
  else
  QMessageBox::information(this,"Aviso del Sistema","NO Se encontro la cotizacion");

}
int QCotizaciones::Consulta()
{
int lintNNodosReg;
const char *lchrPtrIdOrden=strdup((const char *)QLEIdOrden->text());

LogSiscom("%s",lchrPtrIdOrden);
zSiscomElectronica lzSisElectronica(zSisConexion,"ConsultaOrden");
if(!(zOrdVenta=lzSisElectronica.ConsultaOrden(lchrPtrIdOrden,
					 ObtenIdTipoOrden(),
					 &zOrdsVentas)))
{
    if((lintNNodosReg=zOrdsVentas->NNodos()>1))
    return 2;
    else
    if(lintNNodosReg==0)
    return 0;
    else
    return 1;
}
else
return 1;
}
const char *QCotizaciones::ObtenIdTipoOrden()
{
char lchrArrDato[128];
sprintf(lchrArrDato,"%d",intTipoOrden);
return strdup(lchrArrDato);
}
int QCotizaciones::ConsultaPorRangoFechas()
{
zSiscomElectronica lzSisElectronica(zSisConexion,"OrdenesVendidas2");
zOrdsVentas=lzSisElectronica.Ordenes2(
			(const char *)QCtrFechaInicio->ObtenFecha(),
			(const char *)QCtrFechaFin->ObtenFecha(),
			ObtenIdTipoOrden());
return zOrdsVentas ? 1 : 0;
}
void QCotizaciones::Muestra()
{
 QLCDNImporte->display(zOrdVenta->ImporteOrden());
 MuestraProductos();
}
void QCotizaciones::MuestraConsultaPorRangoFechas()
{
  MuestraOrdenesVendidas();  
  zSiscomQt3::AjustaFilasTabla(QTOrdenes);
}
void QCotizaciones::MuestraProductos()
{
const char *lchrPtrCampos[]={"Cantidad","Clave","Precio","Importe",0};
zSiscomQt3::LlenaTabla(lchrPtrCampos,zOrdVenta->Productos(),QTProductos);
}
void QCotizaciones::MuestraCotizacion(int pintFila,zOrdenVenta *pzOrdenVenta)
{
  QTOrdenes->setText(pintFila,2,pzOrdenVenta->Cotizacion()->Descripcion());
}
void QCotizaciones::MuestraVenta(int pintFila,zOrdenVenta *pzOrden)
{

}
void QCotizaciones::MuestraCancelacion(int pintFila,zOrdenVenta *pzOrden)
{

}

void QCotizaciones::MuestraNoDefinida(int pintFila,zOrdenVenta *pzOrden)
{
   LogSiscom("El Tipo de orden No definido %d",pintFila);
}
void QCotizaciones::AsignandoMuestraOrdenes()
{
int lintContador;
for(lintContador=0;lintContador<10;lintContador++)
MuestraPorTipoOrden[lintContador]=&QCotizaciones::MuestraNoDefinida;
    
MuestraPorTipoOrden[0]=&QCotizaciones::MuestraVenta;
MuestraPorTipoOrden[1]=&QCotizaciones::MuestraCotizacion;
MuestraPorTipoOrden[5]=&QCotizaciones::MuestraCancelacion;

}
void QCotizaciones::MuestraOrdenesVendidas()
{
int lintContador;
zOrdenVenta *lzOrdenVenta;
QTOrdenes->setNumRows(zOrdsVentas->NNodos());
AsignandoMuestraOrdenes();
for(lzOrdenVenta=(zOrdenVenta *)zOrdsVentas->Primer(),
    lintContador=0;
    lzOrdenVenta;
    lzOrdenVenta=(zOrdenVenta *)zOrdsVentas->Siguiente(),
    lintContador++)
{
  QTOrdenes->setText(lintContador,0,lzOrdenVenta->IdVenta());
  QTOrdenes->setText(lintContador,1,lzOrdenVenta->ImporteOrden());
  LogSiscom("El IdTipo Orden %d",lzOrdenVenta->IdTipoOrdenInt());
  (this->*MuestraPorTipoOrden[lzOrdenVenta->IdTipoOrdenInt()])(lintContador,lzOrdenVenta);
}
zSiscomQt3::AjustaColumnasTabla(QTOrdenes);
}
void QCotizaciones::MuestraProductosOrden(int pintNOrden)
{
zProductoCotizar *lzProdOrden;
int lintContador;
zOrdVenta=zOrdsVentas->Orden(pintNOrden);
QLCDNImporte->display(zOrdVenta->ImporteOrden());
zOrdVenta->NumProductos(zOrdVenta->Productos()->NNodos()); 
QTProductos->setNumRows(zOrdVenta->Productos()->NNodos());
for(lintContador=0,
    lzProdOrden=(zProductoCotizar *)zOrdVenta->Productos()->Primer();
    lzProdOrden;
    lintContador++,
    lzProdOrden=(zProductoCotizar *)zOrdVenta->Productos()->Siguiente())
{
 QTProductos->setText(lintContador,0,lzProdOrden->Cantidad());
 QTProductos->setText(lintContador,1,lzProdOrden->Clave());
 QTProductos->setText(lintContador,2,lzProdOrden->Precio());
 QTProductos->setText(lintContador,3,lzProdOrden->Importe());
 lzProdOrden->PrecioEspecial("1");
}
zSiscomQt3::AjustaColumnasTabla(QTProductos);
}
void QCotizaciones::MuestraDescripcion()
{
QTEDescripcion->setText(zOrdVenta->Cotizacion()->Descripcion());
}
void QCotizaciones::Ejecutando()
{
  exec();
}
int QCotizaciones::EsConsultaPorIdVenta()
{
   return intConsultaPorIdVenta;
}
int QCotizaciones::EsConsultaPorRangoFechas()
{
  return intConsultaPorRangoFechas; 	
}
void QCotizaciones::HabilitandoConsulta()
{
  QPBConsultar->setEnabled(zSiscomQt3::TextoValido(QLEIdOrden));
}

void QCotizaciones::HabilitaBotones(bool pbModal)
{
  QRBVentas->setEnabled(pbModal);
  QRBPedidos->setEnabled(pbModal);
}

void QCotizaciones::TipoOrden(int pintTipoOrden)
{
   intTipoOrden=pintTipoOrden;
}
int QCotizaciones::TipoOrden()
{
	return intTipoOrden;
}

void QCotizaciones::ActivaAceptar()
{
   QPBAceptar->setEnabled(zOrdVenta->Productos()->NNodos()); 
}

void QCotizaciones::PonConsultaPorRangoFechas(int pintConsultaPorRangoFechas)
{
    intConsultaPorRangoFechas=pintConsultaPorRangoFechas;
}
void QCotizaciones::reject()
{
 LogSiscom("Cerrando .... ");
}
zOrdenVenta *QCotizaciones::Orden()
{
   return zOrdVenta;
}
/*
void QCotizaciones::keyPressEvent(QKeyEvent *pQKETeclas)
{
  LogSiscom("");

}*/
