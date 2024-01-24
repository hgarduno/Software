#include <SqlReportePorExistenciaMinima.h>

void SqlReportePorExistenciaMinima(SArgsSiscom *pSArgsSiscom)
{
char lchrArrSql[2048];

sprintf(lchrArrSql,
"select a.cveproducto,									\n\
	a.existencia+b.exbodegas as total,						\n\
       a.existencia,									\n\
       b.exbodegas as exbodegas,							\n\
       a.eximinima,									\n\
       '' as fechaultimacompra,								\n\
       '' as cantidadultimacompra,							\n\
       '' as precioultimacompra,							\n\
       '' as proveedor,									\n\
       ultimacompra(a.cveproducto,'%s','%s',a.idexpendio),				\n\
       totalventas(a.cveproducto,'%s','%s',a.idexpendio) as ventsemestreanterior,	\n\
       totalcompras(a.cveproducto,'%s','%s',a.idexpendio) as comsemestreanterior,	\n\
       totalventas(a.cveproducto,'%s','%s',a.idexpendio) as ventactuales,		\n\
       totalcompras(a.cveproducto,'%s','%s',a.idexpendio) as comactuales		\n\
from existencias as a inner join 							\n\
     existenciaexpendiobodegas as b on(a.cveproducto=b.cveproducto and 			\n\
                                       a.idexpendio=b.idexpendio)			\n\
where a.idexpendio=%s and 								\n\
	(a.existencia+b.exbodegas) <a.eximinima and					\n\
	(a.existencia+b.exbodegas) >10							\n\
order by existencia desc",
pSArgsSiscom->chrPtrArgConsulta[2],
pSArgsSiscom->chrPtrArgConsulta[6],

pSArgsSiscom->chrPtrArgConsulta[2],
pSArgsSiscom->chrPtrArgConsulta[3],

pSArgsSiscom->chrPtrArgConsulta[2],
pSArgsSiscom->chrPtrArgConsulta[3],

pSArgsSiscom->chrPtrArgConsulta[4],
pSArgsSiscom->chrPtrArgConsulta[6],

pSArgsSiscom->chrPtrArgConsulta[4],
pSArgsSiscom->chrPtrArgConsulta[6],

pSArgsSiscom->chrPtrArgConsulta[1]);
SiscomImprimeArgumentosConsulta(pSArgsSiscom);
SiscomLog("%s",lchrArrSql);
SiscomConsultaBaseSinEnvio2(lchrArrSql,pSArgsSiscom);
SiscomContenidoProtocolo(pSArgsSiscom->LCSiscomPro2Regreso);
}

void SqlProductosPorcentajeExMinima(SArgsSiscom *pSArgsSiscom)
{
char lchrArrSql[2048];

sprintf(lchrArrSql,
"select a.cveproducto,									\n\
	a.existencia+b.exbodegas as total,						\n\
       a.existencia,									\n\
       b.exbodegas as exbodegas,							\n\
       a.eximinima,									\n\
       '' as fechaultimacompra,								\n\
       '' as cantidadultimacompra,							\n\
       '' as precioultimacompra,							\n\
       '' as proveedor,									\n\
       ultimacompra(a.cveproducto,'%s','%s',a.idexpendio),				\n\
       --totalventas(a.cveproducto,'%s','%s',a.idexpendio) as ventsemestreanterior,	\n\
       0 						as ventsemestreanterior,	\n\
       totalcompras(a.cveproducto,'%s','%s',a.idexpendio) as comsemestreanterior,	\n\
       --totalventas(a.cveproducto,'%s','%s',a.idexpendio) as ventactuales,		\n\
       0						as ventactuales,		\n\
       totalcompras(a.cveproducto,'%s','%s',a.idexpendio) as comactuales		\n\
from existencias as a inner join 							\n\
     existenciaexpendiobodegas as b on(a.cveproducto=b.cveproducto and 			\n\
                                       a.idexpendio=b.idexpendio) inner join		\n\
    vporexistenciaminima as c on(a.cveproducto=c.cveproducto and 			\n\
                                     a.idexpendio=c.idexpendio)				\n\
where a.idexpendio=%s and 								\n\
      c.poreximinima>=%s and 								\n\
      c.poreximinima<=%s								\n\
order by a.cveproducto ",
pSArgsSiscom->chrPtrArgConsulta[4],
pSArgsSiscom->chrPtrArgConsulta[8],

pSArgsSiscom->chrPtrArgConsulta[4],
pSArgsSiscom->chrPtrArgConsulta[5],

pSArgsSiscom->chrPtrArgConsulta[4],
pSArgsSiscom->chrPtrArgConsulta[5],

pSArgsSiscom->chrPtrArgConsulta[4],
pSArgsSiscom->chrPtrArgConsulta[6],

pSArgsSiscom->chrPtrArgConsulta[6],
pSArgsSiscom->chrPtrArgConsulta[8],

pSArgsSiscom->chrPtrArgConsulta[1],

pSArgsSiscom->chrPtrArgConsulta[2],
pSArgsSiscom->chrPtrArgConsulta[3]);
SiscomImprimeArgumentosConsulta(pSArgsSiscom);
SiscomLog("%s",lchrArrSql);
SiscomConsultaBaseSinEnvio2(lchrArrSql,pSArgsSiscom);
/*
SiscomContenidoProtocolo(pSArgsSiscom->LCSiscomPro2Regreso);

*/
}



void SqlVentasPorExistenciaMinima(
			const char *pchrPtrIdExpendio,
			const char *pchrPtrPorExMinimaB,
			const char *pchrPtrPorExMinimaA,
			const char *pchrPtrFechaIni,
			const char *pchrPtrFechaFin,
			const char *pchrPtrArgumento,
			SArgsSiscom *pSAgsSiscom)
{
char lchrArrSql[1024];
sprintf(lchrArrSql,
"							\n\
select sum(cantidad) as Ventas,				\n\
	cveproducto 					\n\
from ventas 						\n\
where cveproducto in (					\n\
		      select cveproducto		\n\
		      from vporexistenciaminima		\n\
		      where poreximinima>=%s and 	\n\
      			    poreximinima<=%s and 	\n\
      			    idexpendio=%s		\n\
		      ) and 				\n\
  fechahora::date>='%s' 	and 			\n\
  fechahora::date<='%s' 	and 			\n\
  idexpendio=%s						\n\
group by cveproducto					\n\
order by cveproducto					\n\
",
pchrPtrPorExMinimaB,
pchrPtrPorExMinimaA,
pchrPtrIdExpendio,
pchrPtrFechaIni,
pchrPtrFechaFin,
pchrPtrIdExpendio);
SiscomConsultaBaseAsignaArgumento(pchrPtrArgumento,
				  lchrArrSql,
				  pSAgsSiscom);
}
void SqlVentasSemestreAnterior(SArgsSiscom *pSAgsSiscom)
{
SqlVentasPorExistenciaMinima(
			pSAgsSiscom->chrPtrArgConsulta[1],
			pSAgsSiscom->chrPtrArgConsulta[2],
			pSAgsSiscom->chrPtrArgConsulta[3],
			pSAgsSiscom->chrPtrArgConsulta[4],
			pSAgsSiscom->chrPtrArgConsulta[5],
			"SqlVentasSemAnterior",
			pSAgsSiscom);
}
void SqlVentasSemestreActual(SArgsSiscom *pSAgsSiscom)
{

SqlVentasPorExistenciaMinima(
			pSAgsSiscom->chrPtrArgConsulta[1],
			pSAgsSiscom->chrPtrArgConsulta[2],
			pSAgsSiscom->chrPtrArgConsulta[3],
			pSAgsSiscom->chrPtrArgConsulta[6],
			pSAgsSiscom->chrPtrArgConsulta[8],
			"SqlVentasActuales",
			pSAgsSiscom);
}
