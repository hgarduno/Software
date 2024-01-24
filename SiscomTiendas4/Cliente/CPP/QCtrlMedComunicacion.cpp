#include <QCtrlMedComunicacion.h>
#include <SISCOMComunicaciones++.h>
#include <SisMedioComunicacion.h>
#include <CQSisOpTiendas4.h>
#include <qlayout.h>


QCtrlMedComunicacion::QCtrlMedComunicacion( QWidget *parent, const char *name )
    : QWidget( parent, name )
{
	IniciaVariables();
	ConectaSlots();
}
void QCtrlMedComunicacion::IniciaVariables()
{
	QHBLayout=new QHBoxLayout(this);
	QHBLayout->setMargin(0);
	QIVCompetencias=new QIconView(this);
	QHBLayout->addWidget(QIVCompetencias);
}
void QCtrlMedComunicacion::MuestraMedComunicaciones()
{
SisMedCom *lSMCom;
for(lSMCom=SLMComunicacion.first();
    lSMCom;
    lSMCom=SLMComunicacion.next())
  QIVCompetencias->insertItem(new QIVItemMedComunicacion(lSMCom,QIVCompetencias)); 
}
void QCtrlMedComunicacion::IniciaControl()
{
	QIVCompetencias->clear();
	ConsultaMedComunicaciones();
	MuestraMedComunicaciones();
}
void QCtrlMedComunicacion::ConsultaMedComunicaciones()
{
CQSisOpTiendas4 lCQSOT4Medios(SisDatCom);
lCQSOT4Medios.MediosComunicacion(&SLMComunicacion);
}
void QCtrlMedComunicacion::PonServidor(SiscomDatCom *pSisDatCom)
{
	SisDatCom=pSisDatCom;
}

void QCtrlMedComunicacion::ConectaSlots()
{
	connect(QIVCompetencias,
		SIGNAL(clicked(QIconViewItem *)),
		SLOT(S_SeleccionoMedComunicacion(QIconViewItem *)));
	/*
	connect(QIVCompetencias,
		SIGNAL(returnPressed(QIconViewItem *)),
		SLOT(S_SeleccionoMedComunicacion(QIconViewItem *)));
	*/

}
void QCtrlMedComunicacion::S_SeleccionoMedComunicacion(QIconViewItem *pQIVMedComunicacion)
{

	if(pQIVMedComunicacion)
	 emit SignalMedComunicacion(((QIVItemMedComunicacion *)pQIVMedComunicacion)->ObtenMedComunicacion());

}

void QCtrlMedComunicacion::setFocus()
{
	
	QIVCompetencias->setFocus();
}
void QCtrlMedComunicacion::LimpiaSeleccion()
{
	QIVCompetencias->clearSelection();
}
void QCtrlMedComunicacion::Limpia()
{
	QIVCompetencias->clear();
}








QIVItemMedComunicacion::QIVItemMedComunicacion(
				SisMedCom *pSMCom,
				QIconView *pQIVParent):
		QIconViewItem(pQIVParent),
		SMCom(pSMCom)

{
	IniciaVariables();
}
void QIVItemMedComunicacion::IniciaVariables()
{
	setText(SMCom->SRegistrosPro2["Medio"]);	
}
SisMedCom *QIVItemMedComunicacion::ObtenMedComunicacion()
{
	return SMCom;
}
