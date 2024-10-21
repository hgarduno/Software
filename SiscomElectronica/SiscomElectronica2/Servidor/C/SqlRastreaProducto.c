#include <SqlRastreaProducto.h>
/*
 * Lunes 19 De Septiembre 2011 
 * Se debe revisar que pasa cuando en la tabla 
 * de ventas se registra una cotizacion edoventa 
 * y despues esta cotizacion se vende, ser cambia 
 * el valor en edoventa, o que pasa 
 *
 */
void SqlExistenciaProducto(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSql[512];

sprintf(lchrArrSql,
	"select *			\n\
	 from existenciaexpendiobodegas	\n\
	 where idexpendio=%s and 	\n\
	 	cveproducto='%s'",
	 SiscomCampoRegistroPrincipal(pSAgsSiscom->LCSiscomPro2SREntrada,
	 			      "IdExpendio"),
	 SiscomCampoSubRegistroArgs(0,"cveproducto",pSAgsSiscom));
if(SiscomConsultaBaseAsignaArgumento(
		"SqlExistencia",
		lchrArrSql,
		pSAgsSiscom))
SiscomPonPrimerRegistroArgumento("SqlExistencia",pSAgsSiscom);
}


void SqlExiProductoBodegas(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSql[512];

sprintf(lchrArrSql,
	"select a.*,bodega			\n\
	 from materialbodega as a inner join 	\n\
	      bodegas as b using(idbodega) 	\n\
	 where cveproducto='%s'",
	 SiscomCampoSubRegistroArgs(0,"cveproducto",pSAgsSiscom));
if(SiscomConsultaBaseAsignaArgumento(
		"SqlExBodegas",
		lchrArrSql,
		pSAgsSiscom))
SiscomPonPrimerRegistroArgumento("SqlExBodegas",pSAgsSiscom);
}

void SqlVentasProductoAnterior(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSql[512];
sprintf(lchrArrSql,
	"SELECT * 				\n\
	 from ventas 				\n\
	 where fechahora::date>='%s' and 	\n\
	       fechahora::date<='%s' and 	\n\
	       cveproducto='%s' and edoventa in(0,9,4)	\n\
	 order by fechahora desc;",
	SiscomCampoSubRegistroArgs(1,"FechaIni",pSAgsSiscom),
	SiscomCampoSubRegistroArgs(1,"FechaFin",pSAgsSiscom),
	SiscomCampoSubRegistroArgs(0,"CveProducto",pSAgsSiscom));
if(SiscomConsultaBaseAsignaArgumento(
		"SqlVentas",
		lchrArrSql,
		pSAgsSiscom))
SiscomPonPrimerRegistroArgumento("SqlVentas",pSAgsSiscom);
}


void SqlTotalVentasAnterior(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSql[512];
sprintf(lchrArrSql,
	"SELECT sum(cantidad) as totalventas	\n\
	 from ventas 				\n\
	 where fechahora::date>='%s' and 	\n\
	       fechahora::date<='%s' and 	\n\
	       cveproducto='%s'	     and 	\n\
	       edoventa in(0,9,4);",
	SiscomCampoSubRegistroArgs(1,"FechaIni",pSAgsSiscom),
	SiscomCampoSubRegistroArgs(1,"FechaFin",pSAgsSiscom),
	SiscomCampoSubRegistroArgs(0,"CveProducto",pSAgsSiscom));
if(SiscomConsultaBaseAsignaArgumento(
		"SqlTotalVentas",
		lchrArrSql,
		pSAgsSiscom))
SiscomPonPrimerRegistroArgumento("SqlTotalVentas",pSAgsSiscom);
}


void SqlComprasProductoAnterior(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSql[512];
sprintf(lchrArrSql,
	"SELECT a.*,						\n\
		razonsocial					\n\
	 from compras as a inner join				\n\
	 	empresas as b on(a.proveedor=b.idempresa)	\n\
	 where fecha::date>='%s' and 				\n\
	       fecha::date<='%s' and 				\n\
	       cveproducto='%s'					\n\
	  order by fecha desc;",
	SiscomCampoSubRegistroArgs(1,"FechaIni",pSAgsSiscom),
	SiscomCampoSubRegistroArgs(1,"FechaFin",pSAgsSiscom),
	SiscomCampoSubRegistroArgs(0,"CveProducto",pSAgsSiscom));
if(SiscomConsultaBaseAsignaArgumento(
		"SqlCompras",
		lchrArrSql,
		pSAgsSiscom))
SiscomPonPrimerRegistroArgumento("SqlCompras",pSAgsSiscom);

}


void SqlTotalComprasAnterior(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSql[256];
sprintf(lchrArrSql,
	"SELECT sum(cantidad) as totalcompras 	\n\
	 from compras 				\n\
	 where fecha::date>='%s' and 		\n\
	       fecha::date<='%s' and 		\n\
	       cveproducto='%s'",
	SiscomCampoSubRegistroArgs(1,"FechaIni",pSAgsSiscom),
	SiscomCampoSubRegistroArgs(1,"FechaFin",pSAgsSiscom),
	SiscomCampoSubRegistroArgs(0,"CveProducto",pSAgsSiscom));
if(SiscomConsultaBaseAsignaArgumento(
		"SqlTotalCompras",
		lchrArrSql,
		pSAgsSiscom))
SiscomPonPrimerRegistroArgumento("SqlTotalCompras",pSAgsSiscom);

}

void SqlTransferenciasExpendioExpendio(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSql[512];
sprintf(lchrArrSql,
	"SELECT a.*,								\n\
		b.razonsocial as destino,					\n\
		c.razonsocial as origen						\n\
	 from transfierematerial as a  inner join				\n\
	 	empresas as b on(b.idempresa=a.idempresadestino) inner join 	\n\
		empresas as c on(c.idempresa=a.idempresaorigen) 		\n\
	 where fechahora::date>='%s' and 					\n\
	       fechahora::date<='%s' and 					\n\
	       cveproducto='%s'							\n\
	 order by fechahora desc",
	SiscomCampoSubRegistroArgs(1,"FechaIni",pSAgsSiscom),
	SiscomCampoSubRegistroArgs(1,"FechaFin",pSAgsSiscom),
	SiscomCampoSubRegistroArgs(0,"CveProducto",pSAgsSiscom));
if(SiscomConsultaBaseAsignaArgumento(
		"SqlTransExpendioExpendio",
		lchrArrSql,
		pSAgsSiscom))
SiscomPonPrimerRegistroArgumento("SqlTransExpendioExpendio",pSAgsSiscom);
}


void SqlTotalTransExpExp(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSql[512];
sprintf(lchrArrSql,
	"SELECT sum(cantidad) as tottransexpexp		\n\
	 from transfierematerial 			\n\
	 where fechahora::date>='%s' and 		\n\
	       fechahora::date<='%s' and 		\n\
	       cveproducto='%s'",
	SiscomCampoSubRegistroArgs(1,"FechaIni",pSAgsSiscom),
	SiscomCampoSubRegistroArgs(1,"FechaFin",pSAgsSiscom),
	SiscomCampoSubRegistroArgs(0,"CveProducto",pSAgsSiscom));
if(SiscomConsultaBaseAsignaArgumento(
		"SqlTotalTransExpExp",
		lchrArrSql,
		pSAgsSiscom))
SiscomPonPrimerRegistroArgumento("SqlTotalTransExpExp",pSAgsSiscom);
}

void SqlTransferenciasBodegasExpendio(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSql[512];
sprintf(lchrArrSql,
	"SELECT a.*,						\n\
		b.razonsocial					\n\
	 from bodegaaexpendio as a inner join			\n\
	 	empresas as b on (a.idexpendio=b.idempresa)	\n\
	 where fecha::date>='%s' and 				\n\
	       fecha::date<='%s' and 				\n\
	       cveproducto='%s'					\n\
	 order by fecha desc;",
	SiscomCampoSubRegistroArgs(1,"FechaIni",pSAgsSiscom),
	SiscomCampoSubRegistroArgs(1,"FechaFin",pSAgsSiscom),
	SiscomCampoSubRegistroArgs(0,"CveProducto",pSAgsSiscom));
if(SiscomConsultaBaseAsignaArgumento(
		"SqlTransBodegaExpendio",
		lchrArrSql,
		pSAgsSiscom))
SiscomPonPrimerRegistroArgumento("SqlTransBodegaExpendio",pSAgsSiscom);
}


void SqlTotalTransBodExp(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSql[512];
sprintf(lchrArrSql,
	"SELECT sum(cantidad) as tottransbodexp \n\
	 from bodegaaexpendio			\n\
	 where fecha::date>='%s' and 		\n\
	       fecha::date<='%s' and 		\n\
	       cveproducto='%s';",
	SiscomCampoSubRegistroArgs(1,"FechaIni",pSAgsSiscom),
	SiscomCampoSubRegistroArgs(1,"FechaFin",pSAgsSiscom),
	SiscomCampoSubRegistroArgs(0,"CveProducto",pSAgsSiscom));
if(SiscomConsultaBaseAsignaArgumento(
		"SqlTotalTransBodExp",
		lchrArrSql,
		pSAgsSiscom))
SiscomPonPrimerRegistroArgumento("SqlTotalTransBodExp",pSAgsSiscom);
}


void SqlActualizoInventario(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSql[512];
sprintf(lchrArrSql,
	"SELECT * 				\n\
	 from inventario 			\n\
	 where fecharegistro>='%s' and 		\n\
	       fecharegistro<='%s' and 		\n\
	       cveproducto='%s'			\n\
	 order by fecharegistro desc;",
	SiscomCampoSubRegistroArgs(1,"FechaIni",pSAgsSiscom),
	SiscomCampoSubRegistroArgs(1,"FechaFin",pSAgsSiscom),
	SiscomCampoSubRegistroArgs(0,"CveProducto",pSAgsSiscom));
if(SiscomConsultaBaseAsignaArgumento(
		"SqlActualizoInventario",
		lchrArrSql,
		pSAgsSiscom))
SiscomPonPrimerRegistroArgumento("SqlActualizoInventario",pSAgsSiscom);
}

void SqlTransferenciaBodegaBodega(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSql[512];
sprintf(lchrArrSql,
	"select a.*,								\n\
		b.bodega as BodegaOrigen,					\n\
		c.bodega as BodegaDestino					\n\
	from 	transferenciabodegabodega as a inner join			\n\
        	bodegas as b on a.idbodegaorigen=b.idbodega   inner join	\n\
        	bodegas as c on a.idbodegadestino=c.idbodega			\n\
	where fecha::date>='%s' and						\n\
        	fecha::date<='%s' and						\n\
		cveproducto='%s';",
	SiscomCampoSubRegistroArgs(1,"FechaIni",pSAgsSiscom),
	SiscomCampoSubRegistroArgs(1,"FechaFin",pSAgsSiscom),
	SiscomCampoSubRegistroArgs(0,"CveProducto",pSAgsSiscom));

if(SiscomConsultaBaseAsignaArgumento(
		"SqlTransferenciaBodegaBodega",
		lchrArrSql,
		pSAgsSiscom))
SiscomPonPrimerRegistroArgumento("SqlTransferenciaBodegaBodega",pSAgsSiscom);

}
