#include <SqlReportesSiscom.h>
#include <SiscomDesarrolloMacros.h>
#include <SiscomReplicacion.h>
#include <stdio.h>
#include <string.h>
#include <SiscomDesarrolloMacros.h>
/*  0 Venta 
 *  1 Cotizacion
 *  2 Apartado
 *  4 Pedido
 *  6 Circuito Impreso
 *  7 Pago con tarjeta
 *  8 Pago Apartado con tarjeta
 *  Viernes 3 Agosto 2018
 *  11 Apartado pagado con tarjeta
 */


int SqlReporteVentas4(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[1024],
	lchrArrSqlVentasTotales[1024],
	lchrArrSqlVentasApartado[256],
	lchrArrSqlVentasPedidos[256],
	lchrArrSqlVentasTarjeta[256],
	lchrArrSqlImporteVentasPorEscuela[512],
	lchrArrSqlImportePedidosPorEscuela[512],
	lchrArrSqlImporteTarjetaPorEscuela[512],
	lchrArrSqlTotalVentas[512],
	lchrArrSqlTotalTotalVentas[1024],
	lchrArrSqlTotales[512],
	lchrArrSqlMaterialEscuela[512];
const char *lchrPtrIdExpendio;
SqlImporteTotalEnCaja(pSiscomOpePtrDato,lchrArrSqlVentasTotales);
SqlVentasTotales(pSiscomOpePtrDato,"VentasApartado","edoventa=2",lchrArrSqlVentasApartado);
SqlVentasTotales(pSiscomOpePtrDato,"VentasPedido","edoventa=4",lchrArrSqlVentasPedidos);
SqlVentasTotales(pSiscomOpePtrDato,"VentasTarjeta","edoventa in(7,11) ",lchrArrSqlVentasTarjeta);

SqlVentaPorEscuela(pSiscomOpePtrDato,"edoventa=0",lchrArrSqlImporteVentasPorEscuela);
SqlVentaPorEscuela(pSiscomOpePtrDato,"edoventa=4",lchrArrSqlImportePedidosPorEscuela);

SqlTotalVentas(pSiscomOpePtrDato,lchrArrSqlTotalVentas);
LogSiscom("%s",lchrArrSqlTotalVentas);
SqlTotalTotalVentas(pSiscomOpePtrDato,lchrArrSqlTotalTotalVentas);
SqlTotales(pSiscomOpePtrDato,lchrArrSqlTotales);
SqlMaterialEscuela(pSiscomOpePtrDato,lchrArrSqlMaterialEscuela);
lchrPtrIdExpendio=SiscomCampoAsociadoEntradaOperacion("Envio","IdExpendio",pSiscomOpePtrDato);
if(SiscomConsultasSqlServidorPorIdMaquina3(
			lchrPtrIdExpendio,
			"Expendios",
			pSiscomOpePtrDato,
			ExpendioParaConsultar,
			lchrArrBuffer,
		   	"Totales%TotalTotalVentas%VentasTotales%VentasApartados%VentasPedidos%ImporteVentasPorEscuela%ImportePedidosPorEscuela%TotalVentas%MaterialEscuela%",
		   lchrArrSqlTotales,
		   lchrArrSqlTotalTotalVentas,
		   lchrArrSqlVentasTotales,
		   lchrArrSqlVentasApartado,
		   lchrArrSqlVentasPedidos,
		   lchrArrSqlImporteVentasPorEscuela,
		   lchrArrSqlImportePedidosPorEscuela,
		   lchrArrSqlTotalVentas,
		   lchrArrSqlMaterialEscuela))
{
LogSiscom("NO Hay Conexion al servidor");
}
else
LogSiscom("Si se conecto");
}
int SqlExpendiosSiscom(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrSql[256],
	lchrArrBuffer[256];
sprintf(lchrArrSql,
	"select * 					\n\
	from expendios as a inner join 			\n\
	     puertosservidorad4 as b using(idempresa) ");
SiscomConsultaSqlAArgumentoOperaciones(lchrArrSql,"Expendios",lchrArrBuffer,pSiscomOpePtrDato);
LogSiscom("%s",lchrArrSql);
}

int SqlCierraDia(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[1024],
	lchrArrSqlVentasEfectivo[256],
	lchrArrSqlVentasApartado[256],
	lchrArrSqlVentasPedidos[256],
	lchrArrSqlVentasTarjeta[256],
	lchrArrSqlVentasTotales[512];
const char *lchrPtrIdExpendio;
SqlImporteTotalEnCaja(pSiscomOpePtrDato,lchrArrSqlVentasTotales);
SqlVentasTotales(pSiscomOpePtrDato,"VentasEfectivo","edoventa in(0,2,6)",lchrArrSqlVentasEfectivo);
SqlVentasTotales(pSiscomOpePtrDato,"VentasPedido","edoventa=4",lchrArrSqlVentasPedidos);
SqlVentasTotales(pSiscomOpePtrDato,"VentasTarjeta","edoventa in(7,11) ",lchrArrSqlVentasTarjeta);
lchrPtrIdExpendio=SiscomCampoAsociadoEntradaOperacion("Envio","IdExpendio",pSiscomOpePtrDato);
if(SiscomConsultasSqlServidorPorIdMaquina3(
			lchrPtrIdExpendio,
			"Expendios",
			pSiscomOpePtrDato,
			ExpendioParaConsultar,
			lchrArrBuffer,
			"VentasEfectivo%VentasPedidos%VentasTarjeta%TotalCaja%",
			lchrArrSqlVentasEfectivo,
			lchrArrSqlVentasPedidos,
			lchrArrSqlVentasTarjeta,
			lchrArrSqlVentasTotales))
{
   LogSiscom("NO Hay Conexion Al Servidor");
}
else
LogSiscom("Se conecto");

}

int SqlVentasSiscom(SiscomOperaciones *pSiscomOpePtrDato)
{
LogSiscom("");
}
void SqlMaterialEscuela(SiscomOperaciones *pSiscomOpePtrDato,
		      	char *pchrPtrSqlMaterialEscuela)
{
sprintf(pchrPtrSqlMaterialEscuela,
	"						\n\
select sum(cantidad) as cantidad ,			\n\
	cveproducto,					\n\
	fechahora::date as fecha,			\n\
	c.nombre					\n\
from ventas as a inner join 				\n\
	escuelaorden as b using(idventa) inner join 	\n\
	escuelas as c using(idescuela)			\n\
where fechahora::date>='%s' and 			\n\
	fechahora::date<='%s' and			\n\
	edoventa in(0,2,4,6,7,11)			\n\
group by cveproducto,					\n\
	fechahora::date,				\n\
	c.nombre					\n\
order by fechahora::date desc,				\n\
	 c.nombre asc,					\n\
	 cantidad desc",
SiscomCampoAsociadoEntradaOperacion("Envio","FechaInicio",pSiscomOpePtrDato),
SiscomCampoAsociadoEntradaOperacion("Envio","FechaFin",pSiscomOpePtrDato));
}
void SqlVentasTotales(SiscomOperaciones *pSiscomOpePtrDato,
		      const char *pchrPtrNombre,
		      const char *pchrPtrEdoVenta,
		      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"select sum(importe) as %s 		\n\
	 from importeorden 			\n\
	 where fecha::date>='%s' and 		\n\
	 	fecha::date<='%s' and 		\n\
		%s",
pchrPtrNombre,
SiscomCampoAsociadoEntradaOperacion("Envio","FechaInicio",pSiscomOpePtrDato),
SiscomCampoAsociadoEntradaOperacion("Envio","FechaFin",pSiscomOpePtrDato),
pchrPtrEdoVenta);
}

void SqlImporteTotalEnCaja(SiscomOperaciones *pSiscomOpePtrDato,
			   char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"							\n\
select sum(importe) as VentasTotales				\n\
from(select sum(importe) as importe 				\n\
     from importeorden						\n\
     where fecha::date>='%s'  and 				\n\
	fecha::date<='%s' and					\n\
	edoventa in(0,2,4,6)					\n\
union								\n\
select sum(porpagar) as importe					\n\
from apartado inner join estadoapartado using(idventa) 		\n\
where fechaentrega::date>='%s' and 				\n\
	fechaentrega::date<='%s' and 				\n\
	estado=0) as VentasTotales",
SiscomCampoAsociadoEntradaOperacion("Envio","FechaInicio",pSiscomOpePtrDato),
SiscomCampoAsociadoEntradaOperacion("Envio","FechaFin",pSiscomOpePtrDato),
SiscomCampoAsociadoEntradaOperacion("Envio","FechaInicio",pSiscomOpePtrDato),
SiscomCampoAsociadoEntradaOperacion("Envio","FechaFin",pSiscomOpePtrDato));
}

void SqlVentaPorEscuela(SiscomOperaciones *pSiscomOpePtrDato,
			  const char *pchrPtrEdoVenta,
			  char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"						\n\
select count(*) as ordenes,				\n\
	sum(importe) as importe,			\n\
	c.idescuela,					\n\
	c.nombre,					\n\
	a.fecha::date					\n\
from importeorden as a inner join			\n\
	escuelaorden as b using(idventa) inner join 	\n\
	escuelas as c using(idescuela)			\n\
where a.fecha::date>='%s' 	and 			\n\
	a.fecha::date<='%s' 				\n\
	and %s						\n\
group by c.idescuela,					\n\
	 a.fecha::date,					\n\
	 c.nombre					\n\
order by a.fecha::date,1 desc",
SiscomCampoAsociadoEntradaOperacion("Envio","FechaInicio",pSiscomOpePtrDato),
SiscomCampoAsociadoEntradaOperacion("Envio","FechaFin",pSiscomOpePtrDato),
pchrPtrEdoVenta);
}

void SqlTotalVentas(SiscomOperaciones *pSiscomOpePtrDato,char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"select count(*) as ordenes,			\n\
	 	sum(importe) as total,fecha::date 	\n\
	 from importeorden 				\n\
	 where fecha::date>='%s' and 			\n\
	       fecha::date<='%s' and 			\n\
	       edoventa in(0,2,4,6,7,11)		\n\
	 group by fecha::date 				\n\
	 order by fecha::date desc;",
SiscomCampoAsociadoEntradaOperacion("Envio","FechaInicio",pSiscomOpePtrDato),
SiscomCampoAsociadoEntradaOperacion("Envio","FechaFin",pSiscomOpePtrDato));
}
void SqlTotalTotalVentas(SiscomOperaciones *pSiscomOpePtrDato,char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"select sum(total) as  total					\n\
	from (select sum(importe) as total 				\n\
	 from importeorden 						\n\
	 where fecha::date>='%s' and 					\n\
	       fecha::date<='%s' and 					\n\
	       edoventa in(0,2,4,6)					\n\
	 union								\n\
	 select sum(porpagar) as total 					\n\
	 from apartado inner join estadoapartado using(idventa)		\n\
	 where fechaentrega::date>='%s' and 				\n\
	       fechaentrega::date<='%s' and 				\n\
	       estado in(0)) as total",
SiscomCampoAsociadoEntradaOperacion("Envio","FechaInicio",pSiscomOpePtrDato),
SiscomCampoAsociadoEntradaOperacion("Envio","FechaFin",pSiscomOpePtrDato),
SiscomCampoAsociadoEntradaOperacion("Envio","FechaInicio",pSiscomOpePtrDato),
SiscomCampoAsociadoEntradaOperacion("Envio","FechaFin",pSiscomOpePtrDato));
}

void SqlTotales(SiscomOperaciones *pSiscomOpePtrDato,char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"							\n\
	select count(*) ordenes,				\n\
		sum(importe) importe,				\n\
		a.fecha::date,					\n\
		c.idescuela,					\n\
		c.nombre					\n\
	from importeorden as a inner join 			\n\
		escuelaorden as b using(idventa) inner join	\n\
		escuelas as c using(idescuela)			\n\
	where a.fecha::date>='%s' and 				\n\
		a.fecha::date<='%s' and 			\n\
		edoventa in(0,2,4,6,7,11)			\n\
	group by a.fecha::date,					\n\
	 	c.idescuela, 					\n\
		c.nombre					\n\
	order by a.fecha::date desc,				\n\
	 	1 desc",
SiscomCampoAsociadoEntradaOperacion("Envio","FechaInicio",pSiscomOpePtrDato),
SiscomCampoAsociadoEntradaOperacion("Envio","FechaFin",pSiscomOpePtrDato));
}

int ExpendioParaConsultar(const char *pchrPtrIdServidor,
		    const char *pchrPtrArgumento,
		    SiscomOperaciones *pSiscomOpePtrDato,
		    int *pintPtrPuerto,
		    char **pchrPtrDirIp)
{
SiscomRegistroProL *lSiscomRegProLPtrRegreso;

if((lSiscomRegProLPtrRegreso=SiscomObtenArgumentoPrimOperaciones(pchrPtrArgumento,pSiscomOpePtrDato)))
{
for( ;
     lSiscomRegProLPtrRegreso;
     lSiscomRegProLPtrRegreso=lSiscomRegProLPtrRegreso->SiscomRegProLPtrSig)
{
if(!SiscomComparaCadenaCampoRegistroProL(pchrPtrIdServidor,"idempresa",lSiscomRegProLPtrRegreso))
{
   *pintPtrPuerto=SiscomObtenCampoRegistroProLInt("puerto",lSiscomRegProLPtrRegreso);
   *pchrPtrDirIp=(char *)SiscomObtenCampoRegistroProLChar("diripsvrad",lSiscomRegProLPtrRegreso);
   strcpy(pSiscomOpePtrDato->chrArrBaseDatos,
   	 SiscomObtenCampoRegistroProLChar("basedatos",lSiscomRegProLPtrRegreso));
  LogSiscom("Servidor %s:%d",*pchrPtrDirIp,*pintPtrPuerto);
   return 0;
}
}
}
else
return 1;
}

