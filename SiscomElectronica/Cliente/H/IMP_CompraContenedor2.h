
#ifndef __IMP_COMPRACONTENEDOR2_H__
#define __IMP_COMPRACONTENEDOR2_H__
#include <QtCompraContenedor2.h>
class SiscomDatCom;
class zSiscomConexion;
class QCompraContenedor2:public QtCompraContenedor2
{
 Q_OBJECT
public:
	QCompraContenedor2(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QCompraContenedor2();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	zSiscomConexion *zSisConexion;
private:
	void ConectaSlots();
	void IniciaVariables();
private slots:
};
extern "C" QCompraContenedor2 *InstanciaCompraContenedor2(void *,char **,void *,const char *,int);
#endif
