#ifndef __SQLPESOPRODUCTO_H__
#define __SQLPESOPRODUCTO_H__

#include <SiscomDesarrollo4/H/SiscomOperaciones.h>
int SqlPesoProducto(SiscomOperaciones *pSiscomOpePtrDato);
int SqlRegistraPesoProducto(SiscomOperaciones *pSiscomOpePtrDato);
int SqlActualizaPesoProducto(SiscomOperaciones *pSiscomOpePtrDato);

void SqlConsultaPesoProducto(SiscomOperaciones *,char *);
void InsertToPesoProducto(SiscomOperaciones *pSiscomOpePtrDato,
			   SiscomRegistroProL *pSiscomRegProLPtrDato,
			   char *pchrPtrSql);

void UpdateFromPesoProducto(SiscomOperaciones *pSiscomOpePtrDato,
			   SiscomRegistroProL *pSiscomRegProLPtrDato,
			   char *pchrPtrSql);
#endif
