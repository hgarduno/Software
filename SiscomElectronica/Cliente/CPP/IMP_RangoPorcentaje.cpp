#include <IMP_RangoPorcentaje.h>
#include <SISCOMComunicaciones++.h>

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

QRangoPorcentaje::QRangoPorcentaje( QWidget* parent, const char* name, bool modal, WFlags fl )
    : RangoPorcentaje( parent, name, modal, fl ),
    intOpcion(0)
{
	IniciaVariables();
	ConectaSlots();
	exec();
}
	

QRangoPorcentaje::~QRangoPorcentaje()
{
}
void QRangoPorcentaje::IniciaVariables()
{
	SiscomPasaFocoControl(QLEBajo);
}
int QRangoPorcentaje::ObtenOpcion()
{
	return intOpcion;
}
void QRangoPorcentaje::ObtenRango(char *pchrPtrBajo,
				  char *pchrPtrAlto)
{
	strcpy(pchrPtrBajo,(const char *)QLEBajo->text());
	strcpy(pchrPtrAlto,(const char *)QLEAlto->text());
}
void QRangoPorcentaje::ConectaSlots()
{
	connect(QLEBajo,
		SIGNAL(returnPressed()),
		SLOT(S_PasaFocoPorcentajeAlto()));
	connect(QLEAlto,
		SIGNAL(returnPressed()),
		SLOT(S_PasaFocoAceptar()));
	connect(QPBAceptar,
		SIGNAL(clicked()),
		SLOT(S_Aceptar()));
	
}
void QRangoPorcentaje::S_PasaFocoPorcentajeAlto()
{
	SiscomPasaFocoControl(QLEAlto);	
}
void QRangoPorcentaje::S_PasaFocoAceptar()
{
	SiscomPasaFocoControl(QPBAceptar);
}
void QRangoPorcentaje::S_Aceptar()
{
	intOpcion=1;
	done(1);
}
void QRangoPorcentaje::S_Cancelar()
{
	intOpcion=0;
	done(0);
}
