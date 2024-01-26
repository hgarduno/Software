#include <QtImpCapturaDatosComplementarios.h>

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
#include <zContratoBeneficios.h>
#include <zReferenciasPersonales.h>
#include <zDireccion.h>
#include <zPersona.h>
#include <zParentesco.h>
#include <zTelefonos.h>

#include <zCargoPublico.h>
#include <zOperacionesServiSNTE.h>
#include <qpushbutton.h>
#include <qlineedit.h>
#include <qtextedit.h> 
#include <qbuttongroup.h>
#include <qtabwidget.h>
#include <qtable.h>
#include <qmessagebox.h>
QtImpCapturaDatosComplementarios::QtImpCapturaDatosComplementarios(
				     zContratoBeneficios *pzContratoBeneficios,
				     QWidget *pQWParent,
				     const char *pchrPtrName,
				     bool pbModal,
				     WFlags pWFlags):
				     CapturaDatosComplementarios(pQWParent,
				     				 pchrPtrName,
								 pbModal,
								 pWFlags),
				     zConBeneficios(pzContratoBeneficios),
				     zPerReferencia(0),
				     intAceptar(0)
{
 Conexion((zSiscomConexion *)gzSiscomConexion);
 IniciaVariables();
 IniciaControles();
 ConectaSlots();
 ConectaSlotsReferencias();
 exec();
}

void QtImpCapturaDatosComplementarios::Conexion(zSiscomConexion *pzSisConexion)
{
	zSisConexion=pzSisConexion;
}

void QtImpCapturaDatosComplementarios::ConectaSlots()
{
	connect(QPBAceptar,
		SIGNAL(clicked()),
		SLOT(SlotAceptar()));
	connect(QPBCancelar,
		SIGNAL(clicked()),
		SLOT(SlotCancelar()));
	connect(QGBCargoPublico,
		SIGNAL(clicked(int)),
		SLOT(SlotFocoAEspecificar()));
	connect(QLEEspecifica,
		SIGNAL(returnPressed()),
		SLOT(SlotFocoADependencia()));
	connect(QLEDependencia,
		SIGNAL(returnPressed()),
		SLOT(SlotFocoAPuesto()));
	connect(QLEPuesto,
		SIGNAL(returnPressed()),
		SLOT(SlotFocoAFunciones()));
	connect(QLEFunciones,
		SIGNAL(returnPressed()),
		SLOT(SlotFocoAPeriodo()));
	connect(QLEPeriodo,
		SIGNAL(returnPressed()),
		SLOT(SlotFocoAAceptar()));
	connect(QLEPeriodo,
		SIGNAL(returnPressed()),
		SLOT(SlotFocoARegistrar()));
	connect(QGBCargoPublico,
		SIGNAL(clicked(int)),
		SLOT(SlotCargoPublico(int)));
	connect(QGBBeneficios,
		SIGNAL(clicked(int)),
		SLOT(SlotBeneficios(int)));
	connect(QGBAportaTercero,
		SIGNAL(clicked(int)),
		SLOT(SlotAportaTercero(int)));
	connect(QPBRegistrar,
		SIGNAL(clicked()),
		SLOT(SlotRegistrar()));

	connect(QTWComplementarios,
		SIGNAL(currentChanged(QWidget *)),
		SLOT(SlotCambioPagina(QWidget *)));
}
void QtImpCapturaDatosComplementarios::ConectaSlotsReferencias()
{
  connect(QLEApellidoPaterno,
  	  SIGNAL(returnPressed()),
	  SLOT(SlotFocoAAMaterno()));
  connect(QLEApellidoMaterno,
  	  SIGNAL(returnPressed()),
	  SLOT(SlotFocoANombre()));
  connect(QLENombres,
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
	  SLOT(SlotFocoATelefono()));
  connect(QLETelefono,
  	  SIGNAL(returnPressed()),
	  SLOT(SlotFocoAParentesco()));
  connect(QLEParentesco,
  	  SIGNAL(returnPressed()),
	  SLOT(SlotFocoAAgregarReferencia()));
  connect(QPBAgregaReferencia,
  	  SIGNAL(clicked()),
	  SLOT(SlotAgregarReferencia()));

   connect(QLEApellidoPaterno,
   	   SIGNAL(textChanged(const QString &)),
	   SLOT(SlotCambioTextoEdit(const QString &)));

    ConectaEditValidacionAgregar(QLEApellidoPaterno);
    ConectaEditValidacionAgregar(QLEApellidoMaterno);
    ConectaEditValidacionAgregar(QLENombres);
    ConectaEditValidacionAgregar(QLECalle);
    ConectaEditValidacionAgregar(QLENoExterior);
    ConectaEditValidacionAgregar(QLEColonia);
    ConectaEditValidacionAgregar(QLEDelegacionMunicipio);
    ConectaEditValidacionAgregar(QLEEstado);
    ConectaEditValidacionAgregar(QLECodigoPostal);
    ConectaEditValidacionAgregar(QLETelefono);
}
void QtImpCapturaDatosComplementarios::SlotCambioTextoEdit(const QString &)
{
  QPBAgregaReferencia->setEnabled(DatosMinimosReferencia());
}
void QtImpCapturaDatosComplementarios::SlotFocoAParentesco()
{
  zSiscomQt3::Foco(QLEParentesco);
  QPBAgregaReferencia->setEnabled(DatosMinimosReferencia());
}
void QtImpCapturaDatosComplementarios::SlotFocoATelefono()
{
	zSiscomQt3::Foco(QLETelefono);
  QPBAgregaReferencia->setEnabled(DatosMinimosReferencia());
}
void QtImpCapturaDatosComplementarios::SlotAgregarReferencia()
{
  AgregaReferenciaPersonal(); 
  MuestraReferencias();
  if(zPerReferencia)
  {
  LogSiscom("Ahora las referencias ...");
  //HabilitaDesHabilita(0);
  zPerReferencia=0;
  zSiscomQt3::Foco(QLEApellidoPaterno);
  }
  QPBRegistrar->setEnabled(true);
}
void QtImpCapturaDatosComplementarios::SlotFocoAAgregarReferencia()
{
   zSiscomQt3::Foco(QPBAgregaReferencia);

}
void QtImpCapturaDatosComplementarios::SlotFocoAAPaterno()
{
   zSiscomQt3::Foco(QLEApellidoPaterno);
  QPBAgregaReferencia->setEnabled(DatosMinimosReferencia());
}

void QtImpCapturaDatosComplementarios::SlotFocoAAMaterno()
{
   zSiscomQt3::Foco(QLEApellidoMaterno);
  QPBAgregaReferencia->setEnabled(DatosMinimosReferencia());
}
void QtImpCapturaDatosComplementarios::SlotFocoANombre()
{
   zSiscomQt3::Foco(QLENombres);
  QPBAgregaReferencia->setEnabled(DatosMinimosReferencia());
}
void QtImpCapturaDatosComplementarios::SlotFocoACalle()
{
   if(ValidaPersonaRegistrada())
   {
   HabilitaControlesPersonaRegistrada();
   MuestraDatosPersonaRegistrada();
   HabilitaDesHabilita(1);
   }
   else
   zSiscomQt3::Foco(QLECalle);
}
void QtImpCapturaDatosComplementarios::SlotFocoANoExterior()
{
   zSiscomQt3::Foco(QLENoExterior);
  QPBAgregaReferencia->setEnabled(DatosMinimosReferencia());
}
void QtImpCapturaDatosComplementarios::SlotFocoANoInterior()
{
   zSiscomQt3::Foco(QLENoInterior);
  QPBAgregaReferencia->setEnabled(DatosMinimosReferencia());
}
void QtImpCapturaDatosComplementarios::SlotFocoAColonia()
{
  zSiscomQt3::Foco(QLEColonia);
  QPBAgregaReferencia->setEnabled(DatosMinimosReferencia());
}
void QtImpCapturaDatosComplementarios::SlotFocoADelegacion()
{
   zSiscomQt3::Foco(QLEDelegacionMunicipio);
  QPBAgregaReferencia->setEnabled(DatosMinimosReferencia());
}
void QtImpCapturaDatosComplementarios::SlotFocoAEstado()
{
   zSiscomQt3::Foco(QLEEstado);
  QPBAgregaReferencia->setEnabled(DatosMinimosReferencia());
}
void QtImpCapturaDatosComplementarios::SlotFocoACodigoPostal()
{
   zSiscomQt3::Foco(QLECodigoPostal);
  QPBAgregaReferencia->setEnabled(DatosMinimosReferencia());
}
void QtImpCapturaDatosComplementarios::SlotFocoARegistrar()
{
  zSiscomQt3::Foco(QPBRegistrar);
  QPBAgregaReferencia->setEnabled(DatosMinimosReferencia());
}
void QtImpCapturaDatosComplementarios::SlotCambioPagina(QWidget *)
{
	intPaginaActiva=QTWComplementarios->currentPageIndex();
	LogSiscom("La Pagina Activa es %d",intPaginaActiva);
	switch(intPaginaActiva)
	{
	   case 2:
     		zSiscomQt3::Foco(QLEApellidoPaterno);
	   break;
	}
	   	

}
void QtImpCapturaDatosComplementarios::SlotRegistrar()
{
    if(intPaginaActiva==0)
     Registrando();
     else
     if(intPaginaActiva==2)
     {
     RegistrandoReferenciasPersonales();
     }
   
   QPBRegistrar->setEnabled(false);
   QPBAceptar->setEnabled(true);

}
void QtImpCapturaDatosComplementarios::SlotAportaTercero(int pintSiNo)
{
   HabilitaAportacionTercero(!pintSiNo);
   zSiscomQt3::Foco(QLEAportaTercero);
}
void QtImpCapturaDatosComplementarios::SlotBeneficios(int pintBeneficios)
{
 HabilitaBeneficios(!pintBeneficios);
 zSiscomQt3::Foco(QLENombreBeneficiado);
}
void QtImpCapturaDatosComplementarios::SlotCargoPublico(int pintSiNo)
{
   HabilitaCargoPublico(!pintSiNo);
   zSiscomQt3::Foco(QLEEspecifica);
}
void QtImpCapturaDatosComplementarios::SlotFocoADependencia()
{
zSiscomQt3::Foco(QLEDependencia);
}

void QtImpCapturaDatosComplementarios::SlotFocoAPuesto()
{
zSiscomQt3::Foco(QLEPuesto);
}
void QtImpCapturaDatosComplementarios::SlotFocoAPeriodo()
{
zSiscomQt3::Foco(QLEPeriodo);
}
void QtImpCapturaDatosComplementarios::SlotFocoAFunciones()
{
zSiscomQt3::Foco(QLEFunciones);
}
void QtImpCapturaDatosComplementarios::SlotFocoAAceptar()
{
zSiscomQt3::Foco(QPBAceptar);
}
void QtImpCapturaDatosComplementarios::SlotFocoAEspecificar()
{
	zSiscomQt3::Foco(QLEEspecifica);
}
void QtImpCapturaDatosComplementarios::SlotAceptar()
{
	intAceptar = 1;
	done(1);
}
void QtImpCapturaDatosComplementarios::SlotCancelar()
{
	intAceptar = 0;
	done(1);
}
void QtImpCapturaDatosComplementarios::reject()
{

}
int QtImpCapturaDatosComplementarios::Aceptar()
{
  return intAceptar;
}

void QtImpCapturaDatosComplementarios::IniciaVariables()
{
  	zRefsPersonales=new zReferenciasPersonales(zConBeneficios->IdCliente()); 
}
void QtImpCapturaDatosComplementarios::IniciaControles()
{

}
void QtImpCapturaDatosComplementarios::HabilitaCargoPublico(int pintHabilita)
{
QLEEspecifica->setEnabled(pintHabilita);
QLEDependencia->setEnabled(pintHabilita);
QLEPuesto->setEnabled(pintHabilita);
QLEFunciones->setEnabled(pintHabilita);
QLEPeriodo->setEnabled(pintHabilita);
}
void QtImpCapturaDatosComplementarios::HabilitaBeneficios(int pintBeneficios)
{
QLENombreBeneficiado->setEnabled(pintBeneficios);
}
void QtImpCapturaDatosComplementarios::HabilitaAportacionTercero(int pintSiNo)
{
QLEAportaTercero->setEnabled(pintSiNo);
}
void QtImpCapturaDatosComplementarios::CargoPublico()
{
zCarPublico=new zCargoPublico(zConBeneficios->IdCliente());
zCarPublico->Descripcion(zSiscomQt3::Texto(QLEEspecifica));
zCarPublico->Dependencia(zSiscomQt3::Texto(QLEDependencia));
zCarPublico->Puesto(zSiscomQt3::Texto(QLEPuesto));
zCarPublico->Funciones(zSiscomQt3::Texto(QLEFunciones));
zCarPublico->Periodo(zSiscomQt3::Texto(QLEPeriodo));
zConBeneficios->CargoPublico(zCarPublico);
}
int QtImpCapturaDatosComplementarios::Registra()
{
zOperacionesServiSNTE lzOperServiSNTE(zSisConexion,"RegistraCargoPublico");
return lzOperServiSNTE.RegistraCargoPublico(zCarPublico);
}
int QtImpCapturaDatosComplementarios::Registrando()
{
   AgregaDatos();
   if(Registra())
   {
     QPBAceptar->setEnabled(true);
     zSiscomQt3::Foco(QPBAceptar);
     QPBRegistrar->setEnabled(false);
     return 1;
   }
   else
   return 0;
}
void QtImpCapturaDatosComplementarios::AgregaDatos()
{
  CargoPublico();
}

void QtImpCapturaDatosComplementarios::AgregaReferenciaPersonal()
{
  AgregaDireccion();
  AgregaPersona();
  AgregaParentesco();
  AgregaTelefono();
}
void QtImpCapturaDatosComplementarios::AgregaDireccion()
{
zDireccion *lzDireccion;
if(!zPerReferencia)
lzDireccion=new zDireccion("",
			   zSiscomQt3::Texto(QLECalle),
			   zSiscomQt3::Texto(QLENoExterior),
			   zSiscomQt3::Texto(QLENoInterior),
			   zSiscomQt3::Texto(QLEColonia),
			   zSiscomQt3::Texto(QLEDelegacionMunicipio),
			   zSiscomQt3::Texto(QLEEstado),
			   zSiscomQt3::Texto(QLECodigoPostal),
			   "",
			   "");
else
lzDireccion=zPerReferencia->Direccion();
zRefsPersonales->Direccion(lzDireccion);
}
void QtImpCapturaDatosComplementarios::AgregaPersona()
{
zPersona *lzPersona;
if(!zPerReferencia)
lzPersona=new zPersona("",
			zSiscomQt3::Texto(QLENombres),
			zSiscomQt3::Texto(QLEApellidoPaterno),
			zSiscomQt3::Texto(QLEApellidoMaterno),
			"");
else
 lzPersona=zPerReferencia;
  zRefsPersonales->Nombre(lzPersona);
}
void QtImpCapturaDatosComplementarios::AgregaParentesco()
{
zParentesco *lzParentesco=new zParentesco;
 lzParentesco->Parentesco(strdup(zSiscomQt3::Texto(QLEParentesco)));	
 zRefsPersonales->Parentesco(lzParentesco);
}
void QtImpCapturaDatosComplementarios::AgregaTelefono()
{
zTelefonos *lzTelefono=new zTelefonos;
if(!zPerReferencia)
   lzTelefono->AgregaTelefono("","Referencia",zSiscomQt3::Texto(QLETelefono),"");
else
   lzTelefono->AgregaTelefono2(zPerReferencia->TelefonoParticular()); 
   zRefsPersonales->Telefonos(lzTelefono);
}
void QtImpCapturaDatosComplementarios::MuestraReferencias()
{
zSiscomRegistros *lzSisRegsDirecciones,
		 *lzSisRegsPersonas,
		 *lzSisRegsParentesco,
		 *lzSisRegsTelefonos;
zDireccion *lzDireccion;
zPersona *lzPersona;
zParentesco *lzParentesco;
zTelefonos *lzTelefono;
int lintContador;
lzSisRegsDirecciones=zRefsPersonales->Direcciones();
lzSisRegsPersonas=zRefsPersonales->Nombres();
lzSisRegsParentesco=zRefsPersonales->Parentescos();
lzSisRegsTelefonos=zRefsPersonales->Telefonos();
QTReferencias->setNumRows(lzSisRegsDirecciones->NNodos());
for(lintContador=0,
    lzPersona=(zPersona *)lzSisRegsPersonas->Primer(),
    lzDireccion=(zDireccion *)lzSisRegsDirecciones->Primer(),
    lzParentesco=(zParentesco *)lzSisRegsParentesco->Primer(),
    lzTelefono=(zTelefonos *)lzSisRegsTelefonos->Primer();
    lintContador<lzSisRegsDirecciones->NNodos();
    lintContador++,
    lzPersona=(zPersona *)lzSisRegsPersonas->Siguiente(),
    lzDireccion=(zDireccion *)lzSisRegsDirecciones->Siguiente(),
    lzParentesco=(zParentesco *)lzSisRegsParentesco->Siguiente(),
    lzTelefono=(zTelefonos *)lzSisRegsTelefonos->Siguiente())
{
 MuestraPersona(lintContador,lzPersona);
 MuestraDireccion(lintContador,lzDireccion);
 MuestraParentesco(lintContador,lzParentesco);
 MuestraTelefonos(lintContador,lzTelefono);
}
}
void QtImpCapturaDatosComplementarios::MuestraPersona(int pintFila,
						      zPersona *pzPersona)
{
char lchrArrPersona[128];
sprintf(lchrArrPersona,
	 "%s %s %s",
	 (const char *)(*pzPersona)["Nombre"],
	 (const char *)(*pzPersona)["APaterno"],
	 (const char *)(*pzPersona)["AMaterno"]);
QTReferencias->setText(pintFila,0,lchrArrPersona);

}
void QtImpCapturaDatosComplementarios::MuestraDireccion(int pintFila,
							zDireccion *pzDireccion)
{
char lchrArrDireccion[128];
sprintf(lchrArrDireccion,
	"%s %s Interior[%s], %s",
 	(*pzDireccion)["Calle"],
	(*pzDireccion)["NumExterior"],
	(*pzDireccion)["NumInterior"],
	(*pzDireccion)["Colonia"]);
QTReferencias->setText(pintFila,1,lchrArrDireccion);
}
void QtImpCapturaDatosComplementarios::MuestraParentesco(int pintFila,zParentesco *pzParentesco)
{
QTReferencias->setText(pintFila,3,(const char *)(*pzParentesco)["Parentesco"]);
}
void QtImpCapturaDatosComplementarios::MuestraTelefonos(int pintFila,zTelefonos *pzTelefono)
{
QTReferencias->setText(pintFila,2,pzTelefono->Telefono());
}
int QtImpCapturaDatosComplementarios::RegistrandoReferenciasPersonales()
{
  if(RegistraReferenciasPersonales())
  {
	LogSiscom("Agregando las referencias personales");
	zConBeneficios->ReferenciasPersonales(zRefsPersonales);
	return 1;

  }
  else
  {
 	return 0;
  }
}
int QtImpCapturaDatosComplementarios::RegistraReferenciasPersonales()
{
zOperacionesServiSNTE lzOpeServiSNTE(zSisConexion,"RegistraReferenciasPersonales");
return lzOpeServiSNTE.RegistraReferenciasPersonales(zRefsPersonales);
}
int QtImpCapturaDatosComplementarios::ValidaPersonaRegistrada()
{
zOperacionesServiSNTE lzOpeServiSNTE(zSisConexion,"PersonaRegistrada");
if((zPerReferencia=lzOpeServiSNTE.PersonaRegistrada(zSiscomQt3::Texto(QLENombres),
				zSiscomQt3::Texto(QLEApellidoPaterno),
				zSiscomQt3::Texto(QLEApellidoMaterno))))
{
  return 1;
}
else
return 0;
}
void QtImpCapturaDatosComplementarios::MuestraDireccionPersonaRegistrada()
{

QLECalle->setText(zPerReferencia->Direccion()->Calle());
QLENoExterior->setText(zPerReferencia->Direccion()->NumExterior());
QLENoInterior->setText(zPerReferencia->Direccion()->NumInterior());
QLEColonia->setText(zPerReferencia->Direccion()->Colonia());
QLEDelegacionMunicipio->setText(zPerReferencia->Direccion()->Delegacion());
QLEEstado->setText(zPerReferencia->Direccion()->Estado());
QLECodigoPostal->setText(zPerReferencia->Direccion()->CodigoPostal());
}
void QtImpCapturaDatosComplementarios::MuestraDatosPersonaRegistrada()
{
  MuestraDireccionPersonaRegistrada();
  MuestraDatosTelefonoPersonaRegistrada();
}
void QtImpCapturaDatosComplementarios::HabilitaDesHabilita(int pintEstado)
{

QLECalle->setReadOnly(pintEstado);
QLENoExterior->setReadOnly(pintEstado);
QLENoInterior->setReadOnly(pintEstado);
QLEColonia->setReadOnly(pintEstado);
QLEDelegacionMunicipio->setReadOnly(pintEstado);
QLEEstado->setReadOnly(pintEstado);
QLECodigoPostal->setReadOnly(pintEstado);
QLETelefono->setReadOnly(pintEstado);

}
void QtImpCapturaDatosComplementarios::MuestraDatosTelefonoPersonaRegistrada()
{
QLETelefono->setText(zPerReferencia->NumeroParticular());
}
void QtImpCapturaDatosComplementarios::HabilitaControlesPersonaRegistrada()
{
   if(zPerReferencia->Direccion())
   {
     if(zPerReferencia->TelefonoParticular())
      QPBAgregaReferencia->setEnabled(true);
     else
      QMessageBox::information(this,
      				"Aviso Sistema",
      				"No Se puede usar una persona registrada sin Telefono");
   }
   else
	QMessageBox::information(this,
				 "Aviso Sistema",
				 "NO Se puede usar una parsona registrada Sin Direccion");
}
int QtImpCapturaDatosComplementarios::LineEditValido(QLineEdit *pQLEDato)
{
   return !pQLEDato->text().isNull()  &&
          !pQLEDato->text().isEmpty();
}
int QtImpCapturaDatosComplementarios::DatosMinimosReferencia()
{
  return  LineEditValido(QLEApellidoPaterno) 		&&
          LineEditValido(QLEApellidoMaterno) 		&&
	  LineEditValido(QLENombres)			&&
	  LineEditValido(QLECalle)			&&
	  LineEditValido(QLENoExterior)			&&
	  LineEditValido(QLEColonia)			&&
	  LineEditValido(QLEDelegacionMunicipio)	&&
	  LineEditValido(QLEEstado)			&&
	  LineEditValido(QLECodigoPostal)		&&
	  LineEditValido(QLETelefono);

}
void QtImpCapturaDatosComplementarios::ConectaEditValidacionAgregar(QLineEdit *pQLETexto)
{
   connect(pQLETexto,
   	   SIGNAL(textChanged(const QString &)),
	   SLOT(SlotCambioTextoEdit(const QString &)));
}
