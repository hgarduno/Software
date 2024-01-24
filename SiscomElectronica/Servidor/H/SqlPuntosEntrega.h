#ifndef __SQLPUNTOSENTREGA_H__
#define __SQLPUNTOSENTREGA_H__
#include <SiscomDesarrollo4/H/SiscomOperaciones.h>
int SqlRegistrandoPuntoEntrega(SiscomOperaciones *);
int SqlPuntosEntrega(SiscomOperaciones *pSisOpePtrDato);

void InsertToPuntoEntrega(SiscomOperaciones *pSisOpePtrDato,
		      SiscomRegistroProL *pSisRegProLPtrDato,
		      char *pchrPtrSql);

void InsertIntoToDireccionesPuntosEntrega(SiscomOperaciones *pSisOpePtrDato,
					 SiscomRegistroProL *pSisRegProLPtrDato,
					 char *pchrPtrSql);
void SqlConsultaPuntosEntrega(SiscomOperaciones *pSisOpePtrDato,char *pchrPtrSql);
#endif
