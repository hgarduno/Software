
#ifndef __IMP_INVENTARIOEXPENDIO_H__
#define __IMP_INVENTARIOEXPENDIO_H__
#include <UIC_H_InventarioExpendio.h>
class SiscomDatCom;
class zSiscomConexion;
class QInventarioExpendio:public InventarioExpendio
{
 Q_OBJECT
public:
	QInventarioExpendio(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QInventarioExpendio();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	zSiscomConexion *zSisConexion;
private:
	void ConectaSlots();
	void IniciaVariables();
private slots:
};
extern "C" QInventarioExpendio *InstanciaInventarioExpendio(void *,char **,void *,const char *,int);
#endif
