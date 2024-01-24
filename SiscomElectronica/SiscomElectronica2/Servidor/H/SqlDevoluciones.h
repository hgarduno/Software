#ifndef __SQLDEVOLUCIONES_H__
#define __SQLDEVOLUCIONES_H__
#include <SiscomDesarrollo2.h>

void SqlEliminaProductosVenta(SArgsSiscom *pSAgsSiscom);
void SqlGeneraEliminaProductosVenta(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			      LCamposSiscomPro2 **pLCSiscomPro2Prim,
			      LCamposSiscomPro2 **pLCSiscomPro2Act,
			      int *pintPtrNRegistros);

void SqlActualizaVentaCaja(SArgsSiscom *pSAgsSiscom);
void SqlGeneraActualizaVentaCaja(LCamposSiscomPro2 *pLCSiscomPro2Dat,
				LCamposSiscomPro2 *pLCSiscomPro2Ultimo,
			      LCamposSiscomPro2 **pLCSiscomPro2Prim,
			      LCamposSiscomPro2 **pLCSiscomPro2Act,
			      int *pintPtrNRegistros);

void SqlActualizaImporteOrden(SArgsSiscom *pSAgsSiscom);
void SqlGeneraActualizaImporteOrden(LCamposSiscomPro2 *pLCSiscomPro2Dat,
				LCamposSiscomPro2 *pLCSiscomPro2Ultimo,
			      LCamposSiscomPro2 **pLCSiscomPro2Prim,
			      LCamposSiscomPro2 **pLCSiscomPro2Act,
			      int *pintPtrNRegistros);


void SqlActualizaExistencia(SArgsSiscom *pSAgsSiscom);
void SqlGeneraActualizaExistencia(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			      LCamposSiscomPro2 **pLCSiscomPro2Prim,
			      LCamposSiscomPro2 **pLCSiscomPro2Act,
			      int *pintPtrNRegistros);


#endif
