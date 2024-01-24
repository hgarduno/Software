#ifndef __ADFUNCIONESCOMUNESPOSTGRESQL_H__
#define __ADFUNCIONESCOMUNESPOSTGRESQL_H__
#include <EstructurasSISCOM.h>
#include <FuncionesComunes.h>
#include <RNADFuncionesComunes.h>
#include <libpq-fe.h>
PGconn *POSTGRESQLConectate(PARDEPURACION STRUCTError *);
int POSTGRESQLEjecutaFuncion(PARDEPURACION PGconn *,PGresult **,char *,STRUCTError *);
int POSTGRESQLEvaluaEstatus(PARDEPURACION PGconn *,PGresult *,STRUCTError *);
#endif 
