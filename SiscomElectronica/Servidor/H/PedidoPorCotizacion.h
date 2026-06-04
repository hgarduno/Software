#ifndef __PEDIDOPORCOTIZACION_H__
#define __PEDIDOPORCOTIZACION_H__
#include <SiscomDesarrollo4/H/SiscomOperaciones.h>
#include <SiscomDesarrollo4/H/SiscomFuncionesComunes.h>
void PedidoPorCotizacion(int pintSocket,
			   SiscomRegistroProL *pSiscomRegProLPtrPrim,
			   SiscomRegistroProL *pSiscomRegProLPtrAct);

int EnviaPedidoPorCotizacion(SiscomOperaciones *pSisOpePtrDatos);
int ArgumentoPedidoPorCotizacion(SiscomOperaciones *pSiscomOpePtrDato);
int AgregaFechaYIdPedidoPorCotizacion(SiscomOperaciones *);
#endif
