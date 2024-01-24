#ifndef __SQLPRECIOS_H__
#define __SQLPRECIOS_H__
#include <SiscomDesarrollo4/H/SiscomOperaciones.h>

int SqlPreciosExpendios(SiscomOperaciones *pSiscomOpePtrDato);
void SqlConsultaPreciosExpendio(SiscomOperaciones *pSiscomOpePtrDato,char *pchrPtrSql);
int SqlConsultaPreciosPorExpendio(const char *pchrPtrIdExpendio,
				  const char *pchrPtrSalida,
				  const char *pchrPtrSql,
				  SiscomOperaciones *pSiscomOpePtrDato);
int SqlPreciosExpendioOrigen(SiscomOperaciones *pSiscomOpePtrDato);
int SqlPreciosExpendioDestino(SiscomOperaciones *pSiscomOpePtrDato);



int SqlActualizaPrecioAlgunosExpendios(SiscomOperaciones *pSisOpePtrDato);
#endif
