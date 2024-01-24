#ifndef __SQLPEDIDOS_H__
#define __SQLPEDIDOS_H__
#include <SiscomDesarrollo2.h>
void SqlPedidosCliente(SArgsSiscom *);

void SqlRegistraPedido(SArgsSiscom *pSAgsSiscom);
void SqlGeneraPedido(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			 LCamposSiscomPro2 **pLCSiscomPro2Prim,
			 LCamposSiscomPro2 **pLCSiscomPro2Act,
			 int *pintPtrNRegistros);
/*
 *
 * Cambiar los nombres de estas dos 
 * funciones por algo referente a actualizar
 *
 */

void SqlRegistraPedidoEntregado(SArgsSiscom *pSAgsSiscom);
void SqlGeneraPedidoEntregado(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			 LCamposSiscomPro2 **pLCSiscomPro2Prim,
			 LCamposSiscomPro2 **pLCSiscomPro2Act,
			 int *pintPtrNRegistros);



void SqlRegistraSeguimientoPedido(SArgsSiscom *pSAgsSiscom);
void SqlGeneraSeguimientoPedido(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			 LCamposSiscomPro2 **pLCSiscomPro2Prim,
			 LCamposSiscomPro2 **pLCSiscomPro2Act,
			 int *pintPtrNRegistros);
#endif
