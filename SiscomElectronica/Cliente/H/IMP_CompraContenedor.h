#ifndef __IMP_COMPRACONTENEDOR_H__
#define __IMP_COMPRACONTENEDOR_H__
#include <QtCompraContenedor.h>
class zSiscomConexion;
class SiscomDatCom;
class QCompraContenedor:public QtCompraContenedor
{
 Q_OBJECT
public:
	QCompraContenedor(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QCompraContenedor();
private:
	char **chrPtrArgumentos;
	zSiscomConexion *zSisConexion;
private:
	void ConectaSlots();
	void IniciaVariables();
private slots:
};
extern "C" QCompraContenedor *InstanciaCompraContenedor(void *,char **,void *,const char *,int);
#endif
