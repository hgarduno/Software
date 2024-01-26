#include <QtImpCapturaDatosEmpleo.h>

#include <QCtrlFrecuenciaPagosSS.h>

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
#include <zEmpresa.h>
#include <zTelefonos.h>
#include <zEmpleo.h>
#include <zCorreo.h>
#include <zOtrosIngresos.h>


#include <zOperacionesServiSNTE.h>
#include <qpushbutton.h>
#include <qlineedit.h>
#include <qtextedit.h> 
QtImpCapturaDatosEmpleo::QtImpCapturaDatosEmpleo(
				     zContratoBeneficios *pzConBeneficios, 	
				     QWidget *pQWParent,
				     const char *pchrPtrName,
				     bool pbModal,
				     WFlags pWFlags):
				     CapturaDatosEmpleo(pQWParent,pchrPtrName,pbModal,pWFlags),
				     zConBeneficios(pzConBeneficios),
				     zEmpresaA(0),
				     zPerJefe(0)
{
 
 Conexion((zSiscomConexion *)gzSiscomConexion);
 IniciaVariables();
 IniciaControles();
 ConectaSlots();
 exec();
}

void QtImpCapturaDatosEmpleo::Conexion(zSiscomConexion *pzSisConexion)
{
	zSisConexion=pzSisConexion;
}

void QtImpCapturaDatosEmpleo::ConectaSlots()
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
	//Slots Pasando Foco{

	connect(QLENombreEmpresa,
		SIGNAL(returnPressed()),
		SLOT(SlotFocoAAntiguedad()));
	connect(QLEAntiguedad,
		SIGNAL(returnPressed()),
		SLOT(SlotFocoAPuestoActual()));
	connect(QLEPuesto,
		SIGNAL(returnPressed()),
		SLOT(SlotFocoAActividadGiro()));
	connect(QLEActGiroEmpresa,
		SIGNAL(returnPressed()),
		SLOT(SlotFocoANombre()));
	connect(QLENombre,
		SIGNAL(returnPressed()),
		SLOT(SlotFocoAAPaterno()));
	connect(QLEAPaterno,
		SIGNAL(returnPressed()),
		SLOT(SlotFocoAAMaterno()));
	connect(QLEAMaterno,
		SIGNAL(returnPressed()),
		SLOT(SlotFocoACalle()));
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
		SLOT(SlotFocoADelegacion()));
	connect(QLEDelegacionMunicipio,
		SIGNAL(returnPressed()),
		SLOT(SlotFocoAEstado()));
	connect(QLEEstado,
		SIGNAL(returnPressed()),
		SLOT(SlotFocoACodigoPostal()));
	connect(QLECodigoPostal,
		SIGNAL(returnPressed()),
		SLOT(SlotFocoAPais()));
	connect(QLEPais,
		SIGNAL(returnPressed()),
		SLOT(SlotFocoATelefono()));
	connect(QLETelefono,
		SIGNAL(returnPressed()),
		SLOT(SlotFocoAExtension()));
	connect(QLEExtension,
		SIGNAL(returnPressed()),
		SLOT(SlotFocoACorreoElectronico()));
	connect(QLECorreoElectronico,
		SIGNAL(returnPressed()),
		SLOT(SlotFocoASueldo()));
	connect(QLESueldo,
		SIGNAL(returnPressed()),
		SLOT(SlotFocoAFrecuenciaPago()));
	connect(QCtrFrecuenciaPago,
		SIGNAL(SignalFrecunciaPago(zSiscomRegistro *)),
		SLOT(SlotFrecuenciaPago(zSiscomRegistro *)));
	connect(QLEOtrosIngresos,
		SIGNAL(returnPressed()),
		SLOT(SlotFocoAEspecificaOIngresos()));
	connect(QLEEspecificacionIngresos,
		SIGNAL(returnPressed()),
		SLOT(SlotFocoATotalIngresos()));
	connect(QLETotalIngresos,
		SIGNAL(returnPressed()),
		SLOT(SlotFocoARegistrar()));
	//}
	connect(QPBActualizar,
		SIGNAL(clicked()),
		SLOT(SlotActualizar()));
}
void QtImpCapturaDatosEmpleo::SlotActualizar()
{
   if(Actualizando())
   {
	
   }
}
void QtImpCapturaDatosEmpleo::SlotFocoARegistrar()
{
   zSiscomQt3::Foco(QPBRegistrar);
}
void QtImpCapturaDatosEmpleo::SlotRegistrar()
{
     Registrando();
     QPBAceptar->setEnabled(true);
     QPBRegistrar->setEnabled(false);
     zSiscomQt3::Foco(QPBAceptar);   
}
void QtImpCapturaDatosEmpleo::SlotFocoAAceptar()
{
	zSiscomQt3::Foco(QPBAceptar);
}
void QtImpCapturaDatosEmpleo::SlotFocoAAntiguedad()
{
   if(ValidaEmpresaRegistrada())  
   {
	MuestraDatosEmpresaRegistrada();
   }
   zSiscomQt3::Foco(QLEAntiguedad);
}

void QtImpCapturaDatosEmpleo::SlotFocoAPuestoActual()
{
   zSiscomQt3::Foco(QLEPuesto);
}
void QtImpCapturaDatosEmpleo::SlotFocoAActividadGiro()
{
   zSiscomQt3::Foco(QLEActGiroEmpresa);
}
void QtImpCapturaDatosEmpleo::SlotFocoANombre()
{
   zSiscomQt3::Foco(QLENombre);
}
void QtImpCapturaDatosEmpleo::SlotFocoAAPaterno()
{
   zSiscomQt3::Foco(QLEAPaterno);
}
void QtImpCapturaDatosEmpleo::SlotFocoAAMaterno()
{
   zSiscomQt3::Foco(QLEAMaterno);
}
void QtImpCapturaDatosEmpleo::SlotFocoACalle()
{
  if(ValidaJefeRegistrado())
  {
	LogSiscom("Jefe Ya Registrado");
  }
   zSiscomQt3::Foco(QLECalle);
}
void QtImpCapturaDatosEmpleo::SlotFocoANoExterior()
{
   zSiscomQt3::Foco(QLENoExterior);
}
void QtImpCapturaDatosEmpleo::SlotFocoANoInterior()
{
   zSiscomQt3::Foco(QLENoInterior);
}
void QtImpCapturaDatosEmpleo::SlotFocoAColonia()
{
   zSiscomQt3::Foco(QLEColonia);
}
void QtImpCapturaDatosEmpleo::SlotFocoADelegacion()
{
   zSiscomQt3::Foco(QLEDelegacionMunicipio);
}
void QtImpCapturaDatosEmpleo::SlotFocoAEstado()
{
   zSiscomQt3::Foco(QLEEstado);
}
void QtImpCapturaDatosEmpleo::SlotFocoACodigoPostal()
{
   zSiscomQt3::Foco(QLECodigoPostal);
}
void QtImpCapturaDatosEmpleo::SlotFocoAPais()
{
   zSiscomQt3::Foco(QLEPais);
}
void QtImpCapturaDatosEmpleo::SlotFocoATelefono()
{
   zSiscomQt3::Foco(QLETelefono);
}
void QtImpCapturaDatosEmpleo::SlotFocoAExtension()
{
   zSiscomQt3::Foco(QLEExtension);
}
void QtImpCapturaDatosEmpleo::SlotFocoACorreoElectronico()
{
   zSiscomQt3::Foco(QLECorreoElectronico);
}
void QtImpCapturaDatosEmpleo::SlotFocoASueldo()
{
   zSiscomQt3::Foco(QLESueldo);
}

void QtImpCapturaDatosEmpleo::SlotFocoAOtrosIngresos()
{
   zSiscomQt3::Foco(QLEOtrosIngresos);
}


void QtImpCapturaDatosEmpleo::SlotFocoAEspecificaOIngresos()
{
   zSiscomQt3::Foco(QLEEspecificacionIngresos);
}
void QtImpCapturaDatosEmpleo::SlotFocoATotalIngresos()
{
   zSiscomQt3::Foco(QLETotalIngresos);
}
void QtImpCapturaDatosEmpleo::SlotFrecuenciaPago(zSiscomRegistro *pzSisRegFrecPago)
{
	zSisRegFrecPago=pzSisRegFrecPago;
	zSiscomQt3::Foco(QLEOtrosIngresos);
}
void QtImpCapturaDatosEmpleo::SlotFocoAFrecuenciaPago()
{
	zSiscomQt3::Foco(QCtrFrecuenciaPago);
}
void QtImpCapturaDatosEmpleo::SlotAceptar()
{
	intAceptar = 1;
	done(1);
}
void QtImpCapturaDatosEmpleo::SlotCancelar()
{
	intAceptar = 0;
	done(1);
}
void QtImpCapturaDatosEmpleo::reject()
{

}
int QtImpCapturaDatosEmpleo::Aceptar()
{
  return intAceptar;
}

void QtImpCapturaDatosEmpleo::IniciaControles()
{
QCtrFrecuenciaPago->Servidor(zSisConexion);
QCtrFrecuenciaPago->IniciaControl();
}
void QtImpCapturaDatosEmpleo::IniciaVariables()
{
    zSiscomQt3::Foco(QLENombreEmpresa);
    QLEOtrosIngresos->setText("0");
    QLEEspecificacionIngresos->setText("");
    QLETotalIngresos->setText("0");
    MuestraDatos();
}
void QtImpCapturaDatosEmpleo::OtrosIngresos()
{
zOtrosIngresos *lzOtrosIng=new zOtrosIngresos(zConBeneficios->IdCliente());
   lzOtrosIng->Monto(zSiscomQt3::Texto(QLEOtrosIngresos));
   lzOtrosIng->Descripcion(zSiscomQt3::Texto(QLEEspecificacionIngresos));
   zEmpActual->OtrosIngresos(lzOtrosIng);
}
void QtImpCapturaDatosEmpleo::Direccion(zEmpresa *pzEmpresa)
{
zDireccion *lzDirEmpresa;
    lzDirEmpresa=new zDireccion("",
    				 zSiscomQt3::Texto(QLECalle),
    				 zSiscomQt3::Texto(QLENoExterior),
    				 zSiscomQt3::Texto(QLENoInterior),
    				 zSiscomQt3::Texto(QLEColonia),
    				 zSiscomQt3::Texto(QLEDelegacionMunicipio),
    				 zSiscomQt3::Texto(QLEEstado),
    				 zSiscomQt3::Texto(QLECodigoPostal),
				 "",
    				 "");
pzEmpresa->Direccion(lzDirEmpresa);
}
void QtImpCapturaDatosEmpleo::Jefe(zEmpresa *pzEmpresa)
{
zPersona *lzPerJefe;
if(!zPerJefe)
{
    lzPerJefe=new zPersona("",
    		 	  zSiscomQt3::Texto(QLENombre),
    		 	  zSiscomQt3::Texto(QLEAPaterno),
    		 	  zSiscomQt3::Texto(QLEAMaterno),
			  "");
}
else
{
LogSiscom("El Jefe ya esta registrado");
lzPerJefe=zPerJefe;
}
zEmpActual->Jefe(lzPerJefe);
}
void QtImpCapturaDatosEmpleo::DatosEmpresa(zEmpresa *pzEmpresa)
{
zTelefonos *lzTelefono;
zCorreo *lzCorreo=new zCorreo;;
lzTelefono=new zTelefonos;
    lzCorreo->Correo(zSiscomQt3::Texto(QLECorreoElectronico));
    lzCorreo->Descripcion("Correo Corporativo");
    lzTelefono->AgregaTelefono("",
    				"Contacto Empleo",
    				zSiscomQt3::Texto(QLETelefono),
			       zSiscomQt3::Texto(QLEExtension));
    pzEmpresa->RazonSocial(zSiscomQt3::Texto(QLENombreEmpresa));
    pzEmpresa->Giro(zSiscomQt3::Texto(QLEActGiroEmpresa));
    pzEmpresa->Telefonos(lzTelefono);
    pzEmpresa->Correos(lzCorreo);
}
void QtImpCapturaDatosEmpleo::Empleo()
{
    zEmpActual->Puesto(zSiscomQt3::Texto(QLEPuesto));
    zEmpActual->Sueldo(zSiscomQt3::Texto(QLESueldo));
    zEmpActual->Antiguedad(zSiscomQt3::Texto(QLEAntiguedad));
    zEmpActual->FrecuenciaPago(zSisRegFrecPago);
}
void QtImpCapturaDatosEmpleo::AnexaDatosGenerales()
{
zEmpresa *lzEmpresa;
zEmpActual=new zEmpleo(zConBeneficios->IdCliente());
if(!zEmpresaA)
{
lzEmpresa=new zEmpresa;
Direccion(lzEmpresa);
DatosEmpresa(lzEmpresa);
}
else
lzEmpresa=zEmpresaA;
	Empleo();
	Jefe(lzEmpresa);
	OtrosIngresos();
	zEmpActual->Empresa(lzEmpresa);
	zConBeneficios->Empleo(zEmpActual);
}
int QtImpCapturaDatosEmpleo::Registra()
{
zOperacionesServiSNTE lzOpServiSNTE(zSisConexion,"RegistraEmpleo");
return lzOpServiSNTE.RegistraEmpleo(zEmpActual);
}
int QtImpCapturaDatosEmpleo::Registrando()
{
   AnexaDatosGenerales();
   return Registra();
}

void QtImpCapturaDatosEmpleo::MuestraDatos()
{
    QLENombreEmpresa->setText(zConBeneficios->Empresa());
    QLEAntiguedad->setText(zConBeneficios->Antiguedad());
    QLEPuesto->setText(zConBeneficios->Puesto());
    QLEActGiroEmpresa->setText(zConBeneficios->Giro());
    QLENombre->setText(zConBeneficios->NombreJefe());
    QLEAPaterno->setText(zConBeneficios->APaternoJefe());
    QLEAMaterno->setText(zConBeneficios->AMaternoJefe());
    QLECalle->setText(zConBeneficios->CalleEmpleo());
    QLENoExterior->setText(zConBeneficios->NumExteriorEmpleo());
    QLENoInterior->setText(zConBeneficios->NumInteriorEmpleo());
    QLEColonia->setText(zConBeneficios->ColoniaEmpleo());
    QLEDelegacionMunicipio->setText(zConBeneficios->DelegacionEmpleo());
    QLEEstado->setText(zConBeneficios->EstadoEmpleo());
    QLECodigoPostal->setText(zConBeneficios->CodigoPostalEmpleo());
    QLEPais->setText((const char *)"Mexico");
    QLETelefono->setText(zConBeneficios->TelefonoEmpleo());
    QLEExtension->setText(zConBeneficios->ExtensionEmpleo());
    QLECorreoElectronico->setText(zConBeneficios->CorreoEmpleo());
    QLESueldo->setText(zConBeneficios->Sueldo());
    //QCtrFrecuenciaPago->setCurrentText(zConBeneficios->FrecuenciaPago());
    QLEOtrosIngresos->setText(zConBeneficios->OtrosIngresosMonto());
    QLEEspecificacionIngresos->setText(zConBeneficios->OtrosIngresosDescripcion());
    QLETotalIngresos->setText(zConBeneficios->OtrosIngresosMonto());
}

int QtImpCapturaDatosEmpleo::ValidaEmpresaRegistrada()
{
zOperacionesServiSNTE lzOpeServiSNTE(zSisConexion,"EmpresaRegistrada");
if((zEmpresaA=lzOpeServiSNTE.EmpresaRegistrada(zSiscomQt3::Texto(QLENombreEmpresa))))
return 1;
else 
return 0;

}
void QtImpCapturaDatosEmpleo::MuestraDatosEmpresaRegistrada()
{
  MuestraDireccionEmpresaRegistrada();
  MuestraTelefonoEmpresaRegistrada();
  MuestraCorreosEmpresaRegistrada();
  MuestraGiroEmpresaRegistrada();
}
void QtImpCapturaDatosEmpleo::MuestraDireccionEmpresaRegistrada()
{
if(zEmpresaA->Direccion())
{
  QLECalle->setText(zEmpresaA->Direccion()->Calle());
  QLENoExterior->setText(zEmpresaA->Direccion()->NumExterior());
  QLENoInterior->setText(zEmpresaA->Direccion()->NumInterior());
  QLEColonia->setText(zEmpresaA->Direccion()->Colonia());
  QLEDelegacionMunicipio->setText(zEmpresaA->Direccion()->Delegacion());
  QLEEstado->setText(zEmpresaA->Direccion()->Estado());
  QLECodigoPostal->setText(zEmpresaA->Direccion()->CodigoPostal());
}

}
void QtImpCapturaDatosEmpleo::MuestraTelefonoEmpresaRegistrada()
{
 if(zEmpresaA->Telefonos())
 {
   QLETelefono->setText(zEmpresaA->Telefonos()->Telefono());	
 }
}
void QtImpCapturaDatosEmpleo::MuestraCorreosEmpresaRegistrada()
{
   if(zEmpresaA->Correo())
   {
	QLECorreoElectronico->setText(zEmpresaA->Correo()->Correo());
   }
}
void QtImpCapturaDatosEmpleo::MuestraGiroEmpresaRegistrada()
{
QLEActGiroEmpresa->setText(zEmpresaA->Giro());
}

int QtImpCapturaDatosEmpleo::ValidaJefeRegistrado()
{
zOperacionesServiSNTE lzOpeServiSNTE(zSisConexion,"PersonaRegistrada");
if((zPerJefe=lzOpeServiSNTE.PersonaRegistrada(zSiscomQt3::Texto(QLENombre),
				zSiscomQt3::Texto(QLEAPaterno),
				zSiscomQt3::Texto(QLEAMaterno))))
{
  return 1;
}
else
return 0;
}
void QtImpCapturaDatosEmpleo::ActualizaJefe()
{
  if(zConBeneficios->Empleo()->Jefe())
  {
	zConBeneficios->Empleo()->Jefe()->Nombre(zSiscomQt3::Texto(QLENombre));
	zConBeneficios->Empleo()->Jefe()->APaterno(zSiscomQt3::Texto(QLEAPaterno));
	zConBeneficios->Empleo()->Jefe()->AMaterno(zSiscomQt3::Texto(QLEAMaterno));
  }
}
void QtImpCapturaDatosEmpleo::ActualizaEmpleo()
{
if(zConBeneficios->Empleo())
{
zConBeneficios->Empleo()->Puesto(zSiscomQt3::Texto(QLEPuesto));
zConBeneficios->Empleo()->Sueldo(zSiscomQt3::Texto(QLESueldo));
zConBeneficios->Empleo()->Antiguedad(zSiscomQt3::Texto(QLEAntiguedad));
}
}
void QtImpCapturaDatosEmpleo::ActualizaEmpresa()
{
if(zConBeneficios->Empleo()->Empresa())
{
zConBeneficios->Empleo()->Empresa()->RazonSocial(zSiscomQt3::Texto(QLENombreEmpresa));
zConBeneficios->Empleo()->Empresa()->Giro(zSiscomQt3::Texto(QLEActGiroEmpresa));
zConBeneficios->Empleo()->Empresa()->Direccion()->Calle(zSiscomQt3::Texto(QLECalle));
zConBeneficios->Empleo()->Empresa()->Direccion()->NumExterior(zSiscomQt3::Texto(QLENoExterior));
zConBeneficios->Empleo()->Empresa()->Direccion()->NumInterior(zSiscomQt3::Texto(QLENoInterior));
zConBeneficios->Empleo()->Empresa()->Direccion()->Colonia(zSiscomQt3::Texto(QLEColonia));
zConBeneficios->Empleo()->Empresa()->Direccion()->Delegacion(zSiscomQt3::Texto(QLEDelegacionMunicipio));
zConBeneficios->Empleo()->Empresa()->Direccion()->Estado(zSiscomQt3::Texto(QLEEstado));
zConBeneficios->Empleo()->Empresa()->Direccion()->CodigoPostal(zSiscomQt3::Texto(QLECodigoPostal));
}
}
void QtImpCapturaDatosEmpleo::ActualizaComunicacion()
{
if(zConBeneficios->Empleo()->Empresa()->Telefonos())
{
zConBeneficios->Empleo()->Empresa()->Telefonos()->ActualizaPorDescripcion("Contacto Empleo",zSiscomQt3::Texto(QLETelefono));
}

}
int QtImpCapturaDatosEmpleo::Actualiza()
{
zOperacionesServiSNTE lzOpServiSNTE(zSisConexion,"ActualizaEmpleo");
SiscomRegistroLog2(zConBeneficios->Empleo());
return lzOpServiSNTE.RegistraEmpleo(zConBeneficios->Empleo());
}
int QtImpCapturaDatosEmpleo::Actualizando()
{
 ActualizaJefe();
 ActualizaEmpleo();
 ActualizaEmpresa();
 ActualizaComunicacion();
  return Actualiza();
}
