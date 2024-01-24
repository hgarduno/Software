#ifndef __CORTECAJA_H__
#define __CORTECAJA_H__
#include <SiscomDesarrollo2.h>

SiscomOperaciones2 *OpRegistraCorteCaja();

void RegistraCorteCaja(SArgsSiscom *); 
void ArgumentosCorteCaja(SArgsSiscom *pSAgsSiscom);
void GeneraIdCorteCaja(SArgsSiscom *psSAgsSiscom);
void CopiaImporteTotalCorte(SArgsSiscom *psSAgsSiscom);
#endif
