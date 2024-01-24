#ifndef __QCTRLEXPLICACIONPROMOCION_H__
#define __QCTRLEXPLICACIONPROMOCION_H__ 
#include <qwidget.h>
#include <qwidgetplugin.h>
#include <SiscomRegistros3.h>
class QHBoxLayout;
class QComboBox;
class QLineEdit;
class SiscomDatCom;
class SiscomRegistro3;
class QT_WIDGET_PLUGIN_EXPORT QCtrlExplicacionPromocion : public QWidget
{
    Q_OBJECT
public:
    QCtrlExplicacionPromocion( QWidget *parent = 0, const char *name = 0);
    void IniciaControl();
    void Servidor(SiscomDatCom *);
    void setFocus();
    void Limpia();
    SiscomRegistro3 *ExplicacionPromocionActual();
    
private:
	void IniciaVariables();
	void ConsultaExplicacionPromocion();
	void MuestraExplicacionPromocion();
	void ConectaSlots();

	void keyPressEvent(QKeyEvent *);
private:
	QHBoxLayout *QHBLayout;
	QComboBox *QCBExplicacionPromocion;
	QLineEdit *QLEExplicacionPromocion;
	SiscomDatCom *SisDatCom;
	SiscomRegistro3Lst SisReg3LstExplicacionPromocion;
	const char *chrPtrIdExpendio;
	int intExplicacionPromocion;
private slots:
	void SlotExplicacionPromocion(int );
signals:
	void SignalExplicacionPromocion(SiscomRegistro3 *);
};

#endif
