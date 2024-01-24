#include <QCtrlEstadosImpresosSE.h>
#include <zSiscomElectronica.h>
#include <zSiscomConexion.h>
#include <zSiscomQt3.h>
#include <zSiscomRegistros.h>
#include <zSiscomRegistro.h>

#include <qlayout.h>
#include <qcombobox.h>

QCtrlEstadosImpresosSE::QCtrlEstadosImpresosSE(QWidget *pQWParent,
				const char *pchrPtrName):
			QWidget(pQWParent,pchrPtrName)
{
IniciaVariables();
ConectaSlots();

}
void QCtrlEstadosImpresosSE::IniciaVariables()
{

QHBLayout=new QHBoxLayout(this);
QHBLayout->setMargin(0);
QCBEstadosImpresos=new QComboBox(this);
QHBLayout->addWidget(QCBEstadosImpresos);
QLEProducto=zSiscomQt3::EditAlCombo(QCBEstadosImpresos,"QLEProducto");
QCBEstadosImpresos->setAutoCompletion(true);
QCBEstadosImpresos->setDuplicatesEnabled(false);
QCBEstadosImpresos->setInsertionPolicy(QComboBox::NoInsertion);
}
void QCtrlEstadosImpresosSE::Servidor(zSiscomConexion *pzSiscomConexion)
{
	zSisConexion=pzSiscomConexion;
} 
void QCtrlEstadosImpresosSE::IniciaControl()
{
   Consultando();
}
void QCtrlEstadosImpresosSE::ConectaSlots()
{
connect(QCBEstadosImpresos,
	SIGNAL(highlighted(int)),
	SLOT(SlotSeleccionando(int)));
connect(QCBEstadosImpresos,
	SIGNAL(activated(int)),
	SLOT(SlotSelecciono(int)));
}
void QCtrlEstadosImpresosSE::SlotSelecciono(int pintNProducto)
{
 if(pintNProducto!=-1)
 emit SignalSelecciono((*zSisRegsEstadosImpresos)[pintNProducto]);
}
void QCtrlEstadosImpresosSE::SlotSeleccionando(int pintNProducto)
{
if(pintNProducto!=-1)
emit SignalSeleccionando((*zSisRegsEstadosImpresos)[pintNProducto]);
}
void QCtrlEstadosImpresosSE::ConsultaEstadosImpresos()
{
zSiscomElectronica lzSisElectronica(zSisConexion,"EstadosImpresosSE");
zSisRegsEstadosImpresos=lzSisElectronica.EstadosImpresos((const char *)0);
}
void QCtrlEstadosImpresosSE::MuestraEstadosImpresos()
{
zSiscomQt3::RegistrosAlCombo(QCBEstadosImpresos,"descripcion",zSisRegsEstadosImpresos);
}
QLineEdit *QCtrlEstadosImpresosSE::QLineEditProducto()
{
	return QLEProducto;
}
void QCtrlEstadosImpresosSE::setFocus()
{
zSiscomQt3::Foco(QLEProducto);
}
void QCtrlEstadosImpresosSE::Consultando()
{
 ConsultaEstadosImpresos();
 MuestraEstadosImpresos();
}
