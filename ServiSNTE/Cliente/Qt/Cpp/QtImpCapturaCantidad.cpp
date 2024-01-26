#include <QtImpCapturaCantidad.h>

#include <qlineedit.h> 
#include <qpushbutton.h>
#include <zSiscomQt3.h>

QtImpCapturaCantidad::QtImpCapturaCantidad(
			QWidget *pQWParent,
			const char *pchrPtrName,
			bool pbModal,
			WFlags pWFlags):
		CapturaCantidad(pQWParent,pchrPtrName,pbModal,pWFlags),
		intAceptar(0)
{
 ConectaSlots();
 exec();
}
void QtImpCapturaCantidad::ConectaSlots()
{
	connect(QPBAceptar,
		SIGNAL(clicked()),
		SLOT(SlotAceptar()));
	connect(QPBCancelar,
		SIGNAL(clicked()),
		SLOT(SlotCancelar()));
	connect(QLECantidad,
		SIGNAL(returnPressed()),
		SLOT(SlotCantidad()));
}
void QtImpCapturaCantidad::SlotAceptar()
{
	intAceptar=1;
	done(1);
}
void QtImpCapturaCantidad::SlotCancelar()
{
	intAceptar=0;
	done(1);
}
void QtImpCapturaCantidad::SlotCantidad()
{
	zSiscomQt3::Foco(QPBAceptar);
}
void QtImpCapturaCantidad::reject()
{

}
void QtImpCapturaCantidad::Cantidad(QString *pQSCantidad)
{
   *pQSCantidad=QLECantidad->text();
}
int QtImpCapturaCantidad::Aceptar()
{
  return intAceptar;
}

