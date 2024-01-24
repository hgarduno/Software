#ifndef __IMP_INVENTARIOBODEGA4_H__
#define __IMP_INVENTARIOBODEGA4_H__
#include <QtInventarioBodega4.h>
class zSiscomConexion;

class zBodega;
class QInventarioBodega4:public QtInventarioBodega4
{
 Q_OBJECT
public:
	QInventarioBodega4(zSiscomConexion *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QInventarioBodega4();
	void Bodega(zBodega *);
	void setFocus();
private:
private:
	void ConsultandoExistencia();
	void Actualizando();
private slots:
};
#endif
