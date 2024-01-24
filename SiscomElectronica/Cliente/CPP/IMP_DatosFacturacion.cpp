#include <IMP_DatosFacturacion.h>


#include <zSiscomElectronica.h>


#include <zPersona.h>
#include <zEmpresa.h>
#include <zDireccion.h>
#include <zCorreo.h>
#include <zTelefono.h>
#include <zCliente.h>
#include <zCorreos.h>

#include <zSiscomConexion.h>
#include <zSiscomRegistros.h>
#include <zSiscomRegistro.h>
#include <zSiscomDesarrollo4.h>
#include <zSiscomQt3.h>
#include <zSiscomCampo.h>

#include <qlineedit.h> 
#include <qpushbutton.h>
#include <qtable.h>

#include <QCtrlRFCs.h>
#include <QCtrlFormaPagoSat.h>
#include <QCtrlMetodoPagoSat.h>
#include <QCtrlUsoCFDISat.h>
#include <QCtrlRegimenFiscal.h>

QDatosFacturacion::QDatosFacturacion(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    zCliente *pzCliente,
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    bool pbModal,
				    WFlags pWFlags):	      
				DatosFacturacion(pQWParent,pchrPtrName,pbModal,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos),
				zClienteC(pzCliente),	
				zSisConexion((zSiscomConexion *)gzSiscomConexion),
				zPersonaC(0),
				zEmpresaC(0),
				zCorreoC(0),
				zDireccionC(0),
				zTelefonoC(0),
				intAceptar(0),
				intEdoRegistro(0),
				intAgregandoCorreo(0),
				zCorreoActivo(0),
				intEmpresaRegistrada(0)
{
IniciaVariables();
ConectaSlots();
exec();
}

QDatosFacturacion::~QDatosFacturacion()
{

}
void QDatosFacturacion::IniciaVariables()
{
IniciaControles();
SeEstaFacturando();
zSiscomQt3::Foco(QCtrRFCs);
}
void QDatosFacturacion::IniciaControles()
{
QCtrRFCs->Servidor(zSisConexion);
QCtrRFCs->IniciaControl();
QCtrFormaPagoSat->Servidor(zSisConexion);
QCtrFormaPagoSat->IniciaControl();
QCtrMetodoPago->Servidor(zSisConexion);
QCtrMetodoPago->IniciaControl();
QCtrUsoCFDI->Servidor(zSisConexion);
QCtrUsoCFDI->IniciaControl();
QCtrRegimenFiscal->Servidor(zSisConexion);
QCtrRegimenFiscal->IniciaControl();
QLEFormaPago->setText(QCtrFormaPagoSat->FormaPagoChar(0));
QLEMetodoPago->setText(QCtrMetodoPago->MetodoPagoChar(0));
QLEUsoFactura->setText(QCtrUsoCFDI->UsoFacturaChar(0));
zSisRegFormaPago=QCtrFormaPagoSat->FormaPago(0);
zSisRegMetodoPago=QCtrMetodoPago->MetodoPago(0);
zSisRegUsoFactura=QCtrUsoCFDI->UsoFactura(0);
}
void QDatosFacturacion::ConectaSlots()
{
//{ Slot Pasa Foco , Capturando 
connect(QCtrRFCs,SIGNAL(SignalSelecciono(zSiscomRegistro *)),SLOT(SlotFocoARazonSocial(zSiscomRegistro *)));
connect(QLERazonSocial,SIGNAL(returnPressed()),SLOT(SlotFocoARegimenFiscal()));
//connect(QLERegimenFiscal,SIGNAL(returnPressed()),SLOT(SlotFocoACalle()));
connect(QLENombre,SIGNAL(returnPressed()),SLOT(SlotFocoAAPaterno()));
connect(QLEAPaterno,SIGNAL(returnPressed()),SLOT(SlotFocoAAMaterno()));
connect(QLEAMaterno,SIGNAL(returnPressed()),SLOT(SlotFocoACalle()));
connect(QLECalle,SIGNAL(returnPressed()),SLOT(SlotFocoANumero()));
connect(QLENumero,SIGNAL(returnPressed()),SLOT(SlotFocoANumeroInt()));
connect(QLENumeroInt,SIGNAL(returnPressed()),SLOT(SlotFocoADelegacion()));
connect(QLEDelegacion,SIGNAL(returnPressed()),SLOT(SlotFocoAColonia()));
connect(QLEColonia,SIGNAL(returnPressed()),SLOT(SlotFocoAEstado()));
connect(QLEEstado,SIGNAL(returnPressed()),SLOT(SlotFocoACP()));
connect(QLECP,SIGNAL(returnPressed()),SLOT(SlotFocoACorreo()));
connect(QLECorreo,SIGNAL(returnPressed()),SLOT(SlotFocoACorreoOtraVez()));
connect(QLECorreoOtraVez,SIGNAL(returnPressed()),SLOT(SlotFocoATelefono()));
connect(QLETelefono,SIGNAL(returnPressed()),SLOT(SlotFocoARegistrarDatos()));

connect(QCtrRFCs,
	SIGNAL(textChanged(const QString &)),
	SLOT(SlotCapturandoRFC(const QString &)));
connect(QLERazonSocial,
	SIGNAL(textChanged(const QString &)),
	SLOT(SlotCapturandoRazonSocial(const QString &)));

connect(QCtrRegimenFiscal,
	SIGNAL(SignalCapturandoRegimenFiscal(const QString &)),
	SLOT(SlotCapturandoRegimenFiscal(const QString &)));
connect(QLENombre,
	SIGNAL(textChanged(const QString &)),
	SLOT(SlotCapturandoNombre(const QString &)));
connect(QLEAPaterno,
	SIGNAL(textChanged(const QString &)),
	SLOT(SlotCapturandoAPaterno(const QString &)));
connect(QLEAMaterno,
	SIGNAL(textChanged(const QString &)),
	SLOT(SlotCapturandoAMaterno(const QString &)));
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
connect(QLECorreo,
	SIGNAL(textChanged(const QString &)),
	SLOT(SlotCapturandoCorreo(const QString &)));
connect(QLECorreoOtraVez,
	SIGNAL(textChanged(const QString &)),
	SLOT(SlotCapturandoCorreoOtraVez(const QString &)));
/*
connect(QLETelefono,
	SIGNAL(textChanged(const QString &)),
	SLOT(SlotCapturandoTelefono(const QString &)));
*/
connect(QCtrFormaPagoSat,
	SIGNAL(SignalSelecciono(zSiscomRegistro *)),
	SLOT(SlotFormaPago(zSiscomRegistro *)));
connect(QCtrMetodoPago,
	SIGNAL(SignalSelecciono(zSiscomRegistro *)),
	SLOT(SlotMetodoPago(zSiscomRegistro *)));
connect(QCtrUsoCFDI,
	SIGNAL(SignalSelecciono(zSiscomRegistro *)),
	SLOT(SlotUsoCFDI(zSiscomRegistro *)));
connect(QCtrRegimenFiscal,
	SIGNAL(SignalSelecciono(zSiscomRegistro *)),
	SLOT(SlotRegimenFiscal(zSiscomRegistro *)));
//}
connect(QPBAceptar,
	SIGNAL(clicked()),
	SLOT(SlotAceptar()));
connect(QPBCancelar,
	SIGNAL(clicked()),
	SLOT(SlotCancelar()));

connect(QPBRegistrar,
	SIGNAL(clicked()),
	SLOT(SlotRegistrar()));
connect(QPBAgregarCorreo,
	SIGNAL(clicked()),
	SLOT(SlotAgregarCorreo()));
connect(QTCorreos,
	SIGNAL(clicked(int,int,int,const QPoint &)),
	SLOT(SlotSeleccionoCorreo(int,int,int,const QPoint &)));

}
void QDatosFacturacion::SlotRegimenFiscal(zSiscomRegistro *pzSisRegRegimenFiscal)
{
    zSisRegRegimenFiscal=pzSisRegRegimenFiscal;
    if(intEmpresaRegistrada)
    RegistrandoRegimenFiscal();
}
void QDatosFacturacion::SlotFocoARegimenFiscal()
{
   zSiscomQt3::Foco(QCtrRegimenFiscal);		
}
void QDatosFacturacion::SlotFormaPago(zSiscomRegistro *pzSisRegFormaPago)
{
    zSisRegFormaPago=pzSisRegFormaPago;
    QLEFormaPago->setText((const char *)(*zSisRegFormaPago)["formapago"]);
    zSiscomQt3::Foco(QCtrMetodoPago);
}

void QDatosFacturacion::SlotMetodoPago(zSiscomRegistro *pzSisRegMetodoPago)
{
    zSisRegMetodoPago=pzSisRegMetodoPago;
    QLEMetodoPago->setText((const char *)(*zSisRegMetodoPago)["metodopago"]); 
    zSiscomQt3::Foco(QCtrUsoCFDI);
}
void QDatosFacturacion::SlotUsoCFDI(zSiscomRegistro *pzSisRegUsoFactura)
{
    zSisRegUsoFactura=pzSisRegUsoFactura;
    QLEUsoFactura->setText((const char *)(*zSisRegUsoFactura)["uso"]);
}
void QDatosFacturacion::SlotFocoARegistrarDatos()
{
   zSiscomQt3::Foco(QPBRegistrar);
}
void QDatosFacturacion::SlotSeleccionoCorreo(int pintCorreo,
					     int,
					     int,
					     const QPoint &)
{
zCorreoActivo=zClienteC->Correo(pintCorreo);
zClienteC->CorreoActivo(zCorreoActivo);
QTCorreos->selectRow(pintCorreo);
QPBAceptar->setEnabled(true);
zSiscomQt3::Foco(QPBAceptar);
}
void QDatosFacturacion::ConectaSlotsAgregaCorreo()
{
	connect(QLECorreoOtraVez,SIGNAL(returnPressed()),SLOT(SlotFocoAAgregarCorreo()));	
}
void QDatosFacturacion::SlotFocoAAgregarCorreo()
{
	zSiscomQt3::Foco(QPBAgregarCorreo);
}
void QDatosFacturacion::SlotAgregarCorreo()
{
	if(!intAgregandoCorreo)
	AgregandoNuevoCorreo();
	else
	{
	RegistraNuevoCorreo();
	ReConsultaCliente();
	MuestraCorreos();
	}
}
void QDatosFacturacion::SlotRegistrar()
{
  DatosCliente();
  Registrando();
  intEdoRegistro=1;
  QPBAceptar->setEnabled(true);
  QPBRegistrar->setEnabled(false);
}
void QDatosFacturacion::SlotAceptar()
{
   intAceptar=1;
   done(intAceptar);
}
void QDatosFacturacion::SlotCancelar()
{
   intAceptar=0;
   done(intAceptar);
}

//{{Slots Foco y Agregando
void QDatosFacturacion::SlotFocoACalle()
{
 /*  
  * Tepotzotlan Mexico a 1 de Mayo del 2023 
  * A punto de cumplir 3 semanas desde la operacion de prostata :)
  * Validar los datos que faltaron 
  * en este caso, solo valido que la empresa sea valida 
  * si , es asi asumo que ya tiene todos los demas datos 
  * y paso el foco a QPBAceptar
  */
       if(Cliente()->Empresa())
       {
       SiscomRegistroLog2(zSisRegRegimenFiscal);
       Cliente()->Empresa()->RegimenFiscal((const char *)(*zSisRegRegimenFiscal)["regimen"]);
       zSiscomQt3::Foco(QPBAceptar);
       }
       else
	zSiscomQt3::Foco(QLECalle);
}
void QDatosFacturacion::SlotFocoANumero()
{
	zSiscomQt3::Foco(QLENumero);
}
void QDatosFacturacion::SlotFocoANumeroInt()
{
	zSiscomQt3::Foco(QLENumeroInt);
}
void QDatosFacturacion::SlotFocoADelegacion()
{
	zSiscomQt3::Foco(QLEDelegacion);
}
void QDatosFacturacion::SlotFocoAColonia()
{
	zSiscomQt3::Foco(QLEColonia);
}
void QDatosFacturacion::SlotFocoAEstado()
{
    zSiscomQt3::Foco(QLEEstado);
}
void QDatosFacturacion::SlotFocoACP()
{
	zSiscomQt3::Foco(QLECP);
}
void QDatosFacturacion::SlotFocoACorreo()
{
	zSiscomQt3::Foco(QLECorreo);
}
void QDatosFacturacion::SlotFocoACorreoOtraVez()
{
	zSiscomQt3::Foco(QLECorreoOtraVez);
}
void QDatosFacturacion::SlotFocoAAceptar()
{
      zSiscomQt3::Foco(QPBAceptar);
}
void QDatosFacturacion::SlotFocoARazonSocial(zSiscomRegistro *)
{
  if(!(intEmpresaRegistrada=ValidaRFCRegistrado()))
  {
  PasandoRazonSocial();
  }
  else
  {
  if(intEmpresaRegistrada==3)
  PasandoRegimenFiscal();
  if(intEmpresaRegistrada==2)
  zSiscomQt3::Foco(QCtrFormaPagoSat);   
  ClienteRegistrado();
  }
}
void QDatosFacturacion::SlotFocoANombre()
{
  zSiscomQt3::Foco(QLENombre);
}
void QDatosFacturacion::SlotFocoAAPaterno()
{
  zSiscomQt3::Foco(QLEAPaterno);
}
void QDatosFacturacion::SlotFocoAAMaterno()
{
  zSiscomQt3::Foco(QLEAMaterno);
}

void QDatosFacturacion::SlotFocoATelefono()
{
  zSiscomQt3::Foco(QLETelefono);
}

void QDatosFacturacion::SlotCapturandoRazonSocial(const QString &pQStrRazonSocial)
{
int lintEdoRazonSocial=zSiscomQt3::TextoValido(pQStrRazonSocial);
 QLERazonSocial->setEnabled(lintEdoRazonSocial);
 QLENombre->setEnabled(!lintEdoRazonSocial);
/*
 QLECalle->setEnabled(lintEdoRazonSocial);
 */
 QCtrRegimenFiscal->setEnabled(lintEdoRazonSocial);
 ActivaRegistrarDatos(); 
}
void QDatosFacturacion::SlotCapturandoRegimenFiscal(const QString &pQStrRegimenFiscal)
{
int lintEdoRegimenFiscal=zSiscomQt3::TextoValido(pQStrRegimenFiscal);
  QCtrRegimenFiscal->setEnabled(lintEdoRegimenFiscal);
  QLECalle->setEnabled(lintEdoRegimenFiscal);
  /*
 ActivaRegistrarDatos(); 
 */

}
void QDatosFacturacion::SlotCapturandoNombre(const QString &pQStrNombre)
{
int lintEdoNombre=zSiscomQt3::TextoValido(pQStrNombre);
 QLERazonSocial->setEnabled(!lintEdoNombre);
 QLEAPaterno->setEnabled(lintEdoNombre);
}
void QDatosFacturacion::SlotCapturandoAPaterno(const QString &pQStrAPaterno)
{
int lintEdoNombre=zSiscomQt3::TextoValido(pQStrAPaterno);
QLEAMaterno->setEnabled(lintEdoNombre);
}
void QDatosFacturacion::SlotCapturandoAMaterno(const QString &pQStrAMaterno)
{
   QLECalle->setEnabled(zSiscomQt3::TextoValido(pQStrAMaterno));
}
void QDatosFacturacion::SlotCapturandoRFC(const QString &pQStrRFC)
{
 int lintEdoRFC=zSiscomQt3::TextoValido(pQStrRFC);
 QLERazonSocial->setEnabled(lintEdoRFC);
 QLENombre->setEnabled(lintEdoRFC);
 ActivaRegistrarDatos(); 
}
void QDatosFacturacion::SlotCapturandoCalle(const QString &pQStrCalle)
{
   QLENumero->setEnabled(zSiscomQt3::TextoValido(pQStrCalle));
 ActivaRegistrarDatos(); 
}
void QDatosFacturacion::SlotCapturandoNumero(const QString &pQStrNumero)
{
  QLENumeroInt->setEnabled(zSiscomQt3::TextoValido(pQStrNumero));
  QLEDelegacion->setEnabled(zSiscomQt3::TextoValido(pQStrNumero));
 ActivaRegistrarDatos(); 
}
void QDatosFacturacion::SlotCapturandoNumeroInt(const QString &pQStrNumeroInt)
{
  QLEDelegacion->setEnabled(zSiscomQt3::TextoValido(pQStrNumeroInt)); 
}
void QDatosFacturacion::SlotCapturandoDelegacion(const QString &pQStrDelegacion)
{
  QLEColonia->setEnabled(zSiscomQt3::TextoValido(pQStrDelegacion)); 
 ActivaRegistrarDatos(); 
}
void QDatosFacturacion::SlotCapturandoColonia(const QString &pQStrColonia)
{
  QLEEstado->setEnabled(zSiscomQt3::TextoValido(pQStrColonia)); 
 ActivaRegistrarDatos(); 
}
void QDatosFacturacion::SlotCapturandoEstado(const QString &pQStrColonia)
{
  QLECP->setEnabled(zSiscomQt3::TextoValido(pQStrColonia)); 
 ActivaRegistrarDatos(); 
}

void QDatosFacturacion::SlotCapturandoCP(const QString &pQStrCP)
{
	QLECorreo->setEnabled(zSiscomQt3::TextoValido(pQStrCP));
 ActivaRegistrarDatos(); 
}
void QDatosFacturacion::SlotCapturandoCorreo(const QString &pQStrCorreo)
{
	QLECorreoOtraVez->setEnabled(zSiscomQt3::TextoValido(pQStrCorreo));
 ActivaRegistrarDatos(); 
}
void QDatosFacturacion::SlotCapturandoCorreoOtraVez(const QString &pQStrCorreo)
{
     QLETelefono->setEnabled(zSiscomQt3::TextoValido(pQStrCorreo));
 ActivaRegistrarDatos(); 
}
//}}


void QDatosFacturacion::ClienteEmpresa()
{
   FormaEmpresa(); 
}
void QDatosFacturacion::ClientePersona()
{
 FormaPersona();
}
void QDatosFacturacion::FormaEmpresa()
{
   zEmpresaC=new zEmpresa(0,zSiscomQt3::Texto(QLERazonSocial));
}
void QDatosFacturacion::FormaPersona()
{
  zPersonaC=new zPersona((const char *)0,
  			 zSiscomQt3::Texto(QLENombre),
  			 zSiscomQt3::Texto(QLEAPaterno),
  			 zSiscomQt3::Texto(QLEAMaterno));
}
void QDatosFacturacion::FormaDireccion()
{
  zDireccionC=new zDireccion((const char *)0,
  			     zSiscomQt3::Texto(QLECalle),
			     zSiscomQt3::Texto(QLENumero),
			     zSiscomQt3::Texto(QLENumeroInt),
			     zSiscomQt3::Texto(QLEDelegacion),
			     zSiscomQt3::Texto(QLEColonia),
			     zSiscomQt3::Texto(QLEEstado),
			     zSiscomQt3::Texto(QLECP));
}
void QDatosFacturacion::FormaCorreo()
{
  zCorreoC=new zCorreo((const char *)0,zSiscomQt3::Texto(QLECorreo));	
}
void QDatosFacturacion::FormaTelefono()
{
   zTelefonoC=new zTelefono((const char *)0,zSiscomQt3::Texto(QLETelefono));
}
void QDatosFacturacion::Registrando()
{
SiscomRegistroLog2(zClienteC);
zSiscomElectronica lzSiscomERegCliente(zSisConexion,"RegistraClienteFacturacion");
lzSiscomERegCliente.RegistraCliente(zClienteC);

}
void QDatosFacturacion::DatosCliente()
{
	if(zSiscomQt3::TextoValido(QLERazonSocial))
	ClienteEmpresa();
	else
	ClientePersona();
	FormaDireccion();
	FormaCorreo();
	FormaTelefono();
	zCorreosC<<zCorreoC;
  	zCorreoActivo=zCorreoC;
	zTelefonosC << zTelefonoC;
	FormaCliente();
}
void QDatosFacturacion::FormaCliente()
{
  zClienteC=new zCliente;
 zClienteC->RFC(zSiscomQt3::Texto(QCtrRFCs->RFC())); 
  zClienteC->Persona(zPersonaC);
  zClienteC->Empresa(zEmpresaC);
  zClienteC->Correos(&zCorreosC);
  zClienteC->CorreoActivo(zCorreoActivo);
  zClienteC->Telefonos(&zTelefonosC);
  zClienteC->Direccion(zDireccionC);
}
zCliente *QDatosFacturacion::Cliente()
{
   return zClienteC;
}
int QDatosFacturacion::Aceptar()
{
	return intAceptar;
}
int QDatosFacturacion::ValidaRFCRegistrado()
{
int lintRegreso;
zClienteC=new zCliente;
zSiscomElectronica lzSisElectronica(zSisConexion,"ValidaRfcRegistrado");
if((lintRegreso=lzSisElectronica.ClienteRegistrado(zSiscomQt3::Texto(QCtrRFCs->RFC()),zClienteC)))
{
AsignaClienteRegistrado();
   if(!(lintRegreso=ValidaRegimenFiscal()))
      return 2;
}

   return lintRegreso;
}

void QDatosFacturacion::ClienteRegistrado()
{
 MuestraClienteRegistrado();
 QPBRegistrar->setEnabled(false);
 QPBAgregarCorreo->setEnabled(true);
}
void QDatosFacturacion::MuestraNombre()
{
    QLENombre->setText(zClienteC->Persona()->Nombre()); 
    QLEAPaterno->setText(zClienteC->Persona()->APaterno());
    QLEAMaterno->setText(zClienteC->Persona()->AMaterno());

}
void QDatosFacturacion::MuestraEmpresa()
{
  QLERazonSocial->setText(zClienteC->Empresa()->RazonSocial());
}
void QDatosFacturacion::MuestraTelefonos()
{

}
void QDatosFacturacion::MuestraCorreos()
{
zCorreo *lzCorreo;
 int lintContador=0; 
   while((lzCorreo=zClienteC->Correo()))
   {
   	QTCorreos->setNumRows(lintContador+1);	
	QTCorreos->setText(lintContador,0,lzCorreo->Correo());
	lintContador++;
   }
  zSiscomQt3::AjustaColumnasTabla(QTCorreos);
}
void QDatosFacturacion::MuestraDireccion()
{
    QLECalle->setText(zClienteC->Direccion()->Calle());
    QLENumero->setText(zClienteC->Direccion()->Numero());
    QLENumeroInt->setText(zClienteC->Direccion()->NumeroInt());
    QLEDelegacion->setText(zClienteC->Direccion()->Delegacion());
    QLEColonia->setText(zClienteC->Direccion()->Colonia());
    QLEEstado->setText(zClienteC->Direccion()->Estado());
    QLECP->setText(zClienteC->Direccion()->CP());

}
void QDatosFacturacion::MuestraClienteRegistrado()
{
	if(zClienteC->Persona())
	MuestraNombre();
	else
	if(zClienteC->Empresa())
	MuestraEmpresa();
	MuestraDireccion();
	MuestraTelefonos();
	MuestraCorreos();

	QLECorreo->setEnabled(false);
	QPBRegistrar->setEnabled(false);
}
void QDatosFacturacion::AgregandoNuevoCorreo()
{
	QLECorreo->setEnabled(true);
	zSiscomQt3::Foco(QLECorreo);
	intAgregandoCorreo=1;
	disconnect(QLECorreoOtraVez,SIGNAL(returnPressed()),0,0);
	ConectaSlotsAgregaCorreo();
}
void QDatosFacturacion::RegistraNuevoCorreo()
{
zCorreos lzCorreos;
zSiscomElectronica lzSiscomElec(zSisConexion,"AgregaCorreoCliente");
  FormaCorreo();
  lzCorreos<< zCorreoC;
lzSiscomElec.AgregaCorreoCliente(zPersonaC,
				 zEmpresaC,
				 &lzCorreos);
}
void QDatosFacturacion::AsignaClienteRegistrado()
{
  zPersonaC=zClienteC->Persona();
  zEmpresaC=zClienteC->Empresa();
}

void QDatosFacturacion::ReConsultaCliente()
{
zSiscomElectronica lzSisElectronica(zSisConexion,"ValidaRfcRegistrado");
lzSisElectronica.ClienteRegistrado(zSiscomQt3::Texto(QCtrRFCs->RFC()),zClienteC);
zClienteC->ReIniciaApuntadorCorreo();
}
zCorreo *QDatosFacturacion::CorreoActivo()
{
 return zCorreoActivo;
}
void QDatosFacturacion::SeEstaFacturando()
{
 LogSiscom("El Cliente : %x ",zClienteC);
 if(zClienteC)
 {
 	zClienteC->ReIniciaApuntadorCorreo();
	MuestraClienteRegistrado();	
 }
}
zSiscomRegistro *QDatosFacturacion::FormaPago()
{
   return zSisRegFormaPago;
}

zSiscomRegistro *QDatosFacturacion::MetodoPago()
{
   return zSisRegMetodoPago;
}
zSiscomRegistro *QDatosFacturacion::UsoFactura()
{
   return zSisRegUsoFactura;
}
void QDatosFacturacion::PasandoRazonSocial()
{
  QLERazonSocial->setEnabled(true);
  zSiscomQt3::Foco(QLERazonSocial);
}
void QDatosFacturacion::PasandoRegimenFiscal()
{
   QCtrRegimenFiscal->setEnabled(true);
   zSiscomQt3::Foco(QCtrRegimenFiscal);
}
void QDatosFacturacion::ActivaRegistrarDatos()
{
int lintActivaRegistrar;

   lintActivaRegistrar=zSiscomQt3::TextoValido(QLERazonSocial) &&
                       zSiscomQt3::TextoValido(QLECalle)       &&
		       zSiscomQt3::TextoValido(QLENumero)      &&
		       zSiscomQt3::TextoValido(QLEDelegacion)  &&
		       zSiscomQt3::TextoValido(QLEColonia)     &&
		       zSiscomQt3::TextoValido(QLEEstado)      &&
		       zSiscomQt3::TextoValido(QLECP)          &&
		       zSiscomQt3::TextoValido(QLECorreo)      &&
		       zSiscomQt3::TextoValido(QLECorreoOtraVez);
QPBRegistrar->setEnabled(lintActivaRegistrar);
}

int QDatosFacturacion::ValidaRegimenFiscal()
{
  if(!(*zEmpresaC)["RegimenFiscal"])
  {
	LogSiscom("NOOOOOO Viene el Regimen Fiscal");
	zSiscomQt3::Foco(QCtrRegimenFiscal);
	return 3;
  }
  else
  {
	LogSiscom("Ya viene el regimen ... continuamos con la facturacion");
	return 0;
  }

}
void QDatosFacturacion::RegistrandoRegimenFiscal()
{
   RegistraRegimenFiscal();
   /*
    * Para el caso de una empresa que no esta registrada ?????
   zSiscomQt3::Foco(QCtrFormaPagoSat);
   */

}
void QDatosFacturacion::RegistraRegimenFiscal()
{
zSiscomElectronica lzSisElectronica(zSisConexion,"RegistraRegimenFiscal");
 lzSisElectronica.RegistraRegimenFiscal(zClienteC->RFC(),
 					(const char *)(*zSisRegRegimenFiscal)["regimen"]);
}
