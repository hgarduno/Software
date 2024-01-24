#include <IMP_NotTransmision.h>

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qlcdnumber.h>
#include <qtextedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

QNotTransmision::QNotTransmision( QWidget* parent, const char* name, bool modal, WFlags fl )
    : NotTransmision( parent, name, modal, fl )
{
//	exec();
}

QNotTransmision::~QNotTransmision()
{
}
void QNotTransmision::PonDatos(const char *pchrPtrEdoTransmision,
			       const char *pchrPtrArchivo,
			       const char *pchrPtrIpEstacion,	
			       const char *pchrPtrPtoEstacion)
{
	if(strcmp(pchrPtrEdoTransmision,"FinTransferencia"))
	{
	QLEArchivo->setText(pchrPtrArchivo);
	QLEIpEstacion->setText(QString(pchrPtrIpEstacion));
	QLEPtoEstacion->setText(QString(pchrPtrPtoEstacion));
	QTEInforma->append(QString(pchrPtrEdoTransmision)        +
			   ":"					 +
			   pchrPtrArchivo			 +
			   "->"					 +
			   pchrPtrIpEstacion			 +
			   ":"					 +
			  pchrPtrPtoEstacion);
	
	setCaption(QString(pchrPtrIpEstacion) +
		   "=>"                       +
		   pchrPtrPtoEstacion);
	}
	chrPtrEdoTransmision=pchrPtrEdoTransmision;
}
void QNotTransmision::closeEvent(QCloseEvent *pQCEvent)
{
	if(!strcmp(chrPtrEdoTransmision,"FinTransferencia"))
	pQCEvent->accept();
	

}
