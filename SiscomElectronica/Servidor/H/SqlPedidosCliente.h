#ifndef __SQLPEDIDOSCLIENTE_H__
#define __SQLPEDIDOSCLIENTE_H__
#include <SiscomDesarrollo4/H/SiscomOperaciones.h>

int SqlConsultaEstadosPedidosCliente(SiscomOperaciones *pSiscomOpePtrDato);
int SqlActualizaEstadoPedidoCliente(SiscomOperaciones *pSiscomOpePtrDato);

void UpdateFromEstadosPedidoCliente(SiscomOperaciones *pSiscomOpePtrDato,
                      SiscomRegistroProL *pSiscomRegProLPtrDato,
                      char *pchrPtrSql);
#endif
