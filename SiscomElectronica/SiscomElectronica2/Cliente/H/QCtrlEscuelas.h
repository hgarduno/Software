#ifndef __QCTRLESCUELAS_H__
#define __QCTRLESCUELAS_H__ 
#include <qwidget.h>
#include <qwidgetplugin.h>
#include <SiscomRegistros3.h>
class QHBoxLayout;
class QComboBox;
class QLineEdit;
class SiscomDatCom;
class SiscomRegistro3;
class QT_WIDGET_PLUGIN_EXPORT QCtrlEscuelas : public QWidget
{
    Q_OBJECT
public:
    QCtrlEscuelas( QWidget *parent = 0, const char *name = 0);
    void IniciaControl();
    void PonServidor(SiscomDatCom *);
    void IdExpendio(const char *);
    void setFocus();
    void Limpia();
    void Escuela(const char *);
    SiscomRegistro3 *EscuelaActual();
    
private:
	void IniciaVariables();
	void ConsultaEscuelas();
	void MuestraEscuelas();
	void ConectaSlots();
private:
	QHBoxLayout *QHBLayout;
	QComboBox *QCBEscuelas;
	QLineEdit *QLEEscuelas;
	SiscomDatCom *SisDatCom;
	SiscomRegistro3Lst SisReg3LstEscuelas;
	const char *chrPtrIdExpendio;
	int intEscuela;
private slots:
	void SlotEscuela(int );
signals:
	void SignalEscuelas(SiscomRegistro3 *);
};

#endif
