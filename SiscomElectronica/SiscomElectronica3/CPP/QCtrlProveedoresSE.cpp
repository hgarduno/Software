#include <QCtrlTiposProductoSE.h>
#include <zSiscomElectronica.h>
#include <zSiscomConexion.h>
#include <zSiscomQt3.h>
#include <zSiscomRegistros.h>
#include <zSiscomRegistro.h>

#include <qlayout.h>
#include <qcombobox.h>
#include <qlineedit.h>

QCtrlTiposProductoSE::QCtrlTiposProductoSE(QWidget *pQWParent,
				const char *pchrPtrName):
			QWidget(pQWParent,pchrPtrName)
{
IniciaVariables();
ConectaSlots();

}
void QCtrlTiposProductoSE::IniciaVariables()
{

QHBLayout=new QHBoxLayout(this);
QHBLayout->setMargin(0);
QCBTiposProducto=new QComboBox(this);
QHBLayout->addWidget(QCBTiposProducto);
QLEProducto=zSiscomQt3::EditAlCombo(QCBTiposProducto,"QLEProducto");
QCBTiposProducto->setAutoCompletion(true);
QCBTiposProducto->setDuplicatesEnabled(false);
QCBTiposProducto->setInsertionPolicy(QComboBox::NoInsertion);
}
void QCtrlTiposProductoSE::Servidor(zSiscomConexion *pzSiscomConexion)
{
	zSisConexion=pzSiscomConexion;
} 
void QCtrlTiposProductoSE::IniciaControl()
{
   Consultando();
}
void QCtrlTiposProductoSE::ConectaSlots()
{
connect(QCBTiposProducto,
	SIGNAL(highlighted(int)),
	SLOT(SlotSeleccionando(int)));
connect(QCBTiposProducto,
	SIGNAL(activated(int)),
	SLOT(SlotSelecciono(int)));
}
void QCtrlTiposProductoSE::SlotSelecciono(int pintNProducto)
{
 if(pintNProducto!=-1)
 emit SignalSelecciono((*zSisRegsTiposProducto)[pintNProducto]);
}
void QCtrlTiposProductoSE::SlotSeleccionando(int pintNProducto)
{
if(pintNProducto!=-1)
emit SignalSeleccionando((*zSisRegsTiposProducto)[pintNProducto]);
}
void QCtrlTiposProductoSE::ConsultaTiposProducto()
{
zSiscomElectronica lzSisElectronica(zSisConexion,"TiposProductoSE");
zSisRegsTiposProducto=lzSisElectronica.TiposProducto((const char *)0);
}
void QCtrlTiposProductoSE::MuestraTiposProducto()
{
zSiscomQt3::RegistrosAlCombo(QCBTiposProducto,"descripcion",zSisRegsTiposProducto);
}
QLineEdit *QCtrlTiposProductoSE::QLineEditProducto()
{
	return QLEProducto;
}
void QCtrlTiposProductoSE::setFocus()
{
zSiscomQt3::Foco(QLEProducto);
}
void QCtrlTiposProductoSE::Consultando()
{
 ConsultaTiposProducto();
 MuestraTiposProducto();
}
