#include <IMP_CapturaTelefono.h>

#include <SISCOMComunicaciones++.h>
#include <MediosComunicacion.h>

#include <SISCOMComunicaciones++.h>

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

QCapturaTelefono::QCapturaTelefono( QWidget* parent, const char* name, bool modal, WFlags fl )
    : CapturaTelefono( parent, name, modal, fl ),
    intSeleccion(0)
{
	IniciaVariables();
	ConectaSlots();
	exec();
}

QCapturaTelefono::~QCapturaTelefono()
{
}
void QCapturaTelefono::IniciaVariables()
{
	SiscomPasaFocoControl(QLETelefono);
}
void QCapturaTelefono::ConectaSlots()
{
	connect(QLETelefono,
		SIGNAL(returnPressed()),
		SLOT(S_PasaFocoDescripcion()));
	connect(QLEDescripcion,
		SIGNAL(returnPressed()),
		SLOT(S_PasaFocoAceptar()));
	connect(QPBAceptar,
		SIGNAL(clicked()),
		SLOT(S_Aceptar()));
}
void QCapturaTelefono::S_PasaFocoDescripcion()
{
	SiscomPasaFocoControl(QLEDescripcion);
}
void QCapturaTelefono::S_PasaFocoAceptar()
{
	SiscomPasaFocoControl(QPBAceptar);
}
void QCapturaTelefono::S_Aceptar()
{
	MCTelefono=new MedioComunicacion("",
					 "",
					 SiscomObtenInformacionDelEdit(QLETelefono),
					 "Telefono",
					 SiscomObtenInformacionDelEdit(QLEDescripcion));
	intSeleccion=1;
	done(1);
}
void QCapturaTelefono::S_Cancelar()
{
	done(1);
}
int QCapturaTelefono::ObtenSeleccion()
{
	return intSeleccion;
}
MedioComunicacion *QCapturaTelefono::ObtenTelefono()
{
	return MCTelefono;
}
