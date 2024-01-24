#ifndef __QCTRLCMBBODEGAS4_H__
#define __QCTRLCMBBODEGAS4_H__
#include <qwidget.h>
#include <qwidgetplugin.h>
#include <SiscomRegistros3.h>

class QHBoxLayout;
class QComboBox;
class QLineEdit;
class zSiscomConexion;
class zSiscomRegistros;
class zSiscomRegistro;
class zBodegas;
class zBodega;

class QT_WIDGET_PLUGIN_EXPORT QCtrlCmbBodegas4:public QWidget 
{
Q_OBJECT
public:
	QCtrlCmbBodegas4(QWidget *pQWParent=0,const char *pchrPtrName=0);
	void Servidor(zSiscomConexion *pzSiscomConexion);
	void IniciaControl();
	QLineEdit *QLineEditProducto();
	void setFocus();
	void IdExpendio(const char *);
	zBodega *Bodega(int);
private:
	void IniciaVariables();
	void ConectaSlots();
	void Consultando();
	void ConsultaBodegas4();
	void MuestraBodegas4();
private:
	QComboBox *QCBBodegas4;
	QHBoxLayout *QHBLayout;
	QLineEdit *QLEProducto;
	zSiscomConexion *zSisConexion;
	const char *chrPtrIdExpendio;
	 zBodegas *zBodegasE;
private slots:
	void SlotSeleccionando(int);
	void SlotSelecciono(int);
signals:
	void SignalSeleccionando(zBodega *);
	void SignalSelecciono(zBodega *);
};

#endif

