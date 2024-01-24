#include <zOrdenes.h>
#include <zOrdenVenta.h>
zOrdenes::zOrdenes()
{


}
void zOrdenes::Orden(zSiscomRegistro *pzSisRegOrden)
{
   (*this) << pzSisRegOrden;
}

int zOrdenes::OrdenFacturada(int pintOrden)
{
  return CampoRegistro(pintOrden,"idfactura") ? 1 : 0;
}
zOrdenVenta *zOrdenes::Orden(int pintNOrden)
{
    return (zOrdenVenta *)(*this)[pintNOrden];
}
int zOrdenes::HayMasDeUnaOrden()
{
  return NNodos()>1  ? 1 :0 ;
}
int zOrdenes::HayUnaOrden()
{
   return NNodos()==1 ? : 0;
}
const char *zOrdenes::IdFactura(int pintOrden)
{
     return (const char *)CampoRegistro(pintOrden,"idfactura");
}
