#include <QCtrlUsoCFDISat.h>
#include <zSiscomElectronica.h>
#include <zSiscomConexion.h>
#include <zSiscomQt3.h>
#include <zSiscomRegistros.h>
#include <zSiscomRegistro.h>

#include <qlayout.h>
#include <qcombobox.h>

QCtrlUsoCFDISat::QCtrlUsoCFDISat(QWidget *pQWParent,
				const char *pchrPtrName):
			QWidget(pQWParent,pchrPtrName)
{
IniciaVariables();
ConectaSlots();

}
void QCtrlUsoCFDISat::IniciaVariables()
{

QHBLayout=new QHBoxLayout(this);
QHBLayout->setMargin(0);
QCBUsoCFDISat=new QComboBox(this);
QHBLayout->addWidget(QCBUsoCFDISat);
QLEProducto=zSiscomQt3::EditAlCombo(QCBUsoCFDISat,"QLEProducto");
QCBUsoCFDISat->setAutoCompletion(true);
QCBUsoCFDISat->setDuplicatesEnabled(false);
QCBUsoCFDISat->setInsertionPolicy(QComboBox::NoInsertion);
}
void QCtrlUsoCFDISat::Servidor(zSiscomConexion *pzSiscomConexion)
{
	zSisConexion=pzSiscomConexion;
} 
void QCtrlUsoCFDISat::IniciaControl()
{
   Consultando();
}
void QCtrlUsoCFDISat::ConectaSlots()
{
connect(QCBUsoCFDISat,
	SIGNAL(highlighted(int)),
	SLOT(SlotSeleccionando(int)));
connect(QCBUsoCFDISat,
	SIGNAL(activated(int)),
	SLOT(SlotSelecciono(int)));
}
void QCtrlUsoCFDISat::SlotSelecciono(int pintNProducto)
{
 if(pintNProducto!=-1)
 emit SignalSelecciono((*zSisRegsUsoCFDISat)[pintNProducto]);
}
void QCtrlUsoCFDISat::SlotSeleccionando(int pintNProducto)
{
if(pintNProducto!=-1)
emit SignalSeleccionando((*zSisRegsUsoCFDISat)[pintNProducto]);
}
void QCtrlUsoCFDISat::ConsultaUsoCFDISat()
{
zSiscomElectronica lzSisElectronica(zSisConexion,"UsoFacturaSat");
zSisRegsUsoCFDISat=lzSisElectronica.UsoFacturaSat(0);  
}
void QCtrlUsoCFDISat::MuestraUsoCFDISat()
{
zSiscomQt3::RegistrosAlCombo(QCBUsoCFDISat,"usocodigo",zSisRegsUsoCFDISat);
}
QLineEdit *QCtrlUsoCFDISat::QLineEditProducto()
{
	return QLEProducto;
}
void QCtrlUsoCFDISat::setFocus()
{
zSiscomQt3::Foco(QLEProducto);
}
void QCtrlUsoCFDISat::Consultando()
{
 ConsultaUsoCFDISat();
 MuestraUsoCFDISat();
}
zSiscomRegistro *QCtrlUsoCFDISat::UsoFactura(int pintNUsoFactura)
{
   return (*zSisRegsUsoCFDISat)[pintNUsoFactura];
}

const char *QCtrlUsoCFDISat::UsoFacturaChar(int pintNUsoFactura)
{
   return (const char *)zSisRegsUsoCFDISat->CampoRegistro(pintNUsoFactura,"uso");
}
