#include <IMP_Juez.h>
#include<SISCOMComunicaciones++.h>

#include <CQSisJueces.h>
#include <qpushbutton.h>
#include <qlineedit.h>
QJuez *InstanciaJuez(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QJuez((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QJuez::QJuez(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				Juez(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos)
{
IniciaVariables();
ConectaSlots();
}

QJuez::~QJuez()
{

}

void QJuez::ConectaSlots()
{
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
		SLOT(SlotPasaFocoDescripcion()));
	connect(QLEDescripcion,
		SIGNAL(returnPressed()),
		SLOT(SlotPasaFocoCorreo()));
	connect(QLECorreo,
		SIGNAL(returnPressed()),
		SLOT(SlotPasaFocoRegistrar()));

	connect(QPBRegistrar,
		SIGNAL(clicked()),
		SLOT(SlotRegistrar()));

}
void QJuez::FormaDatosJuez(CQSisJuez **pCQSJuez)
{
	*pCQSJuez=new CQSisJuez(SiscomObtenInformacionDelEdit(QLENombre),
					    SiscomObtenInformacionDelEdit(QLEAPaterno),
					    SiscomObtenInformacionDelEdit(QLEAMaterno),
					    "");
	(*pCQSJuez)->AnexaCorreoElectronico(
				SiscomObtenInformacionDelEdit(QLECorreo));
	(*pCQSJuez)->AnexaTelefono(
				SiscomObtenInformacionDelEdit(QLETelefono),
				SiscomObtenInformacionDelEdit(QLEDescripcion));
	
}
void QJuez::SlotRegistrar()
{
CQSisOpJuez lCQSOJuez(SisDatCom);
CQSisJuez *lCQSJuez;

	FormaDatosJuez(&lCQSJuez);

	lCQSOJuez.InsertaJuez(lCQSJuez,&SRegistrosPro2);
}
void QJuez::SlotPasaFocoRegistrar()
{
	SiscomPasaFocoControl(QPBRegistrar);
}
void QJuez::SlotPasaFocoDescripcion()
{
	SiscomPasaFocoControl(QLEDescripcion);
}
void QJuez::SlotPasaFocoCorreo()
{
	SiscomPasaFocoControl(QLECorreo);
}
void QJuez::SlotPasaFocoTelefono()
{
	SiscomPasaFocoControl(QLETelefono);
}
void QJuez::SlotPasaFocoAMaterno()
{
	SiscomPasaFocoControl(QLEAMaterno);
}
void QJuez::SlotPasaFocoAPaterno()
{
	SiscomPasaFocoControl(QLEAPaterno);
}
void QJuez::IniciaVariables()
{
	SiscomPasaFocoControl(QLENombre);
}
