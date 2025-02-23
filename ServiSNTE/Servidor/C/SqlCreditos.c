#include <SqlCreditos.h>
#include <SqlApartados.h>
#include <SiscomDesarrolloMacros.h>

#include <SiscomInsercionesSql.h>
#include <SiscomReplicacion.h>
#include <stdio.h>

int SqlCreditosCliente(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[512],
	lchrArrSqlPersona[256],
	lchrArrSqlCreditos[1024],
	lchrArrSqlDireccion[1024];

/*
SqlPersonaPorRFC(pSiscomOpePtrDat,lchrArrSqlPersona);

*/
SqlCreditosDelCliente(pSiscomOpePtrDat,lchrArrSqlCreditos);
SqlDireccionCliente(pSiscomOpePtrDat,lchrArrSqlDireccion);
SiscomConsultasSqlOperaciones(lchrArrBuffer,
			      pSiscomOpePtrDat,
			     "Persona%Creditos%Direccion%",
			     lchrArrSqlPersona,
			     lchrArrSqlCreditos,
			     lchrArrSqlDireccion);
}
void SqlDireccionCliente(SiscomOperaciones *pSiscomOpePtrDat,char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"							\n\
select  *							\n\
from  direccionescliente inner join 				\n\
      direcciones using(iddireccion)				\n\
where idcliente in (select idcliente 				\n\
	            from personas inner join 			\n\
		         clientes on idcliente=idpersona	\n\
			where rfc='%s')",
	 SiscomCampoAsociadoEntradaOperacion("Envio",
	 				     "RFC",
					     pSiscomOpePtrDat));
}
void SqlCreditosDelCliente(SiscomOperaciones *pSiscomOpePtrDat,char *pchrPtrSql)
{
sprintf(pchrPtrSql,
"select a.idventa,						\n\
	a.idcliente,						\n\
	b.total,						\n\
	c.pagototal,						\n\
	c.pagoquincenal,					\n\
	e.nombre as plazo,					\n\
	f.tasa,							\n\
	f.tasa*100 as porcentajetasa,				\n\
	e.meses*2 as numeropagos				\n\
from ventas as a inner join					\n\
     importeventa as b using(idventa) inner join		\n\
     ventacredito as c using(idventa) inner join 		\n\
     financiadoras as d using(idfinanciadora) inner join 	\n\
     plazos as e using(idplazo)  inner join			\n\
     tasainteres as f on (e.idplazo=f.idplazo  and		\n\
	                  c.idfinanciadora=f.idfinanciadora)	\n\
where idcliente in (select idcliente 				\n\
		    from personas inner join 			\n\
		    	 clientes on idcliente=idpersona	\n\
		     where rfc='%s') and 			\n\
       idtipoventa=2",
	 SiscomCampoAsociadoEntradaOperacion("Envio",
	 				     "RFC",
					     pSiscomOpePtrDat));
}
int SqlAbonoACredito(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[512],
	lchrArrSql[512];
SiscomRegistroProL *lSisRegProLPtrDat;
SiscomAgregaArgumentoInsercionSql("SqlAbonoACredito",
				  pSiscomOpePtrDat->chrArrBaseDatos,
				  pSiscomOpePtrDat->chrArrPuertoBaseDatos,
				  lchrArrBuffer,
				  pSiscomOpePtrDat);

SiscomAgregaSentenciasSqlDelAsociado("SqlAbonoACredito",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDat,
				     InsertToAbonoACredito);

SiscomReplicaMaquinaLocal("SqlAbonoACredito", lchrArrBuffer, 0, pSiscomOpePtrDat);

}

void InsertToAbonoACredito(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into AbonosCredito values(%s,'%s',%s);",
	 SiscomCampoAsociadoEntradaOperacion("Envio","IdVenta",pSiscomOpePtrDatos),
	 SiscomCampoAsociadoEntradaOperacion("Envio","Fecha",pSiscomOpePtrDatos),
	 SiscomCampoAsociadoEntradaOperacion("Envio","MontoAbono",pSiscomOpePtrDatos));
}
