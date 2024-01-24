#ifndef __QSISEXPEDIENTE_H__
#define __QSISEXPEDIENTE_H__
#include <SISCOMComunicaciones++.h>

class QLineEdit;
class QTextEdit;
class QLabel;
class QPushButton;

class CQSisExpediente;
class QSisExpediente:public QWidget
{
Q_OBJECT
public:
	QSisExpediente(QWidget *pQWParent=0,
		       const char *pchrPtrName=0,
		       WFlags pWFlags=0);
	void Expediente(CQSisExpediente *);
	void Informacion();
private:
	QGridLayout *QGLRegilla;
	QLabel *QLMedico;
	QLabel *QLObservaciones;
	QLineEdit *QLEMedico;
	QTextEdit *QTEObservaciones;
	QPushButton *QPBRecetas;
	CQSisExpediente *CQSExpediente;
private:
	void IniciaVariables();
	QPushButton *Boton(const char *,const char *);
	QLabel *Etiqueta(const char *,const char *);
	QLineEdit *LineEdit(const char *,bool);
	QTextEdit *TextEdit(const char *,bool);
};


#endif
