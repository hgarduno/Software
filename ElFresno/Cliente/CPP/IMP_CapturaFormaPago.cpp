#include <IMP_CapturaFormaPago.h>
#include <CQSiscomCom.h>
#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qcombobox.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <IMP_QControlFecha.h>
QCapturaFormaPago::QCapturaFormaPago( QWidget* parent, const char* name, bool modal, WFlags fl )
    : CapturaFormaPago( parent, name, modal, fl )
{
	ConectaSlots();
	IniciaVariables();
	exec();
}

QCapturaFormaPago::~QCapturaFormaPago()
{
}
void QCapturaFormaPago::IniciaVariables()
{

	QCFechaPago->ColocaFechaHoy();
}
void QCapturaFormaPago::ConectaSlots()
{
	connect(QCBFPago,
		SIGNAL(activated(int)),
		SLOT(S_SFormaPago(int)));
	connect(QPBAceptar,
		SIGNAL(clicked()),
		SLOT(S_Aceptar()));
	connect(QPBCancelar,
		SIGNAL(clicked()),
		SLOT(S_Cancelar()));


}
void QCapturaFormaPago::S_Aceptar()
{

	Opcion=SISCOMGlobales::Aceptar;
	done(1);
}
void QCapturaFormaPago::S_Cancelar()
{
	
	Opcion=SISCOMGlobales::Cancelar;
	done(1);

}
void QCapturaFormaPago::S_SFormaPago(int pintNFPago)
{

	QCFechaPago->setEnabled(pintNFPago);
	PasaFocoControl(QCFechaPago);

}
SISCOMGlobales::BTN_Captura QCapturaFormaPago::ObtenOpcion()
{
	return Opcion;
}
void QCapturaFormaPago::ObtenFormaPago(char *pchrPtrFormaPago,
				       char *pchrPtrFechaPago)
{

	strcpy(pchrPtrFormaPago,
	       (const char *)QCBFPago->currentText());
	if(QCFechaPago->isEnabled())
	strcpy(pchrPtrFechaPago,
	       (const char *)QCFechaPago->ObtenFecha());
	else
	pchrPtrFechaPago[0]=0;
}
