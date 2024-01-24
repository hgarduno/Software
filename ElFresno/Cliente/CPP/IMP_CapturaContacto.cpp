#include <IMP_CapturaContacto.h>

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

QCapturaContacto::QCapturaContacto( QWidget* parent, const char* name, bool modal, WFlags fl )
    : CapturaContacto( parent, name, modal, fl )
{
	PasaFocoControl(QLENombre);
	ConectaSlots();
	exec();
}

QCapturaContacto::~QCapturaContacto()
{
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
	connect(QPBAceptar,
		SIGNAL(clicked()),
		SLOT(S_Aceptar()));
	connect(QPBCancelar,
		SIGNAL(clicked()),
		SLOT(S_Cancelar()));

}
void QCapturaContacto::S_PasaFocoAPaterno()
{
	PasaFocoControl(QLEAPaterno);
}
void QCapturaContacto::S_PasaFocoAMaterno()
{
	PasaFocoControl(QLEAMaterno);
}
void QCapturaContacto::S_PasaFocoDescripcion()
{
	PasaFocoControl(QLEDescripcion);
}
void QCapturaContacto::S_PasaFocoAceptar()
{
	PasaFocoControl(QPBAceptar);
}
void QCapturaContacto::S_Aceptar()
{
	Seleccion=SISCOMGlobales::Aceptar;
        chrPtrNombre=SISCOMObtenInformacionDelEdit(QLENombre); 
	chrPtrAPaterno=SISCOMObtenInformacionDelEdit(QLEAPaterno);
	chrPtrAMaterno=SISCOMObtenInformacionDelEdit(QLEAMaterno); 
	chrPtrDescripcion=SISCOMObtenInformacionDelEdit(QLEDescripcion);
	done(1);
}
void QCapturaContacto::S_Cancelar()
{
	Seleccion=SISCOMGlobales::Cancelar;
	done(1);
}
SISCOMGlobales::BTN_Captura QCapturaContacto::ObtenOpcion()
{
	return Seleccion;
}
const char *QCapturaContacto::ObtenNombreCompleto()
{
 char *lchrPtrNmbCompleto=(char *)malloc(strlen(chrPtrNombre)+
		 			 strlen(chrPtrAPaterno) +
					 strlen(chrPtrAMaterno) +
					 4);

 	strcpy(lchrPtrNmbCompleto,chrPtrNombre);
	strcat(lchrPtrNmbCompleto," ");
	strcat(lchrPtrNmbCompleto,chrPtrAPaterno);
	strcat(lchrPtrNmbCompleto," ");
	strcat(lchrPtrNmbCompleto,chrPtrAMaterno);

 	return (const char *)lchrPtrNmbCompleto;	
}
const char *QCapturaContacto::ObtenNombre()
{
	return chrPtrNombre;
}
const char *QCapturaContacto::ObtenAPaterno()
{
	return chrPtrAPaterno;
}
const char *QCapturaContacto::ObtenAMaterno()
{
	return chrPtrAMaterno;
}
const char *QCapturaContacto::ObtenDescripcion()
{
	return chrPtrDescripcion;
}
