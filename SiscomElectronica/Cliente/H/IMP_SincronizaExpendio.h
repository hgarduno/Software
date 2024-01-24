
#ifndef __IMP_SINCRONIZAEXPENDIO_H__
#define __IMP_SINCRONIZAEXPENDIO_H__
#include <QtSincronizaExpendio.h>
class SiscomDatCom;
class zSiscomConexion;
class zListaExpendios;
class QSincronizaExpendio:public QtSincronizaExpendio
{
 Q_OBJECT
public:
	QSincronizaExpendio(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QSincronizaExpendio();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	zSiscomConexion *zSisConexion;
private:
	void ConectaSlots();
	void IniciaVariables();
	void SincronizaProductos(zListaExpendios *);
	void SincronizaPrecios();
private slots:
};
extern "C" QSincronizaExpendio *InstanciaSincronizaExpendio(void *,char **,void *,const char *,int);
#endif
