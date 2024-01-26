#ifndef __QTIMPPROVEEDORES_H__
#define __QTIMPPROVEEDORES_H__
#include <cstddef>
#include <Proveedores.h>

class zSiscomConexion;
class zSiscomRegistro;

class QtImpProveedores:public Proveedores
{
Q_OBJECT
public:
	QtImpProveedores(QWidget *pQWParent,
			  const char *pchrPtrName);

public:
	void Conexion(zSiscomConexion *pzSiscomConexion);
	void ConectaSlots();
private:
	zSiscomConexion *zSisConexion;
private slots:

};



#endif
