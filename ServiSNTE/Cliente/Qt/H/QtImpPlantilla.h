#ifndef __QTIMPREPSTOCKDEPARTAMENTOPROVEEDOR_H__
#define __QTIMPREPSTOCKDEPARTAMENTOPROVEEDOR_H__
#include <RepStockDepartamentoProveedor.h>

class zSiscomConexion;
class zSiscomRegistro;
class zSiscomRegistros;
class QtImpRepStockDepartamentoProveedor:public RepStockDepartamentoProveedor
{
Q_OBJECT
public:
	QtImpRepStockDepartamentoProveedor(QWidget *pQWParent=0,
				const char *pchrPtrName=0);
private:
	void IniciaVariables();
	void ConectaSlots();
	void Conexion(zSiscomConexion *pzSisConexion);
private:
	zSiscomConexion *zSisConexion;
private:
private slots:
	
};

#endif
