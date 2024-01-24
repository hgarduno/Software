#include <QCtrlRangoHora.h>
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
QCtrlRangoHora::QCtrlRangoHora( QWidget* parent, const char* name,WFlags fl)
    : QWidget ( parent, name,fl)
{
	IniciaVariables();
	ConectaSlots();	
}

QCtrlRangoHora::~QCtrlRangoHora()
{
}
void QCtrlRangoHora::ConectaSlots()
{
connect(QLEHora,
	SIGNAL(returnPressed()),
	SLOT(S_PasaFocoMinuto()));
connect(QLEMinuto,
	SIGNAL(returnPressed()),
	SLOT(S_PasaFocoHoraFin()));
connect(QLEHoraFin,
	SIGNAL(returnPressed()),
	SLOT(S_PasaFocoMinutoFin()));
connect(QLEMinutoFin,
	SIGNAL(returnPressed()),
	SLOT(S_CapturoRangoHora()));

}
void QCtrlRangoHora::S_CapturoRangoHora()
{
char lchrArrHoraFin[6],
     lchrArrHoraInicio[6];
sprintf(lchrArrHoraInicio,
	"%s:%s",
	(const char *)QLEHora->text(),
	(const char *)QLEMinuto->text());

sprintf(lchrArrHoraFin,
	"%s:%s",
	(const char *)QLEHoraFin->text(),
	(const char *)QLEMinutoFin->text());

 emit SignalCapturoRangoHora(lchrArrHoraInicio,
 			     lchrArrHoraFin);
}
QLineEdit *QCtrlRangoHora::ColocaEditRegilla(const char *pchrPtrName,
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
void QCtrlRangoHora::IniciaVariables()
{
	QHBRegilla=new QHBoxLayout(this);
	QLEHora=ColocaEditRegilla("QLEHora",30,0,30,1000);
	QLEMinuto=ColocaEditRegilla("QLMinuto",30,0,30,1000);

	QLEHoraFin=ColocaEditRegilla("QLEHoraFin",30,0,30,1000);
	QLEMinutoFin=ColocaEditRegilla("QLEMinutoFin",30,0,30,1000);
	SiscomPasaFocoControl(QLEHora);
	QLEHora->setText("HH");
	QLEMinuto->setText("MM");
	QLEHoraFin->setText("HH");
	QLEMinutoFin->setText("MM");

}
void QCtrlRangoHora::S_PasaFocoMinuto()
{
	
	SiscomPasaFocoControl(QLEMinuto);

}
void QCtrlRangoHora::S_PasaFocoHoraFin()
{
	SiscomPasaFocoControl(QLEHoraFin);
}
void QCtrlRangoHora::S_PasaFocoMinutoFin()
{
	SiscomPasaFocoControl(QLEMinutoFin);
}
void QCtrlRangoHora::setFocus()
{
	SiscomPasaFocoControl(QLEHora);
}
