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
#include <qlcdnumber.h>
#include <qtabwidget.h>
#include <zSiscomDesarrollo4.h>
#include <zConCuantoPago.h> 
#include <zFormaPagoTarjeta.h>
#include <zSiscomElectronica.h>
#include <zApartado.h>
#include <zFormaPagoTransferencia.h>
QComoPago::QComoPago(zOrdenVenta *pzOrdenVenta,
			QWidget *pQWParent,       
				    const char *pchrPtrName,
				    bool pbModal,
				    WFlags pWFlags):	      
				ComoPago(pQWParent,pchrPtrName,pbModal,pWFlags),
				FrmPago(Cancelar),
				zOVenta(pzOrdenVenta)
{
setFont(pQWParent->font());
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

connect(QTWComoPago,SIGNAL(currentChanged(QWidget *)),SLOT(SlotFormaPago(QWidget *)));

/* 
 * Mixquiahuala7 de Junio 2026 
 * Integrando en la forma de pago, combinar 2 metodos de pago
 */
connect(QPBEfectivo,SIGNAL(clicked()),SLOT(SlotCapturaEfectivo()));
connect(QPBTarjeta,SIGNAL(clicked()),SLOT(SlotCapturaTarjeta()));
connect(QPBTransferencia,SIGNAL(clicked()),SLOT(SlotCapturaTransferencia()));

connect(QLECaptura,SIGNAL(returnPressed()),SLOT(SlotCaptura()));
}
void QComoPago::SlotFormaPago(QWidget *)
{

}
void QComoPago::SlotCaptura()
{
QLECaptura->setEnabled(false);
  switch(ComoPagare())
  {
    case Efectivo:
    	ComoPagareEfectivo();
    break;
    case Tarjeta:
    	ComoPagareTarjeta();
    break;
    case Transferencia:
    	ComoPagareTransferencia();
    break;
  }
  PagoCompleto();
}
void QComoPago::SlotCapturandoConCuantoPaga(const QString &)
{
  QPBAceptar->setEnabled((intValidoPago && zSiscomQt3::TextoValido(QLEConCuantoPaga)));
}
void QComoPago::SlotCapturaEfectivo()
{
 QLECaptura->setEnabled(true);
 zSiscomQt3::Foco(QLECaptura);
 FrmComoPagare=Efectivo;
}

void QComoPago::SlotCapturaTarjeta()
{
 QLECaptura->setEnabled(true);
 zSiscomQt3::Foco(QLECaptura);
 FrmComoPagare=Tarjeta;
}

void QComoPago::SlotCapturaTransferencia()
{
 QLECaptura->setEnabled(true);
 zSiscomQt3::Foco(QLECaptura);
 FrmComoPagare=Transferencia;
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
   	QLEConCuantoPaga->setReadOnly(false); 
   break;
   case 1:
   	QPBAceptar->setEnabled(false);
   	Pagando(Transferencia);
   break;
   case 2:
   	QPBAceptar->setEnabled(true);
   	PagandoConTarjeta();
   break;
   }
}
void QComoPago::SlotAceptar()
{
    done(1); 
}
void QComoPago::IniciaVariables()
{
   QRBEfectivo->setFocus(); 
   Orden()->FormaPago(FormaPago());
   QLCDNTotal->display(Orden()->ImporteOrden());
   if(EsUnApartado())
   {
 	ControlesApartado();
	if(!Orden()->Apartado()->EstadoInt())
	QLEConCuantoPaga->setText(Orden()->Apartado()->PorPagar());
	else
	QLEConCuantoPaga->setText(Orden()->Apartado()->ACuenta());

   }
   else
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
QComoPago::FormaDePago QComoPago::ComoPagare()
{
    return FrmComoPagare;
}
void QComoPago::reject()
{
    FrmPago=Cancelar;
    done(1);
}
void QComoPago::PagandoConTarjeta()
{
	FrmPago=Tarjeta;
 	Orden()->FormaPago()->Transferencia(0);
	Orden()->FormaPago()->Tarjeta(SePagaConTarjeta());
 	QPBAceptar->setEnabled(true);
	 zSiscomQt3::Foco(QPBAceptar);

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
void QComoPago::ControlesApartado()
{
   QLEConCuantoPaga->setReadOnly(true); 
}
int QComoPago::EsUnApartado()
{
  if(Orden()->Apartado())
  {
	return 1;

  }
  else
  {
	return 0;
  }
}

zFormaPagoTarjeta *QComoPago::SePagaConTarjeta()
{
   return new zFormaPagoTarjeta;
}

void QComoPago::keyPressEvent(QKeyEvent *pQKETeclas)
{
    if(pQKETeclas->state()==Qt::ControlButton)
    TeclasEspeciales(pQKETeclas);

}
void QComoPago::TeclasEspeciales(QKeyEvent *pQKETeclas)
{
        if(pQKETeclas->key()==Qt::Key_R)
	TransferenciaReflejada();
}
void QComoPago::TransferenciaReflejada()
{
  LogSiscom("La transferencia ya se refeljo"); 
  Orden()->FormaPago()->Transferencia(new zFormaPagoTransferencia);
  Orden()->FormaPago()->Transferencia()->YaSeReflejo("1");
 FrmPago=Transferencia;
  done(1);
}

void QComoPago::PoniendoEfectivo()
{
zSiscomElectronica lzSisComoPago(zSiscomDesarrollo4::Conexion(),"FormandoComoPago");
Orden()->FormaPago()->Efectivo((const char *)QLECaptura->text());
Orden()->FormaPago()->Total(Orden()->ImporteOrden());
lzSisComoPago.FormandoComoPago(Orden()->FormaPago());
FrmPago=Combinado;
}
void QComoPago::PoniendoTransferencia()
{
zSiscomElectronica lzSisComoPago(zSiscomDesarrollo4::Conexion(),"FormandoComoPago");
Orden()->FormaPago()->Transferencia()->Importe((const char *)QLECaptura->text());
Orden()->FormaPago()->Total(Orden()->ImporteOrden());
lzSisComoPago.FormandoComoPago(Orden()->FormaPago());
FrmPago=Combinado;
}
void QComoPago::MemoriaTarjeta()
{
zFormaPagoTarjeta *lzFpTarjeta=new zFormaPagoTarjeta;
Orden()->FormaPago()->Tarjeta(lzFpTarjeta);
}
void QComoPago::PoniendoTarjeta()
{
zSiscomElectronica lzSisComoPago(zSiscomDesarrollo4::Conexion(),"FormandoComoPago");
MemoriaTarjeta();
Orden()->FormaPago()->Tarjeta()->Importe((const char *)QLECaptura->text());
Orden()->FormaPago()->Total(Orden()->ImporteOrden());
lzSisComoPago.FormandoComoPago(Orden()->FormaPago());
FrmPago=Combinado;
}
void QComoPago::MuestraComoPagara()
{
/*
 QLETarjeta->setText(Orden()->FormaPago()->PorPagar());
 QLETransferencia->setText(Orden()->FormaPago()->PorPagar());
 SiscomRegistroLog2(Orden()->FormaPago());
 */
}
void QComoPago::MostrandoTextoBoton(QPushButton *pQPBBoton,
				    const char *pchrPtrTexto)
{
QString lQStrTexto=pchrPtrTexto;
lQStrTexto+="\n";
lQStrTexto+=QLECaptura->text();
pQPBBoton->setText(lQStrTexto);
}
void QComoPago::ComoPagareEfectivo()
{
 MostrandoTextoBoton(QPBEfectivo,"Efectivo");
 PoniendoEfectivo();
 QLECaptura->setText(Orden()->FormaPago()->PorPagar());
 Orden()->ConCuantoPaga(Orden()->FormaPago()->Efectivo());
}
void QComoPago::ComoPagareTarjeta()
{
 MostrandoTextoBoton(QPBTarjeta,"Tarjeta");
 PoniendoTarjeta();
 QLECaptura->setText(Orden()->FormaPago()->PorPagar());
}
void QComoPago::ComoPagareTransferencia()
{
 MostrandoTextoBoton(QPBTransferencia,"Transferencia");
 PoniendoTransferencia();
 QLECaptura->setText(Orden()->FormaPago()->PorPagar());
}
void QComoPago::PagoCompleto()
{
int lintPagoCompleto;
lintPagoCompleto=Orden()->FormaPago()->PagoCompletoInt();
 if(lintPagoCompleto)
 {
  QPBAceptar->setEnabled(lintPagoCompleto);
  zSiscomQt3::Foco(QPBAceptar);
 }
}
