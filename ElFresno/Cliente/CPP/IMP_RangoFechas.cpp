#include <IMP_RangoFechas.h>
#include <CQSiscomCom.h>

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <IMP_QControlFecha.h>

QRangoFechas::QRangoFechas( QWidget* parent, const char* name, bool modal, WFlags fl )
    : RangoFechas( parent, name, modal, fl )
{
	IniciaVariables();
	ConectaSlots();
	exec();
}

QRangoFechas::~QRangoFechas()
{
}
void QRangoFechas::IniciaVariables()
{
	QCFechaIni->ColocaFechaHoy();
	QCFechaFin->ColocaFechaHoy();
	QCFechaIni->setFocus();
}
void QRangoFechas::ConectaSlots()
{
	connect(QPBAceptar,
		SIGNAL(clicked()),
		SLOT(S_Aceptar()));
	connect(QPBCancelar,
		SIGNAL(clicked()),
		SLOT(S_Cancelar()));
	connect(QCFechaIni,
		SIGNAL(Signal_EnterA_o()),
		SLOT(S_PasaFocoFechaFin()));
	connect(QCFechaFin,
		SIGNAL(Signal_EnterA_o()),
		SLOT(S_PasaFocoAceptar()));

}
void QRangoFechas::S_PasaFocoAceptar()
{
	PasaFocoControl(QPBAceptar);
}
void QRangoFechas::S_PasaFocoFechaFin()
{
	QCFechaFin->setFocus();	
}
void QRangoFechas::S_Cancelar()
{
	BTNOpcion=QRangoFechas::Cancelar;
	done(1);
}
void QRangoFechas::S_Aceptar()
{
	BTNOpcion=QRangoFechas::Aceptar;
	done(1);
}
QRangoFechas::BTN_Opciones QRangoFechas::ObtenSeleccion()
{
	return BTNOpcion;
}
void QRangoFechas::ObtenRangoFechas(char **pchrPtrFechaIni,
				     char **pchrPtrFechaFin)
{

		*pchrPtrFechaIni=strdup((const char *)QCFechaIni->ObtenFecha());
		*pchrPtrFechaFin=strdup((const char *)QCFechaFin->ObtenFecha());

}
