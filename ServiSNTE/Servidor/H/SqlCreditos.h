#ifndef __SQLAPARTADOS_H__
#define __SQLAPARTADOS_H__
#include <SiscomProtocoloComunicaciones.h>
#include <SiscomOperaciones.h>
#include <SiscomArchivosIni.h>

int SqlCreditosCliente(SiscomOperaciones *pSiscomOpePtrDat);
void SqlCreditosDelCliente(SiscomOperaciones *pSiscomOpePtrDat,char *pchrPtrSql);
void SqlDireccionCliente(SiscomOperaciones *pSiscomOpePtrDat,char *pchrPtrSql);
int SqlAbonoACredito(SiscomOperaciones *pSiscomOpePtrDat);
void InsertToAbonoACredito(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql);
#endif
