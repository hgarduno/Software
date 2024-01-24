
#ifndef __IMP_ACTUALIZAPRECIOEXPENDIOS_H__
#define __IMP_ACTUALIZAPRECIOEXPENDIOS_H__
#include <QtActualizaPrecioExpendios.h>
class SiscomDatCom;
class zSiscomConexion;
class QActualizaPrecioExpendios:public QtActualizaPrecioExpendios
{
 Q_OBJECT
public:
	QActualizaPrecioExpendios(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QActualizaPrecioExpendios();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	zSiscomConexion *zSisConexion;
private:
	void Actualizando();
	void EjecutaActualizacion(zProductoPrecioExpendios *);
private slots:
};
extern "C" QActualizaPrecioExpendios *InstanciaActualizaPrecioExpendios(void *,char **,void *,const char *,int);
#endif
