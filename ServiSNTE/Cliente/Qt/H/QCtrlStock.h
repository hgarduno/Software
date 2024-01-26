#ifndef __QCTRLSTOCK_H__
#define __QCTRLSTOCK_H__ 
#include <qtable.h>
#include <qwidgetplugin.h>

class zSiscomConexion;
class zSiscomRegistros;
class zSiscomRegistro;
class zStockTienda;
class QT_WIDGET_PLUGIN_EXPORT QCtrlStock : public QTable
{
    Q_OBJECT
public:
    	QCtrlStock( QWidget *parent = 0, const char *name = 0);
	void Proveedor(zSiscomRegistro *pzSisRegProveedor);
	void Tienda(zSiscomRegistro *pzSisRegTienda);
	void IniciaControl();
	void ReIniciaControl();
	void Servidor(zSiscomConexion *pzSisConexion);
	const char *Stock();
	void ConCosto(int pintConCosto);
	void ReConsultando();
private:
	void IniciaVariables();
	void ConsultaStock();
	void MuestraStock();
	int MuestraProductosProveedor(int pintContador);
	void ConectaSlots();
	void FormaEncabezado();
private:
	zSiscomRegistros *zSisRegsStock;
	zSiscomConexion *zSisConexion;
	zSiscomRegistro *zSisRegStock;
	zSiscomRegistro *zSisRegTienda;
	zSiscomRegistro *zSisRegProveedor;
	zStockTienda *zLstStock;
	int intConCosto;
private slots:
signals:
};

#endif
