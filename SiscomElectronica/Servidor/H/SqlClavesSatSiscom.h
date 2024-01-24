#ifndef __SQLCLAVESSATSISCOM_H__
#define __SQLCLAVESSATSISCOM_H__
#include <SiscomDesarrollo4/H/SiscomOperaciones.h>
int SqlRegistraClaveSatSiscom(SiscomOperaciones *pSiscomOpePtrDato);
int SqlClaveSat(SiscomOperaciones *pSiscomOpePtrDato);


void InsertToClaveSatSiscom(SiscomOperaciones *pSiscomOpePtrDato,
                      SiscomRegistroProL *pSiscomRegProLPtrDato,
                      char *pchrPtrSql);
#endif
