
#ifndef __IMP_PRODUCTOSFALTANTES4_H__
#define __IMP_PRODUCTOSFALTANTES4_H__
#include <UIC_H_ProductosFaltantes4.h>
class SiscomDatCom;
class zSiscomConexion;
class QProductosFaltantes4:public ProductosFaltantes4
{
 Q_OBJECT
public:
	QProductosFaltantes4(char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    bool pbModal=false,
	    WFlags pWFlags=0);
	~QProductosFaltantes4();
private:
	char **chrPtrArgumentos;
	zSiscomConexion *zSisConexion;
private:
	void ConectaSlots();
	void IniciaVariables();
private slots:
};
#endif
