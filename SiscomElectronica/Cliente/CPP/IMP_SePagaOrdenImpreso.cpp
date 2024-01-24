#include <IMP_SePagaOrdenImpreso.h>

#include <zOrdenVenta.h>


#include <zSiscomQt3.h>

#include <qlcdnumber.h>
#include <qpushbutton.h>
#include <qlineedit.h>
QSePagaOrdenImpreso::QSePagaOrdenImpreso(
				    zOrdenVenta *pzOrdVenta,
				    int pintImpresosOrden,
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    bool pbModal,
				    WFlags pWFlags):	      
				SePagaOrdenImpreso(pQWParent,pchrPtrName,pbModal,pWFlags),
				zOrdVenta(pzOrdVenta),
				intImpresosOrden(pintImpresosOrden),
				intSePagaCompleto(0)
{
IniciaVariables();
ConectaSlots();
exec();
}

QSePagaOrdenImpreso::~QSePagaOrdenImpreso()
{

}

void QSePagaOrdenImpreso::ConectaSlots()
{
 connect(QPBSePagaCompleto,SIGNAL(clicked()),SLOT(SlotSePagaCompleto())); 
 connect(QPBSeDaAdelanto,SIGNAL(clicked()),SLOT(SlotSeDaAdelanto()));
 connect(QPBAceptar,SIGNAL(clicked()),SLOT(SlotAceptar()));
 connect(QLEAdelanto,SIGNAL(returnPressed()),SLOT(SlotFocoAAceptar()));

}
void QSePagaOrdenImpreso::SlotFocoAAceptar()
{
  zSiscomQt3::Foco(QPBAceptar);
}
void QSePagaOrdenImpreso::SlotAceptar()
{
    intSePagaCompleto=0;
    done(1);

}
void QSePagaOrdenImpreso::SlotSeDaAdelanto()
{
  QLEAdelanto->setEnabled(true);
  zSiscomQt3::Foco(QLEAdelanto);
  QPBSePagaCompleto->setEnabled(false);
  QPBAceptar->setEnabled(true);
}
void QSePagaOrdenImpreso::SlotSePagaCompleto()
{
    intSePagaCompleto=1;
    done(1);
}
void QSePagaOrdenImpreso::IniciaVariables()
{
 QLCDNNImpresos->display(intImpresosOrden);
 QLCDNumImporte->display(zOrdVenta->ImporteOrden());

 zSiscomQt3::Foco(QPBSePagaCompleto);
}
void QSePagaOrdenImpreso::reject()
{
   
}

int QSePagaOrdenImpreso::SePagaCompleto()
{
 return intSePagaCompleto;
}
void QSePagaOrdenImpreso::ACuenta(char *pchrPtrAdelanto)
{
  strcpy(pchrPtrAdelanto,(const char *)QLEAdelanto->text());
}
