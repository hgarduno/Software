#ifndef __ZSISCOMDIBUJANDO_H__
#define __ZSISCOMDIBUJANDO_H__
#include <qscrollview.h>
class QPaintDeviceMetrics;
class QPainter;
class QPrinter;

class zSiscomDibujando:public QScrollView
{
public:
	zSiscomDibujando(QWidget *pQWparent,
		         const char *pchrPtrName);
  	int PixelesAmm(int pintPixeles);	
	virtual void Dibujando(QPainter *pQPDibujo);
	void Linea(int pintX,int pintY,int pintX1,int pintY1);

	void paintEvent(QPaintEvent *);
protected:
	void Medidas(QPainter *pQPDispositivo);
	void drawContents(QPainter *pQPDibuja,
			  int,
			  int,
			  int,
			  int);
private:
	QPaintDeviceMetrics *QPaDevMedidas;
	
};
#endif
