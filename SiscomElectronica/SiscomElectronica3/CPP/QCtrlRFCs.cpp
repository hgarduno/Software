#include <QCtrlRFCs.h>
#include <zSiscomElectronica.h>
#include <zSiscomConexion.h>
#include <zSiscomQt3.h>
#include <zSiscomRegistros.h>
#include <zSiscomRegistro.h>
#include <zSiscomDesarrollo4.h>

#include <qlayout.h>
#include <qcombobox.h>
#include <qlineedit.h>

QCtrlRFCs::QCtrlRFCs(QWidget *pQWParent,
		     const char *pchrPtrName):
		     QWidget(pQWParent,pchrPtrName)
{
IniciaVariables();
ConectaSlots();

}
void QCtrlRFCs::IniciaVariables()
{

QHBLayout=new QHBoxLayout(this);
QHBLayout->setMargin(0);
QCBRFCs=new QComboBox(this);
QHBLayout->addWidget(QCBRFCs);
QLERFC=zSiscomQt3::EditAlCombo(QCBRFCs,"QLERFC");
QCBRFCs->setAutoCompletion(true);
QCBRFCs->setDuplicatesEnabled(false);
//QCBRFCs->setInsertionPolicy(QComboBox::NoInsertion);
}
void QCtrlRFCs::Servidor(zSiscomConexion *pzSiscomConexion)
{
	zSisConexion=pzSiscomConexion;
} 
void QCtrlRFCs::IniciaControl()
{
   Consultando();
}
void QCtrlRFCs::ConectaSlots()
{
connect(QCBRFCs,
	SIGNAL(highlighted(int)),
	SLOT(SlotSeleccionando(int)));
connect(QCBRFCs,
	SIGNAL(activated(int)),
	SLOT(SlotSelecciono(int)));


connect(QCBRFCs,
	SIGNAL(textChanged(const QString &)),
	SLOT(SlotCambioRFC(const QString &)));

connect(QLERFC,SIGNAL(returnPressed()),SLOT(SlotCapturoRfc()));
}
void QCtrlRFCs::SlotCapturoRfc()
{

}
void QCtrlRFCs::SlotCambioRFC(const QString &pQStrRFC)
{

}
void QCtrlRFCs::SlotSeleccionoRFC()
{
   LogSiscom("El RFC Seleccionado %d",
   	      QCBRFCs->currentItem());
}
void QCtrlRFCs::SlotSelecciono(int pintNProducto)
{
 if(pintNProducto!=-1)
 emit SignalSelecciono((*zSisRegsRFCs)[pintNProducto]);
}
void QCtrlRFCs::SlotSeleccionando(int pintNProducto)
{
if(pintNProducto!=-1)
emit SignalSeleccionando((*zSisRegsRFCs)[pintNProducto]);
}
void QCtrlRFCs::ConsultaRFCs()
{
zSiscomElectronica lzSisElectronica(zSisConexion,"RFCs");
zSisRegsRFCs=lzSisElectronica.RFCs(0);  
}
void QCtrlRFCs::MuestraRFCs()
{
zSiscomQt3::RegistrosAlCombo(QCBRFCs,"rfc",zSisRegsRFCs);
}
QLineEdit *QCtrlRFCs::RFC()
{
	return QLERFC;
}
void QCtrlRFCs::setFocus()
{
zSiscomQt3::Foco(QLERFC);
}
void QCtrlRFCs::Consultando()
{
 ConsultaRFCs();
 MuestraRFCs();
}
