#ifndef __SQLMEDIOSCOMUNICACION_H__
#define __SQLMEDIOSCOMUNICACION_H__
#include <SiscomProtocoloComunicaciones.h>
#include <SiscomOperaciones.h>

int SqlTelefonosCliente(SiscomOperaciones *pSiscomOpePtrDat);
int SqlActualizaTelefonosCliente(SiscomOperaciones *pSiscomOpePtrDat);
void InsertToTelefonos(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql);
void UpdateTelefonos(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql);
void InsertToTelefonoCliente(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql);

void InsertToCorreo(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql);
void UpdateCorreo(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql);
void InsertToCorreoCliente(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql);
#endif
