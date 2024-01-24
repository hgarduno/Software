#include <QCtrlFormaPagoSat.h>
#include <zSiscomElectronica.h>
#include <zSiscomConexion.h>
#include <zSiscomQt3.h>
#include <zSiscomRegistros.h>
#include <zSiscomRegistro.h>

#include <qlayout.h>
#include <qcombobox.h>

QCtrlFormaPagoSat::QCtrlFormaPagoSat(QWidget *pQWParent,
				const char *pchrPtrName):
			QWidget(pQWParent,pchrPtrName)
{
IniciaVariables();
ConectaSlots();

}
void QCtrlFormaPagoSat::IniciaVariables()
{

QHBLayout=new QHBoxLayout(this);
QHBLayout->setMargin(0);
QCBFormasPagoSat=new QComboBox(this);
QHBLayout->addWidget(QCBFormasPagoSat);
QLEProducto=zSiscomQt3::EditAlCombo(QCBFormasPagoSat,"QLEProducto");
QCBFormasPagoSat->setAutoCompletion(true);
QCBFormasPagoSat->setDuplicatesEnabled(false);
QCBFormasPagoSat->setInsertionPolicy(QComboBox::NoInsertion);
}
void QCtrlFormaPagoSat::Servidor(zSiscomConexion *pzSiscomConexion)
{
	zSisConexion=pzSiscomConexion;
} 
void QCtrlFormaPagoSat::IniciaControl()
{
   Consultando();
}
void QCtrlFormaPagoSat::ConectaSlots()
{
connect(QCBFormasPagoSat,
	SIGNAL(highlighted(int)),
	SLOT(SlotSeleccionando(int)));
connect(QCBFormasPagoSat,
	SIGNAL(activated(int)),
	SLOT(SlotSelecciono(int)));
}
void QCtrlFormaPagoSat::SlotSelecciono(int pintNProducto)
{
 if(pintNProducto!=-1)
 emit SignalSelecciono((*zSisRegsFormasPagoSat)[pintNProducto]);
}
void QCtrlFormaPagoSat::SlotSeleccionando(int pintNProducto)
{
if(pintNProducto!=-1)
emit SignalSeleccionando((*zSisRegsFormasPagoSat)[pintNProducto]);
}
void QCtrlFormaPagoSat::ConsultaFormasPagoSat()
{
zSiscomElectronica lzSisElectronica(zSisConexion,"FormasPagoSat");
zSisRegsFormasPagoSat=lzSisElectronica.FormasPagoSat(0);  
}
void QCtrlFormaPagoSat::MuestraFormasPagoSat()
{
zSiscomQt3::RegistrosAlCombo(QCBFormasPagoSat,"formapago",zSisRegsFormasPagoSat);
}
QLineEdit *QCtrlFormaPagoSat::QLineEditProducto()
{
	return QLEProducto;
}
void QCtrlFormaPagoSat::setFocus()
{
zSiscomQt3::Foco(QLEProducto);
}
void QCtrlFormaPagoSat::Consultando()
{
 ConsultaFormasPagoSat();
 MuestraFormasPagoSat();
}
zSiscomRegistro *QCtrlFormaPagoSat::FormaPago(int pintNNFormaPago)
{
    return (*zSisRegsFormasPagoSat)[pintNNFormaPago];
}

const char *QCtrlFormaPagoSat::FormaPagoChar(int pintNNFormaPago)
{
    return (const char *)zSisRegsFormasPagoSat->CampoRegistro(pintNNFormaPago,"formapago");
}
