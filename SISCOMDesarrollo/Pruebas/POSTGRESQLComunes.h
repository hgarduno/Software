#ifndef __POSTGRESQLCOMUN_H__
#define __POSTGRESQLCOMUN_H__
#include <libpq-fe.h>
#include <FuncionesComunes.h>
   const char *POSTGRESQLConectaBD(const char *,PGconn **);
   const char *POSTGRESQLEjecutaFuncion(PGconn *,const char *,PGresult  **);
   const char *POSTGRESQLEjecutaConsulta(PGconn *,const char *,const char *,int *,int *,PGresult **);


#endif
