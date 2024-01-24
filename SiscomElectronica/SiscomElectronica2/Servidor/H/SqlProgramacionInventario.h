#ifndef __SQLPROGRAMACIONINVENTARIO_H__
#define __SQLPROGRAMACIONINVENTARIO_H__
#include <SiscomDesarrollo2.h>
void SqlRegistraProgramacionInventario(SArgsSiscom *pSAgsSiscom);
void SqlGenerandoRegistroProgramacionInventario(
			const LCamposSiscomPro2ConSubReg *pLCSiscomPro2SRDat,
			SArgsSiscom *pSAgsSiscom,
			LCamposSiscomPro2 **pLCSiscomPro2Prim,
			LCamposSiscomPro2 **pLCSiscomPro2Act,
			int *pintPtrNRegistros);

void SqlInventariosProgramados(SArgsSiscom *);
#endif
