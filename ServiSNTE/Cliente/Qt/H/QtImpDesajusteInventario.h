#ifndef __QTIMPDESAJUSTEINVENTARIO_H__
#define __QTIMPDESAJUSTEINVENTARIO_H__
#include <DesajusteInventario.h>

class zSiscomConexion;
class zSiscomRegistro;
class zSiscomRegistros;
class QtImpDesajusteInventario:public DesajusteInventario
{
Q_OBJECT
public:
	QtImpDesajusteInventario(QWidget *pQWParent=0,
				const char *pchrPtrName=0);
private:
	void IniciaVariables();
	void ConectaSlots();
	void Conexion(zSiscomConexion *pzSisConexion);
private:
	zSiscomConexion *zSisConexion;
        zSiscomRegistro *zSisRegTienda;
private:
private slots:
        void SlotTienda(zSiscomRegistro *pzSisRegProveedor);
};

#endif
