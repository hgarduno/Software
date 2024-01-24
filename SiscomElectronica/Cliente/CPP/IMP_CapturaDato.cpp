#include <IMP_CapturaDato.h>

#include <qvariant.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
QCapturaDato::QCapturaDato(const char *pchrPtrCaption,
			   const char *pchrPtrEtiqueta,
			   const char *pchrPtrTextoInicial,
			   QWidget* parent,
			   const char* name,
			   bool modal,
			   WFlags fl )
    : CapturaDato( parent, name, modal, fl )
{
	setCaption(pchrPtrCaption);
	PonTextoInicial(pchrPtrTextoInicial);
	QLEtiqueta->setText(pchrPtrEtiqueta);
	connect(QLEDato,
		SIGNAL(returnPressed()),
		SLOT(S_Capturo()));
	exec();
}
QCapturaDato::QCapturaDato(const char *pchrPtrCaption,
			   const char *pchrPtrEtiqueta,
			   QWidget* parent,
			   const char* name,
			   bool modal,
			   WFlags fl )
    : CapturaDato( parent, name, modal, fl )
{
	setCaption(pchrPtrCaption);
	QLEtiqueta->setText(pchrPtrEtiqueta);
	connect(QLEDato,
		SIGNAL(returnPressed()),
		SLOT(S_Capturo()));
	exec();
}

QCapturaDato::~QCapturaDato()
{
}
void QCapturaDato::PonTextoInicial(const char *pchrPtrDato)
{
	QLEDato->setText(pchrPtrDato);
	QLEDato->selectAll();
}
void QCapturaDato::S_Capturo()
{
	done(1);
}
void QCapturaDato::ObtenDato(char *pchrPtrDato)
{
	strcpy(pchrPtrDato,
	       (const char *)QLEDato->text());
}
float QCapturaDato::ObtenDatoFloat()
{
return (QLEDato->text()).toFloat();
}

int QCapturaDato::ObtenDatoInt()
{
return (QLEDato->text()).toInt();
}
