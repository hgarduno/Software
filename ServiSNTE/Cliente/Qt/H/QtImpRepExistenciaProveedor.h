#ifndef __QTIMPREPEXISTENCIAPROVEEDOR_H__
#define __QTIMPREPEXISTENCIAPROVEEDOR_H__
#include <RepExistenciaProveedor.h>

class zSiscomConexion;
class zSiscomRegistro;
class zSiscomRegistros;
class zExistenciaProveedor;
class QtImpRepExistenciaProveedor:public RepExistenciaProveedor
{
Q_OBJECT
public:
	QtImpRepExistenciaProveedor(QWidget *pQWParent=0,
				const char *pchrPtrName=0);
private:
	void IniciaVariables();
	void ConectaSlots();
	void Conexion(zSiscomConexion *pzSisConexion);
private:
	zSiscomConexion *zSisConexion;
	zSiscomRegistro *zSisRegProveedor;
	zExistenciaProveedor *zExiProveedor;
private:
	void Consultando();
	void Consulta();
	void Muestra();
	int MuestraExistenciaTienda(int pintContador);
	int MuestraStockExistencia(int pintContador);
	int MuestraTotalExistencia(int pintContador);
	
private slots:
	void SlotProveedor(zSiscomRegistro *pzSisRegistro);
	void SlotConsulta();
	void SlotImprimir();
	
};

#endif
