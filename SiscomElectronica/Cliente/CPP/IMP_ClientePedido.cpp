#include <IMP_ClientePedido.h>
#include <IMP_ClientesRegistrados4.h>
#include <IMP_Cotizaciones.h>
#include <QCtrlEscuelasSE.h>

#include <zOpsClientePedido.h>

#include <zSiscomElectronica.h>
#include <zProductoCotizar.h>
#include <zSiscomDesarrollo4.h>
#include <zSiscomRegistro.h>
#include <zSiscomQt3.h>
#include <zOrdenVenta.h>
#include <zCobertura.h>

#include <zClienteSiscom.h>
#include <zTelefono.h>
#include <zDireccion.h>
#include <zPuntoEntrega.h>
#include <zPedido.h>
#include <zConexionExpendio.h>

#include <zClientesSiscom.h>

#include <qtextedit.h> 
#include <qlineedit.h>
#include <qlcdnumber.h>
#include <qpushbutton.h>
#include <qtable.h>
#include <qmessagebox.h>
#include <qtabwidget.h>

QClientePedido::QClientePedido(zOrdenVenta *pzOrdVenta,
			       char **pchrPtrArgumentos, 
			       QWidget *pQWParent,       
			       const char *pchrPtrName,
			       bool pbModal,
			       WFlags pWFlags):
			QtClientePedido(pzOrdVenta,pQWParent,pchrPtrName,pbModal,pWFlags),
			chrPtrArgumentos(pchrPtrArgumentos),
			zOrdVenta(pzOrdVenta)

{
setFont(pQWParent->font());
IniciaVariables();
exec();
}

QClientePedido::~QClientePedido()
{

}
int QClientePedido::Aceptar()
{
  return QtClientePedido::Aceptar();
}
void QClientePedido::SlotRegistraDireccion()
{
  if(RegistrandoDireccion())
  {
      QtClientePedido::RegistraPersonales(1);
      QtClientePedido::Aceptar(2);
      QtClientePedido::HabilitaDesHabilitaAceptar();
      QtClientePedido::HabilitaDesHabilitaRegistraDireccion(false);
  }
}
void QClientePedido::SlotDireccionEnvio(int pintDireccion,
					int,
					int,
					const QPoint &)
{

 if(pintDireccion!=-1)
 {
 Direccion(pintDireccion);
 HabilitaAceptarEleccionDireccion();
 QtClientePedido::Aceptar(2);
 }

}
void QClientePedido::SlotCoberturaJTExpress()
{
 if(CoberturaJTExpress((const char *)QLECP->text()))
  SiHayCoberturaPaqueteria();
  else
  MensajeNoHayCobertura();
}
void QClientePedido::SlotAceptar()
{
   if(QtClientePedido::Aceptar()==2)
   PuntoEntregaDomicilioCliente();
   done(1); 
}
void QClientePedido::SlotRegistraPersonales()
{
int lintRegistro;
Cliente();
    if((lintRegistro=RegistrandoPersonales())==1)
    {
	QtClientePedido::RegistraPersonales(1);
	zSiscomQt3::Foco(QLECelular);
	QPBRegistraPersonales->setEnabled(false);
	HabilitaDesHabilitaAceptar();
    }
    else
    if(lintRegistro==2)
    {
    QtClientePedido::YaTengoAlCliente();
    QtClientePedido::VeSiFaltaAlgunDato();
    }
    else
    {
	LogSiscom("Se envio cancelar en los similares %d",lintRegistro);	
    }
}

void QClientePedido::SlotRegistraCelular()
{
   if(!ValidandoTelefono())
   {
   Orden()->Cliente()->Celular(FormaCelular());
   if(RegistrandoCelular())
   {
	QtClientePedido::RegistraCelular(1);
	QPBRegistraCelular->setEnabled(false);
	HabilitaDesHabilitaAceptar();
   }
  }
}
zDireccion *QClientePedido::DireccionEnvio()
{
 return zDirEnvio;
}
void QClientePedido::Direccion(int pintNDireccion)
{ 
zDirEnvio=Orden()->Cliente()->Direcciones()->Direccion(pintNDireccion);
}
void QClientePedido::IniciaVariables()
{
  	QtClientePedido::VerificandoCliente();
	QtClientePedido::IniciaVariables();
	QtClientePedido::ConectaSlots();
}
int QClientePedido::ValidandoTelefono()
{
char lchrArrMensajeNoIgual[256];
zSiscomElectronica lzSisElectronica(Orden()->Expendio(),"ValidaReCaptura");
if(!lzSisElectronica.ValidaReCaptura((const char *)QLECelular->text(),
				     (const char *)QLEReCelular->text()))
{
sprintf(lchrArrMensajeNoIgual,
	"El Numero (%s) No es igual a (%s)",
	(const char *)QLECelular->text(),
	(const char *)QLEReCelular->text());
  QMessageBox::information(this,"Aviso Sistema",lchrArrMensajeNoIgual);
  zSiscomQt3::Foco(QLECelular);
  return 1;
}
else
return 0;
/*
else
zSiscomQt3::Foco(QLECorreo);
*/
}

int QClientePedido::RegistrandoPersonales()
{
int lintRegistroCliente;
  if((lintRegistroCliente=RegistraCliente())==1)
  {
  return 1;
  }
  else
  if(lintRegistroCliente==2)
  {
    LogSiscom("-ddddd-");
     return BuscandoAElCliente();
  }
  else
  if(lintRegistroCliente==3)
  {
	zSiscomQt3::Foco(QLEAPaterno);
  }
  else
  {
    MuestraDatosComunicacion();
    MuestraDireccion(); 
    QtClientePedido::MuestraGenerales();
    ControlesClienteRegistrado();
    return 0;
  }
}
int QClientePedido::RegistrandoCelular()
{
  if(RegistraCelular())
  return 1;
  else
  return 0;
}

int QClientePedido::RegistrandoDireccion()
{
   QtClientePedido::DireccionCliente();
   SiscomRegistroLog2(Orden()->Cliente()->Direccion());
   if(RegistraDireccion())
   return 1;
   else
   return 0;
}
int QClientePedido::RegistraCliente()
{
zSiscomElectronica lzSisElectronica(Orden()->Expendio(),"RegistraClientePersona");
return lzSisElectronica.RegistraCliente(Orden()->Cliente(),&zClisSiscom);
}
int QClientePedido::RegistraCelular()
{
zSiscomElectronica lzSisElectronica(Orden()->Expendio(),"RegistraCelularAlumno");
 return lzSisElectronica.RegistraCelularAlumno(Orden()->Cliente());
}
int QClientePedido::RegistraDireccion()
{
zSiscomElectronica lzSisElectronica(Orden()->Expendio(),"RegistraDireccionAlumno");
return lzSisElectronica.RegistraDireccionAlumno(Orden()->Cliente());
}

const char *QClientePedido::IdTipoOrden()
{
	return "4";
}
int QClientePedido::MuestraClientesSimilares()
{
}

void QClientePedido::ObtenDireccionEscuela()
{
/*
zSiscomElectronica lzSisElectronica(Orden()->Expendio(),"DireccionEscuela");
zDirEscuela=lzSisElectronica.Escuela(zSisRegEscuela);
*/
}
zOrdenVenta *QClientePedido::Orden()
{
     return zOrdVenta;
}
int QClientePedido::BuscandoAElCliente()
{
int lintClientesSimilares;
   if((lintClientesSimilares=HayClientesSimilares())==1)
   {
     SiscomRegistroLog2(UnClienteEncontrado());
   Orden()->Cliente(UnClienteEncontrado());
   QtClientePedido::MuestraCliente();
   return 2;
   }
   else
   if(lintClientesSimilares==2)
   QtClientePedido::MuestraClientes(zClisSiscom);
   else
   return -1;
}
int QClientePedido::HayClientesSimilares()
{
int lintNClientes;
 if(zClisSiscom && (lintNClientes=zClisSiscom->NNodos())==1)
 return 1;
 else
 if(lintNClientes>1)
 return 2;
 else
 return 0;
}
zClienteSiscom *QClientePedido::UnClienteEncontrado()
{
  return (zClienteSiscom *)(*zClisSiscom)[0];
}
int QClientePedido::CoberturaJTExpress(const char *pchrPtrCP)
{
zOpsClientePedido lzOpsCliPedido(Orden()->Expendio(),"JTExpressCobertura");
zCobPaqueteria=lzOpsCliPedido.CoberturaJTExpress(pchrPtrCP);
return zCobPaqueteria->Cobertura();
}
void QClientePedido::SiHayCoberturaPaqueteria()
{
  QtClientePedido::Cobertura(zCobPaqueteria);
  QtClientePedido::MuestraCobertura();
  zSiscomQt3::Foco(QLECalle);
}

void QClientePedido::PuntoEntregaDomicilioCliente()
{
zPuntoEntrega *lzPEntrega;
 lzPEntrega=new zPuntoEntrega("",
 			  "",
			  Orden()->Cliente()->Direccion());
LogSiscom("\n Enviando al domicilio del cliente \n");
SiscomRegistroLog2(Orden()->Cliente()->Direccion());
Orden()->Pedido()->PuntoEntrega(lzPEntrega);
}
