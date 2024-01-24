#include <QCtrlAparatoCompetencia.h>
#include <CQSisClase.h>
#include <CQSisConsultas.h>
#include <CQSisAparato.h>
#include <CQSisCompetencias.h>
#include <qlayout.h>

#include <SISCOMComunicaciones++.h>

QCtrlAparatoCompetencia::QCtrlAparatoCompetencia( QWidget *parent, const char *name )
    : QWidget( parent, name )
{
	IniciaVariables();
}
void QCtrlAparatoCompetencia::IniciaVariables()
{
	QHBLayout=new QHBoxLayout(this);
	QHBLayout->setMargin(0);
	QIVCompetencias=new QIconView(this);
	QHBLayout->addWidget(QIVCompetencias);
}
void QCtrlAparatoCompetencia::MuestraAparatoCompetencia()
{
CQSisAparatoCompetencia *lCQSACompetencia;

for(lCQSACompetencia=CQSLAparatoCompetencia.first();
    lCQSACompetencia;
    lCQSACompetencia=CQSLAparatoCompetencia.next())
   QIVCompetencias->insertItem(
      new QIVItemAparatoCompetencia(lCQSACompetencia,QIVCompetencias)
      				);
		  				
}
void QCtrlAparatoCompetencia::IniciaControl()
{
	QIVCompetencias->clear();
	ConsultaAparatoCompetencia();
	MuestraAparatoCompetencia();
	ConectaSlots();
}
void QCtrlAparatoCompetencia::ConsultaAparatoCompetencia()
{
CQSisOpConsultas lCQSOConsulta(SisDatCom);
		lCQSOConsulta.ConsultaAparatosCompetencia(
			CQSCompetencia,
			&CQSLAparatoCompetencia);
}
void QCtrlAparatoCompetencia::PonServidor(SiscomDatCom *pSisDatCom)
{
	SisDatCom=pSisDatCom;
}
void QCtrlAparatoCompetencia::PonCompetencia(
				CQSisCompetencia *pCQSCompetencia)
{
	CQSCompetencia=pCQSCompetencia;
}
void QCtrlAparatoCompetencia::ConectaSlots()
{
	connect(QIVCompetencias,
		SIGNAL(doubleClicked(QIconViewItem *)),
		SLOT(SlotAparatoCompetencia(QIconViewItem *)));
	connect(QIVCompetencias,
		SIGNAL(returnPressed(QIconViewItem *)),
		SLOT(SlotAparatoCompetencia(QIconViewItem *)));

}
void QCtrlAparatoCompetencia::SlotAparatoCompetencia(QIconViewItem *pQIVAparatoCompetencia)
{
	if(pQIVAparatoCompetencia)
	 emit SignalAparatoCompetencia(((QIVItemAparatoCompetencia *)pQIVAparatoCompetencia)->ObtenAparatoCompetencia());
}
void QCtrlAparatoCompetencia::setFocus()
{
	
	QIVCompetencias->setFocus();
}
void QCtrlAparatoCompetencia::LimpiaSeleccion()
{
	QIVCompetencias->clearSelection();
}
void QCtrlAparatoCompetencia::Limpia()
{
	QIVCompetencias->clear();
}

const CQSisLstAparatoCompetencia &QCtrlAparatoCompetencia::ObtenAparatos()
{
	return CQSLAparatoCompetencia;
}






QIVItemAparatoCompetencia::QIVItemAparatoCompetencia(CQSisAparatoCompetencia *pCQSAparatoCompetencia,
				QIconView *pQIVParent):
		QIconViewItem(pQIVParent),
		CQSAparatoCompetencia(pCQSAparatoCompetencia)

{
	IniciaVariables();
}
void QIVItemAparatoCompetencia::IniciaVariables()
{
	setText(CQSAparatoCompetencia->ObtenAparato()->SRegistrosPro2["Aparato"]);	
}
CQSisAparatoCompetencia *QIVItemAparatoCompetencia::ObtenAparatoCompetencia()
{
	return CQSAparatoCompetencia;
}
