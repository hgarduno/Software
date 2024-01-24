#include <IMP_CapturaTelefono.h>
#include <CQSiscomCom.h>

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

QCapturaTelefono::QCapturaTelefono( QWidget* parent, const char* name, bool modal, WFlags fl )
    : CapturaTelefono( parent, name, modal, fl )
{
ConectaSlots();
	exec();
}


QCapturaTelefono::~QCapturaTelefono()
{
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
	connect(QPBCancelar,
		SIGNAL(clicked()),
		SLOT(S_Cancelar()));	

	PasaFocoControl(QLETelefono);
}
void QCapturaTelefono::S_PasaFocoDescripcion()
{
	PasaFocoControl(QLEDescripcion);
}
void QCapturaTelefono::S_PasaFocoAceptar()
{
	PasaFocoControl(QPBAceptar);
}
void QCapturaTelefono::S_Aceptar()
{
	Seleccion=QCapturaTelefono::Aceptar;
	done(1);
}
void QCapturaTelefono::S_Cancelar()
{
	Seleccion=QCapturaTelefono::Cancelar;
	done(1);
}

QCapturaTelefono::BTN_Opciones QCapturaTelefono::ObtenOpcion()
{
	return Seleccion;
}
const char *QCapturaTelefono::ObtenTelefono()
{
	return strdup(SISCOMObtenInformacionDelEdit(QLETelefono));
}
const char *QCapturaTelefono::ObtenDescripcion()
{
	return strdup(SISCOMObtenInformacionDelEdit(QLEDescripcion));
}

const char *QCapturaTelefono::ObtenTelefonoYDescripcion()
{
const char *lchrPtrTelefono=SISCOMObtenInformacionDelEdit(QLETelefono),
     *lchrPtrDescripcion=SISCOMObtenInformacionDelEdit(QLEDescripcion);
char *lchrPtrRegreso=(char *)malloc(strlen(lchrPtrTelefono)+
				    strlen(lchrPtrDescripcion)+
				    4);


	strcpy(lchrPtrRegreso,lchrPtrTelefono);
	strcat(lchrPtrRegreso," ");
	strcat(lchrPtrRegreso,"[");
	strcat(lchrPtrRegreso,lchrPtrDescripcion);
	strcat(lchrPtrRegreso,"]");

	return (const char *)lchrPtrRegreso;
}
