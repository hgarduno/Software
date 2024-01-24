#include <SqlProgramacionPlacas.h>
void SqlProgramacionPlacas(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSql[1024];
sprintf(lchrArrSql,
	"								\n\
	select b.nombre 	|| 					\n\
	       ' '  		|| 					\n\
	       b.apaterno	||					\n\
	       ' '		||					\n\
	       b.amaterno as nombre,					\n\
	       cveproducto,						\n\
	       fechahora,						\n\
	       idventa							\n\
	from ventas as a inner join 					\n\
	     personas as b on a.cliente=b.idpersona left outer join	\n\
	     placaentregada as c using(idventa)				\n\
	 where a.fechahora::date>='%s'  and 				\n\
	       a.fechahora::date<='%s' and 				\n\
	       cveproducto like 'CIRCUITOIMPRESO%%' and 				\n\
	       fecha is null",
	pSAgsSiscom->chrPtrArgConsulta[2],
	pSAgsSiscom->chrPtrArgConsulta[3]);
SiscomLog("%s",lchrArrSql);
SiscomEjecutaConsultaYResponde(pSAgsSiscom,lchrArrSql);
}

void SqlEntregaPlaca(SArgsSiscom *pSAgsSiscom)
{
SiscomGeneraInsercionActualizacion(pSAgsSiscom,
				   "SqlEntregarPlaca",
				   SqlInsertIntoPlacaEntregada);
}

void SqlInsertIntoPlacaEntregada(LCamposSiscomPro2 *pLCSiscomPro2,
				      LCamposSiscomPro2 **pLCSiscomPro2Prim,
				      LCamposSiscomPro2 **pLCSiscomPro2Act,
				      int *pintPtrNRegistros)
{
char lchrArrSQL[512],
	lchrArrFechaHoy[28];
SiscomObtenFechaHoraActualAAAADDMM(lchrArrFechaHoy);
sprintf(lchrArrSQL,
	"insert into PlacaEntregada values(%s,'%s');",
	SiscomObtenDato(pLCSiscomPro2,"idventa"),
	lchrArrFechaHoy);
SiscomAnexaRegistroPro2(pLCSiscomPro2Prim,
			pLCSiscomPro2Act,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegitro",
			lchrArrSQL,
			"");
}
