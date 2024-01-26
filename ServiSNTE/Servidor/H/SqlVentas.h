#ifndef __SQLVENTAS_H__
#define __SQLVENTAS_H__
#include <SiscomProtocoloComunicaciones.h>
#include <SiscomOperaciones.h>
#include <SiscomArchivosIni.h>

int SqlRegistraVenta(SiscomOperaciones *pSiscomOpePtrDat);
int SqlDatosCalculoCredito(SiscomOperaciones *pSiscomOpePtrDat);
int SqlDatosTiendaVenta(SiscomOperaciones *pSiscomOpePtrDat);
void InsertToVentasCliente(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql);
void InsertToVentas(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql);

void InsertToVentaCredito(SiscomOperaciones *pSiscomOpePtrDatos,
			  SiscomRegistroProL *pSiscomRegProLPtrEnt,
			  char *pchrPtrSql);
void InsertToImporteVenta(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql);

void InsertToDetalleVenta(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql);
void UpdateExistencia(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql);

void InsertToVendedorVenta(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql);

void InsertToTotalAbonado(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql);

void InsertToEstatusVenta(SiscomOperaciones *pSiscomOpePtrDatos,
              SiscomRegistroProL *pSiscomRegProLPtrEnt,
              char *pchrPtrSql);
void UpdateFolioActualFactura(SiscomOperaciones *pSiscomOpePtrDatos,
              SiscomRegistroProL *pSiscomRegProLPtrEnt,
              char *pchrPtrSql);

#endif
