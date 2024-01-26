#include <QtImpCapturaDatosGenerales.h>

#include <QCtrlTipoViviendaSS.h>
#include <zSiscomConexion.h>
#include <zSiscomOperaciones.h>
#include <zContratoBeneficios.h>
#include <zDatosGenerales.h>

#include <zSiscomQt3.h>
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
#include <qradiobutton.h>
#include <qbuttongroup.h> 
QtImpCapturaDatosGenerales::QtImpCapturaDatosGenerales(zContratoBeneficios *pzConBeneficios,
					QWidget *pQWParent,
				     const char *pchrPtrName,
				     bool pbModal,
				     WFlags pWFlags):
				     CapturaDatosGenerales(pQWParent,pchrPtrName,pbModal,pWFlags),
				     zConBeneficios(pzConBeneficios),
				     zCliente(0)
{
 Conexion((zSiscomConexion *)gzSiscomConexion);
 IniciaControles();
 IniciaVariables();
 ConectaSlots();
 exec();
}

void QtImpCapturaDatosGenerales::Conexion(zSiscomConexion *pzSisConexion)
{
	zSisConexion=pzSisConexion;
}
void QtImpCapturaDatosGenerales::IniciaVariables()
{
	HabilitaRegistrar();
    MuestraDatos();
}
void QtImpCapturaDatosGenerales::ConectaSlots()
{
	connect(QPBAceptar,
		SIGNAL(clicked()),
		SLOT(SlotAceptar()));
	connect(QPBCancelar,
		SIGNAL(clicked()),
		SLOT(SlotCancelar()));
	connect(QPBRegistrar,
		SIGNAL(clicked()),
		SLOT(SlotRegistrar()));

	connect(QLERFCHomoclave,
		SIGNAL(returnPressed()),
		SLOT(SlotFocoACurp()));
	connect(QLECurp,
		SIGNAL(returnPressed()),
		SLOT(SlotFocoAEstadoNacimiento()));
	connect(QLEEstadoNacimiento,
		SIGNAL(returnPressed()),
		SLOT(SlotFocoAPaisNacimiento()));
	connect(QLEPaisNacimiento,
		SIGNAL(returnPressed()),
		SLOT(SlotFocoAMasculino()));
	connect(QLEEdad,
		SIGNAL(returnPressed()),
		SLOT(SlotFocoAFechaNacimiento()));
	connect(QLEFechaNacimiento,
		SIGNAL(returnPressed()),
		SLOT(SlotFocoAIdentificacion()));
	connect(QLEIdentificacion,
		SIGNAL(returnPressed()),
		SLOT(SlotFocoANoIdentificacion()));
	connect(QLENoIdentificacion,
		SIGNAL(returnPressed()),
		SLOT(SlotFocoAOcupacion()));
	connect(QLEOcupacion,
		SIGNAL(returnPressed()),
		SLOT(SlotFocoANacionalidad()));
	connect(QLENacionalidad,
		SIGNAL(returnPressed()),
		SLOT(SlotFocoARegistrar()));
	connect(QGBSexo,
		SIGNAL(clicked(int)),
		SLOT(SlotSeleccionaSexo(int)));

	connect(QPBActualizar,
		SIGNAL(clicked()),
		SLOT(SlotActualizaGenerales()));
}
void QtImpCapturaDatosGenerales::SlotActualizaGenerales()
{
   Actualizando();
}
void QtImpCapturaDatosGenerales::SlotSeleccionaSexo(int pintNBoton)
{
  LogSiscom("Seleccionando el sexo %d",pintNBoton);
}
void QtImpCapturaDatosGenerales::SlotFocoARegistrar()
{
   zSiscomQt3::Foco(QPBRegistrar);
}
void QtImpCapturaDatosGenerales::SlotFocoACurp()
{
  zSiscomQt3::Foco(QLECurp);
}

void QtImpCapturaDatosGenerales::SlotFocoAEstadoNacimiento()
{
  zSiscomQt3::Foco(QLEEstadoNacimiento);
}
void QtImpCapturaDatosGenerales::SlotFocoAPaisNacimiento()
{
  zSiscomQt3::Foco(QLEPaisNacimiento);
}
void QtImpCapturaDatosGenerales::SlotFocoAMasculino()
{
  zSiscomQt3::Foco((QWidget *)QRBMasculino);
}
void QtImpCapturaDatosGenerales::SlotFocoAIdentificacion()
{
  zSiscomQt3::Foco(QLEIdentificacion);
}
void QtImpCapturaDatosGenerales::SlotFocoAFechaNacimiento()
{
  zSiscomQt3::Foco(QLEFechaNacimiento);
}
void QtImpCapturaDatosGenerales::SlotFocoANoIdentificacion()
{
  zSiscomQt3::Foco(QLENoIdentificacion);
}
void QtImpCapturaDatosGenerales::SlotFocoAOcupacion()
{
  zSiscomQt3::Foco(QLEOcupacion);
}
void QtImpCapturaDatosGenerales::SlotFocoANacionalidad()
{
  zSiscomQt3::Foco(QLENacionalidad);
}
void QtImpCapturaDatosGenerales::SlotRegistrar()
{
  if(Registrando())
  {
  SiscomRegistroLog2(zDatGenerales);
  QPBAceptar->setEnabled(true); 
  QPBRegistrar->setEnabled(false);
  zSiscomQt3::Foco(QPBAceptar);
  }
}
void QtImpCapturaDatosGenerales::SlotAceptar()
{
	intAceptar = 1;
	done(1);
}
void QtImpCapturaDatosGenerales::SlotCancelar()
{
	intAceptar = 0;
	done(1);
}
void QtImpCapturaDatosGenerales::reject()
{

}
int QtImpCapturaDatosGenerales::Aceptar()
{
  return intAceptar;
}

void QtImpCapturaDatosGenerales::IniciaControles()
{

}
void QtImpCapturaDatosGenerales::AsignaPersonales()
{
const char *lchrPtrFechaNacimiento=strdup((const char *)QLEFechaNacimiento->text());
  zDatGenerales=new zDatosGenerales(zConBeneficios->IdCliente());
  zDatGenerales->CURP(zSiscomQt3::Texto(QLECurp));
  zDatGenerales->EstadoNacimiento(zSiscomQt3::Texto(QLEEstadoNacimiento));
  zDatGenerales->PaisNacimiento(zSiscomQt3::Texto(QLEPaisNacimiento));
  zDatGenerales->Genero(Sexo());
  zDatGenerales->EstadoCivil(EstadoCivil());
  zDatGenerales->Edad(zSiscomQt3::Texto(QLEEdad));
  zDatGenerales->FechaNacimiento(lchrPtrFechaNacimiento);
  zDatGenerales->Identificacion(zSiscomQt3::Texto(QLEIdentificacion));
  zDatGenerales->NoIdentificacion(zSiscomQt3::Texto(QLENoIdentificacion));
  zDatGenerales->Ocupacion(zSiscomQt3::Texto(QLEOcupacion));
  zDatGenerales->Nacionalidad(zSiscomQt3::Texto(QLENacionalidad));
  zConBeneficios->Generales(zDatGenerales);
}
int QtImpCapturaDatosGenerales::Registrando()
{
   AsignaPersonales();
   if(Registra())
   {
   return 1;
   }
   else 
   return 0;
}
int QtImpCapturaDatosGenerales::Actualizando()
{
   AsignaPersonales();
   if(Actualiza())
   {
   return 1;
   }
   else 
   return 0;
}

int QtImpCapturaDatosGenerales::Registra()
{
zOperacionesServiSNTE lzOpServiSNTE(zSisConexion,"RegistraGenerales");
return lzOpServiSNTE.RegistraGenerales(zDatGenerales);
}

int QtImpCapturaDatosGenerales::Actualiza()
{
zOperacionesServiSNTE lzOpServiSNTE(zSisConexion,"ActualizaGenerales");
return lzOpServiSNTE.RegistraGenerales(zDatGenerales);
}
const char *QtImpCapturaDatosGenerales::Sexo()
{
   if(QRBMasculino->isChecked())
   return "Masculino";
   else
   if(QRBFemenino->isChecked())
   return "Femenino";
}
const char *QtImpCapturaDatosGenerales::EstadoCivil()
{
  if(QRBCasado->isChecked())
  return "Casado";
  else
  if(QRBSoltero->isChecked())
  return "Soltero";
}

void QtImpCapturaDatosGenerales::MuestraDatos()
{
    QLERFCHomoclave->setText(zConBeneficios->RFC()); 
    QLECurp->setText(zConBeneficios->CURP());
    QLEEstadoNacimiento->setText(zConBeneficios->EstadoNacimiento());
    QLEPaisNacimiento->setText(zConBeneficios->PaisNacimiento());
    QLEEdad->setText(zConBeneficios->Edad());
    QLEFechaNacimiento->setText(zConBeneficios->FechaNacimiento());
    QLEIdentificacion->setText(zConBeneficios->Identificacion());
    QLENoIdentificacion->setText(zConBeneficios->NoIdentificacion());
    QLEOcupacion->setText(zConBeneficios->Ocupacion());
    QLENacionalidad->setText(zConBeneficios->Nacionalidad());
    if(strcmp(zConBeneficios->Genero(),"Masculino")==0)
        QRBMasculino->setDown(true);
    else
        QRBFemenino->setDown(true);
    if(strcmp(zConBeneficios->EstadoCivil(),"Casado")==0)
        QRBCasado->setDown(true);
    else
        QRBSoltero->setDown(true);
}
void QtImpCapturaDatosGenerales::HabilitaRegistrar()
{
QPBRegistrar->setEnabled(!((*zConBeneficios->RFC()) 			&&
                           (*zConBeneficios->CURP()) 			&&
			   (*zConBeneficios->EstadoNacimiento()) 	&&
			   (*zConBeneficios->PaisNacimiento())   	&&
			   (*zConBeneficios->Edad())			&&
			   (*zConBeneficios->FechaNacimiento())		&&
			   (*zConBeneficios->Identificacion())		&&
			   (*zConBeneficios->NoIdentificacion())	&&
			   (*zConBeneficios->Ocupacion())		&&
			   (*zConBeneficios->Nacionalidad()) ));

}
