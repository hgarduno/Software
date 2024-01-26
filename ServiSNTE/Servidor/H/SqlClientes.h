#ifndef __SQLCLIENTES_H__
#define __SQLCLIENTES_H__
#include <SiscomProtocoloComunicaciones.h>
#include <SiscomOperaciones.h>
#include <SiscomArchivosIni.h>
int SqlComprasCliente(SiscomOperaciones *pSiscomOpePtrDat);

void SqlClientePorRFC(SiscomOperaciones *pSiscomOpePtrDat,char *pchrPtrSql);
void SqlComprasClientePorRFC(SiscomOperaciones *pSiscomOpePtrDat,char *pchrPtrSql);
void SqlDireccionClientePorRFC(SiscomOperaciones *pSiscomOpePtrDat,char *pchrPtrSql);

void SqlCreditosPorFinanciera(SiscomOperaciones *pSiscomOpePtrDat,char *pchrPtrSql);
#endif
