#ifndef __QCTRLCLIENTESMAYOREO_H__
#define __QCTRLCLIENTESMAYOREO_H__
#include <qwidget.h>
#include <qwidgetplugin.h>
#include <SiscomRegistros3.h>

class QHBoxLayout;
class QComboBox;
class QLineEdit;
class zSiscomConexion;
class zSiscomRegistros;
class zSiscomRegistro;

class QT_WIDGET_PLUGIN_EXPORT QCtrlClientesMayoreo:public QWidget 
{
Q_OBJECT
public:
	QCtrlClientesMayoreo(QWidget *pQWParent=0,const char *pchrPtrName=0);
	void Servidor(zSiscomConexion *pzSiscomConexion);
	void IniciaControl();
	QLineEdit *QLineEditProducto();
	void setFocus();
	void IdExpendio(const char *);
private:
	void IniciaVariables();
	void ConectaSlots();
	void Consultando();
	void ConsultaClientesMayoreo();
	void MuestraClientesMayoreo();
private:
	QComboBox *QCBClientesMayoreo;
	QHBoxLayout *QHBLayout;
	QLineEdit *QLEProducto;
	zSiscomConexion *zSisConexion;
	zSiscomRegistros *zSisRegsClientesMayoreo;
	const char *chrPtrIdExpendio;
private slots:
	void SlotSeleccionando(int);
	void SlotSelecciono(int);
signals:
	void SignalSeleccionando(zSiscomRegistro *);
	void SignalSelecciono(zSiscomRegistro *);

};

#endif

