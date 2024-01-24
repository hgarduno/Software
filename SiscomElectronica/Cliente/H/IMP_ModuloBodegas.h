
#ifndef __IMP_MODULOBODEGAS_H__
#define __IMP_MODULOBODEGAS_H__
#include <QtModuloBodegas.h>
class SiscomDatCom;
class zSiscomConexion;
class QModuloBodegas:public QtModuloBodegas
{
 Q_OBJECT
public:
	QModuloBodegas(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QModuloBodegas();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	zSiscomConexion *zSisConexion;
};
extern "C" QModuloBodegas *InstanciaModuloBodegas(void *,char **,void *,const char *,int);
#endif
