#ifndef __SQLTELEFONOS_H__
#define __SQLTELEFONOS_H__
#include <SiscomDesarrollo2.h>

void SqlRegistraTelefonoFisica(SArgsSiscom *pSAgsSiscom);
void SqlRegistraTelefonoMoral(SArgsSiscom *pSAgsSiscom);


void SqlInsertIntoTelefonosFisica(LCamposSiscomPro2 *pLCSiscomPro2,
                                 LCamposSiscomPro2 **pLCSiscomPro2Prim,
				 LCamposSiscomPro2 **pLCSiscomPro2Act,
				 int *pintPtrNRegistros);
void SqlInsertIntoTelefonosMoral(LCamposSiscomPro2 *pLCSiscomPro2,
                                 LCamposSiscomPro2 **pLCSiscomPro2Prim,
				 LCamposSiscomPro2 **pLCSiscomPro2Act,
				 int *pintPtrNRegistros);
#endif
