
#ifndef __IMP_ACTUALIZAPESOSPPUNTO_H__
#define __IMP_ACTUALIZAPESOSPPUNTO_H__
#include <UIC_H_ActualizaPesosPPunto.h>
class SiscomDatCom;
class QActualizaPesosPPunto:public ActualizaPesosPPunto
{
 Q_OBJECT
public:
	QActualizaPesosPPunto(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QActualizaPesosPPunto();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
private:
	void ConectaSlots();
	void IniciaVariables();
private slots:
};
extern "C" QActualizaPesosPPunto *InstanciaActualizaPesosPPunto(void *,char **,void *,const char *,int);
#endif
