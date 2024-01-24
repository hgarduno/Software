#ifndef __SQLPROGRAMACIONPLACAS_H__
#define __SQLPROGRAMACIONPLACAS_H__
#include <SiscomDesarrollo2.h>
void SqlEntregaPlaca(SArgsSiscom *pSAgsSiscom);
void SqlProgramacionPlacas(SArgsSiscom *pSAgsSiscom);

void SqlInsertIntoPlacaEntregada(LCamposSiscomPro2 *pLCSiscomPro2,
				      LCamposSiscomPro2 **pLCSiscomPro2Prim,
				      LCamposSiscomPro2 **pLCSiscomPro2Act,
				      int *pintPtrNRegistros);
#endif
