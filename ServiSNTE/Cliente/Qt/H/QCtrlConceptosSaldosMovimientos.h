#ifndef __QCTRLCONCEPTOSSALDOSMOVIMIENTOS_H__
#define __QCTRLCONCEPTOSSALDOSMOVIMIENTOS_H__ 
#include <qtable.h>
#include <qwidgetplugin.h>

class zSiscomConexion;
class zSiscomRegistros;
class zSiscomRegistro;
class zStockTienda;
class QT_WIDGET_PLUGIN_EXPORT QCtrlConceptosSaldosMovimientos : public QTable
{
    Q_OBJECT
public:
    	QCtrlConceptosSaldosMovimientos( QWidget *parent = 0, const char *name = 0);
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
	zSiscomRegistro *zSisRegProducto;
	zSiscomRegistro *zSisRegTienda;
	zSiscomRegistros *zSisRegsConceptosSaldosMovimientos;
private slots:
	void SlotMes(int pintMes,int,int,const QPoint &);
signals:
	void SignalMes(int pintMes);
};

#endif
