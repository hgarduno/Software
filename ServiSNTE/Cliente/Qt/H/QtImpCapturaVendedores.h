#ifndef __QTIMPCAPTURAVENDEDORES_H__
#define __QTIMPCAPTURAVENDEDORES_H__
#include <cstddef>
#include <CapturaVendedores.h>

class zSiscomConexion;
class zSiscomRegistro;

class QtImpCapturaVendedores:public CapturaVendedores
{
Q_OBJECT
public:
	QtImpCapturaVendedores(QWidget *pQWParent,
			  const char *pchrPtrName);

public:
	void Conexion(zSiscomConexion *pzSiscomConexion);
	void ConectaSlots();
	void IniciaControles();
private:
	zSiscomConexion *zSisConexion;
private slots:

};



#endif
