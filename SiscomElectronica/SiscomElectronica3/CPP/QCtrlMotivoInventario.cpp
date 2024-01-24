#include <QCtrlMotivoInventario.h>
#include <CQSis3QtOperaciones.h>
#include <SiscomDesarrollo3Qt++.h>
#include <qlayout.h>
#include <qcombobox.h>

extern FILE *gzPtrFleArchivoLog3Qt;

QCtrlMotivoInventario::QCtrlMotivoInventario( QWidget *parent, const char *name )
    : QWidget( parent, name ),
    intMotivoInventario(0)

{
	IniciaVariables();
	ConectaSlots();
}
void QCtrlMotivoInventario::IniciaVariables()
{
	QHBLayout=new QHBoxLayout(this);
	QHBLayout->setMargin(0);
	QCBMotivoInventario=new QComboBox(this);
	QHBLayout->addWidget(QCBMotivoInventario);
	QLEMotivoInventario=SiscomDesarrollo3Qt::ColocaEditAlCombo(QCBMotivoInventario,"QLEMotivoInventario");
	QCBMotivoInventario->setAutoCompletion(true);
	QCBMotivoInventario->setDuplicatesEnabled(false);
	QCBMotivoInventario->setInsertionPolicy(QComboBox::NoInsertion);

}
void QCtrlMotivoInventario::MuestraMotivoInventario()
{

SiscomDesarrollo3Qt::RegistrosAlCombo("descripcion",
				      QCBMotivoInventario,
				      &SisReg3LstMotivoInventario);

}
void QCtrlMotivoInventario::IniciaControl()
{
	ConsultaMotivoInventario();
	MuestraMotivoInventario();
}
void QCtrlMotivoInventario::ConsultaMotivoInventario()
{
CQSis3QtOperaciones lCQS3QtOperaciones(SisDatCom);
SisReg3LstMotivoInventario.clear();
QCBMotivoInventario->clear();
lCQS3QtOperaciones.MotivoInventario(chrPtrIdExpendio,
				   &SisReg3LstMotivoInventario);
}
void QCtrlMotivoInventario::IdExpendio(const char *pchrPtrIdExpendio)
{
	chrPtrIdExpendio=pchrPtrIdExpendio;
}
void QCtrlMotivoInventario::Servidor(SiscomDatCom *pSisDatCom)
{
	SisDatCom=pSisDatCom;
}
void QCtrlMotivoInventario::ConectaSlots()
{
	connect(QCBMotivoInventario,
		SIGNAL(activated(int)),
		SLOT(SlotMotivoInventario(int)));

}
void QCtrlMotivoInventario::SlotMotivoInventario(int pintNEscuela)
{
	intMotivoInventario=pintNEscuela;
	emit SignalMotivoInventario(SisReg3LstMotivoInventario[pintNEscuela]);
}
void QCtrlMotivoInventario::setFocus()
{
  SiscomDesarrollo3Qt::PasaFocoControl(QLEMotivoInventario);	
}

void QCtrlMotivoInventario::Limpia()
{
}

SiscomRegistro3 *QCtrlMotivoInventario::MotivoInventarioActual()
{
	return SisReg3LstMotivoInventario[intMotivoInventario];
}

