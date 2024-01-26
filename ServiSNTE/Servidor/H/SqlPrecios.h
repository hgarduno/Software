#ifndef __SQLVENTAS_H__
#define __SQLVENTAS_H__
#include <SiscomProtocoloComunicaciones.h>
#include <SiscomOperaciones.h>
#include <SiscomArchivosIni.h>

int SqlRegistraPrecioGeneralForaneo(SiscomOperaciones *pSiscomOpePtrDato);
int SqlRegistraPrecioGeneral(SiscomOperaciones *pSiscomOpePtrDat);
int SqlRegistraPrecioForaneo(SiscomOperaciones *pSiscomOpePtrDat);
int SqlRegistraPrecioBruto(SiscomOperaciones *pSiscomOpePtrDat);
int SqlRegistraPreciosCostosDescuentos(SiscomOperaciones *pSiscomOpePtrDat);
void InsertToPrecioGeneral(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql);
void InsertToPrecioGeneral2(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql);

void InsertToUltimoPrecioGeneral(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql);
void InsertToUltimoPrecioGeneral2(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql);
void UpdateUltimoPrecioGeneral(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql);


void InsertToPrecioForaneo(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql);

void InsertToUltimoPrecioForaneo(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql);

void InsertToPrecioBruto(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql);

void InsertToCostoBruto3(SiscomOperaciones *pSiscomOpePtrDato,
		        SiscomRegistroProL *pSiscomRegProLPtrEnt,
			char *pchrPtrSql);

void InsertToUltimoCosto(SiscomOperaciones *pSiscomOpePtrDato,
		        SiscomRegistroProL *pSiscomRegProLPtrEnt,
			char *pchrPtrSql);
#endif
