#ifndef __QTIMPCAPTURACHOFERES_H__
#define __QTIMPCAPTURACHOFERES_H__
#include <cstddef>
#include <CapturaChoferes.h>

class zSiscomConexion;
class zSiscomRegistro;

class QtImpCapturaChoferes:public CapturaChoferes
{
Q_OBJECT
public:
	QtImpCapturaChoferes(QWidget *pQWParent,
			  const char *pchrPtrName);

public:
	void Conexion(zSiscomConexion *pzSiscomConexion);
	void ConectaSlots();
private:
	zSiscomConexion *zSisConexion;
private slots:

};



#endif
