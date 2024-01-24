#include <IMP_CapturaFecha.h>
#include <CQSiscomCom.h>

#include <qvariant.h>
#include <qlabel.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qpushbutton.h>
#include <IMP_QControlFecha.h>

QCapturaFecha::QCapturaFecha( QWidget* parent, const char* name, bool modal, WFlags fl )
    : CapturaFecha( parent, name, modal, fl )
{
   ConectaSlots();
   IniciaVariables();
   exec();
}

QCapturaFecha::~QCapturaFecha()
{
}
void QCapturaFecha::IniciaVariables()
{
   QCFecha->setFocus();
   QCFecha->ColocaFechaHoy();
   connect(QCFecha,
	   SIGNAL(Signal_EnterA_o()),
	   SLOT(S_PasaFocoAceptar()));
}

void QCapturaFecha::ConectaSlots()
{
	connect(QPBAceptar,
		SIGNAL(clicked()),
		SLOT(S_Aceptar()));
	connect(QPBCancelar,
		SIGNAL(clicked()),
		SLOT(S_Cancelar()));

}
void QCapturaFecha::S_PasaFocoAceptar()
{
	PasaFocoControl(QPBAceptar);
}
void QCapturaFecha::S_Aceptar()
{
	Opcion=QCapturaFecha::Aceptar;
	done(1);
}
void QCapturaFecha::S_Cancelar()
{

	Opcion=QCapturaFecha::Cancelar;
	done(1);
}
QCapturaFecha::BTN_Opciones QCapturaFecha::ObtenSeleccion()
{
	return Opcion;
}
QString QCapturaFecha::ObtenFecha()
{
	return QCFecha->ObtenFecha();
}
