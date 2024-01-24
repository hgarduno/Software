#ifndef __QCTRLFECHASCURSOS_H__
#define __QCTRLFECHASCURSOS_H__ 
#include <qwidget.h>
#include <qwidgetplugin.h>
#include <SiscomRegistros3.h>
class QHBoxLayout;
class QComboBox;
class QLineEdit;
class SiscomDatCom;
class SiscomRegistro3;
class QT_WIDGET_PLUGIN_EXPORT QCtrlFechasCursos : public QWidget
{
    Q_OBJECT
public:
    QCtrlFechasCursos( QWidget *parent = 0, const char *name = 0);
    void IniciaControl();
    void Servidor(SiscomDatCom *);
    void IdCurso(const char *);
    void setFocus();
    void Limpia();
    SiscomRegistro3 *FechaCursoActual();
    
private:
	void IniciaVariables();
	void ConsultaFechasCursos();
	void MuestraFechasCursos();
	void ConectaSlots();

	void keyPressEvent(QKeyEvent *);
private:
	QHBoxLayout *QHBLayout;
	QComboBox *QCBFechasCursos;
	QLineEdit *QLEFechasCursos;
	SiscomDatCom *SisDatCom;
	SiscomRegistro3Lst SisReg3LstFechasCursos;
	const char *chrPtrIdCurso;
	const char *chrPtrIdExpendio;
	int intFechaCurso;
private slots:
	void SlotFechaCurso(int );
signals:
	void SignalFechaCurso(SiscomRegistro3 *);
};

#endif
