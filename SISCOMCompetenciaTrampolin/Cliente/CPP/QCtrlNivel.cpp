#include <QCtrlNivel.h>
#include <CQSisClase.h>
#include <CQSisConsultas.h>
#include <SISCOMComunicaciones++.h>
#include <qlayout.h>


QCtrlNivel::QCtrlNivel( QWidget *parent, const char *name )
    : QWidget( parent, name ),
    intYaConectaSlots(0)
{
	IniciaVariables();
}
void QCtrlNivel::IniciaVariables()
{
	QHBLayout=new QHBoxLayout(this);
	QHBLayout->setMargin(0);
	QIVCompetencias=new QIconView(this);
	QHBLayout->addWidget(QIVCompetencias);
}
void QCtrlNivel::MuestraNiveles()
{
/*
CQSisGimnasio *lCQSGPtrGimnasio;

	for(lCQSGPtrGimnasio=CQSLstCompetencias.first();
	    lCQSGPtrGimnasio;
	    lCQSGPtrGimnasio=CQSLstCompetencias.next())
	 QIVCompetencias->insertItem(new QIVItemNivel(lCQSGPtrGimnasio,QIVCompetencias));
	 */
CQSisNivel *lCQSNivel;
	for(lCQSNivel=CQSLNivel.first();
	    lCQSNivel;
	    lCQSNivel=CQSLNivel.next())
	  QIVCompetencias->insertItem(new QIVItemNivel(lCQSNivel,QIVCompetencias));

}
void QCtrlNivel::IniciaControl()
{
	QIVCompetencias->clear();
	ConsultaNiveles();
	MuestraNiveles();
	if(!intYaConectaSlots)
	ConectaSlots();
}
void QCtrlNivel::ConsultaNiveles()
{
CQSLNivel.clear();
CQSisOpConsultas lCQSOConsultas(SisDatCom);
		lCQSOConsultas.ObtenNiveles(CQSClase,&CQSLNivel);
}
void QCtrlNivel::PonServidor(SiscomDatCom *pSisDatCom)
{
	SisDatCom=pSisDatCom;
}
void QCtrlNivel::PonClase(CQSisClase *pCQSClase)
{
	CQSClase=pCQSClase;
}
void QCtrlNivel::ConectaSlots()
{
	connect(QIVCompetencias,
		SIGNAL(doubleClicked(QIconViewItem *)),
		SLOT(S_SeleccionoNivel(QIconViewItem *)));
	connect(QIVCompetencias,
		SIGNAL(returnPressed(QIconViewItem *)),
		SLOT(S_SeleccionoNivel(QIconViewItem *)));
	intYaConectaSlots=1;

}
void QCtrlNivel::S_SeleccionoNivel(QIconViewItem *pQIVNivel)
{
	if(pQIVNivel)
	 emit SignalNivel(((QIVItemNivel *)pQIVNivel)->ObtenNivel());
}
void QCtrlNivel::setFocus()
{
	
	QIVCompetencias->setFocus();
}
void QCtrlNivel::LimpiaSeleccion()
{
	QIVCompetencias->clearSelection();
}
void QCtrlNivel::Limpia()
{
	QIVCompetencias->clear();
}








QIVItemNivel::QIVItemNivel(CQSisNivel *pCQSNivel,
				QIconView *pQIVParent):
		QIconViewItem(pQIVParent),
		CQSNivel(pCQSNivel)

{
	IniciaVariables();
}
void QIVItemNivel::IniciaVariables()
{
	setText(CQSNivel->SRegistrosPro2["Descripcion"]);	
}
CQSisNivel *QIVItemNivel::ObtenNivel()
{
	return CQSNivel;
}
