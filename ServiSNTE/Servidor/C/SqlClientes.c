#include <SqlClientes.h>
#include <stdio.h>
#include <string.h>
#include <SiscomDesarrolloMacros.h>

#include <SiscomInsercionesSql.h>
#include <SiscomReplicacion.h>
int SqlComprasCliente(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrSqlClienteRFC[1024],
     lchrArrSqlComprasClienteRFC[1024],
     lchrArrSqlDireccionesClienteRFC[1024],
     lchrArrSqlCreditosPorFinanciera[256],
	lchrArrBuffer[1024];
SqlClientePorRFC(pSiscomOpePtrDat,lchrArrSqlClienteRFC);
SqlComprasClientePorRFC(pSiscomOpePtrDat,lchrArrSqlComprasClienteRFC);
SqlDireccionClientePorRFC(pSiscomOpePtrDat,lchrArrSqlDireccionesClienteRFC);
SqlCreditosPorFinanciera(pSiscomOpePtrDat,lchrArrSqlCreditosPorFinanciera);
SiscomConsultasSqlOperaciones(lchrArrBuffer,
			      pSiscomOpePtrDat,
			     "Cliente%Compras%Direcciones%CreditosPorFinanciera%",
			      lchrArrSqlClienteRFC,
			      lchrArrSqlComprasClienteRFC,
			      lchrArrSqlDireccionesClienteRFC,
			      lchrArrSqlCreditosPorFinanciera);

SiscomRegistrosAsociadosLog(lchrArrBuffer,"Cliente",pSiscomOpePtrDat->SiscomRegProLPtrPrimRes); 
SiscomRegistrosAsociadosLog(lchrArrBuffer,"Compras",pSiscomOpePtrDat->SiscomRegProLPtrPrimRes); 
SiscomRegistrosAsociadosLog(lchrArrBuffer,"Direcciones",pSiscomOpePtrDat->SiscomRegProLPtrPrimRes); 
}

void SqlClientePorRFC(SiscomOperaciones *pSiscomOpePtrDat, 
		   char *pchrPtrSql)
{
 sprintf(pchrPtrSql,
 	 "select personas.* 						\n\
	  from clientes  inner join 					\n\
	       personas on clientes.idcliente=personas.idpersona 	\n\
	  where RFc='%s'",
	  SiscomCampoAsociadoEntradaOperacion("Envio","RFC",pSiscomOpePtrDat));
}
void SqlCreditosPorFinanciera(SiscomOperaciones *pSiscomOpePtrDat,
			      char *pchrPtrSql)
{
	strcpy(pchrPtrSql,"select * from numerocreditos");
}
void SqlComprasClientePorRFC(SiscomOperaciones *pSiscomOpePtrDat,
			    char *pchrPtrSql)
{
sprintf(pchrPtrSql,
 	 "										\n\
select a.idtipoventa,									\n\
	a.fecha::date,									\n\
	b.pagoquincenal,								\n\
       b.pagototal,									\n\
       c.nombre as Plazo,								\n\
       d.nombre  as Financiadora,							\n\
       d.idfinanciadora,								\n\
       case when meses=12 then								\n\
				(fecha + interval '12 mons')::date			\n\
	    when meses=18 then								\n\
		 		(fecha + interval '18 mons')::date			\n\
	    when meses=24 then								\n\
		 		(fecha + interval '24 mons')::date			\n\
	end as vencimiento								\n\
from ventas as a left outer join							\n\
	ventacredito as b using(idventa) inner join					\n\
	plazos as c using(idplazo) inner join						\n\
	financiadoras as d using(idfinanciadora)					\n\
where idcliente in (select idcliente 							\n\
		    from clientes inner join personas on idcliente=idpersona		\n\
		    where rfc='%s');",
SiscomCampoAsociadoEntradaOperacion("Envio","RFC",pSiscomOpePtrDat));
}

void SqlDireccionClientePorRFC(SiscomOperaciones *pSiscomOpePtrDat,
			    char *pchrPtrSql)
{
 sprintf(pchrPtrSql,
 	 "								\n\
	select * 							\n\
	from direccionescliente inner join 				\n\
	     direcciones using(iddireccion) 				\n\
	where idcliente in(select idcliente 				\n\
	    		   from clientes inner join 			\n\
			   	personas on idcliente=idpersona		\n\
	        	    where rfc='%s');",
SiscomCampoAsociadoEntradaOperacion("Envio","RFC",pSiscomOpePtrDat));
}

