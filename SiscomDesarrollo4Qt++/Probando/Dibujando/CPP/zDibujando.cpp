#include <zDibujando.h>
#include <zSiscomDesarrollo4.h>

#include <qpainter.h>
zDibujando::zDibujando(QWidget *pQWParent,
		       const char *pchrPtrName):
		       zSiscomDibujando(pQWParent,pchrPtrName)
{
lQPaDibuja.drawLine(0,10,20,35);
}
void zDibujando::Dibujando(QPainter *pQPDibujo)
{
  LogSiscom("**");  
}
void zDibujando::paintEvent(QPaintEvent *)
{
   QPainter lQPaDibuja(this);
   lQPaDibuja.drawLine(0,10,20,35);

}
