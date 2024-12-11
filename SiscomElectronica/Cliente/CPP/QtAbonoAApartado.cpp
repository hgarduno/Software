#include <QtAbonoAApartado.h>

#include <zSiscomQt3.h>

#include <zSiscomRegistro.h> 
#include <zAbonoAApartado.h>
#include <zOrdenVenta.h>

#include <qlineedit.h>
#include <qpushbutton.h>
QtAbonoAApartado::QtAbonoAApartado(zOrdenVenta *pzOrden,
				   QWidget *pQWParent,
				   const char *pchrPtrName,
				   bool pbModal,
				   WFlags pWFlags):
				AbonoAApartado(pQWParent,pchrPtrName,pbModal,pWFlags),
				zOrden(pzOrden)
{
IniciaVariables();
ConectaSlots();
}


void QtAbonoAApartado::IniciaVariables()
{
zSiscomQt3::Foco(QLEImporte);
}
void QtAbonoAApartado::ConectaSlots()
{
connect(QLEImporte,SIGNAL(returnPressed()),SLOT(SlotFocoARegistrar()));
connect(QPBRegistrar,SIGNAL(clicked()),SLOT(SlotRegistrar()));
}

void QtAbonoAApartado::SlotRegistrar()
{
   Registrar();
}
void QtAbonoAApartado::SlotFocoARegistrar()
{
  zSiscomQt3::Foco(QPBRegistrar);
}
void QtAbonoAApartado::Registrar()
{

}
zAbonoAApartado *QtAbonoAApartado::AbonoAApartadoD()
{
zAbonoAApartado *lzAApartado;
  lzAApartado=new zAbonoAApartado(Orden()->IdVenta());
  lzAApartado->Importe(zSiscomQt3::Texto(QLEImporte));
  return lzAApartado;
}
zOrdenVenta *QtAbonoAApartado::Orden()
{
  return zOrden;
}
