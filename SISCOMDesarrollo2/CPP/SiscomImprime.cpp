#include <SiscomImprime.h>
#include <qpainter.h>
#include <qpushbutton.h>
#include <qprinter.h>
#include <qpaintdevicemetrics.h>
#include <qsimplerichtext.h> 
#include <qscrollbar.h>
#include <stdlib.h>
SiscomImprime::SiscomImprime(QWidget *pQWParent,
				 const char *pchrPtrName):
	QScrollView(pQWParent,pchrPtrName),
	intMargenX(25),
	intMargenY(25),
	intMargenX1(25),
	intMargenY1(25)
{
	IniciaVariables();		
	Mide();	
	Imprime();
}
void SiscomImprime::drawContents(QPainter *pQPDibuja,
				   int pintCX,
				   int pintCY,
				   int pintCW,
				   int pintCH)
{
	Dibuja(pQPDibuja);

}
int SiscomImprime::PixelesAMM(int pintPixeles)
{
	return pintPixeles/MMAPixeles(1);
}
int SiscomImprime::MMAPixeles(int pintMilimetros)
{
int lintPixeles;
	lintPixeles=(int )((pintMilimetros/25.4)*QPDMedidas->logicalDpiY());
	return lintPixeles;
}
void SiscomImprime::DibujaHoja(QPainter *pQPDibuja,
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
void SiscomImprime::Dibuja(QPainter *pQPDibuja)
{
	DibujaHoja(pQPDibuja,1);
	DibujaHoja(pQPDibuja,2);
	DibujaHoja(pQPDibuja,3);

}
void SiscomImprime::TamanoHoja(int pintTamXMM,
				       int pintTamYMM)
{
  	intTamXMM=pintTamXMM;
	intTamYMM=pintTamYMM;
	resize(MMAPixeles(intTamXMM),MMAPixeles(intTamYMM));
}
void SiscomImprime::ObtenMedidas(QPainter *pQPDibuja)
{
	QPDMedidas=new QPaintDeviceMetrics(pQPDibuja->device());
}
void SiscomImprime::Mide()
{
QPainter lQPDibuja(this);
	ObtenMedidas(&lQPDibuja);
}

int SiscomImprime::TrasladaX(int pintMMX)
{

	return MMAPixeles(intMargenX)+MMAPixeles(pintMMX);

}
int SiscomImprime::TrasladaY(int pintMMY)
{
	return MMAPixeles(intMargenY)+MMAPixeles(pintMMY);
}

void SiscomImprime::Imprime()
{
QPrinter *lQPImprime=new QPrinter;

	lQPImprime->setup(this);
	QPainter lQPainter;
	lQPainter.begin(lQPImprime);
	Dibuja(&lQPainter);

}
void SiscomImprime::Texto(QPainter *pQPDibuja,
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
void SiscomImprime::PonCadenaEnFormatoHTML(const char *pchrPtrCadena,
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
void SiscomImprime::IniciaVariables()
{
	QFLetra=new QFont("Helvetica [Cronyx]",8 );	
	intTamSaltoLinea=3;
	viewport()->setBackgroundMode( PaletteBase );
	setVScrollBarMode(QScrollView::AlwaysOn);
	 resizeContents(3000,3000); 
	 srandom(3);
}
