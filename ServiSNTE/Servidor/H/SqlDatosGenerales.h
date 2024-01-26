#ifndef __SQLDATOSGENERALES_H__
#define __SQLDATOSGENERALES_H__
#include <SiscomProtocoloComunicaciones.h>
#include <SiscomOperaciones.h>

int SqlInsertaGeneralesCliente(SiscomOperaciones *pSiscomOpePtrDat);
int SqlActualizaGeneralesCliente(SiscomOperaciones *pSiscomOpePtrDat);
void InsertToDatosNacimiento(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql);
void UpdateDatosNacimiento(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql);

void InsertToIdentificacion(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql);
void UpdateIdentificacion(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql);

void InsertToOtrosDatosPersonales(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql);
void UpdateOtrosDatosPersonales(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql);


#endif
