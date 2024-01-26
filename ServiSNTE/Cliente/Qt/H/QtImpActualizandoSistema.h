#ifndef __QTIMPACTUALIZANDOSISTEMA_H__
#define __QTIMPACTUALIZANDOSISTEMA_H__
#include <cstddef>
#include <ActualizandoSistema.h>

class QProcess;
class zSiscomRegistros;
class QtImpActualizandoSistema:public ActualizandoSistema
{
Q_OBJECT
public:
	QtImpActualizandoSistema(QWidget *pQWParent=0,
			  const char *pchrPtrName=0,
			  bool pbModal=false,
			  WFlags pWFlags=false);
private:
	void ConectaSlots();
	void IniciaVariables();
	int HayActualizacionDisponible();
private:
	QProcess *QPEjecutaAct;
private slots:
	void reject();

};
#endif
