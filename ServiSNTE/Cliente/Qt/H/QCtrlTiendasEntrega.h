#ifndef __QCTRLTIENDASENTREGA_H__
#define __QCTRLTIENDASENTREGA_H__ 
#include <qwidget.h>
#include <qwidgetplugin.h>

class zSiscomConexion;
class zSiscomRegistros;
class zSiscomRegistro;
class QHBoxLayout;
class QComboBox;
class QLineEdit;
class QT_WIDGET_PLUGIN_EXPORT QCtrlTiendasEntrega : public QWidget
{
    Q_OBJECT
public:
    QCtrlTiendasEntrega( QWidget *parent = 0, const char *name = 0);
	void IniciaControl();
	void ReIniciaControl();
	void Servidor(zSiscomConexion *pzSisConexion);
	void setFocus();
	const char *Tienda();
private:
	void IniciaVariables();
	void ConsultaTienda();
	void MuestraTienda();
	void ConectaSlots();
	void keyPressEvent(QKeyEvent *);
private:
	QHBoxLayout *QHBLayout;
	QComboBox *QCBTienda;
	QLineEdit *QLETienda;
	zSiscomRegistros *zSisRegTiendasEntrega;
	zSiscomConexion *zSisConexion;
	zSiscomRegistro *zSisRegTienda;

private slots:
	void SlotTienda(int);
	void SlotCapturo();
	void SlotCapturandoTienda(const QString &pQStrTienda);
signals:
	void SignalNuevoTienda(const QString &);
	void SignalTienda(zSiscomRegistro *pzSisRegTienda);
	void SignalTiendaVacia();
};

#endif
