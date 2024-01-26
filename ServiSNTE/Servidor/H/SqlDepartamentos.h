#ifndef __SQLDEPARTAMENTOS_H__
#define __SQLDEPARTAMENTOS_H__
#include <SiscomProtocoloComunicaciones.h>
#include <SiscomOperaciones.h>
#include <SiscomArchivosIni.h>

int SqlRegistraDepartamento(SiscomOperaciones *pSiscomOpePtrDat);
void InsertToDepartamentos(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql);
#endif
