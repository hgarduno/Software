#ifndef __SQLPRACTICAS_H__
#define __SQLPRACTICAS_H__
#include <SiscomDesarrollo4/H/SiscomOperaciones.h>

int SqlPracticaRegistrada(SiscomOperaciones *pSiscomOpePtrDato);
int SqlPractica(SiscomOperaciones *pSiscomOpePtrDato);
int SqlProductoPorTipoProductoPractica(SiscomOperaciones *pSiscomOpePtrDato);

void InsertToPractica(SiscomOperaciones *pSiscomOpePtrDato,
		      SiscomRegistroProL *pSisRegProLPtrDato,
		      char *pchrPtrSql);
void InsertToProductoPorTipoProductoPractica(SiscomOperaciones *pSiscomOpePtrDato,
		      SiscomRegistroProL *pSisRegProLPtrDato,
		      char *pchrPtrSql);

void SqlDefinicionTipoProductoPractica(SiscomOperaciones *pSiscomOpePtrDato,char *pchrPtrSql);
void SqlDatosPractica(SiscomOperaciones *pSiscomOpePtrDato,char *pchrPtrSql);
void SqlDatosProfesor(SiscomOperaciones *pSiscomOpePtrDato,char *pchrPtrSql);
#endif
