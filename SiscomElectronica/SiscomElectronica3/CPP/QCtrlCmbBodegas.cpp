#include <QCtrlCmbBodegas.h>
#include <SiscomDesarrollo3Qt++.h>
#include <SiscomOperaciones3.h>
#include <SiscomParametroConsulta3.h>
#include <SiscomDatCom.h>
#include <qlayout.h>
#include <qcombobox.h>

QCtrlCmbBodegas::QCtrlCmbBodegas(
				QWidget *pQWParent,
				const char *pchrPtrName):
			QWidget(pQWParent,pchrPtrName)
{
gPtrFleArchivoLog3Qt=stdout;
IniciaVariables();
ConectaSlots();

}
void QCtrlCmbBodegas::IniciaVariables()
{

QHBLayout=new QHBoxLayout(this);
QHBLayout->setMargin(0);
QCBProductos=new QComboBox(this);
QHBLayout->addWidget(QCBProductos);
QLEBodega=SiscomDesarrollo3Qt::ColocaEditAlCombo(QCBProductos,"QLEBodega");
QCBProductos->setAutoCompletion(true);
QCBProductos->setDuplicatesEnabled(false);
QCBProductos->setInsertionPolicy(QComboBox::NoInsertion);
}
void QCtrlCmbBodegas::Servidor(SiscomDatCom *pSisDatCom)
{
	SisDatCom=pSisDatCom;
}
void QCtrlCmbBodegas::IniciaControl()
{
	ConsultaBodegas();
	MuestraBodegas();
}
void QCtrlCmbBodegas::ConectaSlots()
{
connect(QCBProductos,
	SIGNAL(highlighted(int)),
	SLOT(SlotSeleccionando(int)));
connect(QCBProductos,
	SIGNAL(activated(int)),
	SLOT(SlotSelecciono(int)));
}
void QCtrlCmbBodegas::SlotSelecciono(int pintNProducto)
{
 if(pintNProducto!=-1)
 emit SignalSelecciono(SReg3LstBodegas[pintNProducto]);
}
void QCtrlCmbBodegas::SlotSeleccionando(int pintNProducto)
{
if(pintNProducto!=-1)
emit SignalSeleccionando(SReg3LstBodegas[pintNProducto]);
}
void QCtrlCmbBodegas::ConsultaBodegas()
{
SiscomOperaciones3 lSOp3Bodegas(SisDatCom);
lSOp3Bodegas.SiscomEnvia("ConsultasSiscomElectronica2",
			   &SReg3LstBodegas,
			   "%s%s",
			   "BodegasExpendio",
			   chrPtrIdExpendio);
}
void QCtrlCmbBodegas::MuestraBodegas()
{
SiscomRegistro3 *lSRegistro3;
for(lSRegistro3=SReg3LstBodegas.first();
    lSRegistro3;
    lSRegistro3=SReg3LstBodegas.next())
QCBProductos->insertItem((*lSRegistro3)["bodega"]);
}
QLineEdit *QCtrlCmbBodegas::QLineEditBodega()
{
	return QLEBodega;
}
void QCtrlCmbBodegas::setFocus()
{
	SiscomDesarrollo3Qt::PasaFocoControl(QLEBodega);
}
void QCtrlCmbBodegas::Expendio(const char *pchrPtrIdExpendio)
{

	chrPtrIdExpendio=pchrPtrIdExpendio;
}
