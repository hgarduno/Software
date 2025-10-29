#include <QtOrdenesRegistradas.h>

#include <IMP_QControlFecha.h>
#include <IMP_CapturaDescripcionCotizacion.h>
#include <IMP_ConExpendiosVenta.h>

#include <zSiscomConexion.h>
#include <zConexionExpendio.h>
#include <zSiscomElectronica.h>
#include <zTextoWhatsApp.h>
#include <zSiscomEnvioACadena.h>

#include <zOrdenVenta.h>
#include <zCotizacion.h>
#include <zOrdenes.h>
#include <zClienteSiscom.h>
#include <zProductoCotizar.h>
#include <zPedido.h>
#include <zPuntoEntrega.h>
#include <zSiscomDesarrollo4.h>
#include <zSiscomQt3.h>
#include <zExpendio.h>
#include <zFormaPago.h>
#include <zFormaPagoTransferencia.h>
#include <zApartado.h>


#include <qbuttongroup.h>
#include <qtable.h>
#include <qlineedit.h>
#include <qpushbutton.h>
#include <qtabwidget.h>

#include <qapplication.h>
#include <qclipboard.h>
QtOrdenesRegistradas::QtOrdenesRegistradas(zSiscomConexion *pzSisConexion,
					   char **pchrPtrArgumentos,
					  QWidget *pQWParent,
					   const char *pchrPtrName,
					   WFlags pWFlags):
					   zSisConexion(pzSisConexion),
					   zSisConOExpendio(zSisConexion),
					   chrPtrArgumentos(pchrPtrArgumentos),
					   OrdenesRegistradas(pQWParent,pchrPtrName,pWFlags),
					   zOrdVenta(0),
					   chrPtrIdTipoOrden(0),
					   QWParent(pQWParent)
{
/*
delete QTWDatosOrden;
QTOrdenes->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

*/
}
void QtOrdenesRegistradas::ConectaSlots()
{
connect(QBGTipoOrden,SIGNAL(clicked(int)),SLOT(SlotTipoOrden(int)));

connect(QPBConsultar,SIGNAL(clicked()),SLOT(SlotConsulta()));
connect(QCtrFechaIni,SIGNAL(Signal_EnterA_o()),SLOT(SlotFocoAFechaFin()));
connect(QCtrFechaFin,SIGNAL(Signal_EnterA_o()),SLOT(SlotFocoAConsulta()));
connect(QTOrdenes,
	SIGNAL(clicked(int,int,int,const QPoint &)),
	SLOT(SlotOrden(int,int,int,const QPoint &)));

connect(QTOrdenes,
	SIGNAL(doubleClicked(int,int,int,const QPoint &)),
	SLOT(SlotDescripcion(int,int,int,const QPoint &)));
connect(QPBImprimir,SIGNAL(clicked()),SLOT(SlotImprimir()));
connect(QPBVender,SIGNAL(clicked()),SLOT(SlotVender()));
connect(QPBDevolucion,SIGNAL(clicked()),SLOT(SlotDevolucion()));
connect(QPBSeReflejo,SIGNAL(clicked()),SLOT(SlotSeReflejo()));
}
void QtOrdenesRegistradas::SlotSeReflejo()
{

}
void QtOrdenesRegistradas::SlotDescripcion(int pintFila,
					   int pintColumna,
					   int,
					   const QPoint &)
{
   if(pintColumna==1)
   CapturandoDescripcionCotizacion();
}
void QtOrdenesRegistradas::SlotConsulta()
{

}
void QtOrdenesRegistradas::SlotImprimir()
{

}
void QtOrdenesRegistradas::SlotVender()
{

}
void QtOrdenesRegistradas::SlotDevolucion()
{

}

void QtOrdenesRegistradas::SlotCambiandoOrden(int pintOrden,
					     int)
{
   MuestraOrden(pintOrden); 
}
void QtOrdenesRegistradas::SlotOrden(int pintFila,
				    int pintColumna,
				    int,
				    const QPoint &)
{
  intOrdenSeleccionada[pintFila]=1;
   MuestraOrden(pintFila);
}
void QtOrdenesRegistradas::SlotFocoAConsulta()
{
zSiscomQt3::Foco(QPBConsultar);
}
void QtOrdenesRegistradas::SlotFocoAFechaFin()
{
  zSiscomQt3::Foco(QCtrFechaFin);
}
void QtOrdenesRegistradas::SlotTipoOrden(int pintIdBoton)
{
chrPtrIdTipoOrden=(this->*IdsTiposOrden[pintIdBoton])();
zSiscomQt3::Foco(QPBConsultar);
}

const char *QtOrdenesRegistradas::IdVenta()
{
  return "0";
}
const char *QtOrdenesRegistradas::IdCotizacion()
{
   return "1";
}
const char *QtOrdenesRegistradas::IdCircuitoImpreso()
{
   return "5";
}
const char *QtOrdenesRegistradas::IdPedido()
{
  return "4";
}

const char *QtOrdenesRegistradas::IdApartado()
{
  return "2";
}

const char *QtOrdenesRegistradas::IdTipoOrden()
{
  return chrPtrIdTipoOrden;
}
const char *QtOrdenesRegistradas::IdSinAsignar()
{
  return "0";
}
const char *QtOrdenesRegistradas::IdTransferencia()
{
  return "11";
}
const char *QtOrdenesRegistradas::IdTarjeta()
{
   return "12";
}
void QtOrdenesRegistradas::IniciaIdsTiposOrdenes()
{
IdsTiposOrden[0]=&QtOrdenesRegistradas::IdVenta;
IdsTiposOrden[1]=&QtOrdenesRegistradas::IdCotizacion;
IdsTiposOrden[2]=&QtOrdenesRegistradas::IdApartado;
IdsTiposOrden[3]=&QtOrdenesRegistradas::IdSinAsignar;
IdsTiposOrden[4]=&QtOrdenesRegistradas::IdPedido;
IdsTiposOrden[5]=&QtOrdenesRegistradas::IdCircuitoImpreso;
IdsTiposOrden[6]=&QtOrdenesRegistradas::IdSinAsignar;
IdsTiposOrden[7]=&QtOrdenesRegistradas::IdSinAsignar;
IdsTiposOrden[8]=&QtOrdenesRegistradas::IdSinAsignar;
IdsTiposOrden[9]=&QtOrdenesRegistradas::IdSinAsignar;
IdsTiposOrden[10]=&QtOrdenesRegistradas::IdSinAsignar;
IdsTiposOrden[11]=&QtOrdenesRegistradas::IdTransferencia;
IdsTiposOrden[12]=&QtOrdenesRegistradas::IdTarjeta;
IdsTiposOrden[13]=&QtOrdenesRegistradas::IdSinAsignar;
IdsTiposOrden[14]=&QtOrdenesRegistradas::IdSinAsignar;
}
void QtOrdenesRegistradas::IniciaVariables()
{
QCtrFechaFin->ColocaFechaHoy();
QCtrFechaIni->ColocaFechaHoy();
zSiscomQt3::Foco(QCtrFechaIni);
QConExpsV=new QConExpendiosVenta(zSisConexion,chrPtrArgumentos);
zSisConOExpendio=new zSiscomConexion;
ConexionExpendio();
}

void QtOrdenesRegistradas::IniciaTiposOrdenes()
{
TipoOrden[0]=&QtOrdenesRegistradas::Venta;
TipoOrden[1]=&QtOrdenesRegistradas::Cotizacion;
TipoOrden[2]=&QtOrdenesRegistradas::Apartado;
TipoOrden[3]=&QtOrdenesRegistradas::SinAsignar;
TipoOrden[4]=&QtOrdenesRegistradas::Pedido;
TipoOrden[5]=&QtOrdenesRegistradas::Cancelacion;
TipoOrden[6]=&QtOrdenesRegistradas::SinAsignar;
TipoOrden[7]=&QtOrdenesRegistradas::SinAsignar;
TipoOrden[8]=&QtOrdenesRegistradas::SinAsignar;
TipoOrden[9]=&QtOrdenesRegistradas::SinAsignar;
TipoOrden[10]=&QtOrdenesRegistradas::SinAsignar;
TipoOrden[11]=&QtOrdenesRegistradas::Transferencia;
TipoOrden[12]=&QtOrdenesRegistradas::Tarjeta;
TipoOrden[13]=&QtOrdenesRegistradas::SinAsignar;
TipoOrden[14]=&QtOrdenesRegistradas::SinAsignar;
}
void QtOrdenesRegistradas::IniciaDescripcionOrdenes()
{
Descripcion[0]=&QtOrdenesRegistradas::DescripcionVenta;
Descripcion[1]=&QtOrdenesRegistradas::DescripcionCotizacion;
Descripcion[2]=&QtOrdenesRegistradas::DescripcionApartado;
Descripcion[3]=&QtOrdenesRegistradas::DescripcionSinAsignar;
Descripcion[4]=&QtOrdenesRegistradas::DescripcionPedido;
Descripcion[5]=&QtOrdenesRegistradas::DescripcionCancelacion;
Descripcion[6]=&QtOrdenesRegistradas::DescripcionSinAsignar;
Descripcion[7]=&QtOrdenesRegistradas::DescripcionSinAsignar;
Descripcion[8]=&QtOrdenesRegistradas::DescripcionSinAsignar;
Descripcion[9]=&QtOrdenesRegistradas::DescripcionSinAsignar;
Descripcion[10]=&QtOrdenesRegistradas::DescripcionSinAsignar;
Descripcion[11]=&QtOrdenesRegistradas::DescripcionTransferencia;
Descripcion[12]=&QtOrdenesRegistradas::DescripcionTarjeta;
Descripcion[13]=&QtOrdenesRegistradas::DescripcionSinAsignar;
Descripcion[14]=&QtOrdenesRegistradas::DescripcionSinAsignar;
}
void QtOrdenesRegistradas::IniciaTipoEntrega()
{
TipoEntrega[0]=&QtOrdenesRegistradas::EntregaPuntoSiscom;
TipoEntrega[1]=&QtOrdenesRegistradas::EntregaDireccionCliente;

}
const char *QtOrdenesRegistradas::Cotizacion()
{
	return "Cotizacion";
}
const  char *QtOrdenesRegistradas::Venta()
{
   return "Venta";
}
const  char *QtOrdenesRegistradas::Apartado()
{
   return "Apartado";
}
const char *QtOrdenesRegistradas::Pedido()
{
   return "Pedido";
}
const char *QtOrdenesRegistradas::Cancelacion()
{
   return "Cancelada";
}
const char *QtOrdenesRegistradas::SinAsignar()
{
   return "Sin Asignar";
}
const char *QtOrdenesRegistradas::Transferencia()
{
    return "Transferencia";
}
const char *QtOrdenesRegistradas::Tarjeta()
{
    return "Tarjeta";
}
const char *QtOrdenesRegistradas::DescripcionCotizacion(zOrdenVenta *pzOrdenVenta)
{
return (char *)pzOrdenVenta->Cotizacion()->Descripcion();
}
const char *QtOrdenesRegistradas::DescripcionVenta(zOrdenVenta *pzOrdenVenta)
{
   return "";    
}
const char *QtOrdenesRegistradas::DescripcionTransferencia(zOrdenVenta *pzOrdenVenta)
{
    return pzOrdenVenta->FormaPago()->Transferencia()->Observaciones();
}
const char *QtOrdenesRegistradas::DescripcionTarjeta(zOrdenVenta *pzOrdenV)
{
   return "Pago con Tarjeta";
}
const char *QtOrdenesRegistradas::DescripcionApartado(zOrdenVenta *pzOrdenVenta)
{
char lchrArrCadena[1024];

SiscomRegistroLog2(pzOrdenVenta->Apartado());
sprintf(lchrArrCadena,
	"\n%s %s\n\n"
	"Fecha de Entrega %s\n\n"
	"ACuenta %s\n\n"
	"Observaciones :%s",
	pzOrdenVenta->Cliente()->Nombre(),
	pzOrdenVenta->Cliente()->APaterno(),
	pzOrdenVenta->Apartado()->FechaHoraE(),
	pzOrdenVenta->Apartado()->ACuenta(),
	pzOrdenVenta->Apartado()->Observaciones());
   return strdup(lchrArrCadena);
}
const char *QtOrdenesRegistradas::EntregaDireccionCliente(zOrdenVenta *pzOrdVenta)
{
  return "";
}
const char *QtOrdenesRegistradas::EntregaPuntoSiscom(zOrdenVenta *pzOrdVenta)
{
char lchrArrCadena[128];
sprintf(lchrArrCadena,
	"El Material se entrega en %s\n",
	pzOrdVenta->Pedido()->PuntoEntrega()->PuntoEntrega());
return strdup(lchrArrCadena);
}
const char *QtOrdenesRegistradas::EntregaPedido(zOrdenVenta *pzOrdVenta)
{
int lintTipoEntrega;
lintTipoEntrega=pzOrdVenta->Pedido()->CampoInt("TipoEntrega");
if(lintTipoEntrega>=0)
return (this->*TipoEntrega[lintTipoEntrega])(pzOrdVenta);
else
return "NO Se capturo Direccion entrega";
}
const char *QtOrdenesRegistradas::DescripcionPedido(zOrdenVenta *pzOrdenVenta)
{
char lchrArrPedido[1024];
sprintf(lchrArrPedido,
	"%s %s\n\n"
	"Hora Entrega %s\n"
	"Total Orden %s Paga con %s Cambio %s\n\n"
	"%s\n",
	pzOrdenVenta->Cliente()->Nombre(),
	pzOrdenVenta->Cliente()->APaterno(),
	pzOrdenVenta->Pedido()->FechaHoraE(),
	pzOrdenVenta->ImporteOrden(),
	pzOrdenVenta->Pedido()->SePagaCon(),
	pzOrdenVenta->Pedido()->Cambio(),
	EntregaPedido(pzOrdenVenta));
return strdup(lchrArrPedido);
}
const char *QtOrdenesRegistradas::DescripcionSinAsignar(zOrdenVenta *)
{
   return "";
}
const char *QtOrdenesRegistradas::DescripcionCancelacion(zOrdenVenta *)
{
   return "Cancelada";
}
void QtOrdenesRegistradas::Muestra()
{
zOrdenVenta *lzOrdenVenta;
char lchrArrTipoOrden[25];
int lintContador;
const char *lchrPtrTextos[]={"Cotizacion","Venta"};
QTOrdenes->setNumRows(zOrdsRegistradas->NNodos());
 for(lzOrdenVenta=(zOrdenVenta *)zOrdsRegistradas->Primer(),lintContador=0 ;
     lzOrdenVenta;
     lzOrdenVenta=(zOrdenVenta *)zOrdsRegistradas->Siguiente(),lintContador++)
{
/*
 QTOrdenes->setText(lintContador,0,(this->*TipoOrden[lzOrdenVenta->IdTipoOrdenInt()])());
 */
 QTOrdenes->setText(lintContador,0,lzOrdenVenta->Fecha());
 QTOrdenes->setText(lintContador,1,lzOrdenVenta->Cliente()->Escuela());
 QTOrdenes->setText(lintContador,2,lzOrdenVenta->ImporteOrden());
 QTOrdenes->setText(lintContador,3,(this->*Descripcion[lzOrdenVenta->IdTipoOrdenInt()])(lzOrdenVenta));
 }

zSiscomQt3::AjustaColumnasTabla(QTOrdenes);
zSiscomQt3::AjustaFilasTabla(QTOrdenes);
}
void QtOrdenesRegistradas::Ordenes(zOrdenes *pzOrdenes)
{
	zOrdsRegistradas=pzOrdenes;
}
zOrdenes *QtOrdenesRegistradas::Ordenes()
{
    return zOrdsRegistradas;
}

void QtOrdenesRegistradas::MuestraOrden(int pintFila)
{
    if(pintFila!=-1)
    {
    	QTOrdenes->selectRow(pintFila);
	zOrdVenta=zOrdsRegistradas->Orden(pintFila);
	if(zOrdVenta)
	{
	MostrandoLaOrden(zOrdVenta);
	ActivandoBotones(true);
	}
    }
}
void QtOrdenesRegistradas::MostrandoLaOrden(zOrdenVenta *pzOrdenVenta)
{
int lintContador=0;
zProductoCotizar *lzProdCotizar;
 QTOrden->setNumRows(pzOrdenVenta->Productos()->NNodos());
for(lzProdCotizar=(zProductoCotizar *)pzOrdenVenta->Productos()->Primer();
    lzProdCotizar;
    lzProdCotizar=(zProductoCotizar *)pzOrdenVenta->Productos()->Siguiente())
{
   QTOrden->setText(lintContador,0,lzProdCotizar->Cantidad());
   QTOrden->setText(lintContador,1,lzProdCotizar->Clave());
   QTOrden->setText(lintContador,2,lzProdCotizar->Precio());
   QTOrden->setText(lintContador,3,lzProdCotizar->Importe());
   lintContador++;
}
zSiscomQt3::AjustaColumnasTabla(QTOrden);
}
void QtOrdenesRegistradas::ActivaBotonSeReflejo()
{
    QPBSeReflejo->setEnabled(Orden()->SePagoConTransferencia() && 
                             !Orden()->FormaPago()->Transferencia()->YaSeReflejoInt());
    
}
void QtOrdenesRegistradas::ActivandoBotones(bool pbActivo)
{
     ActivaBotones(pbActivo);
    ActivaBotonSeReflejo();

}
void QtOrdenesRegistradas::ActivaBotones(bool pbActivo)
{
 QPBVender->setEnabled(pbActivo);
 QPBImprimir->setEnabled(pbActivo);
 QPBDevolucion->setEnabled(pbActivo);
}
zOrdenVenta *QtOrdenesRegistradas::Orden()
{
	return zOrdVenta;
}
void QtOrdenesRegistradas::CapturandoDescripcionCotizacion()
{
QCapturaDescripcionCotizacion lQCapDesCotizacion(1,"Envio",Orden(),Conexion(),QWParent);
ActualizaDescripcion();
Muestra();
}

void QtOrdenesRegistradas::keyPressEvent(QKeyEvent *pQKETeclas)
{
   TeclasEspeciales(pQKETeclas); 
}
void QtOrdenesRegistradas::TeclasEspeciales(QKeyEvent *pQKETeclas)
{
   if(pQKETeclas->state()==Qt::AltButton)
   {
	if(pQKETeclas->key()==Qt::Key_F1)
	    CambiandoExpendio();
   }
   else
   if(pQKETeclas->state()==Qt::ControlButton)
   if(pQKETeclas->key()==Qt::Key_D)
   CopiandoPortaPapeles();
   else
   if(pQKETeclas->key()==Qt::Key_C)
   CopiandoPortaPapelesOrden();
   else
	if(pQKETeclas->key()==Qt::Key_F12)
	MarcaOrden();

}
int QtOrdenesRegistradas::CambiandoExpendio()
{
       CambiaExpendio();
       MuestraExpendio();
}
int QtOrdenesRegistradas::CambiaExpendio()
{
   QConExpsV->Corriendo();
   ConexionExpendio();
}
void QtOrdenesRegistradas::ConexionExpendio()
{
   zSisConOExpendio->DireccionIp(QConExpsV->Actual()->DirIp());
   zSisConOExpendio->Puerto(QConExpsV->Actual()->PuertoInt());
}
zSiscomConexion *QtOrdenesRegistradas::Conexion()
{
    return zSisConOExpendio;
}
void QtOrdenesRegistradas::MuestraExpendio()
{
  setCaption(QConExpsV->Actual()->RazonSocial());
}
const char *QtOrdenesRegistradas::IdExpendio()
{
   return QConExpsV->Actual()->IdExpendio();
}
void QtOrdenesRegistradas::MarcaCotizacionComoVendida()
{
if(Orden()->EsCotizacion())
{
QString lQStrDescripcion=Orden()->Cotizacion()->Descripcion();
 lQStrDescripcion+="\nVendida :)\n"; 
 Orden()->Cotizacion()->Descripcion((const char *)lQStrDescripcion);
 ActualizaDescripcion();
}
}
void QtOrdenesRegistradas::ActualizaDescripcion()
{
zSiscomElectronica lzSEACotizacion(Conexion(),"ActualizaDescripcionCotizacion");
lzSEACotizacion.ActualizaDescripcionCotizacion(Orden());
}
void QtOrdenesRegistradas::CopiandoPortaPapeles()
{
 char *lchrPtrTexto=0;
 zTextoWhatsApp lzTextoW(Orden());
 lzTextoW.CotizacionWhats(&lchrPtrTexto);
  QApplication::clipboard()->setText(lchrPtrTexto); 

}
void QtOrdenesRegistradas::CopiandoPortaPapelesOrden()
{
zSiscomConexion lzSisConexion;
char lchrArrOrden[32192];
zSiscomRegistros lzSisRegsEnvio;
lzSisRegsEnvio << Orden();
SiscomRegistroLog2(Orden());
lchrArrOrden[0]=0;
lzSisConexion.Cadena(lchrArrOrden);
zSiscomEnvioACadena lzSisEnvioACadena(&lzSisConexion,&lzSisRegsEnvio);
LogSiscom("La cadenota \n\n\n%s\n\n%d\n",
	  lzSisConexion.Cadena(),
	  strlen(lchrArrOrden));
QApplication::clipboard()->setText(lchrArrOrden);
}
zOrdenVenta *QtOrdenesRegistradas::Orden(int pintNOrden)
{
    return (zOrdenVenta *)(*Ordenes())[pintNOrden];
}


void QtOrdenesRegistradas::MarcaOrden()
{
   zSiscomQt3::ColoreaFilas(QTOrdenes,Qt::green,intOrdenSeleccionada);
}

void QtOrdenesRegistradas::Parent(QWidget *pQWParent)
{
  QWParent=pQWParent;
}

QWidget *QtOrdenesRegistradas::Parent()
{
   return QWParent;
}
