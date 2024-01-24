#include <IMP_RegistroPlaca.h>
#include <IMP_ClientesRegistrados4.h>
#include <IMP_ClientePedido.h>
#include <IMP_SePagaOrdenImpreso.h>
#include <QCtrlFechaHora.h>

#include <zSiscomElectronica.h>
#include <zClienteSiscom.h>
#include <zPersona.h>
#include <zTelefono.h>
#include <zOrdenVenta.h>
#include <zCircuitoImpreso.h>
#include <zProductoCotizar.h>
#include <zApartado.h>

#include <zSiscomDesarrollo4.h>
#include <zSiscomRegistro.h>
#include <zSiscomQt3.h>

#include <qlineedit.h>
#include <qtextedit.h>
#include <qpushbutton.h>
#include <qmessagebox.h>
#include <qcombobox.h>
#include <qlcdnumber.h>


QRegistroPlaca::QRegistroPlaca(zSiscomConexion *pzSiscomConexion,
			      QWidget *pQWParent,       
			       const char *pchrPtrName,
			       bool pbModal,
			       WFlags pWFlags):	      
				RegistroPlaca(pQWParent,pchrPtrName,pbModal,pWFlags),
				 zSisConexion((zSiscomConexion *)pzSiscomConexion),
				 intImprimioComprobante(0),
				 zOrdVenta(0),
				 intNImpresosRegistrados(0),
				 intPuedeCerrarVentana(0),
				 intRegistrando(0)
{
/*IniciaVariables(); */
ConectaSlots();
}

QRegistroPlaca::~QRegistroPlaca()
{

}

void QRegistroPlaca::ConectaSlots()
{
connect(QCBProductos,SIGNAL(activated(int)),SLOT(SlotProducto(int)));
connect(QLENombre,SIGNAL(returnPressed()),SLOT(SlotFocoAAPaterno()));
connect(QLEAPaterno,SIGNAL(returnPressed()),SLOT(SlotFocoAAMaterno()));
connect(QLEAMaterno,SIGNAL(returnPressed()),SLOT(SlotFocoARegistraPersonales()));

connect(QLECelular,SIGNAL(returnPressed()),SLOT(SlotFocoAReCelular()));
connect(QLEReCelular,SIGNAL(returnPressed()),SLOT(SlotValidandoCapturaCelular()));
connect(QPBRegistraPersonales,SIGNAL(clicked()),SLOT(SlotRegistraPersonales()));
connect(QPBRegistraCelular,SIGNAL(clicked()),SLOT(SlotRegistraCelular()));
connect(QPBImprimeComprobante,SIGNAL(clicked()),SLOT(SlotImprimeComprobante()));
connect(QPBRegistra,SIGNAL(clicked()),SLOT(SlotRegistra()));
connect(QCtrFechaEntrega,SIGNAL(Signal_EnterMinuto()),SLOT(SlotFocoAArchivo()));
connect(QPBAceptar,SIGNAL(clicked()),SLOT(SlotAceptar()));
connect(QPBCancelar,SIGNAL(clicked()),SLOT(SlotCancelar()));

connect(QLENombre,SIGNAL(textChanged(const QString &)),SLOT(SlotCapturandoNombre(const QString &)));
connect(QLEAPaterno,SIGNAL(textChanged(const QString &)),SLOT(SlotCapturandoNombre(const QString &)));
connect(QLEAMaterno,SIGNAL(textChanged(const QString &)),SLOT(SlotCapturandoNombre(const QString &)));

connect(QTEArchivo,SIGNAL(textChanged()),SLOT(SlotCapturandoDatosParaImpreso()));
connect(QTEMemoria,SIGNAL(textChanged()),SLOT(SlotCapturandoDatosParaImpreso()));
connect(QLECelular,SIGNAL(textChanged(const QString &)),SLOT(SlotCapturandoCelular(const QString &)));
connect(QLEReCelular,SIGNAL(textChanged(const QString &)),SLOT(SlotCapturandoCelular(const QString &)));
}
void QRegistroPlaca::SlotCapturandoCelular(const QString &)
{
	ValidandoDatosCelular();
}
void QRegistroPlaca::SlotCapturandoDatosParaImpreso(const QString &)
{
   ValidandoDatosParaImpreso();
}

void QRegistroPlaca::SlotCapturandoDatosParaImpreso()
{
   ValidandoDatosParaImpreso();
}
void QRegistroPlaca::SlotCapturandoNombre(const QString &)
{
	ValidandoDatosMinimosNombre();
}
void QRegistroPlaca::SlotCancelar()
{
	intAceptar=0;
	done(1);
}
void QRegistroPlaca::SlotAceptar()
{
        zOrdVenta->IdTipoOrden(intPagado ? "0" :"2");
	if(!intPagado)
	{
	  zOrdVenta->Cliente()->Nombre(zSiscomQt3::Texto(QLENombre));
	  zOrdVenta->Cliente()->APaterno(zSiscomQt3::Texto(QLEAPaterno));
	  zOrdVenta->Cliente()->AMaterno(zSiscomQt3::Texto(QLEAMaterno));
	}
	intAceptar=1;
	done(1);
}

void QRegistroPlaca::SlotFocoAArchivo()
{
  zSiscomQt3::Foco(QTEArchivo);
}
void QRegistroPlaca::SlotImprimeComprobante()
{
zOrdenVenta *lzOrdVenta;
 lzOrdVenta=OrdenImpreso();
 AgregandoDatosOrden(lzOrdVenta);
 Imprimiendo(lzOrdVenta);
 QPBRegistra->setEnabled(true);
 zSiscomQt3::Foco(QPBRegistra);
 intImprimioComprobante=1;

}
void QRegistroPlaca::SlotRegistra()
{
   RegistrandoImpreso();
   SigueRegistrando();
   intRegistrando=1;
}
void QRegistroPlaca::SlotProducto(int pintNProducto)
{
	intClaveImpreso=pintNProducto; 
if(EsCircuitoImpreso(zOrdVenta->Producto(pintNProducto)))
{

	if(!intRegistrando)	
	  zSiscomQt3::Foco(QLENombre);
	else
	  zSiscomQt3::Foco(QCtrFechaEntrega); 
}
else
QMessageBox::information(this,"Aviso Sistema","El Producto NO Es un circuito Impreso");
}
void QRegistroPlaca::SlotRegistraCelular()
{
  if(RegistrandoCelular())
  {
	ControlesAFechaHoraEntrega();
  }
  else
  {

  }
}
void QRegistroPlaca::SlotValidandoCapturaCelular()
{
  if(!ValidandoTelefono())
  zSiscomQt3::Foco(QLECelular);
  else
  zSiscomQt3::Foco(QPBRegistraCelular);
}
void QRegistroPlaca::SlotRegistraPersonales()
{
int lintRegistro;
	if((lintRegistro=RegistrandoPersonales())==1)
	{
	  ControlesARegistroCelular();
	}
	else
	if((lintRegistro==2))
	   zOrdVenta->Cliente(zCliSiscom);
}
void QRegistroPlaca::SlotFocoAAPaterno()
{
  zSiscomQt3::Foco(QLEAPaterno);
}
/*

void QRegistroPlaca::SlotFocoA()
{
	zSiscomQt3::Foco(QLE);
}

*/

void QRegistroPlaca::SlotFocoAAMaterno()
{
	zSiscomQt3::Foco(QLEAMaterno);
}
void QRegistroPlaca::SlotFocoACelular()
{
	zSiscomQt3::Foco(QLECelular);
}
void QRegistroPlaca::SlotFocoAReCelular()
{
	zSiscomQt3::Foco(QLEReCelular);
}

void QRegistroPlaca::SlotFocoARegistraPersonales()
{
	zSiscomQt3::Foco(QPBRegistraPersonales);
}

void QRegistroPlaca::IniciaVariables()
{
 QCtrFechaEntrega->ColocaFechaHoy();
 ConsultandoImpresosPendientes();
}
void QRegistroPlaca::Ejecutando()
{
 CargandoSePagaOrdenImpreso();
 MuestraProductos();
 QLCDNNImpresos->display(CuantosImpresosHayEnLaOrden());
 zSiscomQt3::Foco(QCBProductos);
 exec();
}
zClienteSiscom *QRegistroPlaca::Cliente()
{
return new zClienteSiscom("",
			  zSiscomQt3::Texto(QLENombre),
			  zSiscomQt3::Texto(QLEAPaterno),
			  zSiscomQt3::Texto(QLEAMaterno));
}
int QRegistroPlaca::RegistrandoPersonales()
{
int lintRegistro;
if((lintRegistro=RegistraCliente())==1)
{
  	SiscomRegistroLog2(zCliSiscom);
	zCliSiscom->Escuela(zSisRegEscuela);
	LogSiscom("La Escuela %s",zCliSiscom->Escuela());
	SiscomRegistroLog2(zSisRegEscuela);
	zOrdVenta->Cliente(zCliSiscom);
	return 1;
}
else
if(lintRegistro==2)
{
	if(MuestraClientesSimilares()==1)
	return 2;
	else
	return -1;
}

}
int QRegistroPlaca::RegistraCliente()
{
zSiscomElectronica lzSisElectronica(zSisConexion,"RegistraClientePersona");
return lzSisElectronica.RegistraCliente((zCliSiscom=Cliente()),&zClisSiscom);
}

int QRegistroPlaca::MuestraClientesSimilares()
{
QClientesRegistrados4 lQCRegistrados(zClisSiscom);
if(lQCRegistrados.Aceptar())
{
delete zCliSiscom;
zCliSiscom=lQCRegistrados.Cliente();
zCliSiscom->Escuela(zSisRegEscuela);
MuestraCliente();
intRegistroPersonales=0;
return 1;
}
else
{
LogSiscom("Se presiono cancelacion");
return -1;
}
}

void QRegistroPlaca::MuestraCliente()
{
    QLENombre->setText(zCliSiscom->Nombre());
    QLEAPaterno->setText(zCliSiscom->APaterno());
    QLEAMaterno->setText(zCliSiscom->AMaterno());
    QLECelular->setText(zCliSiscom->Celular()->Telefono());

}
void QRegistroPlaca::Escuela(zSiscomRegistro *pzSisRegEscuela)
{
	zSisRegEscuela=pzSisRegEscuela;
}
void QRegistroPlaca::ControlesARegistroCelular()
{
    QPBRegistraPersonales->setEnabled(false);
    QPBRegistraCelular->setEnabled(true);
    zSiscomQt3::Foco(QLECelular);
}

int QRegistroPlaca::ValidandoTelefono()
{
char lchrArrMensajeNoIgual[256];
zSiscomElectronica lzSisElectronica(zSisConexion,"ValidaReCaptura");
if(!lzSisElectronica.ValidaReCaptura(zSiscomQt3::Texto(QLECelular),
				     zSiscomQt3::Texto(QLEReCelular)))
{
sprintf(lchrArrMensajeNoIgual,
	"El Numero (%s) No es igual a (%s)",
	zSiscomQt3::Texto(QLECelular),
	zSiscomQt3::Texto(QLEReCelular));
  QMessageBox::information(this,"Aviso Sistema",lchrArrMensajeNoIgual);
  zSiscomQt3::Foco(QLECelular);
  return 0;
}
else
return 1;
}

int QRegistroPlaca::RegistrandoCelular()
{
   zCliSiscom->Celular(FormaCelular());
  if(RegistraCelular())
  return 1;
  else
  return 0;
}

zTelefono *QRegistroPlaca::FormaCelular()
{
   return new zTelefono("",zSiscomQt3::Texto(QLECelular));
}

int QRegistroPlaca::RegistraCelular()
{
zSiscomElectronica lzSisElectronica(zSisConexion,"RegistraCelularAlumno");
 return lzSisElectronica.RegistraCelularAlumno(zCliSiscom);
}
void QRegistroPlaca::ControlesAFechaHoraEntrega()
{
   QPBRegistraCelular->setEnabled(false);
   zSiscomQt3::Foco(QCtrFechaEntrega);
}
void QRegistroPlaca::Orden(zOrdenVenta *pzOrden)
{
	zOrdVenta=pzOrden;
}
void QRegistroPlaca::MuestraProductos()
{
if(zOrdVenta && zOrdVenta->Productos())
zSiscomQt3::RegistrosAlCombo(QCBProductos,"Clave",zOrdVenta->Productos());
}
int QRegistroPlaca::RegistraImpreso()
{
 zSiscomElectronica lzSisElectronica(zSisConexion,"RegistraCircuitoImpreso");
 lzSisElectronica.RegistraImpreso(zCirImpreso);
 intNImpresosRegistrados++;
 QLCDNNImpRegistrados->display(intNImpresosRegistrados);
}
int QRegistroPlaca::RegistrandoImpreso()
{
    RegistraImpreso();
    ConsultandoImpresosPendientes();
}
zCircuitoImpreso *QRegistroPlaca::FormaCircuitoImpreso(zOrdenVenta *pzOrdVenta)
{
zCircuitoImpreso *lzCirImpreso=new zCircuitoImpreso("");
lzCirImpreso->IdVenta(pzOrdVenta->IdVenta());
lzCirImpreso->IdCliente(pzOrdVenta->Cliente()->IdPersona());
lzCirImpreso->CveProducto(pzOrdVenta->Clave(0));
lzCirImpreso->Memoria(zSiscomQt3::Texto(QTEMemoria));
lzCirImpreso->Archivo(zSiscomQt3::Texto(QTEArchivo));
lzCirImpreso->FechaHoraEntrega((const char *)QCtrFechaEntrega->ObtenFechaHora());
lzCirImpreso->Pagado(intPagado ? "Si" : "No");
return lzCirImpreso;
}

void QRegistroPlaca::ConsultandoImpresosPendientes()
{
   ConsultaImpresosPendientes();
   MuestraImpresosPendientes();
}

void QRegistroPlaca::ConsultaImpresosPendientes()
{
zSiscomElectronica lzSisElectronica(zSisConexion,"CircuitosImpresosPendientes");
lzSisElectronica.CircuitosImpresosRegistrados(&zSisRegsCircuitosPendientes);
}
void QRegistroPlaca::MuestraImpresosPendientes()
{
const char *lchrPtrCampos[]={"nombrecompleto",
			"telefono",
			"descripcion",
			"cveproducto",
			"fecha",
			"hora",
			"memoria",
			"archivo",
			(char *)0};
zSiscomQt3::LlenaTabla(lchrPtrCampos,zSisRegsCircuitosPendientes,QTDatos);
zSiscomQt3::AjustaColumnasTabla(QTDatos);
zSiscomQt3::AjustaFilasTabla(QTDatos);
}
void QRegistroPlaca::Imprimiendo(zOrdenVenta *pzOrdVenta)
{
    ImprimeUnaPlaca(pzOrdVenta);
}
void QRegistroPlaca::ImprimeUnaPlaca(zOrdenVenta *pzOrdVenta)
{
zSiscomElectronica lzSisElectronica(zSisConexion,"ImprimeTicketVenta4");
lzSisElectronica.ImprimeTicketVenta(pzOrdVenta);
}
zOrdenVenta *QRegistroPlaca::ImprimeVariasPlacas(zProductoCotizar *pzProdCotizar)
{
zOrdenVenta *lzOrdVenta=new zOrdenVenta(zOrdVenta);
lzOrdVenta->AgregaProducto(pzProdCotizar);
lzOrdVenta->Importe(pzProdCotizar->Precio());
return lzOrdVenta;
}
zOrdenVenta *QRegistroPlaca::OrdenImpreso()
{
  if(SeImprimeUnaPlaca())
  return zOrdVenta;
  else
  return ImprimeVariasPlacas(zOrdVenta->Producto(intClaveImpreso));
}
void QRegistroPlaca::AgregandoDatosOrden(zOrdenVenta *pzOrdVenta)
{
 zCirImpreso=FormaCircuitoImpreso(pzOrdVenta); 
 pzOrdVenta->CircuitoImpreso(zCirImpreso);
}
int QRegistroPlaca::Aceptar()
{
	return intAceptar; 
}
int QRegistroPlaca::SeImprimioComprobante()
{
  return intImprimioComprobante;
}
void QRegistroPlaca::ValidandoDatosMinimosNombre()
{
    QPBRegistraPersonales->setEnabled(zSiscomQt3::TextoValido(QLENombre)     &&
                		      zSiscomQt3::TextoValido(QLEAPaterno)   &&
               			      zSiscomQt3::TextoValido(QLEAMaterno));
}
void QRegistroPlaca::ValidandoDatosParaImpreso()
{
 QPBImprimeComprobante->setEnabled(zSiscomQt3::TextoValido(QTEArchivo) &&
				   zSiscomQt3::TextoValido(QTEMemoria));
}
void QRegistroPlaca::ValidandoDatosCelular()
{
    QPBRegistraCelular->setEnabled(zSiscomQt3::TextoValido(QLECelular) &&
    				   zSiscomQt3::TextoValido(QLEReCelular));
}

int QRegistroPlaca::SeImprimeUnaPlaca()
{
   return zOrdVenta->NumProductos()==1;
}
void QRegistroPlaca::reject()
{
   LogSiscom("Impresos Registrados %d ? Impresos en la Orden %d",
   		intNImpresosRegistrados,
		CuantosImpresosHayEnLaOrden());
   done(2);
}
void QRegistroPlaca::SigueRegistrando()
{
  
   if(intNImpresosRegistrados==CuantosImpresosHayEnLaOrden())
   intPuedeCerrarVentana=1;
   else
   {
     HabilitaDesHabilitaDatos(false);
   }

   QPBAceptar->setEnabled(SePuedeCerrarLaVentana());
   QPBRegistra->setEnabled(false);
   zSiscomQt3::Foco(QCBProductos); 

}
int QRegistroPlaca::CuantosImpresosHayEnLaOrden()
{
int lintContador;
int lintNImpresos=0;
for(lintContador=0;lintContador<zOrdVenta->ProductosCotizados();lintContador++)
if(zOrdVenta->Producto(lintContador)->TipoProductoInt()==4)
lintNImpresos++;
return lintNImpresos;
}


void QRegistroPlaca::HabilitaDesHabilitaDatos(bool pbEstado)
{
  QLENombre->setEnabled(pbEstado);
  QLEAPaterno->setEnabled(pbEstado);
  QLEAMaterno->setEnabled(pbEstado);
  QLECelular->setEnabled(pbEstado);
  QLEReCelular->setEnabled(pbEstado);
}
int QRegistroPlaca::EsCircuitoImpreso(zProductoCotizar *pzProdCotizar)
{
  return pzProdCotizar->TipoProductoInt()==4;
}
int QRegistroPlaca::SePuedeCerrarLaVentana()
{
   return CuantosImpresosHayEnLaOrden()==intNImpresosRegistrados;	
}
void QRegistroPlaca::AsignaOrdenComoApartado()
{
 LogSiscom("Se Procesa la orden como apartado");
}

void QRegistroPlaca::CargandoSePagaOrdenImpreso()
{
char lchrArrACuenta[12];
  if(zOrdVenta && zOrdVenta->ProductosCotizados())
  {
	QSePagaOrdenImpreso lQSPOImpreso(zOrdVenta,CuantosImpresosHayEnLaOrden());
	if((intPagado=lQSPOImpreso.SePagaCompleto()))
	{
	    
	}
	 else
	 {
	    LogSiscom("Se procesa la orden como apartado"); 
	    lQSPOImpreso.ACuenta(lchrArrACuenta);
	    FormaRegistroApartado(lchrArrACuenta);
	 }
  }
}
int QRegistroPlaca::Pagado()
{
   return intPagado;
}
void QRegistroPlaca::FormaRegistroApartado(const char *pchrPtrACuenta)
{
zApartado *lzApartado;
lzApartado=new zApartado(pchrPtrACuenta,
			 (const char *)QCtrFechaEntrega->ObtenFechaHora(),
			 "");
zOrdVenta->Apartado(lzApartado);
}
