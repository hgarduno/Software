#include <QCtrlFechaHora.h>
#include <LibSISCOMComunControles.h>
#include <SISCOMComunicaciones++.h>

#include <qvariant.h>
#include <qlineedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qfile.h>
#include <qdatetime.h>
#include <qlineedit.h>
#include <qpushbutton.h>
#include <qfiledialog.h>
#include <qlayout.h>
QCtrlFechaHora::QCtrlFechaHora( QWidget* parent, const char* name,WFlags fl)
    : QWidget ( parent, name,fl),
	intNCAno(0),
	intNCMes(0),
	intNCDia(0)
{
	IniciaVariables();
	ConectaSlots();	
}

QCtrlFechaHora::~QCtrlFechaHora()
{
}
void QCtrlFechaHora::ConectaSlots()
{

	connect(QLEDia,
		SIGNAL(returnPressed()),
		SLOT(S_PasaFocoMes()));
	connect(QLEMes,
		SIGNAL(returnPressed()),
		SLOT(S_PasaFocoAno()));
	connect(QLEAno,
		SIGNAL(returnPressed()),
		SLOT(S_PasaFocoHora()));
	connect(QLEHora,
		SIGNAL(returnPressed()),
		SLOT(S_PasaFocoMinuto()));
	connect(QLEMinuto,
		SIGNAL(returnPressed()),
		SLOT(S_EnterMinuto()));
	connect(QLEAno,
		SIGNAL(textChanged(const QString &)),
		SLOT(S_CambioElA_o(const QString &)));
	connect(QLEDia,
		SIGNAL(textChanged(const QString &)),
		SLOT(S_CambioElDia(const QString &)));
	connect(QLEMes,
		SIGNAL(textChanged(const QString &)),
		SLOT(S_CambioElMes(const QString &)));

}
void QCtrlFechaHora::S_EnterMinuto()
{
emit Signal_EnterMinuto();
}
void QCtrlFechaHora::S_PasaFocoHora()
{
SiscomPasaFocoControl(QLEHora);
}
void QCtrlFechaHora::S_PasaFocoMinuto()
{
SiscomPasaFocoControl(QLEMinuto);
}
QLineEdit *QCtrlFechaHora::ColocaEditRegilla(const char *pchrPtrName,
					     int pintMinAncho,
					     int pintMinLargo,
					     int pintMaxAncho,
					     int pintMaxLargo)
{
QLineEdit *lQLEControl=new QLineEdit(this,pchrPtrName);
	lQLEControl->setMinimumSize(QSize(pintMinAncho,pintMinLargo));
	lQLEControl->setMaximumSize(QSize(pintMaxAncho,pintMaxLargo));
	QHBRegilla->addWidget(lQLEControl);
	return lQLEControl;
}
void QCtrlFechaHora::IniciaVariables()
{
	QHBRegilla=new QHBoxLayout(this);
	QLEDia=ColocaEditRegilla("QLEDia",30,0,30,1000);
	QLEMes=ColocaEditRegilla("QLEMes",30,0,30,1000);
	QLEAno=ColocaEditRegilla("QLEAno",40,0,60,1000);
	QLEHora=ColocaEditRegilla("QLEHora",30,0,30,1000);
	QLEMinuto=ColocaEditRegilla("QLEMinuto",30,0,30,1000);
	SiscomPasaFocoControl(QLEAno);
	QLEDia->setText("DD");
	QLEMes->setText("MM");
	QLEAno->setText("AAAA");
	QLEHora->setText("HH");
	QLEMinuto->setText("MM");

}
void QCtrlFechaHora::S_PasaFocoDia()
{
	
	SiscomPasaFocoControl(QLEDia);

}
void QCtrlFechaHora::S_PasaFocoAno()
{
	SiscomPasaFocoControl(QLEAno);
}
void QCtrlFechaHora::S_PasaFocoMes()
{
	SiscomPasaFocoControl(QLEMes);
}
void QCtrlFechaHora::S_CambioElA_o(const QString &pQSTexto)
{
	ValidaSoloNumerosYTamano(QLEAno,0,4,0,pQSTexto);
}
void QCtrlFechaHora::S_CambioElMes(const QString &pQSTexto)
{

	ValidaSoloNumerosYTamano(QLEMes,12,2,"MM",pQSTexto);
}
void QCtrlFechaHora::S_CambioElDia(const QString &pQSTexto)
{

	ValidaSoloNumerosYTamano(QLEDia,31,2,"DD",pQSTexto);
}
QString QCtrlFechaHora::ObtenA_o()
{
	return QLEAno->text();
}
QString QCtrlFechaHora::ObtenMes()
{
	return QLEMes->text();
}
QString QCtrlFechaHora::ObtenDia()
{
	return QLEDia->text();
}
QString QCtrlFechaHora::ObtenFechaHora()
{
	return QLEAno->text() 	+ 
		"-"           	+
	       QLEMes->text() 	+
	        "-"           	+
		QLEDia->text() 	+
		" "		+
		QLEHora->text() +
		":"		+
		QLEMinuto->text();
}
void QCtrlFechaHora::ColocaFechaHoy()
{
QDateTime lQDTime=QDateTime::currentDateTime();

	QLEAno->setText(QString().sprintf("%04d",lQDTime.date().year()));
	QLEMes->setText(QString().sprintf("%02d",lQDTime.date().month()));
	QLEDia->setText(QString().sprintf("%02d",lQDTime.date().day()));
	QLEHora->setText(QString().sprintf("%02d",lQDTime.time().hour()));
	QLEMinuto->setText(QString().sprintf("%02d",lQDTime.time().minute()));
}
void QCtrlFechaHora::ObtenDatoFecha(const char *pchrPtrFecha,
				    int pintNCaracteres,
				    char *pchrPtrDato)
{
	strncpy(pchrPtrDato,pchrPtrFecha,pintNCaracteres);
	pchrPtrDato[pintNCaracteres]=0;
}
void QCtrlFechaHora::setFocus()
{
	SiscomPasaFocoControl(QLEDia);
}


void QCtrlFechaHora::PonFecha(const char *pchrPtrFecha)
{
char lchrArrAno[5];
char lchrArrMes[3];
char lchrArrDia[3];
	ObtenDatoFecha(pchrPtrFecha,4,lchrArrAno);
	ObtenDatoFecha(pchrPtrFecha+5,2,lchrArrMes);
	ObtenDatoFecha(pchrPtrFecha+8,2,lchrArrDia);
	QLEAno->setText(lchrArrAno);
	QLEMes->setText(lchrArrMes);
	QLEDia->setText(lchrArrDia);
}
