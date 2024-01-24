#include <IMP_Gimnastas.h>
#include <IMP_QControlFecha.h>
#include<SISCOMComunicaciones++.h>
#include <QCtrlGimnasios.h>
#include <CQSisGimnastas.h>

#include <qlineedit.h>
#include <qpushbutton.h>
#include <qmessagebox.h>
QGimnastas *InstanciaGimnastas(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QGimnastas((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QGimnastas::QGimnastas(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				Gimnastas(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos)
{
IniciaVariables();
ConectaSlots();
}

QGimnastas::~QGimnastas()
{

}

void QGimnastas::ConectaSlots()
{
	connect(QCtrGimnasios,
		SIGNAL(SignalGimnasio(CQSisGimnasio *)),
		SLOT(SlotGimnasio(CQSisGimnasio *)));
	connect(QLENombre,
		SIGNAL(returnPressed()),
		SLOT(SlotPasaFocoAPaterno()));
	connect(QLEAPaterno,
		SIGNAL(returnPressed()),
		SLOT(SlotPasaFocoAMaterno()));
	connect(QLEAMaterno,
		SIGNAL(returnPressed()),
		SLOT(SlotPasaFocoFechaNac()));
	connect(QCtrFechaNac,
		SIGNAL(Signal_EnterA_o()),
		SLOT(SlotPasaFocoTelefono()));
	connect(QLETelefono,
		SIGNAL(returnPressed()),
		SLOT(SlotPasaFocoDscTelefono()));
	connect(QLEDescripcionT,
		SIGNAL(returnPressed()),
		SLOT(SlotPasaFocoCorreo()));
	connect(QLECorreo,
		SIGNAL(returnPressed()),
		SLOT(SlotPasaFocoRegistrar()));
	connect(QPBRegistrar,
		SIGNAL(clicked()),
		SLOT(SlotRegistra()));

}
void QGimnastas::IniciaVariables()
{

	QCtrGimnasios->PonServidor(SisDatCom);
	QCtrGimnasios->IniciaControl();
	QCtrGimnasios->setFocus();
}
void QGimnastas::SlotPasaFocoFechaNac()
{
	QCtrFechaNac->setFocus();
}

void QGimnastas::SlotRegistra()
{
EstanTodosLosDatos();
CQSisOpGimnasta lCQSOpEnt(SisDatCom);
CQSisGimnasta *lCQSGimnasta;
SiscomRegistrosPro2 *lSRegistrosPro2;
	FormaDatosGimnasta(&lCQSGimnasta);
	lCQSOpEnt.InsertaGimnasta(lCQSGimnasta,&lSRegistrosPro2);
	if((*lSRegistrosPro2)["edovalidacion"][0])
	QMessageBox::information(this,
				 "Aviso Del Sistema",
				 (*lSRegistrosPro2)["edovalidacion"]);
SiscomPasaFocoControl(QLENombre);
}

void QGimnastas::FormaDatosGimnasta(CQSisGimnasta **pCQSGimnasta)
{
	*pCQSGimnasta=new CQSisGimnasta(SiscomObtenInformacionDelEdit(QLENombre),
					    SiscomObtenInformacionDelEdit(QLEAPaterno),
					    SiscomObtenInformacionDelEdit(QLEAMaterno),
					    "");
	(*pCQSGimnasta)->PonGimnasio(CQSGimnasio);
	(*pCQSGimnasta)->PonFechaNac((const char *)QCtrFechaNac->ObtenFecha());
	(*pCQSGimnasta)->AnexaCorreoElectronico(
				SiscomObtenInformacionDelEdit(QLECorreo));
	(*pCQSGimnasta)->AnexaTelefono(
				SiscomObtenInformacionDelEdit(QLETelefono),
				SiscomObtenInformacionDelEdit(QLEDescripcionT));
	
}
void QGimnastas::SlotPasaFocoAPaterno()
{
	SiscomPasaFocoControl(QLEAPaterno);
	EstanTodosLosDatos();
}
void QGimnastas::SlotPasaFocoAMaterno()
{
	EstanTodosLosDatos();
	SiscomPasaFocoControl(QLEAMaterno);
}
void QGimnastas::SlotPasaFocoTelefono()
{
	SiscomPasaFocoControl(QLETelefono);
}
void QGimnastas::SlotPasaFocoDscTelefono()
{
	SiscomPasaFocoControl(QLEDescripcionT);
}
void QGimnastas::SlotPasaFocoCorreo()
{
	SiscomPasaFocoControl(QLECorreo);
}
void QGimnastas::SlotPasaFocoRegistrar()
{
	EstanTodosLosDatos();
	SiscomPasaFocoControl(QPBRegistrar);
}
void QGimnastas::SlotGimnasio(CQSisGimnasio *pCQSGimnasio)
{
	CQSGimnasio=pCQSGimnasio;
	SiscomPasaFocoControl(QLENombre);
EstanTodosLosDatos();
}

void QGimnastas::EstanTodosLosDatos()
{
	QPBRegistrar->setEnabled(CQSGimnasio 	&&
				 SiscomObtenInformacionDelEdit(QLEAPaterno)[0] &&
				 SiscomObtenInformacionDelEdit(QLENombre)[0]);
}
