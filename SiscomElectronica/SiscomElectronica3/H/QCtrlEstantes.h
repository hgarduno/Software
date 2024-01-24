#ifndef __QCTRLESTANTES_H__
#define __QCTRLESTANTES_H__
#include <qwidget.h>
#include <qwidgetplugin.h>
#include <SiscomRegistros3.h>

class QHBoxLayout;
class QComboBox;
class QLineEdit;
class zSiscomConexion;
class zSiscomRegistros;
class zSiscomRegistro;

class QT_WIDGET_PLUGIN_EXPORT QCtrlEstantes:public QWidget 
{
Q_OBJECT
public:
	QCtrlEstantes(QWidget *pQWParent=0,const char *pchrPtrName=0);
	void Servidor(zSiscomConexion *pzSiscomConexion);
	void IniciaControl();
	QLineEdit *RFC();
	void setFocus();
	void IdEscuela(const char *);
	void ReConsultando();
private:
	void IniciaVariables();
	void ConectaSlots();
	void Consultando();
	void ConsultaEstantes();
	void MuestraEstantes();
private:
	QComboBox *QCBEstantes;
	QHBoxLayout *QHBLayout;
	QLineEdit *QLERFC;
	zSiscomConexion *zSisConexion;
	zSiscomRegistros *zSisRegsEstantes;
	const char *chrPtrIdEscuela;
private slots:
	void SlotSeleccionando(int);
	void SlotSelecciono(int);
	void SlotSeleccionoRFC();

	void SlotCambioRFC(const QString &);
	void SlotCapturoRfc();
signals:
	void SignalSeleccionando(zSiscomRegistro *);
	void SignalSelecciono(zSiscomRegistro *);

};

#endif

