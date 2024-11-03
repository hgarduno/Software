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

void QtManejadorOrden::SeleccionandoOrden()
{
  SeleccionaOrden();
  AsignaOrdenCotizacion();
}

void QtManejadorOrden::SeleccionaOrden()
{
QSeleccionaOrden lQSelOrden(QManOrden->Orden()->Expendio());
lQSelOrden.exec();
lQSelOrden.Orden()->Expendio(QManOrden->Orden()->Expendio());
zOrdVenta=lQSelOrden.Orden();
}

void QtManejadorOrden::AsignaOrdenCotizacion()
{
QManOrden->Orden()->AgregandoProductos(zOrdVenta->Productos());
QManOrden->ReCotizandoOrden();
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
