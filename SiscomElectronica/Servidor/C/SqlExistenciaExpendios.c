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
/*
*pchrPtrSql=strdup("select a.*,							\n\
        		   c.precio,						\n\
        		   d.razonsocial,					\n\
			   f.bodega,						\n\
			   b.existencia as existenciab				\n\
		    from existencias as a inner join 				\n\
     			 materialbodega as b using(cveproducto) inner join	\n\
     		         precios as c on (a.cveproducto=c.cveproducto and 	\n\
                                           nmbtipoprecio='DEFAULT') inner join	\n\
     			  empresas as d  on a.idexpendio=d.idempresa inner join	\n\
			  bodegas as f on b.idbodega=f.idbodega			\n\
		     where a.cveproducto in(");

*/

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
