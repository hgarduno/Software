
#ifndef __IMP_FACTURACONTENEDOR_H__
#define __IMP_FACTURACONTENEDOR_H__
#include <QtFacturaContenedor.h>

class zCompraImportacion;
class QFacturaContenedor:public QtFacturaContenedor
{
 Q_OBJECT
public:
	QFacturaContenedor(zSiscomConexion *pzSisConexion,
	QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    bool pbModal=false,
	    WFlags pWFlags=0);
	~QFacturaContenedor();
private:
private:
	void Inicia();
private slots:
};
#endif
