#include <IMP_SelOrden.h>
#include <IMP_OrdenElectronica.h>

#include <SISCOMComunicaciones++.h>

#include <qvariant.h>
#include <qiconview.h>
#include <qpushbutton.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

QSelOrden::QSelOrden(QIconView *pQIVOrdenes,
			QWidget* parent, const char* name, bool modal, WFlags fl )
    : SelOrden( parent, name, modal, fl )
{
	AnexaOrdenesDisponibles(pQIVOrdenes);
	ConectaSlots();
	exec();
}

QSelOrden::~QSelOrden()
{
}
void QSelOrden::ConectaSlots()
{
	connect(QIVIOrdenes,
		SIGNAL(clicked(QIconViewItem *)),
		SLOT(S_SeleccionaOrden(QIconViewItem *)));
	connect(QIVIOrdenes,
		SIGNAL(doubleClicked(QIconViewItem *)),
		SLOT(S_SeleccionoOrden(QIconViewItem *)));
	connect(QIVIOrdenes,
		SIGNAL(returnPressed(QIconViewItem *)),
		SLOT(S_SeleccionoOrden(QIconViewItem *)));

	connect(QPBAceptar,
		SIGNAL(clicked()),
		SLOT(S_Aceptar()));
	connect(QPBCancelar,
		SIGNAL(clicked()),
		SLOT(S_Cancelar()));
	
}
void QSelOrden::S_SeleccionoOrden(QIconViewItem *pQIVIOrden)
{

	QOElectronica=((QIconVOrdenE *)pQIVIOrden)->ObtenOrdenElectronica();
	S_Aceptar();

}
void QSelOrden::S_Cancelar()
{
	intOpcion=0;
	done(1);
}
void QSelOrden::S_Aceptar()
{

	intOpcion=1;
	done(1);
}
void QSelOrden::S_SeleccionaOrden(QIconViewItem *pQIVIOrden)
{

	QOElectronica=((QIconVOrdenE *)pQIVIOrden)->ObtenOrdenElectronica();
	SiscomPasaFocoControl(QPBAceptar);

}
void QSelOrden::AnexaOrdenesDisponibles(QIconView *pQIVOrdenes)
{
QIconVOrdenE *lQIVOrdenE;

	for(lQIVOrdenE=(QIconVOrdenE *)pQIVOrdenes->firstItem();
	    lQIVOrdenE;
	    lQIVOrdenE=(QIconVOrdenE *)lQIVOrdenE->nextItem())
	 QIVIOrdenes->insertItem(new QIconVOrdenE(lQIVOrdenE->ObtenOrdenElectronica(),
	 			  QIVIOrdenes));
}
QOrdenElectronica *QSelOrden::ObtenOrden()
{
	return QOElectronica;
}
int QSelOrden::ObtenSeleccion()
{
	return intOpcion;
}
