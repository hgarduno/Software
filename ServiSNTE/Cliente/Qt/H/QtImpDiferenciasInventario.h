#ifndef __QTIMPDIFERENCIASINVENTARIO_H__
#define __QTIMPDIFERENCIASINVENTARIO_H__
#include <DiferenciasInventario.h>

class zSiscomConexion;
class zSiscomRegistro;
class zSiscomRegistros;
class QtImpDiferenciasInventario:public DiferenciasInventario
{
Q_OBJECT
public:
	QtImpDiferenciasInventario(QWidget *pQWParent=0,
				const char *pchrPtrName=0);
private:
	void IniciaVariables();
	void ConectaSlots();
	void Conexion(zSiscomConexion *pzSisConexion);
private:
	zSiscomConexion *zSisConexion;
private:
private slots:
	
};

#endif
