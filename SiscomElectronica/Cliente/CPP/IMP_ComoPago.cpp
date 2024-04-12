#include <IMP_ComoPago.h>
#include <IMP_PagaConTransferencia.h>
#include <zOrdenVenta.h>
#include <zFormaPago.h>
#include <zSiscomQt3.h>
#include <qpushbutton.h>
#include <qbuttongroup.h>
QComoPago::QComoPago(zOrdenVenta *pzOrdenVenta,
			QWidget *pQWParent,       
				    const char *pchrPtrName,
				    bool pbModal,
				    WFlags pWFlags):	      
				ComoPago(pQWParent,pchrPtrName,pbModal,pWFlags),
				FrmPago(Cancelar),
				zOVenta(pzOrdenVenta)
{
IniciaVariables();
ConectaSlots();
exec();
}

QComoPago::~QComoPago()
{

}

void QComoPago::ConectaSlots()
{
connect(QPBAceptar,SIGNAL(clicked()),SLOT(SlotAceptar()));
connect(QPBCancelar,SIGNAL(clicked()),SLOT(SlotCancelar()));
connect(QBGComoPago,SIGNAL(clicked(int)),SLOT(SlotComoPago(int)));

}
void QComoPago::SlotCancelar()
{
	FrmPago=Cancelar;
	done(1);
}
void QComoPago::SlotComoPago(int pintOpcion)
{
  switch(pintOpcion) 
  {
   case 0:
    	FrmPago=Efectivo;
	QPBAceptar->setEnabled(true);
	zSiscomQt3::Foco(QPBAceptar);
   break;
   case 1:
   	QPBAceptar->setEnabled(false);
   	Pagando(Transferencia);
   break;
   case 2:
   	QPBAceptar->setEnabled(false);
   	Pagando(Tarjeta);
   break;
   }
}
void QComoPago::SlotAceptar()
{
    done(1); 
}
void QComoPago::IniciaVariables()
{
   Orden()->FormaPago(FormaPago());
}
zOrdenVenta *QComoPago::Orden()
{
  return zOVenta;
}

QComoPago::FormaDePago QComoPago::ComoPague()
{
    return FrmPago;
}
void QComoPago::reject()
{
    FrmPago=Cancelar;
    done(1);
}
void QComoPago::Pagando(QComoPago::FormaDePago pQFPago)
{
QPagaConTransferencia lQPCTransferencia(Orden());
if(lQPCTransferencia.Aceptar())
{
 FrmPago=Transferencia;
 QPBAceptar->setEnabled(true);
 zSiscomQt3::Foco(QPBAceptar);
}
 else
 FrmPago=Cancelar;
}

zFormaPago *QComoPago::FormaPago()
{
   return new zFormaPago(); 
}
