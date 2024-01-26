#ifndef __SQLEMPLEO_H__
#define __SQLEMPLEO_H__
#include <SiscomProtocoloComunicaciones.h>
#include <SiscomOperaciones.h>

void SqlDireccionEmpresaRegistrada(SiscomOperaciones *pSiscomOpePtrDat,char *pchrPtrSql);
void SqlActividadEmpresaRegistrada(SiscomOperaciones *pSiscomOpePtrDat,char *pchrPtrSql);
void SqlTelefonoEmpresaRegistrada(SiscomOperaciones *pSiscomOpePtrDat,char *pchrPtrSql);
void SqlCorreoEmpresaRegostrada(SiscomOperaciones *pSiscomOpePtrDat,char *pchrPtrSql);

int SqlInsertaEmpleo(SiscomOperaciones *pSiscomOpePtrDat);
int SqlActualizaEmpleo(SiscomOperaciones *pSiscomOpePtrDat);
int SqlEmpresaYaRegistrada(SiscomOperaciones *pSiscomOpePtrDat);
void InsertToEmpresa(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql);
void UpdateEmpresa(SiscomOperaciones *pSiscomOpePtr,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql);
void InsertToEmpresaGiro(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql);
void UpdateEmpresaGiro(SiscomOperaciones *pSiscomOpePtr,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql);

void InsertToEmpleo(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql);


void InsertToJefes(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql);
void InsertToDatosEmpleo(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql);

void UpdateDatosEmpleo(SiscomOperaciones *pSiscomOpePtr,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql);
void InsertToOtrosIngresos(SiscomOperaciones *pSiscomOpePtr,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql);

void UpdateOtrosIngresos(SiscomOperaciones *pSiscomOpePtr,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql);
void InsertToDireccionEmpleo(SiscomOperaciones *pSiscomOpePtr,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql);
void UpdateDireccionEmpleo(SiscomOperaciones *pSiscomOpePtr,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql);

void InsertToDireccionEmpresa(SiscomOperaciones *pSiscomOpePtrDat,
			      SiscomRegistroProL *pSiscomRegProLPtrEnt,
			      char *pchrPtrSql);

void InsertToTelefonoEmpleo(SiscomOperaciones *pSiscomOpePtrDat,
			      SiscomRegistroProL *pSiscomRegProLPtrEnt,
			      char *pchrPtrSql);
void UpdateTelefonoEmpleo(SiscomOperaciones *pSiscomOpePtrDat,
			      SiscomRegistroProL *pSiscomRegProLPtrEnt,
			      char *pchrPtrSql);

void InsertToTelefonoEmpresaEmpleo(SiscomOperaciones *pSiscomOpePtrDat,
			      SiscomRegistroProL *pSiscomRegProLPtrEnt,
			      char *pchrPtrSql);
void InsertToCorreoEmpleo(SiscomOperaciones *pSiscomOpePtrDat,
			      SiscomRegistroProL *pSiscomRegProLPtrEnt,
			      char *pchrPtrSql);

void UpdateCorreoEmpleo(SiscomOperaciones *pSiscomOpePtrDat,
			      SiscomRegistroProL *pSiscomRegProLPtrEnt,
			      char *pchrPtrSql);
void InsertToCorreoEmpresaEmpleo(SiscomOperaciones *pSiscomOpePtrDat,
			      SiscomRegistroProL *pSiscomRegProLPtrEnt,
			      char *pchrPtrSql);

#endif
