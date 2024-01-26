#ifndef __QTIMPREPSTOCKPROVEEDORCOSTO_H__
#define __QTIMPREPSTOCKPROVEEDORCOSTO_H__
#include <RepStockProveedorCosto.h>

class zSiscomConexion;
class zSiscomRegistro;
class zSiscomRegistros;
class zExistenciaProveedor;
class QtImpRepStockProveedorCosto:public RepStockProveedorCosto
{
Q_OBJECT
public:
	QtImpRepStockProveedorCosto(QWidget *pQWParent=0,
				const char *pchrPtrName=0);
private:
	void IniciaVariables();
	void ConectaSlots();
	void Conexion(zSiscomConexion *pzSisConexion);
	void Consultando();
	void Consulta();
	void Muestra();
	void MuestraStockPorTienda(int pintFila);
	void AgregaColumnasTiendas();
	
private:
	zSiscomConexion *zSisConexion;
	zSiscomRegistro *zSisRegProveedor;
	zExistenciaProveedor *zExiProveedor;
private:
private slots:
	void SlotProveedor(zSiscomRegistro *);
	void SlotConsulta();
	void SlotImprimir();
	
};

#endif
