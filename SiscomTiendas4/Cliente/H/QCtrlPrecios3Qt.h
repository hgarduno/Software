
#ifndef __QCTRLPRECIOS3QT_H__
#define __QCTRLPRECIOS3QT_H__ 
#include <qwidget.h>
#include <qwidgetplugin.h>
#include <SiscomRegistros3.h>
class QHBoxLayout;
class QComboBox;
class QLineEdit;
class SiscomDatCom;

class QT_WIDGET_PLUGIN_EXPORT QCtrlPrecios3Qt : public QWidget
{
    Q_OBJECT
public:
    QCtrlPrecios3Qt( QWidget *parent = 0, const char *name = 0);
    ~QCtrlPrecios3Qt();
    SiscomRegistro3Lst &Precios();
    void IniciaControl();
    void Servidor(SiscomDatCom *);
    void setFocus();
    void Limpia();
    SiscomRegistro3 *PrimerPrecio();
    
private:
	void IniciaVariables();
	void ConsultaPrecios();
	void MuestraPrecios();
	void ConectaSlots();
	void SeleccionoPrecio(int );
private:
	QHBoxLayout *QHBLayout;
	QComboBox *QCBPrecios;
	QLineEdit *QLEPrecios;
	SiscomDatCom *SisDatCom;
	SiscomRegistro3Lst SReg3LstPrecios;
private slots:
	void SlotPrecio(int);
signals:
	void SignalPrecio(SiscomRegistro3 *);
};

#endif
