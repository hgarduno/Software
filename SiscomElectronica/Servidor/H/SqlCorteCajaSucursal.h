
#ifndef __SQLCORTECAJA_H__
#define __SQLCORTECAJA_H__

#include <SiscomDesarrollo4/H/SiscomOperaciones.h>

int SqlDatosCierreCorteSucursal(SiscomOperaciones *pSisOpePtrDato);
int SqlEnviaRegistroCambioCaja(SiscomOperaciones *pSisOpePtrDato);

int SqlRegistraCorteCajaSucursal(SiscomOperaciones *pSisOpePtrDato);
int SqlRegistraCambioCaja(SiscomOperaciones *pSisOpePtrDato);
int SqlActualizaCambioCaja(SiscomOperaciones *pSisOpePtrDato);
int SqlCajaConCambio(SiscomOperaciones *pSisOpePtrDato,char *pchrPtrIdCajaCambio);
int SqlCambiosCaja(SiscomOperaciones *pSisOpePtrDato);
int SqlCambioCaja(SiscomOperaciones *pSisOpePtrDato);


void InsertToCorteCajaSucursal(SiscomOperaciones *pSisOpePtrDato,
			       SiscomRegistroProL *pSisRegProLPtrDato,
			       char *pchrPtrSql);

void InsertIntoCambioCaja(SiscomOperaciones *pSisOpePtrDato,
                          SiscomRegistroProL *pSisRegProLPtrDato,
                          char *pchrPtrSql);

void InsertIntoDenominacionesCambioCaja(SiscomOperaciones *pSisOpePtrDato,
                          		SiscomRegistroProL *pSisRegProLPtrDato,
                          		char *pchrPtrSql);


void UpdateCambioCaja(SiscomOperaciones *pSisOpePtrDato,
			     SiscomRegistroProL *pSisRegProLPtrDato,
			     char *pchrPtrSql);

void UpdateDenominacionesCambioCaja(SiscomOperaciones *pSisOpePtrDato,
			     SiscomRegistroProL *pSisRegProLPtrDato,
			     char *pchrPtrSql);
#endif

