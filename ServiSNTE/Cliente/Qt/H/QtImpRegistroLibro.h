#ifndef __QTIMPREGISTROLIBRO_H__
#define __QTIMPREGISTROLIBRO_H__
#include <RegistroLibro.h>

class zSiscomConexion;
class zSiscomRegistro;
class zSiscomRegistros;
class zCuentasPagar;
class QtImpRegistroLibro:public RegistroLibro
{
Q_OBJECT
public:
	QtImpRegistroLibro(QWidget *pQWParent=0,
				const char *pchrPtrName=0);
private:
	void IniciaVariables();
	void ConectaSlots();
	void Conexion(zSiscomConexion *pzSisConexion);
private:
	zSiscomConexion *zSisConexion;
	zCuentasPagar *zCtsPagar;
private:
private slots:
	void SlotImprimir();
	
};

#endif
