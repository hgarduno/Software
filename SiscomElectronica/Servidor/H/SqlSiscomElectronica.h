#ifndef __SQLSISCOMELECTRONICA_H__
#define __SQLSISCOMELECTRONICA_H__
#include <SiscomDesarrollo4/H/SiscomOperaciones.h>
int SqlConsultandoUnosExpendios(SiscomOperaciones *pSisOpPtrDatos);
int SqlComunicacionExpendios(SiscomOperaciones *pSiscomOpePtrDatos);
int SqlComunicacionMatriz(SiscomOperaciones *pSiscomOpePtrDatos);
int SqlComunicacionMatrizAArgumento(SiscomOperaciones *pSiscomOpePtrDatos);
void SqlDatosComunicacionExpendios(SiscomOperaciones *pSiscomOpePtrDatos,char *pchrPtrSql);
void SqlConsultaComunicacionMatriz(SiscomOperaciones *pSiscomOpePtrDatos,char *pchrPtrSql);
void SqlDatosComunicacionUnosExpendios(SiscomOperaciones *pSiscomOpePtrDatos,char *pchrPtrSql);

#endif
