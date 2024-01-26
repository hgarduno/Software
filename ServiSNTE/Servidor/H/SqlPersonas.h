#ifndef __SQLPERSONAS_H__
#define __SQLPERSONAS_H__
#include <SiscomProtocoloComunicaciones.h>
#include <SiscomOperaciones.h>
#include <SiscomArchivosIni.h>

int SqlRegistraCliente(SiscomOperaciones *pSiscomOpePtrDat);
int SqlActualizaRFC(SiscomOperaciones *pSiscomOpePtrDat);
int SqlPersonaYaRegistrada(SiscomOperaciones *pSiscomOpePtrDat);
int SqlRFCRegistradoBaseDatos(SiscomOperaciones *pSiscomOpePtrDat);

void InsertToPersonas(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql);

void UpdatePersonas(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql);

void UpdateRFC(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql);
void InsertToClientes(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql);
#endif
