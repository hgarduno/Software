#ifndef __QCTRLFRECUENCIAPAGOSSS_H__
#define __QCTRLFRECUENCIAPAGOSSS_H__
#include <qwidget.h>
#include <qwidgetplugin.h>

class zSiscomConexion;
class zSiscomRegistros;
class zSiscomRegistro;
class QHBoxLayout;
class QComboBox;
class QLineEdit;
class QT_WIDGET_PLUGIN_EXPORT QCtrlFrecuenciaPagosSS : public QWidget
{
    Q_OBJECT
public:
    QCtrlFrecuenciaPagosSS( QWidget *parent = 0, const char *name = 0);
	void IniciaControl();
	void ReIniciaControl();
	void Servidor(zSiscomConexion *pzSisConexion);
	void setFocus();
	const char *FrecunciaPago();
private:
	void IniciaVariables();
	void ConsultaFrecunciaPago();
	void MuestraFrecunciaPago();
	void ConectaSlots();
	void keyPressEvent(QKeyEvent *);
private:
	QHBoxLayout *QHBLayout;
	QComboBox *QCBFrecunciaPago;
	QLineEdit *QLEFrecunciaPago;
	zSiscomRegistros *zSisRegFrecuenciaPagosSS;
	zSiscomConexion *zSisConexion;
	zSiscomRegistro *zSisRegFrecunciaPago;

private slots:
	void SlotFrecunciaPago(int);
	void SlotCapturo();
	void SlotCapturandoFrecunciaPago(const QString &pQStrTipoDocumento);
signals:
	void SignalNuevoFrecunciaPago(const QString &);
	void SignalFrecunciaPago(zSiscomRegistro *pzSisRegTipoDocumento);
	void SignalFrecunciaPagoVacia();
};

#endif
