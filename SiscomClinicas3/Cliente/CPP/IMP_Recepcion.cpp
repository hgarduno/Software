#include <IMP_Recepcion.h>
#include <IMP_Cobra.h>
#include <IMP_QControlFecha.h>
#include<SISCOMComunicaciones++.h>
#include <Seguridad3Protocolo2.h>
#include <QCtrlPersonas.h>
#include <QCtrlPrecios.h>
#include <CQSisConsultas.h>
#include <CQSisPersonas.h>
#include <CQSisObjetos.h>
#include <CQSisEstadoConsulta.h>
#include <CQSisCotizando.h>
#include <CQSisPrecios.h>
#include <IMP_ControladorPacientes.h>
#include <qpushbutton.h>
#include <qlcdnumber.h>
#include <qmessagebox.h>
QRecepcion *InstanciaRecepcion(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QRecepcion((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QRecepcion::QRecepcion(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				Recepcion(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos),
				CQSConsulta(0)
{
IniciaVariables();
ConectaSlots();
IniciaPrecios();
}

QRecepcion::~QRecepcion()
{

}

void QRecepcion::ConectaSlots()
{
	connect(QPBRegistro,
		SIGNAL(clicked()),
		SLOT(SlotRegistraPaciente()));
	connect(QCtrMedicos,
		SIGNAL(SignalPersona(CQSisPersona *)),
		SLOT(SlotMedico(CQSisPersona *)));
	connect(QTDatos,
		SIGNAL(clicked(int,int,int,const QPoint &)),
		SLOT(SlotMarcaConsulta(int,int,int,const QPoint &)));
	connect(QPBPConsulta,
		SIGNAL(clicked()),
		SLOT(SlotPasaPaciente()));
	connect(QCtrPrecios,
		SIGNAL(SignalPrecio(CQSisPrecio *)),
		SLOT(SlotPrecio(CQSisPrecio *)));
	connect(QPBCobrar,
		SIGNAL(clicked()),
		SLOT(SlotCobrar()));
	connect(QPBActualizar,
		SIGNAL(clicked()),
		SLOT(SlotActualizar()));
	connect(QPBEliminar,
		SIGNAL(clicked()),
		SLOT(SlotEliminar()));
	connect(QPBHospitaliza,
		SIGNAL(clicked()),
		SLOT(SlotHospitalizar()));

}
void QRecepcion::SlotHospitalizar()
{

  if(CQSConsulta)
  {
     Hospitalizar();
     ConsultasRegistradas();
     CQSConsulta=0;
  }
  else
QMessageBox::information(this,
			 "Siscom Clinicas3",
			 "Debe seleccionar una consulta");

}
void QRecepcion::SlotEliminar()
{
  if(CQSConsulta)
  {
     EliminaConsulta();
     ConsultasRegistradas();
     CQSConsulta=0;
  }
  else
QMessageBox::information(this,
			 "Siscom Clinicas3",
			 "Debe seleccionar una consulta");


}
void QRecepcion::SlotActualizar()
{
ConsultasRegistradas();
}
void QRecepcion::SlotCobrar()
{
if(CQSConsulta)
{
Cobrar();
CQSConsulta=0;
}
else
QMessageBox::information(this,
			 "Siscom Clinicas3",
			 "Debe seleccionar una consulta");
ConsultasRegistradas();
}
void QRecepcion::SlotPrecio(CQSisPrecio *pCQSPrecio)
{
	CQSPrecio=pCQSPrecio;
}
void QRecepcion::SlotPasaPaciente()
{
if(CQSConsulta)
{
PasaPaciente();
ConsultasRegistradas();
CQSConsulta=0;
}
else
QMessageBox::information(
		this,
		"Siscom Clinicas3",
		"No Se ha seleccionado a ningun paciente");
}
void QRecepcion::SlotMarcaConsulta(int pintNConsulta,
				   int,
				   int,
				   const QPoint &)
{
if(pintNConsulta!=-1) 
{
CQSConsulta=CQSLCRegistradas.at(pintNConsulta);
QTDatos->selectRow(pintNConsulta);
}
}
void QRecepcion::SlotMedico(CQSisPersona *pCQSisPersona)
{
	CQSPMedico=pCQSisPersona;
	ConsultasPendientesMedico();
	CotizaPerfilMedico();
}
void QRecepcion::SlotRegistraPaciente()
{
QControladorPacientes lQCPacientes(SisDatCom,
				   chrPtrArgumentos);
ConsultasRegistradas();
}
void QRecepcion::IniciaVariables()
{
	 QCtrFechaIni->ColocaFechaHoy();
	 QCtrFechaFin->ColocaFechaHoy();
	 QCtrMedicos->PonServidor(SisDatCom);
	 QCtrMedicos->NombrePerfil("Medicos");
	 QCtrMedicos->IniciaControl();
	 SUSeg3Firmado=(SisUsuarioSeg3 *)chrPtrArgumentos[0];
	 ConsultasRegistradas();
}
void QRecepcion::IniciaPrecios()
{
	 QCtrPrecios->PonServidor(SisDatCom);
	 QCtrPrecios->IniciaControl();
}

void QRecepcion::ConsultasPendientesMedico()
{
char lchrArrNoCnsPendientes[10];
CQSisOpConsulta lCQSOConsultas(SisDatCom);
lCQSOConsultas.ConsultasPendientesMedico(
		CQSPMedico->SRegistrosPro2["IdPersona"],
		strdup((const char *)QCtrFechaIni->ObtenFecha()),
		strdup((const char *)QCtrFechaFin->ObtenFecha()),
		lchrArrNoCnsPendientes);
QLCDNCnsPendientes->display(lchrArrNoCnsPendientes);
}
void QRecepcion::ConsultaConsultas(const char *pchrPtrFechaIni,
				   const char *pchrPtrFechaFin,
				   const char *pchrPtrEstado,
				   const char *pchrPtrIdMedico)
{
CQSisOpConsulta lCQSOConsulta(SisDatCom);
lCQSOConsulta.Consultas("ConsultasHoyPorEstado",
			pchrPtrFechaIni,
		        pchrPtrFechaFin,
			pchrPtrEstado,
			pchrPtrIdMedico,
			&CQSLCRegistradas);
}
void QRecepcion::ConsultasRegistradas()
{
ConsultaConsultas(strdup((const char *)QCtrFechaIni->ObtenFecha()),
		  strdup((const char *)QCtrFechaFin->ObtenFecha()),
		  "En Espera|Terminada",
		  "");
MuestraConsultas();
}
void QRecepcion::MuestraConsultas()
{
int lintContador;
CQSisConsulta *lCQSConsulta;
char lchrArrPaciente[125];
char lchrArrMedico[125];
QTDatos->setNumRows(CQSLCRegistradas.count());
for(lCQSConsulta=CQSLCRegistradas.first(),
    lintContador=0;
    lCQSConsulta;
    lCQSConsulta=CQSLCRegistradas.next(),
    lintContador++)
{
CQSisObjetos::NombreCompleto(lCQSConsulta->Paciente(),lchrArrPaciente);
CQSisObjetos::NombreCompleto(lCQSConsulta->Medico(),lchrArrMedico);
SiscomAnexarRegistroALaTabla(
	lintContador,
	QTDatos,
	QStringList() <<
	(*lCQSConsulta)["Fecha"]	<<
	(*lCQSConsulta)["NoConsulta"]	<<
	lchrArrPaciente			<<
	lchrArrMedico			<<
	(*lCQSConsulta)["Estado"]);
}
SiscomAjustaColumnas(QTDatos);
}
void QRecepcion::PasaPaciente()
{
if(!strcmp((*CQSConsulta)["IdEdo"],"1"))
{
SiscomRegistrosPro2 *lSRegistrosPro2;
CQSisOpEstadoConsulta lCQSOEConsulta(SisDatCom);
lCQSOEConsulta.EstadoConsulta(
		new CQSisEstadoConsulta(
		      (*CQSConsulta)["IdConsulta"],
		      "2",
		      (*SUSeg3Firmado)["IdPersona"],
		      ""),
		&lSRegistrosPro2);
}
else
QMessageBox::information(this,
			 "Siscom Clinicas3",
			 "No se puede pasar a un paciente que no este en espera");
}

void QRecepcion::CotizaPerfilMedico()
{
CQSisLstCotizando lCQSLCotizando;
CQSisOpCotizando lCQSOCotizando(SisDatCom);
lCQSOCotizando.CotizaPerfilMedico((*CQSPMedico)["IdPersona"],
				  (*CQSPrecio)["IdPrecio"],
				  &lCQSLCotizando);
QLCDNTConsulta->display(lCQSLCotizando.ImporteTotal());
}
void QRecepcion::Cobrar()
{
if(!strcmp((*CQSConsulta)["IdEdo"],"7"))
{
QCobra lQCobra(CQSConsulta,
	       SisDatCom,
	       chrPtrArgumentos);
}
else
QMessageBox::information(this,
			 "Siscom Clinicas3",
			 "No se puede cobrar la consulta, si no ha terminado el medico");
}
void QRecepcion::EliminaConsulta()
{
CQSisOpEstadoConsulta lCQSOEConsulta(SisDatCom);
SiscomRegistrosPro2 *lSRegistrosPro2;
lCQSOEConsulta.EstadoConsulta(
		new CQSisEstadoConsulta((*CQSConsulta)["IdConsulta"],
					"6",
					(*SUSeg3Firmado)["IdPersona"],
					""),
		&lSRegistrosPro2);
}

void QRecepcion::Hospitalizar()
{
CQSisOpEstadoConsulta lCQSOEConsulta(SisDatCom);
SiscomRegistrosPro2 *lSRegistrosPro2;
lCQSOEConsulta.EstadoConsulta(
		new CQSisEstadoConsulta((*CQSConsulta)["IdConsulta"],
					"8",
					(*SUSeg3Firmado)["IdPersona"],
					""),
		&lSRegistrosPro2);

}
