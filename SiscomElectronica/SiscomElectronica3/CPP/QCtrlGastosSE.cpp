#include <QCtrlGastosSE.h>
#include <zSiscomElectronica.h>
#include <zSiscomConexion.h>
#include <zSiscomQt3.h>
#include <zSiscomRegistros.h>
#include <zSiscomRegistro.h>

#include <qlayout.h>
#include <qcombobox.h>

QCtrlGastosSE::QCtrlGastosSE(QWidget *pQWParent,
				const char *pchrPtrName):
			QWidget(pQWParent,pchrPtrName)
{
IniciaVariables();
ConectaSlots();

}
void QCtrlGastosSE::IniciaVariables()
{

QHBLayout=new QHBoxLayout(this);
QHBLayout->setMargin(0);
QCBGastos=new QComboBox(this);
QHBLayout->addWidget(QCBGastos);
QLEProducto=zSiscomQt3::EditAlCombo(QCBGastos,"QLEProducto");
QCBGastos->setAutoCompletion(true);
QCBGastos->setDuplicatesEnabled(false);
QCBGastos->setInsertionPolicy(QComboBox::NoInsertion);
}
void QCtrlGastosSE::Servidor(zSiscomConexion *pzSiscomConexion)
{
	zSisConexion=pzSiscomConexion;
} 
void QCtrlGastosSE::IniciaControl()
{
   Consultando();
}
void QCtrlGastosSE::ConectaSlots()
{
connect(QCBGastos,
	SIGNAL(highlighted(int)),
	SLOT(SlotSeleccionando(int)));
connect(QCBGastos,
	SIGNAL(activated(int)),
	SLOT(SlotSelecciono(int)));
}
void QCtrlGastosSE::SlotSelecciono(int pintNProducto)
{
 if(pintNProducto!=-1)
 emit SignalSelecciono((*zSisRegsGastos)[pintNProducto]);
}
void QCtrlGastosSE::SlotSeleccionando(int pintNProducto)
{
if(pintNProducto!=-1)
emit SignalSeleccionando((*zSisRegsGastos)[pintNProducto]);
}
void QCtrlGastosSE::ConsultaGastos()
{
zSiscomElectronica lzSisElectronica(zSisConexion,"GastosSiscom");
zSisRegsGastos=lzSisElectronica.Gastos((const char *)0);
}
void QCtrlGastosSE::MuestraGastos()
{
zSiscomQt3::RegistrosAlCombo(QCBGastos,"gasto",zSisRegsGastos);
}
QLineEdit *QCtrlGastosSE::QLineEditProducto()
{
	return QLEProducto;
}
void QCtrlGastosSE::setFocus()
{
zSiscomQt3::Foco(QLEProducto);
}
void QCtrlGastosSE::Consultando()
{
 ConsultaGastos();
 MuestraGastos();
}
