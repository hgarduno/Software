#ifndef __QCTRLGASTOSSE_H__
#define __QCTRLGASTOSSE_H__
#include <qwidget.h>
#include <qwidgetplugin.h>
#include <SiscomRegistros3.h>

class QHBoxLayout;
class QComboBox;
class QLineEdit;
class zSiscomConexion;
class zSiscomRegistros;
class zSiscomRegistro;

class QT_WIDGET_PLUGIN_EXPORT QCtrlGastosSE:public QWidget 
{
Q_OBJECT
public:
	QCtrlGastosSE(QWidget *pQWParent=0,const char *pchrPtrName=0);
	void Servidor(zSiscomConexion *pzSiscomConexion);
	void IniciaControl();
	QLineEdit *QLineEditProducto();
	void setFocus();
	void IdExpendio(const char *);
private:
	void IniciaVariables();
	void ConectaSlots();
	void Consultando();
	void ConsultaGastos();
	void MuestraGastos();
private:
	QComboBox *QCBGastos;
	QHBoxLayout *QHBLayout;
	QLineEdit *QLEProducto;
	zSiscomConexion *zSisConexion;
	zSiscomRegistros *zSisRegsGastos;
	const char *chrPtrIdExpendio;
private slots:
	void SlotSeleccionando(int);
	void SlotSelecciono(int);
signals:
	void SignalSeleccionando(zSiscomRegistro *);
	void SignalSelecciono(zSiscomRegistro *);

};

#endif

