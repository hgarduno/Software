#ifndef __QCTRLFORMASENTREGA_H__
#define __QCTRLFORMASENTREGA_H__ 
#include <qwidget.h>
#include <qwidgetplugin.h>

class zSiscomConexion;
class zSiscomRegistros;
class zSiscomRegistro;
class QHBoxLayout;
class QComboBox;
class QLineEdit;
class QT_WIDGET_PLUGIN_EXPORT QCtrlFormasEntrega : public QWidget
{
    Q_OBJECT
public:
    QCtrlFormasEntrega( QWidget *parent = 0, const char *name = 0);
	void IniciaControl();
	void ReIniciaControl();
	void Servidor(zSiscomConexion *pzSisConexion);
	void setFocus();
	const char *FormaEntrega();
private:
	void IniciaVariables();
	void ConsultaFormaEntrega();
	void MuestraFormaEntrega();
	void ConectaSlots();
	void keyPressEvent(QKeyEvent *);
private:
	QHBoxLayout *QHBLayout;
	QComboBox *QCBFormaEntrega;
	QLineEdit *QLEFormaEntrega;
	zSiscomRegistros *zSisRegFormasEntrega;
	zSiscomConexion *zSisConexion;
	zSiscomRegistro *zSisRegFormaEntrega;

private slots:
	void SlotFormaEntrega(int);
	void SlotCapturo();
	void SlotCapturandoFormaEntrega(const QString &pQStrTipoDocumento);
signals:
	void SignalNuevoFormaEntrega(const QString &);
	void SignalFormaEntrega(zSiscomRegistro *pzSisRegTipoDocumento);
	void SignalFormaEntregaVacia();
};

#endif
