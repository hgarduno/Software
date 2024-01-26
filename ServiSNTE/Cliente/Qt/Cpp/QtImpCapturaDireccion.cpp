#include <QtImpCapturaDireccion.h>

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
#include <zOperacionesServiSNTE.h>
#include <qpushbutton.h>
#include <qlineedit.h>
#include <qtextedit.h> 
QtImpCapturaDireccion::QtImpCapturaDireccion(int pintClienteRegistrado,
					QWidget *pQWParent,
				     const char *pchrPtrName,
				     bool pbModal,
				     WFlags pWFlags):
				     CapturaDireccion(pQWParent,pchrPtrName,pbModal,pWFlags),
				     zCliente(0),
				     intClienteRegistrado(pintClienteRegistrado)
{
 Conexion((zSiscomConexion *)gzSiscomConexion);
 ConectaSlots();
 zSiscomQt3::Foco(QLECalle);

}

void QtImpCapturaDireccion::Conexion(zSiscomConexion *pzSisConexion)
{
	zSisConexion=pzSisConexion;
}

void QtImpCapturaDireccion::ConectaSlots()
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
}
void QtImpCapturaDireccion::SlotFocoANoExterior()
{
  zSiscomQt3::Foco(QLENoExterior);
}

void QtImpCapturaDireccion::SlotFocoANoInterior()
{
  zSiscomQt3::Foco(QLENoInterior);
}

void QtImpCapturaDireccion::SlotFocoAColonia()
{
  zSiscomQt3::Foco(QLEColonia);
}

void QtImpCapturaDireccion::SlotFocoADelegacionMunicipio()
{
  zSiscomQt3::Foco(QLEDelegacionMunicipio);
}

void QtImpCapturaDireccion::SlotFocoAEstado()
{
  zSiscomQt3::Foco(QLEEstado);
}

void QtImpCapturaDireccion::SlotFocoACodigoPostal()
{
  zSiscomQt3::Foco(QLECodigoPostal);
}

void QtImpCapturaDireccion::SlotFocoAReferencias()
{
  zSiscomQt3::Foco(QTEReferencias);
}


void QtImpCapturaDireccion::SlotAceptar()
{
	intAceptar = 1;
	zPerDireccion=FormaDireccion();	
	done(1);
}
void QtImpCapturaDireccion::SlotCancelar()
{
	intAceptar = 0;
	done(1);
}
void QtImpCapturaDireccion::reject()
{

}
zDireccion *QtImpCapturaDireccion::FormaDireccion()
{
  if(!intClienteRegistrado)
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
   if(intClienteRegistrado==1)
   return zPerDireccion;
   if(intClienteRegistrado==2)
   return ActualizaDireccion();

}
zDireccion *QtImpCapturaDireccion::Direccion()
{  
   return zPerDireccion;
}
int QtImpCapturaDireccion::Aceptar()
{
  return intAceptar;
}

void QtImpCapturaDireccion::DireccionesPersona()
{
	if(zCliente)
	{
		ConsultandoDirecciones();
		zSiscomQt3::Foco(QPBAceptar);
	}

}
void QtImpCapturaDireccion::ConsultandoDirecciones()
{
	 ConsultaDirecciones();
	 CreaDireccion();
	 MuestraDireccion();
}
void QtImpCapturaDireccion::ConsultaDirecciones()
{
zOperacionesServiSNTE lzOpServiSNTE(zSisConexion,"DireccionesPersona");
zSisRegsDirecciones=lzOpServiSNTE.DireccionesPersona(zCliente);
}
void QtImpCapturaDireccion::MuestraDireccion()
{
  LogSiscom("Calle: %s\n\
            NoInterior: %s\n\
            NoExterior: %s\n\
            Colonia: %s\n\
            DelegMunic: %s\n\
            Estado: %s\n\
            CodigoPostal: %s\n\
            Referencias %s\n",
            (*zPerDireccion)["Calle"],
            (*zPerDireccion)["NumInterior"],
            (*zPerDireccion)["NumExterior"],
            (*zPerDireccion)["Colonia"],
            (*zPerDireccion)["DelegMunic"],
            (*zPerDireccion)["Estado"],
            (*zPerDireccion)["CodigoPostal"],
            (*zPerDireccion)["Referencias"]);
  QLECalle->setText((const char *)(*zPerDireccion)["Calle"]);
  QLENoInterior->setText((const char *)(*zPerDireccion)["NumInterior"]);
  QLENoExterior->setText((const char *)(*zPerDireccion)["NumExterior"]);
  QLEColonia->setText((const char *)(*zPerDireccion)["Colonia"]);
  QLEDelegacionMunicipio->setText((const char *)(*zPerDireccion)["DelegMunic"]);
  QLEEstado->setText((const char *)(*zPerDireccion)["Estado"]);
  QLECodigoPostal->setText((const char *)(*zPerDireccion)["CodigoPostal"]);
  QTEReferencias->setText((const char *)(*zPerDireccion)["Referencias"]);
}
void QtImpCapturaDireccion::Persona(zPersona *pzPersona)
{
  zCliente=pzPersona;
}
void QtImpCapturaDireccion::CapturandoDireccion()
{
    if(intClienteRegistrado)
    ConsultandoDirecciones();
    exec();
}
void QtImpCapturaDireccion::CreaDireccion()
{
  zPerDireccion=new zDireccion((*zSisRegsDirecciones)[0]);
}
zDireccion *QtImpCapturaDireccion::ActualizaDireccion()
{
 	zPerDireccion->Calle(zSiscomQt3::Texto(QLECalle));
	zPerDireccion->NumExterior(zSiscomQt3::Texto(QLENoInterior));
	zPerDireccion->NumInterior(zSiscomQt3::Texto(QLENoExterior));
	zPerDireccion->Colonia(zSiscomQt3::Texto(QLEColonia));
	zPerDireccion->Delegacion(zSiscomQt3::Texto(QLEDelegacionMunicipio));
	zPerDireccion->Estado(zSiscomQt3::Texto(QLEEstado));
	zPerDireccion->CodigoPostal(zSiscomQt3::Texto(QLECodigoPostal));
	zPerDireccion->Referencias(strdup((const char *)QTEReferencias->text()));
	return zPerDireccion;
}
