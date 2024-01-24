#include <SqlOrdenCompra.h>

void SqlComprasProductoSemestreAnterior(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSql[512];
sprintf(lchrArrSql,
	"select sum(cantidad) as ComSemAnt	\n\
	 from compras 				\n\
	 where fecha::date>='%s' and 		\n\
	       fecha::date<='%s' and 		\n\
	       cveproducto='%s'",
	 SiscomObtenCampoArgumento("FechasSemestres","FechaIniSemAnterior",pSAgsSiscom),
	 SiscomObtenCampoArgumento("FechasSemestres","FechaFinSemAnterior",pSAgsSiscom),
	 SiscomCampoDatosEntrada("CveProducto",pSAgsSiscom));
SiscomConsultaBaseAsignaArgumento("SqlComprasSemestreAnterior",
				   lchrArrSql,
				   pSAgsSiscom);
}

void SqlVentasProductoSemestreAnterior(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSql[512];
sprintf(lchrArrSql,
	"select sum(cantidad) as VenSemAnt 		\n\
	 from ventas 					\n\
	 where fechahora::date>='%s' and 		\n\
	       fechahora::date<='%s' and 		\n\
	       cveproducto='%s'",
	 SiscomObtenCampoArgumento("FechasSemestres","FechaIniSemAnterior",pSAgsSiscom),
	 SiscomObtenCampoArgumento("FechasSemestres","FechaFinSemAnterior",pSAgsSiscom),
	 SiscomCampoDatosEntrada("CveProducto",pSAgsSiscom));
SiscomConsultaBaseAsignaArgumento("SqlVentasSemestreAnterior",
				   lchrArrSql,
				   pSAgsSiscom);
}


void SqlComprasProductoSemestreActual(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSql[512];
sprintf(lchrArrSql,
	"select sum(cantidad) as ComSemAct	\n\
	 from compras 				\n\
	 where fecha::date>='%s' and 		\n\
	       fecha::date<='%s' and 		\n\
	       cveproducto='%s'",
	 SiscomObtenCampoArgumento("FechasSemestres","FechaIniSemActual",pSAgsSiscom),
	 SiscomObtenCampoArgumento("FechasSemestres","FechaFinSemActual",pSAgsSiscom),
	 SiscomCampoDatosEntrada("CveProducto",pSAgsSiscom));
SiscomConsultaBaseAsignaArgumento("SqlComprasSemestreActual",
				   lchrArrSql,
				   pSAgsSiscom);
}

void SqlVentasProductoSemestreActual(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSql[512];
sprintf(lchrArrSql,
	"select sum(cantidad) as VenSemAct 		\n\
	 from ventas 					\n\
	 where fechahora::date>='%s' and 		\n\
	       fechahora::date<='%s' and 		\n\
	       cveproducto='%s'",
	 SiscomObtenCampoArgumento("FechasSemestres","FechaIniSemActual",pSAgsSiscom),
	 SiscomObtenCampoArgumento("FechasSemestres","FechaFinSemActual",pSAgsSiscom),
	 SiscomCampoDatosEntrada("CveProducto",pSAgsSiscom));
SiscomConsultaBaseAsignaArgumento("SqlVentasSemestreActual",
				   lchrArrSql,
				   pSAgsSiscom);
}

void SqlExistenciasPrecio(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSql[512];
sprintf(lchrArrSql,
	"select existencia,exbodegas,precio 		\n\
	 from existenciaexpendiobodegas inner join	\n\
	      precios using(cveproducto)		\n\
	 where cveproducto='%s'	and			\n\
	       idexpendio=%s",
	 SiscomCampoDatosEntrada("CveProducto",pSAgsSiscom),
	 SiscomCampoDatosEntrada("IdExpendio",pSAgsSiscom));
SiscomConsultaBaseAsignaArgumento("SqlExistencias",
				   lchrArrSql,
				   pSAgsSiscom);
}

void SqlHistoricoComprasOrden(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSql[1024];
sprintf(lchrArrSql,
"select a.cveproducto,								\n\
	fecha::date,								\n\
	cantidad,								\n\
	importe,								\n\
	proveedor,								\n\
	numfactura,								\n\
	precio,									\n\
	preciosiniva,								\n\
	cveproveedor,								\n\
	razonsocial								\n\
from compras as a  inner join  							\n\
	clavesproveedores as b on  (a.cveproducto=b.cveproducto and 		\n\
				   a.proveedor=b.idempresa) inner join		\n\
	empresas as c on a.proveedor=c.idempresa				\n\
where fecha<=current_date and  							\n\
      proveedor!=0      and							\n\
      a.cveproducto='%s'							\n\
order by fecha desc								\n\
limit 20",
SiscomCampoDatosEntrada("CveProducto",pSAgsSiscom));
SiscomConsultaBaseAsignaArgumento("SqlHistorico",
				   lchrArrSql,
				   pSAgsSiscom);
}

void SqlTotalTransferencias(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSql[1024];
sprintf(lchrArrSql,
"select sum(cantidad) as tottrans		\n\
 from transfierematerial 			\n\
 where fechahora::date>='%s' and 	\n\
       fechahora::date<='%s' and 	\n\
       cveproducto='%s'",
SiscomObtenCampoArgumento("FechasSemestres","FechaIniSemActual",pSAgsSiscom),
SiscomObtenCampoArgumento("FechasSemestres","FechaFinSemActual",pSAgsSiscom),
SiscomCampoDatosEntrada("CveProducto",pSAgsSiscom));
SiscomConsultaBaseAsignaArgumento("SqlTotalTransferencias",
				   lchrArrSql,
				   pSAgsSiscom);
}

void SqlTransferenciasPorExpendio(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSql[1024];
sprintf(lchrArrSql,
"								\n\
select sum(cantidad),						\n\
	razonsocial						\n\
from transfierematerial  as a inner join 			\n\
	empresas as b on a.idempresadestino=b.idempresa		\n\
where 	fechahora::date>='%s' and 				\n\
	fechahora::date<='%s' and 				\n\
	cveproducto='%s'					\n\
group by  razonsocial 						\n\
order by 1 desc",
SiscomObtenCampoArgumento("FechasSemestres","FechaIniSemActual",pSAgsSiscom),
SiscomObtenCampoArgumento("FechasSemestres","FechaFinSemActual",pSAgsSiscom),
SiscomCampoDatosEntrada("CveProducto",pSAgsSiscom));
SiscomConsultaBaseAsignaArgumento("SqlTransferenciasPorExpendio",
				   lchrArrSql,
				   pSAgsSiscom);
}
