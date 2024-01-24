#ifndef __SQLCOTIZACIONIMPORTACION_H__
#define __SQLCOTIZACIONIMPORTACION_H__
#include <SiscomDesarrollo4/H/SiscomOperaciones.h>

int SqlDetalleCotizacionImportacion(SiscomOperaciones *pSiscomOpePtrDato);
int SqlAnexaProductoCotizacionImportacion(SiscomOperaciones *pSiscomOpePtrDato);
int SqlCotizacionesImportacion(SiscomOperaciones *pSiscomOpePtrDato);
int SqlRegistraCotizacionImportacion(SiscomOperaciones *);
void InsertToCotizacionImportacion(SiscomOperaciones *pSiscomOpePtrDato,
			   SiscomRegistroProL *pSiscomRegProLPtrDato,
			   char *pchrPtrSql);
void InsertToTotalesCotizacionImportacion(SiscomOperaciones *pSiscomOpePtrDato,
			   SiscomRegistroProL *pSiscomRegProLPtrDato,
			   char *pchrPtrSql);
void InsertToDetalleCotizacionImportacion(SiscomOperaciones *pSiscomOpePtrDato,
			   SiscomRegistroProL *pSiscomRegProLPtrDato,
			   char *pchrPtrSql);
void DeleteFromDetalleCotizacionImportacion(SiscomOperaciones *pSiscomOpePtrDato,
			   SiscomRegistroProL *pSiscomRegProLPtrDato,
			   char *pchrPtrSql);

void UpdateTotalesCotizacionImportacion(SiscomOperaciones *pSiscomOpePtrDato,
			   SiscomRegistroProL *pSiscomRegProLPtrDato,
			   char *pchrPtrSql);
#endif
