#ifndef __OPERACIONESPEDIDOS_H__
#define __OPERACIONESPEDIDOS_H__
#include <SiscomDesarrollo4/H/SiscomOperaciones.h>

const char *NombrePuntoEntrega(SiscomRegistroProL *pSisRegProLPtrPedido);
SiscomRegistroProL *DireccionEntregaPedido(SiscomOperaciones *pSisOpePtrDato);
const char *ObtenTipoEntregaPedido(SiscomRegistroProL *pSisRegProLPtrPedido);
const char *IdDireccionEntregaPedido(SiscomOperaciones *pSisOpePtrDato);

#endif
