#include <IMP_ImprimeReporteSemestral.h>
#include<SISCOMComunicaciones++.h>
#include <QtSisImprime.h>
#include <QtSisImprimeTabla.h>
#include <SiscomDesarrollo3Qt++.h>
#include <SiscomRegistros3.h>
#include <qprinter.h>
#include <qpainter.h>
QImprimeReporteSemestral::QImprimeReporteSemestral(
				    SiscomRegistro3Lst *pSisReg3LstDatos,
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				ImprimeReporteSemestral(pQWParent,pchrPtrName,pWFlags),
				SisReg3LstDatos(pSisReg3LstDatos),
				QWParent(pQWParent)
{
IniciaVariables();
ConectaSlots();
show();
}

QImprimeReporteSemestral::~QImprimeReporteSemestral()
{

}

void QImprimeReporteSemestral::ConectaSlots()
{
	connect(QPBImprime,
		SIGNAL(clicked()),
		SLOT(SlotImprime()));

}
void QImprimeReporteSemestral::SlotImprime()
{
 QPrinter *lQPImprime=new QPrinter;
          QPainter lQPainter;
	  lQPImprime->setPageSize(QPrinter::Letter); 
	  lQPImprime->setOutputToFile(true);
	  lQPImprime->setOutputFileName("PruebaSiscom.ps");
	  lQPImprime->setPageOrder(QPrinter::FirstPageFirst);
	  lQPImprime->setPrintRange(QPrinter::AllPages);
          /*lQPImprime->setup(this);*/
          lQPainter.begin(lQPImprime);
	  QtSisImpRepSemestral->Dibujando(&lQPainter,lQPImprime);

}
void QImprimeReporteSemestral::IniciaVariables()
{
 chrPtrCampos=(char **)malloc(sizeof(char *)*9);
 chrPtrCampos[0]=strdup("precioventa");
 chrPtrCampos[1]=strdup("total");
 chrPtrCampos[2]=strdup("inventario");
 chrPtrCampos[3]=strdup("cveproducto");
 chrPtrCampos[4]=strdup("fechaucompra");
 chrPtrCampos[5]=strdup("cantidaducompra");
 chrPtrCampos[6]=strdup("precioucompra");
 chrPtrCampos[7]=strdup("proveedor");
 chrPtrCampos[8]=0;

 chrPtrTitulosColumnas=(char **)malloc(sizeof(char *)*10);
 chrPtrTitulosColumnas[0]=strdup("Precio Venta");
 chrPtrTitulosColumnas[1]=strdup("Total Ventas");
 chrPtrTitulosColumnas[2]=strdup("Inventario");
 chrPtrTitulosColumnas[3]=strdup("Producto");
 chrPtrTitulosColumnas[4]=strdup("Fecha Ultima Compra");
 chrPtrTitulosColumnas[5]=strdup("Cantidad Ultima Compra");
 chrPtrTitulosColumnas[6]=strdup("Precio Ultima Compra");
 chrPtrTitulosColumnas[7]=strdup("Proveedor");
 chrPtrTitulosColumnas[8]=0;
 intCaracteresColumna[0]=6;
 intCaracteresColumna[1]=4;
 intCaracteresColumna[2]=5;
 intCaracteresColumna[3]=25;
 intCaracteresColumna[4]=10;
 intCaracteresColumna[5]=5;
 intCaracteresColumna[6]=7;
 intCaracteresColumna[7]=50;
 intCaracteresColumna[8]=0;

	 QHBRegilla=new QGridLayout(this,2,1,11,6,"QHRegislla");
	 QtSisImpRepSemestral=new QtSisImprimeTabla(this,"QtSisImpRepSemestral");
	 QtSisImpRepSemestral->Columnas(chrPtrCampos);
	 QtSisImpRepSemestral->TitulosColumnas(chrPtrTitulosColumnas);
	 QtSisImpRepSemestral->RegistrosSiscom(SisReg3LstDatos);
	 QtSisImpRepSemestral->CaracteresColumna(intCaracteresColumna);
	 QtSisImpRepSemestral->MargenSuperior(10,10);
	 QtSisImpRepSemestral->MargenInferior(15,15);
	 QtSisImpRepSemestral->TamanoHoja(206,279);
	 QPBImprime=new QPushButton("Imprime",this,"QPBImprime");
	 QHBRegilla->addWidget(QtSisImpRepSemestral,0,0);
	 QHBRegilla->addWidget(QPBImprime,1,0);


}
