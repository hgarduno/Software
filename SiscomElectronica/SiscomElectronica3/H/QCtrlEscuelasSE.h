#ifndef __QCTRLESCUELASSE_H__
#define __QCTRLESCUELASSE_H__
#include <qwidget.h>
#include <qwidgetplugin.h>
#include <SiscomRegistros3.h>

class QHBoxLayout;
class QComboBox;
class QLineEdit;
class zSiscomConexion;
class zSiscomRegistros;
class zSiscomRegistro;

class QT_WIDGET_PLUGIN_EXPORT QCtrlEscuelasSE:public QWidget 
{
Q_OBJECT
public:
	QCtrlEscuelasSE(QWidget *pQWParent=0,const char *pchrPtrName=0);
	void Servidor(zSiscomConexion *pzSiscomConexion);
	void IniciaControl();
	QLineEdit *QLineEditProducto();
	void setFocus();
	void setReadOnly(bool );
	void IdExpendio(const char *);
private:
	void IniciaVariables();
	void ConectaSlots();
	void Consultando();
	void ConsultaEscuelas();
	void MuestraEscuelas();
private:
	QComboBox *QCBEscuelas;
	QHBoxLayout *QHBLayout;
	QLineEdit *QLEProducto;
	zSiscomConexion *zSisConexion;
	zSiscomRegistros *zSisRegsEscuelas;
	const char *chrPtrIdExpendio;
private slots:
	void SlotSeleccionando(int);
	void SlotSelecciono(int);
signals:
	void SignalSeleccionando(zSiscomRegistro *);
	void SignalSelecciono(zSiscomRegistro *);

};

#endif

