#ifndef __SQLCAMIONES_H__
#define __SQLCAMIONES_H__
#include <SiscomProtocoloComunicaciones.h>
#include <SiscomOperaciones.h>
#include <SiscomArchivosIni.h>

int SqlRegistraCamion(SiscomOperaciones *pSiscomOpePtrDat);
void InsertToCamiones(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql);
#endif
