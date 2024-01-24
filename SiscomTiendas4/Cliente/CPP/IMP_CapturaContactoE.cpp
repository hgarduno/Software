#include <IMP_CapturaContactoE.h>
#include <SiscomDesarrollo3Qt++.h>

#include <QCtrlMedComunicacion.h>
#include <CQSisEmpresas2.h>
#include <qlineedit.h>
#include <qtextedit.h>
#include <qpushbutton.h>
QCapturaContactoE::QCapturaContactoE(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    bool pbModal,
				    WFlags pWFlags):	      
				CapturaContactoE(pQWParent,pchrPtrName,pbModal,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos)
{
IniciaVariables();
ConectaSlots();
exec();
}

QCapturaContactoE::~QCapturaContactoE()
{

}

void QCapturaContactoE::ConectaSlots()
{
connect(QLENombre,
	SIGNAL(returnPressed()),
	SLOT(SlotPasaFocoAPaterno()));
connect(QLEAPaterno,
	SIGNAL(returnPressed()),
	SLOT(SlotPasaFocoAMaterno()));
connect(QLEAMaterno,
	SIGNAL(returnPressed()),
	SLOT(SlotPasaFocoDescripcion()));
connect(QPBAceptar,
	SIGNAL(clicked()),
	SLOT(SlotAceptar()));
}
void QCapturaContactoE::SlotAceptar()
{
done(1);
}
void QCapturaContactoE::SlotPasaFocoAPaterno()
{
SiscomDesarrollo3Qt::PasaFocoControl(QLEAPaterno);
}
void QCapturaContactoE::SlotPasaFocoAMaterno()
{
SiscomDesarrollo3Qt::PasaFocoControl(QLEAMaterno);
}
void QCapturaContactoE::SlotPasaFocoDescripcion()
{
SiscomDesarrollo3Qt::PasaFocoControl(QTEDescripcion);
}
void QCapturaContactoE::IniciaVariables()
{
SiscomDesarrollo3Qt::PasaFocoControl(QLENombre);
}
CQSisContactoE *QCapturaContactoE::ContactoE()
{
return new CQSisContactoE("",
			  SiscomDesarrollo3Qt::ObtenInformacionDelEdit(QTEDescripcion),
			  SiscomDesarrollo3Qt::ObtenInformacionDelEdit(QLENombre),
			  SiscomDesarrollo3Qt::ObtenInformacionDelEdit(QLEAPaterno),
			  SiscomDesarrollo3Qt::ObtenInformacionDelEdit(QLEAMaterno));
}
