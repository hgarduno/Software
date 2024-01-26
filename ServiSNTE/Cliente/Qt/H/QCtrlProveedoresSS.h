#ifndef __QCTRLPROVEEDORESSS_H__
#define __QCTRLPROVEEDORESSS_H__ 
#include <qwidget.h>
#include <qwidgetplugin.h>

class zSiscomConexion;
class zSiscomRegistros;
class zSiscomRegistro;
class QHBoxLayout;
class QComboBox;
class QLineEdit;
class QT_WIDGET_PLUGIN_EXPORT QCtrlProveedoresSS : public QWidget
{
    Q_OBJECT
public:
    QCtrlProveedoresSS( QWidget *parent = 0, const char *name = 0);
	void IniciaControl();
	void IniciaControlPorClave();
	void ReIniciaControl();
	void Servidor(zSiscomConexion *pzSisConexion);
	void setFocus();
	const char *Proveedor();
private:
	void IniciaVariables();
	void ConsultaProveedor();
	void MuestraProveedor();
	void MuestraProveedorPorClave();
	void ConectaSlots();
	void keyPressEvent(QKeyEvent *);
	void IniciaControlPorRazonSocial();
private:
	QHBoxLayout *QHBLayout;
	QComboBox *QCBProveedor;
	QLineEdit *QLEProveedor;
	zSiscomRegistros *zSisRegProveedoresSS;
	zSiscomConexion *zSisConexion;
	zSiscomRegistro *zSisRegProveedor;

private slots:
	void SlotProveedor(int);
	void SlotCapturo();
	void SlotCapturandoProveedor(const QString &pQStrProveedor);
signals:
	void SignalNuevoProveedor(const QString &);
	void SignalProveedor(zSiscomRegistro *pzSisRegProveedor);
	void SignalProveedorVacia();
};

#endif
