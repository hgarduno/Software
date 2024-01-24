#include <IMP_OpcionCerrar.h>

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

QOpcionCerrar::QOpcionCerrar( QWidget* parent, const char* name, bool modal, WFlags fl )
    : OpcionCerrar( parent, name, modal, fl )
{
	ConectaSlots();
	exec();
}


QOpcionCerrar::~QOpcionCerrar()
{
}


void QOpcionCerrar::closeEvent(QCloseEvent *)
{

}
void QOpcionCerrar::ConectaSlots()
{
	connect(QPBCancelar,
		SIGNAL(clicked()),
		SLOT(S_Cancelar()));
	connect(QPBRealizarVenta,
		SIGNAL(clicked()),
		SLOT(S_RealizarVenta()));
}
void QOpcionCerrar::S_Cancelar()
{
	OpcSeleccionada=QOpcionCerrar::Cancelar_Venta;
	done(1);
}
void QOpcionCerrar::S_RealizarVenta()
{
	OpcSeleccionada=QOpcionCerrar::Realizar_Venta;
	done(1);
}
QOpcionCerrar::Opciones QOpcionCerrar::ObtenSeleccion()
{
	return OpcSeleccionada;
}
