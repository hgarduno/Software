#include <QCtrlRegimenFiscal.h>
#include <zSiscomElectronica.h>
#include <zSiscomConexion.h>
#include <zSiscomQt3.h>
#include <zSiscomRegistros.h>
#include <zSiscomRegistro.h>

#include <qlayout.h>
#include <qcombobox.h>
#include <qlineedit.h>

QCtrlRegimenFiscal::QCtrlRegimenFiscal(QWidget *pQWParent,
				const char *pchrPtrName):
			QWidget(pQWParent,pchrPtrName)
{
IniciaVariables();
ConectaSlots();

}
void QCtrlRegimenFiscal::IniciaVariables()
{

QHBLayout=new QHBoxLayout(this);
QHBLayout->setMargin(0);
QCBRegimenFiscal=new QComboBox(this);
QHBLayout->addWidget(QCBRegimenFiscal);
QLEProducto=zSiscomQt3::EditAlCombo(QCBRegimenFiscal,"QLEProducto");
QCBRegimenFiscal->setAutoCompletion(true);
QCBRegimenFiscal->setDuplicatesEnabled(false);
QCBRegimenFiscal->setInsertionPolicy(QComboBox::NoInsertion);
}
void QCtrlRegimenFiscal::Servidor(zSiscomConexion *pzSiscomConexion)
{
	zSisConexion=pzSiscomConexion;
} 
void QCtrlRegimenFiscal::IniciaControl()
{
   Consultando();
}
void QCtrlRegimenFiscal::ConectaSlots()
{
connect(QCBRegimenFiscal,
	SIGNAL(highlighted(int)),
	SLOT(SlotSeleccionando(int)));
connect(QCBRegimenFiscal,
	SIGNAL(activated(int)),
	SLOT(SlotSelecciono(int)));
connect(QLEProducto,
	SIGNAL(textChanged(const QString &)),
	SLOT(SlotCapturandoRegimenFiscal(const QString &)));
}
void QCtrlRegimenFiscal::SlotSelecciono(int pintNProducto)
{
 if(pintNProducto!=-1)
 emit SignalSelecciono((*zSisRegsRegimenFiscal)[pintNProducto]);
}
void QCtrlRegimenFiscal::SlotSeleccionando(int pintNProducto)
{
if(pintNProducto!=-1)
emit SignalSeleccionando((*zSisRegsRegimenFiscal)[pintNProducto]);
}
void QCtrlRegimenFiscal::ConsultaRegimenFiscal()
{
zSiscomElectronica lzSisElectronica(zSisConexion,"RegimenFiscal");
zSisRegsRegimenFiscal=lzSisElectronica.RegimenFiscal(0);  
}
void QCtrlRegimenFiscal::MuestraRegimenFiscal()
{
zSiscomQt3::RegistrosAlCombo(QCBRegimenFiscal,"regimensat",zSisRegsRegimenFiscal);
}
QLineEdit *QCtrlRegimenFiscal::QLineEditProducto()
{
	return QLEProducto;
}
void QCtrlRegimenFiscal::setFocus()
{
zSiscomQt3::Foco(QLEProducto);
}
void QCtrlRegimenFiscal::Consultando()
{
 ConsultaRegimenFiscal();
 MuestraRegimenFiscal();
}
zSiscomRegistro *QCtrlRegimenFiscal::MetodoPago(int pintNMetodoPago)
{
    return (*zSisRegsRegimenFiscal)[pintNMetodoPago];
}
const char *QCtrlRegimenFiscal::MetodoPagoChar(int pintNMetodoPago)
{
    return (const char *)zSisRegsRegimenFiscal->CampoRegistro(pintNMetodoPago,"metodopago");
}

void QCtrlRegimenFiscal::SlotCapturandoRegimenFiscal(const QString &pQStrCadena)
{
    emit SignalCapturandoRegimenFiscal(pQStrCadena);
}
