#include <SqlOrigenCompra.h>

void SqlOrigenCompra(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSql[1024];
sprintf(lchrArrSql,
	"select * 		\n\
	 from origencompra");
SiscomConsultaBaseSinEnvio2(lchrArrSql,pSAgsSiscom);
SiscomLog("%s",lchrArrSql);
}
