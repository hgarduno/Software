#ifndef __QCONTROLMESVENTA_H__
#define __QCONTROLMESVENTA_H__
#include <qtable.h>
#include <OrdenesHora.h>
class QCtrMesVenta:public QTable
{
public:
	QCtrMesVenta(CSisDatosSemanas,
		     QWidget *,
		     const char *);
	void ActualizaDatos(CSisDatosSemanas );
private:
	 CSisDatosSemanas CSDtsSemanas;
private:
	void AsignaColumnasYFilas();
	void MuestraInformacion();
	void MuestraSemanas();
};

#endif
