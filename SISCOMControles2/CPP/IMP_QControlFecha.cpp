#include <IMP_QControlFecha.h>
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
FILE *gPtrFleArchivoLog;
CQControlFecha::CQControlFecha( QWidget* parent, const char* name,WFlags fl)
    : QWidget ( parent, name,fl),
	intNCAno(0),
	intNCMes(0),
	intNCDia(0)
{
	IniciaVariables();
	ConectaSlots();	
}

CQControlFecha::~CQControlFecha()
{
}
void CQControlFecha::ConectaSlots()
{

	connect(QLEDia,
		SIGNAL(returnPressed()),
		SLOT(S_PasaFocoMes()));
	connect(QLEMes,
		SIGNAL(returnPressed()),
		SLOT(S_PasaFocoAno()));
	connect(QLEAno,
		SIGNAL(returnPressed()),
		SLOT(S_IntrodujoA_o()));
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
QLineEdit *CQControlFecha::ColocaEditRegilla(const char *pchrPtrName,
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
void CQControlFecha::IniciaVariables()
{
	QHBRegilla=new QHBoxLayout(this);
	QLEDia=ColocaEditRegilla("QLEDia",30,0,30,1000);
	QLEMes=ColocaEditRegilla("QLEMes",30,0,30,1000);
	QLEAno=ColocaEditRegilla("QLEAno",40,0,60,1000);
	SiscomPasaFocoControl(QLEAno);
	QLEDia->setText("DD");
	QLEMes->setText("MM");
	QLEAno->setText("AAAA");

}
void CQControlFecha::S_PasaFocoDia()
{
	
	SiscomPasaFocoControl(QLEDia);

}
void CQControlFecha::S_PasaFocoAno()
{
	SiscomPasaFocoControl(QLEAno);
}
void CQControlFecha::S_PasaFocoMes()
{
	SiscomPasaFocoControl(QLEMes);
}
void CQControlFecha::S_IntrodujoA_o()
{
	emit Signal_EnterA_o();
}
void CQControlFecha::S_CambioElA_o(const QString &pQSTexto)
{
	ValidaSoloNumerosYTamano(QLEAno,0,4,0,pQSTexto);
}
void CQControlFecha::S_CambioElMes(const QString &pQSTexto)
{

	ValidaSoloNumerosYTamano(QLEMes,12,2,"MM",pQSTexto);
}
void CQControlFecha::S_CambioElDia(const QString &pQSTexto)
{

	ValidaSoloNumerosYTamano(QLEDia,31,2,"DD",pQSTexto);
}
QString CQControlFecha::ObtenA_o()
{
	return QLEAno->text();
}
QString CQControlFecha::ObtenMes()
{
	return QLEMes->text();
}
QString CQControlFecha::ObtenDia()
{
	return QLEDia->text();
}
QString CQControlFecha::ObtenFecha()
{
	return QLEAno->text() + 
		"-"           +
	       QLEMes->text() +
	        "-"           +
		QLEDia->text();
}
void CQControlFecha::AAAAMMDD(char *pchrPtrFecha)
{
sprintf(pchrPtrFecha,
	"%04d-%02d-%02d",
	intNCAno,
	intNCMes,
	intNCDia);
}
void CQControlFecha::ColocaFechaHoy()
{
QDate lQDFHoy=QDate::currentDate();

	QLEAno->setText(QString().sprintf("%04d",lQDFHoy.year()));
	QLEMes->setText(QString().sprintf("%02d",lQDFHoy.month()));
	QLEDia->setText(QString().sprintf("%02d",lQDFHoy.day()));
}
void CQControlFecha::ObtenDatoFecha(const char *pchrPtrFecha,
				    int pintNCaracteres,
				    char *pchrPtrDato)
{
	strncpy(pchrPtrDato,pchrPtrFecha,pintNCaracteres);
	pchrPtrDato[pintNCaracteres]=0;
}
void CQControlFecha::setFocus()
{
	SiscomPasaFocoControl(QLEDia);
}


void CQControlFecha::PonFecha(const char *pchrPtrFecha)
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
