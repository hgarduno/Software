#include <SqlExistenciasProductos.h>

void SqlExistenciasProductos(SArgsSiscom *pSArgsSiscom)
{

char lchrArrSql[2048];

SiscomImprimeArgumentosConsulta(pSArgsSiscom);
sprintf(lchrArrSql,
"select a.cveproducto,								\n\
 a.existencia+b.exbodegas as total,						\n\
 a.existencia,									\n\
 b.exbodegas as exbodegas,							\n\
 a.eximinima,									\n\
 '' as fechaultimacompra,							\n\
 '' as cantidadultimacompra,							\n\
 '' as precioultimacompra,							\n\
 '' as proveedor,								\n\
 ultimacompra(a.cveproducto,'%s','%s',a.idexpendio),				\n\
 totalventas(a.cveproducto,'%s','%s',a.idexpendio) as ventsemestreanterior,	\n\
 totalcompras(a.cveproducto,'%s','%s',a.idexpendio) as comsemestreanterior,	\n\
 totalventas(a.cveproducto,'%s','%s',a.idexpendio) as ventactuales,		\n\
 totalcompras(a.cveproducto,'%s','%s',a.idexpendio) as comactuales		\n\
from existencias as a inner join 						\n\
     existenciaexpendiobodegas as b on(a.cveproducto=b.cveproducto and		\n\
     				       a.idexpendio=b.idexpendio)  		\n\
where a.idexpendio=%s and 							\n\
      a.cveproducto='%s'							\n\
order by a.existencia desc",
pSArgsSiscom->chrPtrArgConsulta[3],
pSArgsSiscom->chrPtrArgConsulta[7],

pSArgsSiscom->chrPtrArgConsulta[3],
pSArgsSiscom->chrPtrArgConsulta[4],

pSArgsSiscom->chrPtrArgConsulta[3],
pSArgsSiscom->chrPtrArgConsulta[4],

pSArgsSiscom->chrPtrArgConsulta[5],
pSArgsSiscom->chrPtrArgConsulta[7],

pSArgsSiscom->chrPtrArgConsulta[5],
pSArgsSiscom->chrPtrArgConsulta[7],

pSArgsSiscom->chrPtrArgConsulta[1],
pSArgsSiscom->chrPtrArgConsulta[2]);
SiscomImprimeArgumentosConsulta(pSArgsSiscom);
SiscomLog("%s",lchrArrSql);
SiscomConsultaBaseSinEnvio2(lchrArrSql,pSArgsSiscom);
SiscomContenidoProtocolo(pSArgsSiscom->LCSiscomPro2Regreso);

}

void SqlExistenciasProductosCasiClave(SArgsSiscom *pSArgsSiscom)
{

char lchrArrSql[2048];

SiscomImprimeArgumentosConsulta(pSArgsSiscom);
sprintf(lchrArrSql,
"select a.cveproducto,								\n\
 a.existencia+b.exbodegas as total,						\n\
 a.existencia,									\n\
 b.exbodegas as exbodegas,							\n\
 a.eximinima,									\n\
 '' as fechaultimacompra,							\n\
 '' as cantidadultimacompra,							\n\
 '' as precioultimacompra,							\n\
 '' as proveedor,								\n\
 ultimacompra(a.cveproducto,'%s','%s',a.idexpendio),				\n\
 totalventas(a.cveproducto,'%s','%s',a.idexpendio) as ventsemestreanterior,	\n\
 totalcompras(a.cveproducto,'%s','%s',a.idexpendio) as comsemestreanterior,	\n\
 totalventas(a.cveproducto,'%s','%s',a.idexpendio) as ventactuales,		\n\
 totalcompras(a.cveproducto,'%s','%s',a.idexpendio) as comactuales		\n\
from existencias as a inner join						\n\
     existenciaexpendiobodegas as b on(a.cveproducto=b.cveproducto and		\n\
     				       a.idexpendio=b.idexpendio)  		\n\
where a.idexpendio=%s and 							\n\
      a.cveproducto like '%%%s%%'						\n\
order by a.existencia desc",
pSArgsSiscom->chrPtrArgConsulta[3],
pSArgsSiscom->chrPtrArgConsulta[7],

pSArgsSiscom->chrPtrArgConsulta[3],
pSArgsSiscom->chrPtrArgConsulta[4],

pSArgsSiscom->chrPtrArgConsulta[3],
pSArgsSiscom->chrPtrArgConsulta[4],

pSArgsSiscom->chrPtrArgConsulta[5],
pSArgsSiscom->chrPtrArgConsulta[7],

pSArgsSiscom->chrPtrArgConsulta[5],
pSArgsSiscom->chrPtrArgConsulta[7],

pSArgsSiscom->chrPtrArgConsulta[1],
pSArgsSiscom->chrPtrArgConsulta[2]);
SiscomImprimeArgumentosConsulta(pSArgsSiscom);
SiscomLog("%s",lchrArrSql);
SiscomConsultaBaseSinEnvio2(lchrArrSql,pSArgsSiscom);
SiscomContenidoProtocolo(pSArgsSiscom->LCSiscomPro2Regreso);

}

void SqlExistenciasExpendio(SArgsSiscom *pSArgsSiscom)
{

char lchrArrSql[2048];

SiscomImprimeArgumentosConsulta(pSArgsSiscom);
sprintf(lchrArrSql,
"select a.cveproducto,								\n\
 a.existencia+b.exbodegas as total,						\n\
 a.existencia,									\n\
 b.exbodegas as exbodegas,							\n\
 a.eximinima,									\n\
 '' as fechaultimacompra,							\n\
 '' as cantidadultimacompra,							\n\
 '' as precioultimacompra,							\n\
 '' as proveedor,								\n\
 ultimacompra(a.cveproducto,'%s','%s',a.idexpendio),				\n\
 totalventas(a.cveproducto,'%s','%s',a.idexpendio) as ventsemestreanterior,	\n\
 totalcompras(a.cveproducto,'%s','%s',a.idexpendio) as comsemestreanterior,	\n\
 totalventas(a.cveproducto,'%s','%s',a.idexpendio) as ventactuales,		\n\
 totalcompras(a.cveproducto,'%s','%s',a.idexpendio) as comactuales		\n\
from existencias as a inner join						\n\
     existenciaexpendiobodegas as b on(a.cveproducto=b.cveproducto and		\n\
     				       a.idexpendio=b.idexpendio)  		\n\
where a.idexpendio=%s								\n\
order by a.cveproducto desc",
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

void SqlExistenciasProductosBodega(SArgsSiscom *pSArgsSiscom)
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
       0 as ventsemestreanterior,							\n\
       totalcompras(a.cveproducto,'%s','%s',a.idexpendio) as comsemestreanterior,	\n\
       0 as ventactuales,								\n\
       totalcompras(a.cveproducto,'%s','%s',a.idexpendio) as comactuales		\n\
from existencias as a inner join 							\n\
     existenciaexpendiobodegas as b on(a.cveproducto=b.cveproducto and 			\n\
                                       a.idexpendio=b.idexpendio)			\n\
where a.idexpendio=%s and 								\n\
      a.cveproducto in (select distinct cveproducto					\n\
                        from materialbodega						\n\
			where existencia>0)						\n\
order by a.cveproducto ",
pSArgsSiscom->chrPtrArgConsulta[4],
pSArgsSiscom->chrPtrArgConsulta[6],

pSArgsSiscom->chrPtrArgConsulta[2],
pSArgsSiscom->chrPtrArgConsulta[3],

pSArgsSiscom->chrPtrArgConsulta[4],
pSArgsSiscom->chrPtrArgConsulta[6],

pSArgsSiscom->chrPtrArgConsulta[1]);
SiscomImprimeArgumentosConsulta(pSArgsSiscom);
SiscomLog("%s",lchrArrSql);
SiscomConsultaBaseSinEnvio2(lchrArrSql,pSArgsSiscom);


}
