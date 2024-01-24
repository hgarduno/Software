#ifndef __SQLCORTECAJA_H__
#define __SQLCORTECAJA_H__
#include <SiscomDesarrollo2.h>
void SqlInsertaDetalleCorteCaja(SArgsSiscom *);
void SqlGeneraInsertaDetalleCorteCaja(LCamposSiscomPro2 *pLCSiscomPro2,
                                 LCamposSiscomPro2 **pLCSiscomPro2Prim,
				 LCamposSiscomPro2 **pLCSiscomPro2Act,
				 int *pintPtrNRegistros);
void SqlInsertaCorteCaja(SArgsSiscom *);
void SqlGeneraInsertaCorteCaja(LCamposSiscomPro2 *pLCSiscomPro2,
                                 LCamposSiscomPro2 **pLCSiscomPro2Prim,
				 LCamposSiscomPro2 **pLCSiscomPro2Act,
				 int *pintPtrNRegistros);

void SqlInsertaCorteCaja(SArgsSiscom *pSAgsSiscom);
void SqlGeneraInsertaCorteCaja(LCamposSiscomPro2 *pLCSiscomPro2,
                                 LCamposSiscomPro2 **pLCSiscomPro2Prim,
				 LCamposSiscomPro2 **pLCSiscomPro2Act,
				 int *pintPtrNRegistros);

void SqlActualizaEstadoCaja(SArgsSiscom *pSAgsSiscom);
void SqlGeneraActualizaEstadoCaja(LCamposSiscomPro2 *pLCSiscomPro2,
                                 LCamposSiscomPro2 **pLCSiscomPro2Prim,
				 LCamposSiscomPro2 **pLCSiscomPro2Act,
				 int *pintPtrNRegistros);

#endif
