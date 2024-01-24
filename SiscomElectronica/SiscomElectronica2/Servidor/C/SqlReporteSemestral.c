#include <SqlReporteSemestral.h>

void SqlReporteSemestral(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSql[2048];
/* Martes 8 de Enero del 2013
 * Se cambio la tabla de donde de toman los productos,
 * ya que en este reporte no se reflaja la informacion
 * total del negocio sino solo los productos que se 
 * vendieron
 */
/*
sprintf(lchrArrSql,
"										\n\
select b.precio as precioventa,							\n\
	sum(cantidad) as total,							\n\
	ExistenciaActual(cveproducto,%s) as inventario,				\n\
       cveproducto,								\n\
       UltimaCompra(cveproducto,'%s'::date,'%s'::date,%s) as ultimacompra,	\n\
       '' as fechaucompra,							\n\
       '' as cantidaducompra,							\n\
       '' as precioucompra,							\n\
       '' as proveedor								\n\
from ventas inner join precios as b using (cveproducto)				\n\
where fechahora::date>='%s' and							\n\
      fechahora::date<='%s' and							\n\
      idexpendio=%s								\n\
group by cveproducto,b.precio							\n\
order by cveproducto desc							\n\
",
pSAgsSiscom->chrPtrArgConsulta[1],
pSAgsSiscom->chrPtrArgConsulta[2],
pSAgsSiscom->chrPtrArgConsulta[3],
pSAgsSiscom->chrPtrArgConsulta[1],
pSAgsSiscom->chrPtrArgConsulta[2],
pSAgsSiscom->chrPtrArgConsulta[3],
pSAgsSiscom->chrPtrArgConsulta[1]);
*/
sprintf(lchrArrSql,
"										\n\
select b.precio as precioventa,							\n\
	sum(cantidad) as total,							\n\
	ExistenciaActual(cveproducto,%s) as inventario,				\n\
       cveproducto,								\n\
       UltimaCompra(cveproducto,'%s'::date,'%s'::date,%s) as ultimacompra,	\n\
       '' as fechaucompra,							\n\
       '' as cantidaducompra,							\n\
       '' as precioucompra,							\n\
       '' as proveedor								\n\
from ventas inner join precios as b using (cveproducto)			\n\
where fechahora::date>='%s' and							\n\
      fechahora::date<='%s' and							\n\
      idexpendio=%s								\n\
group by cveproducto,b.precio							\n\
order by cveproducto desc							\n\
",
pSAgsSiscom->chrPtrArgConsulta[1],
pSAgsSiscom->chrPtrArgConsulta[2],
pSAgsSiscom->chrPtrArgConsulta[3],
pSAgsSiscom->chrPtrArgConsulta[1],
pSAgsSiscom->chrPtrArgConsulta[2],
pSAgsSiscom->chrPtrArgConsulta[3],
pSAgsSiscom->chrPtrArgConsulta[1]);
SiscomLog("%s",lchrArrSql);
SiscomConsultaBaseSinEnvio2(lchrArrSql,pSAgsSiscom);
}
