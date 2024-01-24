#include <IMP_CentroMedico2.h>
#include <IMP_CentroMedico.h>
#include <IMP_BuscaPersonas.h>
#include <IMP_Expedientes.h>
#include<SISCOMComunicaciones++.h>
#include <Seguridad3Protocolo2.h>
#include <CQSisObjetos.h>
#include <QSisEstsMedico.h>
#include <CQSisPersonas.h>
QCentroMedico2 *InstanciaCentroMedico2(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QCentroMedico2((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QCentroMedico2::QCentroMedico2(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				CentroMedico2(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos),
				QWParent(pQWParent),
				QWCnsActual(0)
{
IniciaVariables();
ConectaSlots();
}

QCentroMedico2::~QCentroMedico2()
{

}

void QCentroMedico2::ConectaSlots()
{
	connect(QIVCnsActual,
		SIGNAL(clicked(QIconViewItem *)),
		SLOT(SlotConsultaActual(QIconViewItem *)));
	connect(QPBActualiza,
		SIGNAL(clicked()),
		SLOT(SlotActualiza()));
	connect(QPBExpedientes,
		SIGNAL(clicked()),
		SLOT(SlotExpedientes()));

}
void QCentroMedico2::SlotExpedientes()
{
CargaExpediente();
}
void QCentroMedico2::SlotActualiza()
{

ConsultasRegistradas();
EstadisticasMedico();
ConsultandoActuales();
}
void QCentroMedico2::SlotConsultaActual(QIconViewItem *pQIVIConsulta)
{
if(pQIVIConsulta)
{
if(QWCnsActual)
 QWCnsActual->close();
 QWCnsActual=((QIconViewCnsActual *)pQIVIConsulta)->ConsultaActual();
 QWCnsActual->show();
}
}
void QCentroMedico2::IniciaVariables()
{
SUSeg3Firmado=(SisUsuarioSeg3 *)chrPtrArgumentos[0];
ConsultasRegistradas();
EstadisticasMedico();
ConsultandoActuales();
}
void QCentroMedico2::ConsultandoActuales()
{
ConsultaActual();
MuestraConsultasActivas();

}
void QCentroMedico2::MuestraConsultasActivas()
{
CQSisConsulta *lCQSConsulta;
QCentroMedico *lQCMedico;
QIVCnsActual->clear();
for(lCQSConsulta=CQSLConsultasActual.first();
    lCQSConsulta;
    lCQSConsulta=CQSLConsultasActual.next())
{
lQCMedico=new QCentroMedico(
		lCQSConsulta,
		SisDatCom,
		chrPtrArgumentos,
		QWParent);

QIVCnsActual->insertItem(new QIconViewCnsActual(
			        lCQSConsulta,
				lQCMedico,
			        QIVCnsActual));
connect(lQCMedico,
	SIGNAL(SignalTerminar(QCentroMedico *)),
	SLOT(SlotTerminaConsulta(QCentroMedico *)));
}
}
void QCentroMedico2::SlotTerminaConsulta(QCentroMedico *pQCMedico)
{
delete pQCMedico;
IniciaVariables();
QWCnsActual=0;
}
void QCentroMedico2::EstadisticasMedico()
{

	QCtrEstsMedico->Servidor(SisDatCom);
	QCtrEstsMedico->IdMedico((*SUSeg3Firmado)["IdPersona"]);
	QCtrEstsMedico->IniciaControl();
}
void QCentroMedico2::ConsultaActual()
{
CQSisLstConsulta lCQSLCActual;
char lchrArrPaciente[125];
CQSisOpConsulta lCQSOConsulta(SisDatCom);
CQSLConsultasActual.clear();
lCQSOConsulta.ConsultaActualMedico(
		(*SUSeg3Firmado)["IdPersona"],
		&CQSLConsultasActual);
}

void QCentroMedico2::ConsultasRegistradas()
{
	ConsultaConsultas();
	MuestraConsultas();

}
void QCentroMedico2::ConsultaConsultas()
{
CQSisOpConsulta lCQSOConsulta(SisDatCom);
lCQSOConsulta.Consultas("ConsultasMedicoHoy",
			"",
			 "",
			 "",
			 (*SUSeg3Firmado)["IdPersona"],
			 &CQSLConsultas);
}
void QCentroMedico2::MuestraConsultas()
{
CQSisConsulta *lCQSConsulta;
int lintContador;
char lchrArrPaciente[125];
QTDatos->setNumRows(CQSLConsultas.count());
for(lCQSConsulta=CQSLConsultas.first(),
    lintContador=0;
    lCQSConsulta;
    lCQSConsulta=CQSLConsultas.next(),
    lintContador++)
{
CQSisObjetos::NombreCompleto(lCQSConsulta->Paciente(),lchrArrPaciente);
 SiscomAnexarRegistroALaTabla(
 	lintContador,
	QTDatos,
	QStringList() 			<<
	(*lCQSConsulta)["Fecha"] 	<<
	lchrArrPaciente			<<
	(*lCQSConsulta)["Estado"]);
	
}
SiscomAjustaColumnas(QTDatos);
}
void QCentroMedico2::CargaExpediente()
{
CQSisBuscaPersona *lCQBPersona;
QBuscaPersonas lQBPPaciente(SisDatCom,
			   chrPtrArgumentos);

if((lCQBPersona=lQBPPaciente.PersonaSeleccionada()))
{
  CQSPPaciente=new CQSisPersona(
  			(*lCQBPersona)["IdPersona"],
			(*lCQBPersona)["Nombre"],
			(*lCQBPersona)["APaterno"],
			(*lCQBPersona)["AMaterno"],
			"",
			"",
			"",
			"",
			"");
 QEExpedientes=new QExpedientes(
 			SisDatCom,
			chrPtrArgumentos,
			QWParent);
connect(QEExpedientes,
	SIGNAL(SignalCerroExpediente(CQSisPersona *)),
	SLOT(SlotCerroExpediente(CQSisPersona *)));
QEExpedientes->Paciente(CQSPPaciente);
QEExpedientes->Expediente();
}
}
void QCentroMedico2::SlotCerroExpediente(CQSisPersona *pCQSPaciente)
{
	delete QEExpedientes;
	QEExpedientes=0;
	delete pCQSPaciente;
}
QIconViewCnsActual::QIconViewCnsActual(CQSisConsulta *pCQSConsulta,
				       QWidget *pQWCnsActual,
				       QIconView *pQIVParent):
				QIconViewItem(pQIVParent),
				QWCnsActual(pQWCnsActual),
				CQSConsulta(pCQSConsulta)
{
char lchrArrPaciente[150];
CQSisObjetos::NombreCompleto(CQSConsulta->Paciente(),lchrArrPaciente);
setText(lchrArrPaciente);
}

QWidget *QIconViewCnsActual::ConsultaActual()
{
return QWCnsActual;
}

