#include <QCtrlMetodoPagoSat.h>
#include <zSiscomElectronica.h>
#include <zSiscomConexion.h>
#include <zSiscomQt3.h>
#include <zSiscomRegistros.h>
#include <zSiscomRegistro.h>

#include <qlayout.h>
#include <qcombobox.h>

QCtrlMetodoPagoSat::QCtrlMetodoPagoSat(QWidget *pQWParent,
				const char *pchrPtrName):
			QWidget(pQWParent,pchrPtrName)
{
IniciaVariables();
ConectaSlots();

}
void QCtrlMetodoPagoSat::IniciaVariables()
{

QHBLayout=new QHBoxLayout(this);
QHBLayout->setMargin(0);
QCBMetodoPagoSat=new QComboBox(this);
QHBLayout->addWidget(QCBMetodoPagoSat);
QLEProducto=zSiscomQt3::EditAlCombo(QCBMetodoPagoSat,"QLEProducto");
QCBMetodoPagoSat->setAutoCompletion(true);
QCBMetodoPagoSat->setDuplicatesEnabled(false);
QCBMetodoPagoSat->setInsertionPolicy(QComboBox::NoInsertion);
}
void QCtrlMetodoPagoSat::Servidor(zSiscomConexion *pzSiscomConexion)
{
	zSisConexion=pzSiscomConexion;
} 
void QCtrlMetodoPagoSat::IniciaControl()
{
   Consultando();
}
void QCtrlMetodoPagoSat::ConectaSlots()
{
connect(QCBMetodoPagoSat,
	SIGNAL(highlighted(int)),
	SLOT(SlotSeleccionando(int)));
connect(QCBMetodoPagoSat,
	SIGNAL(activated(int)),
	SLOT(SlotSelecciono(int)));
}
void QCtrlMetodoPagoSat::SlotSelecciono(int pintNProducto)
{
 if(pintNProducto!=-1)
 emit SignalSelecciono((*zSisRegsMetodoPagoSat)[pintNProducto]);
}
void QCtrlMetodoPagoSat::SlotSeleccionando(int pintNProducto)
{
if(pintNProducto!=-1)
emit SignalSeleccionando((*zSisRegsMetodoPagoSat)[pintNProducto]);
}
void QCtrlMetodoPagoSat::ConsultaMetodoPagoSat()
{
zSiscomElectronica lzSisElectronica(zSisConexion,"MetodoPagoSat");
zSisRegsMetodoPagoSat=lzSisElectronica.MetodoPagoSat(0);  
}
void QCtrlMetodoPagoSat::MuestraMetodoPagoSat()
{
zSiscomQt3::RegistrosAlCombo(QCBMetodoPagoSat,"metodopago",zSisRegsMetodoPagoSat);
}
QLineEdit *QCtrlMetodoPagoSat::QLineEditProducto()
{
	return QLEProducto;
}
void QCtrlMetodoPagoSat::setFocus()
{
zSiscomQt3::Foco(QLEProducto);
}
void QCtrlMetodoPagoSat::Consultando()
{
 ConsultaMetodoPagoSat();
 MuestraMetodoPagoSat();
}
zSiscomRegistro *QCtrlMetodoPagoSat::MetodoPago(int pintNMetodoPago)
{
    return (*zSisRegsMetodoPagoSat)[pintNMetodoPago];
}
const char *QCtrlMetodoPagoSat::MetodoPagoChar(int pintNMetodoPago)
{
    return (const char *)zSisRegsMetodoPagoSat->CampoRegistro(pintNMetodoPago,"metodopago");
}

