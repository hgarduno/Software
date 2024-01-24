#ifndef __SQLORDENESFAVORITAS_H__
#define __SQLORDENESFAVORITAS_H__
#include <SiscomDesarrollo4/H/SiscomOperaciones.h>

int SqlEliminaOrdenesFavoritas(SiscomOperaciones *pSiscomOpePtrDato);
int SqlRegistraOrdenesFavoritas(SiscomOperaciones *pSiscomOpePtrDato);
int SqlOrdenesFavoritasRegistradas(SiscomOperaciones *pSiscomOpePtrDato);

void InsertToOrdenesFavoritas(SiscomOperaciones *pSiscomOpePtrDato,
			      SiscomRegistroProL *pSiscomRegProLPtrDato,
			      char *pchrPtrSql);
void DeleteFromOrdenesFavoritas(SiscomOperaciones *pSiscomOpePtrDato,
			      SiscomRegistroProL *pSiscomRegProLPtrDato,
			      char *pchrPtrSql);
#endif
