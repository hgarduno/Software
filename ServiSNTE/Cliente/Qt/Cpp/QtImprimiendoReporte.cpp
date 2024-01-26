#include <QtImprimiendoReporte.h>
#include <QtImprimeReporte.h>

#include <zSiscomDesarrollo4.h> 

#include <qlayout.h>
#include <qpushbutton.h>
#include <stdlib.h>
#include <qprinter.h>
#include <qpainter.h>
QtImprimiendoReporte::QtImprimiendoReporte(zSiscomConexion *pzSisConexion,
					   zSiscomRegistros *pzSisRegsInformacion,
					   QWidget *pQWParent,
					   const char *pchrPtrName,
					   bool pbModal,
					  WFlags pWFlags):
					QDialog(pQWParent,pchrPtrName,pbModal,pWFlags),
					zSisConexion(pzSisConexion),
					zSisRegsInformacion(pzSisRegsInformacion)
{
}
void QtImprimiendoReporte::ColocaControles()
{
QVBLayout=new QVBoxLayout(this);
QPBImprimir=new QPushButton("Imprimir",this,"QPBImprimir");
QtImpReporte=ControlReporte();
QVBLayout->addWidget(QtImpReporte);
QVBLayout->addWidget(QPBImprimir);
}

QtImprimeReporte *QtImprimiendoReporte::ControlReporte()
{
   return 0;
}
void QtImprimiendoReporte::Iniciando()
{
ColocaControles();
ConectaSlots();
resize(QSize(1280,400));
exec();
}
void QtImprimiendoReporte::ConectaSlots()
{
	connect(QPBImprimir,
		SIGNAL(clicked()),
		SLOT(SlotImprimir()));
}
void QtImprimiendoReporte::SlotImprimir()
{
   if(ImprimeAArchivo()==1)
   ImprimeImpresoraDefault();
   if(ImprimeAArchivo()==2)
   ImprimeVentanaConfiguracion();
   else
   if(ImprimeAArchivo()==3)
   ImprimeArchivo();

}
int QtImprimiendoReporte::ImprimeAArchivo()
{
const char *lchrPtrImprimePuntoVentaAArchivo;

if((lchrPtrImprimePuntoVentaAArchivo=getenv("ImprimeAArchivo")))
{
return atoi(lchrPtrImprimePuntoVentaAArchivo);
}
else
return 0;
}
void QtImprimiendoReporte::ImprimeImpresoraDefault()
{
QPrinter lQPImpresora(QPrinter::HighResolution);
QPainter lQPainter;
lQPainter.begin(&lQPImpresora); 
QtImpReporte->Imprime(&lQPainter); 

}
void QtImprimiendoReporte::ImprimeVentanaConfiguracion()
{
QPrinter lQPImpresora(QPrinter::HighResolution);
QPainter lQPainter;
     if(lQPImpresora.setup(this))
     {
     lQPainter.begin(&lQPImpresora); 
      QtImpReporte->Imprime(&lQPainter); 
     }
}
void QtImprimiendoReporte::ImprimeArchivo()
{
char lchrArrArchivo[256];
const char *lchrPtrHome=getenv("HOME");
QPrinter lQPImpresora(QPrinter::HighResolution);
QPainter lQPainter;
sprintf(lchrArrArchivo,"%s/%s",lchrPtrHome,"ServiSNTE.Reporte.ps");
lQPImpresora.setOutputToFile(true);
lQPImpresora.setOutputFileName(lchrArrArchivo);
lQPainter.begin(&lQPImpresora);
 QtImpReporte->Imprime(&lQPainter);
}
