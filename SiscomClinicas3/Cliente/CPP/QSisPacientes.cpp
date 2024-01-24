#include <Seguridad3Protocolo2.h>
#include <QSisPacientes.h>
#include <CQSisPersonas.h>
#include <CQSisObjetos.h>
#include <CQSisPersonas.h>
#include <qiconview.h>


QSisPacientes::QSisPacientes(QWidget *pQWParent,
			     const char *pchrPtrName):
		QWidget(pQWParent,pchrPtrName)
{
	IniciaVariables();
	ConectaSlots();

}
void QSisPacientes::RangoFechas(const char *pchrPtrFechaIni,
				const char *pchrPtrFechaFin)
{
	chrPtrFechaIni=pchrPtrFechaIni;
	chrPtrFechaFin=pchrPtrFechaFin;
}
void QSisPacientes::Servidor(SiscomDatCom *pSisDatCom)
{
	SisDatCom=pSisDatCom;
}
void QSisPacientes::IniciaControl()
{
ConsultandoHospitalizados();
}

void QSisPacientes::Medico(CQSisPersona *pCQSPMedico)
{

}
void QSisPacientes::AnexaEstadoConsulta(const char *pchrPtrEdoConsulta)
{


}
void QSisPacientes::ConectaSlots()
{
   connect(QIVPacientes,
   	   SIGNAL(clicked(QIconViewItem *)),
	   SLOT(SlotConsulta(QIconViewItem *)));
}
void QSisPacientes::SlotConsulta(QIconViewItem *pQIVIConsulta)
{
if(pQIVIConsulta)
{
QSisIconViewItemConsulta *lQSIVIConsulta=(QSisIconViewItemConsulta *)pQIVIConsulta;
emit SignalConsulta(lQSIVIConsulta->Consulta());
}
}
void QSisPacientes::IniciaVariables()
{
	IniciaInterfaz();

}
void QSisPacientes::IniciaInterfaz()
{
	QHBLayout=new QHBoxLayout(this);
	QHBLayout->setMargin(0);
	QIVPacientes=new QIconView(this);
	QHBLayout->addWidget(QIVPacientes);
}

void QSisPacientes::ConsultandoHospitalizados()
{
	ConsultaHospitalizados();
	MuestraHospitalizados();
}
void QSisPacientes::ConsultaHospitalizados()
{
CQSisOpConsulta lCQSOConsulta(SisDatCom);
lCQSOConsulta.Consultas("ConsultasHoyPorEstado",
			 chrPtrFechaIni,
			 chrPtrFechaFin,
			"Hospitalizado",
			"",
			&CQSLCRegistradas);
}
void QSisPacientes::MuestraHospitalizados()
{
CQSisConsulta *lCQSConsulta;
for(lCQSConsulta=CQSLCRegistradas.first();
    lCQSConsulta;
    lCQSConsulta=CQSLCRegistradas.next())
{
	QIVPacientes->insertItem(new QSisIconViewItemConsulta(lCQSConsulta,QIVPacientes));	
}
}

QSisIconViewItemConsulta::QSisIconViewItemConsulta(
				CQSisConsulta *pCQSConsulta,
				QIconView *pQIVConsultas):
			QIconViewItem(pQIVConsultas),
			CQSConsulta(pCQSConsulta)
{
char lchrArrPaciente[150];
CQSisObjetos::NombreCompleto(CQSConsulta->Paciente(),lchrArrPaciente);
setText(lchrArrPaciente);
}
CQSisConsulta *QSisIconViewItemConsulta::Consulta()
{
	return CQSConsulta;
}


