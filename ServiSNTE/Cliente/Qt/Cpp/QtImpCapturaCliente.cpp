#include <QtImpCapturaCliente.h>

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
#include <zPersona.h> 
#include <zCliente.h>
#include <qlineedit.h> 
#include <qcheckbox.h> 
#include <qpushbutton.h>
#include <qmessagebox.h>
#include <qtable.h>


QtImpCapturaCliente::QtImpCapturaCliente(
			zSiscomConexion *pzSisConexion,
			zSiscomRegistro *pzSisRegTipoVenta,
			QWidget *pQWParent,
			const char *pchrPtrName,
			bool pbModal,
			WFlags pWFlags):
		CapturaCliente(pQWParent,pchrPtrName,pbModal,pWFlags),
		zSisConexion(pzSisConexion),
		zPerCliente(0),
		zSisRegTipoVenta(pzSisRegTipoVenta),
		QTCompras(0),
		intAceptar(0),
		intClienteRegistrado(0)
{
    ConectaSlots();
    zSiscomQt3::Foco(QLEClaveCliente);
    exec();
}

void QtImpCapturaCliente::Conexion(zSiscomConexion *pzSisConexion)
{
	zSisConexion=pzSisConexion;
}

void QtImpCapturaCliente::ConectaSlots()
{
	connect(QPBCrear,
		SIGNAL(clicked()),
		SLOT(SlotCrear()));
	connect(QPBAceptar,
		SIGNAL(clicked()),
		SLOT(SlotAceptar()));
	connect(QPBCancelar,
		SIGNAL(clicked()),
		SLOT(SlotCancelar()));
	connect(QLEClaveCliente,
		SIGNAL(returnPressed()),
		SLOT(SlotFocoARFC()));
	connect(QLERFC,
		SIGNAL(returnPressed()),
		SLOT(SlotFocoAApellidoPaterno()));
	connect(QLEApellidoPaterno,
		SIGNAL(returnPressed()),
		SLOT(SlotFocoAApellidoMaterno()));
	connect(QLEApellidoMaterno,
		SIGNAL(returnPressed()),
		SLOT(SlotFocoANombres()));
	connect(QLENombres,
		SIGNAL(returnPressed()),
		SLOT(SlotFocoACrear()));
	ConectaEditValidacionAgregar(QLERFC); 
	ConectaEditValidacionAgregar(QLEApellidoPaterno);
	ConectaEditValidacionAgregar(QLEApellidoMaterno);
	ConectaEditValidacionAgregar(QLENombres);
}
void QtImpCapturaCliente::SlotCambioTexto(const QString &)
{
   QPBCrear->setEnabled(DatosMinimosNombre());
}
void QtImpCapturaCliente::SlotFocoARFC()
{
  zSiscomQt3::Foco(QLERFC);
}
void QtImpCapturaCliente::SlotFocoAApellidoPaterno()
{
  ConsultandoCliente();
}
void QtImpCapturaCliente::SlotFocoAApellidoMaterno()
{
  zSiscomQt3::Foco(QLEApellidoMaterno);
}
void QtImpCapturaCliente::SlotFocoANombres()
{
  zSiscomQt3::Foco(QLENombres);
}
void QtImpCapturaCliente::SlotFocoACrear()
{
  zSiscomQt3::Foco(QPBCrear);
}

void QtImpCapturaCliente::SlotCrear()
{
char *lchrPtrRegreso;
int lintRegresoRegistro;
	zPerCliente=FormaCliente();
	if((lintRegresoRegistro=RegistraCliente(&lchrPtrRegreso))==1)
	{
		/* Viernes 17 de Junio 2016 
		 * Se integra la validacion del cliente 
		 * registrado 
		 */
		ValidaRFCClienteRegistrado();
		MuestraCliente();
		CondicionesClienteRegistrado();
	}
	if(lintRegresoRegistro==2)
	{
		CondicionesClienteNuevo();		

	}
}
void QtImpCapturaCliente::SlotAceptar()
{
	intAceptar=1;
	done(1);
}
void QtImpCapturaCliente::SlotCancelar()
{
	intAceptar=0;
	done(1);
}
void QtImpCapturaCliente::reject()
{

}
zCliente *QtImpCapturaCliente::FormaCliente()
{
  return new zCliente(0,
		      zSiscomQt3::Texto(QLENombres),
		      zSiscomQt3::Texto(QLEApellidoPaterno),
		      zSiscomQt3::Texto(QLEApellidoMaterno),
		      zSiscomQt3::Texto(QLERFC));


}
zCliente *QtImpCapturaCliente::Cliente()
{ 
   return zPerCliente;
}
int QtImpCapturaCliente::Aceptar()
{
  return intAceptar;
}
void QtImpCapturaCliente::ReCapturaAlgunDato()
{
	zSiscomQt3::Foco(QLERFC);
	 exec();
}

int QtImpCapturaCliente::RegistraCliente(char **pchrPtrMensaje)
{
zOperacionesServiSNTE lzOpServiSNTE(zSisConexion,"RegistraCliente");
return lzOpServiSNTE.RegistraCliente(zPerCliente,pchrPtrMensaje);
}

void QtImpCapturaCliente::ConsultaCliente()
{
zOperacionesServiSNTE lzOpServiSNTE(zSisConexion,"ConsultaClienteCompras");

if((zPerCliente=lzOpServiSNTE.ValidaRfcParaVenta(zSiscomQt3::Texto(QLERFC),
						     (const char *)(*zSisRegTipoVenta)["idtipoventa"])))
{
 MuestraCliente();
 SePuedeVenderOtraVez(zPerCliente);
}
else
{
  zSiscomQt3::Foco(QLEApellidoPaterno);
}
}
void QtImpCapturaCliente::ConsultandoCliente()
{
 if(EsVentaCredito() &&
    LineEditValido(QLERFC))
 {
  if(EstaRFCRegistradoBaseDatos())
  {
    HabilitaDesHabilitaDatosPersonales(true);
    ConsultaCliente();
  }
  else
    HabilitaDesHabilitaDatosPersonales(false);
 }
 else if(EsVentaCredito()==0)
 {
    HabilitaDesHabilitaDatosPersonales(true);
    zSiscomQt3::Foco(QLEApellidoPaterno);
 }
}
void QtImpCapturaCliente::MuestraCliente()
{
  QLEApellidoPaterno->setText((const char *)(*zPerCliente)["APaterno"]);
  QLEApellidoMaterno->setText((const char *)(*zPerCliente)["AMaterno"]);
  QLENombres->setText((const char *)(*zPerCliente)["Nombre"]);
  QLERFC->setText(zPerCliente->RFC());
  QLEApellidoPaterno->setReadOnly(false);
  QLEApellidoMaterno->setReadOnly(false);
  QLENombres->setReadOnly(false);
}
int QtImpCapturaCliente::ClienteRegistrado()
{
  return intClienteRegistrado;
}

void QtImpCapturaCliente::SePuedeVenderOtraVez(zSiscomRegistro *pzSisRegCliente)
{
  if(pzSisRegCliente->CampoInt("SePuedeVender")==1)
  {
    QPBCrear->setEnabled(false);
    QPBAceptar->setEnabled(true);
    zSiscomQt3::Foco(QPBAceptar);
  }
  else
  {
	QPBAceptar->setEnabled(false);
	QPBCrear->setEnabled(false);
	MuestraComprasCliente(pzSisRegCliente);
  }
 intClienteRegistrado=1; 
}

void QtImpCapturaCliente::MuestraComprasCliente(zSiscomRegistro *pzSisRegCliente)
{
zSiscomRegistros *lzSisRegsCompras=pzSisRegCliente->AsociadosDelCampo("Compras");
SiscomRegistrosLog(lzSisRegsCompras);
/*
showExtension( true );
setOrientation(Vertical);
*/
if(lzSisRegsCompras)
{
const char *lchrPtrCampos[]={(char *)"fecha",
			(char *)"pagoquincenal",
			(char *)"pagototal",
			(char *)"plazo",
			(char *)"financiadora",
			(char *)0
			};
    QTCompras = new QTable(lzSisRegsCompras->NNodos(),5,0);
    zSiscomQt3::LlenaTabla(lchrPtrCampos,lzSisRegsCompras,QTCompras);
    setExtension( QTCompras );
    showExtension(true);
    setOrientation( Horizontal);
}
}

void QtImpCapturaCliente::ConectaEditValidacionAgregar(QLineEdit *pQLETexto)
{
connect(pQLETexto,
        SIGNAL(textChanged(const QString &)),
	SLOT(SlotCambioTexto(const QString &)));
}
int QtImpCapturaCliente::DatosMinimosNombre()
{
 return /*  Queretaro 29 de Febrero del 2016
  	 * Se habia definido el RFC, como valor
	 * valido y central para el seguimiento 
	 * del cliente, pero en la sesion de trabajo
	 * del dia de hoy con la Gente del ServiSNTE 
	 * se llego a la definicion de que el RFC 
	 * es solo importante en la venta a credito ....
	 * Para el caso de la venta por apartado y
	 * de contado, la gente no acostumbra dejar 
	 * estos datos 
 	 *LineEditValido(QLERFC) && 
 	 *
	 */
        LineEditValido(QLEApellidoPaterno) &&
	LineEditValido(QLEApellidoMaterno) &&
	LineEditValido(QLENombres) ;
}
int QtImpCapturaCliente::LineEditValido(QLineEdit *pQLETexto)
{
   return !pQLETexto->text().isNull() &&
          !pQLETexto->text().isEmpty() ;
}
void QtImpCapturaCliente::CondicionesClienteRegistrado()
{
		intAceptar=1;
		QPBAceptar->setEnabled(true);
		QPBCrear->setEnabled(false);
		zSiscomQt3::Foco(QPBAceptar);
		intClienteRegistrado=1;
}

void QtImpCapturaCliente::CondicionesClienteNuevo()
{
		intAceptar=1;
		QPBAceptar->setEnabled(true);
		QPBCrear->setEnabled(false);
		zSiscomQt3::Foco(QPBAceptar);
}
int QtImpCapturaCliente::ValidaRFCClienteRegistrado()
{
    if(zSisRegTipoVenta->CampoInt("idtipoventa")==2 &&
       !zPerCliente->RFC() &&
       !QLERFC->text().isNull())
    {
	ActualizaRFCCliente();
	zPerCliente->RFC((const char *)QLERFC->text());
    }
}
void QtImpCapturaCliente::ActualizaRFCCliente()
{
zOperacionesServiSNTE lzOpServiSNTE(zSisConexion,"ActualizaRFC");
lzOpServiSNTE.ActualizaRFC(zPerCliente->Id(),zSiscomQt3::Texto(QLERFC));
}
int QtImpCapturaCliente::RFCRegistradoBaseDatos()
{
zOperacionesServiSNTE lzOpServiSNTE(zSisConexion,"RFCRegistradoBaseDatos");
return lzOpServiSNTE.RFCRegistradoBaseDatos(zSiscomQt3::Texto(QLERFC));
}
int QtImpCapturaCliente::EstaRFCRegistradoBaseDatos()
{
   if(RFCRegistradoBaseDatos())
   {
	QMessageBox::information(this,"Aviso Sistema","RFC Registrado");	
	return 1;
   }
    else
    {
       QMessageBox::information(this,"Aviso Sistema","RFC NO REGISTRADO, NO SE PUEDE OTORGAR CREDITO");
       return 0;
    }

}
void QtImpCapturaCliente::HabilitaDesHabilitaDatosPersonales(bool pbHabilita)
{
  QLEApellidoPaterno->setEnabled(pbHabilita);
  QLEApellidoMaterno->setEnabled(pbHabilita);
  QLENombres->setEnabled(pbHabilita);
}
int QtImpCapturaCliente::EsVentaCredito()
{
   // return zSisRegTipoVenta->CampoInt("idtipoventa")==2;
    if(zSisRegTipoVenta->CampoInt("idtipoventa")==2)
    return 1;
    else
    return 0;
}
