#include <QCtrlMateriasSE.h>
#include <zSiscomElectronica.h>
#include <zSiscomConexion.h>
#include <zSiscomQt3.h>
#include <zSiscomRegistros.h>
#include <zSiscomRegistro.h>
#include <zSiscomDesarrollo4.h>

#include <qlayout.h>
#include <qcombobox.h>
#include <qlineedit.h>

QCtrlMateriasSE::QCtrlMateriasSE(QWidget *pQWParent,
		     const char *pchrPtrName):
		     QWidget(pQWParent,pchrPtrName)
{
IniciaVariables();
ConectaSlots();

}
void QCtrlMateriasSE::IniciaVariables()
{

QHBLayout=new QHBoxLayout(this);
QHBLayout->setMargin(0);
QCBMateriasSE=new QComboBox(this);
QHBLayout->addWidget(QCBMateriasSE);
QLERFC=zSiscomQt3::EditAlCombo(QCBMateriasSE,"QLERFC");
QCBMateriasSE->setAutoCompletion(true);
QCBMateriasSE->setDuplicatesEnabled(false);
//QCBMateriasSE->setInsertionPolicy(QComboBox::NoInsertion);
}
void QCtrlMateriasSE::Servidor(zSiscomConexion *pzSiscomConexion)
{
	zSisConexion=pzSiscomConexion;
} 
void QCtrlMateriasSE::IniciaControl()
{
   Consultando();
}
void QCtrlMateriasSE::ConectaSlots()
{
connect(QCBMateriasSE,
	SIGNAL(highlighted(int)),
	SLOT(SlotSeleccionando(int)));
connect(QCBMateriasSE,
	SIGNAL(activated(int)),
	SLOT(SlotSelecciono(int)));


connect(QCBMateriasSE,
	SIGNAL(textChanged(const QString &)),
	SLOT(SlotCambioRFC(const QString &)));

connect(QLERFC,SIGNAL(returnPressed()),SLOT(SlotCapturoRfc()));
}
void QCtrlMateriasSE::SlotCapturoRfc()
{

}
void QCtrlMateriasSE::SlotCambioRFC(const QString &pQStrRFC)
{

}
void QCtrlMateriasSE::SlotSeleccionoRFC()
{
   LogSiscom("El RFC Seleccionado %d",
   	      QCBMateriasSE->currentItem());
}
void QCtrlMateriasSE::SlotSelecciono(int pintNProducto)
{
 if(pintNProducto!=-1)
 emit SignalSelecciono((*zSisRegsMateriasSE)[pintNProducto]);
}
void QCtrlMateriasSE::SlotSeleccionando(int pintNProducto)
{
if(pintNProducto!=-1)
emit SignalSeleccionando((*zSisRegsMateriasSE)[pintNProducto]);
}
void QCtrlMateriasSE::ConsultaMateriasSE()
{
zSiscomElectronica lzSisElectronica(zSisConexion,"MateriasSE");
zSisRegsMateriasSE=lzSisElectronica.Materias(0); 
}
void QCtrlMateriasSE::MuestraMateriasSE()
{
zSiscomQt3::RegistrosAlCombo(QCBMateriasSE,"rfc",zSisRegsMateriasSE);
}
QLineEdit *QCtrlMateriasSE::RFC()
{
	return QLERFC;
}
void QCtrlMateriasSE::setFocus()
{
zSiscomQt3::Foco(QLERFC);
}
void QCtrlMateriasSE::Consultando()
{
 ConsultaMateriasSE();
 MuestraMateriasSE();
}
void QCtrlMateriasSE::IdEscuela(const char *pchrPtrIdEscuela)
{
    chrPtrIdEscuela=pchrPtrIdEscuela;
}
