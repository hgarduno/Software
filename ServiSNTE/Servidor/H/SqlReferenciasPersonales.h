#ifndef __SQLREFERENCIASPERSONALES_H__
#define __SQLREFERENCIASPERSONALES_H__
#include <SiscomProtocoloComunicaciones.h>
#include <SiscomOperaciones.h>

int SqlInsertaReferenciasPersonales(SiscomOperaciones *pSiscomOpePtrDat);
void InsertToReferenciaPersonal(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql);
void InsertToPersonaReferencia(SiscomOperaciones *pSiscomOpePtr);

void InsertToDireccionesReferencia(SiscomOperaciones *pSiscomOpePtr,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql);

void InsertToTelefonosReferencia(SiscomOperaciones *pSiscomOpePrDato);
#endif
