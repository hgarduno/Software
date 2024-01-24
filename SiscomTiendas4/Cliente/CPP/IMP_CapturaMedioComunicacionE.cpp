#include <IMP_CapturaMedioComunicacionE.h>
#include<SiscomDesarrollo3Qt++.h>

#include <QCtrlMedComunicacion.h>
#include <CQSisEmpresas2.h>
QCapturaMedioComunicacionE::QCapturaMedioComunicacionE(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    bool pbModal,
				    WFlags pWFlags):	      
				CapturaMedioComunicacionE(pQWParent,pchrPtrName,pbModal,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos)
{
IniciaVariables();
ConectaSlots();
exec();
}

QCapturaMedioComunicacionE::~QCapturaMedioComunicacionE()
{

}

void QCapturaMedioComunicacionE::ConectaSlots()
{

connect(QCtrMedioComunicacion,
	SIGNAL(SignalMedComunicacion(SisMedCom *)),
	SLOT(SlotMedioComunicacion(SisMedCom *)));
connect(QLEDato,
	SIGNAL(returnPressed()),
	SLOT(SlotPasaFocoDescripcion()));
connect(QPBAceptar,
	SIGNAL(clicked()),
	SLOT(SlotAceptar()));

}
void QCapturaMedioComunicacionE::SlotAceptar()
{
	done(1);
}
void QCapturaMedioComunicacionE::SlotPasaFocoDescripcion()
{
	SiscomDesarrollo3Qt::PasaFocoControl(QTEDescripcion);
}
void QCapturaMedioComunicacionE::SlotMedioComunicacion(SisMedCom *pSisMedCom)
{
	SisMedioCom=pSisMedCom;
	SiscomDesarrollo3Qt::PasaFocoControl(QLEDato);
}
void QCapturaMedioComunicacionE::IniciaVariables()
{
QCtrMedioComunicacion->PonServidor(SisDatCom);
QCtrMedioComunicacion->IniciaControl();
}
CQSisMedioComunicacionE *QCapturaMedioComunicacionE::MedioComunicacion()
{
return new CQSisMedioComunicacionE(
		"",
		"",
		(*SisMedioCom)["IdMedio"],
		SiscomDesarrollo3Qt::ObtenInformacionDelEdit(QTEDescripcion),
		SiscomDesarrollo3Qt::ObtenInformacionDelEdit(QLEDato));
}
