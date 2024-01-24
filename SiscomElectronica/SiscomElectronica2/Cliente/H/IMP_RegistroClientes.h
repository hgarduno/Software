
#ifndef __IMP_REGISTROCLIENTES_H__
#define __IMP_REGISTROCLIENTES_H__
#include <UIC_H_RegistroClientes.h>
class SiscomDatCom;
class CQSisEscuela;
class CQSisAlumno;
class SiscomRegistrosPro2;
class QRegistroClientes:public RegistroClientes
{
 Q_OBJECT
public:
	QRegistroClientes(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QRegistroClientes();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
private:
};
extern "C" QRegistroClientes *InstanciaRegistroClientes(void *,char **,void *,const char *,int);
#endif
