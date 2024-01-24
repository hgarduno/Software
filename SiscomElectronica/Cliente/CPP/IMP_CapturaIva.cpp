#include <IMP_CapturaIva.h>

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

QCapturaIva::QCapturaIva( QWidget* parent, const char* name, bool modal, WFlags fl )
    : CapturaIva( parent, name, modal, fl )
{
	ConectaSlots();
	exec();
}
	

QCapturaIva::~QCapturaIva()
{
}
void QCapturaIva::ConectaSlots()
{
	connect(QPBMasIva,
		SIGNAL(clicked()),
		SLOT(S_MasIva()));
	connect(QPBConIva,
		SIGNAL(clicked()),
		SLOT(S_ConIva()));
	
}
void QCapturaIva::S_MasIva()
{
	chrPtrMasConIva="+IVA";
	done(1);

}
void QCapturaIva::S_ConIva()
{
	chrPtrMasConIva="Con IVA";	
	done(1);
}
const char *QCapturaIva::ObtenSinConIva()
{
	return chrPtrMasConIva;
}
void QCapturaIva::closeEvent(QCloseEvent *)
{
	printf("Imposible cerrar la ventana\n");
}
