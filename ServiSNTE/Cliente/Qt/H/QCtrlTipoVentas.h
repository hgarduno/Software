#ifndef __QCTRLTIPOVENTAS_H__
#define __QCTRLTIPOVENTAS_H__
#include <qwidget.h>
#include <qwidgetplugin.h>

class zSiscomConexion;
class zSiscomRegistros;
class zSiscomRegistro;
class QHBoxLayout;
class QComboBox;
class QLineEdit;
class QT_WIDGET_PLUGIN_EXPORT QCtrlTipoVentas : public QWidget
{
    Q_OBJECT
public:
    QCtrlTipoVentas( QWidget *parent = 0, const char *name = 0);
	void IniciaControl();
	void ReIniciaControl();
	void Servidor(zSiscomConexion *pzSisConexion);
	void setFocus();
	const char *TipoVenta();
private:
	void IniciaVariables();
	void ConsultaTipoVenta();
	void MuestraTipoVenta();
	void ConectaSlots();
	void keyPressEvent(QKeyEvent *);
private:
	QHBoxLayout *QHBLayout;
	QComboBox *QCBTipoVenta;
	QLineEdit *QLETipoVenta;
	zSiscomRegistros *zSisRegTipoVentas;
	zSiscomConexion *zSisConexion;
	zSiscomRegistro *zSisRegTipoVenta;

private slots:
	void SlotTipoVenta(int);
	void SlotCapturo();
	void SlotCapturandoTipoVenta(const QString &pQStrTipoDocumento);
signals:
	void SignalNuevoTipoVenta(const QString &);
	void SignalTipoVenta(zSiscomRegistro *pzSisRegTipoDocumento);
	void SignalTipoVentaVacia();
};

#endif
