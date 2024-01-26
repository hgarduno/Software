#ifndef __SQLDIRECCIONES_H__
#define __SQLDIRECCIONES_H__
#include <SiscomProtocoloComunicaciones.h>
#include <SiscomOperaciones.h>
#include <SiscomArchivosIni.h>

int SqlRegistraDatosCasa(SiscomOperaciones *pSiscomOpePtrDat);
int SqlRegistraDireccion(SiscomOperaciones *pSiscomOpePtrDat);
int SqlDireccionesPersona(SiscomOperaciones *pSiscomOpePtrDat);
void InsertToDireccionesCliente(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql);

void InsertToDirecciones(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql);

void UpdateDireccion(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql);


void InsertToDatosCasa(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql);

int SqlActualizaDireccion(SiscomOperaciones *pSiscomOpePtrDat);
#endif
