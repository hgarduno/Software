#ifndef __QCTRLPRODUCTOSSS_H__
#define __QCTRLPRODUCTOSSS_H__ 
#include <qwidget.h>
#include <qwidgetplugin.h>

class zSiscomConexion;
class zSiscomRegistros;
class zSiscomRegistro;
class QHBoxLayout;
class QComboBox;
class QLineEdit;
class QT_WIDGET_PLUGIN_EXPORT QCtrlProductosSS : public QWidget
{
    Q_OBJECT
public:
    QCtrlProductosSS( QWidget *parent = 0, const char *name = 0);
	void IniciaControl();
	void ReIniciaControl();
	void Servidor(zSiscomConexion *pzSisConexion);
	void Proveedor(zSiscomRegistro *pzSisProveedor);
	void setFocus();
	const char *Producto();
	zSiscomRegistros *Productos();
private:
	void IniciaVariables();
	void ConsultaProducto();
	void ConectaSlots();
	void keyPressEvent(QKeyEvent *);
	void MuestraProductosDescripcion();
	void MuestraProductosNumeroProducto();
private:
	QHBoxLayout *QHBLayout;
	QComboBox *QCBProducto;
	QLineEdit *QLEProducto;
	zSiscomRegistros *zSisRegProductosSS;
	zSiscomConexion *zSisConexion;
	zSiscomRegistro *zSisRegProducto;
	zSiscomRegistro *zSisProveedor;

private slots:
	void SlotProducto(int);
	void SlotCapturo();
	void SlotCapturandoProducto(const QString &pQStrProducto);
signals:
	void SignalNuevoProducto(const QString &);
	void SignalProducto(zSiscomRegistro *pzSisRegProducto);
	void SignalProductoVacia();
};

#endif
