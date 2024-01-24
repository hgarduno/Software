#include <QCtrlClientesMayoreo.h>
#include <zSiscomElectronica.h>
#include <zSiscomConexion.h>
#include <zSiscomQt3.h>
#include <zSiscomRegistros.h>
#include <zSiscomRegistro.h>

#include <qlayout.h>
#include <qcombobox.h>

QCtrlClientesMayoreo::QCtrlClientesMayoreo(QWidget *pQWParent,
				const char *pchrPtrName):
			QWidget(pQWParent,pchrPtrName)
{
IniciaVariables();
ConectaSlots();

}
void QCtrlClientesMayoreo::IniciaVariables()
{

QHBLayout=new QHBoxLayout(this);
QHBLayout->setMargin(0);
QCBClientesMayoreo=new QComboBox(this);
QHBLayout->addWidget(QCBClientesMayoreo);
QLEProducto=zSiscomQt3::EditAlCombo(QCBClientesMayoreo,"QLEProducto");
QCBClientesMayoreo->setAutoCompletion(true);
QCBClientesMayoreo->setDuplicatesEnabled(false);
QCBClientesMayoreo->setInsertionPolicy(QComboBox::NoInsertion);
}
void QCtrlClientesMayoreo::Servidor(zSiscomConexion *pzSiscomConexion)
{
	zSisConexion=pzSiscomConexion;
} 
void QCtrlClientesMayoreo::IniciaControl()
{
   Consultando();
}
void QCtrlClientesMayoreo::ConectaSlots()
{
connect(QCBClientesMayoreo,
	SIGNAL(highlighted(int)),
	SLOT(SlotSeleccionando(int)));
connect(QCBClientesMayoreo,
	SIGNAL(activated(int)),
	SLOT(SlotSelecciono(int)));
}
void QCtrlClientesMayoreo::SlotSelecciono(int pintNProducto)
{
 if(pintNProducto!=-1)
 emit SignalSelecciono((*zSisRegsClientesMayoreo)[pintNProducto]);
}
void QCtrlClientesMayoreo::SlotSeleccionando(int pintNProducto)
{
if(pintNProducto!=-1)
emit SignalSeleccionando((*zSisRegsClientesMayoreo)[pintNProducto]);
}
void QCtrlClientesMayoreo::ConsultaClientesMayoreo()
{
zSiscomElectronica lzSisElectronica(zSisConexion,"ClientesMayoreo");
lzSisElectronica.ClientesMayoreo(&zSisRegsClientesMayoreo);
}
void QCtrlClientesMayoreo::MuestraClientesMayoreo()
{
zSiscomQt3::RegistrosAlCombo(QCBClientesMayoreo,"nombre",zSisRegsClientesMayoreo);
}
QLineEdit *QCtrlClientesMayoreo::QLineEditProducto()
{
	return QLEProducto;
}
void QCtrlClientesMayoreo::setFocus()
{
zSiscomQt3::Foco(QLEProducto);
}
void QCtrlClientesMayoreo::Consultando()
{
 ConsultaClientesMayoreo();
 MuestraClientesMayoreo();
}
