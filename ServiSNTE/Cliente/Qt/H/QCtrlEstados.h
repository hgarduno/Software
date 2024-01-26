#ifndef __QCTRLESTADOS_H__
#define __QCTRLESTADOS_H__ 
#include <qwidget.h>
#include <qwidgetplugin.h>

class zSiscomConexion;
class zSiscomRegistros;
class zSiscomRegistro;
class QHBoxLayout;
class QComboBox;
class QLineEdit;
class QT_WIDGET_PLUGIN_EXPORT QCtrlEstados : public QWidget
{
    Q_OBJECT
public:
    QCtrlEstados( QWidget *parent = 0, const char *name = 0);
	void IniciaControl();
	void ReIniciaControl();
	void Servidor(zSiscomConexion *pzSisConexion);
	void setFocus();
	const char *Estado();
private:
	void IniciaVariables();
	void ConsultaEstado();
	void MuestraEstado();
	void ConectaSlots();
	void keyPressEvent(QKeyEvent *);
private:
	QHBoxLayout *QHBLayout;
	QComboBox *QCBEstado;
	QLineEdit *QLEEstado;
	zSiscomRegistros *zSisRegEstados;
	zSiscomConexion *zSisConexion;
	zSiscomRegistro *zSisRegEstado;

private slots:
	void SlotEstado(int);
	void SlotCapturo();
	void SlotCapturandoEstado(const QString &pQStrTipoDocumento);
signals:
	void SignalNuevoEstado(const QString &);
	void SignalEstado(zSiscomRegistro *pzSisRegTipoDocumento);
	void SignalEstadoVacia();
};

#endif
