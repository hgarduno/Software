#include <QCtrlEmpresas.h>
#include <CQSisOpTiendas4.h>
#include <SISCOMComunicaciones++.h>
#include <qlayout.h>


QCtrlEmpresas::QCtrlEmpresas( QWidget *parent, const char *name )
    : QWidget( parent, name )
{
	IniciaVariables();
	ConectaSlots();
}
void QCtrlEmpresas::IniciaVariables()
{
	QHBLayout=new QHBoxLayout(this);
	QHBLayout->setMargin(0);
	QCBEmpresas=new QComboBox(this);
	QHBLayout->addWidget(QCBEmpresas);
	QLEEmpresas=SiscomColocaEditAlCombo(QCBEmpresas,"QLEEmpresas");
	QCBEmpresas->setAutoCompletion(true);
	QCBEmpresas->setDuplicatesEnabled(false);
	QCBEmpresas->setInsertionPolicy(QComboBox::NoInsertion);
}
void QCtrlEmpresas::MuestraEmpresas()
{
CQSisEmpresa *lCQSProducto;
  for(lCQSProducto=CQSLEmpresas.first();
      lCQSProducto;
      lCQSProducto=CQSLEmpresas.next())
     QCBEmpresas->insertItem(lCQSProducto->SRegistrosPro2["RazonSocial"]);
}
void QCtrlEmpresas::IniciaControl()
{
	ConsultaEmpresas();
	MuestraEmpresas();
	ConectaSlots();
}
void QCtrlEmpresas::ConsultaEmpresas()
{
CQSisOpTiendas4 lCQSOT4Empresas(SisDatCom);
	lCQSOT4Empresas.Proveedores(&CQSLEmpresas);
}
void QCtrlEmpresas::PonServidor(SiscomDatCom *pSisDatCom)
{
	SisDatCom=pSisDatCom;
}
void QCtrlEmpresas::ConectaSlots()
{
	connect(QCBEmpresas,
		SIGNAL(activated(int)),
		SLOT(SlotProducto(int)));

}
void QCtrlEmpresas::SlotProducto(int pintNProducto)
{
	emit SignalEmpresas(CQSLEmpresas.at(pintNProducto));
}
void QCtrlEmpresas::setFocus()
{
  SiscomPasaFocoControl(QLEEmpresas);	
}

void QCtrlEmpresas::Limpia()
{
}






