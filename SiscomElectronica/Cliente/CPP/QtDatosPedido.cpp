#include <QtDatosPedido.h>

#include <zSiscomQt3.h>
#include <QCtrlFechaHora.h>
#include <zOrdenVenta.h>
#include <zPedido.h>
#include <zPuntoEntrega.h>

#include <qlineedit.h>
#include <qtextedit.h>
#include <qpushbutton.h>
#include <qlcdnumber.h>
#include <qmessagebox.h>
QtDatosPedido::QtDatosPedido(zOrdenVenta *pzOrdVenta,
			    QWidget *pQWParent,
			     const char *pchrPtrName,
			     bool pbModal,
			     WFlags pWFlags):
			     DatosPedido(pQWParent,pchrPtrName,pbModal,pWFlags),
			     zOrdVenta(pzOrdVenta)
{


}
void QtDatosPedido::ConectaSlots()
{
connect(QPBAceptar,SIGNAL(clicked()),SLOT(SlotAceptar()));
connect(QPBCancelar,SIGNAL(clicked()),SLOT(SlotCancelar()));
connect(QCtrFechaHora,SIGNAL(Signal_EnterMinuto()),SLOT(SlotFocoAPagaCon()));
connect(QLEPagaCon,SIGNAL(returnPressed()),SLOT(SlotFocoAObservaciones()));
connect(QLEPagaCon,SIGNAL(textChanged(const QString &)),SLOT(SlotCapturandoPagaCon(const QString &)));
}
void QtDatosPedido::SlotCapturandoPagaCon(const QString &)
{
  HabilitandoAceptar();
}
void QtDatosPedido::IniciaVariables()
{

    QCtrFechaHora->ColocaFechaHoy();
    QCtrFechaHora->setFocus();
    ConectaSlots();
    MuestraDatosPedido();
    QLEPagaCon->setText(Orden()->ImporteOrden());
    QLEPEntrega->setText(Orden()->Pedido()->PuntoEntrega()->PuntoEntrega());
}
void QtDatosPedido::HabilitandoAceptar()
{
bool lpbEstado=zSiscomQt3::TextoValido(QLEPagaCon);
	QPBAceptar->setEnabled(lpbEstado);
}
void QtDatosPedido::MuestraDatosPedido()
{
    if(Orden()->Pedido() && Orden()->Pedido()->FechaHoraE())
    {
	QCtrFechaHora->PonFecha(Orden()->Pedido()->FechaHoraE());
	QLEPagaCon->setText(Orden()->Pedido()->SePagaCon());
	QTEObservaciones->setText(Orden()->Pedido()->Observaciones());
    }
}
zOrdenVenta *QtDatosPedido::Orden()
{
	return zOrdVenta;
}

void QtDatosPedido::SlotFocoAObservaciones()
{
char lchrArrCambio[25],
	lchrArrDsc[128];
if(!CambioPago(zSiscomQt3::Texto(QLEPagaCon),
 	    Orden()->ImporteOrden(),
	    lchrArrCambio,
	    lchrArrDsc))
QMessageBox::information(this,"Aviso Sistema",lchrArrDsc);
else
{
 QLECambio->setText(lchrArrCambio);
 Orden()->Pedido()->Cambio(lchrArrCambio);
 zSiscomQt3::Foco(QTEObservaciones);
}
}
void QtDatosPedido::SlotFocoAAceptar()
{
  zSiscomQt3::Foco(QPBAceptar);
}
void QtDatosPedido::SlotFocoAPagaCon()
{
	zSiscomQt3::Foco(QLEPagaCon);
}
void QtDatosPedido::SlotAceptar()
{
}
void QtDatosPedido::SlotCancelar()
{
}
void QtDatosPedido::FormaDatosPedido()
{
Orden()->Pedido()->FechaHoraE((const char *)QCtrFechaHora->ObtenFechaHora());
Orden()->Pedido()->SePagaCon(zSiscomQt3::Texto(QLEPagaCon));
Orden()->Pedido()->Observaciones(zSiscomQt3::Texto(QTEObservaciones));
}
int QtDatosPedido::CambioPago(const char *,const char *,char *,char *)
{

return 0;
}

