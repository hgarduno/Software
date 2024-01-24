#ifndef __PEDIDOSEXPENDIO_H__
#define __PEDIDOSEXPENDIO_H__
#include <SiscomDesarrollo4/H/SiscomOperaciones.h>
int EnviandoPedidoExpendioHoy(SiscomOperaciones *pSiscomOpePtrDato);

void ActualizaInventarioParaPedido(int pintSocket,
			SiscomRegistroProL *pSiscomRegProLPtrPrim,
			SiscomRegistroProL *pSiscomRegProLPtrAct);

void TransfiereBodegaExpendioParaPedido(int pintSocket,
			SiscomRegistroProL *pSiscomRegProLPtrPrim,
			SiscomRegistroProL *pSiscomRegProLPtrAct);
void PedidoExpendioHoy(int pintSocket,
			SiscomRegistroProL *pSiscomRegProLPtrPrim,
			SiscomRegistroProL *pSiscomRegProLPtrAct);

void ProductoAPedidoExpendio(int pintSocket,
			SiscomRegistroProL *pSiscomRegProLPtrPrim,
			SiscomRegistroProL *pSiscomRegProLPtrAct);

void IniciaPedidoExpendioHoy(int pintSocket,
			SiscomRegistroProL *pSiscomRegProLPtrPrim,
			SiscomRegistroProL *pSiscomRegProLPtrAct);

void EliminaProductoPedido(int pintSocket,
			SiscomRegistroProL *pSiscomRegProLPtrPrim,
			SiscomRegistroProL *pSiscomRegProLPtrAct);

void ActualizaProductoPedido(int pintSocket,
		SiscomRegistroProL *pSiscomRegProLPtrPrim,
		SiscomRegistroProL *pSiscomRegProLPtrAct);
void ActualizaObservacionesPedido(int pintSocket,
		SiscomRegistroProL *pSiscomRegProLPtrPrim,
		SiscomRegistroProL *pSiscomRegProLPtrAct);


void RegistraPedido(int pintSocket,
		SiscomRegistroProL *pSiscomRegProLPtrPrim,
		SiscomRegistroProL *pSiscomRegProLPtrAct);
int AgregaFechaSinHora(SiscomOperaciones *pSiscomOpePtrDato);
int EnviaInicioPedidoExpendioHoy(SiscomOperaciones *pSiscomOpePtrDato);
int EnviaRegistroPedido(SiscomOperaciones *pSiscomOpePtrDato);
int ArgumentoIniciaPedidoExpendio(SiscomOperaciones *pSiscomOpePtrDato);
int ArgumentoServidores(SiscomOperaciones *pSiscomOpePtrDato);
int ArgumentoEstadoPedidoExpendioProducto(SiscomOperaciones *pSiscomOpePtrDato);
int ArgumentoPedidoExpendioAMatriz(SiscomOperaciones *pSiscomOpePtrDato);
int ArgumentoExistenciaExpendioBodegaProducto(SiscomOperaciones *pSiscomOpePtrDato);
int GeneraIdPedidoExpendio(SiscomOperaciones *pSiscomOpePtrDato);
int GeneraIdProducto(SiscomOperaciones *pSiscomOpePtrDato);
int ArgumentoIniciaPedidoExpendio(SiscomOperaciones *pSiscomOpePtrDato);
int EnviandoProductoPedidoExpendio(SiscomOperaciones *pSiscomOpePtrDato);
int ActualizandoInventarioParaPedido(SiscomOperaciones *pSiscomOpePtrDato);

int ValidaExistenciaBodegaVsCantidad(SiscomOperaciones *pSisOpePtrDato);


int ERRORCantidadVsExBodega(SiscomOperaciones *pSisOpePtrDato);
#endif
