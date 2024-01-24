#include <QCtrlProdSiscomElectronica.h>
#include <SiscomDesarrollo3Qt++.h>
#include <SiscomOperaciones3.h>
#include <SiscomParametroConsulta3.h>
#include <SiscomDatCom.h>
#include <qlayout.h>
#include <qcombobox.h>

QCtrlProdSiscomElectronica::QCtrlProdSiscomElectronica(
				QWidget *pQWParent,
				const char *pchrPtrName):
			QWidget(pQWParent,pchrPtrName)
{
gPtrFleArchivoLog3Qt=stdout;
IniciaVariables();
ConectaSlots();

}
void QCtrlProdSiscomElectronica::IniciaVariables()
{

QHBLayout=new QHBoxLayout(this);
QHBLayout->setMargin(0);
QCBProductos=new QComboBox(this);
QHBLayout->addWidget(QCBProductos);
QLEProducto=SiscomDesarrollo3Qt::ColocaEditAlCombo(QCBProductos,"QLEProducto");
QCBProductos->setAutoCompletion(true);
QCBProductos->setDuplicatesEnabled(false);
QCBProductos->setInsertionPolicy(QComboBox::NoInsertion);
}
void QCtrlProdSiscomElectronica::Servidor(SiscomDatCom *pSisDatCom)
{
	SisDatCom=pSisDatCom;
}
void QCtrlProdSiscomElectronica::IniciaControl()
{
	ConsultaProductos();
	MuestraProductos();
}
void QCtrlProdSiscomElectronica::ConectaSlots()
{
connect(QCBProductos,
	SIGNAL(highlighted(int)),
	SLOT(SlotSeleccionando(int)));
connect(QCBProductos,
	SIGNAL(activated(int)),
	SLOT(SlotSelecciono(int)));
}
void QCtrlProdSiscomElectronica::SlotSelecciono(int pintNProducto)
{
 if(pintNProducto!=-1)
 emit SignalSelecciono(SRegistro3LstProds[pintNProducto]);
}
void QCtrlProdSiscomElectronica::SlotSeleccionando(int pintNProducto)
{
if(pintNProducto!=-1)
emit SignalSeleccionando(SRegistro3LstProds[pintNProducto]);
}
void QCtrlProdSiscomElectronica::ConsultaProductos()
{
SiscomOperaciones3 lSOperaciones3Prods(SisDatCom);
SiscomRegistro3Lst lSRegistro3LstCns;
lSRegistro3LstCns << 
new SiscomParametroConsulta3("ConsultaSimilares") <<
new SiscomParametroConsulta3("")		  <<
new SiscomParametroConsulta3("")		  <<
new SiscomParametroConsulta3("")		  <<
new SiscomParametroConsulta3(chrPtrIdExpendio);
lSOperaciones3Prods.SiscomEnvia("ConsultaProductos",
			        &lSRegistro3LstCns,
				&SRegistro3LstProds);
}
void QCtrlProdSiscomElectronica::MuestraProductos()
{
SiscomRegistro3 *lSRegistro3;
for(lSRegistro3=SRegistro3LstProds.first();
    lSRegistro3;
    lSRegistro3=SRegistro3LstProds.next())
QCBProductos->insertItem((*lSRegistro3)["cveproducto"]);
}
QLineEdit *QCtrlProdSiscomElectronica::QLineEditProducto()
{
	return QLEProducto;
}
void QCtrlProdSiscomElectronica::setFocus()
{
	SiscomDesarrollo3Qt::PasaFocoControl(QLEProducto);
}
void QCtrlProdSiscomElectronica::IdExpendio(const char *pchrPtrIdExpendio)
{
     chrPtrIdExpendio=pchrPtrIdExpendio;
}
