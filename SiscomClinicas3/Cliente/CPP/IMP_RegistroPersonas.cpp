#include <IMP_RegistroPersonas.h>
#include<SISCOMComunicaciones++.h>
#include <QCtrlPerfiles.h>
#include <CQSisPersonas.h>
#include <qpushbutton.h>
#include <qmessagebox.h>
FILE *gPtrFleArchivoLog3Qt;
QRegistroPersonas *InstanciaRegistroPersonas(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QRegistroPersonas((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QRegistroPersonas::QRegistroPersonas(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				RegistroPersonas(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos)
{
IniciaVariables();
ConectaSlots();
}

QRegistroPersonas::~QRegistroPersonas()
{

}

void QRegistroPersonas::ConectaSlots()
{

	connect(QLENombre,
		SIGNAL(returnPressed()),
		SLOT(SlotPasaFocoAPaterno()));
	connect(QLEAPaterno,
		SIGNAL(returnPressed()),
		SLOT(SlotPasaFocoAMaterno()));
	connect(QLEAMaterno,
		SIGNAL(returnPressed()),
		SLOT(SlotPasaFocoRFC()));
	connect(QLERFC,
		SIGNAL(returnPressed()),
		SLOT(SlotPasaFocoFirma()));
	connect(QLEFirma,
		SIGNAL(returnPressed()),
		SLOT(SlotPasaFocoPassword()));
	connect(QLEPassword,
		SIGNAL(returnPressed()),
		SLOT(SlotPasaFocoRePassword()));
	connect(QLERPassword,
		SIGNAL(returnPressed()),
		SLOT(SlotPasaFocoPerfiles()));
	connect(QCtrPerfiles,
		SIGNAL(SignalPerfil(PerfilSeguridadProt2 *)),
		SLOT(SlotPerfil(PerfilSeguridadProt2 *)));
	connect(QPBRGenerales,
		SIGNAL(clicked()),
		SLOT(SlotRegistraGenerales()));

}
void QRegistroPersonas::SlotRegistraGenerales()
{

	RegistraGenerales();

}

void QRegistroPersonas::SlotPerfil(PerfilSeguridadProt2 *pPSeguridadProt2)
{
	PSegProt2=pPSeguridadProt2;
	SiscomPasaFocoControl(QPBRGenerales);
}
void QRegistroPersonas::SlotPasaFocoAPaterno()
{
	SiscomPasaFocoControl(QLEAPaterno);
}

void QRegistroPersonas::SlotPasaFocoAMaterno()
{
	SiscomPasaFocoControl(QLEAMaterno);
}
void QRegistroPersonas::SlotPasaFocoRFC()
{
	SiscomPasaFocoControl(QLERFC);
}
void QRegistroPersonas::SlotPasaFocoFirma()
{
	SiscomPasaFocoControl(QLEFirma);
}
void QRegistroPersonas::SlotPasaFocoPassword()
{
	SiscomPasaFocoControl(QLEPassword);
}
void QRegistroPersonas::SlotPasaFocoRePassword()
{
	SiscomPasaFocoControl(QLERPassword);
}
void QRegistroPersonas::SlotPasaFocoPerfiles()
{
	QCtrPerfiles->setFocus();
}
void QRegistroPersonas::IniciaVariables()
{
	setCaption(chrPtrArgumentos[11]);
	QCtrPerfiles->PonServidor(SisDatCom);
	QCtrPerfiles->PonAplicacion(getenv("Aplicacion"));
	QCtrPerfiles->IniciaControl();
	SiscomPasaFocoControl(QLENombre);
}
CQSisPersona *QRegistroPersonas::Empleado()
{

return new CQSisPersona(
		"",
		SiscomObtenInformacionDelEdit(QLENombre),
		SiscomObtenInformacionDelEdit(QLEAPaterno),
		SiscomObtenInformacionDelEdit(QLEAMaterno),
		SiscomObtenInformacionDelEdit(QLERFC),
		SiscomObtenInformacionDelEdit(QLEFirma),
		SiscomObtenInformacionDelEdit(QLEPassword),
		SiscomObtenInformacionDelEdit(QLERPassword),
		PSegProt2->SRegistrosPro2["IdPerfil"]);
}
void QRegistroPersonas::RegistraGenerales()
{
SiscomRegistrosPro2 *lSRegistrosPro2;
CQSisPersona *lCQSPEmpleado;
	lCQSPEmpleado=Empleado();
CQSisOpPersona lCQSOPersona(SisDatCom);
lCQSOPersona.Empleado(lCQSPEmpleado,&lSRegistrosPro2);
InformaEdoRegistro(lSRegistrosPro2);
}

void QRegistroPersonas::InformaEdoRegistro(SiscomRegistrosPro2 *pSRegistrosPro2)
{

	if(pSRegistrosPro2->SiscomObtenNumRegistros())
	 QMessageBox::information(this,
	 			  "Aviso Del Sistema",
	 			  "Medico Ya Registrado");

}
