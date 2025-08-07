#include <QCtrlEstantes.h>
#include <zSiscomElectronica.h>
#include <zSiscomConexion.h>
#include <zSiscomQt3.h>
#include <zSiscomRegistros.h>
#include <zSiscomRegistro.h>
#include <zSiscomDesarrollo4.h>

#include <qlayout.h>
#include <qcombobox.h>
#include <qlineedit.h>

QCtrlEstantes::QCtrlEstantes(QWidget *pQWParent,
		     const char *pchrPtrName):
		     QWidget(pQWParent,pchrPtrName)
{
IniciaVariables();
ConectaSlots();

}
void QCtrlEstantes::IniciaVariables()
{

QHBLayout=new QHBoxLayout(this);
QHBLayout->setMargin(0);
QCBEstantes=new QComboBox(this);
QHBLayout->addWidget(QCBEstantes);
QLERFC=zSiscomQt3::EditAlCombo(QCBEstantes,"QLERFC");
QCBEstantes->setAutoCompletion(true);
QCBEstantes->setDuplicatesEnabled(false);
QCBEstantes->setInsertionPolicy(QComboBox::NoInsertion);
}
void QCtrlEstantes::Servidor(zSiscomConexion *pzSiscomConexion)
{
	zSisConexion=pzSiscomConexion;
} 
void QCtrlEstantes::IniciaControl()
{
   Consultando();
}
void QCtrlEstantes::ConectaSlots()
{
connect(QCBEstantes,
	SIGNAL(activated(int)),
	SLOT(SlotSelecciono(int)));



}
void QCtrlEstantes::SlotSelecciono(int pintNProducto)
{
 if(pintNProducto!=-1)
 emit SignalSelecciono((*zSisRegsEstantes)[pintNProducto]);
}
void QCtrlEstantes::ConsultaEstantes()
{
zSiscomElectronica lzSisElectronica(zSisConexion,"Estantes");
zSisRegsEstantes=lzSisElectronica.Estantes(); 
}
void QCtrlEstantes::MuestraEstantes()
{
zSiscomQt3::RegistrosAlCombo(QCBEstantes,"estante",zSisRegsEstantes);
}
QLineEdit *QCtrlEstantes::RFC()
{
	return QLERFC;
}
void QCtrlEstantes::setFocus()
{
zSiscomQt3::Foco(QLERFC);
}
void QCtrlEstantes::Consultando()
{
 ConsultaEstantes();
 MuestraEstantes();
}
void QCtrlEstantes::IdEscuela(const char *pchrPtrIdEscuela)
{
    chrPtrIdEscuela=pchrPtrIdEscuela;
}
void QCtrlEstantes::ReConsultando()
{
 QCBEstantes->clear();
 Consultando();
}
