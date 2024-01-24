#ifndef __SQLCONTABILIDAD_H__
#define __SQLCONTABILIDAD_H__
#include <SiscomDesarrollo2.h>

void SqlProductosVendidosFacturados(SArgsSiscom *);
void SqlComprasProductosVendidos(SArgsSiscom *);


void SqlInsertaResultadoContable(SArgsSiscom *);
void SqlGeneraInsertaResultadoContable(LCamposSiscomPro2 *pLCSiscomPro2,
				   LCamposSiscomPro2 **pLCSiscomPro2Prim,
				   LCamposSiscomPro2 **pLCSiscomPro2Act,
				   int *pintPtrNRegistros);
#endif
