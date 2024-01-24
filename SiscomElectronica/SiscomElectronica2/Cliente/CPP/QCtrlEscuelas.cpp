#include <QCtrlEscuelas.h>
#include <SiscomDesarrollo3Qt++.h>
#include <CQSisEscuelas.h>
#include <qlayout.h>
#include <qcombobox.h>

extern FILE *gzPtrFleArchivoLog3Qt;

QCtrlEscuelas::QCtrlEscuelas( QWidget *parent, const char *name )
    : QWidget( parent, name ),
    intEscuela(0)

{
	IniciaVariables();
	ConectaSlots();
}
void QCtrlEscuelas::IniciaVariables()
{
	QHBLayout=new QHBoxLayout(this);
	QHBLayout->setMargin(0);
	QCBEscuelas=new QComboBox(this);
	QHBLayout->addWidget(QCBEscuelas);
	QLEEscuelas=SiscomDesarrollo3Qt::ColocaEditAlCombo(QCBEscuelas,"QLEEscuelas");
	QCBEscuelas->setAutoCompletion(true);
	QCBEscuelas->setDuplicatesEnabled(false);
	QCBEscuelas->setInsertionPolicy(QComboBox::NoInsertion);

}
void QCtrlEscuelas::MuestraEscuelas()
{

SiscomDesarrollo3Qt::RegistrosAlCombo("nombre",
				      QCBEscuelas,
				      &SisReg3LstEscuelas);

}
void QCtrlEscuelas::IniciaControl()
{
	ConsultaEscuelas();
	MuestraEscuelas();
}
void QCtrlEscuelas::ConsultaEscuelas()
{
QCBEscuelas->clear();
CQSisOpEscuelas lCQSOEscuelas(SisDatCom);
	lCQSOEscuelas.Escuelas(chrPtrIdExpendio,
			       &SisReg3LstEscuelas);
}
void QCtrlEscuelas::IdExpendio(const char *pchrPtrIdExpendio)
{
	chrPtrIdExpendio=pchrPtrIdExpendio;
}
void QCtrlEscuelas::PonServidor(SiscomDatCom *pSisDatCom)
{
	SisDatCom=pSisDatCom;
}
void QCtrlEscuelas::ConectaSlots()
{
	connect(QCBEscuelas,
		SIGNAL(activated(int)),
		SLOT(SlotEscuela(int)));

}
void QCtrlEscuelas::SlotEscuela(int pintNEscuela)
{
	intEscuela=pintNEscuela;
	emit SignalEscuelas(SisReg3LstEscuelas[pintNEscuela]);
}
void QCtrlEscuelas::setFocus()
{
  SiscomDesarrollo3Qt::PasaFocoControl(QLEEscuelas);	
}

void QCtrlEscuelas::Limpia()
{
}

SiscomRegistro3 *QCtrlEscuelas::EscuelaActual()
{
	return SisReg3LstEscuelas[intEscuela];
}

void QCtrlEscuelas::Escuela(const char *pchrPtrEscuela)
{
QCBEscuelas->setCurrentText(pchrPtrEscuela);
}


