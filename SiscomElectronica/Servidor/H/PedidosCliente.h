#ifndef __PEDIDOSCLIENTE_H__
#define __PEDIDOSCLIENTE_H__

#include <SiscomDesarrollo4/H/SiscomOperaciones.h>
void EstadosPedidosCliente(int pintSocket,
		SiscomRegistroProL *pSiscomRegProLPtrPrim,
		SiscomRegistroProL *pSiscomRegProLPtrAct);

void ActualizaEstadoPedidoCliente(int pintSocket,
		SiscomRegistroProL *pSiscomRegProLPtrPrim,
		SiscomRegistroProL *pSiscomRegProLPtrAct);

int EnviandoEstadosPedidosCliente(SiscomOperaciones *pSisOpePtrDatos);
int EnviaActualizaEstadoPedidoCliente(SiscomOperaciones *pSisOpePtrDatos);
int AgregaArgumentosEstadoPedidoCliente(SiscomOperaciones *pSiscomOpePtrDato);

int FechaHoraCambioEstado(SiscomOperaciones *pSiscomOpePtrDato);
#endif
