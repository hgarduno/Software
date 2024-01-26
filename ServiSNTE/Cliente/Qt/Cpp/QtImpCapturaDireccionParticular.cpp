#include <QtImpCapturaDireccionParticular.h>

#include <QCtrlTipoViviendaSS.h>
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

#include <zDireccion.h>
#include <zPersona.h>
#include <zContratoBeneficios.h>
#include <zTelefonos.h>
#include <zOperacionesServiSNTE.h>
#include <qpushbutton.h>
#include <qlineedit.h>
#include <qtextedit.h> 
#include <qmessagebox.h>
QtImpCapturaDireccionParticular::QtImpCapturaDireccionParticular(
				     zContratoBeneficios *pzContratoBeneficios,
				     QWidget *pQWParent,
				     const char *pchrPtrName,
				     bool pbModal,
				     WFlags pWFlags):
				     CapturaDireccionParticular(pQWParent,
				     				pchrPtrName,
								pbModal,
								pWFlags),
				     zPerDireccion(pzContratoBeneficios->DireccionParticular()),
				     zSisRegTipoVivienda(0),
				     zCliente(0),
				     zConBeneficios(pzContratoBeneficios),
				     intAceptar(0)
{
 Conexion((zSiscomConexion *)gzSiscomConexion);
 Iniciando();
 exec();
}
void QtImpCapturaDireccionParticular::Iniciando()
{
    ConectaSlots();
    IniciaControles();
    HabilitaRegistrar();
    if(zPerDireccion)
      InicioDireccionRegistrada();
    else
     InicioDireccionSinRegistrar();

}
void QtImpCapturaDireccionParticular::InicioDireccionRegistrada()
{
	MuestraDireccion();	
}
void QtImpCapturaDireccionParticular::InicioDireccionSinRegistrar()
{
    zSiscomQt3::Foco(QLECalle);
}
void QtImpCapturaDireccionParticular::Conexion(zSiscomConexion *pzSisConexion)
{
	zSisConexion=pzSisConexion;
}

void QtImpCapturaDireccionParticular::ConectaSlots()
{
	connect(QPBAceptar,
		SIGNAL(clicked()),
		SLOT(SlotAceptar()));
	connect(QPBCancelar,
		SIGNAL(clicked()),
		SLOT(SlotCancelar()));
	connect(QLECalle,
		SIGNAL(returnPressed()),
		SLOT(SlotFocoANoExterior()));
	connect(QLENoExterior,
		SIGNAL(returnPressed()),
		SLOT(SlotFocoANoInterior()));
	connect(QLENoInterior,
		SIGNAL(returnPressed()),
		SLOT(SlotFocoAColonia()));
	connect(QLEColonia,
		SIGNAL(returnPressed()),
		SLOT(SlotFocoADelegacionMunicipio()));
	connect(QLEDelegacionMunicipio,
		SIGNAL(returnPressed()),
		SLOT(SlotFocoAEstado()));
	connect(QLEEstado,
		SIGNAL(returnPressed()),
		SLOT(SlotFocoACodigoPostal()));
	connect(QLECodigoPostal,
		SIGNAL(returnPressed()),
		SLOT(SlotFocoAReferencias()));
	connect(QCtrTipoVivienda,
		SIGNAL(SignalTipoVivienda(zSiscomRegistro *)),
		SLOT(SlotTipoVivienda(zSiscomRegistro *)));
	connect(QLETiempoResidir,
		SIGNAL(returnPressed()),
		SLOT(SlotFocoARegistrar()));
	connect(QPBRegistrar,
		SIGNAL(clicked()),
		SLOT(SlotRegistrar()));
	connect(QLETiempoResidir,
		SIGNAL(textChanged(const QString &)),
		SLOT(SlotCambiaTiempoResidir(const QString &)));
}
void QtImpCapturaDireccionParticular::SlotCambiaTiempoResidir(const QString &)
{
  HabilitaRegistrar(); 
}
void QtImpCapturaDireccionParticular::SlotFocoARegistrar()
{
  zSiscomQt3::Foco(QPBRegistrar);
}
void QtImpCapturaDireccionParticular::SlotRegistrar()
{
	if(RegistrandoDatosCasa())
	{
	  QPBAceptar->setEnabled(true);
	  zSiscomQt3::Foco(QPBAceptar);
	  QPBRegistrar->setEnabled(false);
	  QLETiempoResidir->disconnect();
	}
}

void QtImpCapturaDireccionParticular::SlotFocoATiempoResidir()
{
   zSiscomQt3::Foco(QLETiempoResidir);
}
void QtImpCapturaDireccionParticular::SlotFocoAAceptar()
{
   zSiscomQt3::Foco(QPBAceptar);
}

void QtImpCapturaDireccionParticular::SlotTipoVivienda(zSiscomRegistro *pzSisRegTVivienda)
{
	zSisRegTipoVivienda=pzSisRegTVivienda;
	zSiscomQt3::Foco(QLETiempoResidir);
}
void QtImpCapturaDireccionParticular::SlotFocoANoExterior()
{
  zSiscomQt3::Foco(QLENoExterior);
}

void QtImpCapturaDireccionParticular::SlotFocoANoInterior()
{
  zSiscomQt3::Foco(QLENoInterior);
}

void QtImpCapturaDireccionParticular::SlotFocoAColonia()
{
  zSiscomQt3::Foco(QLEColonia);
}

void QtImpCapturaDireccionParticular::SlotFocoADelegacionMunicipio()
{
  zSiscomQt3::Foco(QLEDelegacionMunicipio);
}

void QtImpCapturaDireccionParticular::SlotFocoAEstado()
{
  zSiscomQt3::Foco(QLEEstado);
}

void QtImpCapturaDireccionParticular::SlotFocoACodigoPostal()
{
  zSiscomQt3::Foco(QLECodigoPostal);
}

void QtImpCapturaDireccionParticular::SlotFocoAReferencias()
{
  zSiscomQt3::Foco(QTEReferencias);
}


void QtImpCapturaDireccionParticular::SlotAceptar()
{
	intAceptar = 1;
	zPerDireccion=FormaDireccion();	
	done(1);
}
void QtImpCapturaDireccionParticular::SlotCancelar()
{
	intAceptar = 0;
	done(1);
}
void QtImpCapturaDireccionParticular::reject()
{

}
zDireccion *QtImpCapturaDireccionParticular::FormaDireccion()
{
  if(!zPerDireccion)
  {
  LogSiscom("No se tiene direccion");
  return new zDireccion(0,
		      zSiscomQt3::Texto(QLECalle),
		      zSiscomQt3::Texto(QLENoInterior),
		      zSiscomQt3::Texto(QLENoExterior),
		      zSiscomQt3::Texto(QLEColonia),
		      zSiscomQt3::Texto(QLEDelegacionMunicipio),
		      zSiscomQt3::Texto(QLEEstado),
		      zSiscomQt3::Texto(QLECodigoPostal),
		      strdup((const char *)QTEReferencias->text()),
		      (const char *)(*zCliente)["IdPersona"]);
   }
   else
   {
   LogSiscom("Ya tiene direccion");
   return zPerDireccion;
   }

}
zDireccion *QtImpCapturaDireccionParticular::Direccion()
{  
   return zPerDireccion;
}
int QtImpCapturaDireccionParticular::Aceptar()
{
  return intAceptar;
}

void QtImpCapturaDireccionParticular::DireccionesPersona()
{
	if(zCliente)
	{
	ConsultandoDirecciones();
	zSiscomQt3::Foco(QPBAceptar);
	}
}
void QtImpCapturaDireccionParticular::ConsultandoDirecciones()
{
	 ConsultaDirecciones();
	 CreaDireccion();
	 MuestraDireccion();
}
void QtImpCapturaDireccionParticular::ConsultaDirecciones()
{
zOperacionesServiSNTE lzOpServiSNTE(zSisConexion,"DireccionesPersona");
zSisRegsDirecciones=lzOpServiSNTE.DireccionesPersona(zCliente);
}
void QtImpCapturaDireccionParticular::HabilitaRegistrar()
{
//QPBRegistrar->setEnabled(!zPerDireccion->EsValida() );
}
void QtImpCapturaDireccionParticular::MuestraDireccion()
{
  QLECalle->setText((const char *)(*zPerDireccion)["Calle"]);
  QLENoInterior->setText((const char *)(*zPerDireccion)["NumInterior"]);
  QLENoExterior->setText((const char *)(*zPerDireccion)["NumExterior"]);
  QLEColonia->setText((const char *)(*zPerDireccion)["Colonia"]);
  QLEDelegacionMunicipio->setText((const char *)(*zPerDireccion)["DelegMunic"]);
  QLEEstado->setText((const char *)(*zPerDireccion)["Estado"]);
  QLECodigoPostal->setText((const char *)(*zPerDireccion)["CodigoPostal"]);
  QTEReferencias->setText((const char *)(*zPerDireccion)["Referencias"]);
  QLETiempoResidir->setText(zConBeneficios->TiempoResidir());
}
void QtImpCapturaDireccionParticular::Persona(zPersona *pzPersona)
{
  zCliente=pzPersona;
}
void QtImpCapturaDireccionParticular::CapturandoDireccion()
{
    if(zPerDireccion)
    ConsultandoDirecciones();
    exec();
}
void QtImpCapturaDireccionParticular::CreaDireccion()
{
  zPerDireccion=new zDireccion((*zSisRegsDirecciones)[0]);
}

void QtImpCapturaDireccionParticular::IniciaControles()
{
QCtrTipoVivienda->Servidor(zSisConexion);
QCtrTipoVivienda->IniciaControl();
}
void QtImpCapturaDireccionParticular::AnexaOtrosDatos()
{
zConBeneficios->TiempoResidir(zSiscomQt3::Texto(QLETiempoResidir));
zConBeneficios->TipoVivienda(zSisRegTipoVivienda);
}
int QtImpCapturaDireccionParticular::RegistrandoDatosCasa()
{
	AnexaOtrosDatos();
	if(RegistraDatosCasa())
	{
	  return 1;
	}
	else
	return 0;

}
int QtImpCapturaDireccionParticular::RegistraDatosCasa()
{
zOperacionesServiSNTE lzOpeServiDatosCasa(zSisConexion,"RegistraDatosCasa");
return lzOpeServiDatosCasa.RegistraDatosCasa(
				(const char *)(*zPerDireccion)["IdDireccion"],
				(const char *)(*zSisRegTipoVivienda)["idtipovivienda"],
				zSiscomQt3::Texto(QLETiempoResidir));
}
