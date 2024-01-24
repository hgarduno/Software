#ifndef __COMPRAS_H__
#define __COMPRAS_H__
#include <SiscomDesarrollo2.h>
SiscomOperaciones2 *OpCompras();
SiscomOperaciones2 *OpComprasExistenciaMinima();
void EnviaResultadoCompras(SArgsSiscom *pSAgsSiscom);
void ObtenSemestreAnterior(SArgsSiscom *);
void FiltraPorProducto(SArgsSiscom *);
#endif
