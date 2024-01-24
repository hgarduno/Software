#include <IMP_BuscarClientes.h>
#include <IMP_ResultadoClientes.h>
#include <SISCOMComunicaciones++.h>

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qtextedit.h>
#include <qcombobox.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qmessagebox.h>

QBuscarClientes::QBuscarClientes(CSISCOMDatComunicaciones *pCSisDatCom,
				 QWidget* parent, const char* name, bool modal, WFlags fl )
    : BuscarClientes( parent, name, modal, fl ),
	CSisDatCom(pCSisDatCom)
{
	IniciaVariables();
	ConectaSlots();
	QPBAceptar->setEnabled(false);
	exec();
}

QBuscarClientes::~QBuscarClientes()
{
}
void QBuscarClientes::IniciaVariables()
{
	QPBSiguiente->setEnabled(false);
	QPBAnterior->setEnabled(false);
	QPBSTodos->setEnabled(false);
	SiscomPasaFocoControl(QLERFC);

}
void QBuscarClientes::ConectaSlots()
{
	connect(QPBConsultar,
		SIGNAL(clicked()),
		SLOT(S_Consultar()));
	connect(QPBSiguiente,
		SIGNAL(clicked()),
		SLOT(S_SiguienteCliente()));
	connect(QPBAnterior,
		SIGNAL(clicked()),
		SLOT(S_ClienteAnterior()));
	connect(QPBAceptar,
		SIGNAL(clicked()),
		SLOT(S_Aceptar()));
	connect(QPBSTodos,
		SIGNAL(clicked()),
		SLOT(S_SeleccionarTodos()));
	connect(QPBCancelar,
		SIGNAL(clicked()),
		SLOT(S_Cancelar()));

	connect(QLERFC,
		SIGNAL(returnPressed()),
		SLOT(SlotPasaFocoNombre()));
	connect(QLENombre,
		SIGNAL(returnPressed()),
		SLOT(SlotPasaFocoAPaterno()));
	connect(QLEAPaterno,
		SIGNAL(returnPressed()),
		SLOT(SlotPasaFocoAMaterno()));
	connect(QLEAMaterno,
		SIGNAL(returnPressed()),
		SLOT(SlotPasaFocoConsultar()));
}
void QBuscarClientes::SlotPasaFocoNombre()
{
SiscomPasaFocoControl(QLENombre);
}
void QBuscarClientes::SlotPasaFocoAPaterno()
{
SiscomPasaFocoControl(QLEAPaterno);
}
void QBuscarClientes::SlotPasaFocoAMaterno()
{
SiscomPasaFocoControl(QLEAMaterno);
}
void QBuscarClientes::SlotPasaFocoConsultar()
{
SiscomPasaFocoControl(QPBConsultar);
}
void QBuscarClientes::S_Cancelar()
{

	BTN_Seleccion=QBuscarClientes::Cancelar;
	done(1);
}
QBuscarClientes::BTN_Botones QBuscarClientes::ObtenSeleccion()
{
	return BTN_Seleccion;
}
void QBuscarClientes::S_SeleccionarTodos()
{
	BTN_Seleccion=QBuscarClientes::Aceptar;
	done(1);
}
void QBuscarClientes::S_Aceptar()
{
	BTN_Seleccion=QBuscarClientes::Aceptar;
	CQPersonas.clear();
	CQPersonas.append(CQPersona);
	done(1);
}
const CQ_Personas &QBuscarClientes::ObtenPersonas()
{
	return CQPersonas;
}
CQ_Persona *QBuscarClientes::ObtenPersona()
{
	return CQPersona;
}
void QBuscarClientes::S_ClienteAnterior()
{

	if(!(CQPersona=CQPersonas.prev()))
	 CQPersona=CQPersonas.last(); 
	MuestraDatosPersona();
}
void QBuscarClientes::S_SiguienteCliente()
{
	if(!(CQPersona=CQPersonas.next()))
	 CQPersona=CQPersonas.first(); 
	MuestraDatosPersona();
}
QString QBuscarClientes::ObtenDato(QLineEdit *pQLEControl)
{
	return pQLEControl->text().isEmpty() ? "":pQLEControl->text();
}
void QBuscarClientes::S_Consultar()
{
CQCtrPersonas lCQCPersonas(CSisDatCom,
			   QStringList() << 
			   "ConsultarPersonas"    <<
			   ObtenDato(QLENombre)   <<
			   ObtenDato(QLEAPaterno) <<
			   ObtenDato(QLEAMaterno)  <<
			   ObtenDato(QLEApodo)	<<
			   ObtenDato(QLERFC),
			   &CQPersonas);
	QPBSiguiente->setEnabled(CQPersonas.count());
	QPBAnterior->setEnabled(CQPersonas.count());
	QPBSTodos->setEnabled(CQPersonas.count());
	if(CQPersonas.count()==1)
	 HabilitaDesHabilitaControles("%W0,%W0",QPBSiguiente,QPBAnterior);
	
	if(CQPersonas.count())
	{
		CQPersona=CQPersonas.first();
		MuestraDatosPersona();	
		QPBAceptar->setEnabled(true);
	}
	else
	QMessageBox::information(this,
				 "Sistema El Fresno",
				 "No Se Encontro Ningun Cliente");

}
void QBuscarClientes::MuestraDatosPersona()
{
CQ_Direcciones lCQDirecciones=CQPersona->ObtenDirecciones();
CQ_Direccion *lCQDireccion=lCQDirecciones.at(0);
CQ_Apodos lCQApodos=CQPersona->ObtenApodos();
CQ_Telefonos lCQTelefonos=CQPersona->ObtenTelefonos();
CQ_Telefono *lCQTelefono;

	LimpiaControles();
	QLERFC->setText(CQPersona->ObtenRFC());
	QLENombre->setText(CQPersona->ObtenNombre());
	QLEAPaterno->setText(CQPersona->ObtenAPaterno());
	QLEAMaterno->setText(CQPersona->ObtenAMaterno());
	QLEApodo->setText(lCQApodos.at(0)->ObtenApodo());

	if(lCQDireccion)
	{	
	QLECalle->setText(lCQDireccion->ObtenCalle());
	QLENumero->setText(lCQDireccion->ObtenNumero());
	QLECP->setText(lCQDireccion->ObtenCP());
	QLEColonia->setText(lCQDireccion->ObtenColonia());
	QTEReferencias->setText(lCQDireccion->ObtenReferencias());
	QLEMunicipio->setText(lCQDireccion->ObtenDelegacion());
	QCBEstado->insertItem(lCQDireccion->ObtenEstado());
	}
	for(lCQTelefono=lCQTelefonos.first();
	    lCQTelefono;
	    lCQTelefono=lCQTelefonos.next())
	 QCBTelefonos->insertItem(lCQTelefono->ObtenTelefono());
}

void QBuscarClientes::LimpiaControles()
{
	QLERFC->clear();
	QLENombre->clear();	
	QLEAPaterno->clear();
	QLEAMaterno->clear();
	QLEApodo->clear();
	QLECalle->clear();
	QLENumero->clear();
	QLECP->clear();
	QLEColonia->clear();
	QTEReferencias->clear();
	QLEMunicipio->clear();
	QCBEstado->clear();
	QCBTelefonos->clear();
}
void QBuscarClientes::closeEvent(QCloseEvent *)
{
	BTN_Seleccion=QBuscarClientes::Cancelar;
	done(1);
}
