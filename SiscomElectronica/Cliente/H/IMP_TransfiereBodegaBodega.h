#ifndef __IMPTRANSFIEREBODEGABODEGA_H__
#define __IMPTRANSFIEREBODEGABODEGA_H__
#include <QtTransfiereBodegaBodega.h>

class zSiscomConexion;
class zExistenciaBodega;
class QTransfiereBodegaBodega:public QtTransfiereBodegaBodega
{
Q_OBJECT
public:
	QTransfiereBodegaBodega(zSiscomConexion *,
				char **,
				QWidget *pQWParent=0,
				const char *pchrPtrName=0,
				WFlags pWFlags=0);

private:
	void Transfiere();
	void Consultando(zExistenciaBodega *);
};
#endif
