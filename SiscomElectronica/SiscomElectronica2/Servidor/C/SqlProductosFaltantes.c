#include <SqlProductosFaltantes.h>

void SqlProductosFaltantes(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSql[512];
sprintf(lchrArrSql,"select * from faltantes order by veces desc");
SiscomConsultaBaseAsignaArgumento("SqlProductosFaltantes",
				   lchrArrSql,
				   pSAgsSiscom);
}
