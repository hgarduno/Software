#ifndef __QTIMPSALDOSMOVIMIENTOS_H__
#define __QTIMPSALDOSMOVIMIENTOS_H__
#include <SaldosMovimientos.h>

class zSiscomConexion;
class zSiscomRegistro;
class zSiscomRegistros;
class zExistenciaProveedor;
class QtImpSaldosMovimientos:public SaldosMovimientos
{
Q_OBJECT
public:
	QtImpSaldosMovimientos(QWidget *pQWParent=0,
				const char *pchrPtrName=0);
private:
	void IniciaVariables();
	void ConectaSlots();
	void Conexion(zSiscomConexion *pzSisConexion);
private:
	zSiscomConexion *zSisConexion;

	zSiscomRegistro *zSisRegProveedor;
	zSiscomRegistro *zSisRegTienda;
	zSiscomRegistro *zSisRegProducto;
	zExistenciaProveedor *zExiProveedor;
private:
	void ConsultandoProductosProveedor();
	void SaldosProducto();
	void MuestraTotalesProducto();
	void SaldosMovimientosMes();
private slots:
	void SlotProveedor(zSiscomRegistro *pzSisRegProveedor);
	void SlotTienda(zSiscomRegistro *pzSisRegTienda);
	void SlotProducto(zSiscomRegistro *pzSisRegProducto);
	void SlotConsultando();
	void SlotMes(int pintMes);
	
};

#endif
