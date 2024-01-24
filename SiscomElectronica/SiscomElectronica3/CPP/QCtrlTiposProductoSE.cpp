#include <QCtrlProveedoresSE.h>
#include <zSiscomElectronica.h>
#include <zSiscomConexion.h>
#include <zSiscomQt3.h>
#include <zSiscomRegistros.h>
#include <zSiscomRegistro.h>

#include <qlayout.h>
#include <qcombobox.h>

QCtrlProveedoresSE::QCtrlProveedoresSE(QWidget *pQWParent,
				const char *pchrPtrName):
			QWidget(pQWParent,pchrPtrName)
{
IniciaVariables();
ConectaSlots();

}
void QCtrlProveedoresSE::IniciaVariables()
{

QHBLayout=new QHBoxLayout(this);
QHBLayout->setMargin(0);
QCBProveedores=new QComboBox(this);
QHBLayout->addWidget(QCBProveedores);
QLEProducto=zSiscomQt3::EditAlCombo(QCBProveedores,"QLEProducto");
QCBProveedores->setAutoCompletion(true);
QCBProveedores->setDuplicatesEnabled(false);
QCBProveedores->setInsertionPolicy(QComboBox::NoInsertion);
}
void QCtrlProveedoresSE::Servidor(zSiscomConexion *pzSiscomConexion)
{
	zSisConexion=pzSiscomConexion;
} 
void QCtrlProveedoresSE::IniciaControl()
{
   Consultando();
}
void QCtrlProveedoresSE::ConectaSlots()
{
connect(QCBProveedores,
	SIGNAL(highlighted(int)),
	SLOT(SlotSeleccionando(int)));
connect(QCBProveedores,
	SIGNAL(activated(int)),
	SLOT(SlotSelecciono(int)));
}
void QCtrlProveedoresSE::SlotSelecciono(int pintNProducto)
{
 if(pintNProducto!=-1)
 emit SignalSelecciono((*zSisRegsProveedores)[pintNProducto]);
}
void QCtrlProveedoresSE::SlotSeleccionando(int pintNProducto)
{
if(pintNProducto!=-1)
emit SignalSeleccionando((*zSisRegsProveedores)[pintNProducto]);
}
void QCtrlProveedoresSE::ConsultaProveedores()
{
zSiscomElectronica lzSisElectronica(zSisConexion,"ProveedoresSE");
lzSisElectronica.Proveedores(&zSisRegsProveedores);
}
void QCtrlProveedoresSE::MuestraProveedores()
{
zSiscomQt3::RegistrosAlCombo(QCBProveedores,"razonsocial",zSisRegsProveedores);
}
QLineEdit *QCtrlProveedoresSE::QLineEditProducto()
{
	return QLEProducto;
}
void QCtrlProveedoresSE::setFocus()
{
zSiscomQt3::Foco(QLEProducto);
}
void QCtrlProveedoresSE::Consultando()
{
 ConsultaProveedores();
 MuestraProveedores();
}
