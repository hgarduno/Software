#include <QtManejadorOrden.h>
#include <IMP_SeleccionaOrden.h>
#include <IMP_ManejadorOrden.h>
#include <IMP_FormaPago.h>
#include <IMP_ComoPago.h>

#include <zConexionExpendio.h>

QtManejadorOrden::QtManejadorOrden(ManejadorOrden *pManOrden,
				   QManejadorOrden *pQManOrden):
				   ManOrden(pManOrden),
				   QManOrden(pQManOrden)
{

}

int QtManejadorOrden::SeleccionandoOrden()
{
  return SeleccionaOrden();
}

int QtManejadorOrden::SeleccionaOrden()
{
QSeleccionaOrden lQSelOrden(QManOrden->Orden()->Expendio());
lQSelOrden.exec();
if(lQSelOrden.Aceptar())
{
lQSelOrden.Orden()->Expendio(QManOrden->Orden()->Expendio());
zOrdVenta=lQSelOrden.Orden();
return 1;
}
else
return 0;

}

void QtManejadorOrden::ComoSePaga()
{
  FormaPago();
}

void QtManejadorOrden::FormaPago()
{


}

zOrdenVenta *QtManejadorOrden::Orden()
{
  return zOrdVenta;
}
