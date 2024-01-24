#include <IMP_PromocionesElectronica.h>


#include <CQSisPromociones.h>
#include <IMP_QControlFecha.h>
#include <SiscomDesarrollo3Qt++.h>
#include <qlineedit.h>
#include <qtextedit.h>
#include <qpushbutton.h>
#include <qmessagebox.h>

QPromocionesElectronica *InstanciaPromocionesElectronica(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QPromocionesElectronica((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QPromocionesElectronica::QPromocionesElectronica(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				PromocionesElectronica(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos)
{
IniciaVariables();
ConectaSlots();
}

QPromocionesElectronica::~QPromocionesElectronica()
{

}

void QPromocionesElectronica::ConectaSlots()
{
connect(QLENombre,
	SIGNAL(returnPressed()),
	SLOT(SlotPasaFocoPuntosSiscom()));
connect(QLEPuntosSiscom,
	SIGNAL(returnPressed()),
	SLOT(SlotPasaFocoFechaIni()));
connect(QCtrFechaIni,
	SIGNAL(Signal_EnterA_o()),
	SLOT(SlotPasaFocoFechaFin()));
connect(QCtrFechaFin,
	SIGNAL(Signal_EnterA_o()),
	SLOT(SlotPasaFocoDescripcion()));
connect(QPBRegistra,
	SIGNAL(clicked()),
	SLOT(SlotRegistra()));
}
void QPromocionesElectronica::IniciaVariables()
{
SiscomDesarrollo3Qt::PasaFocoControl(QLENombre);
}


void QPromocionesElectronica::SlotPasaFocoPuntosSiscom()
{
SiscomDesarrollo3Qt::PasaFocoControl(QLEPuntosSiscom);
}


void QPromocionesElectronica::SlotPasaFocoFechaIni()
{
SiscomDesarrollo3Qt::PasaFocoControl(QCtrFechaIni);
}
void QPromocionesElectronica::SlotPasaFocoFechaFin()
{
SiscomDesarrollo3Qt::PasaFocoControl(QCtrFechaFin);
}
void QPromocionesElectronica::SlotPasaFocoDescripcion()
{
SiscomDesarrollo3Qt::PasaFocoControl(QTEDescripcion);
}
void QPromocionesElectronica::SlotRegistra()
{
RegistraPromocion();
}
void QPromocionesElectronica::SlotActualiza()
{

}

void QPromocionesElectronica::RegistraPromocion()
{
SiscomRegistro3Lst lSisReg3LstEdoReg;
CQSisOpPromocion lCQSOpPromocion(SisDatCom);
lCQSOpPromocion.Registra(Promocion(),&lSisReg3LstEdoReg);
MuestraEdoRegistro(&lSisReg3LstEdoReg);
}
void QPromocionesElectronica::MuestraEdoRegistro(SiscomRegistro3Lst *pSisReg3LstRegreso)
{
 if(strcmp((*pSisReg3LstRegreso)["NoError"],"0"))
    QMessageBox::information(0,
    			     "Mensaje de Sistema",
			     (*pSisReg3LstRegreso)["MsgError"]);
}
CQSisPromocion *QPromocionesElectronica::Promocion()
{
return new CQSisPromocion(
		chrPtrArgumentos[0],
		"",
		SiscomDesarrollo3Qt::ObtenInformacionDelEdit(QLENombre),
		(const char *)QCtrFechaIni->ObtenFecha(),
		(const char *)QCtrFechaFin->ObtenFecha(),
		SiscomDesarrollo3Qt::ObtenInformacionDelEdit(QLEPuntosSiscom),
		SiscomDesarrollo3Qt::ObtenInformacionDelEdit(QTEDescripcion));
}
