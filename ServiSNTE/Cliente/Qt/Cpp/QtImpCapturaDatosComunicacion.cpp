#include <QtImpCapturaDatosComunicacion.h>

#include <QCtrlTipoViviendaSS.h>
#include <zSiscomConexion.h>
#include <zSiscomOperaciones.h>
#include <zContratoBeneficios.h>


#include <zSiscomConexion.h>
#include <zSiscomRegistros.h>
#include <zSiscomRegistro.h>
#include <zSiscomDesarrollo4.h>
#include <zSiscomEnviaArchivo.h>
#include <zSiscomRecibeArchivo.h>
#include <zSiscomQt3.h>
#include <zSiscomCampo.h>
#include <zDatosComunicacion.h>
#include <zCorreo.h>
#include <zOperacionesServiSNTE.h>
#include <qpushbutton.h>
#include <qlineedit.h>
#include <qtextedit.h> 
#include <qradiobutton.h>
QtImpCapturaDatosComunicacion::QtImpCapturaDatosComunicacion(zContratoBeneficios *pzConBeneficios,
					QWidget *pQWParent,
				     const char *pchrPtrName,
				     bool pbModal,
				     WFlags pWFlags):
				     CapturaDatosComunicacion(pQWParent,pchrPtrName,pbModal,pWFlags),
				     zConBeneficios(pzConBeneficios)
{
 Conexion((zSiscomConexion *)gzSiscomConexion);
 IniciaControles();
 IniciaVariables();
 ConectaSlots();
 exec();
}

void QtImpCapturaDatosComunicacion::Conexion(zSiscomConexion *pzSisConexion)
{
	zSisConexion=pzSisConexion;
}
void QtImpCapturaDatosComunicacion::IniciaVariables()
{
    zSiscomQt3::Foco(QLETelefonoParticular);
    MuestraDatos();
    HabilitaRegistrar();
}
void QtImpCapturaDatosComunicacion::ConectaSlots()
{
	connect(QLETelefonoParticular,
		SIGNAL(returnPressed()),
		SLOT(SlotFocoATelefonoCelular()));
	connect(QLETelefonoCelular,
		SIGNAL(returnPressed()),
		SLOT(SlotFocoATelefonoRecado()));
	connect(QLETelefonoRecados,
		SIGNAL(returnPressed()),
		SLOT(SlotFocoACorreoElectronico()));
	connect(QLECorreo,
		SIGNAL(returnPressed()),
		SLOT(SlotFocoARegistrar()));
	connect(QPBAceptar,
		SIGNAL(clicked()),
		SLOT(SlotAceptar()));
	connect(QPBCancelar,
		SIGNAL(clicked()),
		SLOT(SlotCancelar()));
	connect(QPBRegistrar,
		SIGNAL(clicked()),
		SLOT(SlotRegistrar()));
	connect(QPBActualizar,
		SIGNAL(clicked()),
		SLOT(SlotActualiza()));
}
void QtImpCapturaDatosComunicacion::SlotActualiza()
{
	if(Actualizando())
	{
		QPBActualizar->setEnabled(false);
		QPBAceptar->setEnabled(true);
		zSiscomQt3::Foco(QPBAceptar);
	}
}
void QtImpCapturaDatosComunicacion::SlotFocoATelefonoCelular()
{
	zSiscomQt3::Foco(QLETelefonoCelular);
}
void QtImpCapturaDatosComunicacion::SlotFocoATelefonoRecado()
{
	zSiscomQt3::Foco(QLETelefonoRecados);
}
void QtImpCapturaDatosComunicacion::SlotFocoACorreoElectronico()
{
	zSiscomQt3::Foco(QLECorreo);
}
void QtImpCapturaDatosComunicacion::SlotFocoARegistrar()
{
   zSiscomQt3::Foco(QPBRegistrar);
}
void QtImpCapturaDatosComunicacion::SlotRegistrar()
{
  if(Registrando())
  {
  SiscomRegistroLog2(zDatComunicacion);
  QPBAceptar->setEnabled(true); 
  QPBRegistrar->setEnabled(false);
  zSiscomQt3::Foco(QPBAceptar);
  }
}
void QtImpCapturaDatosComunicacion::SlotAceptar()
{
	intAceptar = 1;
	done(1);
}
void QtImpCapturaDatosComunicacion::SlotCancelar()
{
	intAceptar = 0;
	done(1);
}
void QtImpCapturaDatosComunicacion::reject()
{

}
int QtImpCapturaDatosComunicacion::Aceptar()
{
  return intAceptar;
}

void QtImpCapturaDatosComunicacion::IniciaControles()
{

}
void QtImpCapturaDatosComunicacion::AsignaComunicacion()
{
if(!(zDatComunicacion=zConBeneficios->Comunicacion()))
{
zCorreo *lzCorreo=new zCorreo;
    lzCorreo->Correo(zSiscomQt3::Texto(QLECorreo));
    zDatComunicacion=new zDatosComunicacion(zConBeneficios->IdCliente());
    zDatComunicacion->AgregaTelefono("","Particular",zSiscomQt3::Texto(QLETelefonoParticular));
    zDatComunicacion->AgregaTelefono("","Celular",zSiscomQt3::Texto(QLETelefonoCelular));
    zDatComunicacion->AgregaTelefono("","Recado",zSiscomQt3::Texto(QLETelefonoRecados));
    zDatComunicacion->Correo(lzCorreo);
    zConBeneficios->Comunicacion(zDatComunicacion);
 }
 else
 {
   zDatComunicacion->ActualizaPorDescripcion("Particular",zSiscomQt3::Texto(QLETelefonoParticular));
   zDatComunicacion->ActualizaPorDescripcion("Celular",zSiscomQt3::Texto(QLETelefonoCelular));
   zDatComunicacion->ActualizaPorDescripcion("Recado",zSiscomQt3::Texto(QLETelefonoRecados));
   zDatComunicacion->ActualizaCorreo(zSiscomQt3::Texto(QLECorreo));
 }
}
int QtImpCapturaDatosComunicacion::Registra()
{
zOperacionesServiSNTE lzOpeServTelefono(zSisConexion,"RegistraTelefonosCliente");
return lzOpeServTelefono.RegistraTelefonos(zDatComunicacion);
}
int QtImpCapturaDatosComunicacion::Registrando()
{
   AsignaComunicacion();
   if(Registra())
   {
   return 1;
   }
   else 
   return 0;
}

void QtImpCapturaDatosComunicacion::MuestraDatos()
{
    QLETelefonoParticular->setText(zConBeneficios->TelefonoParticular());
    QLETelefonoCelular->setText(zConBeneficios->TelefonoCelular());
    QLETelefonoRecados->setText(zConBeneficios->TelefonoRecados());
    QLECorreo->setText(zConBeneficios->CorreoElectronico());
}
void QtImpCapturaDatosComunicacion::HabilitaRegistrar()
{
   QPBRegistrar->setEnabled(!((*zConBeneficios->TelefonoParticular()) ||
   			      (*zConBeneficios->TelefonoCelular())));
                              
}

int QtImpCapturaDatosComunicacion::Actualizando()
{
    AsignaComunicacion();
    if(Actualiza())
    {
	return 1;
    }
    else 
    {
	return 0;
    }
}
int QtImpCapturaDatosComunicacion::Actualiza()
{
zOperacionesServiSNTE lzOpServiSNTE(zSisConexion,"ActualizaTelefonosCliente");
return lzOpServiSNTE.RegistraTelefonos(zDatComunicacion);
}
