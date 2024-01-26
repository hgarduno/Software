#ifndef __PRINCIPAL_H__
#define __PRINCIPAL_H__

#include <SiscomProtocoloComunicaciones.h>
#include <PostgresAccesoDatos.h>
typedef struct OperacionesMigracion
{
    const char *chrPtrDatos;
    const char *chrPtrSql;
    const char *chrPtrVariableArreglo;
    const char *chrPtrDirServiSNTE;
    const char *chrPtrDirSqls;
    const char *chrPtrArchivoDatos;
    const char *chrPtrDirTalones;
    void (*ProcesaTablas)(const char *,
    			  const char *,
			  const char *pchrPtrVariable,
			  SiscomRegistroProL **pSiscomRegProLPtrSqlPrim,
			  SiscomRegistroProL **pSiscomRegProLPtrSqlAct);
    void (*InsercionesSql)(const char *pchrPtrIdTienda,
    			   SiscomRegistroProL *,
			   SiscomRegistroProL **,
			   SiscomRegistroProL **);
}zOperacionesMigracion;

typedef struct ErroresInsercion
{
   char chrArrError[256];
   void (*ErrorInsercion)(const char *pchrPtrError,
   			  const char *pchrPtrDescripcionError,
			  SiscomRegistroProL *pSiscomRegProLPtrSentenciasPrim,
			  SiscomRegistroProL *pSiscomRegProLPtrSentenciasAct);
}zErroresInsercion;

zOperacionesMigracion *LlenaProcesoMigracion(zOperacionesMigracion *pzOpMigracion,
					     const char *pchrPtrDirServiSNTE,
					     const char *pchrPtrDirTablasSql,
					     const char *pchrPtrDirScritpsSql,
					     int *pintPtrNOperaciones);


void AsignaEjecucionOperaciones(int pintNOperaciones,
			        zOperacionesMigracion *pzOpMigracion);
void ConectateBaseDatos(char **pchrPtrArgv);

void LanzaSentenciasSql(int pintSoloMuestra,SiscomRegistroProL *pSiscomRegProLPtrSqlPrim);
void ErrorClienteDuplicado(const char *pchrPtrError,
			   const char *pchrPtrDescripcionError,
			   SiscomRegistroProL *pSiscomRegProLPtrSentenciasPrim,
			   SiscomRegistroProL *pSiscomRegProLPtrSentenciasAct);
void AnalizaErrorInsercion(const char *pchrPtrError,
			   SiscomRegistroProL *pSiscomRegProLPtrSentenciasPrim,
			   SiscomRegistroProL *pSiscomRegProLPtrSentenciasAct);
const char *IdTienda(char **pchrPtrArgv);
int ModoSilencioActivado();
extern PostgresSql gzPostgresSql;
#endif
