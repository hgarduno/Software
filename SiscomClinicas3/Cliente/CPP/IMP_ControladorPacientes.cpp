#include <IMP_ControladorPacientes.h>
#include <IMP_PersonasSimilares.h>
#include <QCtrlFechaHora.h>
#include<SISCOMComunicaciones++.h>

#include <Seguridad3Protocolo2.h>
#include <QCtrlPersonas.h>
#include <QCtrlPrecios.h>
#include <QSisSepomex.h>
#include <QSisDirecciones.h>
#include <QSisTelefonos.h>
#include <CQSisConsultas.h>
#include <CQSisCotizando.h>
#include <CQSisPrecios.h>

#include <qpushbutton.h>
#include <qmessagebox.h>
#include <qlcdnumber.h>
#include <qtabwidget.h>

QControladorPacientes::QControladorPacientes(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    bool pbModal,
				    WFlags pWFlags):	      
				ControladorPacientes(pQWParent,pchrPtrName,pbModal,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos),
				chrPtrIdPaciente(0),
				CQSPMedico(0)

{
IniciaVariables();
ConectaSlots();
IniciaPrecios();
exec();
}

QControladorPacientes::~QControladorPacientes()
{

}

void QControladorPacientes::ConectaSlots()
{
	connect(QCtrMedicos,
		SIGNAL(SignalPersona(CQSisPersona *)),
		SLOT(SlotMedico(CQSisPersona *)));
	connect(QLENombree,
		SIGNAL(returnPressed()),
		SLOT(SlotPasaFocoAPaterno()));
	connect(QLEAPaternoo,
		SIGNAL(returnPressed()),
		SLOT(SlotPasaFocoAMaterno()));
	
	connect(QLEAMaternoo,
		SIGNAL(returnPressed()),
		SLOT(SlotPasaFocoRFC()));
	connect(QLERFCC,
		SIGNAL(returnPressed()),
		SLOT(SlotPasaFocoRegistraGenerales()));
	connect(QPBRGenerales,
		SIGNAL(clicked()),
		SLOT(SlotRegistraGenerales()));
	connect(QPBRConsulta,
		SIGNAL(clicked()),
		SLOT(SlotRegistraConsulta()));
	connect(QCtrPrecios,
		SIGNAL(SignalPrecio(CQSisPrecio *)),
		SLOT(SlotPrecio(CQSisPrecio *)));
	connect(QCtrFechaHora,
		SIGNAL(Signal_EnterMinuto()),
		SLOT(SlotPasaFocoNombre()));

}
void QControladorPacientes::SlotPasaFocoNombre()
{
	SiscomPasaFocoControl(QLENombree);
}
void QControladorPacientes::SlotPrecio(CQSisPrecio *pCQSPrecio)
{
	CQSPrecio=pCQSPrecio;
}
void QControladorPacientes::SlotRegistraConsulta()
{
	RegistraConsulta();
	done(1);
}

void QControladorPacientes::SlotPasaFocoAPaterno()
{
	SiscomPasaFocoControl(QLEAPaternoo);
	HabilitaRegistraConsulta();
}
void QControladorPacientes::SlotPasaFocoAMaterno()
{
	SiscomPasaFocoControl(QLEAMaternoo);
	HabilitaRegistraConsulta();
}
void QControladorPacientes::SlotPasaFocoRFC()
{
	SiscomPasaFocoControl(QLERFCC);
	HabilitaRegistraConsulta();
}
void QControladorPacientes::SlotPasaFocoRegistraGenerales()
{
	SiscomPasaFocoControl(QPBRGenerales);
}
void QControladorPacientes::SlotMedico(CQSisPersona *pCQSPersona)
{
	CQSPMedico=pCQSPersona;
	ConsultasPendientesMedico();
	CotizaPerfilMedico();
	SiscomPasaFocoControl(QLENombree);

	QPBRConsulta->setEnabled(CQSPMedico 				&&
				 chrPtrIdPaciente); 
	QCtrFechaHora->setFocus();
}
void QControladorPacientes::SlotRegistraGenerales()
{
	RegistraGenerales();
	if(!QLENoPaciente->text().isEmpty())
	{
	QCtrSDirecciones->Sepomex()->setEnabled(true);
	QCtrSDirecciones->SistemaConsulta("ConsultasClinicas3");
	QCtrSDirecciones->IdPersona(chrPtrIdPaciente);
	QCtrSDirecciones->DireccionesPersona();
	QCtrTelefonos->SistemaConsulta("ConsultasClinicas3");
	QCtrTelefonos->IdPersona(chrPtrIdPaciente);
	QCtrTelefonos->TelefonosRegistrados();
	QTWDatos->setFocus();
	QCtrSDirecciones->setFocus();
	}


}
void QControladorPacientes::IniciaVariables()
{
	 QCtrMedicos->PonServidor(SisDatCom);
	 QCtrMedicos->NombrePerfil("Medicos");
	 QCtrMedicos->IniciaControl();
	 SUSeg3Firmado=(SisUsuarioSeg3 *)chrPtrArgumentos[0];
	 QCtrSDirecciones->Sepomex()->setEnabled(false);
	 QCtrSDirecciones->Servidor(SisDatCom);
	 QCtrSDirecciones->IniciaControl();
	 QCtrTelefonos->Servidor(SisDatCom);
	 QCtrFechaHora->ColocaFechaHoy();
	 QCtrMedicos->setFocus();
}

CQSisPersona *QControladorPacientes::Paciente()
{
return new CQSisPersona("",
			SiscomObtenInformacionDelEdit(QLENombree),
			SiscomObtenInformacionDelEdit(QLEAPaternoo),
			SiscomObtenInformacionDelEdit(QLEAMaternoo),
			SiscomObtenInformacionDelEdit(QLERFCC),
			"",
			"",
			"",
			"2");
}
void QControladorPacientes::RegistraGenerales()
{
if((chrPtrIdPaciente=ChecaPacientesSimilares()))
{

QLENoPaciente->setText(chrPtrIdPaciente);
QPBRGenerales->setEnabled(false);
QPBRConsulta->setEnabled(CQSPMedico 				&&
			 chrPtrIdPaciente); 
}
else
{
SiscomRegistrosPro2 *lSRegistrosPro2;
CQSisOpPersona lCQSOPersona(SisDatCom);
lCQSOPersona.Paciente(Paciente(),&lSRegistrosPro2);
EstadoRegistroPaciente(lSRegistrosPro2);
}
}
const char *QControladorPacientes::ChecaPacientesSimilares()
{
SiscomRegistrosPro2 *lSRegistrosPro2;
CQSisOpPersona lCQSOPersona(SisDatCom);
lCQSOPersona.PacientesSimilares(Paciente(),&lSRegistrosPro2);
if(lSRegistrosPro2->SiscomObtenNumRegistros()>1)
{
QPersonasSimilares lQPSimilares(lSRegistrosPro2,
				SisDatCom,
				chrPtrArgumentos);
return lQPSimilares.IdPersona();
}
return 0;
}
void QControladorPacientes::EstadoRegistroPaciente(SiscomRegistrosPro2 *pSRegistrosPro2)
{
if(pSRegistrosPro2->SiscomObtenNumRegistros())
{
QLENoPaciente->setText((chrPtrIdPaciente=(*pSRegistrosPro2)["IdPersona"]));
QPBRGenerales->setEnabled(false);
QPBRConsulta->setEnabled(CQSPMedico 				&&
			 chrPtrIdPaciente); 
}
else
QMessageBox::information(this,
			 "Aviso Del Sistem",
			 "Error al Registrar El Paciente");
}
void QControladorPacientes::RegistraConsulta()
{
SiscomRegistrosPro2 *lSRegistrosPro2;
CQSisOpConsulta lCQSOConsulta(SisDatCom);
lCQSOConsulta.Consulta(new CQSisConsulta(
				"",
				CQSPMedico->SRegistrosPro2["IdPersona"],
				SUSeg3Firmado->SRegistrosPro2["IdPersona"],
				chrPtrIdPaciente,
				strdup((const char *)QCtrFechaHora->ObtenFechaHora()),
				"1"),
			 &lSRegistrosPro2);
}
void QControladorPacientes::ConsultasPendientesMedico()
{
const char *lchrPtrFecha;
char lchrArrNoCnsPendientes[20];
CQSisOpConsulta lCQSOConsultas(SisDatCom);
lCQSOConsultas.ConsultasPendientesMedico(
   CQSPMedico->SRegistrosPro2["IdPersona"],
   (lchrPtrFecha=strdup((const char *)QCtrFechaHora->ObtenFechaHora())),
    lchrPtrFecha,
    lchrArrNoCnsPendientes);
QLCDNCnsPendientes->display(lchrArrNoCnsPendientes);
}

void QControladorPacientes::CotizaPerfilMedico()
{
CQSisLstCotizando lCQSLCotizando;
CQSisOpCotizando lCQSOCotizando(SisDatCom);
lCQSOCotizando.CotizaPerfilMedico((*CQSPMedico)["IdPersona"],
				  (*CQSPrecio)["IdPrecio"],
				  &lCQSLCotizando);
QLCDNTConsulta->display(lCQSLCotizando.ImporteTotal());
}

void QControladorPacientes::IniciaPrecios()
{
	 QCtrPrecios->PonServidor(SisDatCom);
	 QCtrPrecios->IniciaControl();
}

void QControladorPacientes::HabilitaRegistraConsulta()
{
	QPBRConsulta->setEnabled(CQSPMedico 				&&
				 chrPtrIdPaciente); 

	QPBRGenerales->setEnabled(!QLENombree->text().isEmpty()		&&
				  !QLEAPaternoo->text().isEmpty()	&&
				  !QLEAMaternoo->text().isEmpty());
}
