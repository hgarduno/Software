#ifndef __SQLCORREOS_H__
#define __SQLCORREOS_H__
#include <SiscomDesarrollo2.h>

void SqlRegistraCorreoFisica(SArgsSiscom *pSAgsSiscom);
void SqlRegistraCorreoMoral(SArgsSiscom *pSAgsSiscom);


void SqlInsertIntoCorreosFisica(LCamposSiscomPro2 *pLCSiscomPro2,
                                 LCamposSiscomPro2 **pLCSiscomPro2Prim,
				 LCamposSiscomPro2 **pLCSiscomPro2Act,
				 int *pintPtrNRegistros);
void SqlInsertIntoCorreosMoral(LCamposSiscomPro2 *pLCSiscomPro2,
                                 LCamposSiscomPro2 **pLCSiscomPro2Prim,
				 LCamposSiscomPro2 **pLCSiscomPro2Act,
				 int *pintPtrNRegistros);
#endif
