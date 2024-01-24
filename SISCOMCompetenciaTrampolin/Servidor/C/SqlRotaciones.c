#include <SqlRotaciones.h>

void SqlAparatosCompetencia(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSql[256];

sprintf(lchrArrSql,
	"select idTipoCompetencia,					\
		Aparato,						\
		idAparato						\
	from    competencia inner join					\
		aparatoscompetencia using(idTipoCompetencia) inner join	\
		aparatos using(idaparato)				\
	where idCompetencia=%s",
	pSAgsSiscom->chrPtrArgConsulta[1]);
SiscomConsultaBaseAsignaArgumento("SqlApCompetencia",
				  lchrArrSql,
				  pSAgsSiscom);
}
void SqlGimnastasAparatoRonda(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSql[256];
sprintf(lchrArrSql,
	"select * 			\
	 from detalleronda inner join 	\
	       aparatos using(idaparato) \
	 where idronda=%s",
	 pSAgsSiscom->chrPtrArgConsulta[2]);
SiscomConsultaBaseAsignaArgumento("SqlGimnastaRonda",
				   lchrArrSql,
				   pSAgsSiscom);
}
void SqlRondasCompetencia(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSql[256];

sprintf(lchrArrSql,
	"select * 		\
	 from rondas		\
	 where idcompetencia=%s",
	 pSAgsSiscom->chrPtrArgConsulta[1]);
SiscomEjecutaConsultaYResponde(pSAgsSiscom,lchrArrSql);
}

void SqlEjecutaRotacion(const char *pchrPtrIdAparatoPasa,
			LCamposSiscomPro2 *pLCSiscomPro2GimsRonda,
			LCamposSiscomPro2 **pLCSiscomPro2RotacionPrim,
			LCamposSiscomPro2 **pLCSiscomPro2RotacionAct,
			int *pintPtrNRegRotacion)
{
char lchrArrSql[256];
sprintf(lchrArrSql,
	"update detalleronda	\
	 set idaparato=%s	\
	 where idronda=%s and 	\
	       idgimnasta=%s;",
	 pchrPtrIdAparatoPasa,
	 SiscomObtenDato(pLCSiscomPro2GimsRonda,"idronda"),
	 SiscomObtenDato(pLCSiscomPro2GimsRonda,"idgimnasta"));
SiscomAnexaRegistroPro2(pLCSiscomPro2RotacionPrim,
			pLCSiscomPro2RotacionAct,
			pintPtrNRegRotacion,
			"ComandoSQL,EdoRegistro",
			lchrArrSql,
			"");
}
