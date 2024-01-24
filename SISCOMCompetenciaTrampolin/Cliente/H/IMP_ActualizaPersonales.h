
#ifndef __IMP_ACTUALIZAPERSONALES_H__
#define __IMP_ACTUALIZAPERSONALES_H__
#include <UIC_H_ActualizaPersonales.h>
class SiscomDatCom;
class CQSisEntrenador;
class QActualizaPersonales:public ActualizaPersonales
{
 Q_OBJECT
public:
	QActualizaPersonales(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QActualizaPersonales();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
private:
	void ConectaSlots();
	void IniciaVariables();
private slots:
	void SlotPersona(CQSisEntrenador *,const char *);
};
extern "C" QActualizaPersonales *InstanciaActualizaPersonales(void *,char **,void *,const char *,int);
#endif
