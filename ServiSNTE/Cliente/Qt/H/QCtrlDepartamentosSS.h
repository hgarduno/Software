#ifndef __QCTRLDEPARTAMENTOSSS_H__
#define __QCTRLDEPARTAMENTOSSS_H__ 
#include <qwidget.h>
#include <qwidgetplugin.h>

class zSiscomConexion;
class zSiscomRegistros;
class zSiscomRegistro;
class QHBoxLayout;
class QComboBox;
class QLineEdit;
class QT_WIDGET_PLUGIN_EXPORT QCtrlDepartamentosSS : public QWidget
{
    Q_OBJECT
public:
    QCtrlDepartamentosSS( QWidget *parent = 0, const char *name = 0);
	void IniciaControl();
	void ReIniciaControl();
	void Servidor(zSiscomConexion *pzSisConexion);
	void setFocus();
	const char *Departamento();
private:
	void IniciaVariables();
	void ConsultaDepartamento();
	void MuestraDepartamento();
	void ConectaSlots();
	void keyPressEvent(QKeyEvent *);
private:
	QHBoxLayout *QHBLayout;
	QComboBox *QCBDepartamento;
	QLineEdit *QLEDepartamento;
	zSiscomRegistros *zSisRegDepartamentosSS;
	zSiscomConexion *zSisConexion;
	zSiscomRegistro *zSisRegDepartamento;

private slots:
	void SlotDepartamento(int);
	void SlotCapturo();
	void SlotCapturandoDepartamento(const QString &pQStrDepartamento);
signals:
	void SignalNuevoDepartamento(const QString &);
	void SignalDepartamento(zSiscomRegistro *pzSisRegDepartamento);
	void SignalDepartamentoVacia();
};

#endif
