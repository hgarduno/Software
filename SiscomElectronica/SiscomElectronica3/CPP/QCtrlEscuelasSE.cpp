#include <QCtrlEscuelasSE.h>
#include <zSiscomElectronica.h>
#include <zSiscomConexion.h>
#include <zSiscomQt3.h>
#include <zSiscomRegistros.h>
#include <zSiscomRegistro.h>

#include <qlayout.h>
#include <qcombobox.h>
#include <qlineedit.h>

QCtrlEscuelasSE::QCtrlEscuelasSE(QWidget *pQWParent,
				const char *pchrPtrName):
			QWidget(pQWParent,pchrPtrName)
{
IniciaVariables();
ConectaSlots();

}
void QCtrlEscuelasSE::IniciaVariables()
{

QHBLayout=new QHBoxLayout(this);
QHBLayout->setMargin(0);
QCBEscuelas=new QComboBox(this);
QHBLayout->addWidget(QCBEscuelas);
QLEProducto=zSiscomQt3::EditAlCombo(QCBEscuelas,"QLEProducto");
QCBEscuelas->setAutoCompletion(true);
QCBEscuelas->setDuplicatesEnabled(false);
QCBEscuelas->setInsertionPolicy(QComboBox::NoInsertion);
}
void QCtrlEscuelasSE::Servidor(zSiscomConexion *pzSiscomConexion)
{
	zSisConexion=pzSiscomConexion;
} 
void QCtrlEscuelasSE::IniciaControl()
{
   Consultando();
}
void QCtrlEscuelasSE::ConectaSlots()
{
connect(QCBEscuelas,
	SIGNAL(highlighted(int)),
	SLOT(SlotSeleccionando(int)));
connect(QCBEscuelas,
	SIGNAL(activated(int)),
	SLOT(SlotSelecciono(int)));
}
void QCtrlEscuelasSE::SlotSelecciono(int pintNProducto)
{
 if(pintNProducto!=-1)
 emit SignalSelecciono((*zSisRegsEscuelas)[pintNProducto]);
}
void QCtrlEscuelasSE::SlotSeleccionando(int pintNProducto)
{
if(pintNProducto!=-1)
emit SignalSeleccionando((*zSisRegsEscuelas)[pintNProducto]);
}
void QCtrlEscuelasSE::ConsultaEscuelas()
{
zSiscomElectronica lzSisElectronica(zSisConexion,"EscuelasSE");
zSisRegsEscuelas=lzSisElectronica.Escuelas(0);  
}
void QCtrlEscuelasSE::MuestraEscuelas()
{
zSiscomQt3::RegistrosAlCombo(QCBEscuelas,"nombre",zSisRegsEscuelas);
}
QLineEdit *QCtrlEscuelasSE::QLineEditProducto()
{
	return QLEProducto;
}
void QCtrlEscuelasSE::setFocus()
{
zSiscomQt3::Foco(QLEProducto);
}
void QCtrlEscuelasSE::setReadOnly(bool pbEstado)
{
   QLEProducto->setReadOnly(pbEstado);  
}
void QCtrlEscuelasSE::Consultando()
{
 ConsultaEscuelas();
 MuestraEscuelas();
}
