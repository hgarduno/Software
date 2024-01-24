#include <QCtrlContactos.h>
#include <CQSisOpTiendas4.h>
#include <SISCOMComunicaciones++.h>
#include <SisPersonas.h>
#include <qlayout.h>


QCtrlContactos::QCtrlContactos( QWidget *parent, const char *name )
    : QWidget( parent, name )
{
	IniciaVariables();
	ConectaSlots();
}
QCtrlContactos::~QCtrlContactos()
{
printf("QCtrlContactos::~QCtrlContactos\n");
	CQSLContactos.setAutoDelete(true);
	CQSLContactos.clear();
}
void QCtrlContactos::IniciaVariables()
{
	QHBLayout=new QHBoxLayout(this);
	QHBLayout->setMargin(0);
	QCBContactos=new QComboBox(this);
	QHBLayout->addWidget(QCBContactos);
	QLEContactos=SiscomColocaEditAlCombo(QCBContactos,"QLEContactos");
	QCBContactos->setAutoCompletion(true);
	QCBContactos->setDuplicatesEnabled(false);
	QCBContactos->setInsertionPolicy(QComboBox::NoInsertion);
}
void QCtrlContactos::MuestraContactos()
{
CQSisContacto *lCQSProducto;
  for(lCQSProducto=CQSLContactos.first();
      lCQSProducto;
      lCQSProducto=CQSLContactos.next())
     QCBContactos->insertItem(
     	QString(lCQSProducto->ObtenPersona()->SRegistrosPro2["Nombre"]) +
     		" "					      +
		lCQSProducto->ObtenPersona()->SRegistrosPro2["APaterno"]);
}
void QCtrlContactos::IniciaControl()
{
	ConsultaContactos();
	MuestraContactos();
}
void QCtrlContactos::ConsultaContactos()
{
QCBContactos->clear();
CQSisOpTiendas4 lCQSOT4Contactos(SisDatCom);
	lCQSOT4Contactos.ContactosProveedor(
				CQSEmpresa,
				&CQSLContactos);
}
void QCtrlContactos::PonServidor(SiscomDatCom *pSisDatCom)
{
	SisDatCom=pSisDatCom;
}
void QCtrlContactos::PonEmpresa(CQSisEmpresa *pCQSEmpresa)
{
	CQSEmpresa=pCQSEmpresa;
}
void QCtrlContactos::ConectaSlots()
{
	connect(QCBContactos,
		SIGNAL(activated(int)),
		SLOT(SlotProducto(int)));

}
void QCtrlContactos::SlotProducto(int pintNProducto)
{
	emit SignalContactos(CQSLContactos.at(pintNProducto));
}
void QCtrlContactos::setFocus()
{
  SiscomPasaFocoControl(QLEContactos);	
}

void QCtrlContactos::Limpia()
{
}






