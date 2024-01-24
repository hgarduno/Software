
#include <QCtrlPrecios3Qt.h>
#include <SiscomDesarrollo3Qt++.h>
#include <SiscomOperaciones3.h>
#include <qcombobox.h>
#include <qlineedit.h>
#include <qlayout.h>


QCtrlPrecios3Qt::QCtrlPrecios3Qt( QWidget *parent, const char *name )
    : QWidget( parent, name )
{
	IniciaVariables();
	ConectaSlots();
}
QCtrlPrecios3Qt::~QCtrlPrecios3Qt()
{
}
SiscomRegistro3Lst &QCtrlPrecios3Qt::Precios()
{
return SReg3LstPrecios;
}
void QCtrlPrecios3Qt::IniciaVariables()
{
	QHBLayout=new QHBoxLayout(this);
	QHBLayout->setMargin(0);
	QCBPrecios=new QComboBox(this);
	QHBLayout->addWidget(QCBPrecios);
	QLEPrecios=SiscomDesarrollo3Qt::ColocaEditAlCombo(QCBPrecios,"QLEPrecios");
	QCBPrecios->setAutoCompletion(true);
	QCBPrecios->setDuplicatesEnabled(false);
	QCBPrecios->setInsertionPolicy(QComboBox::NoInsertion);
}
void QCtrlPrecios3Qt::MuestraPrecios()
{
SiscomDesarrollo3Qt::RegistrosAlCombo("nombre",
				      QCBPrecios,
				      &SReg3LstPrecios);
}
void QCtrlPrecios3Qt::IniciaControl()
{
	ConsultaPrecios();
	MuestraPrecios();
	SeleccionoPrecio(0);
	
}
void QCtrlPrecios3Qt::ConsultaPrecios()
{
SiscomOperaciones3 lSOpPrecios(SisDatCom);
lSOpPrecios.SiscomEnvia("ConsultaTiendas4",
		  &SReg3LstPrecios,
		  "%s",
		  "Precios");
}

void QCtrlPrecios3Qt::Servidor(SiscomDatCom *pSisDatCom)
{
	SisDatCom=pSisDatCom;
}
void QCtrlPrecios3Qt::ConectaSlots()
{
	connect(QCBPrecios,
		SIGNAL(activated(int)),
		SLOT(SlotPrecio(int)));
}
void QCtrlPrecios3Qt::SlotPrecio(int pintNPrecio)
{
	SeleccionoPrecio(pintNPrecio);
}
void QCtrlPrecios3Qt::setFocus()
{
SiscomDesarrollo3Qt::PasaFocoControl(QLEPrecios);	
}

void QCtrlPrecios3Qt::Limpia()
{
}
void QCtrlPrecios3Qt::SeleccionoPrecio(int pintNPrecio)
{
emit SignalPrecio(SReg3LstPrecios[pintNPrecio]);
}




SiscomRegistro3 *QCtrlPrecios3Qt::PrimerPrecio()
{
 if(SReg3LstPrecios.count())
  return SReg3LstPrecios[0];
 else
 return 0;
 }
