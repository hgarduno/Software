#include <zSiscomDibujando.h>
#include <zSiscomDesarrollo4.h>

#include <qpainter.h>
#include <qpaintdevicemetrics.h>



zSiscomDibujando::zSiscomDibujando(QWidget *pQWParent,
				   const char *pchrPtrName):
				   QScrollView(pQWParent,pchrPtrName,WStaticContents)


{


}
void zSiscomDibujando::Medidas(QPainter *pQPaDispositivo)
{
   QPaDevMedidas=new QPaintDeviceMetrics(pQPaDispositivo->device());
}

int zSiscomDibujando::PixelesAmm(int pintPixeles)
{
    return (pintPixeles/25.4)*(QPaDevMedidas->logicalDpiX());
}

void zSiscomDibujando::Dibujando(QPainter *pQPainter)
{

}
void zSiscomDibujando::Linea(int pintXmm,
			     int pintYmm,
			     int pintX1mm,
			     int pintY1mm)
{

}
void zSiscomDibujando::paintEvent(QPaintEvent *)
{

}
void zSiscomDibujando::drawContents(QPainter *pQPDibujando,
				    int,
				    int,
				    int,
				    int)
{
//LogSiscom("");

}
