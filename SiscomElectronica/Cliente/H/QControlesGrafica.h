#ifndef __QCONTROLESGRAFICA_H__
#define __QCONTROLESGRAFICA_H__
#include <qwidget.h>
class QVBoxLayout;
class QPushButton;
class QComboBox;
class QTextEdit;
class QControlesGrafica:public QWidget 
{
Q_OBJECT
public:
	QControlesGrafica(QWidget *,const char *);
private:
	QVBoxLayout *QVBControles;
	QComboBox *QCBFechas;
	QPushButton *QPBUno;
	QPushButton *QPBDos;
	QTextEdit *QTEOtro;
private:
	void IniciaVariables();
};

#endif
