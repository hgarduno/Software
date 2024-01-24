
#include <QCtrlContactos3Qt.h>
#include <SiscomDesarrollo3Qt++.h>
#include <SiscomOperaciones3.h>

#include <CQSisComunesTiendas3Qt.h>
#include <qlayout.h>
#include <qcombobox.h>
#include <qlineedit.h>

QCtrlContactos3Qt::QCtrlContactos3Qt( QWidget *parent, const char *name )
    : QWidget( parent, name )
{
	IniciaVariables();
	ConectaSlots();
}
QCtrlContactos3Qt::~QCtrlContactos3Qt()
{
}
void QCtrlContactos3Qt::IniciaVariables()
{
	QHBLayout=new QHBoxLayout(this);
	QHBLayout->setMargin(0);
	QCBContactos=new QComboBox(this);
	QHBLayout->addWidget(QCBContactos);
	QLEContactos=SiscomDesarrollo3Qt::ColocaEditAlCombo(QCBContactos,"QLEContactos");
	QCBContactos->setAutoCompletion(true);
	QCBContactos->setDuplicatesEnabled(false);
	QCBContactos->setInsertionPolicy(QComboBox::NoInsertion);
}
void QCtrlContactos3Qt::MuestraContactos()
{
SiscomRegistro3 *lSReg3Contacto;
char lchrArrContacto[128];
for(lSReg3Contacto=SReg3Contactos.first();
    lSReg3Contacto;
    lSReg3Contacto=SReg3Contactos.next())
{
CQSisComunesTiendas3Qt::NombreCompleto(lSReg3Contacto,lchrArrContacto);
QCBContactos->insertItem(lchrArrContacto);
}
}
void QCtrlContactos3Qt::IniciaControl()
{
	ConsultaContactos();
	MuestraContactos();
}
void QCtrlContactos3Qt::ConsultaContactos()
{
SiscomOperaciones3 lSOpContactos(SisDatCom);
SReg3Contactos.clear();
lSOpContactos.SiscomEnvia("ConsultaTiendas4",
			  &SReg3Contactos,
			  "%s%s",
			  "ContactosProveedor",
			  (*SReg3Empresa)["idpersona"]);
}
void QCtrlContactos3Qt::Servidor(SiscomDatCom *pSisDatCom)
{
	SisDatCom=pSisDatCom;
}
void QCtrlContactos3Qt::PonEmpresa(SiscomRegistro3 *pSReg3Empresa)
{
	SReg3Empresa=pSReg3Empresa;
}
void QCtrlContactos3Qt::ConectaSlots()
{
	connect(QCBContactos,
		SIGNAL(activated(int)),
		SLOT(SlotContacto(int)));

}
void QCtrlContactos3Qt::SlotContacto(int pintNContacto)
{
	emit SignalContacto(SReg3Contactos[pintNContacto]);
}
void QCtrlContactos3Qt::setFocus()
{
  SiscomDesarrollo3Qt::PasaFocoControl(QLEContactos);	
}

void QCtrlContactos3Qt::Limpia()
{
	QCBContactos->clear();	
}






