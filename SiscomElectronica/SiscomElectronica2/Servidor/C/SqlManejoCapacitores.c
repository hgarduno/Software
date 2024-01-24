#include <SqlManejoCapacitores.h>
void SqlCodigoCapacitor(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSql[1024];
sprintf(lchrArrSql,
	"select *			\n\
	 from codigocapacitores		\n\
	 %s",
	 pSAgsSiscom->Condicion(pSAgsSiscom));
SiscomConsultaBaseAsignaArgumento("SqlCapacitor",lchrArrSql,pSAgsSiscom);
}
void SqlProductosCapacitores(const char *pchrPtrSql,SArgsSiscom *pSAgsSiscom)
{
SiscomConsultaBaseAsignaArgumento("SqlProductosRes",
				  pchrPtrSql,
				  pSAgsSiscom);
}
