#ifndef __SQLINVENTARIO_H__
#define __SQLINVENTARIO_H__
#include <SiscomProtocoloComunicaciones.h>
#include <SiscomOperaciones.h>
#include <SiscomArchivosIni.h>

int SqlProgramaInventario(SiscomOperaciones *pSiscomOpePtrDat);
int SqlPreRegistraInventario(SiscomOperaciones *pSiscomOpePtrDat);
int SqlRegistraInventario(SiscomOperaciones *pSiscomOpePtrDat);
int SqlVerificarInventarioEnCurso(SiscomOperaciones *pSiscomOpePtrDat);
int SqlRecuperaInventario(SiscomOperaciones *pSiscomOpePtrDat);
int SqlCancelaInventario(SiscomOperaciones *pSiscomOpePtrDat);

void InsertToInventario(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql);

void InsertToDetalleInventarioPaso(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql);

void InsertToDetalleInventario(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql);

void UpdateToInventario(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql);

void UpdateToExistencia(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql);

int SqlProgramaInventarioAlmacen(SiscomOperaciones *pSiscomOpePtrDat);
int SqlPreRegistraInventarioAlmacen(SiscomOperaciones *pSiscomOpePtrDat);
int SqlRegistraInventarioAlmacen(SiscomOperaciones *pSiscomOpePtrDat);
int SqlVerificarInventarioEnCursoAlmacen(SiscomOperaciones *pSiscomOpePtrDat);
int SqlRecuperaInventarioAlmacen(SiscomOperaciones *pSiscomOpePtrDat);
int SqlCancelaInventarioAlmacen(SiscomOperaciones *pSiscomOpePtrDat);

void InsertToInventarioAlmacen(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql);

void InsertToDetalleInventarioAlmacenPaso(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql);

void InsertToDetalleInventarioAlmacen(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql);

void UpdateToInventarioAlmacen(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql);

void UpdateToExistenciaAlmacen(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql);
void UpdateToExistenciaAlmacen2(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql);
#endif
