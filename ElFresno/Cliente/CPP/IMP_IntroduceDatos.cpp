#include <IMP_IntroduceDatos.h>
#include <CQSiscomCom.h>

#include <qvariant.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qpushbutton.h>
QIntroduceDatos::QIntroduceDatos(const char *pchrPtrNombre,
				 const char *pchrPtrCaption,
				 QWidget* parent, const char* name, bool modal, WFlags fl )
    : IntroduceDatos( parent, name, modal, fl )
{
	ConectaSlots();
	QLDato->setText(pchrPtrNombre);
	QPBAceptar->setEnabled(false);
	setCaption(pchrPtrCaption);
	exec();
}

QIntroduceDatos::~QIntroduceDatos()
{
}
void QIntroduceDatos::ConectaSlots()
{
	connect(QLEDato,
		SIGNAL(returnPressed()),
		SLOT(S_PasaFocoAceptar()));
	connect(QPBAceptar,
		SIGNAL(clicked()),
		SLOT(S_Aceptar()));
	connect(QPBCancelar,
		SIGNAL(clicked()),
		SLOT(S_Cancelar()));
	connect(QLEDato,
		SIGNAL(textChanged(const QString &)),
		SLOT(S_CambioTexto(const QString &)));
}
void QIntroduceDatos::S_CambioTexto(const QString &pQSTexto)
{

	QPBAceptar->setEnabled(!pQSTexto.isEmpty());

}
void QIntroduceDatos::S_PasaFocoAceptar()
{
	 QPBAceptar->setEnabled(true);
	PasaFocoControl(QPBAceptar);
}

void QIntroduceDatos::S_Cancelar()
{
	Boton=QIntroduceDatos::Cancelar;
	done(1);
}
void QIntroduceDatos::S_Aceptar()
{
	Boton=QIntroduceDatos::Aceptar;
	done(1);
}
QIntroduceDatos::BTN_Acciones QIntroduceDatos::ObtenBoton()
{
	return QIntroduceDatos::Boton;
}
QString QIntroduceDatos::ObtenDato()
{
	return QLEDato->text();
}
