#ifndef __QTIMPSOPORTETRANSFERENCIAS_H__
#define __QTIMPSOPORTETRANSFERENCIAS_H__
#include <SoporteTransferencias.h>

class zSiscomConexion;
class zSiscomRegistro;
class zSiscomRegistros;
class zSoporteTransferencias;
class QtImpSoporteTransferencias:public SoporteTransferencias
{
Q_OBJECT
public:
	QtImpSoporteTransferencias(QWidget *pQWParent=0,
				const char *pchrPtrName=0);
private:
	void IniciaVariables();
	void ConectaSlots();
	void Conexion(zSiscomConexion *pzSisConexion);
private:
	zSiscomConexion *zSisConexion;
        zSiscomRegistro *zSisRegTienda;
	zSoporteTransferencias *zSptTransferencias;
private:
private slots:
        void SlotTienda(zSiscomRegistro *pzSisRegTienda);
	void SlotImprimir();
};

#endif
