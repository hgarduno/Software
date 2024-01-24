#include <QCtrlProductos.h>
#include <CQSisOpTiendas4.h>
#include <SISCOMComunicaciones++.h>
#include <qlayout.h>


QCtrlProductos::QCtrlProductos( QWidget *parent, const char *name )
    : QWidget( parent, name )
{
	IniciaVariables();
	ConectaSlots();
}
QCtrlProductos::~QCtrlProductos()
{
printf("QCtrlProductos::~QCtrlProductos\n");
CQSLProductos.setAutoDelete(true);
CQSLProductos.clear();
}
void QCtrlProductos::IniciaVariables()
{
	QHBLayout=new QHBoxLayout(this);
	QHBLayout->setMargin(0);
	QCBProductos=new QComboBox(this);
	QHBLayout->addWidget(QCBProductos);
	QLEProductos=SiscomColocaEditAlCombo(QCBProductos,"QLEProductos");
	QCBProductos->setAutoCompletion(true);
	QCBProductos->setDuplicatesEnabled(false);
	QCBProductos->setInsertionPolicy(QComboBox::NoInsertion);
}
void QCtrlProductos::MuestraProductos()
{
CQSisProducto *lCQSProducto;
  for(lCQSProducto=CQSLProductos.first();
      lCQSProducto;
      lCQSProducto=CQSLProductos.next())
     QCBProductos->insertItem(lCQSProducto->SRegistrosPro2["Clave"]);
	emit SignalProductos(CQSLProductos.at(0));
}
void QCtrlProductos::IniciaControl()
{
	ConsultaProductos();
	MuestraProductos();
	ConectaSlots();
}
void QCtrlProductos::ConsultaProductos()
{
CQSisOpTiendas4 lCQSOT4Productos(SisDatCom);
	lCQSOT4Productos.Productos(&CQSLProductos);
}
void QCtrlProductos::PonServidor(SiscomDatCom *pSisDatCom)
{
	SisDatCom=pSisDatCom;
}
void QCtrlProductos::ConectaSlots()
{
	connect(QCBProductos,
		SIGNAL(activated(int)),
		SLOT(SlotProducto(int)));
	connect(QCBProductos,
		SIGNAL(highlighted(int)),
		SLOT(SlotSeleccionandoProducto(int)));

}
void QCtrlProductos::SlotSeleccionandoProducto(int pintProducto)
{
	if(CQSLProductos.count())
	emit SignalSeleccionandoProducto(CQSLProductos.at(pintProducto));
}
void QCtrlProductos::SlotProducto(int pintNProducto)
{

	if(CQSLProductos.count())
	emit SignalProductos(CQSLProductos.at(pintNProducto));
}
void QCtrlProductos::setFocus()
{
  SiscomPasaFocoControl(QLEProductos);	
}

void QCtrlProductos::Limpia()
{
}






