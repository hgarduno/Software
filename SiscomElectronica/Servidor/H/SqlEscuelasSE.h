#ifndef __SQLSQLESCUELASSE_H__
#define __SQLSQLESCUELASSE_H__
#include <SiscomDesarrollo4/H/SiscomOperaciones.h>
int SqlEscuelasSE(SiscomOperaciones *pSiscomPtrDato);
int SqlEntregaEscuela(SiscomOperaciones *pSiscomOpePtrDato);
void SqlFormaEscuelaPorNombre(SiscomOperaciones *pSiscomOpePtrDato,
			      char *pchrPtrSqlEscPorNombre);
void SqlFormaEscuelaOtro(SiscomOperaciones *pSiscomOpePtrDato,
		  char *pchrPtrSql);
#endif
