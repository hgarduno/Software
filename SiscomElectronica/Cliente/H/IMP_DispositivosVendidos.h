
#ifndef __IMP_DISPOSITIVOSVENDIDOS_H__
#define __IMP_DISPOSITIVOSVENDIDOS_H__
#include <UIC_H_DispositivosVendidos.h>
class SiscomDatCom;
class QDispositivosVendidos:public DispositivosVendidos
{
 Q_OBJECT
public:
	QDispositivosVendidos(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QDispositivosVendidos();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
private:
	void ConectaSlots();
	void IniciaVariables();
private slots:
};
extern "C" QDispositivosVendidos *InstanciaDispositivosVendidos(void *,char **,void *,const char *,int);
#endif
