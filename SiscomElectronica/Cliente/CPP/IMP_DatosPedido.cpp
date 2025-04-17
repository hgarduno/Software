#include <IMP_DatosPedido.h>
#include <QCtrlFechaHora.h>
#include <zSiscomElectronica.h>
#include <zProductoCotizar.h>
#include <zSiscomDesarrollo4.h>
#include <zSiscomRegistro.h>
#include <zSiscomQt3.h>
#include <zPedido.h>
#include <zOrdenVenta.h>
#include <zConexionExpendio.h>

#include <qlineedit.h>
#include <qtextedit.h>
#include <qpushbutton.h>
#include <qlcdnumber.h>

QDatosPedido::QDatosPedido(zOrdenVenta *pzOrdVenta,
				   QWidget *pQWParent,       
				    const char *pchrPtrName,
				    bool pbModal,
				    WFlags pWFlags):	      
				QtDatosPedido(pzOrdVenta,pQWParent,pchrPtrName,pbModal,pWFlags),
				intAceptar(0)
{
setFont(pQWParent->font());
IniciaVariables();
exec();
}

QDatosPedido::~QDatosPedido()
{

}

void QDatosPedido::SlotAceptar()
{
 QtDatosPedido::FormaDatosPedido();
  intAceptar=1;
  done(1);
}
void QDatosPedido::SlotCancelar()
{


}

int QDatosPedido::CambioPago(const char *pchrPtrPagaCon,
			      const char *pchrPtrImporte,
			       char *pchrPtrCambio,
			       char *pchrPtrDescripcion)
{
zSiscomElectronica lzSisECambio(Orden()->Expendio(),"CalculaCambioPago");
return lzSisECambio.CalculaCambioPago(pchrPtrPagaCon,
				      pchrPtrImporte,
				      pchrPtrCambio,
				      pchrPtrDescripcion);
}
int QDatosPedido::Aceptar()
{
  return intAceptar;
}
