#include <zProductoPedido.h>
#include <zSiscomCampo.h>

zProductoPedido::zProductoPedido(const char *pchrPtrClave):
			zProducto(pchrPtrClave)
{
	(*this) 			<< 
	new zSiscomCampo("Cantidad")  	<<
	new zSiscomCampo("ObsProducto") <<
	new zSiscomCampo("IdPedido")	<<
	new zSiscomCampo("IdProducto");
}

void zProductoPedido::Cantidad(const char *pchrPtrCantidad)
{
	ActualizaCampo("Cantidad",(const unsigned char *)pchrPtrCantidad);
}
void zProductoPedido::ObsProducto(const char *pchrPtrObsProducto)
{
	ActualizaCampo("ObsProducto",(const unsigned char *)pchrPtrObsProducto);
}
void zProductoPedido::IdPedido(const char *pchrPtrIdPedido)
{
	ActualizaCampo("IdPedido",(const unsigned char *)pchrPtrIdPedido);
}
void zProductoPedido::IdProducto(const char *pchrPtrIdProducto)
{
	ActualizaCampo("IdProducto",(const unsigned char *)pchrPtrIdProducto);
}

const char *zProductoPedido::Cantidad()
{
	return (const char *)(*this)["Descripcion"];
}
const char *zProductoPedido::ObsProducto()
{
	return (const char *)(*this)["ObsProducto"];
}
