#ifndef __QCTRLCUENTADINERO_H__
#define __QCTRLCUENTADINERO_H__
#include <qwidget.h>
#include <qwidgetplugin.h>
#include <qtable.h>
#include <SiscomRegistros3.h>

class QHBoxLayout;
class QTable;
class zSiscomConexion;
class zSiscomRegistros;
class zSiscomRegistro;

class QT_WIDGET_PLUGIN_EXPORT QCtrlCuentaDinero:public QWidget 
{
Q_OBJECT
public:
	QCtrlCuentaDinero(QWidget *pQWParent=0,const char *pchrPtrName=0);
	void Servidor(zSiscomConexion *pzSiscomConexion);
	void IniciaControl();
	void setFocus();
private:
	void IniciaVariables();
	void ConectaSlots();
private:
	QHBoxLayout *QHBLayout;
	zSiscomConexion *zSisConexion;
	zSiscomRegistros *zSisRegsGastos;
	QTable *QTCuDinero;
private slots:
signals:

};

#endif

