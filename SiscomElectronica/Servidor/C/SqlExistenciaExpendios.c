#include <SqlExistenciaExpendios.h>
#include <ExistenciaExpendios.h>
#include <stdio.h>
#include <SiscomDesarrolloMacros.h>
#include <SiscomMacrosOperaciones.h>
#include <SiscomReplicacion.h>
#include <string.h>
#include <stdlib.h>


int SqlExistenciaExpendios(SiscomOperaciones *pSiscomOpePtrDatos)
{
char *lchrPtrBuffer,
     *lchrPtrSqlExistencia=0;
char lchrArrBuffer[256];
SiscomRegistroProL *lSiscomRegProLPtrServidores;
SiscomRegistroProL *lSiscomRegProLPtrProductos;
lSiscomRegProLPtrProductos=SiscomRegistrosAsociadoEntradaOperacion("Envio",pSiscomOpePtrDatos);
SqlConsultaExistenciaProducto(pSiscomOpePtrDatos,
			      lSiscomRegProLPtrProductos,
			      &lchrPtrSqlExistencia);
lchrPtrBuffer=(char *)malloc(strlen(lchrPtrSqlExistencia)+120);
lSiscomRegProLPtrServidores=pSiscomOpePtrDatos->SiscomRegProLPtrPrimRes;
pSiscomOpePtrDatos->SiscomRegProLPtrPrimRes=0;
SiscomConsultasSqlSistema("Expendio",
			   "idempresa",
			   1,
			   lSiscomRegProLPtrServidores,
			   ConexionExpendioConsultaSiscom,
			   ErrorConexionExpendio,
			   EstadoConsultaSistemaSiscom,
			   lchrPtrBuffer,
			   pSiscomOpePtrDatos,
			   "Existencia%",
			   lchrPtrSqlExistencia);
LogSiscom("Termino la Consulta a todos los expendio");
return 0;
}

void SqlConsultaExistenciaProducto(SiscomOperaciones *pSiscomOpePtrDatos,
				   SiscomRegistroProL *pSiscomRegProLPtrProductos,
				   char **pchrPtrSql)
{
*pchrPtrSql=strdup("								\n\
select a.*,									\n\
	b.precio,								\n\
        d.razonsocial,								\n\
        e.bodega,								\n\
        c.existencia as existenciab						\n\
from existencias as a inner join						\n\
        precios as b on (a.cveproducto=b.cveproducto and			\n\
                         nmbtipoprecio='DEFAULT') left outer join		\n\
        materialbodega as c on a.cveproducto=c.cveproducto left outer join	\n\
        empresas as d on a.idexpendio=d.idempresa left outer join		\n\
        bodegas as e using(idbodega)						\n\
where a.cveproducto in(");

CondicionConsultaProductos(pSiscomRegProLPtrProductos,pchrPtrSql);
}
char *SqlCadenaInicialExistenciaVenta(SiscomOperaciones *pSiscomOpePtrDatos)
{
char lchrArrSql[512];
sprintf(lchrArrSql,
	"select sum(cantidad) as totalventas,		\n\
	       cveproducto				\n\
	from  ventas					\n\
	where fechahora::date>='%s' and 		\n\
	      fechahora::date<='%s' and			\n\
	      edoventa in(0,2,4,6,7,11) and		\n\
	      cveproducto ",
	SiscomCampoAsociadoEntradaOperacion("Envio","FechaIni",pSiscomOpePtrDatos),
	SiscomCampoAsociadoEntradaOperacion("Envio","FechaFin",pSiscomOpePtrDatos));
return strdup(lchrArrSql);

}
char *SqlCadenaInicialExistenciaSiscom(SiscomOperaciones *pSiscomOpePtrDatos)
{
char lchrArrSql[512];
sprintf(lchrArrSql,
	"select cveproducto,				\n\
		existencia+exbodegas as existenciat	\n\
	 from existenciaexpendiobodegas			\n\
	 where cveproducto ");
return strdup(lchrArrSql);
}
void SqlConsultaVentasPeriodo(SiscomOperaciones *pSiscomOpePtrDatos,char **pchrPtrSql)
{
char *lchrPtrClausulaIn;
ClausulaInProductos(SiscomRegistroAsociadoEntradaOperacion("Envio","Productos",pSiscomOpePtrDatos),
		    &lchrPtrClausulaIn);
*pchrPtrSql=SqlCadenaInicialExistenciaVenta(pSiscomOpePtrDatos);
*pchrPtrSql=AgregandoUnaCadena(lchrPtrClausulaIn,*pchrPtrSql);
*pchrPtrSql=AgregandoUnaCadena("\ngroup by cveproducto",*pchrPtrSql);
}
void SqlConsultaExistenciaSiscom(SiscomOperaciones *pSiscomOpePtrDatos,
				 char **pchrPtrSql)
{
char *lchrPtrClausulaIn;
ClausulaInProductos(SiscomRegistroAsociadoEntradaOperacion("Envio","Productos",pSiscomOpePtrDatos),
		    &lchrPtrClausulaIn);
*pchrPtrSql=SqlCadenaInicialExistenciaSiscom(pSiscomOpePtrDatos);
*pchrPtrSql=AgregandoUnaCadena(lchrPtrClausulaIn,*pchrPtrSql);
}
int SqlExistenciasVentasExpendios(SiscomOperaciones *pSiscomOpePtrDatos)
{
char *lchrPtrBuffer,
     *lchrPtrSqlExistencia=0,
     *lchrPtrSqlVentas=0;
char lchrArrBuffer[512];
SiscomRegistroProL *lSiscomRegProLPtrServidores,*lSiscomRegProLPtrDatosServidor;
SiscomRegistroProL *lSiscomRegProLPtrProductos;
lSiscomRegProLPtrProductos=SiscomRegistrosAsociadoEntradaOperacion("Envio",pSiscomOpePtrDatos);

SqlConsultaVentasPeriodo(pSiscomOpePtrDatos,&lchrPtrSqlVentas);
SqlConsultaExistenciaSiscom(pSiscomOpePtrDatos,&lchrPtrSqlExistencia);


lchrPtrBuffer=(char *)malloc(strlen(lchrPtrSqlExistencia)+256);
lSiscomRegProLPtrServidores=pSiscomOpePtrDatos->SiscomRegProLPtrPrimRes;
SiscomRegistroProtocoloLog(lchrArrBuffer,lSiscomRegProLPtrServidores);
lSiscomRegProLPtrDatosServidor=SiscomObtenRegistrosCampoProL("Servidores",lSiscomRegProLPtrServidores);
pSiscomOpePtrDatos->SiscomRegProLPtrPrimRes=0;
SiscomConsultasSqlSistema("Expendio",
			   "idempresa",
			   1,
			   lSiscomRegProLPtrServidores,
			   ConexionExpendioConsultaSiscom,
			   ErrorConexionVentasExistenciaSiscom,
			   EstadoConsultaVentasExistenciaSiscom,
			   lchrPtrBuffer,
			   pSiscomOpePtrDatos,
			   "Existencia%Ventas%",
			   lchrPtrSqlExistencia,
			   lchrPtrSqlVentas);
return 0;
}

char *SqlCadenaInicialExistenciaSiscomT(SiscomOperaciones *pSiscomOpePtrDatos)
{
char lchrArrSql[512];
sprintf(lchrArrSql,
	"select cveproducto,				\n\
		existencia+exbodegas as existenciat	\n\
	 from existenciaexpendiobodegas			\n\
	 where cveproducto");
return strdup(lchrArrSql);
}
void SqlConsultaVentasPeriodoT(SiscomOperaciones *pSiscomOpePtrDatos,char **pchrPtrSql)
{
char lchrArrClausulaIn[256];
strcpy(lchrArrClausulaIn,"in(select cveproducto from productos)");
*pchrPtrSql=SqlCadenaInicialExistenciaVenta(pSiscomOpePtrDatos);
*pchrPtrSql=AgregandoUnaCadena(lchrArrClausulaIn,*pchrPtrSql);
*pchrPtrSql=AgregandoUnaCadena("\ngroup by cveproducto",*pchrPtrSql);
}

void SqlConsultaExistenciaSiscomT(SiscomOperaciones *pSiscomOpePtrDatos,
				 char **pchrPtrSql)
{
char lchrArrClausulaIn[256];
strcpy(lchrArrClausulaIn," in(select cveproducto from productos)");
*pchrPtrSql=SqlCadenaInicialExistenciaSiscomT(pSiscomOpePtrDatos);
*pchrPtrSql=AgregandoUnaCadena(lchrArrClausulaIn,*pchrPtrSql);
LogSiscom("%s",*pchrPtrSql);
}
int SqlExistenciasVentasExpendiosT(SiscomOperaciones *pSiscomOpePtrDatos)
{
char *lchrPtrBuffer,
     *lchrPtrSqlExistencia=0,
     *lchrPtrSqlVentas=0;
char lchrArrBuffer[512];
SiscomRegistroProL *lSiscomRegProLPtrServidores,*lSiscomRegProLPtrDatosServidor;
SiscomRegistroProL *lSiscomRegProLPtrProductos;
lSiscomRegProLPtrProductos=SiscomRegistrosAsociadoEntradaOperacion("Envio",pSiscomOpePtrDatos);

SqlConsultaVentasPeriodoT(pSiscomOpePtrDatos,&lchrPtrSqlVentas);
SqlConsultaExistenciaSiscomT(pSiscomOpePtrDatos,&lchrPtrSqlExistencia);

lchrPtrBuffer=(char *)malloc(strlen(lchrPtrSqlExistencia)+256);
lSiscomRegProLPtrServidores=pSiscomOpePtrDatos->SiscomRegProLPtrPrimRes;
SiscomRegistroProtocoloLog(lchrArrBuffer,lSiscomRegProLPtrServidores);
lSiscomRegProLPtrDatosServidor=SiscomObtenRegistrosCampoProL("Servidores",lSiscomRegProLPtrServidores);
pSiscomOpePtrDatos->SiscomRegProLPtrPrimRes=0;
SiscomConsultasSqlSistema("Expendio",
			   "idempresa",
			   1,
			   lSiscomRegProLPtrServidores,
			   ConexionExpendioConsultaSiscom,
			   ErrorConexionVentasExistenciaSiscomT,
			   EstadoConsultaSistemaSiscomT,
			   lchrPtrBuffer,
			   pSiscomOpePtrDatos,
			   "Existencia%Ventas%",
			   lchrPtrSqlExistencia,
			   lchrPtrSqlVentas);
/*
LogSiscom("%s",lchrPtrSqlVentas);
LogSiscom("%s",lchrPtrSqlExistencia);
*/
return 0;
}
