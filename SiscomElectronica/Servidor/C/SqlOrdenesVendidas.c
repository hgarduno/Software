#include <SqlOrdenesVendidas.h>
#include <SiscomDesarrolloMacros.h>
#include <stdio.h>
#include <string.h>
int SqlOrdenesVendidas(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[512],
	lchrArrSql[512];
sprintf(lchrArrSql,
	"							\n\
	select a.*,						\n\
		b.importe as totalorden,			\n\
		c.idfactura					\n\
	from ventas as a inner join 				\n\
	     importeorden as b using(idventa) left outer join	\n\
	     ordenesfacturadas as c using(idventa)		\n\
	where fechahora::date>='%s' and 			\n\
	      fechahora::date<='%s' and				\n\
	      a.edoventa=%s					\n\
	order by fechahora desc",
SiscomCampoAsociadoEntradaOperacion("Envio","FechaInicio",pSiscomOpePtrDato),
SiscomCampoAsociadoEntradaOperacion("Envio","FechaFin",pSiscomOpePtrDato),
SiscomCampoAsociadoEntradaOperacion("Envio","IdTipoOrden",pSiscomOpePtrDato));
SiscomConsultasSqlOperaciones(lchrArrBuffer,
		   pSiscomOpePtrDato,
		   "Ordenes%",
		   lchrArrSql);
}

int SqlOrdenesParaFacturar(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[1024],
	lchrArrSql[1024];
sprintf(lchrArrSql,
	"							\n\
	select a.*,						\n\
		'Pza' as unidad,				\n\
		d.dscproducto,					\n\
		case when e.sat is null then			\n\
			'32101600' 				\n\
			else					\n\
			e.sat					\n\
		 end,						\n\
		b.importe as totalorden,			\n\
		c.idfactura					\n\
	from ventas as a inner join 				\n\
	     importeorden as b using(idventa) left outer join	\n\
	     ordenesfacturadas as c using(idventa) inner join	\n\
	     productos as d using(cveproducto) left outer join	\n\
	     clavesatsiscom as e on a.cveproducto=e.clave 	\n\
	where fechahora::date>='%s' and 			\n\
	      fechahora::date<='%s' and				\n\
	      a.edoventa in(0,2,4,7)				\n\
	order by fechahora desc",
SiscomCampoAsociadoEntradaOperacion("Envio","FechaInicio",pSiscomOpePtrDato),
SiscomCampoAsociadoEntradaOperacion("Envio","FechaFin",pSiscomOpePtrDato));
SiscomConsultasSqlOperaciones(lchrArrBuffer,
		   pSiscomOpePtrDato,
		   "Ordenes%",
		   lchrArrSql);
}

int SqlOrdenParaFacturar(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[1024],
	lchrArrSql[1024];
sprintf(lchrArrSql,
	"							\n\
	select a.*,						\n\
		'Pza' as unidad,				\n\
		d.dscproducto,					\n\
		case when e.sat is null then			\n\
			'32101600' 				\n\
			else					\n\
			e.sat					\n\
		 end,						\n\
		b.importe as totalorden,			\n\
		c.idfactura					\n\
	from ventas as a inner join 				\n\
	     importeorden as b using(idventa) left outer join	\n\
	     ordenesfacturadas as c using(idventa) inner join	\n\
	     productos as d using(cveproducto) left outer join	\n\
	     clavesatsiscom as e on a.cveproducto=e.clave 	\n\
	where b.idventa=%s and 					\n\
	      a.edoventa in(0,2,4,7)				\n\
	order by fechahora desc",
SiscomCampoAsociadoEntradaOperacion("Envio","IdVenta",pSiscomOpePtrDato));
SiscomConsultasSqlOperaciones(lchrArrBuffer,
		   pSiscomOpePtrDato,
		   "Ordenes%",
		   lchrArrSql);
}

int SqlOrdenesVendidas2(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[2048],
	lchrArrSql[2048];
const char *lchrPtrIdTipoOrden,
	   *lchrPtrCondicionConsulta;
lchrPtrCondicionConsulta=SiscomObtenCampoArgumento4("Condicion","CondicionConsulta",pSiscomOpePtrDato);
/* Casa de Dani Gonzalez, viendo como encorda 
 * Lunes 29 de Enero del 2022 
 *
 * Falta identificar como pruebo la condicion else de este if :)
 *{
 *
if((lchrPtrIdTipoOrden=SiscomCampoAsociadoEntradaOperacion("Envio","IdTipoOrden",pSiscomOpePtrDato)))
sprintf(lchrArrSql,
	"									\n\
	select a.*,								\n\
	       c.idtipoproducto,						\n\
	       b.importe as importeorden, 					\n\
	       d.existencia,							\n\
	       a.edoventa as idtipoorden,					\n\
	       f.nombre as escuela,						\n\
	       f.idescuela,							\n\
	       h.*								\n\
	from ventas as a left outer join 					\n\
	     importeorden as b using(idventa) left outer join			\n\
	     productoportipoproducto as c using(cveproducto) inner join		\n\
	     existencias as d using(cveproducto) inner join 			\n\
	     escuelaorden as e using(idventa)    inner join 			\n\
	     escuelas as f using(idescuela)	inner join 			\n\
	     ordencliente as g using(idventa)    inner join			\n\
	     personas as h using(idpersona)					\n\
	where fechahora::date>='%s' and 					\n\
	      fechahora::date<='%s' and						\n\
	     a.edoventa=%s							\n\
	order by a.fechahora desc,						\n\
	         a.idconsecutivo desc",
SiscomCampoAsociadoEntradaOperacion("Envio","FechaInicio",pSiscomOpePtrDato),
SiscomCampoAsociadoEntradaOperacion("Envio","FechaFin",pSiscomOpePtrDato),
lchrPtrIdTipoOrden);
else
sprintf(lchrArrSql,
	"									\n\
	select a.*,								\n\
	       c.idtipoproducto,						\n\
	       b.importe as importeorden, 					\n\
	       d.existencia,							\n\
	       a.edoventa as idtipoorden,					\n\
	       f.nombre as escuela,						\n\
	       f.idescuela,							\n\
	       h.*								\n\
	from ventas as a left outer join 					\n\
	     importeorden as b using(idventa) left outer join			\n\
	     productoportipoproducto as c using(cveproducto) inner join		\n\
	     existencias as d using(cveproducto) inner join			\n\
	     escuelaorden as e using(idventa)    inner join 			\n\
	     escuelas as f using(idescuela)	 inner join			\n\
	     ordencliente as g using(idventa)    inner join			\n\
	     personas as h using(idpersona)					\n\
	where fechahora::date>='%s' and 					\n\
	      fechahora::date<='%s' 						\n\
	order by a.fechahora desc,						\n\
	         a.idconsecutivo asc",
SiscomCampoAsociadoEntradaOperacion("Envio","FechaInicio",pSiscomOpePtrDato),
SiscomCampoAsociadoEntradaOperacion("Envio","FechaFin",pSiscomOpePtrDato));
}
*/

/* Tepotzotlan Mexico a 2 de enero del 2024 
 *
 * Las consultas generales por IdTipoOrden, no es buena idea ya, ya que por ejemplo 
 * los pagos de apartados con transferencia o tarjeta no se identifican de manera correcta
 *
 */


lchrPtrIdTipoOrden=SiscomCampoAsociadoEntradaOperacion("Envio","IdTipoOrden",pSiscomOpePtrDato);

LogSiscom("Consultando por tipo de Orden %s",lchrPtrIdTipoOrden);
if(!SiscomComparaCampoAsociadoEntradaCadena("Envio","IdTipoOrden","11",pSiscomOpePtrDato))
{
LogSiscom(" Consultando las transferencias");
sprintf(lchrArrSql,
	"									\n\
select a.idexpendio,								\n\
	a.idventa,								\n\
	a.fechahora,								\n\
	a.cveproducto,								\n\
	a.cantidad,								\n\
	a.importe,								\n\
	a.precio,								\n\
	a.vendedor,								\n\
	a.cliente,								\n\
	a.cliente as idpersona,							\n\
	11 as edoventa,								\n\
	a.idproducto,								\n\
	a.idconsecutivo,							\n\
	c.idtipoproducto,							\n\
	b.importe as importeorden,						\n\
	d.existencia,								\n\
	11 as idtipoorden,							\n\
	f.nombre as escuela,							\n\
	f.idescuela,								\n\
	h.*,									\n\
	i.*,									\n\
	k.telefono as telefonotra,						\n\
	k.sereflejo,								\n\
	k.observaciones								\n\
from pagotransferencia as k inner join 						\n\
	ventas as a using(idventa) inner join					\n\
	importeorden as b using(idventa) left outer join			\n\
	productoportipoproducto as c using(cveproducto) inner join		\n\
	existencias as d using(cveproducto) inner join 				\n\
	escuelaorden as e using(idventa) inner join				\n\
	escuelas as f   using(idescuela) inner join				\n\
	ordencliente as g using(idventa) inner join				\n\
	personas as h using(idpersona)  left outer join				\n\
	telefonos as i on (h.idpersona=i.idpersona and 				\n\
	                   i.departamenteo='Celular')				\n\
	%s									\n\
	order by a.fechahora desc, 						\n\
	         a.idconsecutivo asc",
	lchrPtrCondicionConsulta);

}
else
sprintf(lchrArrSql,
	"									\n\
 select a.*,									\n\
 	a.cliente as idpersona,							\n\
               c.idtipoproducto,						\n\
               case when a.edoventa=2 						\n\
	       then l.porpagar 							\n\
	       else								\n\
	       b.importe 							\n\
	       end as importeorden, 						\n\
               d.existencia,							\n\
               a.edoventa as idtipoorden,					\n\
               f.nombre as escuela,						\n\
               f.idescuela,							\n\
               h.*,								\n\
               i.*,								\n\
               k.telefono as telefonotra,					\n\
               k.sereflejo,							\n\
               k.observaciones							\n\
        from ventas as a  left outer join 					\n\
             cotizacion as j using(idventa) left outer join			\n\
	     apartado as l using(idventa)   left outer join			\n\
             pagotransferencia as k using(idventa)  left outer join		\n\
             importeorden as b using(idventa) left outer join			\n\
             productoportipoproducto as c using(cveproducto) inner join		\n\
             existencias as d using(cveproducto) inner join			\n\
             escuelaorden as e using(idventa)    inner join 			\n\
             escuelas as f using(idescuela)      inner join			\n\
             ordencliente as g using(idventa)    inner join			\n\
             personas as h using(idpersona)      left outer join		\n\
             telefonos as i on (h.idpersona=i.idpersona and 			\n\
                                i.departamenteo='Celular')			\n\
	    %s									\n\
        order by a.fechahora desc,						\n\
                 a.idconsecutivo asc",
	lchrPtrCondicionConsulta);
LogSiscom("%d",strlen(lchrArrSql));
SiscomConsultasSqlOperaciones(lchrArrBuffer,
		   pSiscomOpePtrDato,
		   "Ordenes%",
		   lchrArrSql);

return 0;
}

int SqlConsultaApartados(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[512],
	lchrArrSql[512];
sprintf(lchrArrSql,
	"						\n\
select distinct idventa,				\n\
		edoventa,				\n\
	fechahora::date,				\n\
	fechaentrega::date,				\n\
	fechahora::time horapedido,			\n\
	fechaentrega::time horaentrega,			\n\
	b.acuenta,					\n\
	b.porpagar,					\n\
	c.*,						\n\
	0 as formapago					\n\
from ventas  as a inner join 				\n\
	apartado as b using(idventa) inner join		\n\
	personas as c on a.cliente=c.idpersona		\n\
where edoventa in(2,11) and 				\n\
	fechahora::date>='%s' and			\n\
	fechahora::date<='%s'",
SiscomCampoAsociadoEntradaOperacion("Envio","FechaIni",pSiscomOpePtrDato),
SiscomCampoAsociadoEntradaOperacion("Envio","FechaFin",pSiscomOpePtrDato));
SiscomConsultasSqlOperaciones(lchrArrBuffer,
		   pSiscomOpePtrDato,
		   "Apartados%",
		   lchrArrSql);
}

int SqlProductoEnApartados(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[512],
	lchrArrSql[512];
sprintf(lchrArrSql,
	"					\n\
select fechahora::date,				\n\
	fechaentrega::date,			\n\
	fechahora::time horapedido,		\n\
	fechaentrega::time horaentrega,		\n\
	a.cantidad,				\n\
	a.precio,				\n\
	a.importe,				\n\
	b.acuenta,				\n\
	b.porpagar,				\n\
	c.nombre || ' ' || c.apaterno as nombre	\n\
from ventas  as a inner join 			\n\
	apartado as b using(idventa) inner join	\n\
	personas as c on a.cliente=c.idpersona	\n\
where edoventa=2 and 				\n\
	cveproducto='%s'",
SiscomCampoAsociadoEntradaOperacion("Envio","Clave",pSiscomOpePtrDato));
SiscomConsultasSqlOperaciones(lchrArrBuffer,
		   pSiscomOpePtrDato,
		   "Apartados%",
		   lchrArrSql);
}
void SqlConsultaImporteOrden(SiscomOperaciones *pSiscomOpePtrDato,
			     char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"select *		\n\
	 from importeorden	\n\
	 where idventa=%s",
	SiscomCampoAsociadoEntradaOperacion("Envio","IdOrden",pSiscomOpePtrDato));
}

void SqlConsultaVenta(SiscomOperaciones *pSiscomOpePtrDato,
		      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"select *			\n\
	 from ventas			\n\
	 where idventa=%s and		\n\
	 	edoventa=%s		\n\
	 order by idconsecutivo asc",
	 SiscomCampoAsociadoEntradaOperacion("Envio","IdOrden",pSiscomOpePtrDato),
	 SiscomCampoAsociadoEntradaOperacion("Envio","IdTipoOrden",pSiscomOpePtrDato));
}
void SqlInformacionCotizacion(SiscomOperaciones *pSiscomOpePtrDato,
			      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"select *		\n\
	 from cotizacion	\n\
	 where idventa=%s",
	 SiscomCampoAsociadoEntradaOperacion("Envio","IdOrden",pSiscomOpePtrDato));
}
void SqlClienteOrdenVendida(SiscomOperaciones *pSiscomOpePtrDato,
			    char *pchrPtrSql)
{

sprintf(pchrPtrSql,
	"select *					\n\
	 from personas 					\n\
	 where idpersona = (select distinct cliente	\n\
	 		    from ventas 		\n\
			    where idventa=%s)",
	 SiscomCampoAsociadoEntradaOperacion("Envio","IdOrden",pSiscomOpePtrDato));
}

void SqlClienteEscuela(SiscomOperaciones *pSiscomOpePtrDato,char *pchrPtrSql)
{

sprintf(pchrPtrSql,
	"							\n\
	 select idescuela,					\n\
	 	nombre 						\n\
	 from escuelaorden inner join 				\n\
	      escuelas using(idescuela)  where idventa=%s",
	 SiscomCampoAsociadoEntradaOperacion("Envio","IdOrden",pSiscomOpePtrDato));
}

int SqlConsultaOrden(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[256],
	lchrArrSqlImporteOrden[256],
	lchrArrSqlVentas[256],
	lchrArrSqlCliente[256],
	lchrArrSqlCotizacion[256],
	lchrArrSqlEscuelaCliente[256];
SqlConsultaImporteOrden(pSiscomOpePtrDato,lchrArrSqlImporteOrden);
SqlConsultaVenta(pSiscomOpePtrDato,lchrArrSqlVentas);
SqlClienteOrdenVendida(pSiscomOpePtrDato,lchrArrSqlCliente);
SqlInformacionCotizacion(pSiscomOpePtrDato,lchrArrSqlCotizacion);
SqlClienteEscuela(pSiscomOpePtrDato,lchrArrSqlEscuelaCliente);
SiscomConsultasSqlOperaciones(lchrArrBuffer,
			      pSiscomOpePtrDato,
			      "ImporteOrden%Productos%Cliente%Cotizacion%Escuela%",
			      lchrArrSqlImporteOrden,
			      lchrArrSqlVentas,
			      lchrArrSqlCliente,
			      lchrArrSqlCotizacion,
			      lchrArrSqlEscuelaCliente);
}


int SqlCompletaCotizaciones(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[512],
	lchrArrSql[512];
sprintf(lchrArrSql,
	"select distinct b.*			\n\
	 from cotizacion as b inner join	\n\
	      ventas as a using(idventa)	\n\
	 %s",
	SiscomObtenCampoArgumento4("Condicion","CondicionConsulta",pSiscomOpePtrDato));	
SiscomConsultaSqlAArgumentoOperaciones(lchrArrSql,
				       "SqlCotizaciones",
				       lchrArrBuffer,
				       pSiscomOpePtrDato);
}
int SqlCompletaPedidos(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[1024],
	lchrArrSql[1024];

sprintf(lchrArrSql,
 	"select *								\n\
	 from datospedido as a inner join					\n\
              pedidocliente as b using(idventa) left outer join			\n\
              direccionentrega as c using(idventa) left outer join		\n\
	      ordencliente as d using(idventa) left outer join			\n\
	      direcciones as e using(iddireccion) inner join			\n\
	      estadospedidocliente as f using(idventa) inner join		\n\
              estadospedido as g on g.idedopedido=f.idestado inner join		\n\
	      accionestadopedido as h using(idedopedido)			\n\
	 where fechaentrega::date>='%s' and 					\n\
	       fechaentrega::date<='%s' ",
	 SiscomCampoAsociadoEntradaOperacion("Envio","FechaInicio",pSiscomOpePtrDato),
	 SiscomCampoAsociadoEntradaOperacion("Envio","FechaFin",pSiscomOpePtrDato));


SiscomConsultaSqlAArgumentoOperaciones(lchrArrSql,
				       "SqlPedidos",
				       lchrArrBuffer,
				       pSiscomOpePtrDato);
return 0;
}
int SqlCompletaVentas(SiscomOperaciones *pSiscomOpePtrDato)
{
}

int SqlCompletaApartados(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[2048],
	lchrArrSql[2048];
/*
sprintf(lchrArrSql,
	"									\n\
select a.*,									\n\
        a.cliente as idpersona,							\n\
               c.idtipoproducto,						\n\
               b.importe as importeorden, 					\n\
               d.existencia,							\n\
               a.edoventa as idtipoorden,					\n\
               f.nombre as escuela,						\n\
               f.idescuela,							\n\
               h.*,								\n\
               i.*,								\n\
	       j.*,								\n\
	       0 as \"AbonosApartado\"						\n\
        from ventas as a  left outer join 					\n\
             apartado as j using(idventa) left outer join			\n\
             pagotransferencia as k using(idventa)  left outer join		\n\
             importeorden as b using(idventa) left outer join			\n\
             productoportipoproducto as c using(cveproducto) inner join		\n\
             existencias as d using(cveproducto) inner join			\n\
             escuelaorden as e using(idventa)    inner join 			\n\
             escuelas as f using(idescuela)      inner join			\n\
             ordencliente as g using(idventa)    inner join			\n\
             personas as h using(idpersona)      left outer join		\n\
             telefonos as i on (h.idpersona=i.idpersona and 			\n\
                                i.departamenteo='Celular')			\n\
            where fechahora::date>='%s' and 					\n\
               fechahora::date<='%s'  and 					\n\
               a.edoventa=2							\n\
        order by a.fechahora desc,						\n\
                 a.idconsecutivo asc",
	 SiscomCampoAsociadoEntradaOperacion("Envio","FechaInicio",pSiscomOpePtrDato),
	 SiscomCampoAsociadoEntradaOperacion("Envio","FechaFin",pSiscomOpePtrDato));
*/
sprintf(lchrArrSql,
	"select * 						\n\
	 from apartado 						\n\
	 where idventa in(select distinct idventa 		\n\
	                  from ventas 				\n\
			  where fechahora::date>='%s' and 	\n\
			        fechahora::date<='%s' and 	\n\
				edoventa=2);",
	 SiscomCampoAsociadoEntradaOperacion("Envio","FechaInicio",pSiscomOpePtrDato),
	 SiscomCampoAsociadoEntradaOperacion("Envio","FechaFin",pSiscomOpePtrDato));
SiscomConsultaSqlAArgumentoOperaciones(lchrArrSql,
				       "SqlApartados",
				       lchrArrBuffer,
				       pSiscomOpePtrDato);
return 0;
}
/* Tepotzotlan Mexico a 18 Noviembre 2024 
 * Me reconcilie ...... creo ....
 *
 * Integro el manejo de abonos al apartado para poder tener el control
 * de un requerimiento de la profesora Erika secundaria, para que 
 * la fuente portatil que Fausto diseno no se hiciera prohibitiva para 
 * los alumnos, pudieran adquirirla en pagos
 *
 */
int SqlAbonosApartados(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[512],lchrArrSql[512];

sprintf(lchrArrSql,
	"							\n\
	select *						\n\
	from abonoapartado					\n\
	where idventa in(select distinct idventa		\n\
		 	 from ventas				\n\
		 	where fechahora::date>='%s' and 	\n\
		 	      fechahora::date<='%s' and		\n\
		              edoventa=2 )",
	 SiscomCampoAsociadoEntradaOperacion("Envio","FechaInicio",pSiscomOpePtrDato),
	 SiscomCampoAsociadoEntradaOperacion("Envio","FechaFin",pSiscomOpePtrDato));

SiscomConsultaSqlAArgumentoOperaciones(lchrArrSql,
				       "SqlAbonosApartados",
				       lchrArrBuffer,
				       pSiscomOpePtrDato);

return 0;
}
