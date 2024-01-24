#include <IMP_ObservacionesConsulta.h>
#include<SISCOMComunicaciones++.h>

#include <CQSisConsultas.h>
#include <CQSisExpedientes.h>

#include <qpushbutton.h>
QObservacionesConsulta::QObservacionesConsulta(
				    CQSisConsulta *pCQSConsulta,
				    SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    bool pbModal,
				    WFlags pWFlags):	      
				ObservacionesConsulta(pQWParent,pchrPtrName,pbModal,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos),
				CQSConsulta(pCQSConsulta)
{
IniciaVariables();
ConectaSlots();
exec();
}

QObservacionesConsulta::~QObservacionesConsulta()
{

}

void QObservacionesConsulta::ConectaSlots()
{

	connect(QPBRegistra,
		SIGNAL(clicked()),
		SLOT(SlotRegistra()));
	connect(QPBTerminar,
		SIGNAL(clicked()),
		SLOT(SlotTerminar()));

}
void QObservacionesConsulta::SlotTerminar()
{
done(1);
}
void QObservacionesConsulta::SlotRegistra()
{
	if(!CQSLExpediente.count())
	Registra();
	else
	Actualiza();
	done(1);
}
void QObservacionesConsulta::IniciaVariables()
{
	Observaciones();
}
void QObservacionesConsulta::closeEvent(QCloseEvent *)
{

}
void QObservacionesConsulta::Registra()
{
SiscomRegistrosPro2 *lSRegistrosPro2;
CQSisOpExpediente lCQSOExpediente(SisDatCom);
	lCQSOExpediente.RegistraConsulta(
		new CQSisExpediente((*CQSConsulta)["IdConsulta"],
		SiscomObtenInformacionDelEdit(QTEObservaciones),
		""),
		&lSRegistrosPro2);
}

void QObservacionesConsulta::Actualiza()
{
SiscomRegistrosPro2 *lSRegistrosPro2;
CQSisOpExpediente lCQSOExpediente(SisDatCom);
	lCQSOExpediente.ActualizaObservaciones(
		new CQSisExpediente((*CQSConsulta)["IdConsulta"],
		SiscomObtenInformacionDelEdit(QTEObservaciones),
		""),
		&lSRegistrosPro2);
}
void QObservacionesConsulta::ConsultaObservaciones()
{
CQSisOpExpediente lCQSOExpediente(SisDatCom);
lCQSOExpediente.ObservacionesConsulta((*CQSConsulta)["IdConsulta"],
				      &CQSLExpediente);
}
void QObservacionesConsulta::Observaciones()
{
	ConsultaObservaciones();
	MuestraObservaciones();
}
void QObservacionesConsulta::MuestraObservaciones()
{
if(CQSLExpediente.count())
QTEObservaciones->setText((*CQSLExpediente.at(0))["Observaciones"]);
}
int QObservacionesConsulta::SiObservaciones()
{
return  CQSLExpediente.count();
}

int QObservacionesConsulta::HayObservaciones(
				SiscomDatCom *pSisDatCom,
				const char *pchrPtrIdConsulta)
{
CQSisLstExpediente lCQSLExpediente;
CQSisOpExpediente lCQSOExpediente(pSisDatCom);
lCQSOExpediente.ObservacionesConsulta(pchrPtrIdConsulta,
				      &lCQSLExpediente);

return lCQSLExpediente.count();
}
				
