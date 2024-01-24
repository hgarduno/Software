#include <QCtrlEstadosPedidosClienteSE.h>
#include <zSiscomElectronica.h>
#include <zSiscomConexion.h>
#include <zSiscomQt3.h>
#include <zSiscomRegistros.h>
#include <zSiscomRegistro.h>

#include <qlayout.h>
#include <qcombobox.h>

QCtrlEstadosPedidosClienteSE::QCtrlEstadosPedidosClienteSE(QWidget *pQWParent,
				const char *pchrPtrName):
			QWidget(pQWParent,pchrPtrName)
{
IniciaVariables();
ConectaSlots();

}
void QCtrlEstadosPedidosClienteSE::IniciaVariables()
{

QHBLayout=new QHBoxLayout(this);
QHBLayout->setMargin(0);
QCBEstadosPedidos=new QComboBox(this);
QHBLayout->addWidget(QCBEstadosPedidos);
QLEProducto=zSiscomQt3::EditAlCombo(QCBEstadosPedidos,"QLEProducto");
QCBEstadosPedidos->setAutoCompletion(true);
QCBEstadosPedidos->setDuplicatesEnabled(false);
QCBEstadosPedidos->setInsertionPolicy(QComboBox::NoInsertion);
}
void QCtrlEstadosPedidosClienteSE::Servidor(zSiscomConexion *pzSiscomConexion)
{
	zSisConexion=pzSiscomConexion;
} 
void QCtrlEstadosPedidosClienteSE::IniciaControl()
{
   Consultando();
}
void QCtrlEstadosPedidosClienteSE::ConectaSlots()
{
connect(QCBEstadosPedidos,
	SIGNAL(highlighted(int)),
	SLOT(SlotSeleccionando(int)));
connect(QCBEstadosPedidos,
	SIGNAL(activated(int)),
	SLOT(SlotSelecciono(int)));
}
void QCtrlEstadosPedidosClienteSE::SlotSelecciono(int pintNProducto)
{
 if(pintNProducto!=-1)
 emit SignalSelecciono((*zSisRegsEstadosPedidos)[pintNProducto]);
}
void QCtrlEstadosPedidosClienteSE::SlotSeleccionando(int pintNProducto)
{
if(pintNProducto!=-1)
emit SignalSeleccionando((*zSisRegsEstadosPedidos)[pintNProducto]);
}
void QCtrlEstadosPedidosClienteSE::ConsultaEstadosPedidos()
{
zSiscomElectronica lzSisElectronica(zSisConexion,"EstadosPedidosCliente");
zSisRegsEstadosPedidos=lzSisElectronica.EstadosPedidos((const char *)0);
}
void QCtrlEstadosPedidosClienteSE::MuestraEstadosPedidos()
{
zSiscomQt3::RegistrosAlCombo(QCBEstadosPedidos,"dscedopedido",zSisRegsEstadosPedidos);
}
QLineEdit *QCtrlEstadosPedidosClienteSE::QLineEditProducto()
{
	return QLEProducto;
}
void QCtrlEstadosPedidosClienteSE::setFocus()
{
zSiscomQt3::Foco(QLEProducto);
}
void QCtrlEstadosPedidosClienteSE::Consultando()
{
 ConsultaEstadosPedidos();
 MuestraEstadosPedidos();
}
