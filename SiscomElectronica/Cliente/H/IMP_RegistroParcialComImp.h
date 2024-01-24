
#ifndef __IMP_REGISTROPARCIALCOMIMP_H__
#define __IMP_REGISTROPARCIALCOMIMP_H__
#include <QtRegistroParcialComImp.h>

class zSiscomConexion;
class QRegistroParcialComImp:public QtRegistroParcialComImp
{
 Q_OBJECT
public:
	QRegistroParcialComImp(char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QRegistroParcialComImp();
private:
	char **chrPtrArgumentos;
	zSiscomConexion *zSisConexion;
private:
	void RegistrandoProductos();
public slots:
	void SlotRegistroProductos();
};
#endif
