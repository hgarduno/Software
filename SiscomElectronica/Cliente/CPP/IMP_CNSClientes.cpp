#include <IMP_CNSClientes.h>
#include <QCtrlEscuelas.h>
#include <SiscomRegistros3.h>
#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qcombobox.h>
#include <qlineedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

QCNSClientes::QCNSClientes(const char *pchrPtrIdExpendio,
			   SiscomDatCom *pSisDatCom,
			   QWidget* parent,
			   const char* name,
			   bool modal, WFlags fl )
    : CNSClientes( parent, name, modal, fl ),
    SisDatCom(pSisDatCom),
    chrPtrIdExpendio(pchrPtrIdExpendio)
{
	ConsultaClientes();
	IniciaVariables();
	ConectaSlots();
	
	exec();
}

QCNSClientes::~QCNSClientes()
{
}
void QCNSClientes::IniciaVariables()
{
	QLERFCCombo=new QLineEdit(QCBRFC,"QLERFCCombo");
	QCBRFC->setLineEdit(QLERFCCombo);
	QLERFCCombo->setFocus();
	QLERFCCombo->selectAll();

	QCtrEscuelas->PonServidor(SisDatCom);
	QCtrEscuelas->IdExpendio(chrPtrIdExpendio);
	QCtrEscuelas->IniciaControl();
}
void QCNSClientes::ConsultaClientes()
{
ConsultaPersonas lCnsPersonas(SisDatCom,
			      "",
			      "",
			      "",
			      "",
			      "",
			      "1",
			      chrPtrIdExpendio,
			      PPersonas);
Persona *lPersona;
	for(lPersona=PPersonas.first();
	    lPersona;
	    lPersona=PPersonas.next())
	   QCBRFC->insertItem(lPersona->SRegistrosPro2["RFC"]);

}
void QCNSClientes::closeEvent(QCloseEvent *)
{

}
void QCNSClientes::ConectaSlots()
{
	connect(QCBRFC,
		SIGNAL(highlighted(int)),
		SLOT(S_Cliente(int)));
	connect(QCBRFC,
		SIGNAL(activated(int)),
		SLOT(S_SelCliente(int)));
	connect(QLERFCCombo,
		SIGNAL(returnPressed()),
		SLOT(S_SelCliente()));
	connect(QPBAceptar,
		SIGNAL(clicked()),
		SLOT(S_Aceptar()));
	connect(QPBCancelar,
		SIGNAL(clicked()),
		SLOT(S_Cancelar()));
	connect(QCtrEscuelas,
		SIGNAL(SignalEscuelas(SiscomRegistro3 *)),
		SLOT(SlotEscuela(SiscomRegistro3 *)));
}
void QCNSClientes::S_Aceptar()
{
	intSeleccion=1;
	done(1);
}
void QCNSClientes::S_Cancelar()
{
	intSeleccion=0;
	done(1);
}
void QCNSClientes::S_SelCliente()
{
int lintNumCliente;
	lintNumCliente=QCBRFC->currentItem();
	if(lintNumCliente>=0)
	{
	QPBAceptar->setEnabled(true);
	S_SelCliente(lintNumCliente);
	}


}
void QCNSClientes::S_Cliente(int pintNCliente)
{
Persona *lPersona=PPersonas.at(pintNCliente);

	QLECliente->setText(QString(lPersona->SRegistrosPro2["Nombre"]) +
			    " "						+
			    lPersona->SRegistrosPro2["APaterno"]	+
			    " "						+
			    lPersona->SRegistrosPro2["AMaterno"]);
	
}
void QCNSClientes::S_SelCliente(int pintNCliente)
{
PPersona=PPersonas.at(pintNCliente);
	QLENombre->setText(PPersona->SRegistrosPro2["Nombre"]);
	QLEAPaterno->setText(PPersona->SRegistrosPro2["APaterno"]);
	QLEAMaterno->setText(PPersona->SRegistrosPro2["AMaterno"]);
	/*
	*/
	QCtrEscuelas->setFocus();
}
void QCNSClientes::SlotEscuela(SiscomRegistro3 *pSisReg3Escuela)
{

	QPBAceptar->setFocus();
	SisReg3Escuela=pSisReg3Escuela;

}
int QCNSClientes::ObtenSeleccion()
{
	return intSeleccion;
}
Persona *QCNSClientes::ObtenPersona()
{
	return PPersona;
}

SiscomRegistro3 *QCNSClientes::Escuela()
{
	return SisReg3Escuela;
}
