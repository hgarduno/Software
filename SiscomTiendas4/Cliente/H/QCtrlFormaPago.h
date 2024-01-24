#ifndef __QCTRLFORMAPAGO_H__
#define __QCTRLFORMAPAGO_H__ 
#include <qwidget.h>
#include <qwidgetplugin.h>
#include <CQSisFormaPago.h>

class QHBoxLayout;
class QComboBox;
class QLineEdit;
class CQSisFormaPago;
class SiscomDatCom;

class QT_WIDGET_PLUGIN_EXPORT QCtrlFormaPago : public QWidget
{
    Q_OBJECT
public:
    QCtrlFormaPago( QWidget *parent = 0, const char *name = 0);
    void IniciaControl();
    void PonServidor(SiscomDatCom *);
    void setFocus();
    void Limpia();
    
private:
	void IniciaVariables();
	void ConsultaFormaPago();
	void MuestraFormaPago();
	void ConectaSlots();
	void SeleccionoFormaPago(int );
private:
	QHBoxLayout *QHBLayout;
	QComboBox *QCBFormaPago;
	QLineEdit *QLEFormaPago;
	SiscomDatCom *SisDatCom;
	CQSisLstFormaPago CQSLFormaPago;
private slots:
	void SlotProducto(int );
signals:
	void SignalFormaPago(CQSisFormaPago *);
};

#endif
