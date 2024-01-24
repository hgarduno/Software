#include <QCtrlFormaPago.h>
#include <CQSisOpTiendas4.h>
#include <CQSisFormaPago.h>
#include <SISCOMComunicaciones++.h>
#include <qlayout.h>


QCtrlFormaPago::QCtrlFormaPago( QWidget *parent, const char *name )
    : QWidget( parent, name )
{
	IniciaVariables();
	ConectaSlots();
}
void QCtrlFormaPago::IniciaVariables()
{
	QHBLayout=new QHBoxLayout(this);
	QHBLayout->setMargin(0);
	QCBFormaPago=new QComboBox(this);
	QHBLayout->addWidget(QCBFormaPago);
	QLEFormaPago=SiscomColocaEditAlCombo(QCBFormaPago,"QLEFormaPago");
	QCBFormaPago->setAutoCompletion(true);
	QCBFormaPago->setDuplicatesEnabled(false);
	QCBFormaPago->setInsertionPolicy(QComboBox::NoInsertion);
}
void QCtrlFormaPago::MuestraFormaPago()
{
CQSisFormaPago *lCQSProducto;
  for(lCQSProducto=CQSLFormaPago.first();
      lCQSProducto;
      lCQSProducto=CQSLFormaPago.next())
     QCBFormaPago->insertItem(lCQSProducto->SRegistrosPro2["Nombre"]);
}
void QCtrlFormaPago::IniciaControl()
{
	ConsultaFormaPago();
	MuestraFormaPago();
	SeleccionoFormaPago(0);
}
void QCtrlFormaPago::ConsultaFormaPago()
{
QCBFormaPago->clear();
CQSisOpTiendas4 lCQSOT4FormaPago(SisDatCom);
	lCQSOT4FormaPago.FormaPago(&CQSLFormaPago);
}
void QCtrlFormaPago::PonServidor(SiscomDatCom *pSisDatCom)
{
	SisDatCom=pSisDatCom;
}
void QCtrlFormaPago::ConectaSlots()
{
	connect(QCBFormaPago,
		SIGNAL(activated(int)),
		SLOT(SlotProducto(int)));

}
void QCtrlFormaPago::SlotProducto(int pintNProducto)
{
	SeleccionoFormaPago(pintNProducto);
}
void QCtrlFormaPago::setFocus()
{
  SiscomPasaFocoControl(QLEFormaPago);	
}

void QCtrlFormaPago::Limpia()
{
}
void QCtrlFormaPago::SeleccionoFormaPago(int pintNProducto)
{
	emit SignalFormaPago(CQSLFormaPago.at(pintNProducto));
}





