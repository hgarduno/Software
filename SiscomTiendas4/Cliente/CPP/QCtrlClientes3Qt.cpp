
#include <QCtrlClientes3Qt.h>
#include <SiscomDesarrollo3Qt++.h>
#include <SiscomOperaciones3.h>
#include <CQSisComunesTiendas3Qt.h>
#include <qlayout.h>
#include <qcombobox.h>
#include <qlineedit.h>


QCtrlClientes3Qt::QCtrlClientes3Qt( QWidget *parent, const char *name )
    : QWidget( parent, name )
{
	IniciaVariables();
	ConectaSlots();
}
QCtrlClientes3Qt::~QCtrlClientes3Qt()
{
}
void QCtrlClientes3Qt::IniciaVariables()
{
	QHBLayout=new QHBoxLayout(this);
	QHBLayout->setMargin(0);
	QCBClientes=new QComboBox(this);
	QHBLayout->addWidget(QCBClientes);
	QLEClientes=SiscomDesarrollo3Qt::ColocaEditAlCombo(QCBClientes,"QLEClientes");
	QCBClientes->setAutoCompletion(true);
	QCBClientes->setDuplicatesEnabled(false);
	QCBClientes->setInsertionPolicy(QComboBox::NoInsertion);
}
void QCtrlClientes3Qt::MuestraClientes()
{
SiscomRegistro3 *lSRegistro3;
for(lSRegistro3=SReg3LstClientes.first();
    lSRegistro3;
    lSRegistro3=SReg3LstClientes.next())
   QCBClientes->insertItem(QString((*lSRegistro3)["nombre"]) + 
   			   " "				     +
			   (*lSRegistro3)["apaterno"]	     +
			   " "				     +
			   (*lSRegistro3)["amaterno"]);
}
void QCtrlClientes3Qt::IniciaControl()
{
	ConsultaClientes();
	MuestraClientes();
	SeleccionoCliente(0);	
}
void QCtrlClientes3Qt::ConsultaClientes()
{
SiscomRegistro3Lst lSRegCns;
SiscomOperaciones3 lSOpClientes(SisDatCom);
SiscomDesarrollo3Qt::ParametrosConsulta3(&lSRegCns,
					 "%s%s%s",
					 "ClientesRegistrados",
					 "Prueba",
					 "Prueba");
lSOpClientes.SiscomEnvia("ConsultaTiendas4",
			 &lSRegCns,
			 &SReg3LstClientes);
}
void QCtrlClientes3Qt::Servidor(SiscomDatCom *pSisDatCom)
{
	SisDatCom=pSisDatCom;
}
void QCtrlClientes3Qt::ConectaSlots()
{
	connect(QCBClientes,
		SIGNAL(activated(int)),
		SLOT(SlotCliente(int)));
	connect(QCBClientes,
		SIGNAL(highlighted(int)),
		SLOT(SlotCliente(int)));
	
	connect(QLEClientes,
		SIGNAL(returnPressed()),
		SLOT(SlotCliente()));
}
void QCtrlClientes3Qt::SlotCliente(int pintNProducto)
{
	
	SeleccionoCliente(pintNProducto);
}
void QCtrlClientes3Qt::SlotCliente()
{
	SiscomEscribeLog3Qt("El Item:%d",QCBClientes->currentItem());	
	SeleccionoCliente(QCBClientes->currentItem());
}
void QCtrlClientes3Qt::setFocus()
{
  SiscomDesarrollo3Qt::PasaFocoControl(QLEClientes);	
}

void QCtrlClientes3Qt::Limpia()
{
}
void QCtrlClientes3Qt::SeleccionoCliente(int pintNumCliente)
{
SiscomRegistro3 *lSReg3Cliente;
	lSReg3Cliente=SReg3LstClientes[pintNumCliente];
EnviaSenal(lSReg3Cliente);
}
void QCtrlClientes3Qt::EnviaSenal(SiscomRegistro3 *pSReg3Cliente)
{
SiscomEscribeLog3Qt("Ve que se envia");
	if(!strcmp((*pSReg3Cliente)["tipopersona"],
		   "Fisica"))
	emit SignalFisica(pSReg3Cliente);
	if(!strcmp((*pSReg3Cliente)["tipopersona"],"Moral"))
	emit SignalMoral(pSReg3Cliente);
}




void QCtrlClientes3Qt::ConElCliente(const char *pchrPtrCliente)
{
SiscomRegistro3 *lSReg3Cliente=SReg3LstClientes.Cliente(pchrPtrCliente);
char lchrArrNombre[90];
 SiscomEscribeLog3Qt("");
if(lSReg3Cliente)
{
 CQSisComunesTiendas3Qt::NombreCompleto(lSReg3Cliente,lchrArrNombre);
 QCBClientes->setCurrentText(lchrArrNombre);
 QCBClientes->setCurrentItem(SReg3LstClientes.Cliente());
 SiscomDesarrollo3Qt::PasaFocoControl(QLEClientes);
 EnviaSenal(lSReg3Cliente);
}
}
SiscomRegistro3 *QCtrlClientes3Qt::PrimerCliente()
{
 if(SReg3LstClientes.count())
  return SReg3LstClientes[0];
  else
  return 0;
}
