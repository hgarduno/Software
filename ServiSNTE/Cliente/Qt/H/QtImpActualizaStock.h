#ifndef __QTIMPACTUALIZASTOCK_H__
#define __QTIMPACTUALIZASTOCK_H__
#include <ActualizaStock.h>

class zSiscomConexion;
class zSiscomRegistro;
class zSiscomRegistros;
class zStockTienda;
class QtImpActualizaStock:public ActualizaStock
{
Q_OBJECT
public:
	QtImpActualizaStock(QWidget *pQWParent=0,
				const char *pchrPtrName=0);
private:
	void IniciaVariables();
	void ConectaSlots();
	void Conexion(zSiscomConexion *pzSisConexion);
	void Consultando();
	void Consulta();
	void Muestra();
	void Actualizando();
	void ConsultandoProductosProveedor();
	void HabilitaDesHabilita(bool pbEstado);
private:
	zSiscomConexion *zSisConexion;
	zSiscomRegistro *zSisRegProveedor;
	zSiscomRegistro *zSisRegTienda;
	zSiscomRegistro *zSisRegProducto;
	zStockTienda *zLstStock;;
private slots:
	void SlotProveedor(zSiscomRegistro *pzSisRegProveedor);
	void SlotTienda(zSiscomRegistro *pzSisRegTienda);
	void SlotFocoANumeroProducto();
	void SlotStock();
	void SlotConsultando();
	void SlotFocoAStock();
	void SlotFocoAActualizar();
	void SlotActualizar();
	void SlotProducto(zSiscomRegistro *);
};

#endif
