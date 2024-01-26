#include <SqlReportes.h>
#include <SqlCreditos.h>
#include <SqlApartados.h>
#include <SqlReportes.h>
#include <Reportes.h>
#include <ComunSiscomServiSNTE.h>
#include <SiscomDesarrolloMacros.h>

#include <SiscomInsercionesSql.h>
#include <SiscomReplicacion.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int SqlReporteVentas(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[512],
	lchrArrSql[256];
sprintf(lchrArrSql,
	"select sum(total) as importe,		\n\
	 fecha::date 				\n\
	 from ventas as a inner join 		\n\
	      importeventa using(idventa) 	\n\
	 where idtipoventa=%s and 		\n\
	       fecha::date>='%s' and			\n\
	       fecha::date<='%s'			\n\
	 group by fecha::date",
	 SiscomCampoAsociadoEntradaOperacion("Envio","IdTipoVenta",pSiscomOpePtrDat),
	 SiscomCampoAsociadoEntradaOperacion("Envio","FechaIni",pSiscomOpePtrDat),
	 SiscomCampoAsociadoEntradaOperacion("Envio","FechaFin",pSiscomOpePtrDat));
SiscomConsultasSqlServidorPorIdMaquina(
	 SiscomCampoAsociadoEntradaOperacion("Envio","IdTienda",pSiscomOpePtrDat),
	 gSiscomRegProLPtrMemoria,
	 lchrArrBuffer,
	 pSiscomOpePtrDat,
	"ReporteVentas%",
	lchrArrSql);
}
void SqlConsultaVentasCliente(SiscomOperaciones *pSiscomOpePtrDat,
			      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
"									\n\
select idplazo,								\n\
	folio,								\n\
	fecha,								\n\
	idfinanciadora,							\n\
	idventa,							\n\
	idtipoventa,							\n\
	c.nombre as NomTipoVenta,					\n\
	total,								\n\
	e.nombre as financiadora,					\n\
	f.nombre as plazo,						\n\
	case when meses=12 						\n\
			then 						\n\
				(fecha + interval '12 mons')::date	\n\
	     when meses=18 						\n\
	     		then 						\n\
				(fecha + interval '18 mons')::date  	\n\
	     when meses=24						\n\
	     		then 						\n\
				(fecha + interval '24 mons')::date	\n\
	end as vencimiento						\n\
from ventas as a  inner  join						\n\
     importeventa as b using(idventa) inner join			\n\
     tipoventas as c using(idtipoventa)   left outer join		\n\
     ventacredito as d using(idventa) left outer join			\n\
     financiadoras as e using(idfinanciadora) left outer join		\n\
     plazos as f using(idplazo)						\n\
where idcliente in (select  idpersona					\n\
	            from personas 					\n\
		    where rfc='%s');",
SiscomCampoAsociadoEntradaOperacion("Envio","RFC",pSiscomOpePtrDat));
}

int SqlVentasCliente(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[1024],
	lchrArrSqlVentasCliente[1024],
	lchrArrSqlPersona[1024];
SqlConsultaVentasCliente(pSiscomOpePtrDat,lchrArrSqlVentasCliente);
SqlPersonaPorRFC(pSiscomOpePtrDat,lchrArrSqlPersona);
SiscomConsultasSqlOperaciones(lchrArrBuffer,
		   pSiscomOpePtrDat,
		   "VentasCliente%Cliente%",
		   lchrArrSqlVentasCliente,
		   lchrArrSqlPersona);
return 0;
}


int SqlExistenciasTienda(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[512],
	lchrArrSql[256];
sprintf(lchrArrSql,
	"							\n\
select *,							\n\
	case when c.idproducto is null then 0 			\n\
	else 							\n\
	  a.existencia 						\n\
	  end as stock  					\n\
from existencia as a inner join					\n\
     productos as b using(idproducto) left outer join		\n\
     productostock	as c using(idproducto) inner join	\n\
     productoproveedor as d using(idproducto) inner join 	\n\
     empresas as e using(idempresa)				\n\
order by a.existencia desc");
ExistenciasTiendaLocalRemota(gSiscomRegProLPtrMemoria,
			     pSiscomOpePtrDat,
			     lchrArrSql);
}

int SqlExistenciasAlmacen(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[512],
	lchrArrSql[512];
sprintf(lchrArrSql,
	"							\n\
select a.*,							\n\
	b.*							\n\
 	idempresa,						\n\
	razonsocial						\n\
from existencia as a inner join					\n\
     productos as b using(idproducto) inner join		\n\
     productoproveedor as c using(idproducto) inner join	\n\
     empresas as d using(idempresa)				\n\
order by							\n\
existencia asc");
SiscomConsultasSqlOperaciones(lchrArrBuffer,
		   pSiscomOpePtrDat,
		   "ExistenciasAlmacen%",
		   lchrArrSql);

}
int SqlExistenciasAlmacenProveedor(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[512],
	lchrArrSql[512];
sprintf(lchrArrSql,
	"						\n\
select a.*,b.*						\n\
from existenciaalmacen as a inner join			\n\
     productos as b using(idproducto) inner join 	\n\
     productoproveedor as c using(idproducto) 		\n\
where idempresa=%s",
SiscomCampoAsociadoEntradaOperacion("Envio","idempresa",pSiscomOpePtrDat));

SiscomConsultasSqlOperaciones(lchrArrBuffer,
		   pSiscomOpePtrDat,
		   "ExistenciasAlmacen%",
		   lchrArrSql);

}
void AsignaMemoriaConsultaSql(const char *pchrPtrSql,
			      const char *pchrPtrCondicion,
			      char **pchrPtrConsultaSql)
{
int lintTamano=strlen(pchrPtrSql)+
		strlen(pchrPtrCondicion);
*pchrPtrConsultaSql=(char *)malloc(lintTamano);
}
int SqlExistenciasAlmacenListaProductos(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[512],
	lchrArrSql[512],
	*lchrPtrCondicion,
	*lchrPtrSql;

FormaCondicionConsultaListaProductos(pSiscomOpePtrDat,&lchrPtrCondicion);
LogSiscom("La Condicion:%s Tamano(%d) ",lchrPtrCondicion,strlen(lchrPtrCondicion));
sprintf(lchrArrSql,
	"							\n\
select a.*,							\n\
	b.*,idempresa,razonsocial				\n\
from existenciaalmacen as a inner join 				\n\
	productos as b using(idproducto) inner join		\n\
	productocodigobarras using(idproducto) inner join 	\n\
	productoproveedor using(idproducto) inner join 		\n\
	empresas using(idempresa)				\n\
	");

AsignaMemoriaConsultaSql(lchrArrSql,lchrPtrCondicion,&lchrPtrSql);

sprintf(lchrPtrSql,"%s %s",lchrArrSql,lchrPtrCondicion);
SiscomConsultasSqlOperaciones(lchrArrBuffer,
		   pSiscomOpePtrDat,
		   "ExistenciasAlmacen%",
		   lchrPtrSql);

}

int SqlExistenciasTiendaListaProductos(SiscomOperaciones *pSiscomOpePtrDat)
{
char *lchrArrBuffer,
	*lchrArrSql,
	*lchrPtrCondicion;
const char *lchrPtrIdTienda;
int lintTamano;
FormaCondicionConsultaListaProductosTienda(pSiscomOpePtrDat,&lchrPtrCondicion);
lintTamano=512+strlen(lchrPtrCondicion);
lchrArrSql=(char *)malloc(lintTamano);
lchrArrBuffer=(char *)malloc(lintTamano);
sprintf(lchrArrSql,
	"								\n\
select a.*,								\n\
	b.*,								\n\
	idempresa,							\n\
	razonsocial							\n\
from existencia as a inner join 					\n\
	productos as b using(idproducto) inner join			\n\
	productocodigobarras using(idproducto) inner join		\n\
	productoproveedor as d using(idproducto) inner join 		\n\
	empresas as e using(idempresa)					\n\
	%s",
	lchrPtrCondicion);
ExistenciasTiendaLocalRemota(gSiscomRegProLPtrMemoria,
			     pSiscomOpePtrDat,
			     lchrArrSql);
}


int SqlExistenciasProductoTienda(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[512],
	lchrArrSql[256];
sprintf(lchrArrSql,
	"							\n\
select *,c.existencia as stock,					\n\
 	e.razonsocial,						\n\
	e.idempresa						\n\
from existencia as a inner join					\n\
     productos as b using(idproducto) left outer join		\n\
     stock as c using(idproducto) inner join 			\n\
     productoproveedor as d using(idproducto) inner join 	\n\
     empresas as e using(idempresa)				\n\
where idproducto=%s						\n\
order by a.existencia asc",
SiscomCampoAsociadoEntradaOperacion("Envio","idproducto",pSiscomOpePtrDat));

ExistenciasTiendaLocalRemota(gSiscomRegProLPtrMemoria,
			     pSiscomOpePtrDat,
			     lchrArrSql);
}

int SqlExistenciasProductoAlmacen(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[512],
	lchrArrSql[512];
sprintf(lchrArrSql,
	"							\n\
select a.*,b.*,idempresa,razonsocial				\n\
from existenciaalmacen as a inner join				\n\
     productos as b using(idproducto) inner join		\n\
     productoproveedor as c using(idproducto) inner join	\n\
     empresas as e using(idempresa)				\n\
where idproducto=%s						\n\
order by							\n\
existencia asc",
SiscomCampoAsociadoEntradaOperacion("Envio","idproducto",pSiscomOpePtrDat));
SiscomConsultasSqlOperaciones(lchrArrBuffer,
		   pSiscomOpePtrDat,
		   "ExistenciasAlmacen%",
		   lchrArrSql);
}

int SqlExistenciasTiendaProveedor(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[1024],
	lchrArrSql[1024] ;
const char *lchrPtrIdTienda;
sprintf(lchrArrSql,
	"							\n\
select case when d.idproducto is null 				\n\
	then a.existencia					\n\
	else							\n\
	null							\n\
	end as existencia,					\n\
	b.*,							\n\
	c.*,							\n\
		case when d.idproducto is null 			\n\
		then null 					\n\
		else 						\n\
		existencia 					\n\
		end as stock,					\n\
	idempresa,						\n\
	razonsocial						\n\
from existencia as a inner join					\n\
     productos as b using(idproducto) inner join		\n\
     productoproveedor as c using(idproducto) left outer join	\n\
     productostock as d using(idproducto) inner join		\n\
     empresas as e using(idempresa)				\n\
where idempresa=%s",
SiscomCampoAsociadoEntradaOperacion("Envio","idempresa",pSiscomOpePtrDat));
ExistenciasTiendaLocalRemota(gSiscomRegProLPtrMemoria,
			     pSiscomOpePtrDat,
			     lchrArrSql);


}

int SqlReporteCompras(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[512],
	lchrArrSql[512];
sprintf(lchrArrSql,
	"								\n\
select  *								\n\
from compras a inner join 						\n\
	tipodocumentos as b using(idtipodocumento) inner join		\n\
	empresas as c using(idempresa) inner join 			\n\
	conceptosexistencias using(idconceptosexistencias)		\n\
where fecha>='%s' and fecha<='%s'",
SiscomCampoAsociadoEntradaOperacion("Envio","FechaIni",pSiscomOpePtrDat),
SiscomCampoAsociadoEntradaOperacion("Envio","FechaFin",pSiscomOpePtrDat));

LogSiscom("%s",lchrArrSql);

SiscomConsultasSqlOperaciones(lchrArrBuffer,
		   pSiscomOpePtrDat,
		   "ReporteCompras%",
		   lchrArrSql);
}

int SqlReporteDetalleCompra(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[512],
	lchrArrSql[256];
sprintf(lchrArrSql,
	"								\n\
select * from detallecompras inner join 				\n\
	productos using(idproducto)					\n\
where idcompra=%s							\n\
order by nombreproducto",
SiscomCampoAsociadoEntradaOperacion("Envio","idcompra",pSiscomOpePtrDat));

LogSiscom("%s",lchrArrSql);

SiscomConsultasSqlOperaciones(lchrArrBuffer,
		   pSiscomOpePtrDat,
		   "ReporteDetalleCompras%",
		   lchrArrSql);
}


int SqlConsultaFoliosCancelados(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[512],
	lchrArrSql[256];

LogSiscom("El Rango de fechas %s %s",
	 SiscomCampoAsociadoEntradaOperacion("Envio","FechaInicio",pSiscomOpePtrDat),
	 SiscomCampoAsociadoEntradaOperacion("Envio","FechaFinal",pSiscomOpePtrDat));
	
sprintf(lchrArrSql,
"					\n\
select a.*,				\n\
	fecha				\n\
from foliocancelado a inner join 	\n\
	ventas as b using(idventa)	\n\
	where fecha::date>='%s' and	\n\
		fecha::date<='%s'",
	SiscomCampoAsociadoEntradaOperacion("Envio","FechaInicio",pSiscomOpePtrDat),
	SiscomCampoAsociadoEntradaOperacion("Envio","FechaFinal",pSiscomOpePtrDat));

SiscomConsultasSqlServidorPorIdMaquina(
	 SiscomCampoAsociadoEntradaOperacion("Envio","IdTienda",pSiscomOpePtrDat),
	 gSiscomRegProLPtrMemoria,
	 lchrArrBuffer,
	 pSiscomOpePtrDat,
	"FoliosCancelados%",
	lchrArrSql);
}

int SqlStockDepartamentoProveedor(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[2048],
	lchrArrSql[2048];
sprintf(lchrArrSql,
"										\n\
select  a.idproducto,								\n\
	idempresa,								\n\
	idcostobruto,								\n\
	costobruto,								\n\
	costoneto,								\n\
	idpreciogeneral,							\n\
	preciogeneral,								\n\
	numproducto,								\n\
	nombreproducto,								\n\
	modelo,									\n\
	g.existencia as stock,							\n\
	costoneto*h.existencia as costototal,					\n\
	preciogeneral*h.existencia as totalventa,				\n\
	preciogeneral-costoneto as margen					\n\
from productoproveedor as a inner join 						\n\
     ultimocosto as b using(idproducto) inner join 				\n\
     costobruto as c on b.idcosto=c.idcostobruto  inner join			\n\
     ultimopreciogeneral as d on a.idproducto=d.idproducto inner join		\n\
     preciogeneral as e on d.idprecio=e.idpreciogeneral inner join		\n\
     productos as f on a.idproducto=f.idproducto left outer join		\n\
     stock as g on a.idproducto=g.idproducto inner join 			\n\
     existencia as h on a.idproducto=h.idproducto inner join 			\n\
     estatusproducto as i on a.idproducto=i.idproducto 				\n\
where idempresa=%s and 								\n\
      i.idestatus in(1,3)							\n\
order by numproducto ;",
	SiscomCampoAsociadoEntradaOperacion("Envio","IdProveedor",pSiscomOpePtrDat));
SiscomConsultasSqlServidorPorIdMaquina(
	 SiscomCampoAsociadoEntradaOperacion("Envio","IdTienda",pSiscomOpePtrDat),
	 gSiscomRegProLPtrMemoria,
	 lchrArrBuffer,
	 pSiscomOpePtrDat,
	"StockDepartamentoProveedor%",
	lchrArrSql);
}

int SqlPreciosProductos(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[2048],
	lchrArrSql[2048];
if(!SiscomCampoAsociadoEntradaOperacion("Envio","IdProveedor",pSiscomOpePtrDat))
sprintf(lchrArrSql,
"										\n\
select idprecio,								\n\
	b.idproducto,								\n\
	numproducto,								\n\
	b.nombreproducto,							\n\
	modelo,									\n\
	e.idempresa,								\n\
	razonsocial,								\n\
	preciogeneral,								\n\
	f.idproducto,								\n\
	h.existencia,								\n\
	f.existencia as stock							\n\
from ultimopreciogeneral as a inner join 					\n\
	productos as b using(idproducto) inner join 				\n\
	preciogeneral as c on a.idprecio=c.idpreciogeneral inner join		\n\
	productoproveedor as d on b.idproducto=d.idproducto inner join		\n\
	empresas as e on d.idempresa=e.idempresa inner join 			\n\
	stock as f on b.idproducto=f.idproducto inner join			\n\
	estatusproducto as g on b.idproducto=g.idproducto left outer join	\n\
	existencia as h on h.idproducto=b.idproducto				\n\
where idestatus in(1,3)								\n\
order by e.idempresa,								\n\
	 numproducto");
else
sprintf(lchrArrSql,
"										\n\
select idprecio,								\n\
	b.idproducto,								\n\
	numproducto,								\n\
	b.nombreproducto,							\n\
	modelo,									\n\
	e.idempresa,								\n\
	razonsocial,								\n\
	preciogeneral,								\n\
	i.existencia as stock,							\n\
	iddepartamento,								\n\
	nombredepto								\n\
from ultimopreciogeneral as a inner join					\n\
	productos as b using(idproducto) inner join				\n\
	departamentoproducto as c using(idproducto) inner join			\n\
	preciogeneral as d on a.idprecio=d.idpreciogeneral inner join		\n\
	productoproveedor as e on b.idproducto=e.idproducto inner join		\n\
	empresas as f on e.idempresa=f.idempresa inner join 			\n\
	stock as g on b.idproducto=g.idproducto inner join 			\n\
	estatusproducto as h on b.idproducto=h.idproducto  inner join		\n\
	existencia as i on i.idproducto=b.idproducto  inner join		\n\
	departamentos as j using(iddepartamento)				\n\
where idestatus in(1,3)  and e.idempresa=%s					\n\
order by iddepartamento,							\n\
	numproducto",
SiscomCampoAsociadoEntradaOperacion("Envio","IdProveedor",pSiscomOpePtrDat));

SiscomConsultasSqlServidorPorIdMaquina(
	 SiscomCampoAsociadoEntradaOperacion("Envio","IdTienda",pSiscomOpePtrDat),
	 gSiscomRegProLPtrMemoria,
	 lchrArrBuffer,
	 pSiscomOpePtrDat,
	"ListaPrecios%",
	lchrArrSql);
}


int SqlPreciosProductosComprador(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[2048],
	lchrArrSql[2048];
if(!SiscomCampoAsociadoEntradaOperacion("Envio","IdProveedor",pSiscomOpePtrDat))
sprintf(lchrArrSql,
"										\n\
select idprecio,								\n\
	b.idproducto,								\n\
	numproducto,								\n\
	b.nombreproducto,							\n\
	modelo,									\n\
	e.idempresa,								\n\
	razonsocial,								\n\
	preciogeneral,								\n\
	h.existencia								\n\
from ultimopreciogeneral as a inner join 					\n\
	productos as b using(idproducto) inner join 				\n\
	preciogeneral as c on a.idprecio=c.idpreciogeneral inner join		\n\
	productoproveedor as d on b.idproducto=d.idproducto inner join		\n\
	empresas as e on d.idempresa=e.idempresa inner join 			\n\
	estatusproducto as g on b.idproducto=g.idproducto left outer join	\n\
	existencia as h on h.idproducto=b.idproducto				\n\
where idestatus in(1,3)								\n\
order by e.idempresa,								\n\
	 numproducto");
else
sprintf(lchrArrSql,
"										\n\
select idprecio,								\n\
	b.idproducto,								\n\
	numproducto,								\n\
	b.nombreproducto,							\n\
	modelo,									\n\
	e.idempresa,								\n\
	razonsocial,								\n\
	preciogeneral,								\n\
	h.existencia,								\n\
	i.iddepartamento,							\n\
	nombredepto								\n\
from ultimopreciogeneral as a inner join 					\n\
	productos as b using(idproducto) inner join 				\n\
	preciogeneral as c on a.idprecio=c.idpreciogeneral inner join		\n\
	productoproveedor as d on b.idproducto=d.idproducto inner join		\n\
	empresas as e on d.idempresa=e.idempresa inner join 			\n\
	estatusproducto as g on b.idproducto=g.idproducto left outer join	\n\
	existencia as h on h.idproducto=b.idproducto inner join			\n\
	departamentoproducto as i on b.idproducto=i.idproducto  inner join	\n\
	departamentos as j using(iddepartamento)				\n\
where idestatus in(1,3) and e.idempresa=%s				\n\
order by i.iddepartamento,							\n\
	 numproducto",
SiscomCampoAsociadoEntradaOperacion("Envio","IdProveedor",pSiscomOpePtrDat));


SiscomConsultasSqlOperaciones(lchrArrBuffer,
                   pSiscomOpePtrDat,
                   "ListaPreciosComprador%",
                   lchrArrSql);
}


int SqlExistenciasProveedor(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[1024],
	lchrArrSql[1024];
const char *lchrPtrIdProducto;
if(!(lchrPtrIdProducto=SiscomCampoAsociadoEntradaOperacion("Envio","IdProducto",pSiscomOpePtrDato)))
sprintf(lchrArrSql,
	"							\n\
select idempresa,						\n\
	razonsocial,						\n\
	numproducto,						\n\
	nombreproducto,						\n\
	modelo,							\n\
	a.existencia,						\n\
	f.existencia as stock					\n\
from existencia as a inner join 				\n\
     productoproveedor as b using(idproducto) inner join 	\n\
     empresas as c using(idempresa) inner join 			\n\
     productos as d using(idproducto) inner join		\n\
     stock as f on d.idproducto=f.idproducto inner join	\n\
     estatusproducto as g on g.idproducto=d.idproducto		\n\
where idestatus in(1,3) and 					\n\
	idempresa=%s						\n\
order by idempresa,						\n\
	 numproducto",
	SiscomCampoAsociadoEntradaOperacion("Envio","IdProveedor",pSiscomOpePtrDato));
else
sprintf(lchrArrSql,
	"							\n\
select idempresa,						\n\
	razonsocial,						\n\
	numproducto,						\n\
	nombreproducto,						\n\
	modelo,							\n\
	a.existencia,						\n\
	f.existencia as stock					\n\
from existencia as a inner join 				\n\
     productoproveedor as b using(idproducto) inner join 	\n\
     empresas as c using(idempresa) inner join 			\n\
     productos as d using(idproducto) inner join		\n\
     stock as f on d.idproducto=f.idproducto inner join		\n\
     estatusproducto as g on g.idproducto=d.idproducto		\n\
where idestatus in(1,3) and 					\n\
	idempresa=%s    and					\n\
	d.idproducto=%s   					\n\
order by idempresa,						\n\
	 numproducto",
SiscomCampoAsociadoEntradaOperacion("Envio","IdProveedor",pSiscomOpePtrDato),
SiscomCampoAsociadoEntradaOperacion("Envio","IdProducto",pSiscomOpePtrDato));


SiscomConsultasSqlSistema("Servidor",
			 "siglas",
			 4,
			 gSiscomRegProLPtrMemoria,
			 (SiscomLogConsultaSistema )0,
			 (SiscomLogConsultaSistema )0,
			 lchrArrBuffer,
			 pSiscomOpePtrDato,
			 "ExistenciasProveedor%",
			 lchrArrSql);
}
int SqlStockTienda(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[2048],
	lchrArrSql[2048];
if(!SiscomCampoAsociadoEntradaOperacion("Envio","IdProveedor",pSiscomOpePtrDato))
sprintf(lchrArrSql,
"									\n\
select idempresa,							\n\
	razonsocial,							\n\
	a.idproducto,							\n\
	a.numproducto,							\n\
	a.modelo,							\n\
	a.nombreproducto,						\n\
	b.idproducto,							\n\
	c.idcosto,							\n\
	costobruto,							\n\
	costoneto,							\n\
	costoneto*b.existencia as importecosto,				\n\
	b.existencia as stock,						\n\
	e.existencia,							\n\
	preciogeneral,							\n\
	preciogeneral*b.existencia as importeventa			\n\
from productos as a inner join 						\n\
     stock as b using(idproducto)  inner join				\n\
     ultimocosto as c on a.idproducto=c.idproducto inner join 		\n\
     costobruto as d on c.idcosto=d.idcostobruto inner join		\n\
     existencia as e on a.idproducto=e.idproducto inner join 		\n\
     estatusproducto as g on a.idproducto=g.idproducto inner join	\n\
     productoproveedor as h on a.idproducto=h.idproducto inner join	\n\
     empresas as i using(idempresa)  inner join				\n\
     productostock as j on a.idproducto=j.idproducto inner join		\n\
     ultimopreciogeneral as k on a.idproducto=k.idproducto inner join   \n\
     preciogeneral as l on k.idprecio=l.idpreciogeneral			\n\
where idestatus in(1,3)							\n\
order by idempresa,							\n\
	 numproducto");
else
sprintf(lchrArrSql,
"									\n\
select idempresa,							\n\
	razonsocial,							\n\
	a.idproducto,							\n\
	a.numproducto,							\n\
	a.modelo,							\n\
	a.nombreproducto,						\n\
	b.idproducto,							\n\
	c.idcosto,							\n\
	costobruto,							\n\
	costoneto,							\n\
	costoneto*b.existencia as importecosto,				\n\
	b.existencia as stock,						\n\
	preciogeneral,							\n\
	preciogeneral*b.existencia as importeventa			\n\
from productos as a inner join 						\n\
     stock as b using(idproducto)  inner join				\n\
     ultimocosto as c on a.idproducto=c.idproducto inner join 		\n\
     costobruto as d on c.idcosto=d.idcostobruto inner join		\n\
     existencia as e on a.idproducto=e.idproducto inner join 		\n\
     estatusproducto as g on a.idproducto=g.idproducto inner join	\n\
     productoproveedor as h on a.idproducto=h.idproducto inner join	\n\
     empresas as i using(idempresa) inner join				\n\
     productostock as j on a.idproducto=j.idproducto inner join		\n\
     ultimopreciogeneral as k on a.idproducto=k.idproducto inner join   \n\
     preciogeneral as l on k.idprecio=l.idpreciogeneral			\n\
where idestatus in(1,3) and idempresa=%s				\n\
order by idempresa,							\n\
	 numproducto",
SiscomCampoAsociadoEntradaOperacion("Envio","IdProveedor",pSiscomOpePtrDato));
SiscomConsultasSqlServidorPorIdMaquina(
	 SiscomCampoAsociadoEntradaOperacion("Envio","IdTienda",pSiscomOpePtrDato),
	 gSiscomRegProLPtrMemoria,
	 lchrArrBuffer,
	 pSiscomOpePtrDato,
	"StockTienda%",
	lchrArrSql);
}

int SqlProductosServiSNTE(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrSql[1024],
	lchrArrBuffer[1024];
sprintf(lchrArrSql,
	"							\n\
select b.idproducto,						\n\
	b.numproducto,						\n\
	b.nombreproducto,					\n\
	b.modelo,						\n\
	e.idcostobruto,						\n\
	e.costoneto,						\n\
	e.costobruto						\n\
from productoproveedor as a inner join 				\n\
	productos as b using(idproducto) inner join		\n\
	estatusproducto as c using(idproducto) inner join	\n\
	ultimocosto as d using(idproducto) inner join 		\n\
	costobruto as e on d.idcosto=e.idcostobruto		\n\
where idestatus in (1,3) and 					\n\
	idempresa=%s",
SiscomCampoAsociadoEntradaOperacion("Envio","IdProveedor",pSiscomOpePtrDato));
SiscomConsultasSqlOperaciones(lchrArrBuffer,
		   pSiscomOpePtrDato,
		   "ProductosServiSNTE%",
		   lchrArrSql);
LogSiscom("%s",lchrArrSql);
}

void SqlDatosCompraProductos(SiscomOperaciones *pSiscomOpePtrDato,
			     char *pchrPtrSql)
{

sprintf(pchrPtrSql,
	"										\n\
select a.idproducto,									\n\
	b.numproducto,									\n\
	b.modelo,									\n\
	b.nombreproducto,								\n\
	d.costoneto,									\n\
	d.costobruto,									\n\
	f.preciogeneral,								\n\
	d1,										\n\
	d2,										\n\
	d3,										\n\
	d4,										\n\
	j.iddepartamento,								\n\
	nombredepto,									\n\
	l.iva,										\n\
	100*((f.preciogeneral-d.costoneto)/f.preciogeneral)::numeric(10,2) as margen	\n\
from productoproveedor as a inner join 							\n\
     productos as b using(idproducto) inner join					\n\
     ultimocosto as c using(idproducto) inner join					\n\
     costobruto as d on c.idcosto=d.idcostobruto inner join				\n\
     ultimopreciogeneral as e on e.idproducto=b.idproducto inner join			\n\
     preciogeneral as f on  f.idpreciogeneral=e.idprecio inner join			\n\
     ultimodescuentoempresa as g on a.idempresa=g.idempresa inner join			\n\
     descuentosempresa as h on h.iddescuentoempresa=g.iddescuentoempresa inner join	\n\
     departamentoproducto as j on j.idproducto=a.idproducto inner join 			\n\
     departamentos as k on j.iddepartamento=k.iddepartamento inner join			\n\
     ivaempresa as l on l.idempresa=a.idempresa						\n\
where a.idempresa=%s and 								\n\
      k.iddepartamento=%s 								\n\
order by b.numproducto",
SiscomCampoAsociadoEntradaOperacion("Envio","IdProveedor",pSiscomOpePtrDato),
SiscomCampoAsociadoEntradaOperacion("Envio","IdDepartamento",pSiscomOpePtrDato));

}

void SqlDatosCompraProveedor(SiscomOperaciones *pSiscomOpePtrDato,
			     char *pchrPtrSql)
{
sprintf(pchrPtrSql,
"									\n\
select a.idempresa,							\n\
	a.razonsocial,							\n\
	c.iddireccion,							\n\
	c.calle,							\n\
	c.numinterior,							\n\
	c.numexterior,							\n\
	c.colonia,							\n\
	c.delegmunic,							\n\
	c.codigopostal,							\n\
	d.plazo								\n\
from empresas as a inner join 						\n\
	direccionesempresa as b using(idempresa) inner join		\n\
	direcciones as c using(iddireccion) inner join 			\n\
	plazoempresa as d using(idempresa)				\n\
where idempresa=%s",
SiscomCampoAsociadoEntradaOperacion("Envio","IdProveedor",pSiscomOpePtrDato));

}

void SqlDatosCompraTelefonos(SiscomOperaciones *pSiscomOpePtrDato,
			     char *pchrPtrSql)
{
sprintf(pchrPtrSql,
"						\n\
select  idtelefono,				\n\
	idempresa,				\n\
	telefono				\n\
from telefonosempresa as a inner join 		\n\
     telefonos as b using(idtelefono)		\n\
where idempresa=%s",
SiscomCampoAsociadoEntradaOperacion("Envio","IdProveedor",pSiscomOpePtrDato));

}


int SqlDatosCompra(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrSqlProductos[2048],
     lchrArrSqlProveedor[1024],
     lchrArrSqlTelefonos[256],
	lchrArrBuffer[2048];
SqlDatosCompraProductos(pSiscomOpePtrDato,lchrArrSqlProductos);
SqlDatosCompraProveedor(pSiscomOpePtrDato,lchrArrSqlProveedor);
SqlDatosCompraTelefonos(pSiscomOpePtrDato,lchrArrSqlTelefonos);
SiscomConsultasSqlOperaciones(lchrArrBuffer,
		   pSiscomOpePtrDato,
		   "DatosCompra%Proveedor%Telefonos%",
		   lchrArrSqlProductos,
		   lchrArrSqlProveedor,
		   lchrArrSqlTelefonos);
}
void SqlRepProveedoresProveedores(SiscomOperaciones *pSiscomOpePtrDato,
				  char *pchrPtrSql)
{
sprintf(pchrPtrSql,
"									\n\
select a.idempresa,							\n\
	b.razonsocial,							\n\
	e.calle,							\n\
	e.numinterior,							\n\
	e.numexterior,							\n\
	e.colonia,							\n\
	e.delegmunic,							\n\
	c.contacto,							\n\
	g.d1,								\n\
	g.d2,								\n\
	g.d3,								\n\
	g.d4,								\n\
	plazo,								\n\
	iva								\n\
from proveedores as a inner join					\n\
     empresas as b using(idempresa) inner join				\n\
     contactoempresa as c using(idempresa) inner join 			\n\
     direccionesempresa as d using(idempresa) inner join 		\n\
     direcciones as e using(iddireccion) inner join 			\n\
     ultimodescuentoempresa as f using(idempresa)  inner join		\n\
     descuentosempresa as g using(iddescuentoempresa) inner join	\n\
     plazoempresa as h on h.idempresa=a.idempresa inner join		\n\
     ivaempresa as i on i.idempresa=a.idempresa				\n\
");
}
void SqlRepProveedoresTelefonos(SiscomOperaciones *pSiscomOpePtrDato,
				char *pchrPtrSql)
{
sprintf(pchrPtrSql,
"					\n\
select *				\n\
from telefonosempresa as a inner join 	\n\
	telefonos using(idtelefono)	\n\
order by idempresa");
}
int SqlRepProveedores(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrSqlProveedores[1024],
	lchrArrSqlTelefonos[256],
	lchrArrBuffer[1024];
SqlRepProveedoresProveedores(pSiscomOpePtrDato,lchrArrSqlProveedores);
SqlRepProveedoresTelefonos(pSiscomOpePtrDato,lchrArrSqlTelefonos);
SiscomConsultasSqlOperaciones(lchrArrBuffer,
		   pSiscomOpePtrDato,
		   "Proveedores%Telefonos%",
		   lchrArrSqlProveedores,
		   lchrArrSqlTelefonos);
}
