
#ifndef __IMP_SINCRONIZAPRODUCTOS_H__
#define __IMP_SINCRONIZAPRODUCTOS_H__
#include <QtSincronizaProductos.h>
class SiscomDatCom;
class QSincronizaProductos:public QtSincronizaProductos
{
 Q_OBJECT
public:
	QSincronizaProductos(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QSincronizaProductos();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
private:
private slots:
};
extern "C" QSincronizaProductos *InstanciaSincronizaProductos(void *,char **,void *,const char *,int);
#endif
