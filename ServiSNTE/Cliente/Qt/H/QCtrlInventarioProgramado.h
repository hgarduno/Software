#ifndef __QCTRLINVENTARIOPROGRAMADO_H__
#define __QCTRLINVENTARIOPROGRAMADO_H__ 
#include <qtable.h>
#include <qwidgetplugin.h>

class zSiscomConexion;
class zSiscomRegistros;
class zSiscomRegistro;
class zStockTienda;
class QT_WIDGET_PLUGIN_EXPORT QCtrlInventarioProgramado : public QTable
{
    Q_OBJECT
public:
    	QCtrlInventarioProgramado( QWidget *parent = 0, const char *name = 0);
	void Tienda(zSiscomRegistro *pzSisRegTienda);
	void IniciaControl();
	void ReIniciaControl();
	void Servidor(zSiscomConexion *pzSisConexion);
	const char *Stock();
private:
	void IniciaVariables();
	void ReConsultando();
	void ConsultaStock();
	void ConectaSlots();
	void FormaEncabezado();
private:
	zSiscomRegistros *zSisRegsStock;
	zSiscomConexion *zSisConexion;
	zSiscomRegistro *zSisRegTienda;
	zSiscomRegistro *zSisRegProveedor;
	zStockTienda *zLstStock;
	int intConCosto;
private slots:
signals:
};

#endif
