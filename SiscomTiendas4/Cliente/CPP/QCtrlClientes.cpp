#include <QCtrlClientes.h>
#include <CQSisOpTiendas4.h>
#include <CQSisClientes.h>
#include <CQSisEmpresas.h>
#include <SISCOMComunicaciones++.h>
#include <qlayout.h>
#include <SisPersonas.h>


QCtrlClientes::QCtrlClientes( QWidget *parent, const char *name )
    : QWidget( parent, name )
{
	IniciaVariables();
	ConectaSlots();
}
QCtrlClientes::~QCtrlClientes()
{
	CQSLClientes.setAutoDelete(true);
	CQSLClientes.clear();
}
void QCtrlClientes::IniciaVariables()
{
	QHBLayout=new QHBoxLayout(this);
	QHBLayout->setMargin(0);
	QCBClientes=new QComboBox(this);
	QHBLayout->addWidget(QCBClientes);
	QLEClientes=SiscomColocaEditAlCombo(QCBClientes,"QLEClientes");
	QCBClientes->setAutoCompletion(true);
	QCBClientes->setDuplicatesEnabled(false);
	QCBClientes->setInsertionPolicy(QComboBox::NoInsertion);
}
void QCtrlClientes::MuestraClientes()
{
CQSisCliente *lCQSProducto;
QString lQSNombre;
  for(lCQSProducto=CQSLClientes.first();
      lCQSProducto;
      lCQSProducto=CQSLClientes.next())
  {
     QCBClientes->insertItem(lCQSProducto->SRegistrosPro2["Nombre"]);
  }
}
void QCtrlClientes::IniciaControl()
{
	ConsultaClientes();
	MuestraClientes();

	/*
	 *
	 *
	SeleccionoCliente(0);	

	*/
}
void QCtrlClientes::ConsultaClientes()
{
QCBClientes->clear();
CQSisOpTiendas4 lCQSOT4Clientes(SisDatCom);
	lCQSOT4Clientes.Clientes(&CQSLClientes);
}
void QCtrlClientes::PonServidor(SiscomDatCom *pSisDatCom)
{
	SisDatCom=pSisDatCom;
}
void QCtrlClientes::ConectaSlots()
{
	connect(QCBClientes,
		SIGNAL(activated(int)),
		SLOT(SlotProducto(int)));

}
void QCtrlClientes::SlotProducto(int pintNProducto)
{
	
	SeleccionoCliente(pintNProducto);
}
void QCtrlClientes::setFocus()
{
  SiscomPasaFocoControl(QLEClientes);	
}

void QCtrlClientes::Limpia()
{
}
void QCtrlClientes::SeleccionoCliente(int pintNumCliente)
{
CQSisCliente *lCQSCliente;
	lCQSCliente=CQSLClientes.at(pintNumCliente);
	if(!strcmp(lCQSCliente->SRegistrosPro2["TipoCliente"],
	           "Fisica"))
	 emit SignalFisica(lCQSCliente);
	if(!strcmp(lCQSCliente->SRegistrosPro2["TipoCliente"],
	           "Moral"))
	emit SignalMoral(lCQSCliente);
}





void QCtrlClientes::ConElCliente(const char *pchrPtrCliente)
{
char lchrArrNombre[256];
CQSisCliente *lCQSCliente;
SisPersona *lSPersona;
	lCQSCliente=CQSLClientes[pchrPtrCliente];
	lSPersona=lCQSCliente->Persona();
if(lCQSCliente)
{
  SiscomLog("%s %s %s",
  	    (*lSPersona)["Nombre"],
	    (*lSPersona)["APaterno"],
	    (*lSPersona)["AMaterno"]);
  sprintf(lchrArrNombre,
  	  "%s %s %s",
  	    (*lSPersona)["Nombre"],
	    (*lSPersona)["APaterno"],
	    (*lSPersona)["AMaterno"]);

QCBClientes->setCurrentText(lchrArrNombre);
QCBClientes->setEnabled(false);
  if(!strcmp(lCQSCliente->SRegistrosPro2["TipoCliente"],
	           "Fisica"))
	 emit SignalFisica(lCQSCliente);
	if(!strcmp(lCQSCliente->SRegistrosPro2["TipoCliente"],
	           "Moral"))
	emit SignalMoral(lCQSCliente);
}
}
