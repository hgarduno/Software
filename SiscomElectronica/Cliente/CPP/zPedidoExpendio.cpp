#include <zPedidoExpendio.h>
#include <zSiscomCampo.h>
#include <zSiscomRegistros.h>
zPedidoExpendio::zPedidoExpendio()
{
  (*this)  			<< 
  new zSiscomCampo("Pedido") 	<<
  new zSiscomCampo("Productos");
}
void zPedidoExpendio::Pedido(zSiscomRegistro *pzSisRegPedido)
{

	AsociadoAlCampo("Pedido",pzSisRegPedido);
}
const char *zPedidoExpendio::Observaciones()
{
   return (const char *)CampoAsociado("Pedido","observaciones");
}
const char *zPedidoExpendio::IdPedido()
{
  return (const char *)CampoAsociado("Pedido","idpedido");
}
void zPedidoExpendio::Productos(zSiscomRegistros *pzSisRegsProductos)
{
	AsociadosAlCampo("Productos",pzSisRegsProductos);
}
zSiscomRegistros *zPedidoExpendio::Productos()
{
	return AsociadosDelCampo("Productos");
}
const char *zPedidoExpendio::IdProducto(int pintNProducto)
{
zSiscomRegistros *lzSisRegsProductos;
zSiscomRegistro *lzSisRegistro;
	if((lzSisRegsProductos=AsociadosDelCampo("Productos")))
	   return (const char *)((*lzSisRegsProductos)[pintNProducto])->Campo("idproducto");
	else
	return 0;
		
}

const char *zPedidoExpendio::Clave(int pintNProducto)
{
zSiscomRegistros *lzSisRegsProductos;
zSiscomRegistro *lzSisRegistro;
	if((lzSisRegsProductos=AsociadosDelCampo("Productos")))
	   return (const char *)((*lzSisRegsProductos)[pintNProducto])->Campo("clave");
	else
	return 0;
		
}

