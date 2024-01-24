#include <IMP_CapturaDireccionE.h>
#include <SiscomDesarrollo3Qt++.h>
#include <CQSisEmpresas2.h>

#include <qlineedit.h>
#include <qpushbutton.h>
QCapturaDireccionE::QCapturaDireccionE(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    bool pbModal,
				    WFlags pWFlags):	      
				CapturaDireccionE(pQWParent,pchrPtrName,pbModal,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos)
{
IniciaVariables();
ConectaSlots();
exec();
}

QCapturaDireccionE::~QCapturaDireccionE()
{

}

void QCapturaDireccionE::ConectaSlots()
{
connect(QLELinea1,
	SIGNAL(returnPressed()),
	SLOT(SlotPasaFocoLinea2()));
connect(QLELinea2,
	SIGNAL(returnPressed()),
	SLOT(SlotPasaFocoLinea3()));
connect(QLELinea3,
	SIGNAL(returnPressed()),
	SLOT(SlotPasaFocoAceptar()));
connect(QPBAceptar,
	SIGNAL(clicked()),
	SLOT(SlotAceptar()));
}
void QCapturaDireccionE::SlotAceptar()
{
	done(1);
}
void QCapturaDireccionE::SlotPasaFocoAceptar()
{
SiscomDesarrollo3Qt::PasaFocoControl(QPBAceptar);
}
void QCapturaDireccionE::SlotPasaFocoLinea2()
{
SiscomDesarrollo3Qt::PasaFocoControl(QLELinea2);
}
void QCapturaDireccionE::SlotPasaFocoLinea3()
{
SiscomDesarrollo3Qt::PasaFocoControl(QLELinea3);
}

void QCapturaDireccionE::IniciaVariables()
{
SiscomDesarrollo3Qt::PasaFocoControl(QLELinea1);
}

CQSisDireccionE *QCapturaDireccionE::DireccionE()
{
return new CQSisDireccionE("",
			   "",
			   SiscomDesarrollo3Qt::ObtenInformacionDelEdit(QLELinea1),
			   SiscomDesarrollo3Qt::ObtenInformacionDelEdit(QLELinea2),
			   SiscomDesarrollo3Qt::ObtenInformacionDelEdit(QLELinea3));
}
