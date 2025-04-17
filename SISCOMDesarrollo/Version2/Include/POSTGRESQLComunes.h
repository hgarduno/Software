#ifndef __POSTGRESQLCOMUN_H__
#define __POSTGRESQLCOMUN_H__
#include <libpq-fe.h>
#include <FuncionesComunes.h>
   const char *POSTGRESQLConectaBD(const char *,PGconn **);
   const char *POSTGRESQLEjecutaFuncion(PGconn *,const char *,int,PGresult  **);
   const char *POSTGRESQLEjecutaConsulta(PGconn *,const char *,const char *,int *,int *,PGresult **);


const char *POSTGRESQLConectateBD(const char *pchrPtrNmbBD,
				  PGconn **pPGCPtrConexion);

const char *POSTGRESQLEjecutaComandoSQL(PGconn *pPGCPtrConexion,
					const char *pchrPtrComandoSQL,
					int pintEvaluaEstatus,
					PGresult **pPGRRegreso);
#endif
