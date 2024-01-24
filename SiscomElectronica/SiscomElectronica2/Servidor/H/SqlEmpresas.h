#ifndef __SQLEMPRESAS_H__
#define __SQLEMPRESAS_H__
#include <SiscomDesarrollo2.h>

void SqlRegistraEmpresa(SArgsSiscom *pSAgsSiscom);

void SqlInsertIntoEmpresas(LCamposSiscomPro2 *pLCSiscomPro2,
                                 LCamposSiscomPro2 **pLCSiscomPro2Prim,
				 LCamposSiscomPro2 **pLCSiscomPro2Act,
				 int *pintPtrNRegistros);
#endif
