#ifndef __QCTRLMETODOPAGOSAT_H__
#define __QCTRLMETODOPAGOSAT_H__
#include <qwidget.h>
#include <qwidgetplugin.h>
#include <SiscomRegistros3.h>

class QHBoxLayout;
class QComboBox;
class QLineEdit;
class zSiscomConexion;
class zSiscomRegistros;
class zSiscomRegistro;

class QT_WIDGET_PLUGIN_EXPORT QCtrlMetodoPagoSat:public QWidget 
{
Q_OBJECT
public:
	QCtrlMetodoPagoSat(QWidget *pQWParent=0,const char *pchrPtrName=0);
	void Servidor(zSiscomConexion *pzSiscomConexion);
	void IniciaControl();
	QLineEdit *QLineEditProducto();
	void setFocus();
	void IdExpendio(const char *);
	zSiscomRegistro *MetodoPago(int pint);
	const char *MetodoPagoChar(int pint);
private:
	void IniciaVariables();
	void ConectaSlots();
	void Consultando();
	void ConsultaMetodoPagoSat();
	void MuestraMetodoPagoSat();
private:
	QComboBox *QCBMetodoPagoSat;
	QHBoxLayout *QHBLayout;
	QLineEdit *QLEProducto;
	zSiscomConexion *zSisConexion;
	zSiscomRegistros *zSisRegsMetodoPagoSat;
	const char *chrPtrIdExpendio;
private slots:
	void SlotSeleccionando(int);
	void SlotSelecciono(int);
signals:
	void SignalSeleccionando(zSiscomRegistro *);
	void SignalSelecciono(zSiscomRegistro *);

};

#endif

