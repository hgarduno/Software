
#ifndef __IMP_LISTAPUNTOSENTREGA_H__
#define __IMP_LISTAPUNTOSENTREGA_H__
#include <QtListaPuntosEntrega.h>
class zSiscomConexion;


class zPuntosEntrega;
class QListaPuntosEntrega:public QtListaPuntosEntrega
{
 Q_OBJECT
public:
	QListaPuntosEntrega(zSiscomConexion *,
			QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    bool pbModal=false,
	    WFlags pWFlags=0);
	~QListaPuntosEntrega();
private:
private:
	void Ejecutando();
	void Consultando();
	void Consulta();
private:
	zSiscomConexion *zSisConexion;
	zPuntosEntrega *zPsEntrega;
private slots:
};
#endif
