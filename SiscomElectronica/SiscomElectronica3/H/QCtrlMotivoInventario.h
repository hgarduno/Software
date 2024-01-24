#ifndef __QCTRLMOTIVOINVENTARIO_H__
#define __QCTRLMOTIVOINVENTARIO_H__ 
#include <qwidget.h>
#include <qwidgetplugin.h>
#include <SiscomRegistros3.h>
class QHBoxLayout;
class QComboBox;
class QLineEdit;
class SiscomDatCom;
class SiscomRegistro3;
class QT_WIDGET_PLUGIN_EXPORT QCtrlMotivoInventario : public QWidget
{
    Q_OBJECT
public:
    QCtrlMotivoInventario( QWidget *parent = 0, const char *name = 0);
    void IniciaControl();
    void Servidor(SiscomDatCom *);
    void IdExpendio(const char *);
    void setFocus();
    void Limpia();
    SiscomRegistro3 *MotivoInventarioActual();
    
private:
	void IniciaVariables();
	void ConsultaMotivoInventario();
	void MuestraMotivoInventario();
	void ConectaSlots();
private:
	QHBoxLayout *QHBLayout;
	QComboBox *QCBMotivoInventario;
	QLineEdit *QLEMotivoInventario;
	SiscomDatCom *SisDatCom;
	SiscomRegistro3Lst SisReg3LstMotivoInventario;
	const char *chrPtrIdExpendio;
	int intMotivoInventario;
private slots:
	void SlotMotivoInventario(int );
signals:
	void SignalMotivoInventario(SiscomRegistro3 *);
};

#endif
