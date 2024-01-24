
#include <QCtrlElFresnos.h>
#include <SISCOMComunicaciones++.h>
#include <CQSisElFresnos.h>
#include <qlayout.h>


QCtrlElFresnos::QCtrlElFresnos( QWidget *parent, const char *name )
    : QWidget( parent, name )
{
	IniciaVariables();
	ConectaSlots();
}
void QCtrlElFresnos::IniciaVariables()
{
	QHBLayout=new QHBoxLayout(this);
	QHBLayout->setMargin(0);
	QIVElFresnos=new QIconView(this);
	QHBLayout->addWidget(QIVElFresnos);
}
void QCtrlElFresnos::MuestraElFresnos()
{
CQSisElFresno *lCQSElFresno;
for(lCQSElFresno=CQSLElFresno.first();
    lCQSElFresno;
    lCQSElFresno=CQSLElFresno.next())
  QIVElFresnos->insertItem(new QIVItemElFresno(lCQSElFresno,QIVElFresnos)); 
}
void QCtrlElFresnos::IniciaControl()
{
	QIVElFresnos->clear();
	ConsultaElFresnos();
	MuestraElFresnos();
}
void QCtrlElFresnos::ConsultaElFresnos()
{
CQSisOpElFresno lCQSOElFresno(SisDatCom);
/*				
lCQSOElFresno.MediosComunicacion(&SLMComunicacion);
*/
}
void QCtrlElFresnos::PonServidor(SiscomDatCom *pSisDatCom)
{
	SisDatCom=pSisDatCom;
}

void QCtrlElFresnos::ConectaSlots()
{
	connect(QIVElFresnos,
		SIGNAL(clicked(QIconViewItem *)),
		SLOT(S_SeleccionoElFresno(QIconViewItem *)));
	/*
	connect(QIVElFresnos,
		SIGNAL(returnPressed(QIconViewItem *)),
		SLOT(S_SeleccionoElFresno(QIconViewItem *)));
	*/

}
void QCtrlElFresnos::S_SeleccionoElFresno(QIconViewItem *pQIVElFresno)
{

	if(pQIVElFresno)
	 emit SignalElFresno(((QIVItemElFresno*)pQIVElFresno)->ObtenElFresno());

}

void QCtrlElFresnos::setFocus()
{
	
	QIVElFresnos->setFocus();
}
void QCtrlElFresnos::LimpiaSeleccion()
{
	QIVElFresnos->clearSelection();
}
void QCtrlElFresnos::Limpia()
{
	QIVElFresnos->clear();
}








QIVItemElFresno::QIVItemElFresno(
		    CQSisElFresno *pCQSElFresno,
				QIconView *pQIVParent):
		QIconViewItem(pQIVParent),
		CQSElFresno(pCQSElFresno)

{
	IniciaVariables();
}
void QIVItemElFresno::IniciaVariables()
{
	setText(CQSElFresno->SRegistrosPro2[""]);	
}
CQSisElFresno *QIVItemElFresno::ObtenElFresno()
{
	return CQSElFresno;
}


