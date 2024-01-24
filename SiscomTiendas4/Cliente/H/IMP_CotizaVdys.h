
#ifndef __IMP_COTIZAVDYS_H__
#define __IMP_COTIZAVDYS_H__
#include <UIC_H_CotizaVdys.h>
class SiscomDatCom;
class QCotizaVdys:public CotizaVdys
{
 Q_OBJECT
public:
	QCotizaVdys(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QCotizaVdys();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
private:
	void ConectaSlots();
	void IniciaVariables();
private slots:
	void SlotSCliente();
};
extern "C" QCotizaVdys *InstanciaCotizaVdys(void *,char **,void *,const char *,int);
#endif
