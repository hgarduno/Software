#ifndef __QTIMPREPEXISTENCIATIENDAPROVEEDOR_H__
#define __QTIMPREPEXISTENCIATIENDAPROVEEDOR_H__
#include <RepExistenciaTiendaProveedor.h>

class zSiscomConexion;
class zSiscomRegistro;
class zSiscomRegistros;
class zExistenciaTiendaProveedor;
class QtImpRepExistenciaTiendaProveedor:public RepExistenciaTiendaProveedor
{
Q_OBJECT
public:
	QtImpRepExistenciaTiendaProveedor(QWidget *pQWParent=0,
				const char *pchrPtrName=0);
private:
	void IniciaVariables();
	void ConectaSlots();
	void Conexion(zSiscomConexion *pzSisConexion);
private:
	zSiscomConexion *zSisConexion;
	zExistenciaTiendaProveedor *zExtTiendaProveedor;
private:
private slots:
	void SlotImprimir();
};

#endif
