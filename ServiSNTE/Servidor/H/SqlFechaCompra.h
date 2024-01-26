#ifndef __SQLFECHACOMPRA_H__
#define __SQLFECHACOMPRA_H__
#include <SiscomProtocoloComunicaciones.h>
#include <SiscomOperaciones.h>
#include <SiscomArchivosIni.h>

int SqlRegistraFechaCompra(SiscomOperaciones *pSiscomOpePtrDat);
int SqlFechaCompraProveedor(SiscomOperaciones *pSiscomOpePtrDat);
void InsertToFijaFechaCompra(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql);
#endif
