#ifndef __SQLSALDOSMOVIMIENTOS_H__
#define __SQLSALDOSMOVIMIENTOS_H__
#include <SiscomProtocoloComunicaciones.h>
#include <SiscomOperaciones.h>
#include <SiscomArchivosIni.h>

char *SqlFormaConsultaPorMes(int pintMes,
				   SiscomOperaciones *pSiscomOpePtrDato);
int SqlSaldosMovimientosMes(SiscomOperaciones *pSiscomOpePtrDato);
int SqlFormaConsultasSaldosMovimientos(SiscomOperaciones *pSiscomOpePtrDato);
int SqlConceptosSaldosMovimientos(SiscomOperaciones *pSiscomOpePtrDato);
#endif