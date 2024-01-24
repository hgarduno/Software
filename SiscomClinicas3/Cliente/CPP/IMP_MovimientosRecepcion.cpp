#include <IMP_MovimientosRecepcion.h>
#include<SISCOMComunicaciones++.h>
#include <IMP_QControlFecha.h>
#include <QCtrlPersonas.h>
#include <CQSisObjetos.h>
#include <CQSisPersonas.h>
QMovimientosRecepcion *InstanciaMovimientosRecepcion(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QMovimientosRecepcion((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QMovimientosRecepcion::QMovimientosRecepcion(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				MovimientosRecepcion(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos),
				CQSMedico(0)
{
IniciaVariables();
ConectaSlots();
}

QMovimientosRecepcion::~QMovimientosRecepcion()
{

}

void QMovimientosRecepcion::ConectaSlots()
{

	connect(QPBConsulta,
		SIGNAL(clicked()),
		SLOT(SlotConsulta()));
	connect(QPBPorMedico,
		SIGNAL(clicked()),
		SLOT(SlotPorMedico()));
	connect(QCtrMedicos,
		SIGNAL(SignalPersona(CQSisPersona *)),
		SLOT(SlotMedico(CQSisPersona *)));
}
void QMovimientosRecepcion::SlotPorMedico()
{
	ConsultasRegistradas();
}
void QMovimientosRecepcion::SlotMedico(CQSisPersona *pCQSMedico)
{
	CQSMedico=pCQSMedico;
}
void QMovimientosRecepcion::SlotConsulta()
{
	CQSMedico=0;
	ConsultasRegistradas();
}
void QMovimientosRecepcion::IniciaVariables()
{

	 QCtrFechaIni->ColocaFechaHoy();
	 QCtrFechaFin->ColocaFechaHoy();
	 QCtrMedicos->PonServidor(SisDatCom);
	 QCtrMedicos->NombrePerfil("Medicos");
	 QCtrMedicos->IniciaControl();
	 ConsultasRegistradas();
}


void QMovimientosRecepcion::ConsultasRegistradas()
{
char lchrArrBuffer[512];
if(CQSMedico)
{
sprintf(lchrArrBuffer,
	"PorMedico%s",
	(*CQSMedico)["IdPersona"]);
}
else
{
lchrArrBuffer[0]=0;
}
ConsultaConsultas(strdup((const char *)QCtrFechaIni->ObtenFecha()),
		  strdup((const char *)QCtrFechaFin->ObtenFecha()),
		  lchrArrBuffer,
		  "");
MuestraConsultas();
}

void QMovimientosRecepcion::MuestraConsultas()
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

void QMovimientosRecepcion::ConsultaConsultas(const char *pchrPtrFechaIni,
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
