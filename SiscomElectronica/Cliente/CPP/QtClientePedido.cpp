#include <IMP_ListaPuntosEntrega.h>
#include <IMP_ClientesRegistrados4.h>
#include <QtClientePedido.h>
#include <QCtrlEscuelasSE.h>

#include <qlineedit.h>
#include <qpushbutton.h>
#include <qtextedit.h>
#include <qmessagebox.h>
#include <qtable.h>


#include <zSiscomRegistros.h>
#include <zSiscomQt3.h>
#include <zClienteSiscom.h>
#include <zOrdenVenta.h>
#include <zDirecciones.h>


#include <zSiscomDesarrollo4.h>
#include <zTelefono.h>
#include <zConexionExpendio.h>
#include <zPedido.h>
#include <zDireccion.h>
#include <zPuntoEntrega.h>
#include <zCobertura.h>

#include <zSiscomRegistro.h>

QtClientePedido::QtClientePedido(zOrdenVenta *pzOrdenVenta,
				QWidget *pQWParent,
				 const char *pchrPtrName,
				 bool pbModal,
				 WFlags pWFlags):
				 ClientePedido(pQWParent,pchrPtrName,pbModal,pWFlags),
				 zOrdVenta(pzOrdenVenta),
				 intAceptar(0)
{


}

QtClientePedido::~QtClientePedido()
{

}
void QtClientePedido::IniciaVariables()
{
QCtrEscuelas->Servidor(Orden()->Expendio());
QCtrEscuelas->IniciaControl();
zSiscomQt3::Foco(QLENombre);
HabilitaDesHabilitaDireccion(false);
}
void QtClientePedido::ConectaSlots()
{
connect(QPBPuntoEntrega,SIGNAL(clicked()),SLOT(SlotPuntoEntrega()));
connect(QPBAceptar,SIGNAL(clicked()),SLOT(SlotAceptar()));
connect(QPBCancelar,SIGNAL(clicked()),SLOT(SlotCancelar()));
connect(QPBRegistraPersonales,SIGNAL(clicked()),SLOT(SlotRegistraPersonales()));
connect(QPBRegistraCelular,SIGNAL(clicked()),SLOT(SlotRegistraCelular()));
connect(QPBRegistraDireccion,SIGNAL(clicked()),SLOT(SlotRegistraDireccion()));
connect(QCtrEscuelas,
	SIGNAL(SignalSelecciono(zSiscomRegistro *)),
	SLOT(SlotEscuela(zSiscomRegistro *)));
connect(QLENombre,SIGNAL(returnPressed()),SLOT(SlotFocoAAPaterno()));
connect(QLEAPaterno,SIGNAL(returnPressed()),SLOT(SlotFocoAAMaterno()));
/*connect(QLEAMaterno,SIGNAL(returnPressed()),SLOT(SlotFocoARegistraPersonales())); */
connect(QLEAMaterno,SIGNAL(returnPressed()),SLOT(SlotFocoAEscuela()));
connect(QLECelular,SIGNAL(returnPressed()),SLOT(SlotFocoAReCelular()));
connect(QLEReCelular,SIGNAL(returnPressed()),SLOT(SlotFocoARegistraCelular()));
connect(QLECalle,SIGNAL(returnPressed()),SLOT(SlotFocoANumero()));
connect(QLENumero,SIGNAL(returnPressed()),SLOT(SlotFocoACalle1()));
connect(QLECalle1,SIGNAL(returnPressed()),SLOT(SlotFocoACalle2()));
connect(QLEDelegacion,SIGNAL(returnPressed()),SLOT(SlotFocoAColonia()));
connect(QLEColonia,SIGNAL(returnPressed()),SLOT(SlotFocoAEstado()));
connect(QLEEstado,SIGNAL(returnPressed()),SLOT(SlotFocoACP()));
/*
connect(QLECP,SIGNAL(returnPressed()),SLOT(SlotFocoAReferencias()));

*/
connect(QPBDireccionCliente,SIGNAL(clicked()),SLOT(SlotDireccionCliente()));
connect(QTDirecciones,
	SIGNAL(clicked(int,int,int,const QPoint &)),
	SLOT(SlotDireccionEnvio(int,int,int,const QPoint &)));
connect(QLECP,SIGNAL(returnPressed()),SLOT(SlotCoberturaJTExpress()));

//{ Slots Capturando ....
connect(QLENombre,
	SIGNAL(textChanged(const QString &)),
	SLOT(SlotCapturandoNombre(const QString &)));
connect(QLEAPaterno,
	SIGNAL(textChanged(const QString &)),
	SLOT(SlotCapturandoAPaterno(const QString &)));
connect(QLEAMaterno,
	SIGNAL(textChanged(const QString &)),
	SLOT(SlotCapturandoAMaterno(const QString &)));

connect(QLECelular,
	SIGNAL(textChanged(const QString &)),
	SLOT(SlotCapturandoCeluar(const QString &)));
connect(QLEReCelular,
	SIGNAL(textChanged(const QString &)),
	SLOT(SlotCapturandoReCelular(const QString &)));

connect(QLECalle,
	SIGNAL(textChanged(const QString &)),
	SLOT(SlotCapturandoCalle(const QString &)));

connect(QLENumero,
	SIGNAL(textChanged(const QString &)),
	SLOT(SlotCapturandoNumero(const QString &)));
connect(QLEDelegacion,
	SIGNAL(textChanged(const QString &)),
	SLOT(SlotCapturandoDelegacion(const QString &)));
connect(QLEColonia,
	SIGNAL(textChanged(const QString &)),
	SLOT(SlotCapturandoColonia(const QString &)));
connect(QLEEstado,
	SIGNAL(textChanged(const QString &)),
	SLOT(SlotCapturandoEstado(const QString &)));
connect(QLECP,
	SIGNAL(textChanged(const QString &)),
	SLOT(SlotCapturandoCP(const QString &)));

connect(QLECalle1,
	SIGNAL(textChanged(const QString &)),
	SLOT(SlotCapturandoCalle1(const QString &)));
connect(QLECalle2,
	SIGNAL(textChanged(const QString &)),
	SLOT(SlotCapturandoCalle2(const QString &)));

//}}
}
void QtClientePedido::SlotDireccionEnvio(int pintDireccion,
					 int,
					 int,
					 const QPoint &)
{
}
void QtClientePedido::SlotCapturandoCalle1(const QString &)
{
   HabilitaDesHabilitaRegistraDireccion();
}

void QtClientePedido::SlotCapturandoCalle2(const QString &)
{
   HabilitaDesHabilitaRegistraDireccion();
}
void QtClientePedido::SlotFocoACalle1()
{
	zSiscomQt3::Foco(QLECalle1);
}
void QtClientePedido::SlotFocoACalle2()
{
	zSiscomQt3::Foco(QLECalle2);
}
void QtClientePedido::SlotCoberturaJTExpress()
{

}
void QtClientePedido::SlotDireccionCliente()
{
Orden()->Pedido()->TipoEntrega("1");
QLECP->setEnabled(true); 
zSiscomQt3::Foco(QLECP);
}
void QtClientePedido::SlotPuntoEntrega()
{
QListaPuntosEntrega lQLstPuEntrega(Orden()->Expendio());
if(lQLstPuEntrega.Aceptar())
{
Orden()->Pedido()->PuntoEntrega(lQLstPuEntrega.PuntoEntrega());
Orden()->Pedido()->TipoEntrega("0");
Aceptar(1);
MuestraPuntoEntrega();
QPBAceptar->setEnabled(true);
zSiscomQt3::Foco(QPBAceptar);
}
}
void QtClientePedido::YaTengoAlCliente()
{
   SoloLecturaDatos(true);
}
void QtClientePedido::HabilitaDesHabilitaDatos(bool pbEstado)
{
 QCtrEscuelas->setEnabled(pbEstado);
 QLENombre->setEnabled(pbEstado); 
 QLEAPaterno->setEnabled(pbEstado); 
 QLEAMaterno->setEnabled(pbEstado); 
 QLECelular->setEnabled(pbEstado);
 QLEReCelular->setEnabled(pbEstado);
 QLEEscuela->setEnabled(pbEstado);
 QLENumCliente->setEnabled(pbEstado);
}

void QtClientePedido::SoloLecturaDatos(bool pbEstado)
{
 QCtrEscuelas->setReadOnly(pbEstado);
 QLENombre->setReadOnly(pbEstado); 
 QLEAPaterno->setReadOnly(pbEstado); 
 QLEAMaterno->setReadOnly(pbEstado); 
 QLECelular->setReadOnly(pbEstado);
 QLEReCelular->setReadOnly(pbEstado);
 QLEEscuela->setReadOnly(pbEstado);
 QLENumCliente->setReadOnly(pbEstado);
}
int QtClientePedido::YaEstaElCliente()
{
   if(Orden() && 
      Orden()->Cliente())
    return 1;
   else
   return 0;
}
int QtClientePedido::VerificandoCliente()
{
  if(YaEstaElCliente())
  {
     MostrandoCliente(); 
     SoloLecturaDatos(true);
     return 1;
  }
  else
  return 0;

}
void QtClientePedido::MostrandoCliente()
{
 QLENombre->setText(Orden()->Cliente()->Nombre()); 
 QLEAPaterno->setText(Orden()->Cliente()->APaterno()); 
 QLEAMaterno->setText(Orden()->Cliente()->AMaterno()); 
 QLECelular->setText(Orden()->Cliente()->Celular()->Telefono());
 QLENumCliente->setText(Orden()->Cliente()->IdPersona());
 QLEEscuela->setText(Orden()->Cliente()->Escuela());
}
zOrdenVenta *QtClientePedido::Orden()
{
    return zOrdVenta;
}
void QtClientePedido::MuestraPuntoEntrega()
{
 QLECalle->setText(Orden()->Pedido()->Calle());  
}

void QtClientePedido::SlotFocoAEscuela()
{
   if(!zSiscomQt3::TextoValido(QLEAPaterno) &&
      !zSiscomQt3::TextoValido(QLEAMaterno))
   zSiscomQt3::Foco(QPBRegistraPersonales);
   else
   if(zSiscomQt3::TextoValido(QLENombre)     &&
      !zSiscomQt3::TextoValido(QLEAPaterno) &&
      !zSiscomQt3::TextoValido(QLEAMaterno))
    zSiscomQt3::Foco(QPBRegistraPersonales);
   else
   {
   FormandoCliente();
   zSiscomQt3::Foco(QCtrEscuelas);
   }
}
void QtClientePedido::SlotCapturandoCelular(const QString &)
{
  HabilitaDesHabilitaRegistraCelular();
}
void QtClientePedido::SlotCapturandoReCelular(const QString &)
{
  HabilitaDesHabilitaRegistraCelular();
}

void QtClientePedido::SlotCapturandoCalle(const QString &)
{
   HabilitaDesHabilitaRegistraDireccion();
}

void QtClientePedido::SlotCapturandoNumero(const QString &)
{
   HabilitaDesHabilitaRegistraDireccion();
}
void QtClientePedido::SlotCapturandoDelegacion(const QString &)
{
   HabilitaDesHabilitaRegistraDireccion();
}
void QtClientePedido::SlotCapturandoColonia(const QString &)
{
   HabilitaDesHabilitaRegistraDireccion();
}
void QtClientePedido::SlotCapturandoEstado(const QString &)
{
   HabilitaDesHabilitaRegistraDireccion();
}
void QtClientePedido::SlotCapturandoCP(const QString &)
{
   HabilitaDesHabilitaRegistraDireccion();
}
void QtClientePedido::SlotCapturandoNombre(const QString &)
{
   HabilitaDesHabilitaRegistraPersonales(); 
}

void QtClientePedido::SlotCapturandoAPaterno(const QString &)
{
   HabilitaDesHabilitaRegistraPersonales(); 
}
void QtClientePedido::SlotCapturandoAMaterno(const QString &)
{
   HabilitaDesHabilitaRegistraPersonales(); 
}


void QtClientePedido::SlotFocoACalle()
{
  zSiscomQt3::Foco(QLECalle);
}
void QtClientePedido::SlotFocoANumero()
{
	zSiscomQt3::Foco(QLENumero);
}
void QtClientePedido::SlotFocoADelegacion()
{
	zSiscomQt3::Foco(QLEDelegacion);
}
void QtClientePedido::SlotFocoAColonia()
{
	zSiscomQt3::Foco(QLEColonia);
}
void QtClientePedido::SlotFocoAEstado()
{
	zSiscomQt3::Foco(QLEEstado);
}
void QtClientePedido::SlotFocoACP()
{
	zSiscomQt3::Foco(QLECP);
}
void QtClientePedido::SlotFocoAReferencias()
{
	zSiscomQt3::Foco(QTEReferencias);
}

void QtClientePedido::SlotFocoACelular()
{
  zSiscomQt3::Foco(QLECelular);
}
void QtClientePedido::SlotFocoAReCelular()
{
  zSiscomQt3::Foco(QLEReCelular);
}
void QtClientePedido::SlotFocoARegistraCelular()
{
 zSiscomQt3::Foco(QPBRegistraCelular);
}
void QtClientePedido::SlotAceptar()
{
}
void QtClientePedido::SlotCancelar()
{
   intAceptar=0;
   done(intAceptar);
}

void QtClientePedido::SlotFocoAAPaterno()
{
 zSiscomQt3::Foco(QLEAPaterno);
}
void QtClientePedido::SlotFocoAAMaterno()
{
  zSiscomQt3::Foco(QLEAMaterno);
}
void QtClientePedido::SlotFocoARegistraPersonales()
{
  zSiscomQt3::Foco(QPBRegistraPersonales);
}

void QtClientePedido::SlotEscuela(zSiscomRegistro *pzSisRegEscuela)
{
Orden()->Cliente()->Escuela(pzSisRegEscuela);
QPBRegistraPersonales->setEnabled(intSePuedeRegistrarPersonales&&pzSisRegEscuela);
zSiscomQt3::Foco(QPBRegistraPersonales);
//ObtenDireccionEscuela();
     
}

void QtClientePedido::SlotRegistraPersonales()
{

}
void QtClientePedido::SlotRegistraCelular()
{
}
void QtClientePedido::SlotRegistraDireccion()
{
}

void QtClientePedido::HabilitaDesHabilitaRegistraCelular()
{
int lintRegistraCelular=zSiscomQt3::TextoValido(QLECelular) &&
                        zSiscomQt3::TextoValido(QLEReCelular);
QPBRegistraCelular->setEnabled(lintRegistraCelular);
}

void QtClientePedido::HabilitaDesHabilitaRegistraDireccion()
{
int lintRegistraDireccion=zSiscomQt3::TextoValido(QLECalle) 		&&
			  zSiscomQt3::TextoValido(QLENumero) 		&&
			  zSiscomQt3::TextoValido(QLEDelegacion) 	&&
			  zSiscomQt3::TextoValido(QLEEstado) 		&&
			  zSiscomQt3::TextoValido(QLECP)     		&&
			  zSiscomQt3::TextoValido(QLECalle1) 		&&
			  zSiscomQt3::TextoValido(QLECalle2);
QPBRegistraDireccion->setEnabled(lintRegistraDireccion);
}
void QtClientePedido::HabilitaDesHabilitaAceptar()
{
int lintAceptar=intRegistroPersonales &&
                intRegistroCelular &&
		intRegistroDireccion;
QPBAceptar->setEnabled(lintAceptar);
}
void QtClientePedido::HabilitaAceptarEleccionDireccion()
{
   QPBAceptar->setEnabled(true);
   zSiscomQt3::Foco(QPBAceptar);
}

void QtClientePedido::HabilitaDesHabilitaRegistraPersonales()
{
  intSePuedeRegistrarPersonales=zSiscomQt3::TextoValido(QLENombre) &&
		          zSiscomQt3::TextoValido(QLEAPaterno) &&
			  zSiscomQt3::TextoValido(QLEAMaterno) ;
if(intSePuedeRegistrarPersonales)
{
QPBRegistraPersonales->setText("&Registra Datos Personales");
QPBRegistraPersonales->setEnabled(false);
QCtrEscuelas->setEnabled(intSePuedeRegistrarPersonales);
}
else
if(zSiscomQt3::TextoValido(QLENombre))
{
 QPBRegistraPersonales->setText("Busca Alumno Po&r Nombre");
 QPBRegistraPersonales->setEnabled(true);
}
}

void QtClientePedido::HabilitaDesHabilitaDireccion(bool pbEstado)
{
QLECalle->setEnabled(pbEstado);
QLENumero->setEnabled(pbEstado);
QLEDelegacion->setEnabled(pbEstado);
QLEColonia->setEnabled(pbEstado);
QLEEstado->setEnabled(pbEstado);
QLECP->setEnabled(pbEstado);
QLECalle1->setEnabled(pbEstado);
QLECalle2->setEnabled(pbEstado);
QTEReferencias->setEnabled(pbEstado);
}

void QtClientePedido::HabilitaDesHabilitaRegistraDireccion(bool pbModal)
{
  QPBRegistraDireccion->setEnabled(pbModal); 
}

void QtClientePedido::MuestraDireccion()
{
   if(Orden()->Cliente()->Direccion())
   {
   QLECalle->setText(Orden()->Cliente()->Direccion()->Calle());
   QLENumero->setText(Orden()->Cliente()->Direccion()->Numero());
   QLEDelegacion->setText(Orden()->Cliente()->Direccion()->Delegacion());
   QLEColonia->setText(Orden()->Cliente()->Direccion()->Colonia());
   QLEEstado->setText(Orden()->Cliente()->Direccion()->Estado());
   QLECP->setText(Orden()->Cliente()->Direccion()->CP());
   QTEReferencias->setText(Orden()->Cliente()->Direccion()->Referencias());
   }
}
void QtClientePedido::MuestraDireccion(zDireccion *pzDirEscuela)
{
   if(pzDirEscuela)
   {
   QLECalle->setText(pzDirEscuela->Calle());
   QLENumero->setText(pzDirEscuela->Numero());
   QLEDelegacion->setText(pzDirEscuela->Delegacion());
   QLEColonia->setText(pzDirEscuela->Colonia());
   QLEEstado->setText(pzDirEscuela->Estado());
   QLECP->setText(pzDirEscuela->CP());
   QTEReferencias->setText(pzDirEscuela->Referencias());
   }
   else
   {	
   	FocoADondeFalta();
	QPBAceptar->setEnabled(false);
   }
}

void QtClientePedido::FocoADondeFalta()
{
    if(!Orden()->Cliente()->Celular())
    zSiscomQt3::Foco(QLECelular);
    else
    if(!Orden()->Cliente()->Direccion())
    zSiscomQt3::Foco(QLECalle);
}
void QtClientePedido::MuestraDatosComunicacion()
{
   if(Orden()->Cliente()->Celular())
   {
   QLECelular->setText(Orden()->Cliente()->Celular()->Telefono());
   intRegistroCelular=zSiscomQt3::TextoValido(QLECelular);
   }
   else
	QPBAceptar->setEnabled(false);
}
void QtClientePedido::ControlesClienteRegistrado()
{
////////QPBRegistraPersonales->setEnabled(false);
QPBRegistraCelular->setEnabled(false);
//QPBRegistraDireccion->setEnabled(false);
QPBAceptar->setEnabled(Orden()->Cliente()->Celular() &&
		       Orden()->Cliente()->Direccion()); 
zSiscomQt3::Foco(QPBAceptar);
}
void QtClientePedido::RegistraCelular(int pintRegistraCelular)
{
    intRegistroCelular=pintRegistraCelular;
}
void QtClientePedido::RegistraPersonales(int pintRegistraPersonales)
{
	intRegistroPersonales=pintRegistraPersonales;
}
void QtClientePedido::Cliente()
{
 if(!Orden()->Cliente())
   Orden()->Cliente(new zClienteSiscom("",
   					zSiscomQt3::Texto(QLENombre),
   					zSiscomQt3::Texto(QLEAPaterno),
   					zSiscomQt3::Texto(QLEAMaterno)));
}

void QtClientePedido::MuestraGenerales()
{
    QLENumCliente->setText(Orden()->Cliente()->IdPersona());
    QLENombre->setText(Orden()->Cliente()->Nombre());
    QLEAPaterno->setText(Orden()->Cliente()->APaterno());
    QLEAMaterno->setText(Orden()->Cliente()->AMaterno());
}
void QtClientePedido::MuestraEscuela()
{
  QLEEscuela->setText(Orden()->Cliente()->Escuela());
}
void QtClientePedido::MuestraCliente()
{
	MuestraGenerales();
	MuestraDatosComunicacion();
	MuestraEscuela();
	if(Orden()->Cliente()->Direcciones())
	MuestraDirecciones();
}
const QString QtClientePedido::ColumnaDireccion(zDireccion *pzDireccion)
{

return QString(pzDireccion->Calle()) 	+
       " "				+
       pzDireccion->Numero()		+
       "\n"				+
       pzDireccion->Referencias();
	  

}
void QtClientePedido::MuestraDirecciones()
{
zDireccion *lzDireccion;
int lintContador=0;
  QTDirecciones->setNumRows(Orden()->Cliente()->Direcciones()->NNodos());
  for(lzDireccion=(zDireccion *)Orden()->Cliente()->Direcciones()->Primer();
      lzDireccion;
      lzDireccion=(zDireccion *)Orden()->Cliente()->Direcciones()->Siguiente(),
      lintContador++)
    QTDirecciones->setText(lintContador,0,ColumnaDireccion(lzDireccion));
zSiscomQt3::AjustaFilasTabla(QTDirecciones);
zSiscomQt3::AjustaColumnasTabla(QTDirecciones);
}
void QtClientePedido::MuestraClientes(zClientesSiscom *pzClisSiscom)
{
QClientesRegistrados4 lQCRegistrados(pzClisSiscom);
if(lQCRegistrados.Aceptar())
{
   Orden()->Cliente(lQCRegistrados.Cliente());
   MuestraCliente();
   SoloLecturaDatos(true);
}
}
void QtClientePedido::VeSiFaltaAlgunDato()
{
  VeSiFaltaCelular();
}
void QtClientePedido::VeSiFaltaCelular()
{
  if(!Orden()->Cliente()->Celular() || !Orden()->Cliente()->Celular()->Telefono())
  {
        QLECelular->setReadOnly(false);
	QLEReCelular->setReadOnly(false);
	zSiscomQt3::Foco(QLECelular);
  }
}
zTelefono *QtClientePedido::FormaCelular()
{
  return new zTelefono("",(const char *)QLECelular->text());
}
void QtClientePedido::FormandoCliente()
{
   FormaCliente();
   HabilitaDesHabilitaNombre(false);

}
void QtClientePedido::FormaCliente()
{
 Orden()->Cliente(new zClienteSiscom("",
 				    zSiscomQt3::Texto(QLENombre),
				    zSiscomQt3::Texto(QLEAPaterno),
				    zSiscomQt3::Texto(QLEAMaterno)));
}
void QtClientePedido::HabilitaDesHabilitaNombre(bool pbEstado)
{
  QLENombre->setEnabled(pbEstado);
  QLEAPaterno->setEnabled(pbEstado);
  QLEAMaterno->setEnabled(pbEstado);
}
void QtClientePedido::Aceptar(int pintAceptar)
{
   intAceptar=pintAceptar;
}
int QtClientePedido::Aceptar()
{
   return intAceptar;
}
void QtClientePedido::MuestraCobertura()
{
 QLECalle->setEnabled(true);
 QLENumero->setEnabled(true);
 QLEDelegacion->setEnabled(true);
 QLEDelegacion->setReadOnly(true);
 QLEEstado->setEnabled(true);
 QLEEstado->setReadOnly(true);
 QLECP->setEnabled(true);
 QLECP->setReadOnly(true);
 QTEReferencias->setEnabled(true);
 QLEDelegacion->setText(Cobertura()->Municipio());
 QLECP->setText(Cobertura()->Cp());
 QLEEstado->setText(Cobertura()->Estado());
 QLECalle1->setEnabled(true);
 QLECalle2->setEnabled(true);
 QLETarifa->setText(Cobertura()->Tarifa());
 QLEDiasEntrega->setText(Cobertura()->Dias());
}
void QtClientePedido::Cobertura(zCobertura *pzCobertura)
{
	zCoEnvio=pzCobertura;
}
zCobertura *QtClientePedido::Cobertura()
{
	return zCoEnvio;
}
void QtClientePedido::MostrandoEntreCalles()
{
QString lQStrReferencias=QString("<b>Entre Calles</b><br>")	+
			 QLECalle1->text()		+
			 " y "				+
			 QLECalle2->text();
QTEReferencias->setText(lQStrReferencias);	 
}

void QtClientePedido::MensajeNoHayCobertura()
{
   QMessageBox::information(this,
   			    "Aviso Sistema",
			    QString("El Codigo postal  ") +
			    QLECP->text()		  +
			    " "
			    "NO Tiene Cobertura");
}

zDireccion *QtClientePedido::FormaDireccion()
{
zDireccion *lzDirDato;
const char *lchrPtrReferencias;
 lzDirDato=new zDireccion(Orden()->Cliente()->IdPersona(),
 			zSiscomQt3::Texto(QLECalle),
			zSiscomQt3::Texto(QLENumero),
			"",
			zSiscomQt3::Texto(QLEDelegacion),
			"",
			zSiscomQt3::Texto(QLEEstado),
			(const char *)QLECP->text());
 lchrPtrReferencias=strdup((const char *)QTEReferencias->text());
 lzDirDato->Referencias(lchrPtrReferencias);
 lzDirDato->Calle1(zSiscomQt3::Texto(QLECalle1));
 lzDirDato->Calle2(zSiscomQt3::Texto(QLECalle2));
 SiscomRegistroLog2(lzDirDato);
 return lzDirDato;
}
void QtClientePedido::DireccionCliente()
{
  Orden()->Cliente()->Direccion(FormaDireccion());
}

void QtClientePedido::reject()
{

}
