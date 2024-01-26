#ifndef __QCTRLFINANCIADORAS_H__
#define __QCTRLFINANCIADORAS_H__ 
#include <qwidget.h>
#include <qwidgetplugin.h>

class zSiscomConexion;
class zSiscomRegistros;
class zSiscomRegistro;
class QHBoxLayout;
class QComboBox;
class QLineEdit;
class QT_WIDGET_PLUGIN_EXPORT QCtrlFinanciadoras : public QWidget
{
    Q_OBJECT
public:
    QCtrlFinanciadoras( QWidget *parent = 0, const char *name = 0);
	void IniciaControl();
	void ReIniciaControl();
	void Servidor(zSiscomConexion *pzSisConexion);
	void setFocus();
	const char *Financiadora();
private:
	void IniciaVariables();
	void ConsultaFinanciadora();
	void MuestraFinanciadora();
	void ConectaSlots();
	void keyPressEvent(QKeyEvent *);
private:
	QHBoxLayout *QHBLayout;
	QComboBox *QCBFinanciadora;
	QLineEdit *QLEFinanciadora;
	zSiscomRegistros *zSisRegFinanciadoras;
	zSiscomConexion *zSisConexion;
	zSiscomRegistro *zSisRegFinanciadora;

private slots:
	void SlotFinanciadora(int);
	void SlotCapturo();
	void SlotCapturandoFinanciadora(const QString &pQStrTipoDocumento);
signals:
	void SignalNuevoFinanciadora(const QString &);
	void SignalFinanciadora(zSiscomRegistro *pzSisRegTipoDocumento);
	void SignalFinanciadoraVacia();
};

#endif
