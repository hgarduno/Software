#ifndef __QCTRLEXISTENCIAPROVEEDOR_H__
#define __QCTRLEXISTENCIAPROVEEDOR_H__ 
#include <qtable.h>
#include <qwidgetplugin.h>

class zSiscomConexion;
class zSiscomRegistros;
class zSiscomRegistro;
class zExistenciaProveedor;
class QT_WIDGET_PLUGIN_EXPORT QCtrlExistenciaProveedor : public QTable
{
    Q_OBJECT
public:
    	QCtrlExistenciaProveedor( QWidget *parent = 0, const char *name = 0);
	void Proveedor(zSiscomRegistro *pzSisRegProveedor);
	void Producto(zSiscomRegistro *pzSisRegProducto);
	void IniciaControl();
	void ReIniciaControl();
	void Servidor(zSiscomConexion *pzSisConexion);
	void ReConsultando();
	void TipoVista(int );
	zExistenciaProveedor *ExistenciaProveedor();
private:
	void IniciaVariables();
	void ConectaSlots();
	void FormaEncabezado();

	void Consultando();
	void Consulta();
	void Muestra();

	int MuestraExistenciaTienda(int pintContador);
	int MuestraStockExistencia(int pintContador);
	int MuestraTotalExistencia(int pintContador);

	void MuestraFormatoSaldosMovimientos();
	void EncabezadoSaldosMovimientos();
	void ConsultandoSaldosMovimientos();
	void ConsultaSaldosMovimientos();
	void SaldosMovimientos();
	int MuestraTiendasSaldosMovimientos(int pintContador);

private:
	zSiscomConexion *zSisConexion;
	zSiscomRegistro *zSisRegProveedor;
	zSiscomRegistro *zSisRegProducto;
	zExistenciaProveedor *zExiProveedor;
	/* Tipo de vista
	 *  Define como se muestran los datos , la idea es usar este
	 *  control en todos los lugares donde se requiera la existencia
	 *  en todas las tiendas
	 *
	 *  intTipoVista 0   Se muestra en formato de saldos y movimientos
	 *
	 */
	int intTipoVista;
private slots:
signals:
};

#endif
