#include <QSisOperacionesPersonas.h>
#include <QSisOperacionPersona.h>
#include <QSisIconDatosPersona.h>

#include <qlayout.h>
#include <qiconview.h>

QSisOperacionesPersonas::QSisOperacionesPersonas( QWidget *parent, const char *name )
    : QWidget( parent, name )
{
	IniciaVariables();
	ConectaSlots();
}

void QSisOperacionesPersonas::IniciaVariables()
{
	QHBLayout=new QHBoxLayout(this);
	QHBLayout->setMargin(0);
	QIVOperaciones=new QIconView(this);
	QHBLayout->addWidget(QIVOperaciones);
}
void QSisOperacionesPersonas::ConectaSlots()
{
	connect(QIVOperaciones,
		SIGNAL(clicked(QIconViewItem *)),
		SLOT(S_SeleccionoOperacion(QIconViewItem *)));
	connect(QIVOperaciones,
		SIGNAL(returnPressed(QIconViewItem *)),
		SLOT(S_SeleccionoOperacion(QIconViewItem *)));
}
void QSisOperacionesPersonas::S_SeleccionoOperacion(QIconViewItem *pQIVIOperacion)
{
QSisIconDatosPersona *lQSisIconDatPersona;
	if(pQIVIOperacion)
	{
	lQSisIconDatPersona=(QSisIconDatosPersona *)pQIVIOperacion;
	lQSisIconDatPersona->ObtenOperacionPersona()->EjecutaOperacion();
	}

}
void QSisOperacionesPersonas::SiscomIniciaControl()
{

}
void QSisOperacionesPersonas::SiscomAnexaOperacion(const char *pchrPtrBiblioteca,
						   const char *pchrPtrFuncion)
{
	QSisBOpsPersonas << new QSisBibliotecaOpPersonas(pchrPtrBiblioteca,
						     pchrPtrFuncion);
}
QIconView *QSisOperacionesPersonas::ObtenIconView()
{
	return QIVOperaciones;
}
QSisOperacionesPersonas &QSisOperacionesPersonas::operator<<(QSisIconDatosPersona *pQSisIcoDPersonas)
{
	pQSisIcoDPersonas->IniciaControl();
	QIVOperaciones->insertItem(pQSisIcoDPersonas);
	return *this;
}
