#include <IMP_Clientes.h>
#include <IMP_IntroduceDatos.h>
#include <IMP_CapturaTelefono.h>
#include <IMP_BuscarClientes.h>
#include <IMP_ModificaGenerales.h>
#include <CQSiscomCom.h>
#include <Personas.h>
#include <GeneralBibliotecaSeguridad3.h>

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qcombobox.h>
#include <qtextedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
QClientes *InstanciaClientes(void *pCSisDatCom,
			     void *pQWParent,
			     const char *pchrPtrName,
			     int pintWFlags)
{
	return new QClientes((CSISCOMDatComunicaciones *)pCSisDatCom,
			     (QWidget *)pQWParent,
			     pchrPtrName,
			     pintWFlags);
}


QClientes::QClientes(CSISCOMDatComunicaciones *pCSisDatCom,
		QWidget* parent, const char* name, WFlags fl )
    : Clientes( parent, name, fl ),
    CSisDatCom(pCSisDatCom)
{
	IniciaVariables();
	ConectaSlots();
}

QClientes::~QClientes()
{
}
void QClientes::ConectaSlots()
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
		SLOT(S_PasaFocoApodo()));
	connect(QLEApodo,
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
		SLOT(S_PasaFocoEstado()));
	connect(QLECEstado,
		SIGNAL(returnPressed()),
		SLOT(S_PasaFocoReferencias()));
	connect(QPBAnexarTelefono,
		SIGNAL(clicked()),
		SLOT(S_AnexarTelefono()));
	connect(QPBRegistrar,
		SIGNAL(clicked()),
		SLOT(S_Registrar()));
	connect(QPBBCliente,
		SIGNAL(clicked()),
		SLOT(S_BuscarCliente()));
	connect(QPBMDatos,
		SIGNAL(clicked()),
		SLOT(S_ModificaDatos()));

}
void QClientes::S_ModificaDatos()
{
QBuscarClientes lQBClientes(CSisDatCom);
if(lQBClientes.ObtenSeleccion()==QBuscarClientes::Aceptar)
{
QModificaGenerales lQMGenerales(CSisDatCom,
				lQBClientes.ObtenPersona());

}



}
void QClientes::S_BuscarCliente()
{
QBuscarClientes lQBClientes(CSisDatCom);
if(lQBClientes.ObtenSeleccion()==QBuscarClientes::Aceptar)
{

}


}
void QClientes::S_Registrar()
{
CQ_Persona *lCQPersona;
int lintContador;

		lCQPersona=new CQ_Persona(SISCOMObtenInformacionDelEdit(QLENombre),
					  SISCOMObtenInformacionDelEdit(QLEAPaterno),
					  SISCOMObtenInformacionDelEdit(QLEAMaterno),
					  SISCOMObtenInformacionDelEdit(QLERFC),
					  "1",
					  "");
		lCQPersona->AnexaDireccion(
				new CQ_Direccion(
					SISCOMObtenInformacionDelEdit(QLECalle),
					SISCOMObtenInformacionDelEdit(QLENumero),
					SISCOMObtenInformacionDelEdit(QLEColonia),
					SISCOMObtenInformacionDelEdit(QLECP),
					SISCOMObtenInformacionDelEdit(QLEMunicipio),
					SISCOMObtenInformacionDelEdit(QLECEstado),
					SISCOMObtenInformacionDelEdit(QTEReferencias)));
		for(lintContador=0;
		    lintContador<QCBTelefonos->count();
		    lintContador++)
		lCQPersona->AnexaTelefono(
				  new CQ_Telefono("",
						  (const char *)QCBTelefonos->text(lintContador)));
		if(!QLECElectronico->text().isEmpty())
		lCQPersona->AnexaCorreo(
				  new CQ_Correo("",		
						SISCOMObtenInformacionDelEdit(QLECElectronico)));
		lCQPersona->PonPerfil(new QSiscomPerfilBD("1",
							  "1",
							  "Cliente",
							  "Clientes El Fresno"));
		lCQPersona->AnexaApodo(new CQ_Apodo("",SISCOMObtenInformacionDelEdit(QLEApodo)));

CQ_Personas lCQPersonas;
		lCQPersonas << lCQPersona;
CQCtrPersonas lCQCPersonas(CSisDatCom,
			   CQCtrPersonas::Registrar,
			   &lCQPersonas);	
					  
}
void QClientes::S_AnexarTelefono()
{
QCapturaTelefono lQCTelefono;
const char *lchrPtrTelefonoYDescripcion;	
	 if(lQCTelefono.ObtenOpcion()==QCapturaTelefono::Aceptar)
		QCBTelefonos->insertItem(lQCTelefono.ObtenTelefonoYDescripcion());
}
void QClientes::S_PasaFocoNombre()
{
	PasaFocoControl(QLENombre);
}

void QClientes::S_PasaFocoAPaterno()
{
	PasaFocoControl(QLEAPaterno);
}


void QClientes::S_PasaFocoAMaterno()
{
	PasaFocoControl(QLEAMaterno);
}

void QClientes::S_PasaFocoApodo()
{
	PasaFocoControl(QLEApodo);
}
void QClientes::S_PasaFocoCalle()
{
	PasaFocoControl(QLECalle);
}
void QClientes::S_PasaFocoNumero()
{
	PasaFocoControl(QLENumero);
}

void QClientes::S_PasaFocoCP()
{
	PasaFocoControl(QLECP);
}


void QClientes::S_PasaFocoColonia()
{
	PasaFocoControl(QLEColonia);
}


void QClientes::S_PasaFocoMunicipio()
{
	PasaFocoControl(QLEMunicipio);
}


void QClientes::S_PasaFocoEstado()
{
	PasaFocoControl(QLECEstado);
}


void QClientes::S_PasaFocoReferencias()
{
	PasaFocoControl(QTEReferencias);
}




void QClientes::IniciaVariables()
{
	PasaFocoControl(QLERFC);
	QLECEstado=ColocaLineEditAlCombo(QCBEstados,"QLECEstado");
}
