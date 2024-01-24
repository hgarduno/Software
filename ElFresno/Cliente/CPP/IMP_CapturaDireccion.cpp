#include <IMP_CapturaDireccion.h>
#include <CQSiscomCom.h>
#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qcombobox.h>
#include <qtextedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
QCapturaDireccion::QCapturaDireccion( QWidget* parent, const char* name, bool modal, WFlags fl )
    : CapturaDireccion( parent, name, modal, fl )
{
	IniciaVariables();
	ConectaSlots();
	exec();
}

QCapturaDireccion::~QCapturaDireccion()
{
}
void QCapturaDireccion::ConectaSlots()
{
	connect(QLECalle,
		SIGNAL(returnPressed()),
		SLOT(S_PasaFocoNumero()));
	connect(QLENumero,
		SIGNAL(returnPressed()),
		SLOT(S_PasaFocoCP()));
	connect(QLECP,
		SIGNAL(returnPressed()),
		SLOT(S_PasaFocoColonia()));
	connect(QLEColonia,
		SIGNAL(returnPressed()),
		SLOT(S_PasaFocoMunicipio()));
	connect(QLEMunicipio,
		SIGNAL(returnPressed()),
		SLOT(S_PasaFocoEstado()));
	connect(QLECEstado,
		SIGNAL(returnPressed()),
		SLOT(S_PasaFocoReferencias()));
	connect(QPBAceptar,
		SIGNAL(clicked()),
		SLOT(S_Aceptar()));
	connect(QPBCancelar,
		SIGNAL(clicked()),
		SLOT(S_Cancelar()));
}
void QCapturaDireccion::S_Aceptar()
{
	Opcion=SISCOMGlobales::Aceptar;
	done(1);
}
void QCapturaDireccion::S_Cancelar()
{
	Opcion=SISCOMGlobales::Cancelar;
	done(1);
}
void QCapturaDireccion::S_PasaFocoNumero()
{
	PasaFocoControl(QLENumero);
}

void QCapturaDireccion::S_PasaFocoCP()
{
	PasaFocoControl(QLECP);
}


void QCapturaDireccion::S_PasaFocoColonia()
{
	PasaFocoControl(QLEColonia);
}


void QCapturaDireccion::S_PasaFocoMunicipio()
{
	PasaFocoControl(QLEMunicipio);
}


void QCapturaDireccion::S_PasaFocoEstado()
{
	PasaFocoControl(QLECEstado);
}


void QCapturaDireccion::S_PasaFocoReferencias()
{
	PasaFocoControl(QTEReferencias);
}

void QCapturaDireccion::IniciaVariables()
{
	QLECEstado=ColocaLineEditAlCombo(QCBEstados,"QLECEstado");
	PasaFocoControl(QLECalle);
}
SISCOMGlobales::BTN_Captura QCapturaDireccion::ObtenOpcion()
{
	return Opcion;
}
const char *QCapturaDireccion::ObtenCalle()
{
	return SISCOMObtenInformacionDelEdit(QLECalle);
}
const char *QCapturaDireccion::ObtenNumero()
{
	return SISCOMObtenInformacionDelEdit(QLENumero);
}


const char *QCapturaDireccion::ObtenCP()
{
	return SISCOMObtenInformacionDelEdit(QLECP);
}


const char *QCapturaDireccion::ObtenColonia()
{
	return SISCOMObtenInformacionDelEdit(QLEColonia);
}


const char *QCapturaDireccion::ObtenMunicipio()
{
	return SISCOMObtenInformacionDelEdit(QLEMunicipio);
}


const char *QCapturaDireccion::ObtenEstado()
{
	return SISCOMObtenInformacionDelEdit(QLECEstado);
}


const char *QCapturaDireccion::ObtenReferencias()
{
	return SISCOMObtenInformacionDelEdit(QTEReferencias);
}

