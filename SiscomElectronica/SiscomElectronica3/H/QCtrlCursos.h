#ifndef __QCTRLCURSOS_H__
#define __QCTRLCURSOS_H__ 
#include <qwidget.h>
#include <qwidgetplugin.h>
#include <SiscomRegistros3.h>
class QHBoxLayout;
class QComboBox;
class QLineEdit;
class SiscomDatCom;
class SiscomRegistro3;
class QT_WIDGET_PLUGIN_EXPORT QCtrlCursos : public QWidget
{
    Q_OBJECT
public:
    QCtrlCursos( QWidget *parent = 0, const char *name = 0);
    void IniciaControl();
    void Servidor(SiscomDatCom *);
    void setFocus();
    void Limpia();
    SiscomRegistro3 *CursoActual();
    
private:
	void IniciaVariables();
	void ConsultaCursos();
	void MuestraCursos();
	void ConectaSlots();

	void keyPressEvent(QKeyEvent *);
private:
	QHBoxLayout *QHBLayout;
	QComboBox *QCBCursos;
	QLineEdit *QLECursos;
	SiscomDatCom *SisDatCom;
	SiscomRegistro3Lst SisReg3LstCursos;
	const char *chrPtrIdExpendio;
	int intCurso;
private slots:
	void SlotCurso(int );
signals:
	void SignalCurso(SiscomRegistro3 *);
};

#endif
