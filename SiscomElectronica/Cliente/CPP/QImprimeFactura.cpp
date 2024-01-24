#include <QImprimeFactura.h>
#include <qpainter.h>
#include <qpushbutton.h>
#include <qprinter.h>
#include <qpaintdevicemetrics.h>
#include <qsimplerichtext.h> 
#include <qscrollbar.h>
QImprimeFactura::QImprimeFactura(const char *pchrPtrCliente,
				 const char *pchrPtrRFC,
				 const ProductosE &pProductos,
				 QWidget *pQWParent,
				 const char *pchrPtrName):
	#ifndef __QSCROLLBAR__
	QWidget(pQWParent,pchrPtrName),
	#else
	QScrollView(pQWParent,pchrPtrName),
	#endif
	chrPtrCliente(pchrPtrCliente),
	chrPtrRFC(pchrPtrRFC),
	PProductos(pProductos),
	intMargenX(25),
	intMargenY(25),
	intMargenX1(25),
	intMargenY1(25)
{
	IniciaVariables();		
	Mide();	

	Imprime();

}
#ifndef __QSCROLLBAR__
void QImprimeFactura::paintEvent(QPaintEvent *)
{
QPainter lQPDibuja(this);
	resize(QSize(MMAPixeles(intTamXMM),
		     MMAPixeles(intTamYMM)));
	Dibuja(&lQPDibuja);

}
#else
void QImprimeFactura::drawContents(QPainter *pQPDibuja,
				   int pintCX,
				   int pintCY,
				   int pintCW,
				   int pintCH)
{
	Dibuja(pQPDibuja);

}
#endif

int QImprimeFactura::PixelesAMM(int pintPixeles)
{
	return pintPixeles/MMAPixeles(1);
}
int QImprimeFactura::MMAPixeles(int pintMilimetros)
{
int lintPixeles;
	lintPixeles=(int )((pintMilimetros/25.4)*QPDMedidas->logicalDpiY());
	return lintPixeles;
}
void QImprimeFactura::DibujaHoja(QPainter *pQPDibuja,
				 int pintNumHoja)
{
	pQPDibuja->drawText(MMAPixeles(intTamXMM/2),
			    pintNumHoja*MMAPixeles(intTamYMM-2),
			    QString().sprintf("%d",pintNumHoja));
	pQPDibuja->drawRect(0+4,
			    ((pintNumHoja-1)*MMAPixeles(intTamYMM))+4,
			    MMAPixeles(intTamXMM)-4,
			    MMAPixeles(intTamYMM)-4);
	QRArea=new QRect(TrasladaX(0),
			    TrasladaY((pintNumHoja-1)*intTamYMM),
			    MMAPixeles(intTamXMM-2*intMargenX1),
			    MMAPixeles(intTamYMM-2*intMargenY1));
	pQPDibuja->setPen(QColor(0,0,255));
	pQPDibuja->drawRect(*QRArea);
	pQPDibuja->setPen(QColor(0,0,0));

	
}
void QImprimeFactura::DatosCliente(QPainter *pQPDibuja)
{
	Texto(pQPDibuja,
	      10,
	      10,
	      chrPtrCliente);
	 Texto(pQPDibuja,
	       80,
	       10,
	       chrPtrRFC);
}
void QImprimeFactura::Productos(QPainter *pQPDibuja)
{
ProductoE *lProducto;
int lintY;
int lintNProductos=PProductos.count();
int lintContador;
	for(lProducto=PProductos.first(),
	    lintY=0,
	    lintContador=0;
	     lintContador<lintNProductos-2;
	     lProducto=PProductos.next(),
	     lintY+=intTamSaltoLinea,
	     lintContador++)
	 {
	   if(MMAPixeles(15+lintY)>=QRArea->width())
	   DibujaHoja(pQPDibuja,3);
	   printf("1 MM Tiene %d Pixeles\n",
	   	   MMAPixeles(1));
	   Texto(pQPDibuja,
	   	 10,
		 15+lintY,
		 lProducto->SRegistrosPro2["Cantidad"]);
	   Texto(pQPDibuja,
	   	 30,
		 15+lintY,
		 lProducto->SRegistrosPro2["CveProducto"]);
	   Texto(pQPDibuja,
	   	 60,
		 15+lintY,
		 lProducto->SRegistrosPro2["Precio"]);
	Texto(pQPDibuja,
	   	 80,
		 15+lintY,
		 lProducto->SRegistrosPro2["Importe"]);
	 }

}
void QImprimeFactura::Dibuja(QPainter *pQPDibuja)
{
	DibujaHoja(pQPDibuja,1);
	/*
	DibujaHoja(pQPDibuja,2);
	DibujaHoja(pQPDibuja,3);
	*/
	DatosCliente(pQPDibuja);
	Productos(pQPDibuja);

}
void QImprimeFactura::PonTamanoFactura(int pintTamXMM,
				       int pintTamYMM)
{
  	intTamXMM=pintTamXMM;
	intTamYMM=pintTamYMM;
	resize(MMAPixeles(intTamXMM),MMAPixeles(intTamYMM));
}
void QImprimeFactura::ObtenMedidas(QPainter *pQPDibuja)
{
	QPDMedidas=new QPaintDeviceMetrics(pQPDibuja->device());
}
void QImprimeFactura::Mide()
{
QPainter lQPDibuja(this);
	ObtenMedidas(&lQPDibuja);
}

int QImprimeFactura::TrasladaX(int pintMMX)
{

	return MMAPixeles(intMargenX)+MMAPixeles(pintMMX);

}
int QImprimeFactura::TrasladaY(int pintMMY)
{
	return MMAPixeles(intMargenY)+MMAPixeles(pintMMY);
}

void QImprimeFactura::Imprime()
{
QPrinter *lQPImprime=new QPrinter;

	lQPImprime->setup(this);
	QPainter lQPainter;
	lQPainter.begin(lQPImprime);
	Dibuja(&lQPainter);

}
void QImprimeFactura::Texto(QPainter *pQPDibuja,
			    int pintXMM,
			    int pintYMM,
			    const char *pchrPtrTexto)
{
char lchrArrBuffer[1024];
PonCadenaEnFormatoHTML(pchrPtrTexto,lchrArrBuffer);
QSimpleRichText lQSRTexto(lchrArrBuffer,*QFLetra);
	lQSRTexto.draw(pQPDibuja,
		       TrasladaX(pintXMM),
		       TrasladaY(pintYMM),
		       *QRArea,
		       colorGroup());
}
void QImprimeFactura::PonCadenaEnFormatoHTML(const char *pchrPtrCadena,
					    char *pchrPtrSalida)
{
	while(*pchrPtrCadena)
	{
	  if(*pchrPtrCadena==' ')
	  {
	     strcpy(pchrPtrSalida,"&nbsp;");
	     pchrPtrSalida+=5;
	  }
	  else
	  *pchrPtrSalida=*pchrPtrCadena;
	  pchrPtrSalida++;
	  *pchrPtrCadena++;
	}
	*pchrPtrSalida=0;

}
void QImprimeFactura::IniciaVariables()
{
	QFLetra=new QFont("Helvetica [Cronyx]",8 );	
	intTamSaltoLinea=3;
	viewport()->setBackgroundMode( PaletteBase );
	setVScrollBarMode(QScrollView::AlwaysOn);
	 resizeContents(3000,3000); 
	 srandom(3);
}
