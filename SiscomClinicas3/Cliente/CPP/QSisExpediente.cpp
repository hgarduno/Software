#include <QSisExpediente.h>
#include <CQSisExpedientes.h>
#include <CQSisObjetos.h>

#include <qlabel.h>
#include <qpushbutton.h>
#include <qtextedit.h>
#include <qlineedit.h>
#include <qlayout.h>

QSisExpediente::QSisExpediente(QWidget *pQWParent,
				const char *pchrPtrName,
				WFlags pWFlags):
			QWidget(pQWParent,pchrPtrName,pWFlags)
{

	IniciaVariables();

}


void QSisExpediente::IniciaVariables()
{
QGLRegilla=new QGridLayout(this,5,1,1,2,"QGLRegilla");
QLMedico=Etiqueta("Medico Responsable","QLEMedico");
QLObservaciones=Etiqueta("Observaciones","QLObservaciones");
QLEMedico=LineEdit("QLEMedico",true);
QTEObservaciones=TextEdit("QTEObservaciones",true);
QPBRecetas=Boton("Recetas","QPBRecetas");

QGLRegilla->addWidget(QLMedico,0,0);
QGLRegilla->addWidget(QLEMedico,1,0);
QGLRegilla->addWidget(QLObservaciones,2,0);
QGLRegilla->addWidget(QTEObservaciones,3,0);
QGLRegilla->addWidget(QPBRecetas,4,0);
}

QPushButton *QSisExpediente::Boton(const char *pchrPtrTexto, const char
*pchrPtrName) 
{ 
QPushButton *lQPBBoton;
	
	lQPBBoton=new QPushButton(pchrPtrTexto, this, pchrPtrName);
	lQPBBoton->setSizePolicy(QSizePolicy(QSizePolicy::Fixed,
				 QSizePolicy::Minimum));
	lQPBBoton->setAutoDefault(false);
	lQPBBoton->setSizePolicy(QSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed));

	return lQPBBoton;
}
QLabel *QSisExpediente::Etiqueta(const char *pchrPtrTexto,
				 const char *pchrPtrName)
{
QLabel *lQLEtiqueta;
	lQLEtiqueta=new QLabel(this,pchrPtrName);
	lQLEtiqueta->setSizePolicy(QSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed));
	lQLEtiqueta->setText(pchrPtrTexto);
	return lQLEtiqueta;
}
QLineEdit *QSisExpediente::LineEdit(const char *pchrPtrName,
				    bool pbSLectura)
{
QLineEdit *lQLEEdit=new QLineEdit(this,pchrPtrName);
lQLEEdit->setReadOnly(pbSLectura);
return lQLEEdit;
}
QTextEdit *QSisExpediente::TextEdit(const char *pchrPtrName,
				    bool pbSLectura)
{
QTextEdit *lQTEdit=new QTextEdit(this,pchrPtrName);
lQTEdit->setReadOnly(pbSLectura);
return lQTEdit;
}


void QSisExpediente::Expediente(CQSisExpediente *pCQSExpediente)
{
	CQSExpediente=pCQSExpediente;
}
void QSisExpediente::Informacion()
{
char lchrArrMedico[128];
	QTEObservaciones->setText((*CQSExpediente)["Observaciones"]);
	CQSisObjetos::NombreCompleto(CQSExpediente->Medico(),lchrArrMedico);
	QLEMedico->setText(lchrArrMedico);
}
