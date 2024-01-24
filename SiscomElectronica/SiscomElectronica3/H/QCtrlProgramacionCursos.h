#ifndef __QCTRLPROGRAMACIONCURSOS_H__
#define __QCTRLPROGRAMACIONCURSOS_H__ 
#include <qwidget.h>
#include <qwidgetplugin.h>
#include <SiscomRegistros3.h>
class QHBoxLayout;
class QComboBox;
class QLineEdit;
class SiscomDatCom;
class SiscomRegistro3;
class QT_WIDGET_PLUGIN_EXPORT QCtrlProgramacionCursos : public QWidget
{
    Q_OBJECT
public:
    QCtrlProgramacionCursos( QWidget *parent = 0, const char *name = 0);
    void IniciaControl();
    void Servidor(SiscomDatCom *);
    void setFocus();
    void Limpia();
    SiscomRegistro3 *ProgramacionCursoActual();
    
private:
	void IniciaVariables();
	void ConsultaProgramacionCursos();
	void MuestraProgramacionCursos();
	void ConectaSlots();

	void keyPressEvent(QKeyEvent *);
private:
	QHBoxLayout *QHBLayout;
	QComboBox *QCBProgramacionCursos;
	QLineEdit *QLEProgramacionCursos;
	SiscomDatCom *SisDatCom;
	SiscomRegistro3Lst SisReg3LstProgramacionCursos;
	const char *chrPtrIdExpendio;
	int intProgramacionCurso;
private slots:
	void SlotProgramacionCurso(int );
signals:
	void SignalProgramacionCurso(SiscomRegistro3 *);
};

#endif
