#ifndef __QTIMPSOPORTECOMPRAS_H__
#define __QTIMPSOPORTECOMPRAS_H__
#include <SoporteCompras.h>

class zSiscomConexion;
class zSiscomRegistro;
class zSiscomRegistros;
class zSoporteCompras;
class QtImpSoporteCompras:public SoporteCompras
{
Q_OBJECT
public:
	QtImpSoporteCompras(QWidget *pQWParent=0,
				const char *pchrPtrName=0);
private:
	void IniciaVariables();
	void ConectaSlots();
	void Conexion(zSiscomConexion *pzSisConexion);
private:
	zSiscomConexion *zSisConexion;
        zSiscomRegistro *zSisRegTienda;
        zSoporteCompras *zLstSoporte;

private:
private slots:
        void SlotTienda(zSiscomRegistro *pzSisRegTienda);
	void SlotImprimir();
};

#endif
