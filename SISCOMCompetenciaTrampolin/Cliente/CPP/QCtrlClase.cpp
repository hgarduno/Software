#include <QCtrlClase.h>
#include <SISCOMComunicaciones++.h>

#include <CQSisConsultas.h>
#include <CQSisCompetencias.h>
#include <qlayout.h>


QCtrlClase::QCtrlClase( QWidget *parent, const char *name )
    : QWidget( parent, name )
{
	IniciaVariables();
}
void QCtrlClase::IniciaVariables()
{
	QHBLayout=new QHBoxLayout(this);
	QHBLayout->setMargin(0);
	QIVCompetencias=new QIconView(this);
	QHBLayout->addWidget(QIVCompetencias);
}
void QCtrlClase::MuestraClases()
{
CQSisClase *lCQSClase;

	for(lCQSClase=CQSLClase.first();
	    lCQSClase;
	    lCQSClase=CQSLClase.next())
	 QIVCompetencias->insertItem(new QIVItemClase(lCQSClase,QIVCompetencias));
	 QIVCompetencias->arrangeItemsInGrid();
}
void QCtrlClase::IniciaControl()
{
	QIVCompetencias->clear();
	ConsultaClases();
	MuestraClases();
	ConectaSlots();
}
void QCtrlClase::ConsultaClases()
{
CQSLClase.clear();
CQSisOpConsultas lCQSOConsultas(SisDatCom);
		lCQSOConsultas.ObtenClases(
			CQSCompetencia->SRegistrosPro2["IdTipoCompetencia"],
			&CQSLClase);
}
void QCtrlClase::PonCompetencia(CQSisCompetencia *pCQSCompetencia)
{
	CQSCompetencia=pCQSCompetencia;
}
void QCtrlClase::PonServidor(SiscomDatCom *pSisDatCom)
{
	SisDatCom=pSisDatCom;
}

void QCtrlClase::ConectaSlots()
{
	connect(QIVCompetencias,
		SIGNAL(doubleClicked(QIconViewItem *)),
		SLOT(S_SeleccionoClase(QIconViewItem *)));
	connect(QIVCompetencias,
		SIGNAL(returnPressed(QIconViewItem *)),
		SLOT(S_SeleccionoClase(QIconViewItem *)));

}
void QCtrlClase::S_SeleccionoClase(QIconViewItem *pQIVGimnasio)
{
	if(pQIVGimnasio)
	 emit SignalClase(((QIVItemClase *)pQIVGimnasio)->ObtenClase());
}
void QCtrlClase::setFocus()
{
	
	QIVCompetencias->setFocus();
}
void QCtrlClase::LimpiaSeleccion()
{
	QIVCompetencias->clearSelection();
}









QIVItemClase::QIVItemClase(CQSisClase *pCQSClase,
				QIconView *pQIVParent):
		QIconViewItem(pQIVParent),
		CQSClase(pCQSClase)

{
	IniciaVariables();
}
void QIVItemClase::IniciaVariables()
{
	setText(QString("Clase ") + CQSClase->SRegistrosPro2["Clase"]);	
}
CQSisClase *QIVItemClase::ObtenClase()
{
	return CQSClase;
}
