#ifndef __SQLTRANSFERENCIAS_H__
#define __SQLTRANSFERENCIAS_H__
#include <SiscomProtocoloComunicaciones.h>
#include <SiscomOperaciones.h>
#include <SiscomArchivosIni.h>

int SqlRegistraTransferencia(SiscomOperaciones *pSiscomOpePtrDat);

int SqlConsultaTransferencias(SiscomOperaciones *pSiscomOpePtrDat);

int SqlConsultaInformacionTransferencia(SiscomOperaciones *pSiscomOpePtrDat);
int SqlActualizaAlmacenCentral(SiscomOperaciones *pSiscomOpePtrDat);

int SqlDetalleTransferencia(SiscomOperaciones *pSiscomOpePtrDat,
              char *pchrPtrSql);

int SqlProductosTransferencia(SiscomOperaciones *pSiscomOpePtrDat,
              char *pchrPtrSql);

int SqlActualizaEstadoTransferencia(SiscomOperaciones *pSiscomOpePtrDat);

int SqlRecibeTransferencia(SiscomOperaciones *pSiscomOpePtrDat);

int SqlTransferenciasEnviadas(SiscomOperaciones *pSiscomOpePtrDat);
int SqlConsultaDetalleTransferencia(SiscomOperaciones *pSiscomOpePtrDat);
int SqlCostoPrecioTransferencia(SiscomOperaciones *pSiscomOpePtrDato);

void InsertToTransferencias(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql);

void InsertToTransporteTransferencias(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql);

void InsertToEstadoTransferencias(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql);

void InsertToObservacionTransferencias(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql);

void InsertToDetalleTransferencia(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql);

void InsertToObservacionProductos(SiscomOperaciones *pSiscomOpePtrDatos,
		      	  SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      	  char *pchrPtrSql);
void InsertToComentarioDetalleTransferencia(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql);

void UpdateToEstado(SiscomOperaciones *pSiscomOpePtrDatos,
              SiscomRegistroProL *pSiscomRegProLPtrEnt,
              char *pchrPtrSql);
void UpdateToEstado2(SiscomOperaciones *pSiscomOpePtrDatos,
              SiscomRegistroProL *pSiscomRegProLPtrEnt,
              char *pchrPtrSql);

void UpdateToExistenciaSuma(SiscomOperaciones *pSiscomOpePtrDatos,
              SiscomRegistroProL *pSiscomRegProLPtrEnt,
              char *pchrPtrSql);

void InsertToProductoStock(SiscomOperaciones *pSiscomOpePtrDatos,
              SiscomRegistroProL *pSiscomRegProLPtrEnt,
              char *pchrPtrSql);
void InsertToTransferenciaPiso(SiscomOperaciones *pSiscomOpePtrDatos,
              SiscomRegistroProL *pSiscomRegProLPtrEnt,
              char *pchrPtrSql);
#endif
