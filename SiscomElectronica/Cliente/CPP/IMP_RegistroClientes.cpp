#include <IMP_RegistroClientes.h>
#include <SiscomDesarrollo3Qt++.h>
#include <SiscomRegistros3.h>
#include <QSisDirecciones.h>
#include <CQSisPersonasProt3.h>
#include <QCtrlEscuelas.h>
#include <qpushbutton.h>
#include <qmessagebox.h>
#include <qlineedit.h>

QRegistroClientes *InstanciaRegistroClientes(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QRegistroClientes((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QRegistroClientes::QRegistroClientes(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				RegistroClientes(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos)
{
IniciaVariables();
ConectaSlots();
}

QRegistroClientes::~QRegistroClientes()
{

}

void QRegistroClientes::ConectaSlots()
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
		SLOT(SlotPasaFocoRegistraGenerales()));
	connect(QPBRGenerales,
		SIGNAL(clicked()),
		SLOT(SlotRegistraGenerales()));
	
}
void QRegistroClientes::SlotPasaFocoBoleta()
{
	SiscomDesarrollo3Qt::PasaFocoControl(QLEBoleta);
}
void QRegistroClientes::SlotRegistraGenerales()
{
RegistraGenerales();
}
void QRegistroClientes::SlotPasaFocoRegistraGenerales()
{
/*
	QDirecciones->setEnabled(true);
*/
	SiscomDesarrollo3Qt::PasaFocoControl(QPBRGenerales);
}
void QRegistroClientes::SlotEscuelas(SiscomRegistro3 *pSisReg3Escuela)
{
	SisReg3Escuela=pSisReg3Escuela;
	SiscomDesarrollo3Qt::PasaFocoControl(QLEGrupo);
}
void QRegistroClientes::SlotPasaFocoRegGenerales()
{
	SiscomDesarrollo3Qt::PasaFocoControl(QPBRGenerales);
}
void QRegistroClientes::SlotPasaFocoEscuelas()
{
	QCtrEscuelas->setFocus();
}

void QRegistroClientes::SlotPasaFocoAPaterno()
{
	SiscomDesarrollo3Qt::PasaFocoControl(QLEAPaterno);
}
void QRegistroClientes::SlotPasaFocoAMaterno()
{
	SiscomDesarrollo3Qt::PasaFocoControl(QLEAMaterno);
}
void QRegistroClientes::IniciaVariables()
{
	SiscomDesarrollo3Qt::PasaFocoControl(QLENombre);
	QDirecciones->Servidor(SisDatCom);
	QDirecciones->DatosServidor("ConsultasSiscomElectronica2",
				    "SepomexEstados");
	QDirecciones->IniciaControl();
	QCtrEscuelas->PonServidor(SisDatCom);
	QCtrEscuelas->IdExpendio(chrPtrArgumentos[0]);
	QCtrEscuelas->IniciaControl();
}

void QRegistroClientes::RegistraGenerales()
{
CQSisPersonasProt3 lCQSisPersonasProt3(SisDatCom);
  SisReg3Alumno=Alumno();
  lCQSisPersonasProt3.Registra("RegistraAlumno",
  			       SisReg3Alumno,
  			       &SisReg3LstRegAlumno); 
  SiscomContenidoRegistro3(SisReg3Alumno);
}

SiscomRegistro3 *QRegistroClientes::Alumno()
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
    SiscomDesarrollo3Qt::Campo3Edit("AMaterno",QLEAMaterno);

(*lSisReg3Persona)+=SisReg3Escuela;
return lSisReg3Persona;
}
void QRegistroClientes::closeEvent(QCloseEvent *)
{
emit SignalTerminar(this);
}
