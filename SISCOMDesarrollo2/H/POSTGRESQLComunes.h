#ifndef __POSTGRESQLCOMUN_H__
#define __POSTGRESQLCOMUN_H__
#include <libpq-fe.h>
#include <SiscomDesarrollo2.h>

const char *POSTGRESQLConectateBD(const char *pchrPtrNmbBD,
				  const char *pchrPtrPtoComBD,
				  PGconn **pPGCPtrConexion);
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
