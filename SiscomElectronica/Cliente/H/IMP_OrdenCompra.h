
#ifndef __IMP_ORDENCOMPRA_H__
#define __IMP_ORDENCOMPRA_H__
#include <UIC_H_OrdenCompra.h>
class SiscomDatCom;
class QOrdenCompra:public OrdenCompra
{
 Q_OBJECT
public:
	QOrdenCompra(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QOrdenCompra();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
private:
	void ConectaSlots();
	void IniciaVariables();
	void closeEvent(QCloseEvent *);
private slots:
signals:
	void SignalTerminar(QWidget *);
};
extern "C" QOrdenCompra *InstanciaOrdenCompra(void *,char **,void *,const char *,int);
#endif
