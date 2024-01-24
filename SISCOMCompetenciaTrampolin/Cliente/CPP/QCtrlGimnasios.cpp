#include <QCtrlGimnasios.h>
#include <SISCOMComunicaciones++.h>
#include <qlayout.h>


QCtrlGimnasios::QCtrlGimnasios( QWidget *parent, const char *name )
    : QWidget( parent, name )
{
	IniciaVariables();
}
void QCtrlGimnasios::IniciaVariables()
{
	QHBLayout=new QHBoxLayout(this);
	QHBLayout->setMargin(0);
	QIVGimnasios=new QIconView(this);
	QHBLayout->addWidget(QIVGimnasios);
}
void QCtrlGimnasios::MuestraGimnasios()
{
CQSisGimnasio *lCQSGPtrGimnasio;

	for(lCQSGPtrGimnasio=CQSLstGimnasios.first();
	    lCQSGPtrGimnasio;
	    lCQSGPtrGimnasio=CQSLstGimnasios.next())
	 QIVGimnasios->insertItem(new QIVItemGimnasio(lCQSGPtrGimnasio,QIVGimnasios));
}
void QCtrlGimnasios::IniciaControl()
{
	QIVGimnasios->clear();
	ConsultaGimnasios();
	MuestraGimnasios();
	ConectaSlots();
}
void QCtrlGimnasios::ConsultaGimnasios()
{
CQSLstGimnasios.clear();
CQSisOpGimnasio lCQSOGimnasio(SisDatCom);
		lCQSOGimnasio.GimnasiosRegistrados(&CQSLstGimnasios);
}
void QCtrlGimnasios::PonServidor(SiscomDatCom *pSisDatCom)
{
	SisDatCom=pSisDatCom;
}

void QCtrlGimnasios::ConectaSlots()
{
	connect(QIVGimnasios,
		SIGNAL(doubleClicked(QIconViewItem *)),
		SLOT(S_SeleccionoGimnasio(QIconViewItem *)));
	connect(QIVGimnasios,
		SIGNAL(returnPressed(QIconViewItem *)),
		SLOT(S_SeleccionoGimnasio(QIconViewItem *)));

}
void QCtrlGimnasios::S_SeleccionoGimnasio(QIconViewItem *pQIVGimnasio)
{

	if(pQIVGimnasio)
	 emit SignalGimnasio(((QIVItemGimnasio *)pQIVGimnasio)->ObtenGimnasio());

}
void QCtrlGimnasios::setFocus()
{
	
	QIVGimnasios->setFocus();
}
void QCtrlGimnasios::LimpiaSeleccion()
{
	QIVGimnasios->clearSelection();
}
void QCtrlGimnasios::Limpia()
{
	QIVGimnasios->clear();
}








QIVItemGimnasio::QIVItemGimnasio(CQSisGimnasio *pCQSGimnasio,
				QIconView *pQIVParent):
		QIconViewItem(pQIVParent),
		CQSGimnasio(pCQSGimnasio)

{
	IniciaVariables();
}
void QIVItemGimnasio::IniciaVariables()
{
	setText(CQSGimnasio->SRegistrosPro2["Gimnasio"]);	
}
CQSisGimnasio *QIVItemGimnasio::ObtenGimnasio()
{
	return CQSGimnasio;
}
