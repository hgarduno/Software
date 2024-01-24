#ifndef __QCTRLALUMNOS_H__
#define __QCTRLALUMNOS_H__ 
#include <qwidget.h>
#include <qwidgetplugin.h>
#include <SiscomRegistros3.h>
class QHBoxLayout;
class QComboBox;
class QLineEdit;
class SiscomDatCom;
class SiscomRegistro3;
class QT_WIDGET_PLUGIN_EXPORT  QCtrlAlumnos : public QWidget
{
    Q_OBJECT
public:
    QCtrlAlumnos( QWidget *parent = 0, const char *name = 0);
    void IniciaControl();
    void Servidor(SiscomDatCom *);
    void IdExpendio(const char *);
    void setFocus();
    void Limpia();
    SiscomRegistro3 *AlumnoActual();
    
private:
	void IniciaVariables();
	void ConsultaAlumnos();
	void MuestraAlumnos();
	void ConectaSlots();

	void keyPressEvent(QKeyEvent *);
private:
	QHBoxLayout *QHBLayout;
	QComboBox *QCBAlumnos;
	QLineEdit *QLEAlumnos;
	SiscomDatCom *SisDatCom;
	SiscomRegistro3Lst SisReg3LstAlumnos;
	const char *chrPtrIdExpendio;
	int intAlumno;
private slots:
	void SlotAlumno(int );
signals:
	void SignalAlumno(SiscomRegistro3 *);
};

#endif
