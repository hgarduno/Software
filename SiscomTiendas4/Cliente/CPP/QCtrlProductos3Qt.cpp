
#include <QCtrlProductos3Qt.h>
#include <SiscomDesarrollo3Qt++.h>
#include <SiscomOperaciones3.h>
#include <SiscomParametroConsulta3.h>
#include <qlayout.h>
#include <qcombobox.h>
#include <qlineedit.h>

QCtrlProductos3Qt::QCtrlProductos3Qt( QWidget *parent, const char *name )
    : QWidget( parent, name ),
    intEsProdDeLaLista(0)
{
 	SiscomEscribeLog3Qt("Creado el objeto"); 
	IniciaVariables();
	ConectaSlots();
}
QCtrlProductos3Qt::~QCtrlProductos3Qt()
{
}
void QCtrlProductos3Qt::IniciaVariables()
{
	QHBLayout=new QHBoxLayout(this);
	QHBLayout->setMargin(0);
	QCBProductos=new QComboBox(this);
	QHBLayout->addWidget(QCBProductos);
	QLEProductos=SiscomDesarrollo3Qt::ColocaEditAlCombo(QCBProductos,"QLEProductos");
	QCBProductos->setAutoCompletion(true);
	QCBProductos->setDuplicatesEnabled(false);
	QCBProductos->setInsertionPolicy(QComboBox::NoInsertion);
}
void QCtrlProductos3Qt::MuestraProductos()
{
SiscomDesarrollo3Qt::RegistrosAlCombo("clave",
		    QCBProductos,
		    &SReg3LstProductos);
}
void QCtrlProductos3Qt::IniciaControl()
{
	QCBProductos->clear();
	ConsultaProductos();
	MuestraProductos();
}
void QCtrlProductos3Qt::ConsultaProductos()
{

SiscomOperaciones3 lSOpProductos(SisDatCom);
SiscomRegistro3Lst lSRegConsulta;
lSRegConsulta << 
new SiscomParametroConsulta3("Productos")	<<
new SiscomParametroConsulta3("Registrados");
SReg3LstProductos.clear();
lSOpProductos.SiscomEnvia("ConsultaTiendas4",
			  &lSRegConsulta,
			  &SReg3LstProductos);
}
void QCtrlProductos3Qt::Servidor(SiscomDatCom *pSisDatCom)
{
	SisDatCom=pSisDatCom;
}
void QCtrlProductos3Qt::ConectaSlots()
{
SiscomEscribeLog3Qt("Conectando los slots");
	connect(QCBProductos,
		SIGNAL(activated(int)),
		SLOT(SlotProducto(int)));
	connect(QCBProductos,
		SIGNAL(highlighted(int)),
		SLOT(SlotSeleccionandoProducto(int)));
	connect(QLEProductos,
		SIGNAL(returnPressed()),
		SLOT(SlotProducto()));
}
void QCtrlProductos3Qt::SlotProducto()
{
SiscomEscribeLog3Qt("La senal:%d",intEsProdDeLaLista);
if(!intEsProdDeLaLista)
emit SignalProductoNoEstaEnLaLista((const char *)QLEProductos->text());
else
intEsProdDeLaLista=0;
}
void QCtrlProductos3Qt::SlotSeleccionandoProducto(int pintProducto)
{
emit SignalSeleccionandoProducto(SReg3LstProductos[pintProducto]);
}
void QCtrlProductos3Qt::SlotProducto(int pintNProducto)
{
emit SignalProductos(SReg3LstProductos[pintNProducto]);
intEsProdDeLaLista=1;
}
void QCtrlProductos3Qt::setFocus()
{
SiscomDesarrollo3Qt::PasaFocoControl(QLEProductos);
}

SiscomRegistro3 *QCtrlProductos3Qt::PrimerProducto()
{
 if(SReg3LstProductos.count())
  return SReg3LstProductos[0];
 else
 return 0;
}
int QCtrlProductos3Qt::EsProductoDeLaLista()
{
   return intEsProdDeLaLista;
}
void QCtrlProductos3Qt::ProductoDeLaLista(int pintProdLista)
{
	intEsProdDeLaLista=pintProdLista;
}
void QCtrlProductos3Qt::ColocaListaEnLaClave(const char *pchrPtrClave)
{
	QCBProductos->setCurrentText(pchrPtrClave);
}
