#ifndef __SQLGENERALESCONTRATOBENEFICIOS_H__
#define __SQLGENERALESCONTRATOBENEFICIOS_H__
#include <SiscomProtocoloComunicaciones.h>
#include <SiscomOperaciones.h>

int SqlInsertaGeneralesContratoBeneficios(SiscomOperaciones *pSiscomOpePtrDat);
void InsertToGeneralesContratoBeneficios(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql);

#endif
