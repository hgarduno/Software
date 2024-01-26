#ifndef __SQLCONTRATOSBENEFICIOS_H__
#define __SQLCONTRATOSBENEFICIOS_H__
#include <SiscomProtocoloComunicaciones.h>
#include <SiscomOperaciones.h>
#include <SiscomArchivosIni.h>

int SqlCreditosBeneficiosIntegrales(SiscomOperaciones *pSiscomOpePtrDat);
int SqlRegistraContratoBeneficios(SiscomOperaciones *pSiscomOpePtrDat);

int SqlConsultaContratosBeneficios(SiscomOperaciones *pSiscomOpePtrDat);

int SqlConsultaInformacionContratoBeneficios(SiscomOperaciones *pSiscomOpePtrDat);

int SqlDetalleContratoBeneficios(SiscomOperaciones *pSiscomOpePtrDat,
              char *pchrPtrSql);

int SqlProductosContratoBeneficios(SiscomOperaciones *pSiscomOpePtrDat,
              char *pchrPtrSql);

int SqlActualizaEstadoContratoBeneficios(SiscomOperaciones *pSiscomOpePtrDat);

int SqlRecibeContratoBeneficios(SiscomOperaciones *pSiscomOpePtrDat);

void InsertToContratosBeneficios(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql);

void InsertToTransporteContratosBeneficios(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql);

void InsertToEstadoContratosBeneficios(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql);

void InsertToObservacionContratosBeneficios(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql);

void InsertToDetalleContratoBeneficios(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql);

void InsertToComentarioDetalleContratoBeneficios(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql);

int SqlInformacionContratoBeneficiosIntegrales(SiscomOperaciones *pSiscomOpePtrDat);
#endif
