#ifndef __QCTRLSALDOSMOVIMIENTOSMES_H__
#define __QCTRLSALDOSMOVIMIENTOSMES_H__ 
#include <qtable.h>
#include <qwidgetplugin.h>

class zSiscomConexion;
class zSiscomRegistros;
class zSiscomRegistro;
class zStockTienda;
class QT_WIDGET_PLUGIN_EXPORT QCtrlSaldosMovimientosMes : public QTable
{
    Q_OBJECT
public:
    	QCtrlSaldosMovimientosMes( QWidget *parent = 0, const char *name = 0);
	void Proveedor(zSiscomRegistro *pzSisRegProveedor);
	void Producto(zSiscomRegistro *pzSisRegProducto);
	void Tienda(zSiscomRegistro *pzSisRegTienda);
	void IniciaControl();
	void ReIniciaControl();
	void Servidor(zSiscomConexion *pzSisConexion);
private:
	void IniciaVariables();
	void FormaEncabezado();
	void ConectaSlots();
	void Consultando();
	void Consulta();
	void Muestra();
private:
	zSiscomRegistros *zSisRegsStock;
	zSiscomConexion *zSisConexion;
	zSiscomRegistro *zSisRegProveedor;
	zSiscomRegistro *zSisRegProducto;
	zSiscomRegistro *zSisRegTienda;
	zSiscomRegistros *zSisRegsSaldosMovimientosProdMes;
private slots:
	void SlotMes(int pintMes,int,int,const QPoint &);
signals:
	void SignalMes(int pintMes);
};

#endif
