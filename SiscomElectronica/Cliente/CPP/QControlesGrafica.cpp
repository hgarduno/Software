#include <QControlesGrafica.h>
#include <qcombobox.h>
#include <qpushbutton.h>
#include <qtextedit.h>
#include <qlayout.h>
QControlesGrafica::QControlesGrafica(QWidget *pQWParent,const char *pchrPtrName):
		QWidget(pQWParent,pchrPtrName)
{

	IniciaVariables();

}
void QControlesGrafica::IniciaVariables()
{
	QVBControles=new QVBoxLayout(this);
	QCBFechas=new QComboBox(this,"QCBFecha");
	QVBControles->addWidget(QCBFechas);


	QPBUno=new QPushButton("Control Uno",this,"QPBUno");
	QPBDos=new QPushButton("Control Dos",this,"QPBDos");
	QTEOtro=new QTextEdit(this,"QTEOtro");
	QVBControles->addWidget(QPBDos);
	QVBControles->addWidget(QPBUno);
	QVBControles->addWidget(QTEOtro);
}
