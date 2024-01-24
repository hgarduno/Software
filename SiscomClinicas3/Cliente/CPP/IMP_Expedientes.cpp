#include <IMP_Expedientes.h>
#include <IMP_Recetas.h>
#include <QSisExpediente.h>
#include<SISCOMComunicaciones++.h>
#include <CQSisPersonas.h>
#include <CQSisObjetos.h>

#include <qtabwidget.h>
QExpedientes::QExpedientes(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				Expedientes(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos),
				QWParent(pQWParent)
{
IniciaVariables();
ConectaSlots();
show();
}

QExpedientes::~QExpedientes()
{

}

void QExpedientes::ConectaSlots()
{
	connect(QPBHRecetas,
		SIGNAL(clicked()),
		SLOT(SlotHistorialRecetas()));

}
void QExpedientes::SlotHistorialRecetas()
{
	QRRecetas=new QRecetas(SisDatCom,
			       chrPtrArgumentos,
			       QWParent);
	QRRecetas->Paciente(CQSPaciente);
	QRRecetas->Informacion();
}
void QExpedientes::IniciaVariables()
{
	QTWConsultas->removePage(QTWConsultas->page(0));
}
void QExpedientes::Expediente()
{
	MuestraPaciente();
	ConsultandoExpediente();
}
void QExpedientes::Paciente(CQSisPersona *pCQSPaciente)
{
	CQSPaciente=pCQSPaciente;
}
void QExpedientes::MuestraPaciente()
{
char lchrArrPaciente[125];
CQSisObjetos::NombreCompleto(CQSPaciente,lchrArrPaciente); 
QLEPaciente->setText(lchrArrPaciente);
}
QSisExpediente *QExpedientes::WidgetExpediente(CQSisExpediente *pCQSExpediente)
{
QSisExpediente *lQSExpediente;
lQSExpediente=new QSisExpediente(
			this);
lQSExpediente->Expediente(pCQSExpediente);
lQSExpediente->Informacion();

return lQSExpediente;
}
void QExpedientes::MuestraExpediente()
{
CQSisExpediente *lCQSExpediente;
QSisExpediente *lQSExpediente;
for(lCQSExpediente=CQSLExpediente.first();
    lCQSExpediente;
    lCQSExpediente=CQSLExpediente.next())
{
lQSExpediente=WidgetExpediente(lCQSExpediente);
QTWConsultas->addTab(lQSExpediente,(*lCQSExpediente)["Fecha"]);
}
QTWConsultas->setCurrentPage(0);
}

void QExpedientes::ConsultaExpediente()
{
CQSisOpExpediente lCQSOExpediente(SisDatCom);
lCQSOExpediente.Expediente((*CQSPaciente)["IdPersona"],&CQSLExpediente);
}
void QExpedientes::ConsultandoExpediente()
{
	ConsultaExpediente();
	MuestraExpediente();
}
void QExpedientes::closeEvent(QCloseEvent *)
{
	CQSLExpediente.setAutoDelete(true);
	CQSLExpediente.clear();
	emit SignalCerroExpediente(CQSPaciente);
}
