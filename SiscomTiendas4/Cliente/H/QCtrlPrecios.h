#ifndef __QCTRLPRECIOS_H__
#define __QCTRLPRECIOS_H__ 
#include <qwidget.h>
#include <qwidgetplugin.h>
#include <CQSisPrecios.h>
class QHBoxLayout;
class QComboBox;
class QLineEdit;
class CQSisPrecio;
class SiscomDatCom;

class QT_WIDGET_PLUGIN_EXPORT QCtrlPrecios : public QWidget
{
    Q_OBJECT
public:
    QCtrlPrecios( QWidget *parent = 0, const char *name = 0);
    ~QCtrlPrecios();
    void IniciaControl();
    void PonServidor(SiscomDatCom *);
    void setFocus();
    void Limpia();
    CQSisLstPrecio &Precios();
    
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
	CQSisLstPrecio CQSLPrecio;
private slots:
	void SlotPrecio(int);
signals:
	void SignalPrecio(CQSisPrecio *);
};

#endif
