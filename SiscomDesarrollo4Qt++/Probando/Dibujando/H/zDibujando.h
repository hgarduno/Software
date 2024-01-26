#ifndef __DIBUJANDO_H__
#define __DIBUJANDO_H__
#include <zSiscomDibujando.h>


class QPainter;
class zDibujando:public zSiscomDibujando
{
Q_OBJECT 

public:
	zDibujando(QWidget *pQWParent=0,const char *pchrPtrName=0);
	void Dibujando(QPainter *pQPDibujo);
	void paintEvent(QPaintEvent *);
private:
	QPainter *QPaDibujando;
};

#endif

