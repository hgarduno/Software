#include <IMP_Entrenadores.h>
#include<SISCOMComunicaciones++.h>

#include <QCtrlGimnasios.h>
#include <CQSisEntrenadores.h>
#include <qlineedit.h>
#include <qpushbutton.h>
#include <qmessagebox.h>
QEntrenadores *InstanciaEntrenadores(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QEntrenadores((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QEntrenadores::QEntrenadores(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				Entrenadores(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos)
{
IniciaVariables();
ConectaSlots();
}

QEntrenadores::~QEntrenadores()
{

}

void QEntrenadores::ConectaSlots()
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
void QEntrenadores::FormaDatosEntrenador(CQSisEntrenador **pCQSEntrenador)
{
	*pCQSEntrenador=new CQSisEntrenador(SiscomObtenInformacionDelEdit(QLENombre),
					    SiscomObtenInformacionDelEdit(QLEAPaterno),
					    SiscomObtenInformacionDelEdit(QLEAMaterno),
					    "");
	(*pCQSEntrenador)->PonGimnasio(CQSGimnasio);
	(*pCQSEntrenador)->AnexaCorreoElectronico(
				SiscomObtenInformacionDelEdit(QLECorreo));
	(*pCQSEntrenador)->AnexaTelefono(
				SiscomObtenInformacionDelEdit(QLETelefono),
				SiscomObtenInformacionDelEdit(QLEDescripcionT));
	
}
void QEntrenadores::SlotRegistra()
{
CQSisOpEntrenador lCQSOpEnt(SisDatCom);
CQSisEntrenador *lCQSEntrenador;
SiscomRegistrosPro2 *lSRegistrosPro2;
	FormaDatosEntrenador(&lCQSEntrenador);
	lCQSOpEnt.InsertaEntrenador(lCQSEntrenador,&lSRegistrosPro2);
	if((*lSRegistrosPro2)["edovalidacion"][0])
	QMessageBox::information(this,
				 "Aviso Del Sistema",
				 (*lSRegistrosPro2)["edovalidacion"]);
}
void QEntrenadores::SlotPasaFocoAPaterno()
{
	SiscomPasaFocoControl(QLEAPaterno);
}
void QEntrenadores::SlotPasaFocoAMaterno()
{
	SiscomPasaFocoControl(QLEAMaterno);
}
void QEntrenadores::SlotPasaFocoTelefono()
{
	SiscomPasaFocoControl(QLETelefono);
}
void QEntrenadores::SlotPasaFocoDscTelefono()
{
	SiscomPasaFocoControl(QLEDescripcionT);
}
void QEntrenadores::SlotPasaFocoCorreo()
{
	SiscomPasaFocoControl(QLECorreo);
}
void QEntrenadores::SlotPasaFocoRegistrar()
{
	SiscomPasaFocoControl(QPBRegistrar);
}
void QEntrenadores::SlotGimnasio(CQSisGimnasio *pCQSGimnasio)
{
	CQSGimnasio=pCQSGimnasio;
	SiscomPasaFocoControl(QLENombre);
}
void QEntrenadores::IniciaVariables()
{
	QCtrGimnasios->PonServidor(SisDatCom);
	QCtrGimnasios->IniciaControl();
	QCtrGimnasios->setFocus();
}
