
#include <QCtrlFormaPago3Qt.h>
#include <SiscomDesarrollo3Qt++.h>
#include <SiscomOperaciones3.h>
#include <qlineedit.h>
#include <qcombobox.h>
#include <qlayout.h>


QCtrlFormaPago3Qt::QCtrlFormaPago3Qt( QWidget *parent, const char *name )
    : QWidget( parent, name )
{
	IniciaVariables();
	ConectaSlots();
}
void QCtrlFormaPago3Qt::IniciaVariables()
{
	QHBLayout=new QHBoxLayout(this);
	QHBLayout->setMargin(0);
	QCBFormaPago=new QComboBox(this);
	QHBLayout->addWidget(QCBFormaPago);
	QLEFormaPago=SiscomDesarrollo3Qt::ColocaEditAlCombo(QCBFormaPago,"QLEFormaPago");
	QCBFormaPago->setAutoCompletion(true);
	QCBFormaPago->setDuplicatesEnabled(false);
	QCBFormaPago->setInsertionPolicy(QComboBox::NoInsertion);
}
void QCtrlFormaPago3Qt::MuestraFormaPago()
{
SiscomDesarrollo3Qt::RegistrosAlCombo("nombre",
				      QCBFormaPago,
				      &SReg3LstFormaPago);
}
void QCtrlFormaPago3Qt::IniciaControl()
{
	ConsultaFormaPago();
	MuestraFormaPago();
	SeleccionoFormaPago(0);
}
void QCtrlFormaPago3Qt::ConsultaFormaPago()
{
SiscomOperaciones3 lSOpFPago(SisDatCom);
SiscomRegistro3Lst lSRegCons;
SiscomDesarrollo3Qt::ParametrosConsulta3(&lSRegCons,
					 "%s",
					 "FormaPago");
lSOpFPago.SiscomEnvia("ConsultaTiendas4",
		      &lSRegCons,
		      &SReg3LstFormaPago);
}
void QCtrlFormaPago3Qt::Servidor(SiscomDatCom *pSisDatCom)
{
	SisDatCom=pSisDatCom;
}
void QCtrlFormaPago3Qt::ConectaSlots()
{
	connect(QCBFormaPago,
		SIGNAL(activated(int)),
		SLOT(SlotFormaPago(int)));

}
void QCtrlFormaPago3Qt::SlotFormaPago(int pintNProducto)
{
	SeleccionoFormaPago(pintNProducto);
}
void QCtrlFormaPago3Qt::setFocus()
{
  SiscomDesarrollo3Qt::PasaFocoControl(QLEFormaPago);	
}

void QCtrlFormaPago3Qt::Limpia()
{
}
void QCtrlFormaPago3Qt::SeleccionoFormaPago(int pintNProducto)
{
	emit SignalFormaPago(SReg3LstFormaPago[pintNProducto]);
}




SiscomRegistro3 *QCtrlFormaPago3Qt::PrimerFormaPago()
{
   if(SReg3LstFormaPago.count())
    return SReg3LstFormaPago[0];
    else
    return 0;
}
