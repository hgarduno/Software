#ifndef __PEDIDOS_H__
#define __PEDIDOS_H__
#include <SiscomDesarrollo2.h>
void ArgumentosPedidos(SArgsSiscom *pSAgsSiscom);
void RegistraPedido(SArgsSiscom *pSAgsSiscom);
SiscomOperaciones2 *ORegistraPedido();
SiscomOperaciones2 *OPedidosCliente();
SiscomOperaciones2 *OPedidoEntregado();

#endif
