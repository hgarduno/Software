#include <IMP_ClienteAlumno.h>
#include <IMP_RegistroApartado.h>
#include <IMP_CierraApartado.h>
#include <IMP_DescripcionCotizacion.h>
#include <IMP_Cotizaciones.h>
#include <IMP_EstadosPedido.h>
#include <IMP_RegistroPlaca.h>
#include <IMP_MaterialAreaDiseno.h>
#include <IMP_DonacionMaterial.h>
#include <IMP_SeleccionaOrden.h>
#include <IMP_DatosPractica.h>

#include <zSiscomElectronica.h>

#include <QCtrlEscuelasSE.h>
#include <QCtrlClientesMayoreo.h>
#include <QCtrlOrdenesFavoritas.h>
#include <zClienteSiscom.h>
#include <zPersona.h>
#include <zApartado.h>
#include <zCotizacion.h>
#include <zOrdenVenta.h>
#include <zConexionExpendio.h>

#include <zSiscomDesarrollo4.h>
#include <zSiscomRegistro.h>
#include <zSiscomQt3.h> 
#include <qpushbutton.h>
#include <qbuttongroup.h>
#include <qlineedit.h>
#include <qtextedit.h>
#include <qradiobutton.h>

QClienteAlumno::QClienteAlumno(const char *pchrPtrTipoPersona,
			       zOrdenVenta *pzOrdenVenta,
			       QWidget *pQWParent,       
			       const char *pchrPtrName,
			       bool pbModal,
			       WFlags pWFlags):	      
				ClienteAlumno(pQWParent,pchrPtrName,pbModal,pWFlags),
				intAceptar(0),
				zSisRegEscuela(0),
				zOrdVenta(pzOrdenVenta),
				zCliSiscom(0),
				intMRegApartado(0),
				zCotOrden(pzOrdenVenta->Cotizacion()),
				intTipoOrden(0),
				intSeImprimio(0),
				chrPtrTipoPersona(pchrPtrTipoPersona),
				intSeCapturoDesVenta(0)
				
{
IniciaVariables();
ConectaSlots();
VerificandoVendiendo(); 
exec();
}

QClienteAlumno::~QClienteAlumno()
{
}
void QClienteAlumno::IniciaVariables()
{
if(zOrdVenta)
zCliSiscom=zOrdVenta->Cliente();
QCtrEscuelas->Servidor(Orden()->Expendio());
QCtrEscuelas->IniciaControl();
QCtrClientesMayoreo->Servidor(Orden()->Expendio());
QCtrClientesMayoreo->IniciaControl();
QCtrOrdenesFavoritas->Servidor(Orden()->Expendio());
QCtrOrdenesFavoritas->IniciaControl();
QCtrOrdenesFavoritas->ModoControl(1);
zSiscomQt3::Foco(QCtrEscuelas);
QPBNuevaOrden->setEnabled(!strcmp(chrPtrTipoPersona,"1173311497"));
ConectaSlotsOtrosMovimientos();
}
void QClienteAlumno::IniciaControlesOtrosMovimientos()
{
}
void QClienteAlumno::ConectaSlotsOtrosMovimientos()
{
connect(QBGTipoOrden,SIGNAL(clicked(int)),SLOT(SlotTipoOrden(int)));
}
void QClienteAlumno::ConectaSlots()
{
connect(QCtrEscuelas,
	SIGNAL(SignalSelecciono(zSiscomRegistro *)),
	SLOT(SlotEscuela(zSiscomRegistro *)));
connect(QPBAceptar,SIGNAL(clicked()),SLOT(SlotAceptar()));
connect(QPBCancelar,SIGNAL(clicked()),SLOT(SlotCancelar()));
connect(QPBOtrosMovimientos,SIGNAL(clicked()),SLOT(SlotOtroMovimiento()));
connect(QPBNuevaOrden,SIGNAL(clicked()),SLOT(SlotNuevaOrden()));
connect(QCtrClientesMayoreo,
	SIGNAL(SignalSelecciono(zSiscomRegistro *)),
	SLOT(SlotClienteMayoreo(zSiscomRegistro *)));
connect(QTEDesVenta,SIGNAL(textChanged()),SLOT(SlotCapturandoDesVenta()));
connect(QCtrOrdenesFavoritas,
	SIGNAL(SignalOrdenVenta(zOrdenVenta *)),
	SLOT(SlotOrdenFavorita(zOrdenVenta *)));
}
void QClienteAlumno::SlotOrdenFavorita(zOrdenVenta *pzOrdenVenta)
{
	zOrdVenta->AgregandoProductos(pzOrdenVenta->Productos());
	intAceptar=100;
	zSiscomQt3::Foco(QPBAceptar);
}
void QClienteAlumno::SlotCapturandoDesVenta()
{
   intSeCapturoDesVenta=1;
}
void QClienteAlumno::SlotModificaCotizacion(zOrdenVenta *pzOrdenVenta)
{
  zOrdVenta->IdVenta(pzOrdenVenta->IdVenta());
  zOrdVenta->AgregandoProductos(pzOrdenVenta->Productos());
  zOrdVenta->Cotizacion(pzOrdenVenta->Cotizacion()); 
  zOrdVenta->Cliente(pzOrdenVenta->Cliente());
  Orden()->NumProductos(pzOrdenVenta->NumProductos());
  Orden()->IdTipoOrden("1");
  intAceptar=110;
  zSiscomQt3::Foco(QPBAceptar);
}
void QClienteAlumno::SlotClienteMayoreo(zSiscomRegistro *pzSisRegCliente)
{
        zCliSiscom=new zClienteSiscom(pzSisRegCliente);
	QPBOtrosMovimientos->setEnabled(true);
	QPBAceptar->setEnabled(true);
	zSiscomQt3::Foco(QPBAceptar);
}
void QClienteAlumno::SlotNuevaOrden()
{
  ConsultandoPublicoEnGeneral();
  intAceptar=99;
  QCtrEscuelas->setEnabled(true);
  zSiscomQt3::Foco(QCtrEscuelas);
}
void QClienteAlumno::SlotOrdenVenta(zOrdenVenta *pzOrdVenta)
{
/*    Tepotzotlan Mexico a 25/10/2020
 *    Problema de sobre escribir la direccion del apuntador 
 *    que se esta pasando desde el inicio de la orden, al dar nueva 
 *    orden
 	zOrdVenta=pzOrdVenta;		
*/
	zOrdVenta->AgregandoProductos(pzOrdVenta->Productos());	
	zOrdVenta->NumProductos(pzOrdVenta->NumProductos());
	showExtension(false);
	intAceptar=100;
	zSiscomQt3::Foco(QPBAceptar);
}
void QClienteAlumno::SlotCancelarApartado()
{
 LogSiscom("");
}
/* Ecatepec 
 * Miercoles 16 de Junio 2021
 * Segun salimos ya a semaforo verde COVID 
 *
 * Se debe revisar la inicializacion de estos controles
 * ya que se tarda mucho en abrir, la interfaz cuando se 
 * seleccionan otros movimientos. 
 *
 * Lo que hice, fue sacar de la funcion IniciaControles 
 * esto, para que al abrir la interfaz y seleccionar escuela
 * y venta directa, no se tarde mucho, pero falta revisar 
 * como hacer de una mejor forma los otros movimientos 
 *
 */
void QClienteAlumno::SlotOtroMovimiento()
{
	QPBOtrosMovimientos->setEnabled(false);
//	IniciaControlesOtrosMovimientos();
/* Siscom Zacatenco 
 * Jueves 23 Mayo del 2024 
 *
 * En esta parte se observo que al estar cargando cotizaciones para modificarse 
 * se debe capturar de nuevo la escuela  y dar otros movimientos, pero para el 
 * caso de modificar cotizacion esa informacion ya eta registrada, solo se debe
 * cargar por numero de cotizacion y ya viene la informacion de escuela etc
 */
/*
	ConectaSlotsOtrosMovimientos();
*/
	QBGTipoOrden->setEnabled(zCliSiscom && zCliSiscom->Escuela() ? 1 : 0);
	HabilitaBotonesOtrosMovimientos(zCliSiscom && zCliSiscom->Escuela() ? 1 : 0);

}
void QClienteAlumno::SlotCotizacion(zCotizacion *pzCotizacion)
{
   zCotOrden=pzCotizacion;
   QDCotizacion->Cierra();
   HabilitaDesHabilitaAceptarCancelar(true);
   zSiscomQt3::Foco(QPBAceptar);
   delete QDCotizacion;
   LogSiscom("Tomo la descripcion de la cotizacion ...");
}
void QClienteAlumno::SlotPagar(zOrdenVenta *pzOrdenVenta)
{
    zOrdenVApartado=pzOrdenVenta;
    PagarApartado();
    zSiscomQt3::Foco(QPBAceptar);
}
void QClienteAlumno::SlotTipoOrden(int pintTipoOrden)
{
   if(pintTipoOrden==2)
    CapturaDatosApartado();
    else
    if(pintTipoOrden==1)
    CapturaDescripcionCotizacion();
    else
    if(pintTipoOrden==100)
    VendeCotizacion(); 
    else
    if(pintTipoOrden==101)
    CierraApartado();
    else
    if(pintTipoOrden==103)
    OrdenActual();
    else
    if(pintTipoOrden==102)
    ConsultandoEstadosPedido();
    else
    if(pintTipoOrden==105)
    RegistrandoPlaca();
    else
    if(pintTipoOrden==107)
    MaterialAreaDiseno();
    else
    if(pintTipoOrden==108)
    DonacionMaterial();
    else
    if(pintTipoOrden==109)
    ModificaOrden();
    else
    if(pintTipoOrden==111)
    DatosPractica();

}
void QClienteAlumno::SlotFocoAAceptar()
{
   zSiscomQt3::Foco(QPBAceptar);
}
void QClienteAlumno::SlotCancelar()
{
   intAceptar=120;
   done(1);
}

void QClienteAlumno::SlotAceptar()
{
SeAgregaDescripcionVenta();
done(1);
}
void QClienteAlumno::SlotCanceloRegistroApartado()
{
    HabilitaDesHabilitaAceptarCancelar(true);
 intAceptar=103;
}
void QClienteAlumno::SlotEscuela(zSiscomRegistro *pzSisRegEscuela)
{
	zSisRegEscuela=pzSisRegEscuela;
	zCliSiscom->Escuela(pzSisRegEscuela);
	QPBOtrosMovimientos->setEnabled(true);
	QPBAceptar->setEnabled(true);
	zSiscomQt3::Foco(QPBAceptar);
	QCtrOrdenesFavoritas->HabilitaBotones(true);
}
void QClienteAlumno::SlotAceptarApartado()
{
    AsignaApartado();
    HabilitaDesHabilitaAceptarCancelar(true);
    zSiscomQt3::Foco(QPBAceptar);
}
void QClienteAlumno::AsignaApartado()
{
   zCliSiscom=QRApartado->Cliente();
}
zClienteSiscom *QClienteAlumno::Cliente()
{
  return zCliSiscom;
}
int QClienteAlumno::Aceptar()
{
  return intAceptar;
}

void QClienteAlumno::ConsultandoPublicoEnGeneral()
{
  ConsultaPublicoEnGeneral();
  MuestraPublicoEnGeneral();
}
void QClienteAlumno::ConsultaPublicoEnGeneral()
{
zCliSiscom=zSiscomElectronica::ClientePublicoEnGeneral(Orden()->Expendio());
}
void QClienteAlumno::MuestraPublicoEnGeneral()
{
   //QPBPublicoEnGeneral->setEnabled(zCliSiscom ? true : false);
}
void QClienteAlumno::reject()
{

}
void QClienteAlumno::CapturaDatosApartado()
{
QRApartado=new QRegistroApartado();
connect(QRApartado,SIGNAL(SignalAceptar()),SLOT(SlotAceptarApartado()));
connect(QRApartado,SIGNAL(SignalCancelar()),SLOT(SlotCanceloRegistroApartado()));
HabilitaDesHabilitaAceptarCancelar(false);
QRApartado->Escuela(zSisRegEscuela);
QRApartado->Ejecutando();
intTipoOrden=2;
}
void QClienteAlumno::CapturaDescripcionCotizacion()
{
 QDCotizacion=new QDescripcionCotizacion(zCotOrden);
 LogSiscom("La Cotizacion %x",zCotOrden);
connect(QDCotizacion,
	 SIGNAL(SignalCotizacion(zCotizacion *)),
	 SLOT(SlotCotizacion(zCotizacion *)));
  QDCotizacion->setFocus();
  QDCotizacion->Ejecutando();
  intTipoOrden=1;
}
zApartado *QClienteAlumno::Apartado()
{
  if(intTipoOrden==2)
  return QRApartado->Apartado();
  else
  return 0;
}
zCotizacion *QClienteAlumno::Cotizacion()
{
	return zCotOrden;
}
const char *QClienteAlumno::IdTipoOrden()
{
char lchrArrIdOrden[28];
sprintf(lchrArrIdOrden,"%d",intTipoOrden);
return strdup(lchrArrIdOrden);
}
int QClienteAlumno::IdTipoOrdenInt()
{
  return intTipoOrden;
}
void QClienteAlumno::CierraApartado()
{
QCApartado=new QCierraApartado(Orden()->Expendio());
connect(QCApartado,
	SIGNAL(SignalPagar(zOrdenVenta *)),
	SLOT(SlotPagar(zOrdenVenta *)));
connect(QCApartado,
	SIGNAL(SignalCancelar()),
	SLOT(SlotCancelarApartado()));
QCApartado->exec();
}

void QClienteAlumno::PagarApartado()
{
zSiscomElectronica lzSisElectronica(Orden()->Expendio(),"PagarApartado");
lzSisElectronica.CierraApartado(zOrdenVApartado);
}
void QClienteAlumno::VendeCotizacion()
{
QCotizacion=new QCotizaciones(Orden()->Expendio());
connect(QCotizacion,
	SIGNAL(SignalVendeOrden(zOrdenVenta *)),
	SLOT(SlotOrdenVenta(zOrdenVenta *)));
QCotizacion->Ejecutando();
delete QCotizacion;
}
void QClienteAlumno::VerificandoEscuela()
{
   if(zCliSiscom && zCliSiscom->Escuela())
   {
      QCtrEscuelas->setEnabled(false);
      QBGTipoOrden->setEnabled(false);
      QLEEscuela->setText(zCliSiscom->Escuela());
      QPBOtrosMovimientos->setEnabled(true);
      QPBAceptar->setEnabled(true);
      zSisRegEscuela=zCliSiscom->EscuelaReg();
   }
}
void QClienteAlumno::VerificandoNombre()
{
if(zCliSiscom->EsPublicoEnGeneral())
QLECliente->setText(zCliSiscom->Nombre());
else
{
  QLECliente->setText(QString(zCliSiscom->Nombre()) 	+
  	              " "				+
		      zCliSiscom->APaterno() 		+
		      " " 				+
		      zCliSiscom->AMaterno());
}
}
void QClienteAlumno::VerificandoVendiendo()
{
    if(!zCliSiscom) 
    ConsultandoPublicoEnGeneral();
    VerificandoEscuela();  
    VerificandoNombre();
}

zOrdenVenta *QClienteAlumno::Orden()
{
  return zOrdVenta;
}
void QClienteAlumno::OrdenActual()
{
	intTipoOrden=0;
	intAceptar=109;

}
void QClienteAlumno::ConsultandoEstadosPedido()
{
QEstadosPedido lQEstadoPedidos(Orden()->Expendio());
}
void QClienteAlumno::HabilitaDesHabilitaAceptarCancelar(bool pbHabilita)
{
  QPBAceptar->setEnabled(pbHabilita);
  QPBCancelar->setEnabled(pbHabilita);
}
void QClienteAlumno::RegistrandoPlaca()
{
   QRPlaca=new QRegistroPlaca(Orden()->Expendio());
  zOrdVenta->IdTipoOrden("6"); 
  QRPlaca->Orden(zOrdVenta);
  QRPlaca->Escuela(zSisRegEscuela); 
  QRPlaca->Ejecutando();
  if(QRPlaca->Aceptar()==1)
  {
	intTipoOrden=QRPlaca->Pagado() ? 0 : 2 ;
 	intSeImprimio=QRPlaca->SeImprimioComprobante();		
	intAceptar=105;
  }
  delete QRPlaca;
}
int QClienteAlumno::YaSeImprimio()
{
   return intSeImprimio; 
}
void QClienteAlumno::MaterialAreaDiseno()
{
QMaterialAreaDiseno lQMAreaDiseno;

if(lQMAreaDiseno.Aceptar())
{
	intAceptar=107;
	intTipoOrden=8;
	zOrdVenta->IdTipoOrden("8");
	zOrdVenta->MaterialAAreaDiseno(lQMAreaDiseno.MaterialAAreaDiseno());
}

}

void QClienteAlumno::DonacionMaterial()
{
QDonacionMaterial lQMDonacionM;
if(lQMDonacionM.Aceptar())
{
	intAceptar=108;
	intTipoOrden=9;
	zOrdVenta->IdTipoOrden("9");
	zOrdVenta->DonacionMaterial(lQMDonacionM.MaterialDonado());
}
}
void QClienteAlumno::ModificaOrden()
{
QSelOrden=new QSeleccionaOrden(Orden()->Expendio());
connect(QSelOrden,
	SIGNAL(SignalVendeOrden(zOrdenVenta *)),
	SLOT(SlotModificaCotizacion(zOrdenVenta *)));
QSelOrden->Ejecutando();
intAceptar=110;
intTipoOrden=1;
QPBAceptar->setEnabled(QSelOrden->Orden() ? 1 : 0);
zSiscomQt3::Foco(QPBAceptar);
delete QSelOrden;
}

int QClienteAlumno::SePagoImpreso()
{
   return QRPlaca->Pagado();
}
void QClienteAlumno::SeAgregaDescripcionVenta()
{
  if(zSiscomQt3::TextoValido(QTEDesVenta))
     zOrdVenta->Descripcion(zSiscomQt3::Texto(QTEDesVenta));
}
void QClienteAlumno::DatosPractica()
{
QDatosPractica lQDatosP(Orden()->Expendio(),zSisRegEscuela);
}
void QClienteAlumno::HabilitaBotonesOtrosMovimientos(bool pbEstado)
{
QRBApartado->setEnabled(pbEstado && (Orden()->NumProductos()>0));
QRBVendeOrdenCA->setEnabled(pbEstado);
QPBOrdenActual->setEnabled(pbEstado);
QRBCierraApartado->setEnabled(pbEstado);
QRBMaterilAD->setEnabled(pbEstado);
QRBDonacion->setEnabled(pbEstado);
QRBCotizacion->setEnabled(pbEstado);
}
