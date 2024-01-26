#include <SqlApartados.h>
#include <SqlTiendas.h>
#include <SiscomDesarrolloMacros.h>

#include <SiscomInsercionesSql.h>
#include <SiscomReplicacion.h>
#include <stdio.h>

int SqlApartadosCliente(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[512],
	lchrArrSqlPersona[256],
	lchrArrSqlApartados[1024],
	lchrArrSqlTienda[128];
/* Queretaro a 29 de Febrero del 2016 
 * Inicialmente se planteo que la busqueda fuera por RFC
 * El dia de hoy en la sesion de trabajo con la gente del
 * ServiSNTE, se definio que el criterio de busqueda del 
 * apartado es el Folio de la factura de apartdo
SqlPersonaPorRFC(pSiscomOpePtrDat,lchrArrSqlPersona);
*/
SqlPersonaFolioFactura(pSiscomOpePtrDat,lchrArrSqlPersona);
SqlApartadosDelCliente(pSiscomOpePtrDat,lchrArrSqlApartados);
SqlConsultaTienda(lchrArrSqlTienda);
SiscomConsultasSqlOperaciones(lchrArrBuffer,
			      pSiscomOpePtrDat,
			     "Tienda%Persona%Apartados%",
			     lchrArrSqlTienda,
			     lchrArrSqlPersona,
			     lchrArrSqlApartados);
}

void SqlPersonaPorRFC(SiscomOperaciones *pSiscomOpePtrDat,char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"select *	\n\
	 from personas	\n\
	 where rfc='%s' ",
	 SiscomCampoAsociadoEntradaOperacion("Envio",
	 				     "RFC",
					     pSiscomOpePtrDat));
}
void SqlPersonaFolioFactura(SiscomOperaciones *pSiscomOpePtrDat,char *pchrPtrSql)
{
sprintf(pchrPtrSql,
"							\n\
select b.*						\n\
from ventas  as a inner join 				\n\
     personas as b on a.idcliente=b.idpersona		\n\
where folio='%s'",
	 SiscomCampoAsociadoEntradaOperacion("Envio",
	 				     "FolioApartado",
					     pSiscomOpePtrDat));

}
void SqlApartadosDelCliente(SiscomOperaciones *pSiscomOpePtrDat,char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"select a.*,							\n\
		b.*,							\n\
		d.*,							\n\
		f.nombre as nombrevendedor,				\n\
		c.total as abonado,					\n\
		b.total-c.total as PorPagar,				\n\
		e.idestatus as estatusventa				\n\
	  from ventas as a inner join					\n\
     	   importeventa as b using(idventa)	inner join		\n\
	       totalabonado as c using(idventa)	inner join  		\n\
	       vendedorventa as d using(idventa) inner join  		\n\
	       personas as f on d.idvendedor=f.idpersona inner join  	\n\
	       estatusventa as e using(idventa)				\n\
	  where idcliente in (select  idcliente				\n\
			      from ventas 				\n\
			      where folio='%s' 				\n\
		     	      ) and 					\n\
       idtipoventa=3 and e.idestatus=1",
	 SiscomCampoAsociadoEntradaOperacion("Envio",
	 				     "FolioApartado",
					     pSiscomOpePtrDat));
}
int SqlAbonoAApartado(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[512],
	lchrArrSql[512];
SiscomRegistroProL *lSisRegProLPtrDat;
SiscomAgregaArgumentoInsercionSql("SqlAbonoAApartado",
				  pSiscomOpePtrDat->chrArrBaseDatos,
				  pSiscomOpePtrDat->chrArrPuertoBaseDatos,
				  lchrArrBuffer,
				  pSiscomOpePtrDat);

SiscomAgregaSentenciasSqlDelAsociado("SqlAbonoAApartado",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDat,
				     InsertToAbonoAApartado);

SiscomAgregaSentenciasSqlDelAsociado("SqlAbonoAApartado",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDat,
				     UpdateTotalAbonado);

SiscomAgregaSentenciasSqlDelAsociado("SqlAbonoAApartado",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDat,
				     UpdateFolioActualApartado);
LogSiscom("Se Incrementa ---------------------------------------------------------");

SiscomReplicaMaquinaLocal("SqlAbonoAApartado", lchrArrBuffer, 0, pSiscomOpePtrDat);

}

int SqlCancelaAApartado(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[512],
	lchrArrSql[512];
SiscomRegistroProL *lSisRegProLPtrDat;
SiscomAgregaArgumentoInsercionSql("SqlAbonoAApartado",
				  pSiscomOpePtrDat->chrArrBaseDatos,
				  pSiscomOpePtrDat->chrArrPuertoBaseDatos,
				  lchrArrBuffer,
				  pSiscomOpePtrDat);

SiscomAgregaSentenciasSqlDelAsociado("SqlAbonoAApartado",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDat,
				     UpdateToCancelaAApartado);
SiscomAgregaSentenciasSqlDelAsociado("SqlAbonoAApartado",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDat,
				     UpdateTotalAbonadoCancela);

SiscomReplicaMaquinaLocal("SqlAbonoAApartado", lchrArrBuffer, 0, pSiscomOpePtrDat);

}

int SqlConsultaAbonos(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[512],
    lchrArrSql[512];
sprintf(lchrArrSql,
"                               \n\
select *         \n\
from abonosapartado     \n\
where idventa=%s and idestado=1;",
    SiscomCampoAsociadoEntradaOperacion("Envio","IdVenta",pSiscomOpePtrDat));

SiscomConsultasSqlOperaciones(lchrArrBuffer,
                  pSiscomOpePtrDat,
                 "Abonos%",
                 lchrArrSql);
}

int SqlCancelaApartado(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[512],
	lchrArrSql[512];
SiscomRegistroProL *lSisRegProLPtrDat;
SiscomAgregaArgumentoInsercionSql("SqlCancelaApartado",
				  pSiscomOpePtrDat->chrArrBaseDatos,
				  pSiscomOpePtrDat->chrArrPuertoBaseDatos,
				  lchrArrBuffer,
				  pSiscomOpePtrDat);

SiscomAgregaSentenciasSqlDelAsociado("SqlCancelaApartado",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDat,
				     UpdateToCancelaApartado);

SiscomReplicaMaquinaLocal("SqlCancelaApartado", lchrArrBuffer, 0, pSiscomOpePtrDat);

}

void InsertToAbonoAApartado(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into AbonosApartado values(%s,'%s',%s,1);",
	 SiscomCampoAsociadoEntradaOperacion("Envio","IdVenta",pSiscomOpePtrDatos),
	 SiscomCampoAsociadoEntradaOperacion("Envio","Fecha",pSiscomOpePtrDatos),
	 SiscomCampoAsociadoEntradaOperacion("Envio","MontoAbono",pSiscomOpePtrDatos));
}
void UpdateTotalAbonado(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"update totalAbonado set total=total+%s where idventa=%s;",
	 SiscomCampoAsociadoEntradaOperacion("Envio","MontoAbono",pSiscomOpePtrDatos),
	 SiscomCampoAsociadoEntradaOperacion("Envio","IdVenta",pSiscomOpePtrDatos));
}

void UpdateToCancelaAApartado(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"update abonosapartado set idestado=0 where idventa=%s and \
     fecha='%s' and monto=%s;",
	 SiscomCampoAsociadoEntradaOperacion("Envio","IdVenta",pSiscomOpePtrDatos),
	 SiscomCampoAsociadoEntradaOperacion("Envio","Fecha",pSiscomOpePtrDatos),
	 SiscomCampoAsociadoEntradaOperacion("Envio","MontoAbono",pSiscomOpePtrDatos));
}

void UpdateTotalAbonadoCancela(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"update totalAbonado set total=total-%s where idventa=%s;",
	 SiscomCampoAsociadoEntradaOperacion("Envio","MontoAbono",pSiscomOpePtrDatos),
	 SiscomCampoAsociadoEntradaOperacion("Envio","IdVenta",pSiscomOpePtrDatos));
}

void UpdateToCancelaApartado(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"update estatusventa set idestatus=2 where idventa=%s;",
	 SiscomCampoAsociadoEntradaOperacion("Envio","IdVenta",pSiscomOpePtrDatos));
}

void UpdateFolioActualApartado(SiscomOperaciones *pSiscomOpePtrDatos,
                         SiscomRegistroProL *pSiscomRegProLPtrEnt,
                         char *pchrPtrSql)
{
sprintf(pchrPtrSql,"update folioactual set folio=folio+1 where idtipofolio=1;");
}
