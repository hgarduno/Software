#ifndef __QTIMPSOPORTEVENTAS_H__
#define __QTIMPSOPORTEVENTAS_H__
#include <SoporteVentas.h>

class zSiscomConexion;
class zSiscomRegistro;
class zSiscomRegistros;
class zSoporteVentas;
class QtImpSoporteVentas:public SoporteVentas
{
Q_OBJECT
public:
	QtImpSoporteVentas(QWidget *pQWParent=0,
				const char *pchrPtrName=0);
private:
	void IniciaVariables();
	void ConectaSlots();
	void Conexion(zSiscomConexion *pzSisConexion);
private:
	zSiscomConexion *zSisConexion;
        zSiscomRegistro *zSisRegTienda;
	zSoporteVentas *zSptVentas;
private:
private slots:
        void SlotTienda(zSiscomRegistro *pzSisRegTienda);
        void SlotImprimir();
};

#endif
