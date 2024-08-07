
#ifndef __IMP_REGISTROPARCIALCOMIMP_H__
#define __IMP_REGISTROPARCIALCOMIMP_H__
#include <QtRegistroParcialComImp.h>

class zSiscomConexion;
class zCompraParcialImportacion;
class QRegistroParcialComImp:public QtRegistroParcialComImp
{
 Q_OBJECT
public:
	QRegistroParcialComImp(
		zCompraParcialImportacion *,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QRegistroParcialComImp();
private:
	zSiscomConexion *zSisConexion;
	zCompraParcialImportacion *zCompraParcialI;
private:
	void RegistrandoProductos();
	void IniciaVariables();
public slots:
	void SlotRegistroProductos();
signals:
	void SignalRegistro();
};
#endif
