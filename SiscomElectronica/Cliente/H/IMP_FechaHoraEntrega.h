
#ifndef __IMP_FECHAHORAENTREGA_H__
#define __IMP_FECHAHORAENTREGA_H__
#include <UIC_H_FechaHoraEntrega.h>
class SiscomDatCom;
class QFechaHoraEntrega:public FechaHoraEntrega
{
 Q_OBJECT
public:
	QFechaHoraEntrega(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    bool pbModal=false,
	    WFlags pWFlags=0);
	~QFechaHoraEntrega();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
private:
	void ConectaSlots();
	void IniciaVariables();
private slots:
};
extern "C" QFechaHoraEntrega *InstanciaFechaHoraEntrega(void *,char **,void *,const char *,int);
#endif
