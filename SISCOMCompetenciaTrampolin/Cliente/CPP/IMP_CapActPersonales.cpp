#include <IMP_CapActPersonales.h>
#include <IMP_QControlFecha.h>
#include <IMP_CapturaCorreo.h>
#include <IMP_CapturaTelefono.h>
#include <IMP_CapturaDireccion.h>
#include<SISCOMComunicaciones++.h>
#include <CQSisEntrenadores.h>
#include <CQSisOperaciones.h>
#include <CQSisConsultas.h>

#include <qpushbutton.h>

QCapActPersonales::QCapActPersonales(CQSisEntrenador *pCQSEPersona,
				    SiscomDatCom *pSisDatCom, 
				    const char *pchrPtrPersona,
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    bool pbModal,
				    WFlags pWFlags):	      
				CapActPersonales(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrPersona(pchrPtrPersona),
				CQSEPersona(pCQSEPersona)
{
IniciaVariables();
ConectaSlots();
exec();
}

QCapActPersonales::~QCapActPersonales()
{

}

void QCapActPersonales::ConectaSlots()
{

	connect(QLENombre,
		SIGNAL(returnPressed()),
		SLOT(SlotPasaFocoAPaterno()));
	connect(QLEAPaterno,
		SIGNAL(returnPressed()),
		SLOT(SlotPasaFocoAMaterno()));
	connect(QLEAMaterno,
		SIGNAL(returnPressed()),
		SLOT(SlotPasaFocoFechaNac()));
	connect(QPBAGenerales,
		SIGNAL(clicked()),
		SLOT(SlotActualizaGenerales()));
	connect(QPBATelefono,
		SIGNAL(clicked()),
		SLOT(SlotAnexarTelefono()));
	connect(QPBACorreo,
		SIGNAL(clicked()),
		SLOT(SlotAnexarCorreo()));
	connect(QPBADireccion,
		SIGNAL(clicked()),
		SLOT(SlotAnexarDireccion()));

}
void QCapActPersonales::SlotAnexarDireccion()
{
QCapturaDireccion lQCDireccion(SisDatCom,
				CQSEPersona);
}
void QCapActPersonales::SlotAnexarTelefono()
{
QCapturaTelefono lCQCTelefono(SisDatCom,
			      CQSEPersona);
	if(lCQCTelefono.SeAnexo())
	ConsultandoMedios();
}

void QCapActPersonales::SlotAnexarCorreo()
{
QCapturaCorreo lCQCCorreo(SisDatCom,
			  CQSEPersona);
}
void QCapActPersonales::SlotActualizaGenerales()
{
CQSisOperaciones lCQSOActNombre(SisDatCom);
	lCQSOActNombre.ActualizaDatosGenerales(
			CQSEPersona,
			SiscomObtenInformacionDelEdit(QLENombre),
			SiscomObtenInformacionDelEdit(QLEAPaterno),
			SiscomObtenInformacionDelEdit(QLEAMaterno),
			(const char *)QCtrFechaNac->ObtenFecha());
}
void QCapActPersonales::SlotPasaFocoAPaterno()
{
	SiscomPasaFocoControl(QLEAPaterno);
}
void QCapActPersonales::SlotPasaFocoAMaterno()
{
	SiscomPasaFocoControl(QLEAMaterno);
}
void QCapActPersonales::SlotPasaFocoFechaNac()
{
	QCtrFechaNac->setFocus();	
}
void QCapActPersonales::IniciaVariables()
{
	QLENombre->setFocus();
	MuestraGenerales();
	ConsultandoMedios();
	ConsultaDirecciones();
	MuestraDirecciones();
}
void QCapActPersonales::MuestraGenerales()
{
	QLENombre->setText(CQSEPersona->SRegistrosPro2["Nombre"]);
	QLEAPaterno->setText(CQSEPersona->SRegistrosPro2["APaterno"]);
	QLEAMaterno->setText(CQSEPersona->SRegistrosPro2["AMaterno"]);
	//QCtrFechaNac->PonFecha(CQSEPersona->SRegistrosPro2["FechaNac"]);
}

void QCapActPersonales::ConsultaMedios()
{
SLMCom.clear();
CQSisOpConsultas lCQSOConsultas(SisDatCom);
	lCQSOConsultas.ConsultaMediosPersona(CQSEPersona,&SLMCom);

}
void QCapActPersonales::MuestraMedios()
{
int lintContador;
SisMedCom *lSMCom;
	QTMedios->setNumRows(SLMCom.count());
	for(lintContador=0,
	    lSMCom=SLMCom.first();
	    lSMCom;
	    lintContador++,
	    lSMCom=SLMCom.next())
	 SiscomAnexarRegistroALaTabla(
	 	lintContador,
		QTMedios,
		QStringList ()			<<
		lSMCom->SRegistrosPro2["Medio"]	<<
		lSMCom->SRegistrosPro2["Dato"]	<<
		lSMCom->SRegistrosPro2["Descripcion"]);
	SiscomAjustaColumnas(QTMedios);
}
void QCapActPersonales::ConsultaDirecciones()
{
CQSisOpConsultas lCQSOConsultas(SisDatCom);
	lCQSOConsultas.DireccionesPersona(CQSEPersona,&SLDireccion);
}
void QCapActPersonales::MuestraDirecciones()
{
SisDireccion *lSDireccion;
int lintContador;
	QTDirecciones->setNumRows(SLDireccion.count());
	for(lintContador=0,
	    lSDireccion=SLDireccion.first();
	    lSDireccion;
	    lintContador++,
	    lSDireccion=SLDireccion.next())
	 SiscomAnexarRegistroALaTabla(
	 		lintContador,
			QTDirecciones,
			QStringList () 				<<
			lSDireccion->SRegistrosPro2["Calle"]	<<
			lSDireccion->SRegistrosPro2["Numero"]);
}
void QCapActPersonales::ConsultandoMedios()
{
	ConsultaMedios();
	MuestraMedios();
}
