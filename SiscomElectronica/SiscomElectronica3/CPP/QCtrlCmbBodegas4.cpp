#include <QCtrlCmbBodegas4.h>

#include <zBodegas.h>
#include <zBodega.h>
#include <zSiscomElectronica.h>
#include <zSiscomConexion.h>
#include <zSiscomQt3.h>
#include <zSiscomRegistros.h>
#include <zSiscomRegistro.h>
#include <zSiscomDesarrollo4.h>

#include <qlayout.h>
#include <qcombobox.h>

QCtrlCmbBodegas4::QCtrlCmbBodegas4(QWidget *pQWParent,
				const char *pchrPtrName):
			QWidget(pQWParent,pchrPtrName)
{
IniciaVariables();
ConectaSlots();

}
void QCtrlCmbBodegas4::IniciaVariables()
{

QHBLayout=new QHBoxLayout(this);
QHBLayout->setMargin(0);
QCBBodegas4=new QComboBox(this);
QHBLayout->addWidget(QCBBodegas4);
QLEProducto=zSiscomQt3::EditAlCombo(QCBBodegas4,"QLEProducto");
QCBBodegas4->setAutoCompletion(true);
QCBBodegas4->setDuplicatesEnabled(false);
QCBBodegas4->setInsertionPolicy(QComboBox::NoInsertion);
}
void QCtrlCmbBodegas4::Servidor(zSiscomConexion *pzSiscomConexion)
{
	zSisConexion=pzSiscomConexion;
} 
void QCtrlCmbBodegas4::IniciaControl()
{
   Consultando();
}
void QCtrlCmbBodegas4::ConectaSlots()
{
/*
connect(QCBBodegas4,
	SIGNAL(highlighted(int)),
	SLOT(SlotSeleccionando(int)));
*/
connect(QCBBodegas4,
	SIGNAL(activated(int)),
	SLOT(SlotSelecciono(int)));
}
void QCtrlCmbBodegas4::SlotSelecciono(int pintNProducto)
{
 if(pintNProducto!=-1)
 emit SignalSelecciono((zBodega *)(*zBodegasE)[pintNProducto]);
}
void QCtrlCmbBodegas4::SlotSeleccionando(int pintNProducto)
{
if(pintNProducto!=-1)
emit SignalSeleccionando((zBodega *)(*zBodegasE)[pintNProducto]);
}
void QCtrlCmbBodegas4::ConsultaBodegas4()
{
zSiscomElectronica lzSisElectronica(zSisConexion,"BodegasExpendios");
lzSisElectronica.BodegasExpendios(&zBodegasE);
}
void QCtrlCmbBodegas4::MuestraBodegas4()
{
zSiscomQt3::RegistrosAlCombo(QCBBodegas4,"Bodega",zBodegasE);
}
QLineEdit *QCtrlCmbBodegas4::QLineEditProducto()
{
	return QLEProducto;
}
void QCtrlCmbBodegas4::setFocus()
{
LogSiscom("El Foco al combo");
zSiscomQt3::Foco(QLEProducto);
}
void QCtrlCmbBodegas4::Consultando()
{
 ConsultaBodegas4();
 MuestraBodegas4();
}
zBodega *QCtrlCmbBodegas4::Bodega(int pintNNFormaPago)
{
    return (zBodega *)(*zBodegasE)[pintNNFormaPago];
}
