#ifndef __QCTRLVENDEDORES_H__
#define __QCTRLVENDEDORES_H__ 
#include <qwidget.h>
#include <qwidgetplugin.h>

class zSiscomConexion;
class zSiscomRegistros;
class zSiscomRegistro;
class QHBoxLayout;
class QComboBox;
class QLineEdit;
class QT_WIDGET_PLUGIN_EXPORT QCtrlVendedores : public QWidget
{
    Q_OBJECT
public:
    QCtrlVendedores( QWidget *parent = 0, const char *name = 0);
	void IniciaControl(const char *pchrArrTipoPersona);
	void ReIniciaControl();
	void Servidor(zSiscomConexion *pzSisConexion);
	void setFocus();
	const char *Vendedor();
private:
	void IniciaVariables();
	void ConsultaVendedor();
	void MuestraVendedor();
	void ConectaSlots();
	void keyPressEvent(QKeyEvent *);
private:
	QHBoxLayout *QHBLayout;
	QComboBox *QCBVendedor;
	QLineEdit *QLEVendedor;
	zSiscomRegistros *zSisRegVendedores;
	zSiscomConexion *zSisConexion;
	zSiscomRegistro *zSisRegVendedor;
    char lchrArrTipoPersona[20];
private slots:
	void SlotVendedor(int);
	void SlotCapturo();
	void SlotCapturandoVendedor(const QString &pQStrVendedor);
signals:
	void SignalNuevoVendedor(const QString &);
	void SignalVendedor(zSiscomRegistro *pzSisRegVendedor);
	void SignalVendedorVacia();
};

#endif
