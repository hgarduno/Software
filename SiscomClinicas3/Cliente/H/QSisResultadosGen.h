#ifndef __QSISRESULTADOSGEN_H__
#define __QSISRESULTADOSGEN_H__
#include <SISCOMComunicaciones++.h>
#include <qwidget.h>

class QSisResultadosGen:public QWidget 
{
Q_OBJECT
public:
	QSisResultadosGen(QWidget *pQWParent=0,
			  const char *pchrPtrName=0,
			  WFlags pWFlags=false);
private:
	QLabel *QLCnsTotales;
	QLabel *QLVTotales;
	QLabel *QLTPromConsulta;
	QLabel *QLTTotalConsulta;
	QLCDNumber *QLCDCnsTotales;
	QLCDNumber *QLCDVenTotales;
	QLCDNumber *QLCDTPromConsulta;
	QLCDNumber *QLCDTotalConsulta;

	QGridLayout *QGLRegilla;
private:
	void IniciaInterfaz();

};
#endif
