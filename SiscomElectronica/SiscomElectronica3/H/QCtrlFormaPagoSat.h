#ifndef __QCTRLFORMAPAGOSAT_H__
#define __QCTRLFORMAPAGOSAT_H__
#include <qwidget.h>
#include <qwidgetplugin.h>
#include <SiscomRegistros3.h>

class QHBoxLayout;
class QComboBox;
class QLineEdit;
class zSiscomConexion;
class zSiscomRegistros;
class zSiscomRegistro;

class QT_WIDGET_PLUGIN_EXPORT QCtrlFormaPagoSat:public QWidget 
{
Q_OBJECT
public:
	QCtrlFormaPagoSat(QWidget *pQWParent=0,const char *pchrPtrName=0);
	void Servidor(zSiscomConexion *pzSiscomConexion);
	void IniciaControl();
	QLineEdit *QLineEditProducto();
	void setFocus();
	void IdExpendio(const char *);
	zSiscomRegistro *FormaPago(int);
	const char *FormaPagoChar(int);
private:
	void IniciaVariables();
	void ConectaSlots();
	void Consultando();
	void ConsultaFormasPagoSat();
	void MuestraFormasPagoSat();
private:
	QComboBox *QCBFormasPagoSat;
	QHBoxLayout *QHBLayout;
	QLineEdit *QLEProducto;
	zSiscomConexion *zSisConexion;
	zSiscomRegistros *zSisRegsFormasPagoSat;
	const char *chrPtrIdExpendio;
private slots:
	void SlotSeleccionando(int);
	void SlotSelecciono(int);
signals:
	void SignalSeleccionando(zSiscomRegistro *);
	void SignalSelecciono(zSiscomRegistro *);

};

#endif

