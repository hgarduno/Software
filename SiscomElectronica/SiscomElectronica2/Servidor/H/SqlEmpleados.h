#ifndef __SQLEMPLEADOS_H__
#define __SQLEMPLEADOS_H__
#include <SiscomDesarrollo2.h>

void SqlEmpleados(SArgsSiscom *pSAgsSiscom);

void SqlInsertaSueldo(SArgsSiscom *);
void SqlGeneraInsertaSueldo(LCamposSiscomPro2 *pLCSiscomPro2,
				   LCamposSiscomPro2 **pLCSiscomPro2Prim,
				   LCamposSiscomPro2 **pLCSiscomPro2Act,
				   int *pintPtrNRegistros);

void SqlActualizaSueldo(SArgsSiscom *);
void SqlGeneraActualizaSueldo(LCamposSiscomPro2 *pLCSiscomPro2,
				   LCamposSiscomPro2 **pLCSiscomPro2Prim,
				   LCamposSiscomPro2 **pLCSiscomPro2Act,
				   int *pintPtrNRegistros);
void SqlIHistoricoSueldo(SArgsSiscom *);
void SqlGeneraHistoricoSueldo(LCamposSiscomPro2 *pLCSiscomPro2,
				   LCamposSiscomPro2 **pLCSiscomPro2Prim,
				   LCamposSiscomPro2 **pLCSiscomPro2Act,
				   int *pintPtrNRegistros);
#endif
