#ifndef __SQLVENTASCAJA_H__
#define __SQLVENTASCAJA_H__
#include <SiscomDesarrollo2.h>
void SqlVentasPorCaja(SArgsSiscom *pSAgsSiscom);
void SqlVentasPorCajaFecha(SArgsSiscom *pSAgsSiscom);
void SqlCajasRegistradas(SArgsSiscom *pSAgsSiscom);


void SqlInsertaImporteCaja(SArgsSiscom *);
void SqlActualizaImporteCaja(SArgsSiscom *);
void SqlGeneraInsertaImporteCaja(LCamposSiscomPro2 *pLCSiscomPro2,
                                 LCamposSiscomPro2 **pLCSiscomPro2Prim,
				 LCamposSiscomPro2 **pLCSiscomPro2Act,
				 int *pintPtrNRegistros);
void SqlGeneraActualizaImporteCaja(LCamposSiscomPro2 *pLCSiscomPro2,
                                 LCamposSiscomPro2 **pLCSiscomPro2Prim,
				 LCamposSiscomPro2 **pLCSiscomPro2Act,
				 int *pintPtrNRegistros);
#endif

