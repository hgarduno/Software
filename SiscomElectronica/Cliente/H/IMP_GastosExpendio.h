
#ifndef __IMP_GASTOSEXPENDIO_H__
#define __IMP_GASTOSEXPENDIO_H__
#include <UIC_H_GastosExpendio.h>
class zSiscomConexion;
class zSiscomRegistros;
class zSiscomRegistro;

class SiscomDatCom;
class QGastosExpendio:public GastosExpendio
{
 Q_OBJECT
public:
	QGastosExpendio(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QGastosExpendio();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	zSiscomConexion *zSisConexion;
private:
	void ConectaSlots();
	void IniciaVariables();
private slots:
};
extern "C" QGastosExpendio *InstanciaGastosExpendio(void *,char **,void *,const char *,int);
#endif
