#include <IMP_PagaConTransferencia.h>
#include <zOrdenVenta.h>
#include <zSiscomDesarrollo4.h>
#include <zSiscomQt3.h>

#include <zFormaPago.h>
#include <zFormaPagoTransferencia.h>

#include <qpushbutton.h>
#include <qlineedit.h>
#include <qbuttongroup.h>
#include <qradiobutton.h>
QPagaConTransferencia::QPagaConTransferencia(
				    zOrdenVenta *pzOrdenVenta,
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    bool pbModal,
				    WFlags pWFlags):
				PagaConTransferencia(pQWParent,pchrPtrName,pbModal,pWFlags),
				zOVenta(pzOrdenVenta),
				lEdoTrans(NoSeReflejo),
				zFrmPgoT(0)

{
IniciaVariables();
ConectaSlots();
exec();
}

QPagaConTransferencia::~QPagaConTransferencia()
{

}

void QPagaConTransferencia::ConectaSlots()
{
connect(QPBAceptar,SIGNAL(clicked()),SLOT(SlotAceptar()));
connect(QLETelefono,SIGNAL(returnPressed()),SLOT(SlotFocoASeReflejo()));
connect(QBGEdoTransferencia,SIGNAL(clicked(int)),SLOT(SlotEstadoTransferencia(int)));

}
void QPagaConTransferencia::SlotEstadoTransferencia(int pintEstado)
{
  QPBAceptar->setEnabled(true);
  zSiscomQt3::Foco(QPBAceptar);
     if(pintEstado==0)
     {
     lEdoTrans=YaSeReflejo;
     Orden()->FormaPago()->Transferencia()->YaSeReflejo("1");
     }
     else
     if(pintEstado==1)
     {
     Orden()->FormaPago()->Transferencia()->YaSeReflejo("0");
     lEdoTrans=NoSeReflejo;
     }
}
void QPagaConTransferencia::SlotAceptar()
{
   done(1); 
}
void QPagaConTransferencia::SlotFocoASeReflejo()
{
   Telefono();
   QRBSeReflejo->setFocus(); 
}
void QPagaConTransferencia::IniciaVariables()
{
LogSiscom("La orden %x",Orden()->FormaPago());
if(Orden()->FormaPago())
{
  if(!Orden()->FormaPago()->Transferencia())
  {
   LogSiscom("Iniciando la transferencia");
  Orden()->FormaPago()->Transferencia(IniciaTransferencia());
  }
  MostrandoDatos();
}
}
zOrdenVenta *QPagaConTransferencia::Orden()
{
   return zOVenta;
}
void QPagaConTransferencia::Telefono()
{
Orden()->FormaPago()->Telefono((const char *)QLETelefono->text());
}
void QPagaConTransferencia::MostrandoDatos()
{
  QLETelefono->setText(Orden()->FormaPago()->Telefono()); 
}
QPagaConTransferencia::EdoTransferencia QPagaConTransferencia::EstadoTransferencia()
{
   return lEdoTrans;
}
zFormaPagoTransferencia *QPagaConTransferencia::Transferencia()
{
  return zFrmPgoT;
}
zFormaPagoTransferencia *QPagaConTransferencia::IniciaTransferencia()
{
   return new zFormaPagoTransferencia;
}
