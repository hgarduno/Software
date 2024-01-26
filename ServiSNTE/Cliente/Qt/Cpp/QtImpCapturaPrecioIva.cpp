#include <QtImpCapturaPrecioIva.h>

#include <qlineedit.h> 
#include <qpushbutton.h>
#include <zSiscomQt3.h>

QtImpCapturaPrecioIva::QtImpCapturaPrecioIva(
			QWidget *pQWParent,
			const char *pchrPtrName,
			bool pbModal,
			WFlags pWFlags):
		CapturaPrecioIva(pQWParent,pchrPtrName,pbModal,pWFlags),
		intAceptar(0)
{
 IniciaVariables();
 ConectaSlots();
 exec();
}
void QtImpCapturaPrecioIva::ConectaSlots()
{
	connect(QPBAceptar,
		SIGNAL(clicked()),
		SLOT(SlotAceptar()));
	connect(QPBCancelar,
		SIGNAL(clicked()),
		SLOT(SlotCancelar()));
	connect(QLECantidad,
		SIGNAL(returnPressed()),
		SLOT(SlotFocoAIva()));
	connect(QLEIva,
		SIGNAL(returnPressed()),
		SLOT(SlotFocoAceptar()));
}
void QtImpCapturaPrecioIva::SlotFocoAceptar()
{
  zSiscomQt3::Foco(QPBAceptar);
}
void QtImpCapturaPrecioIva::SlotFocoAIva()
{
    zSiscomQt3::Foco(QLEIva);  
}
void QtImpCapturaPrecioIva::SlotAceptar()
{
	intAceptar=1;
	done(1);
}
void QtImpCapturaPrecioIva::SlotCancelar()
{
	intAceptar=0;
	done(1);
}
void QtImpCapturaPrecioIva::SlotCantidad()
{
	zSiscomQt3::Foco(QPBAceptar);
}
void QtImpCapturaPrecioIva::reject()
{

}
void QtImpCapturaPrecioIva::Cantidad(QString *pQSCantidad)
{
   *pQSCantidad=QLECantidad->text();
}

void QtImpCapturaPrecioIva::PrecioIva(QString *pQSCantidad,
				     QString *pQSIva)
{
   *pQSCantidad=QLECantidad->text();
   *pQSIva=QLEIva->text();
}

int QtImpCapturaPrecioIva::Aceptar()
{
  return intAceptar;
}

void QtImpCapturaPrecioIva::IniciaVariables()
{
   zSiscomQt3::Foco(QLECantidad); 
}
