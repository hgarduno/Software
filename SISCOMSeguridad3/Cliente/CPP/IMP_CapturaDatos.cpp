#include <IMP_CapturaDatos.h>

#include <SISCOMComunicaciones++.h>
#include <CQSiscomCom.h>

#include <qvariant.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qpushbutton.h>

CQSisCapturaDatos::CQSisCapturaDatos(QString pQSDato,
				      QWidget* parent,
				       const char* name,
				         bool modal, 
				        WFlags fl )
    : CapturaDatos( parent, name, modal, fl ),
      QSDato(pQSDato)
{
	MuestraTexto(QLEDatos,QSDato);
	ConectaSlots();
	exec();
}
CQSisCapturaDatos::~CQSisCapturaDatos()
{
}
void CQSisCapturaDatos::ConectaSlots()
{
	connect(QPBAceptar,
		SIGNAL(clicked()),
		SLOT(SlotAceptar()));
	connect(QPBCancelar,
		SIGNAL(clicked()),
		SLOT(SlotCancelar()));
}
void CQSisCapturaDatos::SlotAceptar()
{
	BTN_Boton=BTN_Aceptar;
	done(1);
}
void CQSisCapturaDatos::SlotCancelar()
{
	BTN_Boton=BTN_Cancelar;
	done(2);
}
CQSisCapturaDatos::BTN_Seleccion CQSisCapturaDatos::ElBotonSeleccionado()
{
	return BTN_Boton;
}
QString CQSisCapturaDatos::ObtenDatoNuevo()
{
	return QLEDatos->text();
}
