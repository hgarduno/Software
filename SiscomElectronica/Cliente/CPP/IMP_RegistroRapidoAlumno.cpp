#include <IMP_RegistroRapidoAlumno.h>
#include <SiscomDesarrollo3Qt++.h>
#include <QCtrlEscuelas.h>

#include <CQSisPersonasProt3.h>

#include <qlineedit.h>
#include <qpushbutton.h>
QRegistroRapidoAlumno *InstanciaRegistroRapidoAlumno(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QRegistroRapidoAlumno((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QRegistroRapidoAlumno::QRegistroRapidoAlumno(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				RegistroRapidoAlumno(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos)
{
IniciaVariables();
ConectaSlots();
show();
}

QRegistroRapidoAlumno::~QRegistroRapidoAlumno()
{

}

void QRegistroRapidoAlumno::ConectaSlots()
{

	connect(QLENombre,
		SIGNAL(returnPressed()),
		SLOT(SlotPasaFocoAPaterno()));
	connect(QLEAPaterno,
		SIGNAL(returnPressed()),
		SLOT(SlotPasaFocoAMaterno()));
	connect(QLEAMaterno,
		SIGNAL(returnPressed()),
		SLOT(SlotPasaFocoEscuelas()));

	connect(QLEGrupo,
		SIGNAL(returnPressed()),
		SLOT(SlotPasaFocoBoleta()));
	connect(QCtrEscuelas,
		SIGNAL(SignalEscuelas(SiscomRegistro3 *)),
		SLOT(SlotEscuelas(SiscomRegistro3 *)));
	connect(QLEBoleta,
		SIGNAL(returnPressed()),
		SLOT(SlotPasaFocoCorreo()));
	connect(QLECorreo,
		SIGNAL(returnPressed()),
		SLOT(SlotPasaFocoCelular()));
	connect(QLECelular,
		SIGNAL(returnPressed()),
		SLOT(SlotPasaFocoTCasa()));
	connect(QLETCasa,
		SIGNAL(returnPressed()),
		SLOT(SlotPasaFocoRegistraGenerales()));

	connect(QPBRegistrar,
		SIGNAL(clicked()),
		SLOT(SlotRegistra()));

}
void QRegistroRapidoAlumno::IniciaVariables()
{

	QCtrEscuelas->PonServidor(SisDatCom);
	QCtrEscuelas->IdExpendio(chrPtrArgumentos[0]);
	QCtrEscuelas->IniciaControl();
}
void QRegistroRapidoAlumno::SlotPasaFocoCorreo()
{
SiscomDesarrollo3Qt::PasaFocoControl(QLECorreo);
}
void QRegistroRapidoAlumno::SlotPasaFocoCelular()
{
SiscomDesarrollo3Qt::PasaFocoControl(QLECelular);
}
void QRegistroRapidoAlumno::SlotPasaFocoTCasa()
{
SiscomDesarrollo3Qt::PasaFocoControl(QLETCasa);
}
void QRegistroRapidoAlumno::SlotPasaFocoBoleta()
{
	SiscomDesarrollo3Qt::PasaFocoControl(QLEBoleta);
}
void QRegistroRapidoAlumno::SlotRegistra()
{
Registra();
  emit SignalRegistroAlumno(QLEBoleta->text());
}
void QRegistroRapidoAlumno::SlotPasaFocoRegistraGenerales()
{
	SiscomDesarrollo3Qt::PasaFocoControl(QPBRegistrar);
}
void QRegistroRapidoAlumno::SlotEscuelas(SiscomRegistro3 *pSisReg3Escuela)
{
	SisReg3Escuela=pSisReg3Escuela;
	SiscomDesarrollo3Qt::PasaFocoControl(QLEGrupo);
}
void QRegistroRapidoAlumno::SlotPasaFocoRegGenerales()
{
	SiscomDesarrollo3Qt::PasaFocoControl(QPBRegistrar);
}
void QRegistroRapidoAlumno::SlotPasaFocoEscuelas()
{
	QCtrEscuelas->setFocus();
}

void QRegistroRapidoAlumno::SlotPasaFocoAPaterno()
{
	SiscomDesarrollo3Qt::PasaFocoControl(QLEAPaterno);
}
void QRegistroRapidoAlumno::SlotPasaFocoAMaterno()
{
	SiscomDesarrollo3Qt::PasaFocoControl(QLEAMaterno);
}
void QRegistroRapidoAlumno::setFocus()
{
   SiscomDesarrollo3Qt::PasaFocoControl(QLENombre);

}
void QRegistroRapidoAlumno::Registra()
{

CQSisPersonasProt3 lCQSisPersonasProt3(SisDatCom);
  SisReg3Alumno=Alumno();
  lCQSisPersonasProt3.Registra("RegistraAlumno",
  			       SisReg3Alumno,
  			       &SisReg3LstRegAlumno); 
  SiscomContenidoRegistro3(SisReg3Alumno);
}

SiscomRegistro3 *QRegistroRapidoAlumno::Alumno()
{
SiscomRegistro3 *lSisReg3Persona=new SiscomRegistro3;

(*lSisReg3Persona)						<<
new SiscomCampo3("IdPersona","") 				<<
new SiscomCampo3("EdoRegistro","") 				<<
new SiscomCampo3("IdExpendio",chrPtrArgumentos[0])		<<
    SiscomDesarrollo3Qt::Campo3Edit("Boleta",QLEBoleta)		<<
    SiscomDesarrollo3Qt::Campo3Edit("Grupo",QLEGrupo)		<<
    SiscomDesarrollo3Qt::Campo3Edit("Nombre",QLENombre)		<<
    SiscomDesarrollo3Qt::Campo3Edit("APaterno",QLEAPaterno)	<<
    SiscomDesarrollo3Qt::Campo3Edit("AMaterno",QLEAMaterno)	<<
    SiscomDesarrollo3Qt::Campo3Edit("Correo",QLECorreo)		<<
    SiscomDesarrollo3Qt::Campo3Edit("Celular",QLECelular)	<<
    SiscomDesarrollo3Qt::Campo3Edit("Telefono",QLETCasa);

(*lSisReg3Persona)+=SisReg3Escuela;
return lSisReg3Persona;
}
