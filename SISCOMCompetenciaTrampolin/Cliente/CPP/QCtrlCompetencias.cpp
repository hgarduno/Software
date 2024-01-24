#include <QCtrlCompetencias.h>
#include <SISCOMComunicaciones++.h>
#include <CQSisConsultas.h>
#include <qlayout.h>


QCtrlCompetencias::QCtrlCompetencias( QWidget *parent, const char *name )
    : QWidget( parent, name )
{
	IniciaVariables();
}
void QCtrlCompetencias::IniciaVariables()
{
	QHBLayout=new QHBoxLayout(this);
	QHBLayout->setMargin(0);
	QIVCompetencias=new QIconView(this);
	QHBLayout->addWidget(QIVCompetencias);
}
void QCtrlCompetencias::MuestraCompetencias()
{
CQSisCompetencia *lCQSCompetencia;
QIVCompetencias->clear();
	for(lCQSCompetencia=CQSLCompetencias.first();
	    lCQSCompetencia;
	    lCQSCompetencia=CQSLCompetencias.next())
	 QIVCompetencias->insertItem(new QIVItemCompetencia(lCQSCompetencia,QIVCompetencias));
}
void QCtrlCompetencias::IniciaControl()
{
	ConsultaCompetencias();
	MuestraCompetencias();
	ConectaSlots();
}
void QCtrlCompetencias::ConsultaCompetencias()
{
CQSLCompetencias.clear();
CQSisOpConsultas lCQSOConsultas(SisDatCom);
		lCQSOConsultas.ObtenCompetencias(&CQSLCompetencias);
}
void QCtrlCompetencias::PonServidor(SiscomDatCom *pSisDatCom)
{
	SisDatCom=pSisDatCom;
}

void QCtrlCompetencias::ConectaSlots()
{
	connect(QIVCompetencias,
		SIGNAL(doubleClicked(QIconViewItem *)),
		SLOT(SlotCompetencia(QIconViewItem *)));
	connect(QIVCompetencias,
		SIGNAL(returnPressed(QIconViewItem *)),
		SLOT(SlotCompetencia(QIconViewItem *)));

}
void QCtrlCompetencias::SlotCompetencia(QIconViewItem *pQIVGimnasio)
{
	if(pQIVGimnasio)
	emit SignalCompetencia(((QIVItemCompetencia *)pQIVGimnasio)->ObtenCompetencia());
}
void QCtrlCompetencias::setFocus()
{
	
	QIVCompetencias->setFocus();
}
void QCtrlCompetencias::LimpiaSeleccion()
{
	QIVCompetencias->clearSelection();
}









QIVItemCompetencia::QIVItemCompetencia(CQSisCompetencia *pCQSCompetencia,
				QIconView *pQIVParent):
		QIconViewItem(pQIVParent),
		CQSCompetencia(pCQSCompetencia)

{
	IniciaVariables();
}
void QIVItemCompetencia::IniciaVariables()
{
	setText(CQSCompetencia->SRegistrosPro2["Competencia"]);	
}
CQSisCompetencia *QIVItemCompetencia::ObtenCompetencia()
{
	return CQSCompetencia;
}
