#include <SqlSepomex.h>
void SqlSepomexEstados(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSql[128];
sprintf(lchrArrSql,
	"select *	\n\
	 from estados");
SiscomEjecutaConsultaYResponde(pSAgsSiscom,lchrArrSql);
}

void SqlSepomexMunicipios(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSql[128];
sprintf(lchrArrSql,
	"select *			\n\
	 from municipios		\n\
	 where numestado=%s",
	 pSAgsSiscom->chrPtrArgConsulta[2]);
SiscomEjecutaConsultaYResponde(pSAgsSiscom,lchrArrSql);
}


void SqlSepomexAsentamientos(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSql[128];
sprintf(lchrArrSql,
	"select *			\n\
	 from asentamientos 		\n\
	 where numestado=%s  and 	\n\
	       nummunicipio=%s",
	 pSAgsSiscom->chrPtrArgConsulta[2],
	 pSAgsSiscom->chrPtrArgConsulta[3]);
SiscomEjecutaConsultaYResponde(pSAgsSiscom,lchrArrSql);
}

