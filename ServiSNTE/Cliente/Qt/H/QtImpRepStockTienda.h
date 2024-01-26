#ifndef __QTIMPREPSTOCKTIENDA_H_
#define __QTIMPREPSTOCKTIENDA_H__
#include <RepStockTienda.h>


/*
 *
 *  QtImpPuntoDeVenta::QtImpPuntoDeVenta()
 *  {
 *  QtImpRepStockTienda *lQtImpRepStockTienda;
 *  lQtImpRepStockTienda=new QtImpRepStockTienda(this,"QtImpRepStockTienda");
 *
 *  }
 *
 *
 */
class zSiscomConexion;
class zSiscomRegistro;
class zSiscomRegistros;
class zStockTienda;
class QtImpRepStockTienda:public RepStockTienda
{
Q_OBJECT
public:
	QtImpRepStockTienda(QWidget *pQWParent=0,
			    const char *pchrPtrName=0);
private:
	void IniciaVariables();
	void ConectaSlots();
	void Conexion(zSiscomConexion *pzSisConexion);
	void Consultando();
	void Consulta();
	void Muestra();
	int MuestraProductosProveedor(int);
	int MuestraTotalProveedor(int );
private:
	zSiscomConexion *zSisConexion;
	zSiscomRegistro *zSisRegTienda;
	zSiscomRegistro *zSisRegProveedor;
	zStockTienda *zLstStock;
private:
private slots:
	void SlotTienda(zSiscomRegistro *pzSisRegTienda);
	void SlotProveedor(zSiscomRegistro *pzSisRegProveedor);
	void SlotConsulta();
	void SlotImprimir();
	
};

#endif
