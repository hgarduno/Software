#include <IMP_ComoPago.h>
#include <IMP_PagaConTransferencia.h>
#include <zOrdenVenta.h>
#include <zFormaPago.h>
#include <zSiscomQt3.h>
#include <qpushbutton.h>
#include <qbuttongroup.h>
#include <qlineedit.h>
#include <qradiobutton.h>
#include <qmessagebox.h> 
#include <zSiscomDesarrollo4.h>
#include <zConCuantoPago.h> 
#include <zSiscomElectronica.h>
#include <zApartado.h>
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
connect(QLEConCuantoPaga,SIGNAL(returnPressed()),SLOT(SlotFocoAAceptar()));
connect(QLEConCuantoPaga,
	SIGNAL(textChanged(const QString &)),
	SLOT(SlotCapturandoConCuantoPaga(const QString &)));
}
void QComoPago::SlotCapturandoConCuantoPaga(const QString &)
{
  QPBAceptar->setEnabled((intValidoPago && zSiscomQt3::TextoValido(QLEConCuantoPaga)));
}
void QComoPago::SlotFocoAAceptar()
{
	zSiscomQt3::Foco(QPBAceptar);
	VerificoConCuantoPago();
}
void QComoPago::SlotCancelar()
{
	FrmPago=Cancelar;
	done(1);
}
void QComoPago::SlotComoPago(int pintOpcion)
{
LogSiscom("la forma de pago %d",pintOpcion);
  switch(pintOpcion) 
  {
   case 0:
   	PagandoEfectivo();
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
   QRBEfectivo->setFocus();
   QLEConCuantoPaga->setText(Orden()->ImporteOrden());
}
void QComoPago::PagandoEfectivo()
{
    	FrmPago=Efectivo;
	zSiscomQt3::Foco(QLEConCuantoPaga);
	Orden()->FormaPago()->Transferencia(0);
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
QPagaConTransferencia::EdoTransferencia lEdoTransferencia;

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
int QComoPago::VerificandoConCuantoPago()
{
zSiscomElectronica lzSisEVerificaCCP(Conexion(),"VerificaConCuantoPago");
zConCPago=ConCuantoPago();
return (intValidoPago=lzSisEVerificaCCP.VerificaConCuantoPago(zConCPago));
}
zConCuantoPago *QComoPago::ConCuantoPago()
{
zConCuantoPago *lzCCPago;
 lzCCPago=new zConCuantoPago(zSiscomQt3::Texto(QLEConCuantoPaga),Orden()->ImporteOrden());
 lzCCPago->IdTipoOrden(Orden()->IdTipoOrden());
 if(Orden()->Apartado())
  lzCCPago->ACuenta(Orden()->Apartado()->ACuenta());

return lzCCPago;
}
zSiscomConexion *QComoPago::Conexion()
{
  return (zSiscomConexion *)gzSiscomConexion;
}
void QComoPago::VerificoConCuantoPago()
{

   if(!VerificandoConCuantoPago())
   {
     QPBAceptar->setEnabled(false);
     zSiscomQt3::Foco(QLEConCuantoPaga);
     QMessageBox::information(this,"Aviso Sistema","El pago no alcanza");
   }
   else
   {
   	QPBAceptar->setEnabled(true);
	zSiscomQt3::Foco(QPBAceptar);
	Orden()->ConCuantoPaga(zSiscomQt3::Texto(QLEConCuantoPaga));
   }
intValidoPago=0;
} 
