#ifndef __QCTRLTIPOVIVIENDAS_H__
#define __QCTRLTIPOVIVIENDAS_H__
#include <qwidget.h>
#include <qwidgetplugin.h>

class zSiscomConexion;
class zSiscomRegistros;
class zSiscomRegistro;
class QHBoxLayout;
class QComboBox;
class QLineEdit;
class QT_WIDGET_PLUGIN_EXPORT QCtrlTipoViviendaSS : public QWidget
{
    Q_OBJECT
public:
    	QCtrlTipoViviendaSS( QWidget *parent = 0, const char *name = 0);
	void IniciaControl();
	void ReIniciaControl();
	void Servidor(zSiscomConexion *pzSisConexion);
	void setFocus();
	const char *TipoVivienda();
private:
	void IniciaVariables();
	void ConsultaTipoVivienda();
	void MuestraTipoVivienda();
	void ConectaSlots();
	void keyPressEvent(QKeyEvent *);
private:
	QHBoxLayout *QHBLayout;
	QComboBox *QCBTipoVivienda;
	QLineEdit *QLETipoVivienda;
	zSiscomRegistros *zSisRegTipoViviendaSS;
	zSiscomConexion *zSisConexion;
	zSiscomRegistro *zSisRegTipoVivienda;

private slots:
	void SlotTipoVivienda(int);
	void SlotCapturo();
	void SlotCapturandoTipoVivienda(const QString &pQStrTipoDocumento);
signals:
	void SignalNuevoTipoVivienda(const QString &);
	void SignalTipoVivienda(zSiscomRegistro *pzSisRegTipoDocumento);
	void SignalTipoViviendaVacia();
};

#endif
