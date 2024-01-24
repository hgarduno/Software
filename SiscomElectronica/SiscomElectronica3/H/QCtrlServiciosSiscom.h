#ifndef __QCTRLSERVICIOSSISCOM_H__
#define __QCTRLSERVICIOSSISCOM_H__ 
#include <qwidget.h>
#include <qwidgetplugin.h>
#include <SiscomRegistros3.h>
class QHBoxLayout;
class QComboBox;
class QLineEdit;
class SiscomDatCom;
class SiscomRegistro3;
class QT_WIDGET_PLUGIN_EXPORT QCtrlServiciosSiscom : public QWidget
{
    Q_OBJECT
public:
    QCtrlServiciosSiscom( QWidget *parent = 0, const char *name = 0);
    void IniciaControl();
    void Servidor(SiscomDatCom *);
    void setFocus();
    void Limpia();
    SiscomRegistro3 *CursoActual();
    
private:
	void IniciaVariables();
	void ConsultaServicios();
	void MuestraServicios();
	void ConectaSlots();

	void keyPressEvent(QKeyEvent *);
private:
	QHBoxLayout *QHBLayout;
	QComboBox *QCBServicios;
	QLineEdit *QLEServicios;
	SiscomDatCom *SisDatCom;
	SiscomRegistro3Lst SisReg3LstServicios;
	const char *chrPtrIdExpendio;
	int intCurso;
private slots:
	void SlotCurso(int );
signals:
	void SignalServicio(SiscomRegistro3 *);
};

#endif
