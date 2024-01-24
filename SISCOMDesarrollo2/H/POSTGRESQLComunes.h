#ifndef __POSTGRESQLCOMUN_H__
#define __POSTGRESQLCOMUN_H__
#include <libpq-fe.h>
#include <SiscomDesarrollo2.h>
const char *POSTGRESQLConectaBD(
		const char *,
		const char *,
		PGconn **
		);

const char *POSTGRESQLEjecutaConsulta(
		PGconn *,
		const char *,
		const char *,
		int *,
		int *,
		PGresult **);

const char *POSTGRESQLEjecutaComandoSQL(
		PGconn *,
		const char *,
		int,
		PGresult **);

#endif
