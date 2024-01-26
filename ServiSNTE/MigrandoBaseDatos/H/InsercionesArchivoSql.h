#ifndef __INSERCIONESARCHIVOSQL_H__
#define __INSERCIONESARCHIVOSQL_H__
#include <SiscomArchivosIni.h>
#include <SiscomProtocoloComunicaciones.h>
#include <stdio.h>
void ProcesaArchivos(const char *pchrPtrDirServiSNTE,
		    const char *pchrPtrDirScriptsSql,
		    const char *pchrPtrVariable,
		   SiscomRegistroProL **pSiscomRegProLPtrSqlPrim,
		   SiscomRegistroProL **pSiscomRegProLPtrSqlAc);
void CargaArchivoSql(const char *pchrPtrArchivo,
		   SiscomRegistroProL **pSiscomRegProLPtrSqlPrim,
		   SiscomRegistroProL **pSiscomRegProLPtrSqlAc);

void CargaArchivosSql(const char *pchrPtrDirServiSNTE,
		      const char *pchrPtrDirTablasSql,
		      char **pchrPtrArchivos,
		   SiscomRegistroProL **pSiscomRegProLPtrSqlPrim,
		   SiscomRegistroProL **pSiscomRegProLPtrSqlAc);
void ProcesaTablas(const char *pchrPtrDirServiSNTE,
		   const char *pchrPtrDirTablasSql,
		   SiscomRegistroProL **pSiscomRegProLPtrSqlPrim,
		   SiscomRegistroProL **pSiscomRegProLPtrSqlAc);

int LeeSentenciaSql(FILE *pFlePtrArchivo,
		     char *pchrPtrSql);
#endif
