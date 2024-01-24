#ifndef __SQLUBICACIONMATERIAL_H__
#define __SQLUBICACIONMATERIAL_H__
#include <SiscomDesarrollo4/H/SiscomOperaciones.h>
int SqlCajasMaterial(SiscomOperaciones *pSiscomOpePtrDato);
int SqlEstantes(SiscomOperaciones *pSiscomOpePtrDato);
int SqlRegistraCajaMaterial(SiscomOperaciones *pSiscomOpePtrDato);
int SqlAsignaCajaProducto(SiscomOperaciones *pSiscomOpePtrDato);


void InsertToCajaMaterial(SiscomOperaciones *pSiscomOpePtrDato,
		      SiscomRegistroProL *pSiscomRegProLPtrDato,
		      char *pchrPtrSql);

void InsertToUbicacionProductoOp(SiscomOperaciones *pSiscomOpePtrDato,
		      SiscomRegistroProL *pSiscomRegProLPtrDato,
		      char *pchrPtrSql);

void UpdateUbicacionProducto(SiscomOperaciones *pSiscomOpePtrDato,
		      SiscomRegistroProL *pSiscomRegProLPtrDato,
		      char *pchrPtrSql);

void InsertToUbicacionProducto(SiscomRegistroProL *pSisRegProLPtrProducto,
			       char *pchrPtrSql);
void InsertToEstante(SiscomRegistroProL *pSisRegProLPtrProducto,
		  char *pchrPtrSql);

void InsertToCaja(SiscomRegistroProL *pSisRegProLPtrProducto,
		  char *pchrPtrSql);

void DeleteFromUbicacionProductoOp(SiscomOperaciones *pSiscomOpePtrDato,
		      SiscomRegistroProL *pSiscomRegProLPtrDato,
		      char *pchrPtrSql);
#endif
