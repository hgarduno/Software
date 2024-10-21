#include <IMP_RegistroApartado.h>
#include <IMP_ClientesRegistrados4.h>
#include <QCtrlFechaHora.h>

#include <zSiscomElectronica.h>

#include <zClienteSiscom.h>
#include <zPersona.h>
#include <zTelefono.h>
#include <zCorreo.h>
#include <zApartado.h>

#include <zSiscomDesarrollo4.h>
#include <zSiscomRegistro.h>
#include <zSiscomQt3.h>

#include <qpushbutton.h>
#include <qlineedit.h>
#include <qmessagebox.h>
QRegistroApartado::QRegistroApartado(QWidget *pQWParent,       
				    const char *pchrPtrName,
				    bool pbModal,
				    WFlags pWFlags):	      
				RegistroApartado(pQWParent,pchrPtrName,pbModal,pWFlags),
				zSisConexion((zSiscomConexion *)gzSiscomConexion)

{
IniciaVariables();
ConectaSlots();
}

QRegistroApartado::~QRegistroApartado()
{

}

void QRegistroApartado::ConectaSlots()
{

connect(QPBAceptar,SIGNAL(clicked()),SLOT(SlotAceptar()));
connect(QPBCancelar,SIGNAL(clicked()),SLOT(SlotCancelar()));
connect(QPBRegistraPersonales,SIGNAL(clicked()),SLOT(SlotRegistraPersonales()));
connect(QPBRegistraCelular,SIGNAL(clicked()),SLOT(SlotRegistraCelular()));
connect(QPBRegistraCorreo,SIGNAL(clicked()),SLOT(SlotRegistraCorreo()));
connect(QLENombre,SIGNAL(returnPressed()),SLOT(SlotFocoAAPaterno()));
connect(QLEAPaterno,SIGNAL(returnPressed()),SLOT(SlotFocoAAMaterno()));
connect(QLEAMaterno,SIGNAL(returnPressed()),SLOT(SlotFocoARegistraPersonales()));
connect(QLECelular,SIGNAL(returnPressed()),SLOT(SlotFocoAReCelular()));
connect(QLEReCelular,SIGNAL(returnPressed()),SLOT(SlotFocoARegistraCelular()));
connect(QLECorreo,SIGNAL(returnPressed()),SLOT(SlotFocoAReCorreo()));
connect(QLEReCorreo,SIGNAL(returnPressed()),SLOT(SlotFocoARegistraCorreo()));
connect(QLEACuenta,SIGNAL(returnPressed()),SLOT(SlotFocoAFechaEntrega()));
connect(QCtrFechaEntrega,SIGNAL(Signal_EnterMinuto()),SLOT(SlotFocoAObservaciones()));

connect(QLECelular,SIGNAL(textChanged(const QString &)),SLOT(SlotCapturandoCelular(const QString &)));
connect(QLEReCelular,SIGNAL(textChanged(const QString &)),SLOT(SlotCapturandoCelular(const QString &)));
connect(QLECorreo,SIGNAL(textChanged(const QString &)),SLOT(SlotCapturandoCorreo(const QString &)));
connect(QLEReCorreo,SIGNAL(textChanged(const QString &)),SLOT(SlotCapturandoCorreo(const QString &)));
connect(QLEACuenta,SIGNAL(textChanged(const QString &)),SLOT(SlotCapturandoACuenta(const QString &)));
connect(QPBCancelar,SIGNAL(clicked()),SLOT(SlotCancelar()));
}
void QRegistroApartado::SlotCancelar()
{
   emit SignalCancelar();
   done(1);
}
void QRegistroApartado::SlotCapturandoACuenta(const QString &)
{
  HabilitandoAceptar();
}
void QRegistroApartado::SlotCapturandoCorreo(const QString &pQStrTexto)
{
  HabilitaDesHabilitaRegistraCorreo();
}
void QRegistroApartado::SlotCapturandoCelular(const QString &pQStrTexto)
{
   HabilitaDesHabilitaRegistraCelular();
}
void QRegistroApartado::SlotFocoAObservaciones()
{
  zSiscomQt3::Foco(QTEObservaciones);
}
void QRegistroApartado::SlotFocoAFechaEntrega()
{
   zSiscomQt3::Foco(QCtrFechaEntrega);
}
void QRegistroApartado::SlotFocoACuenta()
{
  zSiscomQt3::Foco(QLEACuenta);
}

void QRegistroApartado::SlotFocoARegistraCorreo()
{
    if(SeCapturoCorreo())
    ValidandoCorreo(); 
    else
    SlotFocoACuenta();
}
void QRegistroApartado::SlotFocoARegistraPersonales()
{
  zSiscomQt3::Foco(QPBRegistraPersonales);
}
void QRegistroApartado::SlotRegistraPersonales()
{
int lintRegistroPersonales;
    if((lintRegistroPersonales=RegistrandoPersonales())==1)
    ControlesDespuesRegistrarPersonales();
    else
    if(lintRegistroPersonales==2)
    	ConsultandoSimilares();
    else
    {
	MuestraDatosComunicacion();
	zSiscomQt3::Foco(QLEACuenta);
	QPBRegistraPersonales->setEnabled(false);
    }
}
void QRegistroApartado::SlotRegistraCelular()
{
   if(RegistrandoCelular())
   {
	zSiscomQt3::Foco(QLECorreo);
	QPBRegistraCelular->setEnabled(false);
	   HabilitandoAceptar();

   }
}
void QRegistroApartado::SlotRegistraCorreo()
{
   if(RegistrandoCorreo())
   {
     QPBRegistraCorreo->setEnabled(false);
     zSiscomQt3::Foco(QLEACuenta);
     HabilitandoAceptar();
   }
   else
   zSiscomQt3::Foco(QLECorreo);
}
void QRegistroApartado::SlotFocoAAPaterno()
{
 zSiscomQt3::Foco(QLEAPaterno);
}
void QRegistroApartado::SlotFocoAAMaterno()
{
  zSiscomQt3::Foco(QLEAMaterno);
}
void QRegistroApartado::SlotFocoAReCorreo()
{
   zSiscomQt3::Foco(QLEReCorreo);
}
void QRegistroApartado::SlotFocoACorreo()
{
 ValidandoTelefono();
}
void QRegistroApartado::SlotFocoACelular()
{
  zSiscomQt3::Foco(QLECelular);
}
void QRegistroApartado::SlotFocoAReCelular()
{
  zSiscomQt3::Foco(QLEReCelular);
}
void QRegistroApartado::SlotFocoARegistraCelular()
{
 ValidandoTelefono();
}
void QRegistroApartado::SlotAceptar()
{
	done(1);
	emit SignalAceptar(); 
}
void QRegistroApartado::IniciaVariables()
{
QCtrFechaEntrega->ColocaFechaHoy();
zSiscomQt3::Foco(QLENombre);

}

void QRegistroApartado::ValidandoCorreo()
{
char lchrArrMensajeNoIgual[256];
zSiscomElectronica lzSisElectronica(zSisConexion,"ValidaReCaptura");
if(!lzSisElectronica.ValidaReCaptura(zSiscomQt3::Texto(QLECorreo),
				     zSiscomQt3::Texto(QLEReCorreo)))
{
sprintf(lchrArrMensajeNoIgual,
	"El Correo (%s) No es igual a (%s)",
	zSiscomQt3::Texto(QLECorreo),
	zSiscomQt3::Texto(QLEReCorreo));
  QMessageBox::information(this,"Aviso Sistema",lchrArrMensajeNoIgual);
  zSiscomQt3::Foco(QLECorreo);
}
else
zSiscomQt3::Foco(QPBRegistraCorreo);

}

void QRegistroApartado::ValidandoTelefono()
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
}
else
zSiscomQt3::Foco(QPBRegistraCelular);
}

int QRegistroApartado::RegistraCliente()
{
zSiscomElectronica lzSisElectronica(zSisConexion,"RegistraClientePersona");
return lzSisElectronica.RegistraCliente((zCliSiscom=ClienteSiscom()),&zClisSiscom);
}

int QRegistroApartado::RegistraCelular()
{
zSiscomElectronica lzSisElectronica(zSisConexion,"RegistraCelularAlumno");
 return lzSisElectronica.RegistraCelularAlumno(zCliSiscom);
}
int QRegistroApartado::RegistraCorreo()
{
zSiscomElectronica lzSisElectronica(zSisConexion,"RegistraCorreoAlumno");
return lzSisElectronica.RegistraCorreoAlumno(zCliSiscom);
}


int QRegistroApartado::RegistrandoCelular()
{
   zCliSiscom->Celular(FormaCelular());
  if(RegistraCelular())
  return 1;
  else
  return 0;
}

int QRegistroApartado::RegistrandoCorreo()
{
  zCliSiscom->Correo(FormaCorreo());
  if(RegistraCorreo())
  return 1;
  else
  return 0;
}


zTelefono *QRegistroApartado::FormaCelular()
{
   return new zTelefono("",zSiscomQt3::Texto(QLECelular));
}
zCorreo *QRegistroApartado::FormaCorreo()
{
  return new zCorreo("",zSiscomQt3::Texto(QLECorreo));
}

int QRegistroApartado::RegistrandoPersonales()
{
int lintRegistroCliente;
  if((lintRegistroCliente=RegistraCliente())==1)
  {
  zCliSiscom->IdPersona();
  return 1;
  }
  else
  if(lintRegistroCliente==2)
  {
	return 2;
  }
  else
  return 0;
}

zClienteSiscom *QRegistroApartado::ClienteSiscom()
{
zClienteSiscom *lzCliSiscom;
lzCliSiscom=new zClienteSiscom("",
 		     zSiscomQt3::Texto(QLENombre),
		     zSiscomQt3::Texto(QLEAPaterno),
		     zSiscomQt3::Texto(QLEAMaterno));
lzCliSiscom->Escuela(zSisRegEscuela);
return lzCliSiscom;
}
void QRegistroApartado::Escuela(zSiscomRegistro *pzSisRegEscuela)
{
	zSisRegEscuela=pzSisRegEscuela;
}
void QRegistroApartado::HabilitaDesHabilita(bool pbDato)
{
 QPBRegistraCelular->setEnabled(pbDato);
 QPBRegistraCorreo->setEnabled(pbDato);
 QPBAceptar->setEnabled(pbDato);
}
zClienteSiscom *QRegistroApartado::Cliente()
{
      return zCliSiscom;
      
}
zApartado *QRegistroApartado::Apartado()
{
    return new zApartado(zSiscomQt3::Texto(QLEACuenta),
    			 (const char *)QCtrFechaEntrega->ObtenFechaHora(),
			 zSiscomQt3::Texto(QTEObservaciones));
}
void QRegistroApartado::setFocus()
{
zSiscomQt3::Foco(QLENombre);
}

void QRegistroApartado::MuestraClientesSimilares()
{
QClientesRegistrados4 lQCRegistrados(zClisSiscom);
if(lQCRegistrados.Aceptar())
{
zCliSiscom=lQCRegistrados.Cliente();
MuestraCliente();
/*
intRegistroPersonales=1;
*/
}

}

void QRegistroApartado::MuestraCliente()
{
//    QLENumCliente->setText(zCliSiscom->IdPersona());
    QLENombre->setText(zCliSiscom->Nombre());
    QLEAPaterno->setText(zCliSiscom->APaterno());
    QLEAMaterno->setText(zCliSiscom->AMaterno());
}

void QRegistroApartado::MuestraDatosComunicacion()
{
   if(zCliSiscom->Celular() &&
      zCliSiscom->Correo())
   {
   QLECelular->setText(zCliSiscom->Celular()->Telefono());
   QLECorreo->setText(zCliSiscom->Correo()->Correo());
   intRegistroCelular=zSiscomQt3::TextoValido(QLECelular);
   intRegistroCorreo=zSiscomQt3::TextoValido(QLECorreo);
   }
   else
   VeADondePasaFocoComunicaciones();
}
void QRegistroApartado::VeADondePasaFocoComunicaciones()
{
   if(!zCliSiscom->Celular())
   zSiscomQt3::Foco(QLECelular);
   else
   if(!zCliSiscom->Correo() &&
      zCliSiscom->Celular())
     zSiscomQt3::Foco(QLECorreo);
}
void QRegistroApartado::ConsultandoSimilares()
{
int lintRegistro;
       MuestraClientesSimilares();	
       if(!(lintRegistro=RegistrandoPersonales()))
       {
	   MuestraDatosComunicacion();
	   QPBRegistraPersonales->setEnabled(false);
	   QPBRegistraCelular->setEnabled(false);
	   QPBRegistraCorreo->setEnabled(false);
	   zSiscomQt3::Foco(QLEACuenta);
	   HabilitandoAceptar();
       }
}
void QRegistroApartado::HabilitandoAceptar()
{
   QPBAceptar->setEnabled(zCliSiscom->PersonaValida() 			&&
   			  (zCliSiscom->Correo() || !SeCapturoCorreo() ) &&
			  zCliSiscom->Celular()      			&&
			  zSiscomQt3::TextoValido(QLEACuenta));
}
void QRegistroApartado::ControlesDespuesRegistrarPersonales()
{
     QPBRegistraPersonales->setEnabled(false); 
     VeADondePasaFocoComunicaciones();
}
void QRegistroApartado::HabilitaDesHabilitaRegistraCelular()
{
int lintRegistraCelular=zSiscomQt3::TextoValido(QLECelular) &&
                        zSiscomQt3::TextoValido(QLEReCelular);
QPBRegistraCelular->setEnabled(lintRegistraCelular);
}

void QRegistroApartado::HabilitaDesHabilitaRegistraCorreo()
{
 int lintRegistraCorreo=zSiscomQt3::TextoValido(QLECorreo) &&
 			zSiscomQt3::TextoValido(QLEReCorreo);
QPBRegistraCorreo->setEnabled(lintRegistraCorreo);
}
void QRegistroApartado::Ejecutando()
{
   exec();
}

int QRegistroApartado::SeCapturoCorreo()
{
  return zSiscomQt3::TextoValido(QLECorreo) &&
         zSiscomQt3::TextoValido(QLEReCorreo);
}
void QRegistroApartado::reject()
{
  LogSiscom("tratando de cerrar");
}
