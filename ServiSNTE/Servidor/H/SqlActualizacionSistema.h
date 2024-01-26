#ifndef __SQLSQLACTUALIZACIONSISTEMA_H__
#define __SQLSQLACTUALIZACIONSISTEMA_H__
#include <SiscomProtocoloComunicaciones.h>
#include <SiscomOperaciones.h>
#include <SiscomArchivosIni.h>
int SqlActualizacionSistema(SiscomOperaciones *pSiscomOpePtrDat);
int SqlInsertaMaquinaActualizada(SiscomOperaciones *pSiscomOpePtrDat);

void InsertToMaquinasActualizadas(SiscomOperaciones *pSiscomOpePtrDatos,
				  SiscomRegistroProL *pSiscomRegProLPtrEnt,
				  char *pchrPtrSql);
#endif
