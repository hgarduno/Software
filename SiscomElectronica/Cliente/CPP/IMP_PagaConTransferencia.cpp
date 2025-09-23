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
				zFrmPgoT(0),
				intAceptar(0),
				intYaFormaPago(0)

{
IniciaVariables();
ConectaSlots();
exec();
}

QPagaConTransferencia::~QPagaConTransferencia()
{

}
int QPagaConTransferencia::Aceptar()
{
 return  lEdoTrans == YaSeReflejo ||
         lEdoTrans == NoSeReflejo;
}
void QPagaConTransferencia::ConectaSlots()
{
connect(QPBAceptar,SIGNAL(clicked()),SLOT(SlotAceptar()));
connect(QLETelefono,SIGNAL(returnPressed()),SLOT(SlotFocoAAceptar()));
connect(QLETelefono,
	SIGNAL(textChanged(const QString &)),
	SLOT(SlotCapturandoTelefono(const QString &)));
connect(QBGEdoTransferencia,SIGNAL(clicked(int)),SLOT(SlotEstadoTransferencia(int))); connect(QPBCancelar,SIGNAL(clicked()),SLOT(SlotCancelar())); }
void QPagaConTransferencia::SlotFocoAAceptar()
{
   Telefono();
   zSiscomQt3::Foco(QPBAceptar);
}
void QPagaConTransferencia::SlotCancelar()
{
lEdoTrans=Cancelar;
done(0);
}
void QPagaConTransferencia::SlotCapturandoTelefono(const QString &)
{
  HabilitandoAceptar();
}
void QPagaConTransferencia::SlotEstadoTransferencia(int pintEstado)
{
  zSiscomQt3::Foco(QPBAceptar);
  intYaFormaPago=1;
     if(pintEstado==0)
     YaSeReflejoTransferencia();
     else
     if(pintEstado==1)
     NoSeReflejoTransferencia();
}
void QPagaConTransferencia::SlotAceptar()
{
  intAceptar=1;
   done(1); 
}
void QPagaConTransferencia::SlotFocoASeReflejo()
{
/*
   Telefono();
   QRBSeReflejo->setFocus(); 
*/
}
void QPagaConTransferencia::NoSeReflejoTransferencia()
{
     Orden()->FormaPago()->Transferencia()->YaSeReflejo("0");
     lEdoTrans=NoSeReflejo;
     QLETelefono->setEnabled(true);
     zSiscomQt3::Foco(QLETelefono);
     /*HabilitandoAceptar(); 
     zSiscomQt3::Foco(QPBAceptar); */
}
void QPagaConTransferencia::YaSeReflejoTransferencia()
{
     Orden()->FormaPago()->Transferencia()->YaSeReflejo("1");
     lEdoTrans=YaSeReflejo;
     QPBAceptar->setEnabled(true);
     zSiscomQt3::Foco(QPBAceptar);
}
void QPagaConTransferencia::IniciaVariables()
{
if(Orden()->FormaPago())
{
  if(!Orden()->FormaPago()->Transferencia())
  Orden()->FormaPago()->Transferencia(IniciaTransferencia());
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
void QPagaConTransferencia::reject()
{
  
}
int QPagaConTransferencia::SeHabilitaAceptar()
{
/*
  return QLETelefono->text().length()==12 && 
  	intYaFormaPago                    &&
	Orden()->FormaPago()->Telefono();
*/

  return QLETelefono->text().length()==12 ;

}
void QPagaConTransferencia::HabilitandoAceptar()
{
   QPBAceptar->setEnabled(SeHabilitaAceptar()); 
}
