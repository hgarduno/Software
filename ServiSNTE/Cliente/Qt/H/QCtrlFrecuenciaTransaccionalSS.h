#ifndef __QCTRLFRECUENCIATRANSACCIONAL_H__
#define __QCTRLFRECUENCIATRANSACCIONAL_H__
#include <qwidget.h>
#include <qwidgetplugin.h>

class zSiscomConexion;
class zSiscomRegistros;
class zSiscomRegistro;
class QHBoxLayout;
class QComboBox;
class QLineEdit;
class QT_WIDGET_PLUGIN_EXPORT QCtrlFrecuenciaTransaccionalSS : public QWidget
{
    Q_OBJECT
public:
    QCtrlFrecuenciaTransaccionalSS( QWidget *parent = 0, const char *name = 0);
	void IniciaControl();
	void ReIniciaControl();
	void Servidor(zSiscomConexion *pzSisConexion);
	void setFocus();
	const char *FrecuenciaTransaccional();
private:
	void IniciaVariables();
	void ConsultaFrecuenciaTransaccional();
	void MuestraFrecuenciaTransaccional();
	void ConectaSlots();
	void keyPressEvent(QKeyEvent *);
private:
	QHBoxLayout *QHBLayout;
	QComboBox *QCBFrecuenciaTransaccional;
	QLineEdit *QLEFrecuenciaTransaccional;
	zSiscomRegistros *zSisRegFrecuenciaTransaccionalSS;
	zSiscomConexion *zSisConexion;
	zSiscomRegistro *zSisRegFrecuenciaTransaccional;

private slots:
	void SlotFrecuenciaTransaccional(int);
	void SlotCapturo();
	void SlotCapturandoFrecuenciaTransaccional(const QString &pQStrTipoDocumento);
signals:
	void SignalNuevoFrecuenciaTransaccional(const QString &);
	void SignalFrecuenciaTransaccional(zSiscomRegistro *pzSisRegTipoDocumento);
	void SignalFrecuenciaTransaccionalVacia();
};

#endif
