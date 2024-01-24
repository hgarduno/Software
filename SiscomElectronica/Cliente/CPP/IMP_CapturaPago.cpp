#include <IMP_CapturaPago.h>
#include <CQSis3QtComunes.h>
#include <SiscomDesarrollo3Qt++.h>
#include <qpushbutton.h>
#include <qlineedit.h>
#include <qlcdnumber.h>
QCapturaPago::QCapturaPago(SiscomDatCom *pSisDatCom, 
				    const char *pchrPtrImporte,
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    bool pbModal,
				    WFlags pWFlags):	      
				CapturaPago(pQWParent,pchrPtrName,pbModal,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrImporte(pchrPtrImporte)
{
IniciaVariables();
ConectaSlots();
exec();
}

QCapturaPago::~QCapturaPago()
{

}
const char *QCapturaPago::Cambio()
{
return chrPtrCambio;
}
void QCapturaPago::Recibi(char *pchrPtrRecibi)
{
strcpy(pchrPtrRecibi,
       (const char *)QLERecibo->text());
}
int QCapturaPago::ImporteValido()
{
return intImporteValido;
}
void QCapturaPago::ConectaSlots()
{
	connect(QPBAceptar,
		SIGNAL(clicked()),
		SLOT(SlotAceptar()));
	connect(QPBCancelar,
		SIGNAL(clicked()),
		SLOT(SlotCancelar()));
	connect(QLERecibo,
		SIGNAL(returnPressed()),
		SLOT(SlotCalculaCambio()));
}
void QCapturaPago::IniciaVariables()
{
QLERecibo->setText(chrPtrImporte);
QLCDNImporte->display(chrPtrImporte);
SiscomDesarrollo3Qt::PasaFocoControl(QLERecibo);
}
void QCapturaPago::SlotCalculaCambio()
{
CQSis3QtComunes lCQS3QtComunes(SisDatCom);
chrPtrCambio=lCQS3QtComunes.ObtenCambio(
		 chrPtrImporte,
		 SiscomDesarrollo3Qt::ObtenInformacionDelEdit(QLERecibo),
		 &intImporteValido);
QLCDNCambio->display(chrPtrCambio);
QPBAceptar->setEnabled(intImporteValido);
SiscomDesarrollo3Qt::PasaFocoControl(QPBAceptar);
}
void QCapturaPago::SlotAceptar()
{
	done(1);
}
void QCapturaPago::SlotCancelar()
{
	intImporteValido=0;
	done(1);
}

void QCapturaPago::closeEvent(QCloseEvent *)
{


}
void QCapturaPago::reject()
{

}
