#ifndef __QCONTROLSEMANAVENTA_H__
#define __QCONTROLSEMANAVENTA_H__
#include <qtable.h>

class CSisDatosSemana;
class QCtrSemanaVenta:public QTable
{
public:	
	QCtrSemanaVenta(CSisDatosSemana *,QWidget *,const char *);
	int ObtenTamanoControl();
private:
	int intTamLetra;
	int intHoras;
	CSisDatosSemana *CSDatosSemana;
private:
	void MuestraInformacion();

};



#endif
