#ifndef __QCTRLFORMAPAGO3QT_H__
#define __QCTRLFORMAPAGO3QT_H__ 
#include <qwidget.h>
#include <qwidgetplugin.h>
#include <SiscomRegistros3.h>
class QHBoxLayout;
class QComboBox;
class QLineEdit;
class SiscomDatCom;

class QT_WIDGET_PLUGIN_EXPORT QCtrlFormaPago3Qt : public QWidget
{
    Q_OBJECT
public:
    QCtrlFormaPago3Qt( QWidget *parent = 0, const char *name = 0);
    void IniciaControl();
    void Servidor(SiscomDatCom *);
    void setFocus();
    void Limpia();
	SiscomRegistro3 *PrimerFormaPago();
    
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
	SiscomRegistro3Lst SReg3LstFormaPago;
private slots:
	void SlotFormaPago(int );
signals:
	void SignalFormaPago(SiscomRegistro3 *);
};

#endif
