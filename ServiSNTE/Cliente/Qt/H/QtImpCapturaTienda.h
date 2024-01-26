#ifndef __QTIMPCAPTURATIENDA_H__
#define __QTIMPCAPTURATIENDA_H__
#include <cstddef>
#include <CapturaTienda.h>

class zSiscomConexion;
class zSiscomRegistro;

class QtImpCapturaTienda:public CapturaTienda
{
Q_OBJECT
public:
	QtImpCapturaTienda(QWidget *pQWParent,
			  const char *pchrPtrName);

public:
	void Conexion(zSiscomConexion *pzSiscomConexion);

	void IniciaControles();
	void ConectaSlots();
private:
	zSiscomConexion *zSisConexion;
private slots:

};



#endif
