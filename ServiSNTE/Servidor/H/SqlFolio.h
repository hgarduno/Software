#ifndef __SQLFOLIO_H__
#define __SQLFOLIO_H__
#include <SiscomProtocoloComunicaciones.h>
#include <SiscomOperaciones.h>
#include <SiscomArchivosIni.h>
int SqlRegistraFolio(SiscomOperaciones *pSiscomOpePtrDat);
int SqlFolioActual(SiscomOperaciones *pSiscomOpePtrDat);
void InsertToFolio(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql);
void UpdateFolioActual(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql);

#endif
