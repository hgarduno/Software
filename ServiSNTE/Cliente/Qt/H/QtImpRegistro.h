#ifndef __QTIMPREGISTRO_H__
#define __QTIMPREGISTRO_H__
#include <Registro.h>

class zSiscomConexion;
class zSiscomRegistro;
class zSiscomRegistros;
class QtImpRegistro:public Registro
{
Q_OBJECT
public:
	QtImpRegistro(QWidget *pQWParent=0,
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
