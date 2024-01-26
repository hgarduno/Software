#ifndef __QTIMPREGISTROINVENTARIO_H__
#define __QTIMPREGISTROINVENTARIO_H__
#include <RegistroInventario.h>

class zSiscomConexion;
class zSiscomRegistro;
class zSiscomRegistros;
class QtImpRegistroInventario:public RegistroInventario
{
Q_OBJECT
public:
	QtImpRegistroInventario(QWidget *pQWParent=0,
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
