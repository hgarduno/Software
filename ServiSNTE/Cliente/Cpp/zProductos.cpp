#include <zProductos.h>
#include <zProducto.h>
#include <zProductoTransferencia.h>
zProductos::zProductos()
{


}
const char *zProductos::CodigoBarras(int pintNProducto)
{
zProducto *lzProducto=(zProducto *)(*this)[pintNProducto];
if(lzProducto)
 return lzProducto->CodigoBarras();
else
return (const char *)0;
}
const char *zProductos::Stock(int pintNProducto)
{
zProductoTransferencia *lzProdTransferencia=(zProductoTransferencia *)(*this)[pintNProducto];
if(lzProdTransferencia)
 return lzProdTransferencia->Stock();
else
return (const char *)0;

}

void zProductos::Cantidad(int pintNProducto,
			  const char *pchrPtrCantidad)
{
zProductoTransferencia *lzProdTransferencia=(zProductoTransferencia *)(*this)[pintNProducto];
if(lzProdTransferencia)
return lzProdTransferencia->Cantidad(pchrPtrCantidad);

}

void zProductos::Observaciones(int pintNProducto,
			  const char *pchrPtrCantidad)
{
zProductoTransferencia *lzProdTransferencia=(zProductoTransferencia *)(*this)[pintNProducto];
if(lzProdTransferencia)
lzProdTransferencia->Observacion(pchrPtrCantidad);

}
