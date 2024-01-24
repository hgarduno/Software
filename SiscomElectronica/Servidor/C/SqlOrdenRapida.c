#include <SqlOrdenRapida.h>
#include <SqlEscuelasSE.h>

#include <stdio.h>

int SqlOrdenEscuelaPrincipal(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[512],
	lchrArrSql[256],
	lchrArrSqlEscuela[256],
	lchrArrSqlPublico[128];

SqlFormaEscuelaPorNombre(pSiscomOpePtrDato,lchrArrSqlEscuela);
SqlFormaPublicoEnGeneral(lchrArrSqlPublico);
SiscomConsultasSqlOperaciones(lchrArrBuffer,
			     pSiscomOpePtrDato,
			     "Escuela%PublicoEnGeneral%",
			     lchrArrSqlEscuela,
			     lchrArrSqlPublico);
}
void SqlFormaPublicoEnGeneral(char *pchrPtrSqlConsulta)
{
sprintf(pchrPtrSqlConsulta,
	"select * 		\n\
	 from personas		\n\
	 where rfc='GENERAL'");
}


int SqlOrdenEscuelaOtro(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[512],
	lchrArrSql[256],
	lchrArrSqlEscuela[256],
	lchrArrSqlPublico[128];

SqlFormaEscuelaOtro(pSiscomOpePtrDato,lchrArrSqlEscuela);
SqlFormaPublicoEnGeneral(lchrArrSqlPublico);
SiscomConsultasSqlOperaciones(lchrArrBuffer,
			     pSiscomOpePtrDato,
			     "Escuela%PublicoEnGeneral%",
			     lchrArrSqlEscuela,
			     lchrArrSqlPublico);
}
