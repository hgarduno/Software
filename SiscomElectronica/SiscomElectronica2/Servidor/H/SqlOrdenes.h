#ifndef __SQLORDENES_H__
#define __SQLORDENES_H__
#include <SiscomDesarrollo2.h>

void SqlOrdenesVendidas(SArgsSiscom *);
void SqlDetalleOrden(SArgsSiscom *);

void SqlAnexarOrdenContabilidad(SArgsSiscom *);

void SqlGeneraAnexarOrdenContabilidad(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			      LCamposSiscomPro2 **pLCSiscomPro2Prim,
			      LCamposSiscomPro2 **pLCSiscomPro2Act,
			      int *pintPtrNRegistros);
#endif
