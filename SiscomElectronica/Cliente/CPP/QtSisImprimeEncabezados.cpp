#include <QtSisImprimeEncabezados.h>
#include <QtSisImprimeMargen.h>

#include <SiscomDesarrollo3Qt++.h>
#include <qpainter.h>
#include <qpaintdevicemetrics.h>
QtSisImprimeEncabezados::QtSisImprimeEncabezados(
			  QPaintDeviceMetrics *pQPDMMedidas,
			  QtSisImprimeMargen *pQtSisImpMarSup,
			  char **pchrPtrTitulosColumnas,
			  int *pintPtrCaracteresC):
			  QPDMMedidas(pQPDMMedidas),
			 QtSisImpMarSup(pQtSisImpMarSup),
			 chrPtrTitulosColumnas(pchrPtrTitulosColumnas),
			 intPtrCaracteresC(pintPtrCaracteresC)
{

}
void QtSisImprimeEncabezados::DibujaEncabezado(QPainter *pQPDibuja)
{
int lintContadorX=QtSisImpMarSup->Xpx(),
    lintContadorY=QtSisImpMarSup->Ypx(),
    lintContador=0;
    intAltoTexto=pQPDibuja->fontMetrics().height();	
    lintContadorY+=intAltoTexto;
    while(chrPtrTitulosColumnas[lintContador])
    {
	pQPDibuja->drawText(lintContadorX+2,
			   lintContadorY+2,
			   chrPtrTitulosColumnas[lintContador]);
	lintContadorX+=AnchoColumnaPx(pQPDibuja,intPtrCaracteresC[lintContador]);
	lintContadorY+=intAltoTexto;
	lintContador++;
    }
    intY1=lintContadorY+intAltoTexto; 

    intNColumnas=lintContador;
}
int QtSisImprimeEncabezados::Columnas()
{
	return intNColumnas;
}
int QtSisImprimeEncabezados::AnchoColumnaPx(QPainter *pQPDibuja,int pintNCaracteres)
{
char lchrArrCadena[128];
char lchrArrPaso[10];
sprintf(lchrArrPaso,"%%0%dd",pintNCaracteres);
sprintf(lchrArrCadena,lchrArrPaso,0);
return pQPDibuja->fontMetrics().width(lchrArrCadena);
}
int QtSisImprimeEncabezados::PixelesAMM(int pintPixeles)
{
	return pintPixeles/MMAPixeles(pintPixeles);
}
int QtSisImprimeEncabezados::MMAPixeles(int pintMilimetros)
{
return (int )((pintMilimetros/25.4)*QPDMMedidas->logicalDpiX());
}
int QtSisImprimeEncabezados::Y1px()
{
	return intY1;
}
