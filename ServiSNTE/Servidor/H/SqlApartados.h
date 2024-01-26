#ifndef __SQLAPARTADOS_H__
#define __SQLAPARTADOS_H__
#include <SiscomProtocoloComunicaciones.h>
#include <SiscomOperaciones.h>
#include <SiscomArchivosIni.h>

int SqlApartadosCliente(SiscomOperaciones *pSiscomOpePtrDat);
void SqlPersonaPorRFC(SiscomOperaciones *pSiscomOpePtrDat,char *pchrPtrSql);
void SqlPersonaFolioFactura(SiscomOperaciones *pSiscomOpePtrDat,char *pchrPtrSql);
void SqlApartadosDelCliente(SiscomOperaciones *pSiscomOpePtrDat,char *pchrPtrSql);
int SqlAbonoAApartado(SiscomOperaciones *pSiscomOpePtrDat);
int SqlCancelaAApartado(SiscomOperaciones *pSiscomOpePtrDat);
int SqlConsultaAbonos(SiscomOperaciones *pSiscomOpePtrDat);
int SqlCancelaApartado(SiscomOperaciones *pSiscomOpePtrDat);
void InsertToAbonoAApartado(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql);
void UpdateTotalAbonado(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql);
void UpdateToCancelaAApartado(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql);
void UpdateTotalAbonadoCancela(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql);
void UpdateToCancelaApartado(SiscomOperaciones *pSiscomOpePtrDatos,
              SiscomRegistroProL *pSiscomRegProLPtrEnt,
              char *pchrPtrSql);
void UpdateFolioActualApartado(SiscomOperaciones *pSiscomOpePtrDatos,
              SiscomRegistroProL *pSiscomRegProLPtrEnt,
              char *pchrPtrSql);
#endif
