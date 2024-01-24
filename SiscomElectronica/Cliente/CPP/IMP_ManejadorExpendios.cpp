#include <IMP_ManejadorExpendios.h>
#include <SiscomDesarrollo3Qt++.h>
#include <CQSisExpendios.h>
#include <QCtrlExpendios.h>

#include <qlineedit.h>
#include <qpushbutton.h>
QManejadorExpendios *InstanciaManejadorExpendios(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QManejadorExpendios((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QManejadorExpendios::QManejadorExpendios(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				ManejadorExpendios(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos)
{
IniciaVariables();
ConectaSlots();
}

QManejadorExpendios::~QManejadorExpendios()
{

}

void QManejadorExpendios::ConectaSlots()
{
connect(QLERazonSocial,
	SIGNAL(returnPressed()),
	SLOT(SlotPasaFocoRFC()));

connect(QLERFC,
	SIGNAL(returnPressed()),
	SLOT(SlotPasaFocoDireccionIp()));
connect(QLEDireccionIp,
	SIGNAL(returnPressed()),
	SLOT(SlotPasaFocoPuerto()));
connect(QLEPuerto,
	SIGNAL(returnPressed()),
	SLOT(SlotPasaFocoBase()));
connect(QLEBase,
	SIGNAL(returnPressed()),
	SLOT(SlotPasaFocoRegistra()));
connect(QPBRegistra,
	SIGNAL(clicked()),
	SLOT(SlotRegistra()));
connect(QCtrExpendios,
	SIGNAL(SignalExpendio(SiscomRegistro3 *)),
	SLOT(SlotExpendio(SiscomRegistro3 *)));
connect(QPBActualiza,
	SIGNAL(clicked()),
	SLOT(SlotActualiza()));
connect(QPBIniciar,
	SIGNAL(clicked()),
	SLOT(SlotInicia()));
}
void QManejadorExpendios::SlotInicia()
{
IniciaExpendio();
}
void QManejadorExpendios::SlotActualiza()
{
   ActualizaExpendio();
   QCtrExpendios->IniciaControl();
}
void QManejadorExpendios::SlotExpendio(SiscomRegistro3 *pSisReg3Expendio)
{
  SisReg3Expendio=pSisReg3Expendio;
  MuestraExpendio(pSisReg3Expendio);
}
void QManejadorExpendios::SlotRegistra()
{
   Registra();
   QCtrExpendios->IniciaControl();
}
void QManejadorExpendios::SlotPasaFocoRegistra()
{
SiscomDesarrollo3Qt::PasaFocoControl(QPBRegistra);
}
void QManejadorExpendios::SlotPasaFocoRFC()
{
 SiscomDesarrollo3Qt::PasaFocoControl(QLERFC);
}
void QManejadorExpendios::SlotPasaFocoDireccionIp()
{
	SiscomDesarrollo3Qt::PasaFocoControl(QLEDireccionIp);
}
void QManejadorExpendios::SlotPasaFocoPuerto()
{
	SiscomDesarrollo3Qt::PasaFocoControl(QLEPuerto);
}
void QManejadorExpendios::SlotPasaFocoBase()
{
	SiscomDesarrollo3Qt::PasaFocoControl(QLEBase);
}
void QManejadorExpendios::IniciaVariables()
{
QCtrExpendios->Servidor(SisDatCom);
QCtrExpendios->Expendio(chrPtrArgumentos[0]);
QCtrExpendios->IniciaControl();


SiscomDesarrollo3Qt::PasaFocoControl(QLERazonSocial);

}
void QManejadorExpendios::Registra()
{
CQSisOpExpendio lCQSisOpExpendio(SisDatCom);
lCQSisOpExpendio.Registra(Expendio(),&SisReg3LstEdoReg);
}
CQSisExpendio *QManejadorExpendios::Expendio()
{
return new CQSisExpendio(
	chrPtrArgumentos[0],
	"",
	SiscomDesarrollo3Qt::ObtenInformacionDelEdit(QLERazonSocial),
	SiscomDesarrollo3Qt::ObtenInformacionDelEdit(QLERFC),
	SiscomDesarrollo3Qt::ObtenInformacionDelEdit(QLEDireccionIp),
	SiscomDesarrollo3Qt::ObtenInformacionDelEdit(QLEPuerto),
	SiscomDesarrollo3Qt::ObtenInformacionDelEdit(QLEBase));
}

CQSisExpendio *QManejadorExpendios::ExpendioActualizar()
{
return new CQSisExpendio(
	chrPtrArgumentos[0],
	(*SisReg3Expendio)["idempresa"],
	SiscomDesarrollo3Qt::ObtenInformacionDelEdit(QLERazonSocial),
	SiscomDesarrollo3Qt::ObtenInformacionDelEdit(QLERFC),
	SiscomDesarrollo3Qt::ObtenInformacionDelEdit(QLEDireccionIp),
	SiscomDesarrollo3Qt::ObtenInformacionDelEdit(QLEPuerto),
	SiscomDesarrollo3Qt::ObtenInformacionDelEdit(QLEBase));
}
void QManejadorExpendios::MuestraExpendio(SiscomRegistro3 *pSisReg3Expendio)
{
QLERazonSocial->setText((*pSisReg3Expendio)["razonsocial"]);
QLERFC->setText((*pSisReg3Expendio)["rfc"]);
QLEDireccionIp->setText((*pSisReg3Expendio)["diripsvrad"]);
QLEPuerto->setText((*pSisReg3Expendio)["ptocomad"]);
QLEBase->setText((*pSisReg3Expendio)["basedatos"]);
}

void QManejadorExpendios::ActualizaExpendio()
{
CQSisOpExpendio lCQSisOpExpendio(SisDatCom);
lCQSisOpExpendio.Actualiza(ExpendioActualizar(),&SisReg3LstEdoReg);
}
void QManejadorExpendios::IniciaExpendio()
{
CQSisOpExpendio lCQSisOpExpendio(SisDatCom);
lCQSisOpExpendio.Inicia(chrPtrArgumentos[0],
			SisReg3Expendio,
			&SisReg3LstEdoReg);
}
