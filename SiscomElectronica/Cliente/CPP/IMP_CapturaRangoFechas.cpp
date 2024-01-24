#include <IMP_CapturaRangoFechas.h>


#include <SISCOMComunicaciones++.h>
#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "IMP_QControlFecha.h"

QCapturaRangoFechas::QCapturaRangoFechas( QWidget* parent, const char* name, bool modal, WFlags fl )
    : CapturaRangoFechas( parent, name, modal, fl ),
    intOpcion(0)
{
	IniciaVariables();
	ConectaSlots();
	exec();
}

QCapturaRangoFechas::~QCapturaRangoFechas()
{
}
void QCapturaRangoFechas::IniciaVariables()
{

	QSisContFechaIni->ColocaFechaHoy();
	QSisContFechaFin->ColocaFechaHoy();
	QSisContFechaIni->setFocus();

}
void QCapturaRangoFechas::ConectaSlots()
{
	connect(QSisContFechaIni,
		SIGNAL(Signal_EnterA_o()),
		SLOT(S_PasaFocoFechaFin()));
	connect(QSisContFechaFin,
		SIGNAL(Signal_EnterA_o()),
		SLOT(S_PasaFocoAceptar()));
	connect(QPBAceptar,
		SIGNAL(clicked()),
		SLOT(S_Aceptar()));

}
void QCapturaRangoFechas::S_Aceptar()
{
	intOpcion=1;
	done(1);
}
void QCapturaRangoFechas::S_PasaFocoAceptar()
{
	SiscomPasaFocoControl(QPBAceptar);
}
void QCapturaRangoFechas::S_PasaFocoFechaFin()
{
	QSisContFechaFin->setFocus();
}
void QCapturaRangoFechas::ObtenRangoFechas(char *pchrPtrFechaIni,
					   char *pchrPtrFechaFin)
{
	strcpy(pchrPtrFechaIni,
	       (const char *)QSisContFechaIni->ObtenFecha());
	strcpy(pchrPtrFechaFin,
	       (const char *)QSisContFechaFin->ObtenFecha());
}
int QCapturaRangoFechas::ObtenOpcion()
{
	return intOpcion;
}
