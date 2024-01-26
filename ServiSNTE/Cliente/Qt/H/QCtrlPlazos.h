#ifndef __QCTRLPLAZOS_H__
#define __QCTRLPLAZOS_H__ 
#include <qwidget.h>
#include <qwidgetplugin.h>

class zSiscomConexion;
class zSiscomRegistros;
class zSiscomRegistro;
class QHBoxLayout;
class QComboBox;
class QLineEdit;
class QT_WIDGET_PLUGIN_EXPORT QCtrlPlazos : public QWidget
{
    Q_OBJECT
public:
    QCtrlPlazos( QWidget *parent = 0, const char *name = 0);
	void IniciaControl();
	void ReIniciaControl();
	void Servidor(zSiscomConexion *pzSisConexion);
	void setFocus();
	const char *Plazo();
private:
	void IniciaVariables();
	void ConsultaPlazo();
	void MuestraPlazo();
	void ConectaSlots();
	void keyPressEvent(QKeyEvent *);
private:
	QHBoxLayout *QHBLayout;
	QComboBox *QCBPlazo;
	QLineEdit *QLEPlazo;
	zSiscomRegistros *zSisRegPlazos;
	zSiscomConexion *zSisConexion;
	zSiscomRegistro *zSisRegPlazo;

private slots:
	void SlotPlazo(int);
	void SlotCapturo();
	void SlotCapturandoPlazo(const QString &pQStrPlazo);
signals:
	void SignalNuevoPlazo(const QString &);
	void SignalPlazo(zSiscomRegistro *pzSisRegPlazo);
	void SignalPlazoVacia();
};

#endif
