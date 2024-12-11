#ifndef __SQLABONOAAPARTADO_H__
#define __SQLABONOAAPARTADO_H__
#include <SiscomDesarrollo4/H/SiscomOperaciones.h>

int SqlAbonoAApartado(SiscomOperaciones *pSisOpePtrDato);
int SqlRegistraAbonoAApartado(SiscomOperaciones *pSiscomOpePtrDato);


void InsertToAbonoAApartado(SiscomOperaciones *pSisOpePtrDato,
			    SiscomRegistroProL *pSisRegProLPtrDato,
			    char *pchrPtrSql);
#endif
