#include <IMP_RegistroEmpleados.h>
#include <IMP_IntroduceDatos.h>
#include <IMP_ConsultaEmpleados.h>
#include <SISCOMComunicaciones++.h>
#include <CQSiscomCom.h>
#include <GeneralBibliotecaSeguridad3.h>
#include <Personas.h>

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qcombobox.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qmessagebox.h>
QRegistroEmpleados *InstanciaRegistroEmpleados(void *pCSisDatCom,
					       void *pQWParent,
					       const char *pchrPtrName,
					       int pintWFlags)
{
	return new QRegistroEmpleados((CSISCOMDatComunicaciones *)pCSisDatCom,
				       (QWidget *)pQWParent,
				       pchrPtrName,
				       pintWFlags);
}
QRegistroEmpleados::QRegistroEmpleados(CSISCOMDatComunicaciones *pCSisDatCom,
		QWidget* parent, const char* name, WFlags fl )
    : RegistroEmpleados( parent, name, fl ),
    CSisDatCom(pCSisDatCom)
{
	SDatCom=new SiscomDatCom(atoi(getenv("PtoComSvr2")),
	                                 CSisDatCom->ObtenDirIpSvr());
	LlenaComboPerfiles();
	IniciaVariables();
	ConectaSlots();
}

QRegistroEmpleados::~QRegistroEmpleados()
{
}
void QRegistroEmpleados::ConectaSlots()
{
	connect(QLERFC,
		SIGNAL(returnPressed()),
		SLOT(S_PasaFocoNombre()));
	connect(QLENombre,
		SIGNAL(returnPressed()),
		SLOT(S_PasaFocoAPaterno()));
	connect(QLEAPaterno,
		SIGNAL(returnPressed()),
		SLOT(S_PasaFocoAMaterno()));
	connect(QLEAMaterno,
		SIGNAL(returnPressed()),
		SLOT(S_PasaFocoCalle()));
	connect(QLECalle,
		SIGNAL(returnPressed()),
		SLOT(S_PasaFocoNumero()));
	connect(QLENumero,
		SIGNAL(returnPressed()),
		SLOT(S_PasaFocoCP()));
	connect(QLECP,
		SIGNAL(returnPressed()),
		SLOT(S_PasaFocoColonia()));
	connect(QLEColonia,
		SIGNAL(returnPressed()),
		SLOT(S_PasaFocoMunicipio()));
	connect(QLEMunicipio,
		SIGNAL(returnPressed()),
		SLOT(S_PasaFocoEstados()));
	connect(QLEEstados,
		SIGNAL(returnPressed()),
		SLOT(S_PasaFocoAnexarTelefono()));
	connect(QPBATelefono,
		SIGNAL(clicked()),
		SLOT(S_AnexarTelefono()));
	connect(QLECElectronico,
		SIGNAL(returnPressed()),
		SLOT(S_PasaFocoPerfil()));
	connect(QCBPerfiles,
		SIGNAL(activated(int)),
		SLOT(S_SeleccionoPerfil(int)));
	connect(QLEFirma,
		SIGNAL(returnPressed()),
		SLOT(S_PasaFocoPassword()));
	connect(QLEPassword,
		SIGNAL(returnPressed()),
		SLOT(S_PasaFocoCPassword()));
	connect(QLECPassword,
		SIGNAL(returnPressed()),
		SLOT(S_PasaFocoRegistrar()));
	connect(QPBREmpleado,
		SIGNAL(clicked()),
		SLOT(S_Registrar()));
	connect(QPBConsultaEmpleados,
		SIGNAL(clicked()),
		SLOT(S_ConsultaEmpleados()));


}
void QRegistroEmpleados::S_ConsultaEmpleados()
{
QConsultaEmpleados lQCEmpleados(SDatCom);
	if(lQCEmpleados.ObtenBoton()==SISCOMGlobales::Aceptar)
	{
	   CQEmpConsultados=lQCEmpleados.ObtenEmpleados(); 
	   SeSeleccionaronEmpleados();
	}
}
void QRegistroEmpleados::S_Registrar()
{
CQ_Persona *lCQPersona;
int lintContador;

/*
	Antes de realizar la operacion
	se debera validar la firma 

*/
QSPerfilBD=(*CQPDatos)[QCBPerfiles->currentItem()];
if(QSiscomSeguridad3::RegistraUsuarioYFirma(CSisDatCom,
					    getenv("Aplicacion"),
					    QSPerfilBD->ObtenNmbPerfil(),
					    SISCOMObtenInformacionDelEdit(QLENombre),
					    SISCOMObtenInformacionDelEdit(QLEAPaterno),
					    SISCOMObtenInformacionDelEdit(QLEAMaterno),
					    SISCOMObtenInformacionDelEdit(QLEFirma),
					    SISCOMObtenInformacionDelEdit(QLEPassword),
					    SISCOMObtenInformacionDelEdit(QLECPassword)))
{
					     
lCQPersona=new CQ_Persona(SISCOMObtenInformacionDelEdit(QLENombre),
			 SISCOMObtenInformacionDelEdit(QLEAPaterno),
			 SISCOMObtenInformacionDelEdit(QLEAMaterno),
			 SISCOMObtenInformacionDelEdit(QLERFC),
			 QSPerfilBD->ObtenIdPerfil(),
			 "");

lCQPersona->AnexaDireccion(new CQ_Direccion(SISCOMObtenInformacionDelEdit(QLECalle),
					    SISCOMObtenInformacionDelEdit(QLENumero),
					    SISCOMObtenInformacionDelEdit(QLEColonia),
					    SISCOMObtenInformacionDelEdit(QLECP),
					    SISCOMObtenInformacionDelEdit(QLEMunicipio),
					    SISCOMObtenInformacionDelEdit(QLEEstados),
					    "Referencias"));

for(lintContador=0;
    lintContador<QCBTelefonos->count();
    lintContador++)
lCQPersona->AnexaTelefono(new CQ_Telefono("",
					  QCBTelefonos->text(lintContador)));
lCQPersona->AnexaCorreo(new CQ_Correo("",
				      SISCOMObtenInformacionDelEdit(QLECElectronico)));
lCQPersona->PonFirma(new CQ_Firma(SISCOMObtenInformacionDelEdit(QLEFirma),
				  ""));

lCQPersona->PonPerfil(QSPerfilBD);
CQ_Personas lCQPersonas;
		lCQPersonas << lCQPersona;
CQCtrPersonas lCQCPersonas(CSisDatCom,
			   CQCtrPersonas::Registrar,
			   &lCQPersonas);
HabilitaDesHabilitaControles("%W0%W0%W0%W0",
				     QLEFirma,
				     QLEPassword,
				     QLECPassword,
				     QPBREmpleado);
PasaFocoControl(QLERFC); 

}
else
QMessageBox::information(this,
                         "Registra Empleados",
                         "El Password No Es Correcto");
}
void QRegistroEmpleados::S_PasaFocoRegistrar()
{
	PasaFocoControl(QPBREmpleado);
}
void QRegistroEmpleados::S_PasaFocoFirma()
{
	PasaFocoControl(QLEFirma);
}
void QRegistroEmpleados::S_PasaFocoPassword()
{
	PasaFocoControl(QLEPassword);
}
void QRegistroEmpleados::S_PasaFocoCPassword()
{
	PasaFocoControl(QLECPassword);
}
void QRegistroEmpleados::S_SeleccionoPerfil(int )
{
	PasaFocoControl(QLEFirma);
	HabilitaDesHabilitaControles("%W1%W1%W1%W1",
				     QLEFirma,
				     QLEPassword,
				     QLECPassword,
				     QPBREmpleado);

}
void QRegistroEmpleados::S_PasaFocoPerfil()
{
	PasaFocoControl(QCBPerfiles);
}
void QRegistroEmpleados::S_AnexarTelefono()
{
QIntroduceDatos lQIDatos("Telefono","Introduce Telefono");
	if(lQIDatos.ObtenBoton()==QIntroduceDatos::Aceptar)
	  QCBTelefonos->insertItem(lQIDatos.ObtenDato()); 
}
void QRegistroEmpleados::S_PasaFocoEstados()
{
	PasaFocoControl(QLEEstados);
}
void QRegistroEmpleados::S_PasaFocoAnexarTelefono()
{
	PasaFocoControl(QPBATelefono);
}
void QRegistroEmpleados::S_PasaFocoNombre()
{
	PasaFocoControl(QLENombre);
}

void QRegistroEmpleados::S_PasaFocoAPaterno()
{
	PasaFocoControl(QLEAPaterno);
}


void QRegistroEmpleados::S_PasaFocoAMaterno()
{
	PasaFocoControl(QLEAMaterno);
}


void QRegistroEmpleados::S_PasaFocoCalle()
{
	PasaFocoControl(QLECalle);
}


void QRegistroEmpleados::S_PasaFocoNumero()
{
	PasaFocoControl(QLENumero);
}


void QRegistroEmpleados::S_PasaFocoCP()
{
	PasaFocoControl(QLECP);
}


void QRegistroEmpleados::S_PasaFocoColonia()
{
	PasaFocoControl(QLEColonia);
}


void QRegistroEmpleados::S_PasaFocoMunicipio()
{
	PasaFocoControl(QLEMunicipio);
}



void QRegistroEmpleados::LlenaComboPerfiles()
{
int lintContador=0;

	CQPDatos=QSiscomSeguridad3::ObtenPerfilesDeLaAplicacion(CSisDatCom);
	while((QSPerfilBD=(*CQPDatos)[lintContador++]))
	  QCBPerfiles->insertItem(QSPerfilBD->ObtenNmbPerfil());
}
void QRegistroEmpleados::IniciaVariables()
{
	PasaFocoControl(QLERFC);
	QLEEstados=ColocaLineEditAlCombo(QCBEstados,
					 "QLEEstados");
	HabilitaDesHabilitaControles("%W0%W0%W0%W)",
				     QLEFirma,
				     QLEPassword,
				     QLECPassword,
				     QPBREmpleado);
	
}




void QRegistroEmpleados::SeSeleccionaronEmpleados()
{
	QCBPerfiles->clear();
	QCBEstados->clear();
	CQPersonaActual=CQEmpConsultados->first();
	HabilitaDesHabilitaControles("%W1%W1%W1%W0%W0%W1%W1%W1%W1%W0%W1%W1%W1",
				     QPBModificar,
				     QPBSiguiente,
				     QPBAnterior,
				     QPBREmpleado,
				     QPBATelefono,
				     QLEFirma,
				     QPBMDireccion,
				     QPBAETelefono,
				     QPBMTelefono,
				     QPBETelefono,
				     QPBACorreo,
				     QPBMCorreo,
				     QPBECorreo,
				     QPBERegistro);
	CambiaEstadoEdits(true);
	ConectaSlotsConsulta();
	MuestraEmpleadoConsulta();
}
void QRegistroEmpleados::ConectaSlotsConsulta()
{
	connect(QPBSiguiente,
		SIGNAL(clicked()),
		SLOT(S_Siguiente()));
	connect(QPBAnterior,
		SIGNAL(clicked()),
		SLOT(S_Anterior()));

}
void QRegistroEmpleados::S_Siguiente()
{
	if(!(CQPersonaActual=CQEmpConsultados->next()))
	 CQPersonaActual=CQEmpConsultados->first();
	MuestraEmpleadoConsulta();
}
void QRegistroEmpleados::S_Anterior()
{
	if(!(CQPersonaActual=CQEmpConsultados->prev()))
	 CQPersonaActual=CQEmpConsultados->last();
	MuestraEmpleadoConsulta();

}
void QRegistroEmpleados::MuestraDireccion()
{
CQ_Direcciones lCQDirecciones=CQPersonaActual->ObtenDirecciones();
CQ_Direccion *lCQDireccion=lCQDirecciones.at(0);
	if(lCQDireccion)
	{
	QLECalle->setText(lCQDireccion->ObtenCalle());
	QLENumero->setText(lCQDireccion->ObtenNumero());
	QLECP->setText(lCQDireccion->ObtenCP());
	QLEColonia->setText(lCQDireccion->ObtenColonia());
	QLEMunicipio->setText(lCQDireccion->ObtenDelegacion());
	QLEEstados->setText(lCQDireccion->ObtenEstado());
	}
	else
	{
	QLECalle->setText("");
	QLENumero->setText("");
	QLECP->setText("");
	QLEColonia->setText("");
	QLEMunicipio->setText("");
	QLEEstados->setText("");
	}
}
void QRegistroEmpleados::MuestraInformacionSeguridad()
{
	QCBPerfiles->clear();
	if(CQPersonaActual->ObtenPerfil())
	QCBPerfiles->insertItem(CQPersonaActual->ObtenPerfil()->ObtenNmbPerfil());

	if(CQPersonaActual->ObtenFirma())
	QLEFirma->setText(CQPersonaActual->ObtenFirma()->ObtenFirma());
	else
	QLEFirma->setText("");
}
void QRegistroEmpleados::MuestraEmpleadoConsulta()
{

	QLERFC->setText(CQPersonaActual->ObtenRFC());
	QLENombre->setText(CQPersonaActual->ObtenNombre());
	QLEAPaterno->setText(CQPersonaActual->ObtenAPaterno());
	QLEAMaterno->setText(CQPersonaActual->ObtenAMaterno());
	MuestraDireccion();
	MuestraInformacionSeguridad();


}
void QRegistroEmpleados::CambiaEstadoEdits(bool pbolEstado)
{
QObjectList *lQOList=queryList("QLineEdit");
QObjectListIt lQOLIterador(*lQOList);
QObject *lQObjeto;
	while((lQObjeto=lQOLIterador.current()))
	{
	     ((QLineEdit *)lQObjeto)->setReadOnly(pbolEstado);
	     ++lQOLIterador;
	}
}
