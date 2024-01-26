#ifndef __SQLCARGOPUBLICO_H__
#define __SQLCARGOPUBLICO_H__
#include <SiscomProtocoloComunicaciones.h>
#include <SiscomOperaciones.h>

int SqlInsertaCargoPublico(SiscomOperaciones *pSiscomOpePtrDat);
void InsertToCargoPublico(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql);

void InsertToCargoPublicoPersona(SiscomOperaciones *pSiscomOpePtr,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql);
#endif
