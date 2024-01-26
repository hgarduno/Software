#ifndef __SQLCENTROTRABAJO_H__
#define __SQLCENTROTRABAJO_H__
#include <SiscomProtocoloComunicaciones.h>
#include <SiscomOperaciones.h>

int SqlInsertaCentroTrabajo(SiscomOperaciones *pSiscomOpePtrDat);

void InsertToCentroTrabajo(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql);

#endif
