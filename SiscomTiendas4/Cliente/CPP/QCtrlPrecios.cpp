#include <QCtrlPrecios.h>
#include <CQSisPrecios.h>
#include <CQSisOpTiendas4.h>
#include <SISCOMComunicaciones++.h>
#include <qlayout.h>


QCtrlPrecios::QCtrlPrecios( QWidget *parent, const char *name )
    : QWidget( parent, name )
{
	IniciaVariables();
	ConectaSlots();
}
QCtrlPrecios::~QCtrlPrecios()
{
	CQSLPrecio.setAutoDelete(true);
	CQSLPrecio.clear();
}
void QCtrlPrecios::IniciaVariables()
{
	QHBLayout=new QHBoxLayout(this);
	QHBLayout->setMargin(0);
	QCBPrecios=new QComboBox(this);
	QHBLayout->addWidget(QCBPrecios);
	QLEPrecios=SiscomColocaEditAlCombo(QCBPrecios,"QLEPrecios");
	QCBPrecios->setAutoCompletion(true);
	QCBPrecios->setDuplicatesEnabled(false);
	QCBPrecios->setInsertionPolicy(QComboBox::NoInsertion);
}
CQSisLstPrecio &QCtrlPrecios::Precios()
{
	return CQSLPrecio;
}
void QCtrlPrecios::MuestraPrecios()
{
CQSisPrecio *lCQSPrecio;
for(lCQSPrecio=CQSLPrecio.first();
    lCQSPrecio;
    lCQSPrecio=CQSLPrecio.next())
 QCBPrecios->insertItem(lCQSPrecio->SRegistrosPro2["Nombre"]);
}
void QCtrlPrecios::IniciaControl()
{
	ConsultaPrecios();
	MuestraPrecios();
	SeleccionoPrecio(0);
	
}
void QCtrlPrecios::ConsultaPrecios()
{
CQSisOpTiendas4 lCQSOT4Precios(SisDatCom);
lCQSOT4Precios.Precios(&CQSLPrecio);
QCBPrecios->clear();
}
void QCtrlPrecios::PonServidor(SiscomDatCom *pSisDatCom)
{
	SisDatCom=pSisDatCom;
}
void QCtrlPrecios::ConectaSlots()
{
	connect(QCBPrecios,
		SIGNAL(activated(int)),
		SLOT(SlotPrecio(int)));
}
void QCtrlPrecios::SlotPrecio(int pintNPrecio)
{
	SeleccionoPrecio(pintNPrecio);
}
void QCtrlPrecios::setFocus()
{
SiscomPasaFocoControl(QLEPrecios);	
}

void QCtrlPrecios::Limpia()
{
}
void QCtrlPrecios::SeleccionoPrecio(int pintNPrecio)
{
	emit SignalPrecio(CQSLPrecio.at(pintNPrecio));
}





