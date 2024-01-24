#include <IMP_CapturaInformacion.h>

#include <qvariant.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qpushbutton.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

QCapturaInformacion::QCapturaInformacion(const char *pchrPtrCaption,
					 const char *pchrPtrDato,
					 QWidget* parent, const char* name, bool modal, WFlags fl )
    : CapturaInformacion( parent, name, modal, fl )
{
	setCaption(pchrPtrCaption);
	QLDato->setText(pchrPtrDato);
	ConectaSlots();
	exec();
}

QCapturaInformacion::~QCapturaInformacion()
{
}
void QCapturaInformacion::ConectaSlots()
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
}
void QCapturaInformacion::S_PasaFocoAceptar()
{
	QPBAceptar->setFocus();
}
void QCapturaInformacion::S_Cancelar()
{
	intBoton=0;
	done(1);
}
void QCapturaInformacion::S_Aceptar()
{
	intBoton=1;
	done(1);

}
int QCapturaInformacion::ObtenCualBoton()
{
	return intBoton;
}
const char *QCapturaInformacion::ObtenDato()
{
	return (const char *)QLEDato->text();
}
