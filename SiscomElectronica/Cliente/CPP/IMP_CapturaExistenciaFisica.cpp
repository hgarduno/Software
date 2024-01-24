#include <IMP_CapturaExistenciaFisica.h>
#include <SiscomDesarrollo3Qt++.h>

#include <qpushbutton.h>
#include <qlineedit.h>
QCapturaExistenciaFisica::QCapturaExistenciaFisica(
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    bool pbModal,
				    WFlags pWFlags):	      
				CapturaExistenciaFisica(pQWParent,
							pchrPtrName,
							pbModal,
							pWFlags)
{
IniciaVariables();
ConectaSlots();
exec();
}

QCapturaExistenciaFisica::~QCapturaExistenciaFisica()
{

}
void QCapturaExistenciaFisica::SlotPasaFocoAceptar()
{
SiscomDesarrollo3Qt::PasaFocoControl(QPBAceptar);
}
void QCapturaExistenciaFisica::SlotAceptar()
{
done(1);
}
void QCapturaExistenciaFisica::ConectaSlots()
{
connect(QLEExistenciaFisica,
	SIGNAL(returnPressed()),
	SLOT(SlotPasaFocoAceptar()));
connect(QPBAceptar,
	SIGNAL(clicked()),
	SLOT(SlotAceptar()));
}
void QCapturaExistenciaFisica::IniciaVariables()
{

}
const char *QCapturaExistenciaFisica::ExistenciaFisica()
{
return strdup(SiscomDesarrollo3Qt::ObtenInformacionDelEdit(QLEExistenciaFisica));
}
