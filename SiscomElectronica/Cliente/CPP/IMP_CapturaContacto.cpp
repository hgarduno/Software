#include <IMP_CapturaContacto.h>
#include <SISCOMComunicaciones++.h>
#include <Personas.h>
#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

QCapturaContacto::QCapturaContacto( QWidget* parent, const char* name, bool modal, WFlags fl )
    : CapturaContacto( parent, name, modal, fl ),
    intSeleccion(0)
{
	IniciaVariables();
	ConectaSlots();
	exec();
}

QCapturaContacto::~QCapturaContacto()
{
}
void QCapturaContacto::IniciaVariables()
{
	SiscomPasaFocoControl(QLENombre);
}
void QCapturaContacto::ConectaSlots()
{
	connect(QLENombre,
		SIGNAL(returnPressed()),
		SLOT(S_PasaFocoAPaterno()));
	connect(QLEAPaterno,
		SIGNAL(returnPressed()),
		SLOT(S_PasaFocoAMaterno()));
	connect(QLEAMaterno,
		SIGNAL(returnPressed()),
		SLOT(S_PasaFocoDescripcion()));
	connect(QLEDescripcion,
		SIGNAL(returnPressed()),
		SLOT(S_PasaFocoAceptar()));
	connect(QPBCancelar,
		SIGNAL(clicked()),
		SLOT(S_Cancelar()));
	connect(QPBAceptar,
		SIGNAL(clicked()),
		SLOT(S_Aceptar()));
}
void QCapturaContacto::S_PasaFocoAPaterno()
{
	SiscomPasaFocoControl(QLEAPaterno);
}
void QCapturaContacto::S_PasaFocoAMaterno()
{
	SiscomPasaFocoControl(QLEAMaterno);

}
void QCapturaContacto::S_PasaFocoDescripcion()
{
	SiscomPasaFocoControl(QLEDescripcion);
}
void QCapturaContacto::S_PasaFocoAceptar()
{
	SiscomPasaFocoControl(QPBAceptar);
}
void QCapturaContacto::S_Aceptar()
{
	PContacto=new Persona(
			SiscomObtenInformacionDelEdit(QLENombre),
			SiscomObtenInformacionDelEdit(QLEAPaterno),
			SiscomObtenInformacionDelEdit(QLEAMaterno),
			"",
			"",
			"",
			"",
			"",
			SiscomObtenInformacionDelEdit(QLEDescripcion));
	intSeleccion=1;
	done(1);
				
}
void QCapturaContacto::S_Cancelar()
{
	done(1);
}
Persona *QCapturaContacto::ObtenContacto()
{
	return PContacto;
}
int QCapturaContacto::ObtenSeleccion()
{
	return intSeleccion;
}
