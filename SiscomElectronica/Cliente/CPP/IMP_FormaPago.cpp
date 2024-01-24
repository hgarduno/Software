#include <IMP_FormaPago.h>

#include <zFormaPago.h>
#include <zSiscomDesarrollo4.h>
#include <zOrdenVenta.h>

#include <qtabwidget.h>
#include <qpushbutton.h> 


class zOrdenVenta;
QFormaPago::QFormaPago(QComoPago::FormaDePago pQCPFPago,
			zOrdenVenta *pzOrdenVenta,
		       QWidget *pQWParent,       
		       const char *pchrPtrName,
		       bool pbModal,
		       WFlags pWFlags):	      
			FormaPago(pQWParent,pchrPtrName,pWFlags),
			QCPForma(pQCPFPago),
			zOVenta(pzOrdenVenta)
{
IniciaVariables();
ConectaSlots();
exec();
}

QFormaPago::~QFormaPago()
{

}

void QFormaPago::ConectaSlots()
{
  connect(QPBAceptar,SIGNAL(clicked()),SLOT(SlotAceptar()));
}
void QFormaPago::SlotAceptar()
{
	done(1);
}
void QFormaPago::IniciaVariables()
{
 ActivaFormaPago();
}

zFormaPago *QFormaPago::ObtenFormaPago()
{
    return zFPago; 
}
void QFormaPago::ActivaFormaPago()
{
QWidget *lQWFormaPago;
  if(QCPForma==QComoPago::Transferencia)
  {
  	 lQWFormaPago=QTWFormaPago->page(1);
	 QTWFormaPago->setTabEnabled(lQWFormaPago,false);
	 QTWFormaPago->setCurrentPage(0);
  }
  else
  if(QCPForma==QComoPago::Tarjeta)
  {
  	 lQWFormaPago=QTWFormaPago->page(0);
	 QTWFormaPago->setTabEnabled(lQWFormaPago,false);
	 QTWFormaPago->setCurrentPage(1);

  }

}
zOrdenVenta *QFormaPago::Orden()
{
     return zOVenta;
}
