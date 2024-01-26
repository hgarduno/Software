#ifndef __QCTRLPROVEEDORES_H__
#define __QCTRLPROVEEDORES_H__ 
#include <qwidget.h>
#include <qwidgetplugin.h>

class zSiscomConexion;
class zSiscomRegistros;
class zSiscomRegistro;
class QHBoxLayout;
class QComboBox;
class QLineEdit;
class QT_WIDGET_PLUGIN_EXPORT QCtrlProveedores : public QWidget
{
    Q_OBJECT
public:
    QCtrlProveedores( QWidget *parent = 0, const char *name = 0);
	void IniciaControl();
	void ReIniciaControl();
	void Servidor(zSiscomConexion *pzSisConexion);
	void setFocus();
	const char *Concepto();
private:
	void IniciaVariables();
	void ConsultaConcepto();
	void MuestraConcepto();
	void ConectaSlots();
	void keyPressEvent(QKeyEvent *);
private:
	QHBoxLayout *QHBLayout;
	QComboBox *QCBConcepto;
	QLineEdit *QLEConcepto;
	zSiscomRegistros *zSisRegProveedores;
	zSiscomConexion *zSisConexion;
	zSiscomRegistro *zSisRegConcepto;

private slots:
	void SlotConcepto(int);
	void SlotCapturo();
	void SlotCapturandoConcepto(const QString &pQStrConcepto);
signals:
	void SignalNuevoConcepto(const QString &);
	void SignalConcepto(zSiscomRegistro *pzSisRegConcepto);
	void SignalConceptoVacia();
};

#endif
