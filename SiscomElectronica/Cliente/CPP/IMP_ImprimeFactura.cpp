#include <IMP_ImprimeFactura.h>
#include <QtSisImprimeFactura.h>

#include <SiscomDesarrollo3Qt++.h>
#include <qpushbutton.h>
#include <qlayout.h>
#include <qprinter.h>
#include <qpainter.h>
QImprimeFactura::QImprimeFactura(SiscomRegistro3 *pSisReg3Cliente,
				 SiscomRegistro3Lst *pSisReg3LstProductos,
				 QWidget *pQWParent,       
				    const char *pchrPtrName,
				    bool pbModal,
				    WFlags pWFlags):	      
				QDialog(pQWParent,pchrPtrName,pbModal,pWFlags),
				SisReg3Cliente(pSisReg3Cliente),
				SisReg3LstProductos(pSisReg3LstProductos)
{
IniciaVariables();
ConectaSlots();
exec();
}

QImprimeFactura::~QImprimeFactura()
{

}

void QImprimeFactura::ConectaSlots()
{
	connect(QPBImprime,
		SIGNAL(clicked()),
		SLOT(SlotImprime()));

}

void QImprimeFactura::SlotImprime()
{
uint lintX,
	lintY,
	lintX1,
	lintY1;
QPrinter *lQPImpresora=new QPrinter;
QPainter lQPDibujando;
lQPImpresora->setup();
lQPImpresora->setFullPage(false);
lQPDibujando.begin(lQPImpresora);
QtSisImpFactura->Dibujando(&lQPDibujando,lQPImpresora);
}


void QImprimeFactura::IniciaVariables()
{
QHBRegilla=new QGridLayout(this,2,1,11,6,"QHRegilla");
QtSisImpFactura=new QtSisImprimeFactura(SisReg3Cliente,
					SisReg3LstProductos,
					this,
					"QtSisImpFactura");
QPBImprime=new QPushButton("Imprime",this,"QPBImprime");
QHBRegilla->addWidget(QtSisImpFactura,0,0);
QHBRegilla->addWidget(QPBImprime,1,0);
}
