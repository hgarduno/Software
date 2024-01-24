#include <QCtrlTipoCompetencia.h>
#include <CQSisClase.h>
#include <CQSisConsultas.h>
#include <SISCOMComunicaciones++.h>
#include <qlayout.h>


QCtrlTipoCompetencia::QCtrlTipoCompetencia( QWidget *parent, const char *name )
    : QWidget( parent, name )
{
	IniciaVariables();
}
void QCtrlTipoCompetencia::IniciaVariables()
{
	QHBLayout=new QHBoxLayout(this);
	QHBLayout->setMargin(0);
	QIVCompetencias=new QIconView(this);
	QHBLayout->addWidget(QIVCompetencias);
}
void QCtrlTipoCompetencia::MuestraTipoCompetencia()
{
CQSisTipoCompetencia *lCQSTipoCompetencia;
QIVCompetencias->clear();
		for(lCQSTipoCompetencia=CQSLTipoCompetencia.first();
		    lCQSTipoCompetencia;
		    lCQSTipoCompetencia=CQSLTipoCompetencia.next())
		  QIVCompetencias->insertItem(
		  	new QIVItemTipoCompetencia(
			    new	CQSisTipoCompetencia(
			    	lCQSTipoCompetencia->SRegistrosPro2["IdTipoCompetencia"],
				lCQSTipoCompetencia->SRegistrosPro2["Competencia"]),
				QIVCompetencias));
		  				
}
void QCtrlTipoCompetencia::IniciaControl()
{
	QIVCompetencias->clear();
	ConsultaTipoCompetencia();
	MuestraTipoCompetencia();
	ConectaSlots();
}
void QCtrlTipoCompetencia::ConsultaTipoCompetencia()
{
CQSisOpConsultas lCQSOConsulta(SisDatCom);
		lCQSOConsulta.ConsultaTipoCompetencia(&CQSLTipoCompetencia);
}
void QCtrlTipoCompetencia::PonServidor(SiscomDatCom *pSisDatCom)
{
	SisDatCom=pSisDatCom;
}
void QCtrlTipoCompetencia::ConectaSlots()
{
	connect(QIVCompetencias,
		SIGNAL(doubleClicked(QIconViewItem *)),
		SLOT(SlotTipoCompetencia(QIconViewItem *)));
	connect(QIVCompetencias,
		SIGNAL(returnPressed(QIconViewItem *)),
		SLOT(SlotTipoCompetencia(QIconViewItem *)));

}
void QCtrlTipoCompetencia::SlotTipoCompetencia(QIconViewItem *pQIVTipoCompetencia)
{
	if(pQIVTipoCompetencia)
	 emit SignalTipoCompetencia(((QIVItemTipoCompetencia *)pQIVTipoCompetencia)->ObtenTipoCompetencia());
}
void QCtrlTipoCompetencia::setFocus()
{
	
	QIVCompetencias->setFocus();
}
void QCtrlTipoCompetencia::LimpiaSeleccion()
{
	QIVCompetencias->clearSelection();
}
void QCtrlTipoCompetencia::Limpia()
{
	QIVCompetencias->clear();
}








QIVItemTipoCompetencia::QIVItemTipoCompetencia(CQSisTipoCompetencia *pCQSTipoCompetencia,
				QIconView *pQIVParent):
		QIconViewItem(pQIVParent),
		CQSTipoCompetencia(pCQSTipoCompetencia)

{
	IniciaVariables();
}
void QIVItemTipoCompetencia::IniciaVariables()
{
	setText(CQSTipoCompetencia->SRegistrosPro2["Competencia"]);	
}
CQSisTipoCompetencia *QIVItemTipoCompetencia::ObtenTipoCompetencia()
{
	return CQSTipoCompetencia;
}
