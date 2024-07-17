#include <IMP_CapturaDatosFactura.h>


#include <zFactura.h>

#include <zSiscomQt3.h> 
#include <qpushbutton.h>
#include <qlineedit.h>

QCapturaDatosFactura::QCapturaDatosFactura(
			zFactura *pzFactura,
			QWidget *pQWParent,       
			const char *pchrPtrName,
			WFlags pWFlags):	      
			CapturaDatosFactura(pQWParent,pchrPtrName,pWFlags),
			zFacturaD(pzFactura)
{
IniciaVariables();
ConectaSlots();
exec();
}

QCapturaDatosFactura::~QCapturaDatosFactura()
{

}

void QCapturaDatosFactura::ConectaSlots()
{
connect(QLETotal,SIGNAL(returnPressed()),SLOT(SlotFocoAImporte()));
connect(QLEImporte,SIGNAL(returnPressed()),SLOT(SlotFocoAIVA()));
connect(QLEIVA,SIGNAL(returnPressed()),SLOT(SlotFocoAAceptar()));
connect(QPBAceptar,SIGNAL(clicke()),SLOT(SlotAceptar()));
}
void QCapturaDatosFactura::SlotFocoATotal()
{


}
void QCapturaDatosFactura::SlotAceptar()
{
  done(1);
}
void QCapturaDatosFactura::SlotFocoAImporte()
{
Factura()->Total(zSiscomQt3::Texto(QLETotal));
zSiscomQt3::Foco(QLEImporte);
}
void QCapturaDatosFactura::SlotFocoAIVA()
{
Factura()->Importe(zSiscomQt3::Texto(QLEImporte));
zSiscomQt3::Foco(QLEIVA);
}
void QCapturaDatosFactura::SlotFocoAAceptar()
{
Factura()->Iva(zSiscomQt3::Texto(QLEIVA));
zSiscomQt3::Foco(QPBAceptar);
}
void QCapturaDatosFactura::IniciaVariables()
{
zSiscomQt3::Foco(QLETotal);
}
zFactura *QCapturaDatosFactura::Factura()
{
  return zFacturaD;
}
