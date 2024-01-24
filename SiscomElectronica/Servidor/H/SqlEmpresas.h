#ifndef __SQLEMPRESAS_H__
#define __SQLEMPRESAS_H__

#include <SiscomDesarrollo4/H/SiscomOperaciones.h>

int SqlRFCsRegistrados(SiscomOperaciones *pSiscomOpePtrDato);
int SqlRegistraRegimenFiscal(SiscomOperaciones *pSisOpePtrDatos);
void UpdateEmpresaRegimenFiscal(SiscomOperaciones *pSiscomOpePtrDato,
                         	SiscomRegistroProL *pSiscomRegProLPtrDatos,
                        	char *pchrPtrSql);
#endif
