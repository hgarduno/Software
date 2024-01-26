#ifndef __QCTRLCAMIONES_H__
#define __QCTRLCAMIONES_H__ 
#include <qwidget.h>
#include <qwidgetplugin.h>

class zSiscomConexion;
class zSiscomRegistros;
class zSiscomRegistro;
class QHBoxLayout;
class QComboBox;
class QLineEdit;
class QT_WIDGET_PLUGIN_EXPORT QCtrlCamiones : public QWidget
{
    Q_OBJECT
public:
    QCtrlCamiones( QWidget *parent = 0, const char *name = 0);
	void IniciaControl();
	void ReIniciaControl();
	void Servidor(zSiscomConexion *pzSisConexion);
	void setFocus();
	const char *Camion();
private:
	void IniciaVariables();
	void ConsultaCamion();
	void MuestraCamion();
	void ConectaSlots();
	void keyPressEvent(QKeyEvent *);
private:
	QHBoxLayout *QHBLayout;
	QComboBox *QCBCamion;
	QLineEdit *QLECamion;
	zSiscomRegistros *zSisRegCamiones;
	zSiscomConexion *zSisConexion;
	zSiscomRegistro *zSisRegCamion;

private slots:
	void SlotCamion(int);
	void SlotCapturo();
	void SlotCapturandoCamion(const QString &pQStrCamion);
signals:
	void SignalNuevoCamion(const QString &);
	void SignalCamion(zSiscomRegistro *pzSisRegCamion);
	void SignalCamionVacia();
};

#endif
