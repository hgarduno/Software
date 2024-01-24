#ifndef __QCTRLUSOCFDISAT_H__
#define __QCTRLUSOCFDISAT_H__
#include <qwidget.h>
#include <qwidgetplugin.h>
#include <SiscomRegistros3.h>

class QHBoxLayout;
class QComboBox;
class QLineEdit;
class zSiscomConexion;
class zSiscomRegistros;
class zSiscomRegistro;

class QT_WIDGET_PLUGIN_EXPORT QCtrlUsoCFDISat:public QWidget 
{
Q_OBJECT
public:
	QCtrlUsoCFDISat(QWidget *pQWParent=0,const char *pchrPtrName=0);
	void Servidor(zSiscomConexion *pzSiscomConexion);
	void IniciaControl();
	QLineEdit *QLineEditProducto();
	void setFocus();
	void IdExpendio(const char *);
	zSiscomRegistro *UsoFactura(int pintNUsoFactura);
	const char *UsoFacturaChar(int pintNUsoFactura);
private:
	void IniciaVariables();
	void ConectaSlots();
	void Consultando();
	void ConsultaUsoCFDISat();
	void MuestraUsoCFDISat();
private:
	QComboBox *QCBUsoCFDISat;
	QHBoxLayout *QHBLayout;
	QLineEdit *QLEProducto;
	zSiscomConexion *zSisConexion;
	zSiscomRegistros *zSisRegsUsoCFDISat;
	const char *chrPtrIdExpendio;
private slots:
	void SlotSeleccionando(int);
	void SlotSelecciono(int);
signals:
	void SignalSeleccionando(zSiscomRegistro *);
	void SignalSelecciono(zSiscomRegistro *);

};

#endif

