#ifndef __QTIMPCATALOGOSTOCK_H__
#define __QTIMPCATALOGOSTOCK_H__
#include <cstddef>
#include <CatalogoStock.h>

class zSiscomConexion;
class zSiscomRegistro;
class zSiscomRegistros;

class QtImpCatalogoStock:public CatalogoStock
{
Q_OBJECT
public:
	QtImpCatalogoStock(QWidget *pQWParent,
			    const char *pchrPtrName);
	
private:
	void Conexion(zSiscomConexion *pzSiscomConexion);
	void ConectaSlots();
	void IniciaControles();
    void IniciaVariables();
private:
	zSiscomRegistros *zSisRegsDirecciones;
	zSiscomConexion *zSisConexion;
private slots:

};

#endif
